#include "../lib/list.h"

// struct AstNode;

Element* create_element(void *value){
    Element *elemento = (Element *) malloc(sizeof(Element));
    elemento->next = NULL;
    elemento->value = value;

    return elemento;
}

void free_element(Element *elemento, void (*callback)(Element *)){
    if(callback){
        if(elemento->value)
            callback(elemento);
    } else {
        free(elemento->value);
        elemento = NULL;
    }
    free(elemento);
}

void* pop_element_list(List *lista){
    Element *first = lista->first;
    Element *past = first;

    void *value;

    if(lista->size == 1){
        lista->first = NULL;
    } else {

        while(first->next){
            past = first;
            first = first->next;
        }

        past->next = NULL;
    }
    
    lista->size--;
    value = first->value;
    free(first);
    
    return value;
}

void* remove_first_element_list(List *lista){
    Element *first = lista->first;
    // Element *past = first;

    void *value;

    if(lista->size == 1){
        lista->first = NULL;
    } else {
        lista->first = first->next;
    }
    
    lista->size--;
    value = first->value;
    free(first);

    return value;
}

void print_element(void *elemento, void (*callback)(Element *)){
    if(callback)
        callback(elemento);
    else
        printf("Callback vazio\n");
    // printf("%s ->", ((struct AstNode *) elemento)->context->name);
}

List* create_list(){
    List *lista = (List *) malloc(sizeof(List));
    lista->first = NULL;
    lista->size = 0;

    return lista;
}

void insert_list_element(List *lista, void *value){
    Element *current;
    Element *elemento = create_element(value);
    
    if (lista->size == 0){
        lista->first = elemento;
    } else {
        current = lista->first;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = elemento;
    }
    lista->size++;
}

void print_list(List *lista, void (*callback)(Element *)){
    Element *aux = lista->first;

    if(lista->size == 0){
        printf("Empty list\n");
    }

    while(aux != NULL){
        print_element(aux->value, callback);
        aux = aux->next;
    }
    printf("\n");
}

void delete_list(List *lista, void (*callback)(Element *)){
    Element *current = lista->first;
    Element *next;
    while(current != NULL){
        next = current->next;
        free_element(current, callback);
        current = next;
    }
    free(lista);
}