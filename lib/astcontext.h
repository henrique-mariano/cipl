#ifndef ___ASTCONTEXT___H___
#define ___ASTCONTEXT___H___

#include <stdlib.h>
#include <string.h>
#include "tree.h"

enum {
    AST_ROOT = 1,
    AST_TYPE,
    AST_VAR_DECLARE,
    AST_FUNC_DECLARE,
    AST_PARAM,
    AST_STATE_FLOW,
    AST_STATE_COMPOUND,
    AST_ID,
    AST_CONSTANT
};

typedef struct AstContext{
    int type;
    char *name;
} AstContext;

AstContext* create_astcontext(int type, char *name);
AstNode* create_astnode_context(int type, char *name);
void free_astcontext(AstContext *context);
void create_context_ast(List *lista_contexto);

// void delete_list_element_list(Element *lista);
// void delete_context_ast(List *lista_contexto);

#endif