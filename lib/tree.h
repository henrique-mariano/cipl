#ifndef ___TREE___H___
#define ___TREE___H___

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

typedef struct Node{
    int name;
    void *value;
    struct Node *parent;
    List *children;
} Node;

#endif