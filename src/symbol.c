#include "../lib/symbol.h"

char *nome_tipos[FLOAT_LIST_SYMBOL_CONST + 1] = {[INT_SYMBOL_CONST] = "int",
                                                 [FLOAT_SYMBOL_CONST] = "float",
                                                 [INT_LIST_SYMBOL_CONST] = "int list",
                                                 [FLOAT_LIST_SYMBOL_CONST] = "float list"};

Symbol *create_symbol(char *name, double value, int line, int column, unsigned int type_symbol, unsigned int function)
{
    Symbol *symbol = (Symbol *)malloc(sizeof(Symbol));
    symbol->name = name;
    symbol->value = value;
    symbol->line = line;
    symbol->column = column;
    symbol->type_simbol = type_symbol;
    symbol->isfunction = function;
    symbol->variable_tac = -1;

    return symbol;
}

SymbolTable *create_symbol_table()
{
    SymbolTable *symbol_table = (SymbolTable *)malloc(sizeof(SymbolTable));
    symbol_table->symbols = create_list();

    return symbol_table;
}

void insert_symbol(SymbolTable *symbol_table, Symbol *symbol)
{
    insert_list_element(symbol_table->symbols, symbol);
}

Symbol *list_symbol_insert(unsigned int type, List *symbol_list, char *name, double value, int line, int column, unsigned int isfunction)
{
    Symbol *sym;
    switch (type)
    {
    case AST_TYPE_INT:
        sym = create_symbol(strdup(name), value, line, column, INT_SYMBOL_CONST, isfunction);
        insert_list_element(symbol_list, sym);
        break;

    case AST_TYPE_FLOAT:
        sym = create_symbol(strdup(name), value, line, column, FLOAT_SYMBOL_CONST, isfunction);
        insert_list_element(symbol_list, sym);
        break;

    case AST_TYPE_INT_LIST:
        sym = create_symbol(strdup(name), value, line, column, INT_LIST_SYMBOL_CONST, isfunction);
        insert_list_element(symbol_list, sym);
        break;

    case AST_TYPE_FLOAT_LIST:
        sym = create_symbol(strdup(name), value, line, column, FLOAT_LIST_SYMBOL_CONST, isfunction);
        insert_list_element(symbol_list, sym);
        break;
    }
    return sym;
}

void delete_symbol(Symbol *symbol)
{
    free(symbol->name);
    free(symbol);
    symbol = NULL;
}

void delete_symbol_table(SymbolTable *symbol_table, void (*callback)(Element *))
{
    delete_list(symbol_table->symbols, callback);
    free(symbol_table);
    symbol_table = NULL;
}

void delete_list_symbol_table(Element *elemento)
{
    delete_symbol(elemento->value);
}

void print_symbol_list(Element *elemento)
{
    print_symbol(elemento->value);
}

void print_symbol(Symbol *symbol)
{
    printf("# %-14s || %-11s || %-10s || %-4d || %-6d #\n", nome_tipos[symbol->type_simbol], symbol->isfunction ? "function" : "variable", symbol->name, symbol->line, symbol->column);
}