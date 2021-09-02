#ifndef __SYMBOL_H__
#define __SYMBOL_H__

typedef enum TypeSimbol{
    INT_SYMBOL_CONST = 1,
    FLOAT_SYMBOL_CONST,
    INT_LIST_SYMBOL_CONST,
    FLOAT_LIST_SYMBOL_CONST,
    FUNC_LIST_SYMBOL_CONST
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

#endif