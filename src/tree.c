#include "../lib/tree.h"
#include "../lib/astcontext.h"

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

void delete_list_astnode(Element *elemento){
    delete_astnode(elemento->value);
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
    printf("%s%s", root->context->name, *root->context->name ? "\n" : "");
    while (first_son != NULL){
        for(int i = 0; *root->context->name && (i < tab+1); i++){
            printf("\t");
        }
        print_tree(first_son->value, tab+(*root->context->name ? 1 : 0));
        first_son = first_son->next;
    }
}
