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
{WS} {/* Nenhuma ação de retorno */}
{KEYWORD_RESERVED} {
    printf("Palavra-chave: <%s>\n", yytext);
}
{COMP_OP} {
    printf("Operador de comparação: <%s>\n", yytext);
}
%%

int main(){
    yylex();
}