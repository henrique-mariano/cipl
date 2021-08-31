%define lr.type canonical-lr
%{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex();
    int yyerror(char *error_msg);
}

startProgram:
    variableDeclare
    | functionDeclare
;

variableDeclare:
    type id
;

functionDeclare:
    type id '('params')' compountStatement
;

compountStatement:
    '{' codeBlock '}'
;

codeBlock:
    statement
    | variableDeclare
;

statement:
    flow_expression
    | compountStatement
    | expression
;

expression:
    expression '=' expression
    | expression binArith expression
    | unaArith expression
    | constantInteger
    | constantReal
;

id:
    ID_TOKEN
;