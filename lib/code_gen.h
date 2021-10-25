#ifndef ___CODE_GEN___H___
#define ___CODE_GEN___H___

#include "tree.h"
#include "astcontext.h"
#include "bison.h"
#include "macros.h"
#include "symbol.h"
#include "sem_eval.h"

#include <stdio.h>

void code_gen(AstNode *root, FILE *fp);

#endif