%define lr.type canonical-lr
%define parse.error verbose
%define api.header.include {"lib/bison.h"}
%define api.value.type {struct AstNode*}
%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include "lib/tree.h"
    #include "lib/astcontext.h"

    extern int error, num_line, num_col;
    
    extern int yyparse();
    extern int yylex();
    extern int yylex_destroy();
    extern void yyerror(const char *error_msg);

    extern FILE *yyin;

    /* No raiz da arvore sintatica abstrata */
    AstNode *root;

    /* Lista para ajudar na criacao da arvore */
    List *node_aux;

%}

// %union{
//     struct AstNode *astnode;
// }

/* Declaração de tipos e tokens */
/* Tipação da regra */
//%type<astnode> declaration variableDeclare type id
//%type<astnode> functionDeclare param optListParams listParams
//%type<astnode> statement listCodeBlock codeBlock expression
//%type<astnode> binArith listArith 

%token INT_TOKEN FLOAT_TOKEN INT_LIST_TOKEN FLOAT_LIST_TOKEN /* Tipos */
%token ID_TOKEN READ_TOKEN WRITE_TOKEN /* IDs */
%token NIL_TOKEN CONSTANT_REAL_TOKEN CONSTANT_INTEGER_TOKEN /* Constantes */
%token MUL_DIV_TOKEN EXCLAMATION_TOKEN QUESTION_TOKEN PERCENTAGE_TOKEN/* Operadores */
%token MAP_TOKEN FILTER_TOKEN CONSTRUCTOR_LIST_TOKEN ADD_MIN_TOKEN /* */
%token ASSIGN_TOKEN OR_TOKEN AND_TOKEN EQ_EXC_TOKEN LE_GR_TOKEN /* */

%token IF_TOKEN ELSE_TOKEN FOR_TOKEN RETURN_TOKEN STRING_TOKEN

/* Precedencia dos operadores */
%right ASSIGN_TOKEN
%left OR_TOKEN
%left AND_TOKEN
%left EQ_EXC_TOKEN
%left LE_GR_TOKEN
%left MAP_TOKEN
%left FILTER_TOKEN
%left CONSTRUCTOR_LIST_TOKEN
%left ADD_MIN_TOKEN
%left MUL_DIV_TOKEN
%right EXCLAMATION_TOKEN
%right QUESTION_TOKEN
%right PERCENTAGE_TOKEN

%precedence IF_TOKEN
%precedence ELSE_TOKEN

// %destructor{
//     delete_astnode($$);
// }<>

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
        $$ = create_astnode_context(AST_VAR_DECLARE, "variable declare");
        insert_kid($1, $$);
        insert_kid($2, $$);
    }
;

functionDeclare: 
    type id '(' optListParams ')' compoundStatement {
        /* Lidar com contextos */
        $$ = create_astnode_context(AST_FUNC_DECLARE, "func declare");
        insert_kid($1, $$);
        insert_kid($2, $$);

        if($4) /* Se existir parametros insira */
            insert_kid($4, $$);
        insert_kid($6, $$);
    }
;

optListParams:
    %empty {
        $$ = NULL;
    }
    | listParams {
        // printf("Lista de params\n");
        $$ = create_astnode_context(AST_LIST_PARAM, "params");
        /* Retira os elementos da lista auxiliar 
        e depois adiciona como filhos ao no listParam */
        do{
            insert_kid(remove_first_element_list(node_aux), $$);
        } while(node_aux->size >= 1);
    }
;

listParams:
    listParams ',' param
    | param
;

param:
    type id {
        $$ = create_astnode_context(AST_PARAM, "param");
        insert_kid($1, $$);
        insert_kid($2, $$);

        /* Adiciona os parametros na lista auxiliar */

        insert_list_element(node_aux, $$);
    }
;


compoundStatement:
    '{' optListCodeBlock '}' {
        // printf("CompoundStatement\n");
        $$ = create_astnode_context(AST_STATE_COMPOUND, "compound statement");
        if($2)
            insert_kid($2, $$);
    }
;

optListCodeBlock:
    %empty {
        $$ = NULL;
    }
    | listCodeBlock{
        $$ = create_astnode_context(AST_LIST_CODEBLOCK, "code block");
        do{
            insert_kid(remove_first_element_list(node_aux), $$);
        } while(node_aux->size >= 1);
    }
;

listCodeBlock:
    listCodeBlock codeBlock
    | codeBlock
;

codeBlock:
    statement {
        $$ = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid($1, $$);
        insert_list_element(node_aux, $$);
    }
    | variableDeclare {
        $$ = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid($1, $$);
        insert_list_element(node_aux, $$);
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
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria or");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression AND_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria and");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression EQ_EXC_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria ==!");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression LE_GR_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria <>");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression ADD_MIN_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria +-");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression MUL_DIV_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria */");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
;

listArith:
    expression MAP_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "aritmetica binaria de lista map");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression FILTER_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "aritmetica binaria de lista filter");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
    | expression CONSTRUCTOR_LIST_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_LIST_ARITH, "aritmetica binaria de lista constructor");
        insert_kid($1, $$);
        insert_kid($3, $$);
    }
;

unaArith:
    EXCLAMATION_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria !");
        insert_kid($2, $$);
    }
    | QUESTION_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria ?");
        insert_kid($2, $$);
    }
    | PERCENTAGE_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria %");
        insert_kid($2, $$);
    }
    | ADD_MIN_TOKEN expression {
        $$ = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria +-");
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

funcCall:
    id '(' optExpression ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid($1, $$);
        if($3)
            insert_kid($3, $$);
    }
    | READ_TOKEN '(' optExpression ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid($1, $$);
        if($3)
            insert_kid($3, $$);
    }
    | WRITE_TOKEN '(' optExpression ')' {
        $$ = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid($1, $$);
        if($3)
            insert_kid($3, $$);
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
    yyparse();
    print_tree(root, 0);
    // print_list(node_aux);
    printf("Tamanho lista: %d\n", node_aux->size);
    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}