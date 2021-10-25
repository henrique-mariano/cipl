#include "../lib/sem_eval.h"

extern AstNode *root;

int sem_check(AstNode *node)
{
    if (!node)
        return DTYPE_ERROR;

    switch (node->context->type)
    {
    case AST_PARAM:
    case AST_CONSTANT_INT:
    case AST_CONSTANT_REAL:
    case AST_CONSTANT_STRING:
    case AST_CONSTANT_NIL:
    case AST_TYPE_INT:
    case AST_TYPE_FLOAT:
    case AST_TYPE_INT_LIST:
    case AST_TYPE_FLOAT_LIST:
        return node->context->dtype;
    case AST_ID:
        if (node->context->sym_ref)
            return sym2dtype(node->context->sym_ref->type_simbol);
        return DTYPE_ERROR;
    case AST_BUILT_IN:
    {
        DataTypes arg_dtype = SECOND_SON(node) ? SECOND_SON(node)->context->dtype : 0;

        if (arg_dtype >= DTYPE_LIST)
        {
            SEMANTIC_ERROR("type of argument invalid || line: %d, column: %d\n", node->context->node_pos.first_line, node->context->node_pos.first_column);
            return DTYPE_ERROR;
        }

        return DTYPE_INT;
    }
    case AST_EXPR_BIN_ARITH:
    {
        DataTypes fdtype = FIRST_SON(node) ? FIRST_SON(node)->context->dtype : 0;
        DataTypes sdtype = SECOND_SON(node) ? SECOND_SON(node)->context->dtype : 0;
        switch (node->context->operation[0])
        {
        case '+':
        case '-':
        case '/':
        case '*':
        {
            if (fdtype >= DTYPE_LIST || sdtype >= DTYPE_LIST)
            {
                SEMANTIC_ERROR("list type used in binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            if (fdtype == DTYPE_ERROR || sdtype == DTYPE_ERROR)
            {
                SEMANTIC_ERROR("error in binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            return MAX(fdtype, sdtype);
        }
        case '=':
        case '!':
        {
            if ((fdtype >= DTYPE_LIST || sdtype >= DTYPE_LIST) && (fdtype < DTYPE_LIST || sdtype < DTYPE_LIST))
            {
                SEMANTIC_ERROR("list type used in binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            return DTYPE_INT;
        }
        default:
        {
            if (fdtype >= DTYPE_LIST || sdtype >= DTYPE_LIST)
            {
                SEMANTIC_ERROR("list type used in binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            return DTYPE_INT;
        }
        }
    }
    case AST_EXPR_ASSIGN:
    {
        DataTypes fdtype = FIRST_SON(node) ? FIRST_SON(node)->context->dtype : 0;
        DataTypes sdtype = SECOND_SON(node) ? SECOND_SON(node)->context->dtype : 0;

        Symbol *sym_id = FIRST_SON(node) ? FIRST_SON(node)->context->sym_ref : NULL;

        Symbol *sym_sec = SECOND_SON(node) ? SECOND_SON(node)->context->sym_ref : NULL;

        if (sym_id->isfunction)
        {
            SEMANTIC_ERROR("left operand can't be a function || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
            return DTYPE_ERROR;
        }

        if(sym_sec && sym_sec->isfunction){
            SEMANTIC_ERROR("right operand can't be a function || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
            return DTYPE_ERROR;
        }

        if (!dtcheck(sdtype, fdtype))
        {
            SEMANTIC_ERROR("invalid list type assign with int or float || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
            return DTYPE_ERROR;
        }

        return MAX(fdtype, sdtype);
    }
    case AST_EXPR_UNA_ARITH:
    {
        DataTypes fdtype = FIRST_SON(node) ? FIRST_SON(node)->context->dtype : 0;
        switch (node->context->operation[0])
        {
        case '+':
        case '-':
            if (fdtype >= DTYPE_LIST)
            {
                SEMANTIC_ERROR("list type used in unary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            return fdtype;
        case '?':
        case '%':
            if (fdtype < DTYPE_INT_LIST)
            {
                SEMANTIC_ERROR("NIL or number type used in unary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            return list2num(fdtype);

        case '!':
            if (fdtype == DTYPE_LIST)
            {
                SEMANTIC_ERROR("NIL or number type used in unary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            if (fdtype < DTYPE_LIST)
                return DTYPE_INT;
            else
                return fdtype;
        }
    }
    case AST_EXPR_LIST_ARITH:
    {
        DataTypes fdtype = FIRST_SON(node) ? FIRST_SON(node)->context->dtype : 0;
        DataTypes sdtype = SECOND_SON(node) ? SECOND_SON(node)->context->dtype : 0;
        
        switch (node->context->operation[0])
        {
        case ':':
        { /* Lado direito precisa ser uma lista */
            if (sdtype < DTYPE_LIST)
            {
                SEMANTIC_ERROR("number type used in right side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            /* Lado esquerdo precisa ser um numero */
            if (fdtype > DTYPE_LIST)
            {
                SEMANTIC_ERROR("list type used in left side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }
            /* Se o lado direito for NIL o tipo da lista é o lado esquerdo no tipo lista */
            if (sdtype == DTYPE_LIST)
            {
                return num2list(fdtype);
            }

            /*Se não retorna o tipo direito da lista */
            return sdtype;
        }
        case '<':
        {
            AstNode *func_node = lookup_global(root, FIRST_SON(node)->context->name) ? lookup_global(root, FIRST_SON(node)->context->name)->father : NULL;

            if (!func_node || (func_node && func_node->context->type != AST_FUNC_DECLARE))
            {
                SEMANTIC_ERROR("left operand needs to be a function of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            AstNode *params = THIRD_SON(func_node);

            if (params->kids->size != 1 || params->context->type != AST_LIST_PARAM)
            {
                SEMANTIC_ERROR("'%s' takes 1 argument in binary operation '%s' || line: %d, column: %d\n", SECOND_SON(func_node)->context->name, node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            DataTypes paramdt = FIRST_SON(params)->context->dtype;

            if (paramdt >= DTYPE_LIST)
            {
                SEMANTIC_ERROR("'%s' param type needs to be a int or float in binary operation '%s' || line: %d, column: %d\n", FIRST_SON(func_node)->context->name, node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            Symbol *sym_func = SECOND_SON(func_node)->context->sym_ref;

            if (!sym_func || (sym_func && !sym_func->isfunction))
            {
                SEMANTIC_ERROR("variable used in left side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            if (sdtype < DTYPE_LIST)
            {
                SEMANTIC_ERROR("number type used in right side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            if (fdtype > DTYPE_LIST)
            {
                SEMANTIC_ERROR("list type used in left side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            return sdtype;
        }

        case '>':
        {
            AstNode *func_node = lookup_global(root, FIRST_SON(node)->context->name) ? lookup_global(root, FIRST_SON(node)->context->name)->father : NULL;

            if (!func_node || (func_node && func_node->context->type != AST_FUNC_DECLARE))
            {
                SEMANTIC_ERROR("left operand needs to be a function of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            AstNode *params = THIRD_SON(func_node);

            if (params->kids->size != 1 || params->context->type != AST_LIST_PARAM)
            {
                SEMANTIC_ERROR("'%s' takes 1 argument in binary operation '%s' || line: %d, column: %d\n", SECOND_SON(func_node)->context->name, node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            DataTypes paramdt = FIRST_SON(params) ? FIRST_SON(params)->context->dtype : 0;

            if (paramdt >= DTYPE_LIST)
            {
                SEMANTIC_ERROR("'%s' param type needs to be a int or float in binary operation '%s' || line: %d, column: %d\n", FIRST_SON(func_node)->context->name, node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            Symbol *sym_func = SECOND_SON(func_node) ? SECOND_SON(func_node)->context->sym_ref : NULL;

            if (!sym_func || (sym_func && !sym_func->isfunction))
            {
                SEMANTIC_ERROR("variable used in left side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            if (sdtype < DTYPE_LIST)
            {
                SEMANTIC_ERROR("number type used in right side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            if (fdtype > DTYPE_LIST)
            {
                SEMANTIC_ERROR("list type used in left side of binary operation '%s' || line: %d, column: %d\n", node->context->operation, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                return DTYPE_ERROR;
            }

            return num2list(fdtype);
        }
        } // func >> list
    }
    case AST_FUNC_CALL:
    {
        Symbol *sym_func = FIRST_SON(node) ? FIRST_SON(node)->context->sym_ref : NULL;

        if (!sym_func || (sym_func->isfunction == 0))
        {
            SEMANTIC_ERROR("Function is not declared || line: %d, column: %d\n", node->context->node_pos.first_line, node->context->node_pos.first_column);
            return DTYPE_ERROR;
        }

        int params_type = -1;

        AstNode *params_func = THIRD_SON(lookup_global(root, sym_func->name)->father);
        params_type = params_func->context->type;

        AstNode *arg = SECOND_SON(node);

        if (((params_type == AST_LIST_PARAM) && !arg) || ((params_type != AST_LIST_PARAM) && arg))
        {
            SEMANTIC_ERROR("number of arguments and params doesn't match || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
            return DTYPE_ERROR;
        }
        else if (arg && params_func->kids->size != arg->kids->size)
        {
            SEMANTIC_ERROR("number of arguments and params doesn't match || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
            return DTYPE_ERROR;
        }

        if (arg)
        {
            Element *itp = params_func->kids->first;
            Element *ita = arg->kids->first;
            int paramdt = -1;
            int argdt = -1;
            for (; itp != NULL; itp = itp->next, ita = ita->next)
            {
                paramdt = ((AstNode *)itp->value)->context->dtype;
                argdt = ((AstNode *)ita->value)->context->dtype;

                if ((paramdt < DTYPE_LIST && argdt >= DTYPE_LIST) || (paramdt >= DTYPE_LIST && argdt < DTYPE_LIST))
                {
                    SEMANTIC_ERROR("Types of arguments and params doesn't match || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                    return DTYPE_ERROR;
                }

                if ((paramdt > DTYPE_LIST || argdt > DTYPE_LIST) && paramdt != argdt)
                {
                    SEMANTIC_ERROR("Types of arguments and params doesn't match || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
                    return DTYPE_ERROR;
                }
            }
        }

        return sym2dtype(sym_func->type_simbol);
    }
    case AST_EXPR_RETURN:
    {
        DataTypes fdtype = FIRST_SON(node) ? FIRST_SON(node)->context->dtype : 0;
        AstNode *it = node->father;
        for (; it->context->type != AST_FUNC_DECLARE; it = it->father)
            ;

        Symbol *sym_func = SECOND_SON(it) ? SECOND_SON(it)->context->sym_ref : NULL;
        int symdt = sym2dtype(sym_func->type_simbol);

        if (!dtcheck(fdtype, symdt))
        {
            SEMANTIC_ERROR("return with different type from function type || line: %d, column: %d\n", FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_line : -1, FIRST_SON(node) ? FIRST_SON(node)->context->node_pos.first_column : -1);
            return DTYPE_ERROR;
        }
    }
    default:
        return DTYPE_ERROR;
    }
    return DTYPE_ERROR;
}

int sem_eval(AstNode *root)
{
    if (!root)
        return DTYPE_ERROR;
    Element *first_son = root->kids->first;

    while (first_son != NULL)
    {
        sem_eval(first_son->value);
        // printf("fs: %s ret: %d\n", ((AstNode *)first_son->value)->context->name, ret);
        first_son = first_son->next;
    }

    int val = sem_check(root);
    root->context->dtype = val;
    // printf("%s_val: %d\n", root->context->name, val);

    return val;
}

char *error_string_type(int type)
{
    switch (type)
    {
    case DTYPE_ERROR:
        return "error";
    case DTYPE_INT:
        return "int";
    case DTYPE_FLOAT:
        return "float";
    case DTYPE_STRING:
        return "string";
    case DTYPE_LIST:
        return "NIL";
    case DTYPE_INT_LIST:
        return "int list";
    case DTYPE_FLOAT_LIST:
        return "float list";

    default:
        printf("unexpected type: %d\n", type);
        return "uknown type";
        break;
    }
}

int sym2dtype(int type)
{
    switch (type)
    {
    case INT_SYMBOL_CONST:
        return DTYPE_INT;
    case FLOAT_SYMBOL_CONST:
        return DTYPE_FLOAT;
    case INT_LIST_SYMBOL_CONST:
        return DTYPE_INT_LIST;
    case FLOAT_LIST_SYMBOL_CONST:
        return DTYPE_FLOAT_LIST;
    default:
        return DTYPE_ERROR;
        break;
    }
}

int list2num(int type)
{
    switch (type)
    {
    case DTYPE_INT_LIST:
        return DTYPE_INT;
    case DTYPE_FLOAT_LIST:
        return DTYPE_FLOAT;
    default:
        return DTYPE_ERROR;
        break;
    }
}

int num2list(int type)
{
    switch (type)
    {
    case DTYPE_INT:
        return DTYPE_INT_LIST;
    case DTYPE_FLOAT:
        return DTYPE_FLOAT_LIST;
    default:
        return DTYPE_ERROR;
        break;
    }
}

int dtcheck(int t1, int t2)
{
    if (t1 == t2)
        return t2;
    switch (t1)
    {
    case DTYPE_INT_LIST:
    case DTYPE_FLOAT_LIST:
        return t2 == DTYPE_LIST ? t1 : DTYPE_ERROR;
    case DTYPE_LIST:
        return (t2 == DTYPE_INT_LIST || t2 == DTYPE_FLOAT_LIST) ? t2 : DTYPE_ERROR;
    case DTYPE_INT:
        return t2 == DTYPE_FLOAT ? t2 : DTYPE_ERROR;
    case DTYPE_FLOAT:
        return t2 == DTYPE_INT ? t2 : DTYPE_ERROR;
    default:
        return DTYPE_ERROR;
    }
}