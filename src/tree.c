#include "../lib/tree.h"
#include "../lib/astcontext.h"
#include "../lib/sem_eval.h"

AstNode *create_astnode(AstContext *context)
{
    AstNode *no = (AstNode *)malloc(sizeof(AstNode));

    no->context = context;
    no->father = NULL;
    no->kids = create_list();

    return no;
}

void insert_kid(AstNode *kid, AstNode *no)
{
    if (!kid)
        return;
    kid->father = no;
    insert_list_element(no->kids, kid);
}

void delete_list_astnode(Element *elemento)
{
    delete_astnode(elemento->value);
}

void delete_astnode(AstNode *no)
{
    if (!no)
        return;
    free_astcontext(no->context);
    delete_list(no->kids, delete_list_astnode);
    free(no);
    no = NULL;
}

void print_tree(AstNode *root, int tab)
{
    if (!root)
        return;
    Element *first_son = root->kids->first;
    if(root->context->dtype != DTYPE_ERROR)
        printf("<%s> %s%s", error_string_type(root->context->dtype), root->context->name, *root->context->name ? "\n" : "");
    else
        printf("%s%s", root->context->name, *root->context->name ? "\n" : "");
    while (first_son != NULL)
    {
        for (int i = 0; *root->context->name && (i < tab + 1); i++)
        {
            printf("    ");
        }
        print_tree(first_son->value, tab + (*root->context->name ? 1 : 0));
        first_son = first_son->next;
    }
}

AstNode *lookup_node(AstNode *root, char *name)
{
    if (!root)
        return NULL;
    Element *first_son = root->kids->first;
    if (!strcmp(root->context->name, name))
        return root;
    while (first_son != NULL)
    {
        root = lookup_node(first_son->value, name);
        if (root)
            return root;
        first_son = first_son->next;
    }
    return NULL;
}

AstNode *lookup_global(AstNode *root, char *name)
{
    if (!root)
        return NULL;

    if (get_depth(root) > 3)
        return NULL;

    Element *first_son = root->kids->first;
    if (!strcmp(root->context->name, name))
        return root;
    while (first_son != NULL)
    {
        root = lookup_global(first_son->value, name);
        if (root)
            return root;
        first_son = first_son->next;
    }
    return NULL;
}

int get_depth(AstNode *root)
{
    int depth = 0;
    for (; root; root = root->father, depth++)
        ;
    return depth;
}