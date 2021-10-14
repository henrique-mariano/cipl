#ifndef ___SEM_EVAL___H___
#define ___SEM_EVAL___H___

#include "tree.h"
#include "astcontext.h"
#include "bison.h"
#include "macros.h"
#include "symbol.h"

int sem_check(AstNode *node);
int sem_eval(AstNode *root);
char *error_string_type(int type);
int sym2dtype(int type);
int list2num(int type);
int num2list(int type);
int dtcheck(int t1, int t2);

#endif