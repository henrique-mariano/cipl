#ifndef ___ASTCONTEXT___H___
#define ___ASTCONTEXT___H___

#include <stdlib.h>
#include <string.h>
#include "tree.h"

enum {
    AST_ROOT = 1,
    AST_TYPE,
    AST_TYPE_INT,
    AST_TYPE_FLOAT,
    AST_TYPE_INT_LIST,
    AST_TYPE_FLOAT_LIST,
    AST_VAR_DECLARE,
    AST_FUNC_DECLARE,
    AST_PARAM,
    AST_LIST_PARAM,
    AST_STATEMENT,
    AST_STATE_FLOW,
    AST_STATE_COMPOUND,
    AST_CODE_BLOCK,
    AST_LIST_CODEBLOCK,
    AST_STATE_EXPRESSION,
    AST_EXPR_FLOW,
    AST_EXPR_COND,
    AST_EXPR_ITERATION,
    AST_EXPR_RETURN,
    AST_EXPRESSION,
    AST_EXPR_ASSIGN,
    AST_EXPR_BIN_ARITH,
    AST_EXPR_LIST_ARITH,
    AST_EXPR_UNA_ARITH,
    AST_ID,
    AST_CONSTANT,
    AST_CONSTANT_INT,
    AST_CONSTANT_REAL,
    AST_CONSTANT_NIL,
    AST_CONSTANT_STRING,
    AST_FUNC_CALL
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