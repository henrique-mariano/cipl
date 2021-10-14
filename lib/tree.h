#ifndef ___TREE___H___
#define ___TREE___H___

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct AstNode
{
    struct AstContext *context;
    struct AstNode *father;
    List *kids;
} AstNode;

AstNode *create_astnode(struct AstContext *context);

void print_tree(AstNode *root, int tab);

AstNode *lookup_node(AstNode *root, char *name);

void insert_kid(AstNode *kid, AstNode *no);

void delete_astnode(AstNode *no);

void delete_list_astnode(Element *elemento);

AstNode *lookup_global(AstNode *root, char *name);

int get_depth(AstNode *root);

#endif