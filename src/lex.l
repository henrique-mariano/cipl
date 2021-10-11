%option nounput noinput noyywrap yylineno

%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280

    int yycolumn = 1;

    #define YY_USER_ACTION                                       \
    yylloc.first_line = yylloc.last_line = yylineno;             \
    yylloc.first_column = yycolumn;                              \
    if (yytext[0] == '\n') {                                     \
        yycolumn =  1;                                           \
    } else {                                                     \
        yycolumn += yyleng;                                      \
    }                                                            \
    yylloc.last_column = yycolumn - 1;


    #define DEBUG_LEX 0
    #define RED "\033[1;31m"
    #define RESET "\033[0m"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #include "lib/bison.h"
    #include "lib/tree.h"
    #include "lib/astcontext.h"

    int num_line = 1, num_col = 1, error = 0, scope = 0, symbol_id = 0;

    void print_token(char *type);
%}

SIMPLE_TYPES            "int"|"float"
LIST_TYPES              "list"

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
            yylval.string = strdup(yytext);
            return INT_TOKEN;
        case 'f':
            yylval.string = strdup(yytext);
            return FLOAT_TOKEN;
    }
}

{LIST_TYPES} {
    if(DEBUG_LEX == 1) print_token("LIST_TYPES");
    num_col += yyleng;
    yylval.string = strdup(yytext);
    return LIST_TOKEN;
}

{CONSTANT_INTEGER} {
    if(DEBUG_LEX == 1) print_token("Constant integer");
    num_col += yyleng;
    yylval.astnode = create_astnode_context(AST_CONSTANT_INT, yytext, yylloc);
    return CONSTANT_INTEGER_TOKEN;
}

{CONSTANT_REAL} {
    if(DEBUG_LEX == 1) print_token("Constant real");
    num_col += yyleng;
    yylval.astnode = create_astnode_context(AST_CONSTANT_REAL, yytext, yylloc);
    return CONSTANT_REAL_TOKEN;
}

{STRING} {
    if(DEBUG_LEX == 1) print_token("String");
    num_col += yyleng;
    yylval.astnode = create_astnode_context(AST_CONSTANT_STRING, yytext, yylloc);
    yylval.astnode->context->dtype = DTYPE_STRING;
    return STRING_TOKEN;
}

{OP_BINARY_ARITHMETIC} {
    if(DEBUG_LEX == 1) print_token("Arithmetic operation");
    num_col += yyleng;
    switch(yytext[0]){
        case '+':
            return yytext[0];
        case '-':
            return yytext[0];
        case '*':
            return yytext[0];
        case '/':
            return yytext[0];
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
            if(yytext[1] == '=')
                return LE_EQ_TOKEN;
            else
                return LESS_TOKEN;
        case '>':
            if(yytext[1] == '=')
                return GR_EQ_TOKEN;
            else
                return GREAT_TOKEN;
        case '=':
            return EQUAL_TOKEN;
        case '!':
            return DIFF_EQ_TOKEN;
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
            return yytext[0];
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
            yylval.astnode = create_astnode_context(AST_CONSTANT_NIL, yytext, yylloc);
            return NIL_TOKEN;
    }
}

{COMMAND_INPUT_OUTPUT} {
    if(DEBUG_LEX == 1) print_token("IN/OUT operation");
    num_col += yyleng;
    switch(yytext[0]){
        case 'r':
            yylval.astnode = create_astnode_context(AST_FUNC_CALL, yytext, yylloc);
            return READ_TOKEN;
        case 'w':
            yylval.astnode = create_astnode_context(AST_FUNC_CALL, yytext, yylloc);
            return WRITE_TOKEN;
    }
}

{ID} {
    if(DEBUG_LEX == 1) print_token("ID");
    num_col += yyleng;
    yylval.astnode = create_astnode_context(AST_ID, yytext, yylloc);
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
    printf(RED"Lexic error: " RESET "unexpected character: %s || line: %d, column: %d\n", yytext, num_line, num_col);
    num_col += yyleng;
}
%%

void print_token(char *type){
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("%s: %s\n", type, yytext);
}