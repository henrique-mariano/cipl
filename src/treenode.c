#include "../lib/treenode.h"

TreeNode *create_node(void *value)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));

    node->value = value;
    node->father = NULL;
    node->children = create_list();

    return node;
}

void insert_children(TreeNode *child, TreeNode *node)
{
    if (!child)
        return;
    child->father = node;
    insert_list_element(node->children, child);
}

void delete_node(TreeNode *node, void (*callback_list)(Element *), void (*callback_value)(void *))
{
    if (!node)
        return;
    if (callback_value)
        callback_value(node->value);
    else
        free(node->value);

    delete_list(node->children, callback_list);

    free(node);
    node = NULL;
}

void tree_iterate_pos(TreeNode *root, void (*callback)(void *))
{
    Element *iterator = root->children->first;

    while (iterator)
    {
        tree_iterate_pos(iterator->value, callback);
        iterator = iterator->next;
    }

    callback(iterator->value);
}
