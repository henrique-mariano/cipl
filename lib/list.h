#ifndef ___LIST___H___
#define ___LIST___H___

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    // definir tipo
    void *value;
    struct Element *next;
} Element;

typedef struct List
{
    Element *first;
    unsigned int size;
} List;

Element *create_element(void *value);

void free_element(Element *elemento, void (*callback)(Element *));

void *pop_element_list(List *lista);

void *remove_first_element_list(List *lista);

void print_element(void *elemento, void (*callback)(Element *));

List *create_list();

void insert_list_element(List *lista, void *value);

void print_list(List *lista, void (*callback)(Element *));

void delete_list(List *lista, void (*callback)(Element *));

#endif