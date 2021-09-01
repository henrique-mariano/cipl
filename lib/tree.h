#ifndef ___TREE___H___
#define ___TREE___H___

#include <stdio.h>
#include <stdlib.h>
#include "astcontext.h"

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

void free_element(Element *elemento);

void print_element(Element *elemento);

List* create_list();

void insert_list_element(List *lista, void *value);

void print_list(List *lista);

void delete_list(List *lista);

AstNode* create_AstNode(AstContext *context);

void print_tree(AstNode *root, int tab);

void insert_kid(AstNode *kid, AstNode *no);

void delete_AstNode(AstNode *no);

#endif