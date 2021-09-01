#include "../lib/tree.h"

Element* create_element(void *value){
    Element *elemento = (Element *) malloc(sizeof(Element));
    elemento->next = NULL;
    elemento->value = value;

    return elemento;
}

void free_element(Element *elemento){
    free(elemento->value);
    free(elemento);
    elemento = NULL;
}

void print_element(Element *elemento){
    printf("%d ->", *((int *) elemento->value) );
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
        print_element(aux);
        aux = aux->next;
    }
    printf("\n");
}

void delete_list(List *lista){
    Element *current = lista->first;
    Element *next;
    while(current != NULL){
        next = current->next;
        free_element(current);
        current = next;
    }
    free(lista);
}

AstNode* create_AstNode(AstContext *context){
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

void delete_AstNode(AstNode *no){
    Element *first_son = no->kids->first;
    Element *post;
    while(first_son != NULL){
        delete_AstNode(first_son->value);
        post = first_son;
        first_son = first_son->next;
        free(post);
    }
    free(no->kids);
    free(no->context); // Adaptar funcao para liberar o contexto
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
