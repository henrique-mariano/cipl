#ifndef ___MACROS___H___
#define ___MACROS___H___

#define FUNCTION 1
#define VARIABLE 0

#define RED "\033[1;31m"
#define RESET "\033[0m"

#define SEMANTIC_ERROR(__STR_ERR_SEM__, ...) { \
    yyerror(NULL); \
    printf(RED"Semantic error: "RESET __STR_ERR_SEM__, ##__VA_ARGS__); \
}

#define SYNTAX_ERROR(__STR_ERR_SYN__, ...) { \
    printf(RED"Syntax error: "RESET __STR_ERR_SYN__, ##__VA_ARGS__); \
}

#define SHOW_SYNTAX_ERROR(__STR_ERR__, ...) { \
    yyerror(NULL); \
    SYNTAX_ERROR(__STR_ERR__, ##__VA_ARGS__); \
}

extern void yyerror(const char *error_msg);

#endif