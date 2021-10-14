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
    yyerrok; \
    SYNTAX_ERROR(__STR_ERR__, ##__VA_ARGS__); \
}

#define FIRST_SON(__NODE_FIR__)  \
    (__NODE_FIR__->kids->size > 0 ? ((AstNode *) __NODE_FIR__->kids->first->value) : NULL)

#define SECOND_SON(__NODE_SEC__) \
    (__NODE_SEC__->kids->size > 1 ? ((AstNode *) __NODE_SEC__->kids->first->next->value) : NULL)

#define THIRD_SON(__NODE_THI__) \
    (__NODE_THI__->kids->size > 2 ? ((AstNode *) __NODE_THI__->kids->first->next->next->value) : NULL)

#define MAX(__VALUE1__, __VALUE2__) \
    (((__VALUE1__) > (__VALUE2__)) ? (__VALUE1__) : (__VALUE2__));

extern void yyerror(const char *error_msg);

#endif