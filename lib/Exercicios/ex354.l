%option nounput noinput noyywrap
%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include <stdlib.h>
%}

DELIM               [ \t\n]
WS                  {DELIM}+
LETTER              [A-Za-z_]
WORD                [A-Za-z0-9_]+
DIGIT               [0-9]
ID                  {LETTER}({LETTER}|{DIGIT})*
NUMBER              {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?
KEYWORD_RESERVED    if|then|else|while
COMP_OP             "<"|"<="|"="|"!="|">"|">="
STRING              \"([^"\\]|(\\.))*\"


%%
{WORD} {
    char *str = yytext;
    char *str_aux = calloc(yyleng + 50, sizeof(char));
    char c;

    switch(str[0]){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%say", yytext);
            break;
        default:
            c = str[0];
            *str++;
            sprintf(str_aux, "%s%cay", str, c);
            printf("%s",str_aux);
            break;
    }
    free(str_aux);
}
%%