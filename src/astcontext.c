#include "../lib/astcontext.h"

AstContext *create_astcontext(int type, char *name, YYLTYPE node_pos)
{
    AstContext *context = (AstContext *)malloc(sizeof(AstContext));
    context->type = type;
    context->name = strdup(name);
    context->dtype = -1;
    context->operation = NULL;
    context->node_pos = node_pos;
    return context;
}

AstNode *create_astnode_context(int type, char *name, YYLTYPE node_pos)
{
    AstNode *no = create_astnode(create_astcontext(type, name, node_pos));
    return no;
}

void free_astcontext(AstContext *context)
{
    free(context->name);
    free(context);
    context = NULL;
}