#ifndef ___CONTEXT___H___
#define ___CONTEXT___H___

#include <stdlib.h>

#include "symbol.h"
#include "treenode.h"

typedef struct Context
{
    unsigned int scope;
    struct Symbol *symbol_context;
} Context;

Context *create_context(struct Symbol *symbol, unsigned int scope);

void delete_context(Context *context);

Symbol *lookup_symbol(char *name, TreeNode *node);

Symbol *lookup_symbol_context(char *name, TreeNode *node);

#endif