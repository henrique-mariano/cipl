%define lr.type canonical-lr
%{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex();
    int yyerror(char *error_msg);
}
