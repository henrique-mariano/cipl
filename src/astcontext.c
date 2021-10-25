#include "../lib/astcontext.h"

char *nome_tipos_ast[AST_BUILT_IN + 1] = {
    [AST_ROOT] = "ROOT",
    [AST_TYPE] = "TYPE",
    [AST_TYPE_INT] = "TYPE_INT",
    [AST_TYPE_FLOAT] = "TYPE_FLOAT",
    [AST_TYPE_LIST] = "TYPE_LIST",
    [AST_TYPE_INT_LIST] = "TYPE_INT_LIST",
    [AST_TYPE_FLOAT_LIST] = "TYPE_FLOAT_LIST",
    [AST_VAR_DECLARE] = "VAR_DECLARE",
    [AST_FUNC_DECLARE] = "FUNC_DECLARE",
    [AST_PARAM] = "PARAM",
    [AST_LIST_PARAM] = "LIST_PARAM",
    [AST_STATEMENT] = "STATEMENT",
    [AST_STATE_FLOW] = "STATE_FLOW",
    [AST_STATE_COMPOUND] = "STATE_COMPOUND",
    [AST_CODE_BLOCK] = "CODE_BLOCK",
    [AST_LIST_CODEBLOCK] = "LIST_CODEBLOCK",
    [AST_STATE_EXPRESSION] = "STATE_EXPRESSION",
    [AST_EXPR_FLOW] = "EXPR_FLOW",
    [AST_EXPR_COND] = "EXPR_COND",
    [AST_EXPR_ITERATION] = "EXPR_ITERATION",
    [AST_EXPR_RETURN] = "EXPR_RETURN",
    [AST_EXPRESSION] = "EXPRESSION",
    [AST_EXPR_ASSIGN] = "EXPR_ASSIGN",
    [AST_EXPR_BIN_ARITH] = "EXPR_BIN_ARITH",
    [AST_EXPR_LIST_ARITH] = "EXPR_LIST_ARITH",
    [AST_EXPR_UNA_ARITH] = "EXPR_UNA_ARITH",
    [AST_ID] = "ID",
    [AST_CONSTANT] = "CONSTANT",
    [AST_CONSTANT_INT] = "CONSTANT_INT",
    [AST_CONSTANT_REAL] = "CONSTANT_REAL",
    [AST_CONSTANT_NIL] = "CONSTANT_NIL",
    [AST_CONSTANT_STRING] = "CONSTANT_STRING",
    [AST_FUNC_CALL] = "FUNC_CALL",
    [AST_BUILT_IN] = "BUILT_IN"};

AstContext *create_astcontext(int type, char *name, YYLTYPE node_pos)
{
    AstContext *context = (AstContext *)malloc(sizeof(AstContext));
    context->type = type;
    context->name = strdup(name);
    context->dtype = -1;
    context->operation = NULL;
    context->node_pos = node_pos;
    context->sym_ref = NULL;

    return context;
}

AstNode *create_astnode_context(int type, char *name, YYLTYPE node_pos)
{
    AstNode *no = create_astnode(create_astcontext(type, name, node_pos));
    return no;
}

void free_astcontext(AstContext *context)
{
    if(context){
        if(context->name)
            free(context->name);
        if (context->operation)
            free(context->operation);
        free(context);
    }
    context = NULL;
}