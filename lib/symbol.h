#ifndef ___SYMBOL_H___
#define ___SYMBOL_H___

#include "list.h"
#include "astcontext.h"

typedef enum TypeSimbol{
    INT_SYMBOL_CONST = 1,
    FLOAT_SYMBOL_CONST,
    INT_LIST_SYMBOL_CONST,
    FLOAT_LIST_SYMBOL_CONST
} TypeSimbol;

extern char* nome_tipos[FLOAT_LIST_SYMBOL_CONST+1];

typedef struct Symbol{
    char *name;
    double value;
    int line;
    int column;
    unsigned int isfunction;
    TypeSimbol type_simbol;
} Symbol;

typedef struct SymbolTable{
    List *symbols;
} SymbolTable;

Symbol* create_symbol(char *name, double value, int line, int column, unsigned int type_symbol, unsigned int function);

SymbolTable* create_symbol_table();

void insert_symbol(SymbolTable* symbol_table, Symbol *symbol);

void list_symbol_insert(unsigned int type, List *symbol_list, char *name, double value, int line, int column, unsigned int isfunction);

void delete_symbol(Symbol *symbol);

void delete_symbol_table(SymbolTable *symbol_table, void (*callback)(Element *));

void delete_list_symbol_table(Element *elemento);

void print_symbol_list(Element *elemento);

void print_symbol(Symbol *symbol);

void lookup_symbol_table(SymbolTable *table, char *symbol);

// Lista -> tabela -> lista


#endif