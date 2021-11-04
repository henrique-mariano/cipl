#include "../lib/code_gen.h"

#include <string.h>

static void write_string_literals(AstNode *node, FILE *fp)
{
    static int counter = 0;

    if (!node)
        return;

    Element *first_son = node->kids->first;

    while (first_son != NULL)
    {
        write_string_literals(first_son->value, fp);
        first_son = first_son->next;
    }

    if (node->context->type == AST_CONSTANT_STRING)
    {
        fprintf(fp, "char string%d[] = %s\n", counter, node->context->name);
        node->context->sym_ref = create_symbol(strdup("string_literal"), 0, -1, -1, 0, 0);
        node->context->sym_ref->variable_tac = counter++;
    }
}

static void write_table_section(AstNode *root, FILE *fp)
{
    fprintf(fp, ".table\n");
    write_string_literals(root, fp);
}

static void write_code_section(FILE *fp)
{
    fprintf(fp, ".code\n");
    fprintf(fp, "main:\n\n");
}

static void write_end_of_program(FILE *fp)
{
    fprintf(fp, "jump fn_main\n");
    fprintf(fp, "END_OF_PROGRAM:\n");
    fprintf(fp, "nop\n\n");
}

static void _code_gen(AstNode *node, FILE *fp);

static void rec_gen_code(AstNode *node, FILE *fp)
{
    Element *first_son = node->kids->first;
    while (first_son != NULL)
    {
        _code_gen(first_son->value, fp);
        first_son = first_son->next;
    }
}

static AstContext *get_current_function(AstNode *curr_node)
{
    AstNode *it = curr_node->father;
    for (; it && it->context->type != AST_FUNC_DECLARE; it = it->father)
        ;
    return it ? SECOND_SON(it)->context : NULL;
}

// var = [VAL, DTYPE]
static void write_var_declaration(DataTypes dtype, int temp, FILE *fp)
{
    fprintf(fp, "// Var Declare\n");
    fprintf(fp, "mema $%d, 2\n", temp);
    if (dtype == DTYPE_INT)
        fprintf(fp, "mov *$%d, %d\n", temp, 0);
    else
        fprintf(fp, "mov *$%d, %lf\n", temp, 0.0);
    fprintf(fp, "mov $%d[1], %d\n", temp, dtype);
    fprintf(fp, "//End Var Declare\n\n");
}

// static char *write_star_for_var(AstContext *ctx)
// {
//     return ctx->type == AST_ID ? "*" : "";
// }

static void _code_gen(AstNode *node, FILE *fp)
{
    static int label_count = 0;

    if (!node)
        return;

    AstContext *func_ctx = get_current_function(node);

    switch (node->context->type)
    {
    case AST_ROOT:
        rec_gen_code(node, fp);
        break;
    case AST_FUNC_DECLARE:
    {
        char *fname = SECOND_SON(node)->context->name;
        fprintf(fp, "jump fn_%s_END\n", fname);
        fprintf(fp, "fn_%s:\n", fname);
        AstNode *maybe_params = THIRD_SON(node);
        if (maybe_params->context->type == AST_LIST_PARAM)
        {
            //TODO: printf("func params\n");
        }
        else
        {
            rec_gen_code(maybe_params, fp);
        }
        fprintf(fp, "fn_%s_END:\n", fname);
        break;
    }
    case AST_VAR_DECLARE:
    {
        DataTypes var_type = FIRST_SON(node)->context->dtype;
        Symbol *var_name = SECOND_SON(node)->context->sym_ref;
        int temp_var = var_name->variable_tac;
        fprintf(fp, "// %s %s\n", error_string_type(var_type), var_name->name);
        write_var_declaration(var_type, temp_var, fp);
        break;
    }
    case AST_STATE_COMPOUND:
    case AST_CODE_BLOCK:
    case AST_LIST_CODEBLOCK:
        rec_gen_code(node, fp);
        break;
    case AST_EXPR_RETURN:
    {
        if (!strcmp("main", func_ctx->sym_ref->name))
        {
            fprintf(fp, "jump END_OF_PROGRAM\n");
        }
        else
        {
            fprintf(fp, "return $%d\n", func_ctx->last_temp);
        }
        break;
    }
    case AST_ID:
    {
        Symbol *var_arg = node->context->sym_ref;
        fprintf(fp, "push $%d\n", var_arg->variable_tac);
        break;
    }
    case AST_BUILT_IN:
    {
        AstContext *fs_ctx = FIRST_SON(node)->context;
        AstContext *ss_ctx = SECOND_SON(node)->context;
        Symbol *var_arg = ss_ctx->sym_ref;

        fprintf(fp, "// Built-in\n");
        _code_gen(SECOND_SON(node), fp);

        fprintf(fp, "pop $%d\n", func_ctx->last_temp);
        if (!strcmp(fs_ctx->name, "read"))
        {
            fprintf(fp, "mov $%d, *$%d\n", func_ctx->last_temp, func_ctx->last_temp);
            fprintf(fp, "scan%c $%d\n", ss_ctx->dtype == DTYPE_INT ? 'i' : 'f', func_ctx->last_temp);
            fprintf(fp, "mov *$%d, $%d\n", var_arg->variable_tac, func_ctx->last_temp);
        }
        else
        {
            if (ss_ctx->type == AST_CONSTANT_STRING)
            {
                fprintf(fp, "write_STRING_%d:\n", label_count);
                fprintf(fp, "mov $%d, 0\n", func_ctx->last_temp + 1);
                fprintf(fp, "write_STRING_%d_LOOP:\n", label_count);
                fprintf(fp, "mov $%d, '\\0'\n", func_ctx->last_temp + 2);
                fprintf(fp, "mov $%d, $%d[$%d]\n", func_ctx->last_temp + 3, func_ctx->last_temp, func_ctx->last_temp + 1);
                fprintf(fp, "seq $%d, $%d, $%d\n", func_ctx->last_temp + 2, func_ctx->last_temp + 2, func_ctx->last_temp + 3);
                fprintf(fp, "brnz write_ENDING_%d, $%d\n", label_count, func_ctx->last_temp + 2);
                fprintf(fp, "print $%d\n", func_ctx->last_temp + 3);
                fprintf(fp, "add $%d, $%d, 1\n", func_ctx->last_temp + 1, func_ctx->last_temp + 1);
                fprintf(fp, "jump write_STRING_%d_LOOP\n", label_count);
                fprintf(fp, "write_ENDING_%d:\n", label_count++);
                if (strstr(fs_ctx->name, "ln"))
                    fprintf(fp, "println \n");
            }
            else
            {
                fprintf(fp, "mov $%d, *$%d\n", func_ctx->last_temp, func_ctx->last_temp);
                fprintf(fp, "print%s $%d\n", strstr(fs_ctx->name, "ln") ? "ln" : "", func_ctx->last_temp);
            }
        }
        fprintf(fp, "// End Built-in\n\n");
        break;
    }
    case AST_EXPR_ASSIGN:
    {
        AstContext *fs_ctx = FIRST_SON(node)->context;
        fprintf(fp, "// Assign\n");
        _code_gen(SECOND_SON(node), fp);
        fprintf(fp, "pop $%d\n", func_ctx->last_temp);
        fprintf(fp, "mov *$%d, *$%d\n", fs_ctx->sym_ref->variable_tac, func_ctx->last_temp);
        fprintf(fp, "// End Assign\n\n");
        break;
    }
    case AST_CONSTANT_INT:
        write_var_declaration(DTYPE_INT, func_ctx->last_temp, fp);
        fprintf(fp, "mov *$%d, %ld\n", func_ctx->last_temp, atol(node->context->name));
        fprintf(fp, "push $%d\n", func_ctx->last_temp);
        break;
    case AST_CONSTANT_REAL:
        write_var_declaration(DTYPE_FLOAT, func_ctx->last_temp, fp);
        fprintf(fp, "mov *$%d, %lf\n", func_ctx->last_temp, atof(node->context->name));
        fprintf(fp, "push $%d\n", func_ctx->last_temp);
        break;
    case AST_EXPR_BIN_ARITH:
    {
        fprintf(fp, "// Binary op\n");

        _code_gen(FIRST_SON(node), fp);
        _code_gen(SECOND_SON(node), fp);

        fprintf(fp, "pop $%d\n", func_ctx->last_temp + 1);
        fprintf(fp, "mov $%d, *$%d\n", func_ctx->last_temp + 3, func_ctx->last_temp + 1);

        if (SECOND_SON(node)->context->dtype != node->context->dtype)
        {
            int cast_to = dtcheck(SECOND_SON(node)->context->dtype, node->context->dtype);
            fprintf(fp, "%s $%d, $%d\n", cast_to == DTYPE_INT ? "fltoint" : "inttofl", func_ctx->last_temp + 3, func_ctx->last_temp + 3);
        }

        fprintf(fp, "pop $%d\n", func_ctx->last_temp);
        fprintf(fp, "mov $%d, *$%d\n", func_ctx->last_temp + 2, func_ctx->last_temp);

        if (FIRST_SON(node)->context->dtype != node->context->dtype)
        {
            int cast_to = dtcheck(FIRST_SON(node)->context->dtype, node->context->dtype);
            fprintf(fp, "%s $%d, $%d\n", cast_to == DTYPE_INT ? "fltoint" : "inttofl", func_ctx->last_temp + 2, func_ctx->last_temp + 2);
        }

        switch (node->context->operation[0])
        {
        case '+':
            fprintf(fp, "add $%d, $%d, $%d\n", func_ctx->last_temp + 3,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 4, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 4, func_ctx->last_temp + 3);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 4);
            break;
        case '-':
            fprintf(fp, "sub $%d, $%d, $%d\n", func_ctx->last_temp + 3,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 4, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 4, func_ctx->last_temp + 3);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 4);
            break;
        case '/':
            fprintf(fp, "div $%d, $%d, $%d\n", func_ctx->last_temp + 3,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 4, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 4, func_ctx->last_temp + 3);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 4);
            break;
        case '*':
            fprintf(fp, "mul $%d, $%d, $%d\n", func_ctx->last_temp + 3,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 4, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 4, func_ctx->last_temp + 3);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 4);
            break;
        case '=':
            fprintf(fp, "seq $%d, $%d, $%d\n", func_ctx->last_temp + 3,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp + 3);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            break;
        case '!':
            fprintf(fp, "seq $%d, $%d, $%d\n", func_ctx->last_temp + 3,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            fprintf(fp, "not $%d, $%d\n", func_ctx->last_temp, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            break;
        case '>':
        {
            // lhs >= rhs = !(lhs < rhs)
            if (strlen(node->context->operation) != 1)
            {
                fprintf(fp, "slt $%d, $%d, $%d\n", func_ctx->last_temp, func_ctx->last_temp + 2, func_ctx->last_temp + 3);
                fprintf(fp, "not $%d, $%d\n", func_ctx->last_temp,
                        func_ctx->last_temp);
                write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
                fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp);
                fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            }
            else
            {
                // lhs > rhs = (rhs <= lhs) && (lhs != rhs)
                fprintf(fp, "sleq $%d, $%d, $%d\n", func_ctx->last_temp + 4,
                        func_ctx->last_temp + 3, func_ctx->last_temp + 2);
                fprintf(fp, "seq $%d, $%d, $%d\n", func_ctx->last_temp + 5,
                        func_ctx->last_temp + 2, func_ctx->last_temp + 3);
                fprintf(fp, "not $%d, $%d\n", func_ctx->last_temp + 5,
                        func_ctx->last_temp + 5);
                fprintf(fp, "and $%d, $%d, $%d\n", func_ctx->last_temp,
                        func_ctx->last_temp + 4, func_ctx->last_temp + 5);
                write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
                fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp);
                fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            }
            break;
        }
        case '<':
            fprintf(fp, "%s $%d, $%d, $%d\n",
                    strlen(node->context->operation) == 1 ? "slt" : "sleq", func_ctx->last_temp,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            break;
        case '&':
            fprintf(fp, "and $%d, $%d, $%d\n", func_ctx->last_temp,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            break;
        case '|':
            fprintf(fp, "or $%d, $%d, $%d\n", func_ctx->last_temp,
                    func_ctx->last_temp + 2, func_ctx->last_temp + 3);
            write_var_declaration(node->context->dtype, func_ctx->last_temp + 1, fp);
            fprintf(fp, "mov *$%d, $%d\n", func_ctx->last_temp + 1, func_ctx->last_temp);
            fprintf(fp, "push $%d\n", func_ctx->last_temp + 1);
            break;
        }
        fprintf(fp, "// End Binary op\n\n");
        break;
    }
    case AST_CONSTANT_STRING:
        fprintf(fp, "// String\n");
        fprintf(fp, "mov $%d, &string%d\n", func_ctx->last_temp, node->context->sym_ref->variable_tac);
        fprintf(fp, "push $%d\n", func_ctx->last_temp);
        fprintf(fp, "// End String\n\n");
        break;
    default:
        printf(RED "Code gen: Tipo não implementado" RESET " AST_TYPE: %s\n", nome_tipos_ast[node->context->type]);
    }
}

void code_gen(AstNode *root, FILE *fp)
{
    write_table_section(root, fp);
    write_code_section(fp);
    _code_gen(root, fp);
    write_end_of_program(fp);
}
