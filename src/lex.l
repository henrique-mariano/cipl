%option nounput noinput noyywrap

%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include <stdlib.h>

    int num_line = 1, num_col = 1, error = 0;
%}

TYPES                   "int"|"float"|"int list"|"float list"

DIGIT                   [0-9]
CONSTANT_INTEGER        -?([1-9]{DIGIT}*|0)
CONSTANT_REAL           {CONSTANT_INTEGER}+(\.{DIGIT}+)?([Ee][+-]?{DIGIT}+)?
STRING                  \"([^\n"\\]|(\\.))*\"

OP_BINARY_ARITHMETIC    "+"|"-"|"*"|"/"
OP_LOGIC                "!"|"||"|"&&"
OP_BINARY_RELATIONAL    "<"|"<="|">"|">="|"=="|"!="
COMMAND_FLOW_CONTROL    if|else|for|return
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

{TYPES} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Type: %s\n", yytext);
    num_col += yyleng;
}

{CONSTANT_INTEGER} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Constant integer: %s\n", yytext);
    num_col += yyleng;
}

{CONSTANT_REAL} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Constant real: %s\n", yytext);
    num_col += yyleng;
}

{STRING} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("String: %s\n", yytext);
    num_col += yyleng;
}

{OP_BINARY_ARITHMETIC} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Arithmetic operation: %s\n", yytext);
    num_col += yyleng;
}

{OP_LOGIC} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Logic operation: %s\n", yytext);
    num_col += yyleng;
}

{OP_BINARY_RELATIONAL} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Relational operation: %s\n", yytext);
    num_col += yyleng;
}

{COMMAND_FLOW_CONTROL} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Flow control command: %s\n", yytext);
    num_col += yyleng;
}

{COMMAND_INPUT_OUTPUT} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("IN/OUT operation: %s\n", yytext);
    num_col += yyleng;
}

{ID} {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("ID: %s\n", yytext);
    num_col += yyleng;
}

{BRACKET} {
    switch(yytext[0]){
        case '[':
        case ']':
            printf("Line: %d || Column: %d || ", num_line, num_col);
            printf("Square bracket: %s\n", yytext);
            num_col += yyleng;
            break;
        case '{':
        case '}':
            printf("Line: %d || Column: %d || ", num_line, num_col);
            printf("Curly bracket: %s\n", yytext);
            num_col += yyleng;
            break;
        case '(':
        case ')':
            printf("Line: %d || Column: %d || ", num_line, num_col);
            printf("Parenthesis: %s\n", yytext);
            num_col += yyleng;
            break;
    }
}

{COMMA} {
    switch(yytext[0]){
        case ',':
            printf("Line: %d || Column: %d || ", num_line, num_col);
            printf("Comma: %s\n", yytext);
            num_col += yyleng;
            break;
        case ';':
            printf("Line: %d || Column: %d || ", num_line, num_col);
            printf("Semicolon: %s\n", yytext);
            num_col += yyleng;
            break;
    }
}

= {
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Equal: %s\n", yytext);
    num_col += yyleng;
}

. {
    error++;
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Unexpected token: %s || Error count: %d\n", yytext, error);
    num_col += yyleng;
}
%%

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
    yylex();
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
