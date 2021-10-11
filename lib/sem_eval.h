#ifndef ___SEM_EVAL___H___
#define ___SEM_EVAL___H___

#include "tree.h"
#include "astcontext.h"
#include "bison.h"
#include "macros.h"

int sem_check(AstNode *node);

int sem_eval(AstNode *root);

#endif