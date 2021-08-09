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
SQL_KEYWORDS        (?i:"SELECT"|"FROM"|"WHERE")

%%
{SQL_KEYWORDS} {
    printf("Token: %s\n", yytext);
}
%%

int installID(){ /* A função install teria que tratar os casos insensitivos 
                para que não crie vários tipos de entrada diferentes na tabela de símbolos, 
                ajustando o valor para maiúsculo ou minúsculo e assim evitando 
                essa grande quantidade de entradas na tabela de símbolos */
}