%option nounput noinput noyywrap

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
"float" printf("double");
%%

int main(){
    yylex();
}