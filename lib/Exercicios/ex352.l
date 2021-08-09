%option nounput noinput noyywrap
%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280    
%}

DELIM               [ \t\n]
WS                  {DELIM}+
LETTER              [A-Za-z_]
DIGIT               [0-9]
ID                  {LETTER}({LETTER}|{DIGIT})*
NUMBER              {DIGIT}+(\.{DIGIT}+)?(E[+-]?{DIGIT}+)?
KEYWORD_RESERVED    if|then|else|while
COMP_OP             "<"|"<="|"="|"!="|">"|">="
STRING              \"([^"\\]|(\\.))*\"


%%
{WS}{2,} {
    printf(" ", yytext);
}
%%

int main(){
    yylex();
}