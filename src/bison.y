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
//     free($$);
// }<astnode>

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
    variableDeclare
    | functionDeclare
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
        printf("FUNC DECLARE\n");
        insert_kid($1, $$);
        insert_kid($2, $$);

        if($4)
            insert_kid($4, $$);
        insert_kid($6, $$);
        // delete_context_ast(node_aux);
    }
;

optListParams:
    %empty {
        $$ = NULL;
    }
    | listParams {
        printf("Lista de params\n");
        $$ = create_astnode_context(AST_PARAM, "listParam");
        /* Retira os elementos da lista auxiliar 
        e depois adiciona como filhos ao no listParam */
        insert_kid(pop_element_list(node_aux), $$);
        insert_kid(pop_element_list(node_aux), $$);
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
        printf("CompoundStatement\n");
        $$ = create_astnode_context(AST_STATE_FLOW, "compound statement");
        if($2)
            insert_kid($2, $$);
    }
;

optListCodeBlock:
    %empty {
        $$ = NULL;
    }
    | listCodeBlock{
        $$ = $1;
    }
;

listCodeBlock:
    listCodeBlock codeBlock {
        $$ = create_astnode_context(AST_STATE_FLOW, "code block");
        insert_kid($1, $$);
        insert_kid($2, $$);
    }
    | codeBlock {
        $$ = create_astnode_context(AST_STATE_FLOW, "code block");
        insert_kid($1, $$);
    }
;

codeBlock:
    statement
    | variableDeclare {
        $$ = $1;
    }
;

statement:
    flowExpression {
        $$ = create_astnode_context(AST_STATE_FLOW, "statement flow");
    }
    | compoundStatement {
        // printf("Compound Statement\n");
        $$ = create_astnode_context(AST_STATE_COMPOUND, "statement compound");
    }
    | expression ';'
;

flowExpression:
    condExpression
    | interationExpression
    | returnExpression ';'
;

condExpression:
    IF_TOKEN '(' expression ')' statement %prec IF_TOKEN
    | IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement
;

interationExpression:
    FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement
;

returnExpression:
    RETURN_TOKEN
    | RETURN_TOKEN expression
    | RETURN_TOKEN id
;

optExpression:
    %empty
    | expression
;

expression:
    binArith
    | listArith
    | unaArith
    | constant
;

binArith:
    expression ASSIGN_TOKEN expression
    | expression OR_TOKEN expression
    | expression AND_TOKEN expression
    | expression EQ_EXC_TOKEN expression
    | expression LE_GR_TOKEN expression
    | expression ADD_MIN_TOKEN expression
    | expression MUL_DIV_TOKEN expression
;

listArith:
    expression MAP_TOKEN expression
    | expression FILTER_TOKEN expression
    | expression CONSTRUCTOR_LIST_TOKEN expression
;

unaArith:
    EXCLAMATION_TOKEN expression
    | QUESTION_TOKEN expression 
    | PERCENTAGE_TOKEN expression
    | ADD_MIN_TOKEN expression
;

constant:
    constantInteger
    | constantReal
    | constantNIL
;

constantInteger:
    CONSTANT_INTEGER_TOKEN {
        printf("CONSTANT_INTEGER_TOKEN\n");
        // insert_kid($1, root);
    }
;

constantReal:
    CONSTANT_REAL_TOKEN {
        printf("CONSTANT_REAL_TOKEN\n");
        // insert_kid($1, root);
    }
;

constantNIL:
    NIL_TOKEN {
        ;
    }
;

id:
    ID_TOKEN {
        printf("ID_TOKEN\n");
        // insert_kid($1, root);
    }
    | READ_TOKEN {
        ;
    }
    | WRITE_TOKEN {
        ;
    }
;

type:
    INT_TOKEN {
        printf("INT_TOKEN\n");
        // printf("contexto: %s\n", $$->context->name);
        // insert_kid($1, root);
    }
    | FLOAT_TOKEN {
        printf("FLOAT_TOKEN\n");
        // insert_kid($1, root);
    }
    | INT_LIST_TOKEN {
        printf("INT_LIST_TOKEN\n");
        // insert_kid($1, root);
    }
    | FLOAT_LIST_TOKEN {
        printf("INT_LIST_TOKEN\n");
        // insert_kid($1, root);
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
    // printf("%d\n", node_aux->size);
    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}