%define lr.type canonical-lr
%define parse.error verbose
%define api.header.include {"lib/bison.h"}
%{
    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    

    extern int error, num_line, num_col;
    
    extern int yyparse();
    extern int yylex();
    extern int yylex_destroy();
    extern void yyerror(const char *error_msg);

    extern FILE *yyin;

%}

%union{
    char *name;
}

%token<name> INT_TOKEN
%token<name> FLOAT_TOKEN
%token<name> INT_LIST_TOKEN
%token<name> FLOAT_LIST_TOKEN

%destructor{
    free($$);
}<name>

%%

program:
    type
    ;

type:
    INT_TOKEN {
        printf("aaaaaaa");
        printf("%s\n", $1);
    }
    | FLOAT_TOKEN {
        printf("%s\n", $1);
    }
    | INT_LIST_TOKEN {
        printf("%s\n", $1);
    }
    | FLOAT_LIST_TOKEN {
        printf("%s\n", $1);
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

    yyin = fp;
    yyparse();
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}