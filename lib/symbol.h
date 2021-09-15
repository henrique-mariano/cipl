#ifndef ___SYMBOL_H___
#define ___SYMBOL_H___

#include "list.h"

typedef enum TypeSimbol{
    INT_SYMBOL_CONST = 1,
    FLOAT_SYMBOL_CONST,
    INT_LIST_SYMBOL_CONST,
    FLOAT_LIST_SYMBOL_CONST,
    FUNC_INT_LIST_SYMBOL_CONST,
    FUNC_FLOAT_LIST_SYMBOL_CONST,
    FUNC_INT_SYMBOL_CONST,
    FUNC_FLOAT_SYMBOL_CONST
} TypeSimbol;


typedef struct Symbol{
    int id;
    char *name;
    double value;
    int line;
    int column;
    int scope;
    TypeSimbol type_simbol;
} Symbol;

typedef struct SymbolTable{
    List *symbols;
} SymbolTable;

SymbolTable* create_symbol_table();

void lookup_symbol_table(SymbolTable *table, char *symbol);

// Lista -> tabela -> lista


#endif