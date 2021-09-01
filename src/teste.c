#include "../lib/tree.h"

int main(){
    // List *lista = create_list();
    // int i;
    // for (i = 0; i < 5; i++){
    //     int *j = calloc(1, sizeof(int));
    //     *j = i;
    //     insert_list_element(lista, j);
    // }

    // print_list(lista);
    // delete_list(lista);

    AstContext *contexto = (AstContext *) malloc(sizeof(AstContext));

    contexto->name = "KKKKKKKK";
    contexto->type = AST_FLAG;

    Node *root = create_node(contexto);

    int i;
    for(i = 0; i < 4; i++){
        AstContext *contexto = (AstContext *) malloc(sizeof(AstContext));
        contexto->name = "EEEEE";
        Node *no_fih = create_node(contexto);
        insert_kid(no_fih, root);
    }

    contexto = (AstContext *) malloc(sizeof(AstContext));
    contexto->name = "fih3";
    Node *kid = create_node(contexto);

    insert_kid(kid, root->kids->first->value);

    print_tree(root, 0);

    delete_node(root);
    
    return 0;
}
