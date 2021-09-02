#include "../lib/tree.h"
#include "../lib/astcontext.h"

Element* create_element(void *value){
    Element *elemento = (Element *) malloc(sizeof(Element));
    elemento->next = NULL;
    elemento->value = value;

    return elemento;
}

void free_element(Element *elemento, void (*callback)(Element *)){
    if(callback){
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

void print_element(AstNode *elemento){
    printf("%s ->", elemento->context->name);
}

void delete_list_astnode(Element *elemento){
    delete_astnode(elemento->value);
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

void print_list(List *lista){
    Element *aux = lista->first;

    if(lista->size == 0){
        printf("Empty list\n");
    }

    while(aux != NULL){
        print_element((AstNode *) aux->value);
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

AstNode* create_astnode(AstContext *context){
    AstNode *no = (AstNode *) malloc(sizeof(AstNode));

    no->context = context;
    no->father = NULL;
    no->kids = create_list();

    return no;
}

void insert_kid(AstNode *kid, AstNode *no){
    kid->father = no;
    insert_list_element(no->kids, kid);
}

void delete_astnode(AstNode *no){
    if(!no)
        return;
    free_astcontext(no->context);
    delete_list(no->kids, delete_list_astnode);
    free(no);
}

void print_tree(AstNode *root, int tab){
    Element *first_son = root->kids->first;
    printf("%s\n", root->context->name);
    while (first_son != NULL){
        for(int i = 0; i < tab+1; i++)
            printf("\t");
        print_tree(first_son->value, tab+1);
        first_son = first_son->next;
    }
}
