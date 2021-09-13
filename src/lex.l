%option nounput noinput noyywrap

%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #define DEBUG_LEX 0

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "lib/bison.h"
    #include "lib/tree.h"
    #include "lib/astcontext.h"

    int num_line = 1, num_col = 1, error = 0, scope = 0;

    void print_token(char *type);
%}

SIMPLE_TYPES            "int"|"float"
LIST_TYPES              int{WS}+list|float{WS}+list
TYPES                   {SIMPLE_TYPES}|{LIST_TYPES}

DIGIT                   [0-9]
CONSTANT_INTEGER        ([1-9]{DIGIT}*|0)
CONSTANT_REAL           ({DIGIT}*\.)?{DIGIT}+([Ee][+-]?{DIGIT}+)?
STRING                  \"([^\n"\\]|(\\.))*\"

OP_BINARY_ARITHMETIC    "+"|"-"|"*"|"/"
OP_LOGIC                "||"|"&&"
OP_BINARY_RELATIONAL    "<"|"<="|">"|">="|"=="|"!="

OP_BINARY               {OP_BINARY_ARITHMETIC}|{OP_BINARY_RELATIONAL}|{OP_LOGIC}|{OP_BINARY_LIST}

OP_UNARY                "!"|"?"|"%"|"+"|"-"

OP_BINARY_LIST          "<<"|">>"|":"
COMMAND_FLOW_CONTROL    if|else|for|return|NIL
COMMAND_INPUT_OUTPUT    read|write|writeln

DELIM                   [ \t\r]
WS                      {DELIM}
LETTER                  [A-Za-z_]
WORD                    [A-Za-z0-9_]
ID                      {LETTER}({WORD})*
BRACKET                 [\[\]{}\(\)]
COMMA                   [,;]

SINGLE_COMMENT          ("//"((.*)|[^\n]))

%%
{WS} {
    num_col += yyleng;
}

\n {
    num_line += yyleng;
    num_col = 1;
}

{SINGLE_COMMENT} {}

{SIMPLE_TYPES} {
    if(DEBUG_LEX == 1) print_token("SIMPLE_TYPE");
    num_col += yyleng;
    switch(yytext[0]){
        case 'i':
            yylval = create_astnode_context(AST_TYPE, yytext);
            return INT_TOKEN;
        case 'f':
            yylval = create_astnode_context(AST_TYPE, yytext);
            return FLOAT_TOKEN;
    }
}

{LIST_TYPES} {
    if(DEBUG_LEX == 1) print_token("LIST_TYPES");
    num_col += yyleng;
    switch(yytext[0]){
        case 'i':
            yylval = create_astnode_context(AST_TYPE, yytext);
            return INT_LIST_TOKEN;
        case 'f':
            yylval = create_astnode_context(AST_TYPE, yytext);
            return FLOAT_LIST_TOKEN;
    }
}

{CONSTANT_INTEGER} {
    if(DEBUG_LEX == 1) print_token("Constant integer");
    num_col += yyleng;
    yylval = create_astnode_context(AST_CONSTANT_INT, yytext);
    return CONSTANT_INTEGER_TOKEN;
}

{CONSTANT_REAL} {
    if(DEBUG_LEX == 1) print_token("Constant real");
    num_col += yyleng;
    yylval = create_astnode_context(AST_CONSTANT_REAL, yytext);
    return CONSTANT_REAL_TOKEN;
}

{STRING} {
    if(DEBUG_LEX == 1) print_token("String");
    num_col += yyleng;
    return STRING_TOKEN;
}

{OP_BINARY_ARITHMETIC} {
    if(DEBUG_LEX == 1) print_token("Arithmetic operation");
    num_col += yyleng;
    switch(yytext[0]){
        case '+':
        case '-':
            return ADD_MIN_TOKEN;
        case '*':
        case '/':
            return MUL_DIV_TOKEN;
    }
}

{OP_LOGIC} {
    if(DEBUG_LEX == 1) print_token("Logic operation");
    num_col += yyleng;
    switch(yytext[0]){
        case '|':
            return OR_TOKEN;
        case '&':
            return AND_TOKEN;
    }
}

{OP_BINARY_RELATIONAL} {
    if(DEBUG_LEX == 1) print_token("Relational operation");
    num_col += yyleng;
    switch(yytext[0]){
        case '<':
        case '>':
            return LE_GR_TOKEN;
        case '=':
        case '!':
            return EQ_EXC_TOKEN;
    }
}

{OP_UNARY} {
    if(DEBUG_LEX == 1) print_token("Unary operation list");
    num_col += yyleng;
    switch(yytext[0]){
        case '!':
            return EXCLAMATION_TOKEN;
        case '?':
            return QUESTION_TOKEN;
        case '%':
            return PERCENTAGE_TOKEN;
        case '+':
        case '-':
            return ADD_MIN_TOKEN;
    }
}

{OP_BINARY_LIST} {
    if(DEBUG_LEX == 1) print_token("Binary operation list");
    num_col += yyleng;
    switch(yytext[0]){
        case '>':
            return MAP_TOKEN;
        case '<':
            return FILTER_TOKEN;
        case ':':
            return CONSTRUCTOR_LIST_TOKEN;
    }
}

{COMMAND_FLOW_CONTROL} {
    if(DEBUG_LEX == 1) print_token("Flow control command");
    num_col += yyleng;
    switch(yytext[0]){
        case 'i':
            return IF_TOKEN;
        case 'e':
            return ELSE_TOKEN;
        case 'f':
            return FOR_TOKEN;
        case 'r':
            return RETURN_TOKEN;
        case 'N':
            yylval = create_astnode_context(AST_CONSTANT_NIL, yytext);
            return NIL_TOKEN;
    }
}

{COMMAND_INPUT_OUTPUT} {
    if(DEBUG_LEX == 1) print_token("IN/OUT operation");
    num_col += yyleng;
    switch(yytext[0]){
        case 'r':
            return READ_TOKEN;
        case 'w':
            return WRITE_TOKEN;
    }
}

{ID} {
    if(DEBUG_LEX == 1) print_token("ID");
    num_col += yyleng;
    yylval = create_astnode_context(AST_ID, yytext);
    return ID_TOKEN;
}

{BRACKET} {
    num_col += yyleng;
    if(DEBUG_LEX == 1) print_token("Bracket");
    return yytext[0];
}

{COMMA} {
    num_col += yyleng;
    if(DEBUG_LEX == 1) print_token("Comma");
    return yytext[0];
}

= {
    if(DEBUG_LEX == 1) print_token("Assign");
    num_col += yyleng;
    return ASSIGN_TOKEN;
}

. {
    error++;
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Unexpected character: %s || Error count: %d\n", yytext, error);
    num_col += yyleng;
}
%%

void print_token(char *type){
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("%s: %s\n", type, yytext);
}