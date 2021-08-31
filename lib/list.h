#ifndef ___LIST___H___
#define ___LIST___H___

typedef struct Element{
    // definir tipo
    void *value;
    struct Element *next;
    struct Element *previous;
} Element;

typedef struct List{
    Element *first;
    Element *last;
    unsigned int size;
} List;

#endif