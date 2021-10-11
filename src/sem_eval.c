#include "../lib/sem_eval.h"

int sem_check(AstNode *node){
    if(!node)
        return DTYPE_ERROR;
    
    switch(node->context->type){
        case AST_EXPRESSION:
        case AST_CONSTANT:
            return sem_check(node->kids->first->value);
        case AST_CONSTANT_INT:
        case AST_CONSTANT_REAL:
        case AST_CONSTANT_STRING:
        case AST_CONSTANT_NIL:
            printf("Node constantnil: %s || dtype: %d\n", node->context->name, node->context->dtype);
            return node->context->dtype;
        // case AST_EXPR_UNA_ARITH:
        //     AstNode *rop = ((AstNode *)node->kids->first->value);

        //     DataTypes ropval = sem_eval(rop);
        //     switch(node->context->operation[0]){
        //         case '!':
        //             if(ropval == DTYPE_LIST){
        //                 SEMANTIC_ERROR("invalid unary operand")
        //             }
        //     }
        case AST_BUILT_IN:;
            // AstNode *func = ((AstNode *) node->kids->first->value);
            printf("Node built: %s || dtype: %d\n", node->context->name, node->context->dtype);

            AstNode *arg = ((AstNode *) node->kids->first->next->value);

            DataTypes arg_value = sem_check(arg);

            if(arg_value >= DTYPE_LIST){
                SEMANTIC_ERROR("type of argument invalid || line: %d, column: %d\n", arg->context->node_pos.first_line, arg->context->node_pos.first_column);
                return DTYPE_ERROR;
            }

            return DTYPE_INT;
        
        default:
            return DTYPE_ERROR;
    }
    return DTYPE_ERROR;
}

int sem_eval(AstNode *root){
    if (!root)
        return DTYPE_ERROR;
    Element *first_son = root->kids->first;
    int ret;
    int val = sem_check(root);
    root->context->dtype = val;

    while (first_son != NULL)
    {
        ret = sem_eval(first_son->value);
        ((AstNode *) first_son->value)->context->dtype = ret;
        first_son = first_son->next;
    }

    return val;
}