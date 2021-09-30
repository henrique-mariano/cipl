%define lr.type canonical-lr
%define parse.error detailed
%define api.header.include {"lib/bison.h"}

%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include "lib/tree.h"
    #include "lib/astcontext.h"
    #include "lib/symbol.h"
    #include "lib/context.h"
    #include "lib/treenode.h"

    #define FUNCTION 1
    #define VARIABLE 0

    extern int error, num_line, num_col;

    // static int symbol_id;

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

    /* Tabela de simbolos */
    // SymbolTable *symbol_table;

    void delete_single_node(Element *node);
    void delete_list_treenode(Element *elem);
    void delete_tree_symbol_table(void *sym);

%}

%union{
    struct AstNode *astnode;
    struct Symbol *symbol;
    struct List *list;
}

/* Declaração de tipos e tokens */
/* Tipação da regra */
%type<astnode> declaration variableDeclare type id
%type<astnode> functionDeclare param
%type<astnode> statement codeBlock expression
%type<astnode> binArith listArith compoundStatement
%type<astnode> flowExpression condExpression interationExpression
%type<astnode> optExpression returnExpression unaArith constant
%type<astnode> constantInteger constantReal constantNIL funcCall
%type<astnode> constantString
%type<astnode> FLOAT_LIST_TOKEN INT_LIST_TOKEN FLOAT_TOKEN INT_TOKEN
%type<astnode> ID_TOKEN READ_TOKEN WRITE_TOKEN STRING_TOKEN
%type<astnode> CONSTANT_INTEGER_TOKEN CONSTANT_REAL_TOKEN NIL_TOKEN

%type<list> optListParams listParams optListCodeBlock listCodeBlock
%type<list> listExpression optListExpression

%token INT_TOKEN FLOAT_TOKEN INT_LIST_TOKEN FLOAT_LIST_TOKEN /* Tipos */
%token ID_TOKEN READ_TOKEN WRITE_TOKEN /* IDs */
%token NIL_TOKEN CONSTANT_REAL_TOKEN CONSTANT_INTEGER_TOKEN /* Constantes */
%token MUL_DIV_TOKEN EXCLAMATION_TOKEN QUESTION_TOKEN PERCENTAGE_TOKEN/* Operadores */
%token MAP_TOKEN FILTER_TOKEN CONSTRUCTOR_LIST_TOKEN ADD_MIN_TOKEN /* */
%token ASSIGN_TOKEN OR_TOKEN AND_TOKEN EQ_EXC_TOKEN LE_GR_TOKEN /* */
%token ADD_UNARY_TOKEN MIN_UNARY_TOKEN
%token EQUAL_TOKEN DIFF_EQ_TOKEN
%token LESS_TOKEN LE_EQ_TOKEN GREAT_TOKEN GR_EQ_TOKEN
%token ADD_TOKEN MIN_TOKEN
%token MUL_TOKEN DIV_TOKEN
%token UNI_OP

%token IF_TOKEN ELSE_TOKEN FOR_TOKEN RETURN_TOKEN STRING_TOKEN

/* Precedencia dos operadores */
%right ASSIGN_TOKEN
%left OR_TOKEN
%left AND_TOKEN
%left EQUAL_TOKEN DIFF_EQ_TOKEN
%left LESS_TOKEN LE_EQ_TOKEN GREAT_TOKEN GR_EQ_TOKEN
%left MAP_TOKEN
%left FILTER_TOKEN
%left CONSTRUCTOR_LIST_TOKEN
%left '+' '-'
%left '*' '/'
%right EXCLAMATION_TOKEN
%right QUESTION_TOKEN
%right PERCENTAGE_TOKEN
%right UNI_OP

%precedence IF_TOKEN
%precedence ELSE_TOKEN

%destructor{
    delete_astnode($$);
}<astnode>

%%

startProgram:
    startProgram declaration {
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
;

variableDeclare:
    type id ';' {
        // current_context = current_context;
        // printf("current_context_var: %p || name: %s\n", (void *) current_context, $2->context->name);
        Symbol *sym_declared = lookup_symbol_context($2->context->name, current_context);
        if(sym_declared != NULL){
            printf("Semantic Error: Variable redeclaration || Value: %s\n", sym_declared->name);
            $$ = NULL;
            delete_astnode($1);
            delete_astnode($2);
        } else {
            list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, VARIABLE);
            $$ = create_astnode_context(AST_VAR_DECLARE, "variable declare");
            insert_kid($1, $$);
            insert_kid($2, $$);
        }
    }
;

functionDeclare: 
    type id '(' <astnode>{
        $$ = $2;
        // printf("current_context_func: %p || name: %s\n", (void *) current_context, $2->context->name);
        last_context = current_context;

        Symbol *sym_declared = lookup_symbol_context($2->context->name, last_context);

        if(sym_declared != NULL){
            printf("Semantic Error: Function redeclaration || Value: %s\n", sym_declared->name);
        } else {
            list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, FUNCTION);
            isFunctionContext = 1;
            insert_list_element(list_context, create_node(create_symbol_table()));
            Element *iterator;

            for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
                current_context = iterator->value;
            }
            insert_children(current_context, last_context);
        }
    } optListParams ')' compoundStatement {
        $$ = create_astnode_context(AST_FUNC_DECLARE, "func declare");
        
        if($1)
            insert_kid($1, $$);
        if($4){
            insert_kid($4, $$);
        }
        if($5){ /* Se existir parametros insira */
            // Cria um noh que recebe os parametros
            AstNode *params = create_astnode_context(AST_LIST_PARAM, "params");

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
;

param:
    type id {
        Symbol *sym_declared = lookup_symbol_context($2->context->name, current_context);
        if(sym_declared != NULL){
            printf("Semantic Error: Param redeclaration || Value: %s\n", sym_declared->name);
            $$ = NULL;
            delete_astnode($1);
            delete_astnode($2);
        } else {
            list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, VARIABLE);
            $$ = create_astnode_context(AST_PARAM, "param");
            insert_kid($1, $$);
            insert_kid($2, $$);
        }
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
        $$ = create_astnode_context(AST_STATE_COMPOUND, "compound statement");
        if($3){ /* Se existir code block insira */
            // Cria um noh que recebe os code blocks
            AstNode *codeblocks = create_astnode_context(AST_CODE_BLOCK, "code block");

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
        $$ = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid($1, $$);
    }
    | variableDeclare {
        $$ = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid($1, $$);
    }
;

statement:
    flowExpression {
        $$ = create_astnode_context(AST_STATEMENT, "");
        insert_kid($1, $$);
    }
    | compoundStatement {
        $$ = create_astnode_context(AST_STATEMENT, "");
        insert_kid($1, $$);
    }
    | expression ';' {
        $$ = create_astnode_context(AST_STATEMENT, "");
        insert_kid($1, $$);
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
        $$ = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid($3, $$);
        insert_kid($5, $$);
    }
    | IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement {
        $$ = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid($3, $$);
        insert_kid($5, $$);
        insert_kid($7, $$);
    }
;

interationExpression:
    FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement {
        $$ = create_astnode_context(AST_EXPR_ITERATION, "interation expression");
        if($3)
            insert_kid($3, $$);
        if($5)
            insert_kid($5, $$);
        if($7)
            insert_kid($7, $$);
        insert_kid($9, $$);
    }
;

returnExpression: 
    RETURN_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_RETURN, "return expression");
        insert_kid($2, $$);
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
    id ASSIGN_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_ASSIGN, "assign");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | binArith {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($1, $$);
    }
    | listArith {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($1, $$);
    }
    | unaArith {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($1, $$);
    }
    | constant {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($1, $$);
    }
    | funcCall {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($1, $$);
    }
    | id {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($1, $$);
    }
    | '(' expression ')' {
        $$ = create_astnode_context(AST_EXPRESSION, "");
        insert_kid($2, $$);
    }
;

binArith:
    expression OR_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression AND_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression EQUAL_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression DIFF_EQ_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression LESS_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression LE_EQ_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression GREAT_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression GR_EQ_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '+' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '-' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '*' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression '/' expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
;

listArith:
    expression MAP_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression FILTER_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression CONSTRUCTOR_LIST_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
;

unaArith:
    EXCLAMATION_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}");
        insert_kid($2, $$);
    }
    | QUESTION_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}");
        insert_kid($2, $$);
    }
    | PERCENTAGE_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}");
        insert_kid($2, $$);
    }
    | '+' expression %prec UNI_OP {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}");
        insert_kid($2, $$);
    }
    | '-' expression %prec UNI_OP {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}");
        insert_kid($2, $$);
    }
;

constant:
    constantInteger {
        $$ = create_astnode_context(AST_CONSTANT, "constant int");
        insert_kid($1, $$);
    }
    | constantReal {
        $$ = create_astnode_context(AST_CONSTANT, "constant real");
        insert_kid($1, $$);
    }
    | constantNIL {
        $$ = create_astnode_context(AST_CONSTANT, "constant nil");
        insert_kid($1, $$);
    }
    | constantString {
        $$ = create_astnode_context(AST_CONSTANT, "constant string");
        insert_kid($1, $$);
    }
;

constantInteger:
    CONSTANT_INTEGER_TOKEN {
        $$ = $1;
    }
;

constantReal:
    CONSTANT_REAL_TOKEN {
        $$ = $1;
    }
;

constantNIL:
    NIL_TOKEN {
        $$ = $1;
    }
;

constantString:
    STRING_TOKEN {
        $$ = $1;
    }
;

funcCall:
    id '(' optListExpression ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid($1, $$);
        if($3){
            AstNode *arguments = create_astnode_context(AST_CODE_BLOCK, "arguments");

            while($3->size) {
                AstNode *aux = remove_first_element_list($3);
                insert_kid(aux, arguments);
            }
            delete_list($3, delete_list_astnode);
            insert_kid(arguments, $$);
        }
    }
    | READ_TOKEN '(' id ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | WRITE_TOKEN '(' optListExpression ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid($1, $$);
        if($3){
            AstNode *arguments = create_astnode_context(AST_CODE_BLOCK, "arguments");

            while($3->size) {
                AstNode *aux = remove_first_element_list($3);
                insert_kid(aux, arguments);
            }
            delete_list($3, delete_list_astnode);
            insert_kid(arguments, $$);
        }
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
        $$ = $1;
    }
    | FLOAT_TOKEN {
        $$ = $1;
    }
    | INT_LIST_TOKEN {
        $$ = $1;
    }
    | FLOAT_LIST_TOKEN {
        $$ = $1;
    }
;

%%

void yyerror(const char *error_msg){
    error++;
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Error: %s || Error count: %d \n", error_msg, error);
}

void delete_single_node(Element *node){
    if(!node)
        return;

    // Element *current = ((TreeNode *) node->value)->children->first;
    // free(((TreeNode *) node->value));
    // Element *next;
    // while(current != NULL){
    //     next = current->next;
    //     free_element(current, delete_single_node);
    //     current = next;
    // }
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
        printf("Error: It is necessary to inform the file path\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        printf("Error: Unable to open file\n");
        return 0;
    }

    yyin = fp;
    root = create_astnode_context(AST_ROOT, "root");
    node_aux = create_list();

    list_context = create_list();
    // global_context = create_node(create_symbol_table());
    insert_list_element(list_context, create_node(create_symbol_table()));
    global_context = list_context->first->value;
    current_context = global_context;

    yyparse();

    if(root->kids->size > 0) {
        printf("##################### %s #####################\n", "Abstract Syntax Tree");
        print_tree(root, 0);
        printf("\n");
    } else {
        printf("Unable to print AST\n");
    }

    Element *iterator;
    // int i = 0;
    if(((SymbolTable *)((TreeNode *) list_context->first->value)->value)->symbols->size > 0){
        for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
            printf("########################## %s #########################\n", "Symbol Table");
            printf("# %-14s || %11s || %-10s || %4s || %6s #\n", "Type", "Symbol Kind", "ID", "Line", "Column");
            if(((SymbolTable *)((TreeNode *)iterator->value)->value)->symbols->size > 0) {
                print_list(((SymbolTable *)((TreeNode *)iterator->value)->value)->symbols, print_symbol_list);
            }
            printf("#################################################################\n");
        }
    } else {
        printf("Unable to print Symbol Table\n");
    }
    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    // delete_symbol_table(symbol_table, delete_list_symbol_table);
    delete_list(list_context, delete_list_treenode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}