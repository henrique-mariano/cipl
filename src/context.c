#include "../lib/context.h"

Context* create_context(struct Symbol *symbol, unsigned int scope){
    Context *context = (Context *) malloc(sizeof(Context));

    context->scope = scope;
    context->symbol_context = symbol;

    return context;
}

void delete_context(Context *context){
    delete_symbol(context->symbol_context);
    free(context);
    context = NULL;
}

Symbol* lookup_symbol(char *name, TreeNode *node){
    TreeNode *iterator;

    for(iterator = node; iterator != NULL; iterator = iterator->father){
        SymbolTable *sym_it;
        sym_it = iterator->value;
        for(Element *elm_it = sym_it->symbols->first; elm_it != NULL; elm_it = elm_it->next){
            if(!strcmp(name, ((Symbol *)elm_it->value)->name)){
                return elm_it->value;
            }
        }
    }
    return NULL;
}