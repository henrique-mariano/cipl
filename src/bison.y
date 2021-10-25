%define lr.type canonical-lr
%define parse.error detailed
%define api.header.include {"lib/bison.h"}
%define parse.lac full
%locations

%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include "lib/tree.h"
    #include "lib/astcontext.h"
    #include "lib/symbol.h"
    #include "lib/context.h"
    #include "lib/treenode.h"
    #include "lib/sem_eval.h"
    #include "lib/macros.h"
    #include "lib/code_gen.h"

    // extern int num_line, num_col;

    int erros = 0;

    int semantic_error = 0;

    unsigned int temporary_count = 0;

    unsigned int current_scope;
    
    extern int yyparse();
    extern int yylex();
    extern int yylex_destroy();
    extern void yyerror(const char *error_msg);

    extern FILE *yyin;

    /* No raiz da arvore sintatica abstrata */
    AstNode *root;

    /* Contexto atual e arvore de contextos */
    List *list_context;
    TreeNode *current_context;
    TreeNode *last_context;
    TreeNode *global_context;
    int isFunctionContext;

    /* Lista para ajudar na criacao da arvore */
    List *node_aux;

    void delete_single_node(Element *node);
    void delete_list_treenode(Element *elem);
    void delete_tree_symbol_table(void *sym);
    unsigned int type_check(AstNode *root);
%}

%union{
    /* Estrutura da árvore sintática */
    struct AstNode *astnode;
    /* Estrutura de Símbolo */
    // struct Symbol *symbol;
    /* Estrutura de Lista */
    struct List *list;
    /* String */
    char *string;
}

/* Declaração de tipos e tokens */
/* Tipação da regra */
%type<astnode> declaration variableDeclare type id
%type<astnode> functionDeclare param
%type<astnode> statement codeBlock expression elseError
%type<astnode> binArith listArith compoundStatement assignArith
%type<astnode> flowExpression condExpression interationExpression
%type<astnode> optExpression returnExpression unaArith constant
%type<astnode> constantInteger constantReal constantNIL funcCall ioCommand
%type<astnode> ID_TOKEN READ_TOKEN WRITE_TOKEN STRING_TOKEN
%type<astnode> CONSTANT_INTEGER_TOKEN CONSTANT_REAL_TOKEN NIL_TOKEN

%type<list> optListParams listParams optListCodeBlock listCodeBlock
%type<list> listExpression optListExpression

%type<string> INT_TOKEN FLOAT_TOKEN LIST_TOKEN

%token INT_TOKEN FLOAT_TOKEN LIST_TOKEN /* Tipos */
%token ID_TOKEN READ_TOKEN WRITE_TOKEN /* IDs */
%token NIL_TOKEN CONSTANT_REAL_TOKEN CONSTANT_INTEGER_TOKEN /* Constantes */
%token MUL_DIV_TOKEN EXCLAMATION_TOKEN QUESTION_TOKEN PERCENTAGE_TOKEN ADD_MIN_TOKEN /* Operadores normais */
%token MAP_TOKEN FILTER_TOKEN CONSTRUCTOR_LIST_TOKEN /* Operadores de lista */
%token ASSIGN_TOKEN OR_TOKEN AND_TOKEN EQ_EXC_TOKEN LE_GR_TOKEN /* Assign e operadores lógicos */
%token ADD_UNARY_TOKEN MIN_UNARY_TOKEN
%token EQUAL_TOKEN DIFF_EQ_TOKEN
%token LESS_TOKEN LE_EQ_TOKEN GREAT_TOKEN GR_EQ_TOKEN
%token ADD_TOKEN MIN_TOKEN
%token MUL_TOKEN DIV_TOKEN
%token UNI_OP

%token IF_TOKEN ELSE_TOKEN FOR_TOKEN RETURN_TOKEN STRING_TOKEN

/* Precedencia dos operadores */
%precedence ASSIGN_TOKEN
%left OR_TOKEN
%left AND_TOKEN
%left EQUAL_TOKEN DIFF_EQ_TOKEN
%left LESS_TOKEN LE_EQ_TOKEN GREAT_TOKEN GR_EQ_TOKEN
%right MAP_TOKEN
%right FILTER_TOKEN
%right CONSTRUCTOR_LIST_TOKEN
%left '+' '-'
%left '*' '/'
%precedence EXCLAMATION_TOKEN
%precedence QUESTION_TOKEN
%precedence PERCENTAGE_TOKEN
%precedence UNI_OP

%precedence IF_TOKEN
%precedence ELSE_TOKEN

/* Destrutores */
%destructor{
    if($$)
        delete_astnode($$);
}<astnode>

%destructor{
    if($$)
        delete_list($$, delete_list_astnode);
}<list>

%destructor{
    if($$)
        free($$);
}<string>

%%

startProgram:
    declarationList
    /* Erros */
    /* Erro inesperado */
    /* int a */
    | error {
        SHOW_SYNTAX_ERROR("unexpected error || line: %d, column: %d\n", @1.first_line, @1.first_column);
    }
    /* Programa vazio */
    | %empty {
        SHOW_SYNTAX_ERROR("empty translation unit\n");
    }
;

declarationList: 
    declarationList declaration {
        insert_kid($2, root);
    }
    | declaration {
        insert_kid($1, root);
    }
;

declaration:
    variableDeclare {
        $$ = $1;
    }
    | functionDeclare {
        $$ = $1;
    }
    /* Erros */
    /*a = 2 + 3';'int main(){} */
    | statement {
        SHOW_SYNTAX_ERROR("an statement is not permitted at this top level || line: %d, column: %d\n", @1.first_line, @1.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
;

variableDeclare:
    type id ';' {
        // printf("current_context_var: %p || name: %s\n", (void *) current_context, $2->context->name);
        Symbol *sym_declared = lookup_symbol_context($2->context->name, current_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("variable redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, @2.first_line, @2.first_column);
            $$ = NULL;
            delete_astnode($1);
            delete_astnode($2);
        } else {
            Symbol *sym_ret;
            sym_ret = list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, VARIABLE);
            sym_ret->variable_tac = temporary_count++;
            $$ = create_astnode_context(AST_VAR_DECLARE, "variable declare", @1);
            insert_kid($1, $$);
            insert_kid($2, $$);
            $2->context->dtype = $1->context->dtype;
            $2->context->sym_ref = sym_ret;
        }
    }
    /* Erros */
    /* int ';' */
    | type ';' {
        SHOW_SYNTAX_ERROR("useless type name in empty declaration || line: %d, column: %d\n", @1.first_line, @1.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    /* int a = 2 */
    | type id ASSIGN_TOKEN error {
        SHOW_SYNTAX_ERROR("expected ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        delete_astnode($2);
        $$ = NULL;
    }
    /* string a = 2 */
    | id id ASSIGN_TOKEN error {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        delete_astnode($2);
        $$ = NULL;
    }
    /* string a';' */
    | id id ';' {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        delete_astnode($2);
        $$ = NULL;
    }
;

functionDeclare: 
    type id '(' <astnode>{
        $$ = $2;
        // printf("current_context_func: %p || name: %s\n", (void *) current_context, $2->context->name);
        last_context = current_context;

        Symbol *sym_declared = lookup_symbol_context($2->context->name, last_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("function redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, @2.first_line, @2.first_column);
            
        } else {
            Symbol *sym_ret;
            sym_ret = list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, FUNCTION);
            isFunctionContext = 1;
            insert_list_element(list_context, create_node(create_symbol_table()));
            Element *iterator;

            for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
                current_context = iterator->value;
            }
            insert_children(current_context, last_context);
            // sym_ret = list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, FUNCTION);
            $2->context->dtype = $1->context->dtype;
            $2->context->sym_ref = sym_ret;
        }
    } optListParams ')' compoundStatement {
        $$ = create_astnode_context(AST_FUNC_DECLARE, "func declare", @$);
        $2->context->last_temp = temporary_count;
        if($1)
            insert_kid($1, $$);
        if($4){
            insert_kid($4, $$);
        }
        if($5){ /* Se existir parametros insira */
            // Cria um noh que recebe os parametros
            AstNode *params = create_astnode_context(AST_LIST_PARAM, "params", @5);

            // Percorre a lista de parametros inserindo os parametros no noh params
            while($5->size) {
                AstNode *aux = remove_first_element_list($5);
                insert_kid(aux, params);
            }
            delete_list($5, delete_list_astnode);
            insert_kid(params, $$);
        }
        insert_kid($7, $$);
    }
;

optListParams:
    %empty {
        $$ = NULL;
    }
    | listParams
;

listParams:
    listParams ',' param {
        insert_list_element($1, $3);
        $$ = $1;
    }
    | param {
        $$ = create_list();
        insert_list_element($$, $1);
    }
    /* Erros */
    /* int func(int a,) */
    | error {
        SHOW_SYNTAX_ERROR("unexpected params || line: %d, column: %d\n", @1.first_line, @1.first_column);
        $$ = NULL;
    }
;

param:
    type id {
        Symbol *sym_declared = lookup_symbol_context($2->context->name, current_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("param redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, @2.first_line, @2.first_column);
            
            $$ = NULL;
            delete_astnode($1);
            delete_astnode($2);
        } else {
            Symbol *sym_ret;
            sym_ret = list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, VARIABLE);
            sym_ret->variable_tac = temporary_count++;
            $$ = create_astnode_context(AST_PARAM, "param", @$);
            insert_kid($1, $$);
            insert_kid($2, $$);
            $2->context->dtype = $1->context->dtype;
            $$->context->dtype = $1->context->dtype;
            $2->context->sym_ref = sym_ret;
        }
    }
    /* Erros */
    /* int func(int) */
    | type {
        SHOW_SYNTAX_ERROR("after '%s' expected identifier || line: %d, column: %d\n", $1->context->name, @1.first_line, @1.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    /* int func(a) */
    | id {
        SHOW_SYNTAX_ERROR("expected type to '%s' || line: %d, column: %d\n", $1->context->name, @1.first_line, @1.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
;

compoundStatement:
    '{' {
        // printf("current_context_compound: %p\n", (void *) current_context);
        if(!isFunctionContext){
            last_context = current_context;
            insert_list_element(list_context, create_node(create_symbol_table()));
            Element *iterator;

            for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
                current_context = iterator->value;
            }
            // printf("current_context: %p || last_context: %p\n", (void *) current_context, (void *) last_context);
            insert_children(current_context, last_context);
        }
        isFunctionContext = 0;
    } optListCodeBlock '}' {
        $$ = create_astnode_context(AST_STATE_COMPOUND, "compound statement", @$);
        if($3){ /* Se existir code block insira */
            // Cria um noh que recebe os code blocks
            AstNode *codeblocks = create_astnode_context(AST_CODE_BLOCK, "code block", @3);

            // Percorre a lista de code blocks inserindo os code blocks no noh code blocks
            while($3->size) {
                AstNode *aux = remove_first_element_list($3);
                insert_kid(aux, codeblocks);
            }
            delete_list($3, delete_list_astnode);
            insert_kid(codeblocks, $$);
        }
        // printf("Atualizando current_context: %p || pai: %p\n", (void *) current_context, (void *) current_context->father);
        current_context = current_context->father;
        // printf("Depois current_context: %p || pai: %p\n", (void *) current_context, (void *) current_context->father);
    }
;

optListCodeBlock:
    %empty {
        $$ = NULL;
    }
    | listCodeBlock
;

listCodeBlock:
    listCodeBlock codeBlock {
        insert_list_element($1, $2);
        $$ = $1;
    }
    | codeBlock {
        $$ = create_list();
        insert_list_element($$, $1);
    }
;

codeBlock:
    statement {
        $$ = $1;
    }
    | variableDeclare {
        $$ = $1;
        // $$ = create_astnode_context(AST_CODE_BLOCK, "", @$);
        // insert_kid($1, $$);
    }
    | elseError
;

statement:
    flowExpression {
        $$ = $1;
    }
    | compoundStatement {
        $$ = $1;
    }
    | expression ';' {
        $$ = $1;
    }
    | ioCommand {
        $$ = $1;
    }
    /* Erros */
    /* 2 1';' */
    | error ';' {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
    /* () */
    | '(' error ')' {
        SHOW_SYNTAX_ERROR("expected expression before ')' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        $$ = NULL;
    }
;

flowExpression:
    condExpression {
        $$ = $1;
    }
    | interationExpression {
        $$ = $1;
    }
    | returnExpression ';' {
        $$ = $1;
    }
;

condExpression:
    IF_TOKEN '(' expression ')' statement %prec IF_TOKEN {
        $$ = create_astnode_context(AST_EXPR_COND, "if cond expression", @$);
        insert_kid($3, $$);
        insert_kid($5, $$);
    }
    | IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement {
        $$ = create_astnode_context(AST_EXPR_COND, "ifelse cond expression", @$);
        insert_kid($3, $$);
        insert_kid($5, $$);
        insert_kid($7, $$);
    }
    /* Erros */
    /* if(){} */
    | IF_TOKEN '(' error ')' statement %prec IF_TOKEN {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($5);
        $$ = NULL;
    }
    /* if(){}else{} */
    | IF_TOKEN '(' error ')' statement ELSE_TOKEN statement {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($5);
        delete_astnode($7);
        $$ = NULL;
    }
    /* if(1+2)else{} */
    | IF_TOKEN '(' expression ')' ELSE_TOKEN statement {
        SHOW_SYNTAX_ERROR("expected expression before 'else' || line: %d, column: %d\n", @5.first_line, @5.first_column);
        delete_astnode($3);
        delete_astnode($6);
        $$ = NULL;
    }
    /* if()else{} */
    | IF_TOKEN '(' error ')' ELSE_TOKEN statement {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($6);
        $$ = NULL;
    }
    /* if */
    | IF_TOKEN error {
        SHOW_SYNTAX_ERROR("expected '(' token || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
;

/* Erros de else */
elseError:
    /* else 1+2';' */
    ELSE_TOKEN statement {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", @1.first_line, @1.first_column);
        delete_astnode($2);
        $$ = NULL;
    }
    /* 1 2 else 1+2';' */
    | error ELSE_TOKEN statement {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        delete_astnode($3);
        $$ = NULL;
    }
;

interationExpression:
    FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement {
        $$ = create_astnode_context(AST_EXPR_ITERATION, "interation expression", @$);
        if($3)
            insert_kid($3, $$);
        if($5)
            insert_kid($5, $$);
        if($7)
            insert_kid($7, $$);
        insert_kid($9, $$);
    }
    /* Erros */
    /* for(1 1';'i > 2';'i++){} */
    | FOR_TOKEN '(' error ';' optExpression ';' optExpression ')' statement {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($5);
        delete_astnode($7);
        delete_astnode($9);
        $$ = NULL;
    }
    /* for(i = 1';'1 2';'i++){} */
    | FOR_TOKEN '(' optExpression ';' error ';' optExpression ')' statement {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", @5.first_line, @5.first_column);
        delete_astnode($3);
        delete_astnode($7);
        delete_astnode($9);
        $$ = NULL;
    }
    /* for(i = 1';'i > 2';'1 2){} */
    | FOR_TOKEN '(' optExpression ';' optExpression ';' error ')' statement {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", @7.first_line, @7.first_column);
        delete_astnode($3);
        delete_astnode($5);
        delete_astnode($9);
        $$ = NULL;
    }
    /* for(1 1';'i=i+1){} */
    | FOR_TOKEN '(' error ';' optExpression ')' statement {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($5);
        delete_astnode($7);
        $$ = NULL;
    }
    /* for(i > 2';'1 1){} */
    | FOR_TOKEN '(' optExpression ';' error ')' statement {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", @5.first_line, @5.first_column);
        delete_astnode($3);
        delete_astnode($7);
        $$ = NULL;
    }
    /* for() */
    | FOR_TOKEN '(' error ')' {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", @4.first_line, @4.first_column);
        $$ = NULL;
    }
    /* for */
    | FOR_TOKEN error {
        SHOW_SYNTAX_ERROR("expected '(' token after 'for' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
;

returnExpression: 
    RETURN_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_RETURN, "return", @$);
        insert_kid($2, $$);
    }
    /* Erros */
    /* return ';' */
    | RETURN_TOKEN error {
        SHOW_SYNTAX_ERROR("'return' with no value, in function returning non-void || line: %d, column: %d\n", @1.first_line, @1.first_column);
        $$ = NULL;
    }
;

optExpression:
    %empty {
        $$ = NULL;
    }
    | expression {
        $$ = $1;
    }
;

expression:
    assignArith {
        $$ = $1;
    }
    | binArith {
        $$ = $1;
    }
    | listArith {
        $$ = $1;
    }
    | unaArith {
        $$ = $1;
    }
    | constant {
        $$ = $1;
    }
    | funcCall {
        $$ = $1;
    }
    | id {
        Symbol *has_sym = lookup_symbol($1->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", $1->context->name, @1.first_line, @1.first_column);
            $$ = NULL;
        } else {
            $$ = $1;
            $$->context->dtype = $1->context->dtype;
            $1->context->sym_ref = has_sym;
        }
    }
    | '(' expression ')' {
        $$ = $2;
        // $$ = create_astnode_context(AST_EXPRESSION, "(exp)", @$);
        // insert_kid($2, $$);
    }
    /* Erros */
    /* i 2 2 */
    | id error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @1.first_line, @1.first_column);
        delete_astnode($1);
        $1 = NULL;
        $$ = NULL;
    }
;

assignArith:
    id {
        Symbol *has_sym = lookup_symbol($1->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", $1->context->name, @1.first_line, @1.first_column);
        } else {
            $1->context->sym_ref = has_sym;
        }
    } ASSIGN_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_ASSIGN, "assign", @$);
        $$->context->operation = strdup("=");
        insert_kid($1, $$);
        insert_kid($4, $$);
    }
;

binArith:
    expression OR_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}", @$);
        $$->context->operation = strdup("||");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression AND_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}", @$);
        $$->context->operation = strdup("&&");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression EQUAL_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}", @$);
        $$->context->operation = strdup("==");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression DIFF_EQ_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}", @$);
        $$->context->operation = strdup("!=");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression LESS_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}", @$);
        $$->context->operation = strdup("<");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression LE_EQ_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}", @$);
        $$->context->operation = strdup("<=");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression GREAT_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}", @$);
        $$->context->operation = strdup(">");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression GR_EQ_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}", @$);
        $$->context->operation = strdup(">=");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '+' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}", @$);
        $$->context->operation = strdup("+");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '-' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}", @$);
        $$->context->operation = strdup("-");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '*' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}", @$);
        $$->context->operation = strdup("*");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '/' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}", @$);
        $$->context->operation = strdup("/");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    /* Erros */
    | expression OR_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression AND_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression EQUAL_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression DIFF_EQ_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression LESS_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression LE_EQ_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression GREAT_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression GR_EQ_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression '+' error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression '-' error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression '*' error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression '/' error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
;

listArith:
    expression MAP_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}", @$);
        $$->context->operation = strdup(">>");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression FILTER_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}", @$);
        $$->context->operation = strdup("<<");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression CONSTRUCTOR_LIST_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}", @$);
        $$->context->operation = strdup(":");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    /* Erros */
    | expression MAP_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression FILTER_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | expression CONSTRUCTOR_LIST_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
;

unaArith:
    EXCLAMATION_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}", @$);
        $$->context->operation = strdup("!");
        insert_kid($2, $$);
    }
    | QUESTION_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}", @$);
        $$->context->operation = strdup("?");
        insert_kid($2, $$);
    }
    | PERCENTAGE_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}", @$);
        $$->context->operation = strdup("%");
        insert_kid($2, $$);
    }
    | '+' expression %prec UNI_OP {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}", @$);
        $$->context->operation = strdup("+");
        insert_kid($2, $$);
    }
    | '-' expression %prec UNI_OP {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}", @$);
        $$->context->operation = strdup("-");
        insert_kid($2, $$);
    }
    /* Erros */
    | EXCLAMATION_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
    | QUESTION_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
    | PERCENTAGE_TOKEN error {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
    | '+' error %prec UNI_OP {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
    | '-' error %prec UNI_OP {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", @2.first_line, @2.first_column);
        $$ = NULL;
    }
;

constant:
    constantInteger {
        // $$ = create_astnode_context(AST_CONSTANT, "constant int", @$);
        // $$->context->dtype = DTYPE_INT;
        // insert_kid($1, $$);
        $$ = $1;
    }
    | constantReal {
        $$ = $1;
    }
    | constantNIL {
        $$ = $1;
    }
;

constantInteger:
    CONSTANT_INTEGER_TOKEN {
        $1->context->dtype = DTYPE_INT;
        $$ = $1;
    }
;

constantReal:
    CONSTANT_REAL_TOKEN {
        $1->context->dtype = DTYPE_FLOAT;
        $$ = $1;
    }
;

constantNIL:
    NIL_TOKEN {
        $1->context->dtype = DTYPE_LIST;
        $$ = $1;
    }
;

funcCall:
    id {
       Symbol *has_sym = lookup_symbol($1->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", $1->context->name, @1.first_line, @1.first_column);
        } else {
            $1->context->sym_ref = has_sym;
        }
    } '(' optListExpression ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call", @$);
        insert_kid($1, $$);
        if($4){
            AstNode *arguments = create_astnode_context(AST_CODE_BLOCK, "arguments", @4);

            while($4->size) {
                AstNode *aux = remove_first_element_list($4);
                insert_kid(aux, arguments);
            }
            delete_list($4, delete_list_astnode);
            insert_kid(arguments, $$);
        }
    }
;

ioCommand:
    READ_TOKEN '(' id ')' ';' {
        Symbol *has_sym = lookup_symbol($3->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", $3->context->name, @3.first_line, @3.first_column);
            $$ = NULL;
        } else {
            $$ = create_astnode_context(AST_BUILT_IN, "read call", @$);
            insert_kid($1, $$);
            $3->context->sym_ref = has_sym;
            insert_kid($3, $$);
        }
    }
    | WRITE_TOKEN '(' expression ')' ';' {
        $$ = create_astnode_context(AST_BUILT_IN, "write call", @$);
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | WRITE_TOKEN '(' STRING_TOKEN ')' ';' {
        $$ = create_astnode_context(AST_BUILT_IN, "write call", @$);
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    /* Erros */
    /* write() */
    | WRITE_TOKEN '(' error ')' ';' {
       SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
       delete_astnode($1);
       $$ = NULL;
    }
    /* read(i) */
    /* read() */
    | READ_TOKEN '(' error ')' ';' {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", @3.first_line, @3.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | READ_TOKEN error ';' {
        SHOW_SYNTAX_ERROR("expected '(' token after 'read' || line: %d, column: %d\n", @1.first_line, @1.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
    | WRITE_TOKEN error ';' {
        SHOW_SYNTAX_ERROR("expected '(' token after 'write' || line: %d, column: %d\n", @1.first_line, @1.first_column);
        delete_astnode($1);
        $$ = NULL;
    }
;

optListExpression:
    %empty {
        $$ = NULL;
    }
    | listExpression
;

listExpression:
    listExpression ',' expression {
        insert_list_element($1, $3);
        $$ = $1;
    }
    | expression {
        $$ = create_list();
        insert_list_element($$, $1);
    }
;

id:
    ID_TOKEN {
        $$ = $1;
    }
;

type:
    INT_TOKEN {
        $$ = create_astnode_context(AST_TYPE_INT, $1, @$);
        $$->context->dtype = DTYPE_INT;
        free($1);
    }
    | FLOAT_TOKEN {
        $$ = create_astnode_context(AST_TYPE_FLOAT, $1, @$);
        $$->context->dtype = DTYPE_FLOAT;
        free($1);
    }
    | INT_TOKEN LIST_TOKEN {
        char *str = (char *) calloc((strlen($1) + strlen($2) + 10), sizeof(char));
        strcat(str, $1);
        strcat(str, " ");
        strcat(str, $2);
        $$ = create_astnode_context(AST_TYPE_INT_LIST, str, @$);
        $$->context->dtype = DTYPE_INT_LIST;
        free(str);
        free($1);
        free($2);
    }
    | FLOAT_TOKEN LIST_TOKEN {
        char *str = (char *) calloc((strlen($1) + strlen($2) + 10), sizeof(char));
        strcat(str, $1);
        strcat(str, " ");
        strcat(str, $2);
        $$ = create_astnode_context(AST_TYPE_FLOAT_LIST, str, @$);
        $$->context->dtype = DTYPE_FLOAT_LIST;
        free(str);
        free($1);
        free($2);
    }
;

%%

void yyerror(const char *error_msg){
    // if (error_msg) {
    //     printf(RED"Line: %d || Column: %d || "RESET, num_line, num_col);
    //     printf(RED"Error: %s || Error count: %d \n"RESET, error_msg, error);
    // }

    if(!error_msg)
        erros++;
}

/* 
*   O primeiro node ja deleta os nodes subsequentes, 
*   assim nao eh necessario deletar os elementos da lista. 
*/
void delete_single_node(Element *node){
    if(!node)
        return;
}

void delete_tree_symbol_table(void *sym){
    SymbolTable *table = sym;
    delete_symbol_table(table, delete_list_symbol_table);
}

void delete_list_treenode(Element *elem){
    TreeNode *node = elem->value;
    delete_node(node, delete_single_node, delete_tree_symbol_table);
}

int main(int argc, char **argv){
    if(argc < 2){
        printf(RED"Error: It is necessary to inform the file path\n"RESET);
        return 0;
    }

    char *fname = argv[1];

    FILE *fp = fopen(fname, "r");
    if(!fp){
        printf(RED"Error: Unable to open file\n"RESET);
        return 0;
    }

    yyin = fp;
    root = create_astnode_context(AST_ROOT, "root", yylloc);
    node_aux = create_list();

    list_context = create_list();
    insert_list_element(list_context, create_node(create_symbol_table()));
    global_context = list_context->first->value;
    current_context = global_context;

    yyparse();

    Symbol *sym_main = lookup_symbol("main", current_context);
    /* Verifica se existe main na tabela de simbolos */
    if(sym_main){
        if(!sym_main->isfunction) {
            SEMANTIC_ERROR("main is not a function\n");
        } else {
            AstNode *main = lookup_node(root, "main");
            AstNode *father = main->father;
            AstNode *params = lookup_node(father, "params");
            Element *it;
            int has_int = 0;
            for(it = father->kids->first; it != NULL; it = it->next){
                if(!strcmp(((AstNode *) it->value)->context->name, "int")){
                    has_int = 1;
                }
            }
            if(!has_int)
                SEMANTIC_ERROR("return type of 'main' is not 'int'\n");
            if(params)
                SEMANTIC_ERROR("'main' takes only zero arguments\n");
        }
    } else {
        SEMANTIC_ERROR("undefined reference to function main\n");
    }

    sem_eval(root);

    if(root->kids->size > 0) {
        printf("\n##################### %s #####################\n", "Abstract Syntax Tree");
        print_tree(root, 0);
        printf("\n");
    } else 
        printf(RED"AST error: " RESET "unable to print AST\n");

    Element *iterator;
    /* TODO: Arrumar if */
    if(((SymbolTable *)((TreeNode *) list_context->first->value)->value)->symbols->size > 0){
        for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
            if(((SymbolTable *)((TreeNode *)iterator->value)->value)->symbols->size > 0) {
                printf("########################## %s #########################\n", "Symbol Table");
                printf("# %-14s || %11s || %-10s || %4s || %6s #\n", "Type", "Symbol Kind", "ID", "Line", "Column");
                print_list(((SymbolTable *)((TreeNode *)iterator->value)->value)->symbols, print_symbol_list);
                printf("#################################################################\n");
            }
        }
    } else 
        printf(RED"Symbol Table error: " RESET "unable to print symbol table\n");

    if(erros > 0)
        printf(RED"Error count: "RESET"%d\n", erros);
    else {
        char *tac_out_name = calloc(sizeof("./") + sizeof(fname) + sizeof(".tac") + 20, sizeof(char));
        strcat(tac_out_name, "./");
        char *fname_without_ext = calloc(strlen(fname) + 20, sizeof(char));
        sscanf(fname, "%[^.]", fname_without_ext);
        strcat(tac_out_name, fname_without_ext);
        strcat(tac_out_name, ".tac");

        FILE *output = fopen(tac_out_name, "w+");
        free(tac_out_name);
        free(fname_without_ext);

        code_gen(root, output);
        fclose(output);
    }

    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_list(list_context, delete_list_treenode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}