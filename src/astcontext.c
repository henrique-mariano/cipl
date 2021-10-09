#include "../lib/astcontext.h"

AstContext *create_astcontext(int type, char *name)
{
    AstContext *context = (AstContext *)malloc(sizeof(AstContext));
    context->type = type;
    context->name = strdup(name);
    return context;
}

AstNode *create_astnode_context(int type, char *name)
{
    AstNode *no = create_astnode(create_astcontext(type, name));
    return no;
}

void free_astcontext(AstContext *context)
{
    free(context->name);
    free(context);
    context = NULL;
}

// void create_context_codeblock(List *lista)