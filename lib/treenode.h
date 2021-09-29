#ifndef ___TREE_NODE_H___
#define ___TREE_NODE_H___

#include <stdlib.h>
#include "list.h"

typedef struct TreeNode{
    void *value;
    void *father;
    struct List *children;
} TreeNode;

TreeNode* create_node(void *value);

void insert_children(TreeNode *child, TreeNode *node);

void delete_node(TreeNode *node, void (*callback_list)(Element *), void (*callback_value)(void *));

void delete_list_node(Element *);

void tree_iterate_pre(TreeNode *root, void (*callback)(void *));

void tree_iterate_pos(TreeNode *root, void (*callback)(void *));

#endif