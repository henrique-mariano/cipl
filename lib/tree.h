#ifndef ___TREE___H___
#define ___TREE___H___

#include <stdio.h>
#include <stdlib.h>

typedef struct Element{
    // definir tipo
    void *value;
    struct Element *next;
} Element;

typedef struct List{
    Element *first;
    unsigned int size;
} List;

typedef struct AstNode{
    struct AstContext *context;
    struct AstNode *father;
    List *kids;
} AstNode;

Element* create_element(void *value);

void free_element(Element *elemento, void (*callback)(Element *));

void* pop_element_list(List *lista);

void print_element(AstNode *elemento);

List* create_list();

void insert_list_element(List *lista, void *value);

void print_list(List *lista);

/* Função de deletar um astnode da lista */

void delete_list_astnode(Element *elemento);

void delete_list(List *lista, void (*callback)(Element *));

AstNode* create_astnode(struct AstContext *context);

void print_tree(AstNode *root, int tab);

void insert_kid(AstNode *kid, AstNode *no);

void delete_astnode(AstNode *no);

#endif