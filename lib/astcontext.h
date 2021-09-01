#ifndef ___ASTCONTEXT___H___
#define ___ASTCONTEXT___H___

enum {
    AST_FLAG = 1,
    AST_DECLARE
};

typedef struct AstContext{
    int type;
    char *name;
} AstContext;

#endif