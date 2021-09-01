%define lr.type canonical-lr
%define parse.error verbose
%define api.header.include {"lib/bison.h"}
%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include "lib/tree.h"

    extern int error, num_line, num_col;
    
    extern int yyparse();
    extern int yylex();
    extern int yylex_destroy();
    extern void yyerror(const char *error_msg);

    extern FILE *yyin;

%}

%union{
    AstNode *AstNode;
}

%type<AstNode> variableDeclare /* Tipação da regra */
%token<AstNode> INT_TOKEN FLOAT_TOKEN INT_LIST_TOKEN FLOAT_LIST_TOKEN /* Tipos */
%token<AstNode> ID_TOKEN READ_TOKEN WRITE_TOKEN /* IDs */
%token<AstNode> NIL_TOKEN CONSTANT_REAL_TOKEN CONSTANT_INTEGER_TOKEN /* Constantes */
%token IF_TOKEN ELSE_TOKEN FOR_TOKEN RETURN_TOKEN

%destructor{
    free($$);
}<name>

%%

startProgram:
    listVariablesDeclare
    | listFunctionsDeclare
;

variableDeclare:
    type id ';'
;

listVariablesDeclare:
    listVariablesDeclare variableDeclare
    | variableDeclare
;

functionDeclare:
    type id '(' listParams ')' compountStatement
;

listFunctionsDeclare:
    listFunctionsDeclare functionDeclare
    | functionDeclare
;

optListParams:
    %empty
    | listParams
;

listParams:
    listParams ',' param
    | param
;

param:
    type id
;


compountStatement:
    '{' optListCodeBlock '}'
;

codeBlock:
    statement
    | variableDeclare
;

optListCodeBlock:
    %empty
    | listCodeBlock
;

listCodeBlock:
    listCodeBlock codeBlock
    | codeBlock
;

statement:
    flowExpression
    | compountStatement
    | expression ';'
;

flowExpression:
    condExpression
    | interationExpression
    | returnExpression ';'
;

condExpression:
    IF_TOKEN '(' expression ')' statement
    | IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement
;

interationExpression:
    FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement
;

returnExpression:
    RETURN_TOKEN
    | RETURN_TOKEN expression
;

expression:
    | binArith
    | listArith
    | unaArith
    | constant
;

optExpression:
    %empty
    | expression
;

binArith:
    expression ASSIGN_TOKEN expression
    | expression NEQUAL_TOKEN expression
    | expression OR_TOKEN expression
    | expression AND_TOKEN expression
    | expression LE_GR_TOKEN expression
    | expression EQ_EXC_TOKEN expression
    | expression ADD_MIN_TOKEN expression
    | expression MUL_DIV_TOKEN expression
;

listArith:
    expression MAP_TOKEN expression
    | expression FILTER_TOKEN expression
    | expression CONSTRUCTOR_LIST_TOKEN
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
        printf("Inteiro: %s\n", $1);
    }
;

constantReal:
    CONSTANT_REAL_TOKEN {
        printf("Float: %s\n", $1);
    }
;

constantNIL:
    NIL_TOKEN {
        printf("NIL: %s\n", $1);
    }
;

id:
    ID_TOKEN {
        printf("ID: %s\n", $1);
    }
    | READ_TOKEN {
        printf("READ: %s\n", $1);
    }
    | WRITE_TOKEN {
        printf("WRITE: %s\n", $1);
    }
;

type:
    INT_TOKEN {
        printf("INTTOKEN %s\n", $1);
    }
    | FLOAT_TOKEN {
        printf("FLOATTOKEN %s\n", $1);
    }
    | INT_LIST_TOKEN {
        printf("INTLISTTOKEN %s\n", $1);
    }
    | FLOAT_LIST_TOKEN {
        printf("FLOATLISTTOKEN %s\n", $1);
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

    AstNode *root = create_AstNode();

    yyin = fp;
    yyparse();
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}