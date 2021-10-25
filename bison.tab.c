/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "./src/bison.y"

    // Autor: Henrique Mendes de Freitas Mariano - 17/0012280
    #include <stdio.h>
    #include "lib/tree.h"
    #include "lib/astcontext.h"
    #include "lib/symbol.h"
    #include "lib/context.h"
    #include "lib/treenode.h"
    #include "lib/sem_eval.h"
    #include "lib/macros.h"
    #include "lib/code_gen.h"

    // extern int num_line, num_col;

    int erros = 0;

    int semantic_error = 0;

    unsigned int temporary_count = 0;

    unsigned int current_scope;
    
    extern int yyparse();
    extern int yylex();
    extern int yylex_destroy();
    extern void yyerror(const char *error_msg);

    extern FILE *yyin;

    /* No raiz da arvore sintatica abstrata */
    AstNode *root;

    /* Contexto atual e arvore de contextos */
    List *list_context;
    TreeNode *current_context;
    TreeNode *last_context;
    TreeNode *global_context;
    int isFunctionContext;

    /* Lista para ajudar na criacao da arvore */
    List *node_aux;

    void delete_single_node(Element *node);
    void delete_list_treenode(Element *elem);
    void delete_tree_symbol_table(void *sym);
    unsigned int type_check(AstNode *root);

#line 119 "bison.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "lib/bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_TOKEN = 3,                  /* INT_TOKEN  */
  YYSYMBOL_FLOAT_TOKEN = 4,                /* FLOAT_TOKEN  */
  YYSYMBOL_LIST_TOKEN = 5,                 /* LIST_TOKEN  */
  YYSYMBOL_ID_TOKEN = 6,                   /* ID_TOKEN  */
  YYSYMBOL_READ_TOKEN = 7,                 /* READ_TOKEN  */
  YYSYMBOL_WRITE_TOKEN = 8,                /* WRITE_TOKEN  */
  YYSYMBOL_NIL_TOKEN = 9,                  /* NIL_TOKEN  */
  YYSYMBOL_CONSTANT_REAL_TOKEN = 10,       /* CONSTANT_REAL_TOKEN  */
  YYSYMBOL_CONSTANT_INTEGER_TOKEN = 11,    /* CONSTANT_INTEGER_TOKEN  */
  YYSYMBOL_MUL_DIV_TOKEN = 12,             /* MUL_DIV_TOKEN  */
  YYSYMBOL_EXCLAMATION_TOKEN = 13,         /* EXCLAMATION_TOKEN  */
  YYSYMBOL_QUESTION_TOKEN = 14,            /* QUESTION_TOKEN  */
  YYSYMBOL_PERCENTAGE_TOKEN = 15,          /* PERCENTAGE_TOKEN  */
  YYSYMBOL_ADD_MIN_TOKEN = 16,             /* ADD_MIN_TOKEN  */
  YYSYMBOL_MAP_TOKEN = 17,                 /* MAP_TOKEN  */
  YYSYMBOL_FILTER_TOKEN = 18,              /* FILTER_TOKEN  */
  YYSYMBOL_CONSTRUCTOR_LIST_TOKEN = 19,    /* CONSTRUCTOR_LIST_TOKEN  */
  YYSYMBOL_ASSIGN_TOKEN = 20,              /* ASSIGN_TOKEN  */
  YYSYMBOL_OR_TOKEN = 21,                  /* OR_TOKEN  */
  YYSYMBOL_AND_TOKEN = 22,                 /* AND_TOKEN  */
  YYSYMBOL_EQ_EXC_TOKEN = 23,              /* EQ_EXC_TOKEN  */
  YYSYMBOL_LE_GR_TOKEN = 24,               /* LE_GR_TOKEN  */
  YYSYMBOL_ADD_UNARY_TOKEN = 25,           /* ADD_UNARY_TOKEN  */
  YYSYMBOL_MIN_UNARY_TOKEN = 26,           /* MIN_UNARY_TOKEN  */
  YYSYMBOL_EQUAL_TOKEN = 27,               /* EQUAL_TOKEN  */
  YYSYMBOL_DIFF_EQ_TOKEN = 28,             /* DIFF_EQ_TOKEN  */
  YYSYMBOL_LESS_TOKEN = 29,                /* LESS_TOKEN  */
  YYSYMBOL_LE_EQ_TOKEN = 30,               /* LE_EQ_TOKEN  */
  YYSYMBOL_GREAT_TOKEN = 31,               /* GREAT_TOKEN  */
  YYSYMBOL_GR_EQ_TOKEN = 32,               /* GR_EQ_TOKEN  */
  YYSYMBOL_ADD_TOKEN = 33,                 /* ADD_TOKEN  */
  YYSYMBOL_MIN_TOKEN = 34,                 /* MIN_TOKEN  */
  YYSYMBOL_MUL_TOKEN = 35,                 /* MUL_TOKEN  */
  YYSYMBOL_DIV_TOKEN = 36,                 /* DIV_TOKEN  */
  YYSYMBOL_UNI_OP = 37,                    /* UNI_OP  */
  YYSYMBOL_IF_TOKEN = 38,                  /* IF_TOKEN  */
  YYSYMBOL_ELSE_TOKEN = 39,                /* ELSE_TOKEN  */
  YYSYMBOL_FOR_TOKEN = 40,                 /* FOR_TOKEN  */
  YYSYMBOL_RETURN_TOKEN = 41,              /* RETURN_TOKEN  */
  YYSYMBOL_STRING_TOKEN = 42,              /* STRING_TOKEN  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_startProgram = 54,              /* startProgram  */
  YYSYMBOL_declarationList = 55,           /* declarationList  */
  YYSYMBOL_declaration = 56,               /* declaration  */
  YYSYMBOL_variableDeclare = 57,           /* variableDeclare  */
  YYSYMBOL_functionDeclare = 58,           /* functionDeclare  */
  YYSYMBOL_59_1 = 59,                      /* @1  */
  YYSYMBOL_optListParams = 60,             /* optListParams  */
  YYSYMBOL_listParams = 61,                /* listParams  */
  YYSYMBOL_param = 62,                     /* param  */
  YYSYMBOL_compoundStatement = 63,         /* compoundStatement  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_optListCodeBlock = 65,          /* optListCodeBlock  */
  YYSYMBOL_listCodeBlock = 66,             /* listCodeBlock  */
  YYSYMBOL_codeBlock = 67,                 /* codeBlock  */
  YYSYMBOL_statement = 68,                 /* statement  */
  YYSYMBOL_flowExpression = 69,            /* flowExpression  */
  YYSYMBOL_condExpression = 70,            /* condExpression  */
  YYSYMBOL_elseError = 71,                 /* elseError  */
  YYSYMBOL_interationExpression = 72,      /* interationExpression  */
  YYSYMBOL_returnExpression = 73,          /* returnExpression  */
  YYSYMBOL_optExpression = 74,             /* optExpression  */
  YYSYMBOL_expression = 75,                /* expression  */
  YYSYMBOL_assignArith = 76,               /* assignArith  */
  YYSYMBOL_77_3 = 77,                      /* $@3  */
  YYSYMBOL_binArith = 78,                  /* binArith  */
  YYSYMBOL_listArith = 79,                 /* listArith  */
  YYSYMBOL_unaArith = 80,                  /* unaArith  */
  YYSYMBOL_constant = 81,                  /* constant  */
  YYSYMBOL_constantInteger = 82,           /* constantInteger  */
  YYSYMBOL_constantReal = 83,              /* constantReal  */
  YYSYMBOL_constantNIL = 84,               /* constantNIL  */
  YYSYMBOL_funcCall = 85,                  /* funcCall  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_ioCommand = 87,                 /* ioCommand  */
  YYSYMBOL_optListExpression = 88,         /* optListExpression  */
  YYSYMBOL_listExpression = 89,            /* listExpression  */
  YYSYMBOL_id = 90,                        /* id  */
  YYSYMBOL_type = 91                       /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   17218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  683

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    45,    43,    50,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   138,   142,   148,   151,   157,   160,   165,
     173,   194,   200,   207,   214,   223,   223,   272,   275,   279,
     283,   289,   296,   318,   324,   332,   332,   367,   370,   374,
     378,   385,   388,   393,   397,   400,   403,   406,   411,   416,
     423,   426,   429,   435,   440,   448,   454,   461,   468,   474,
     483,   489,   497,   509,   517,   525,   533,   540,   547,   552,
     559,   565,   572,   575,   581,   584,   587,   590,   593,   596,
     599,   610,   617,   626,   626,   642,   648,   654,   660,   666,
     672,   678,   684,   690,   696,   702,   708,   715,   720,   725,
     730,   735,   740,   745,   750,   755,   760,   765,   770,   778,
     784,   790,   797,   802,   807,   815,   820,   825,   830,   835,
     841,   845,   849,   853,   857,   864,   870,   873,   879,   886,
     893,   900,   900,   924,   936,   941,   948,   955,   960,   965,
     973,   976,   980,   984,   991,   997,  1002,  1007,  1018
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "INT_TOKEN", "FLOAT_TOKEN",
  "LIST_TOKEN", "ID_TOKEN", "READ_TOKEN", "WRITE_TOKEN", "NIL_TOKEN",
  "CONSTANT_REAL_TOKEN", "CONSTANT_INTEGER_TOKEN", "MUL_DIV_TOKEN",
  "EXCLAMATION_TOKEN", "QUESTION_TOKEN", "PERCENTAGE_TOKEN",
  "ADD_MIN_TOKEN", "MAP_TOKEN", "FILTER_TOKEN", "CONSTRUCTOR_LIST_TOKEN",
  "ASSIGN_TOKEN", "OR_TOKEN", "AND_TOKEN", "EQ_EXC_TOKEN", "LE_GR_TOKEN",
  "ADD_UNARY_TOKEN", "MIN_UNARY_TOKEN", "EQUAL_TOKEN", "DIFF_EQ_TOKEN",
  "LESS_TOKEN", "LE_EQ_TOKEN", "GREAT_TOKEN", "GR_EQ_TOKEN", "ADD_TOKEN",
  "MIN_TOKEN", "MUL_TOKEN", "DIV_TOKEN", "UNI_OP", "IF_TOKEN",
  "ELSE_TOKEN", "FOR_TOKEN", "RETURN_TOKEN", "STRING_TOKEN", "'+'", "'-'",
  "'*'", "'/'", "';'", "'('", "')'", "','", "'{'", "'}'", "$accept",
  "startProgram", "declarationList", "declaration", "variableDeclare",
  "functionDeclare", "@1", "optListParams", "listParams", "param",
  "compoundStatement", "$@2", "optListCodeBlock", "listCodeBlock",
  "codeBlock", "statement", "flowExpression", "condExpression",
  "elseError", "interationExpression", "returnExpression", "optExpression",
  "expression", "assignArith", "$@3", "binArith", "listArith", "unaArith",
  "constant", "constantInteger", "constantReal", "constantNIL", "funcCall",
  "$@4", "ioCommand", "optListExpression", "listExpression", "id", "type", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    43,    45,    42,    47,    59,    40,    41,
      44,   123,   125
};
#endif

#define YYPACT_NINF (-509)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-139)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6256,     6,   164,   170,  1997,    13,    19, 15311, 15342, 15373,
    4571,  4996,  5091,    24,    25,  5379,  7602,  7613,  7624,    94,
      42,  6302,  6318,  6364,  6380,  6426,  6442,  6488,  6504,  6550,
      17, 15404, 15435, 15466, 15497, 15528, 15559, 15590, 15621, 15652,
   15683,  6566,  2422,     7,  6612,    52,   121,    71,    18,    83,
    1009, 15714,   366, 15745,  3272, 15776, 15807, 15838, 15869,  6628,
    7664,  6674,   909,   119, 15900, 15931, 15962, 15993, 16024,   140,
   13100,   827,  -509,   171,  6690,  6736,  7675,  7686,  7726,  7737,
    7748,  7788,  7799,  7810,  7850,  7861,  7872,  7912,  7923,  7934,
    7974,  6752, 16055,    35,   188,   -13,  6798,   224,  6814,   148,
     181,  6860,   206,   225, 13133,   242, 13166,    -9,   226, 16086,
    6876, 16117,   134,  3391,   936,   257,  1061,  1079,  1359,  1375,
     143, 16148, 16179, 16210, 16241, 16272, 16303, 16334, 16365, 16396,
   16427, 16458, 16489, 16520, 16551, 16582, 16613, 16644, 16675, 16706,
   16737, 16768, 16799, 16830, 16861, 16892, 16923, 16954, 16985, 17016,
   17047,  2987,  2137,   300,  6922,   315,  6938,    45,   271,   273,
     285,   286,   287,   495,   958,  1712,  6984,  2761,  3391,  1438,
    7000,  1490,    97, 17078,  2675,   288,   128,  7046,  7062,   125,
    7108,  7124,  7170,  7186,  7232,  3816,  1508,  3816,  1781,   149,
     182,   291,  1796, 17109,  3412,   249,   311,   254,   256,   258,
     133,  7248,  3816,  7294,  3816,  2562,  3816,  2562,  3816,    22,
    3525,   284,   248,   262,  7310,  7356,   312,  7372,   313,  7418,
     314,   317,  7434,   265,  3816,  3816,  3816,  3816,  7480,  7496,
    7542,  7558,  4122,  1284, 13199, 13232, 13265,  7985,  7996,  8036,
    8047,  8058,   366, 13298, 13331, 13364, 13397, 13430, 13463, 13496,
   13529, 13562,  1572,   137,   229,   319,  8098,  8109,  8120,  8160,
    8171,  8182,  8222,  8233,  8244,  8284,  8295,  8306,  8346,  8357,
    8368,    26,    58,    62,    74,  8408,    94,  1863,  1915,  1932,
    2209,   322, 17140,  2224,  2422,  2288,   323,  2340,   401,  9315,
    9349,  9383,  8419,  8430,  8470,  8481,  8492,   366,  9417,  9451,
    9485,  9519,  9553,  9587,  9621,  9655,  9689,   863,   324,    92,
      95,   112,   113,  8532,    94,  2358,  2631,  2647,  2750,   326,
   17171,  2810,   536, 11219, 11252, 11285,  8543,  8554,  8594,  8605,
    8616,   366, 11318, 11351, 11384, 11417, 11450, 11483, 11516, 11549,
   11582, 11615,  1134,   321,  2825,  8656,  8667,  8678,  8718,  8729,
    8740,  8780,  8791,  8802,  8842,  8853,  8864,  8904,  8915,  8926,
     142,   150,   275, 13595, 13628, 13661, 13694, 13727, 13760, 13793,
   13826, 13859, 13892, 13925, 13958, 13991,   316,   330, 14024, 14057,
   14090, 14123, 14156, 14189, 14222, 14255, 14288, 14321, 14354, 14387,
   14420, 14453, 14486, 14519, 14552, 14585, 14618, 14651, 14684, 14717,
   14750, 14783, 14816, 14849, 14882, 14915, 14948, 14981,   327,    38,
     336,  2881,  3059,  8966,  3074,  3611,   340,   827,  3138,  3190,
     166,  9723,  9757,  9791,  9825,  9859,  9893,  9927,  9961,  9995,
   10029, 15014, 10063,   344,   337,  3208,   343,   214,   345,  3731,
    3481,  8977,  3497,  4548,   342,   827,  3600,  3660, 11648, 11681,
   11714, 11747, 11780, 11813, 11846, 11879, 11912, 11945, 15047,  8988,
    9028,  9039,  9050,  9090,  9101,  9112,  9152,  9163,  9174,  9214,
    9225,  9236,  9276,  9287, 11978,   373,   346,  3675, 10097, 10131,
   10165, 10199, 10233, 10267, 10301, 10335, 10369, 10403, 10437, 10471,
   10505, 10539, 10573, 10607, 10641, 10675, 10709, 10743, 10777, 10811,
   10845, 10879, 10913, 10947, 10981, 11015, 11049, 11083,   173,   197,
   15080,   366,  2137,  3909,   347,   348,  3924,   349,   350, 15113,
     351, 15146,   196,   354,  3988,   360,   394,  4040, 11117,  3412,
    2137,  4058,   367,   368,  4331,   376,   378, 15179,   385, 15212,
     201,   356,  4347,   383, 12011, 12044, 12077, 12110, 12143, 12176,
   12209, 12242, 12275, 12308, 12341, 12374, 12407, 12440, 12473, 12506,
   12539, 12572, 12605, 12638, 12671, 12704, 12737, 12770, 12803, 12836,
   12869, 12902, 12935, 12968, 13001,  3837,  2137, 15245,   388,   389,
     395,   407,   408,   409,  1691,  2116,  1712,  4413,  4666,  4465,
    4482, 11151,   399,   410,   411,   431,   433,   434,  2541,  2966,
    1712,  4756,  4973,  4772, 13034,   436, 15278,  4838,  4890,  4907,
    5184,  5199,  3391,  5259,  3391,  5313,   233,   237,   435, 11185,
    5333,  5401,  5471,  5487,  5533,  4241,  5549,  4241,  5595,   238,
     241,   440, 13067,  5610,  3391,  5662,  3391,  2562,  3391,  2562,
    3391,   110,  5678,  4241,  5724,  4241,  2562,  4241,  2562,  4241,
     800,  5739,  5791,   441,  5806,   443,  5858,   445,   449,  5874,
    5920,   451,  5936,   458,  5982,   468,   469,  3391,  3391,  3391,
    3391,  4241,  4241,  4241,  4241,  5997,  6049,  6064,  6116,  6132,
    6178,  6194,  6240
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -509,  -509,  -509,   462,   141,  -509,  -509,  -509,  -509,   277,
       8,  -164,  -376,  -509,   403,   115,   180,   289,  -509,   387,
     499,  -162,     0,  1420,  -251,  1845,  2270,  2695,  3120,  3545,
    3970,  4395,  4820,  -250,   569,  -508,  -509,   995,     9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,   114,    24,   179,   196,   197,   198,
     277,    71,   115,   116,   117,   118,   278,   279,   119,   280,
     281,   108,   282,    32,    93,    33,    34,    35,    36,    37,
      38,    39,    40,    94,   283,   175,   176,    54,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   376,   377,   189,   578,   191,    -3,   153,    25,    43,
      53,    56,    58,   254,    47,    64,    66,    68,    70,    99,
      49,    31,   592,   220,   255,    59,    61,   408,   233,    25,
      43,   234,   235,   236,   154,   237,   238,   239,   165,   514,
     166,   525,    72,   216,   255,   218,   -15,   221,   -15,   -15,
     104,   -15,    70,    44,    96,   151,   433,   434,  -137,   410,
     106,    48,   109,   412,    75,   240,   241,    50,   605,   543,
     242,   -62,    60,    62,   409,   414,   122,   124,   126,   128,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   475,   476,   436,   -15,   -25,   438,   -25,   -25,  -137,
     -25,   -25,   -25,   -25,   -25,   -25,   411,   -25,   -25,   -25,
     413,   657,   417,   440,   442,    26,   233,   343,    98,   234,
     235,   236,   415,   237,   238,   239,   195,  -138,   360,   361,
     101,   362,   -25,   -25,   -25,   -25,    26,   -25,   -25,   362,
     437,    23,   -25,   439,   344,   -25,   -25,   508,  -135,   253,
     445,   173,   174,   240,   241,   509,  -136,  -134,   242,   -62,
     441,   443,    23,   320,   320,   332,   -61,   109,  -138,    45,
    -135,   315,   315,   168,   -17,    46,  -136,  -131,   194,  -137,
      27,   285,   -23,   -23,  -134,    31,   526,    31,   200,   110,
     287,  -135,  -135,    25,   210,    25,   205,   158,   206,  -136,
    -136,    27,    31,  -138,    31,   363,    31,   363,    31,   363,
      25,  -135,    25,   527,    25,   532,    25,  -136,    44,   222,
     255,   200,  -137,  -137,    31,    31,    31,    31,   169,   207,
     159,   208,    25,    25,    25,    25,   152,   365,   367,   369,
     371,   373,   374,   586,   155,   587,  -138,  -138,   600,  -134,
     601,   360,   361,   523,   362,   160,   379,   381,   383,   385,
     387,   389,   391,   393,   395,   397,   399,   401,   403,   405,
     407,   156,   157,   167,   161,    70,  -134,  -134,   186,   188,
     637,   541,   638,   192,   639,   646,   640,   647,   648,    28,
     649,   163,   422,   424,   426,   428,   430,   431,   -21,   -21,
     201,   177,   203,   -18,   212,   -20,   -20,   -24,   -24,   170,
      28,   -22,   -22,    70,   -19,   -19,   178,   214,   180,   215,
     181,   217,   477,   219,  -134,  -134,   449,   451,   453,   455,
     457,   458,   182,   183,   184,    19,   511,   193,   209,   228,
     229,   230,   231,   316,   316,   479,   481,   483,   485,   487,
     489,   491,   493,   495,   497,   499,   501,   503,   505,   507,
     211,   224,   225,   226,   529,    27,   227,    27,  -134,   418,
     285,   435,   233,   446,   513,   234,   235,   236,   512,   237,
     238,   239,    27,   516,    27,   530,    27,    29,    27,   524,
     531,   542,   534,   575,   576,   590,   579,   580,   581,   582,
     584,   588,  -134,   602,    27,    27,    27,    27,    29,   240,
     241,   519,   589,   521,   242,   109,   593,   594,  -134,  -134,
    -134,  -134,  -134,  -134,   616,   595,   618,   596,  -134,  -134,
    -134,  -134,  -134,  -134,   598,   603,   607,   606,   629,   537,
     631,   539,   608,   109,  -134,  -134,  -134,  -134,   619,  -134,
    -134,  -134,   317,   317,   609,   610,   611,   620,   621,   546,
     548,   550,   552,   554,   556,   558,   560,   562,   564,   566,
     568,   570,   572,   574,    28,   653,    28,   655,   622,   658,
     623,   624,   641,    74,   661,   632,   663,   650,   666,   223,
     667,    28,   668,    28,   669,    28,   308,    28,   670,    30,
     671,   232,   309,   310,     7,     8,     9,   672,    10,    11,
      12,   577,   174,    28,    28,    28,    28,   673,   674,   171,
      30,     0,     0,     0,     0,     0,     0,     0,     0,   591,
     174,     0,     0,   311,   185,   312,    15,  -134,    16,    17,
       0,     0,     0,   313,     0,     0,   314,     0,     0,     0,
     318,   318,     0,  -134,  -134,  -134,  -134,  -134,  -134,     0,
       0,     0,     0,  -134,  -134,  -134,  -134,  -134,  -134,    41,
       0,     0,    29,     0,    29,   604,   174,     0,     0,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,   332,     0,   109,    29,
      41,    29,     0,    29,     0,    29,     0,     0,   320,   320,
     332,     0,   109,     0,     0,     0,   315,   315,     0,     0,
       0,    29,    29,    29,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,     0,   320,     0,     0,
       0,     0,     0,   315,     0,   315,     0,   363,     0,   363,
       0,   363,     0,   320,     0,   320,   363,   320,   363,   320,
     363,   315,     0,   315,     0,   315,     0,   315,     0,     0,
       0,     0,   319,   319,     0,     0,     0,     0,     0,     0,
       0,   320,   320,   320,   320,     0,     0,     0,     0,   315,
     315,   315,   315,     0,    30,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     615,    30,     0,    30,     0,    30,     0,    30,     0,     0,
       0,     0,     0,   626,   628,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    30,    30,    30,   633,     0,   635,
       0,     0,   321,   321,     0,     0,     0,     0,     0,     0,
     642,     0,   644,     0,     0,     0,     0,     0,     0,   651,
       0,   652,     0,   654,    41,   656,    41,     0,   659,     0,
     660,     0,   662,     0,   664,     0,     0,     0,     0,     0,
       0,    41,     0,    41,     0,    41,     0,    41,   316,   316,
       0,     0,   675,   676,   677,   678,   679,   680,   681,   682,
       0,     0,     0,    41,    41,    41,    41,     0,     0,     0,
       0,   665,     0,     0,     0,   316,   233,   316,     0,   234,
     235,   236,     0,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,   316,     0,   316,     0,   316,   112,   316,
       2,     3,     0,     4,   271,   272,     7,     8,     9,     0,
      10,    11,    12,   240,   241,     0,     0,     0,   242,   -62,
       0,   316,   316,   316,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   273,   113,   274,    15,     0,
      16,    17,     0,     0,     0,   275,     0,     0,   276,   -27,
     -70,   -70,   -70,   -73,   -70,   -70,     0,   317,   317,     0,
     -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -70,   -70,   -70,   -70,
     107,  -121,   -70,   -70,   317,   232,   317,     0,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,   317,     0,   317,     0,   317,   -32,   317,   -32,
     -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,
     -32,   -32,    16,    17,     0,     0,   -62,    52,     0,   308,
     317,   317,   317,   317,   232,   309,   310,     7,     8,     9,
       0,    10,    11,    12,   -32,   -32,   -32,   -32,     0,   -32,
     -32,     0,     0,     0,   -32,   318,   318,   -32,   -32,     0,
       0,     0,     0,     0,     0,    42,   311,   187,   312,    15,
       0,    16,    17,     0,     0,     0,   313,     0,     0,   314,
     102,     0,   318,   252,   318,   233,    42,     0,   234,   235,
     236,     0,   237,   238,   239,     0,     0,     0,     0,     0,
     318,     0,   318,     0,   318,     0,   318,    95,    97,     0,
       0,     0,     0,   100,     0,   252,     0,   252,     0,     0,
       0,   103,   240,   241,     0,   252,     0,   242,   318,   318,
     318,   318,   112,     0,     2,     3,   284,     4,   271,   272,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,   -30,     0,     0,   319,   319,   273,
     113,   274,    15,     0,    16,    17,     0,     0,     0,   275,
       0,   284,   276,   -28,     0,   172,     0,   -30,   -30,   -30,
     -30,     0,   -30,   -30,   319,     0,   319,   -30,     0,     0,
     -30,   -30,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,   319,     0,   319,     0,   319,   307,   319,     0,
       0,   -70,   -70,   -70,   -73,   -70,   -70,     0,     0,     0,
     342,   -70,   -70,   -70,   -70,   -70,   -70,   321,   321,     0,
     319,   319,   319,   319,   199,     0,     0,   -70,   -70,   -70,
     -70,   -70,  -121,   -70,     0,     0,     0,     0,     0,   307,
       0,     0,     0,     0,   321,   213,   321,     0,     0,     0,
     252,     0,   252,     0,   252,     0,     0,   199,     0,     0,
       0,     0,   321,     0,   321,     0,   321,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   252,   252,   252,   252,   252,     0,     0,
     321,   321,   321,   321,     0,     0,     0,     0,     0,     0,
       0,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,  -134,     0,   307,   307,   307,
     307,   307,   252,     0,     0,     0,     0,     0,     0,     0,
       0,  -134,  -134,  -134,  -134,  -134,  -134,     0,   252,     0,
       0,  -134,  -134,  -134,  -134,  -134,  -134,     0,     0,     0,
       0,   342,   342,   342,   342,   342,   252,  -134,  -134,  -134,
    -134,     0,  -134,  -134,     0,     0,     0,     0,     0,     0,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,     0,     0,     0,     0,     0,
     -31,     0,   -31,   -31,     0,   -31,   -31,   -31,   -31,   -31,
     -31,     0,   -31,   -31,   -31,     0,   -33,     0,   -33,   -33,
       0,   -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,
     -33,     0,     0,     0,     0,     0,     0,   -31,   -31,   -31,
     -31,     0,   -31,   -31,   515,     0,   252,   -31,   252,     0,
     -31,   -31,   284,   -33,   -33,   -33,   -33,     0,   -33,   -33,
       0,     0,     0,   -33,     0,     0,   -33,   -33,     0,     0,
       0,     0,   533,     0,   252,     0,   252,     0,   243,   -50,
     284,   -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,
       0,   -50,   -50,   -50,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,     0,
     243,     0,   243,     0,     0,     0,   -50,   -50,   -50,   -50,
     243,   -50,   -50,     0,     0,     0,   -50,     0,     0,   -50,
     -50,   -29,     0,   -29,   -29,     0,   -29,   -29,   -29,   -29,
     -29,   -29,     0,   -29,   -29,   -29,   252,   307,   -45,   -45,
       0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,
       0,   -45,   -45,   -45,   307,   307,     0,     0,   -29,   -29,
     -29,   -29,     0,   -29,   -29,     0,     0,     0,   -29,     0,
       0,   -29,   -29,     0,     0,     0,   -45,   202,   -45,   -45,
       0,   -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     342,   307,   298,   375,     0,     0,     0,     0,     0,     0,
       0,   342,     0,     0,     0,   333,     0,     0,     0,   -70,
     -70,   -70,   -73,   -70,   -70,   342,     0,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,   -70,   -70,   -70,   -70,     0,
    -121,   -70,     0,     0,     0,   243,     0,   243,     0,   243,
       0,     0,   252,     0,   252,     0,   252,     0,     0,     0,
       0,   252,     0,   252,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   243,   243,
     243,   243,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,     0,   286,     0,     0,   243,     0,   232,   271,   272,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,   298,   298,   298,   298,   298,   243,   322,     0,
       0,   323,   324,   325,     0,   326,   327,   328,     0,   273,
     612,   274,    15,   243,    16,    17,     0,     0,     0,   275,
       0,     0,   276,     0,     0,     0,   333,   333,   333,   333,
     333,   243,     0,     0,     0,   329,   330,     0,     0,   -62,
     331,   -62,     0,     0,     0,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
       0,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -43,   -51,     0,   -51,
     -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,
     -51,   -51,     0,     0,     0,     0,     0,     0,     0,   -43,
     204,   -43,   -43,     0,   -43,   -43,     0,     0,     0,   -43,
       0,   243,   -43,   243,   -51,   -51,   -51,   -51,     0,   -51,
     -51,     0,     0,     0,   -51,     0,     0,   -51,   -51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,   243,     0,   244,   -35,     0,   -35,   -35,     0,   -35,
     -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,   -35,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,     0,   244,     0,   244,     0,     0,
       0,   -35,   -35,   -35,   -35,   244,   -35,   -35,     0,     0,
       0,   -35,     0,     0,   -35,   -35,   -34,     0,   -34,   -34,
       0,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,
     -34,   243,   298,   -40,     0,   -40,   -40,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,     0,   298,
     298,     0,     0,   -34,   -34,   -34,   -34,     0,   -34,   -34,
       0,     0,     0,   -34,     0,     0,   -34,   -34,     0,     0,
     -40,   -40,   -40,   -40,     0,   -40,   -40,     0,     0,     0,
     -40,     0,     0,   -40,   -40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   333,   298,   299,  -134,     0,
       0,     0,     0,  -134,     0,     0,   333,     0,     0,     0,
     334,     0,     0,     0,  -134,  -134,  -134,  -134,  -134,  -134,
     333,     0,     0,     0,  -134,  -134,  -134,  -134,  -134,  -134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   299,
    -134,  -134,  -134,  -134,  -134,  -134,     0,     0,     0,     0,
     244,     0,   244,     0,   244,     0,     0,   243,     0,   243,
       0,   243,     0,     0,     0,     0,   243,     0,   243,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   244,   244,   244,   244,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,     0,   286,     0,     0,
     244,     0,   232,   271,   272,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,   299,   299,   299,
     299,   299,   244,   288,     0,     0,   289,   290,   291,     0,
     292,   293,   294,     0,   273,   614,   274,    15,   244,    16,
      17,     0,     0,     0,   275,     0,     0,   276,     0,     0,
       0,   334,   334,   334,   334,   334,   244,     0,     0,     0,
     295,   296,     0,     0,     0,   297,  -130,     0,     0,     0,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,     0,     0,     0,     0,     0,
     -41,     0,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   -41,   -41,   -41,   -37,     0,   -37,   -37,     0,
     -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,
       0,     0,     0,     0,     0,     0,     0,   -41,   -41,   -41,
     -41,     0,   -41,   -41,     0,     0,   244,   -41,   244,     0,
     -41,   -41,   -37,   -37,   -37,   -37,     0,   -37,   -37,     0,
       0,     0,   -37,     0,     0,   -37,   -37,     0,     0,     0,
       0,     0,     0,     0,   244,     0,   244,     0,   245,   -38,
       0,   -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,   -38,   -38,   -38,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,     0,
     245,     0,   245,     0,     0,     0,   -38,   -38,   -38,   -38,
     245,   -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,
     -38,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,   -11,
     -11,   -11,     0,   -11,   -11,   -11,   244,   299,   -35,   -35,
       0,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -35,   299,   299,     0,     0,   -11,   -11,
     -11,   -11,     0,   -11,   -11,     0,     0,     0,   -11,     0,
       0,   -11,   -11,     0,     0,     0,   -35,   -35,   -35,   -35,
       0,   -35,   -35,     0,     0,     0,   -35,     0,     0,   -35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     334,   299,   300,    92,     0,     0,     0,     0,   253,     0,
       0,   334,     0,     0,     0,   335,     0,     0,     0,   -70,
     -70,   -70,   -73,   -70,   -70,   334,     0,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,   -70,   -70,   -70,   -70,   -70,
    -121,     0,     0,     0,     0,   245,     0,   245,     0,   245,
       0,     0,   244,     0,   244,     0,   244,     0,     0,     0,
       0,   244,     0,   244,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   245,   245,
     245,   245,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,     0,   308,     0,     0,   245,     0,   232,   309,   310,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,   300,   300,   300,   300,   300,   245,   233,     0,
       0,   234,   235,   236,     0,   237,   238,   239,     0,   311,
     625,   312,    15,   245,    16,    17,     0,     0,     0,   313,
       0,     0,   314,     0,     0,     0,   335,   335,   335,   335,
     335,   245,     0,     0,     0,   240,   241,     0,     0,     0,
     242,   -62,     0,     0,     0,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
       0,   -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,   -34,   -34,   -34,   -40,   -40,     0,
     -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,     0,     0,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,     0,   -34,   -34,     0,     0,     0,   -34,
       0,   245,   -34,   245,     0,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   345,   346,   347,   -40,   348,   349,   -40,     0,
       0,     0,   350,   351,   352,   353,   354,   355,     0,   245,
       0,   245,     0,   246,     0,     0,     0,     0,   356,   357,
     358,   359,     0,     0,  -133,  -133,     0,     0,     0,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,     0,   246,     0,   246,     0,     0,
     -41,   -41,     0,   -41,   -41,   246,   -41,   -41,   -41,   -41,
     -41,   -41,   190,   -41,   -41,   -41,     0,   232,     0,     0,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,   245,   300,     0,     0,     0,     0,     0,   -41,   -41,
     -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,   300,
     300,   -41,     0,     0,    16,    17,     0,     0,   -62,    52,
     -37,   -37,     0,   -37,   -37,     0,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,   -37,   -10,     0,   -10,   -10,
       0,   -10,   -10,   -10,   -10,   -10,   -10,     0,   -10,   -10,
     -10,     0,     0,     0,     0,   335,   300,   301,   -37,   -37,
     -37,   -37,     0,   -37,   -37,     0,   335,     0,   -37,     0,
     336,   -37,     0,   -10,   -10,   -10,   -10,     0,   -10,   -10,
     335,     0,     0,   -10,     0,     0,   -10,   -10,     0,     0,
       0,     0,   517,     0,     0,     0,     0,   233,     0,   301,
     234,   235,   236,     0,   237,   238,   239,     0,     0,     0,
     246,     0,   246,     0,   246,     0,     0,   245,     0,   245,
       0,   245,     0,     0,     0,     0,   245,     0,   245,     0,
     245,     0,     0,   518,   240,   241,     0,     0,     0,   242,
       0,     0,   246,   246,   246,   246,   246,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,     0,   308,     0,     0,
     246,     0,   232,   309,   310,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,   301,   301,   301,
     301,   301,   246,   232,     0,     0,     7,     8,     9,     0,
      10,    11,    12,     0,   311,   627,   312,    15,   246,    16,
      17,     0,     0,     0,   313,     0,     0,   314,     0,     0,
       0,   336,   336,   336,   336,   336,   246,     0,     0,     0,
      16,    17,     0,     0,     0,    52,     0,     0,     0,     0,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,     0,     0,     0,     0,     0,
     -49,     0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
     -49,     0,   -49,   -49,   -49,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,   -59,
       0,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
     -49,     0,   -49,   -49,     0,     0,   246,   -49,   246,     0,
     -49,   -49,   -59,   -59,   -59,   -59,     0,   -59,   -59,     0,
       0,     0,   -59,     0,     0,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,   246,     0,   246,     0,   247,   -42,
       0,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -42,   -42,   -42,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,     0,
     247,     0,   247,     0,     0,     0,   -42,   -42,   -42,   -42,
     247,   -42,   -42,     0,     0,     0,   -42,     0,     0,   -42,
     -42,   -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,   -36,   246,   301,   -38,   -38,
       0,   -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,   -38,   -38,   -38,   301,   301,     0,     0,   -36,   -36,
     -36,   -36,     0,   -36,   -36,     0,     0,     0,   -36,     0,
       0,   -36,   -36,     0,     0,     0,   -38,   -38,   -38,   -38,
       0,   -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,   301,   302,    92,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,     0,   337,     0,     0,     0,   -70,
     -70,   -70,   -73,   -70,   -70,   336,     0,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   302,   -70,   -70,   -70,   -70,   -70,
    -121,     0,     0,     0,     0,   247,     0,   247,     0,   247,
       0,     0,   246,     0,   246,     0,   246,     0,     0,     0,
       0,   246,     0,   246,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   247,   247,
     247,   247,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,     0,   286,     0,     0,   247,     0,   232,   271,   272,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,   302,   302,   302,   302,   302,   247,   288,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,   273,
       0,   274,    15,   247,    16,    17,     0,     0,     0,   275,
       0,     0,   276,     0,     0,     0,   337,   337,   337,   337,
     337,   247,     0,     0,     0,   295,   296,     0,     0,     0,
     297,     0,     0,     0,     0,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
       0,   -49,   -49,     0,   -49,   -49,     0,   -49,   -49,   -49,
     -49,   -49,   -49,     0,   -49,   -49,   -49,   -59,   -59,     0,
     -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,
     -59,   -59,   -59,     0,     0,     0,     0,     0,     0,   -49,
     -49,   -49,   -49,     0,   -49,   -49,     0,     0,     0,   -49,
       0,   247,   -49,   247,     0,   -59,   -59,   -59,   -59,     0,
     -59,   -59,   345,   346,   347,   -59,   348,   349,   -59,     0,
       0,     0,   350,   351,   352,   353,   354,   355,     0,   247,
       0,   247,     0,   248,     0,     0,     0,     0,   356,   357,
     358,   359,     0,     0,  -132,  -132,     0,     0,     0,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,     0,   248,     0,   248,     0,     0,
     -42,   -42,     0,   -42,   -42,   248,   -42,   -42,   -42,   -42,
     -42,   -42,   522,   -42,   -42,   -42,     0,   232,     0,     0,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,   247,   302,     0,     0,     0,     0,     0,   -42,   -42,
     -42,   -42,     0,   -42,   -42,     0,     0,     0,   -42,   302,
     302,   -42,     0,     0,    16,    17,     0,     0,   -62,    52,
     -36,   -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,   -36,   -36,   -36,   -12,     0,   -12,   -12,
       0,   -12,   -12,   -12,   -12,   -12,   -12,     0,   -12,   -12,
     -12,     0,     0,     0,     0,   337,   302,   303,   -36,   -36,
     -36,   -36,     0,   -36,   -36,     0,   337,     0,   -36,     0,
     338,   -36,     0,   -12,   -12,   -12,   -12,     0,   -12,   -12,
     337,     0,     0,   -12,     0,     0,   -12,   -12,     0,     0,
       0,     0,   535,     0,     0,     0,     0,   233,     0,   303,
     234,   235,   236,     0,   237,   238,   239,     0,     0,     0,
     248,     0,   248,     0,   248,     0,     0,   247,     0,   247,
       0,   247,     0,     0,     0,     0,   247,     0,   247,     0,
     247,     0,     0,   536,   240,   241,     0,     0,     0,   242,
       0,     0,   248,   248,   248,   248,   248,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,     0,    73,     0,     0,
     248,     0,   232,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,   303,   303,   303,
     303,   303,   248,   322,     0,     0,   323,   324,   325,     0,
     326,   327,   328,     0,    13,     0,    14,    15,   248,    16,
      17,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,   338,   338,   338,   338,   338,   248,     0,     0,     0,
     329,   330,     0,     0,     0,   331,     0,     0,     0,     0,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,     0,     0,     0,     0,     0,
    -128,     0,  -128,  -128,     0,  -128,  -128,  -128,  -128,  -128,
    -128,     0,  -128,  -128,  -128,  -129,     0,  -129,  -129,     0,
    -129,  -129,  -129,  -129,  -129,  -129,     0,  -129,  -129,  -129,
       0,     0,     0,     0,     0,     0,     0,  -128,  -128,  -128,
    -128,     0,  -128,  -128,     0,     0,   248,  -128,   248,     0,
    -128,  -128,  -129,  -129,  -129,  -129,     0,  -129,  -129,     0,
       0,     0,  -129,     0,     0,  -129,  -129,     0,     0,     0,
       0,     0,     0,     0,   248,     0,   248,     0,   249,   -39,
       0,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,   -39,   -39,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,     0,
     249,     0,   249,     0,     0,     0,   -39,   -39,   -39,   -39,
     249,   -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,
     -39,   -14,     0,   -14,   -14,     0,   -14,   -14,   -14,   -14,
     -14,   -14,     0,   -14,   -14,   -14,   248,   303,  -128,  -128,
       0,  -128,  -128,     0,  -128,  -128,  -128,  -128,  -128,  -128,
       0,  -128,  -128,  -128,   303,   303,     0,     0,   -14,   -14,
     -14,   -14,     0,   -14,   -14,     0,     0,     0,   -14,     0,
       0,   -14,   -14,     0,     0,     0,  -128,  -128,  -128,  -128,
       0,  -128,  -128,     0,     0,     0,  -128,     0,     0,  -128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     338,   303,   304,  -134,     0,     0,     0,     0,     0,     0,
       0,   338,     0,     0,     0,   339,     0,     0,     0,  -134,
    -134,  -134,  -134,  -134,  -134,   338,     0,     0,     0,  -134,
    -134,  -134,  -134,  -134,  -134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,  -134,  -134,  -134,  -134,  -134,
    -134,     0,     0,     0,     0,   249,     0,   249,     0,   249,
       0,     0,   248,     0,   248,     0,   248,     0,     0,     0,
       0,   248,     0,   248,     0,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   249,   249,
     249,   249,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,     0,   308,     0,     0,   249,     0,   232,   309,   310,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,   304,   304,   304,   304,   304,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   311,
       0,   312,    15,   249,    16,    17,     0,     0,     0,   313,
       0,     0,   314,     0,     0,     0,   339,   339,   339,   339,
     339,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
       0,  -129,  -129,     0,  -129,  -129,     0,  -129,  -129,  -129,
    -129,  -129,  -129,     0,  -129,  -129,  -129,   -39,   -39,     0,
     -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,
     -39,   -39,   -39,     0,     0,     0,     0,     0,     0,  -129,
    -129,  -129,  -129,     0,  -129,  -129,     0,     0,     0,  -129,
       0,   249,  -129,   249,     0,   -39,   -39,   -39,   -39,     0,
     -39,   -39,     0,     0,     0,   -39,     0,     0,   -39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,   249,     0,   250,   -58,     0,   -58,   -58,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,   -58,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,     0,   250,     0,   250,     0,     0,
       0,   -58,   -58,   -58,   -58,   250,   -58,   -58,     0,     0,
       0,   -58,     0,     0,   -58,   -58,   -26,     0,   -26,   -26,
       0,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   249,   304,   -13,     0,   -13,   -13,     0,   -13,   -13,
     -13,   -13,   -13,   -13,     0,   -13,   -13,   -13,     0,   304,
     304,     0,     0,   -26,   -26,   -26,   -26,     0,   -26,   -26,
       0,     0,     0,   -26,     0,     0,   -26,   -26,     0,     0,
     -13,   -13,   -13,   -13,     0,   -13,   -13,     0,     0,     0,
     -13,     0,     0,   -13,   -13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   339,   304,   305,     0,   540,
       0,     0,     0,     0,   232,     0,   339,     7,     8,     9,
     340,    10,    11,    12,     0,     0,     0,     0,     0,     0,
     339,     0,    51,     0,     0,     0,     0,   232,     0,     0,
       7,     8,     9,     0,    10,    11,    12,     0,     0,   305,
       0,    16,    17,     0,     0,   -62,    52,     0,     0,     0,
     250,     0,   250,     0,   250,     0,     0,   249,     0,   249,
       0,   249,     0,     0,    16,    17,   249,     0,   249,    52,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   250,   250,   250,   250,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,     0,   617,     0,     0,
     250,     0,   232,     0,     0,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,   305,   305,   305,
     305,   305,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    16,
      17,     0,     0,   -62,    52,     0,     0,     0,     0,     0,
       0,   340,   340,   340,   340,   340,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,     0,   -58,   -58,     0,   -58,
     -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,   -58,
     -58,   -58,   -26,   -26,     0,   -26,   -26,     0,   -26,   -26,
     -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,     0,     0,
       0,     0,     0,     0,   -58,   -58,   -58,   -58,     0,   -58,
     -58,     0,     0,     0,   -58,     0,   250,   -58,   250,     0,
     -26,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,     0,
     -26,     0,     0,   -26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,   250,     0,   251,  -127,
       0,  -127,  -127,     0,  -127,  -127,  -127,  -127,  -127,  -127,
       0,  -127,  -127,  -127,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,     0,
     251,     0,   251,     0,     0,     0,  -127,  -127,  -127,  -127,
     251,  -127,  -127,     0,     0,     0,  -127,     0,     0,  -127,
    -127,  -123,     0,  -123,  -123,     0,  -123,  -123,  -123,  -123,
    -123,  -123,     0,  -123,  -123,  -123,   250,   305,  -126,     0,
    -126,  -126,     0,  -126,  -126,  -126,  -126,  -126,  -126,     0,
    -126,  -126,  -126,     0,   305,   305,     0,     0,  -123,  -123,
    -123,  -123,     0,  -123,  -123,     0,     0,     0,  -123,     0,
       0,  -123,  -123,     0,     0,  -126,  -126,  -126,  -126,     0,
    -126,  -126,     0,     0,     0,  -126,     0,     0,  -126,  -126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,   305,   306,     0,   630,     0,     0,     0,     0,   232,
       0,   340,     7,     8,     9,   341,    10,    11,    12,     0,
       0,     0,     0,     0,     0,   340,     0,    55,     0,     0,
       0,     0,   232,     0,     0,     7,     8,     9,     0,    10,
      11,    12,     0,     0,   306,     0,    16,    17,     0,     0,
     -62,    52,     0,     0,     0,   251,     0,   251,     0,   251,
       0,     0,   250,     0,   250,     0,   250,     0,     0,    16,
      17,   250,     0,   250,    52,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   251,   251,   251,
     251,   251,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,     0,    57,     0,     0,   251,     0,   232,     0,     0,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,   306,   306,   306,   306,   306,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    16,    17,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,   341,   341,   341,   341,
     341,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
       0,     0,     0,     0,     0,  -125,     0,  -125,  -125,     0,
    -125,  -125,  -125,  -125,  -125,  -125,     0,  -125,  -125,  -125,
    -124,     0,  -124,  -124,     0,  -124,  -124,  -124,  -124,  -124,
    -124,     0,  -124,  -124,  -124,     0,     0,     0,     0,     0,
       0,     0,  -125,  -125,  -125,  -125,     0,  -125,  -125,     0,
       0,   251,  -125,   251,     0,  -125,  -125,  -124,  -124,  -124,
    -124,     0,  -124,  -124,     0,     0,     0,  -124,     0,     0,
    -124,  -124,     0,     0,     0,     0,     0,     0,     0,   251,
     -45,   251,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,     0,     0,     0,     0,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,     0,     0,     0,   -45,   634,   -45,
     -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,     0,
     -45,   -45,     0,     0,   -43,     0,   -43,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,     0,
       0,   251,   306,  -127,  -127,     0,  -127,  -127,     0,  -127,
    -127,  -127,  -127,  -127,  -127,     0,  -127,  -127,  -127,   306,
     306,   -43,   636,   -43,   -43,     0,   -43,   -43,     0,     0,
       0,   -43,     0,     0,   -43,   -43,     0,     0,     0,     0,
       0,  -127,  -127,  -127,  -127,     0,  -127,  -127,     0,     0,
      63,  -127,     0,     0,  -127,   232,     0,     0,     7,     8,
       9,     0,    10,    11,    12,   341,   306,     0,     0,     0,
       0,  -123,  -123,     0,  -123,  -123,   341,  -123,  -123,  -123,
    -123,  -123,  -123,     0,  -123,  -123,  -123,     0,     0,     0,
     341,     0,    16,    17,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -123,
    -123,  -123,  -123,     0,  -123,  -123,     0,     0,     0,  -123,
       0,     0,  -123,     0,     0,     0,     0,   251,     0,   251,
       0,   251,     0,     0,     0,     0,   251,     0,   251,     0,
     251,  -126,  -126,     0,  -126,  -126,     0,  -126,  -126,  -126,
    -126,  -126,  -126,     0,  -126,  -126,  -126,  -125,  -125,     0,
    -125,  -125,     0,  -125,  -125,  -125,  -125,  -125,  -125,     0,
    -125,  -125,  -125,     0,     0,     0,     0,     0,     0,  -126,
    -126,  -126,  -126,     0,  -126,  -126,     0,     0,     0,  -126,
       0,     0,  -126,     0,     0,  -125,  -125,  -125,  -125,     0,
    -125,  -125,     0,  -124,  -124,  -125,  -124,  -124,  -125,  -124,
    -124,  -124,  -124,  -124,  -124,     0,  -124,  -124,  -124,   -45,
     -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,     0,     0,     0,     0,     0,
       0,  -124,  -124,  -124,  -124,     0,  -124,  -124,     0,     0,
       0,  -124,     0,     0,  -124,     0,     0,   -45,   643,   -45,
     -45,     0,   -45,   -45,     0,   -43,   -43,   -45,   -43,   -43,
     -45,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,
     -43,   -48,     0,   -48,   -48,     0,   -48,   -48,   -48,   -48,
     -48,   -48,     0,   -48,   -48,   -48,     0,     0,     0,     0,
       0,     0,     0,   -43,   645,   -43,   -43,     0,   -43,   -43,
       0,     0,     0,   -43,     0,     0,   -43,     0,   -48,   -48,
     -48,   -48,     0,   -48,   -48,     0,     0,     0,   -48,     0,
       0,   -48,   -48,   -47,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -48,   -48,
       0,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,
       0,   -48,   -48,   -48,     0,     0,     0,     0,     0,     0,
     -47,   -47,   -47,   -47,     0,   -47,   -47,     0,     0,     0,
     -47,     0,     0,   -47,   -47,     0,   -48,   -48,   -48,   -48,
       0,   -48,   -48,     0,   -47,   -47,   -48,   -47,   -47,   -48,
     -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,
     -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,     0,   -46,   -46,   -46,     0,     0,     0,     0,     0,
       0,     0,   -47,   -47,   -47,   -47,     0,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,     0,   -46,   -46,   -46,
     -46,     0,   -46,   -46,     0,     0,     0,   -46,     0,     0,
     -46,   -46,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,   -44,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,
     -56,   -56,     0,     0,     0,     0,     0,     0,     0,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,
       0,     0,   -44,   -44,   -56,   -56,   -56,   -56,     0,   -56,
     -56,     0,     0,     0,   -56,     0,     0,   -56,   -56,   -57,
       0,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,   -57,   -57,   -57,   -46,   -46,     0,   -46,   -46,     0,
     -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,
       0,     0,     0,     0,     0,     0,   -57,   -57,   -57,   -57,
       0,   -57,   -57,     0,     0,     0,   -57,     0,     0,   -57,
     -57,     0,   -46,   -46,   -46,   -46,     0,   -46,   -46,     0,
     -44,   -44,   -46,   -44,   -44,   -46,   -44,   -44,   -44,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -56,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,
     -56,   -56,     0,     0,     0,     0,     0,     0,   -44,   -44,
     -44,   -44,     0,   -44,   -44,     0,     0,     0,   -44,     0,
       0,   -44,     0,     0,   -56,   -56,   -56,   -56,     0,   -56,
     -56,     0,   -57,   -57,   -56,   -57,   -57,   -56,   -57,   -57,
     -57,   -57,   -57,   -57,     0,   -57,   -57,   -57,   -53,     0,
     -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,     0,
     -53,   -53,   -53,     0,     0,     0,     0,     0,     0,     0,
     -57,   -57,   -57,   -57,     0,   -57,   -57,     0,     0,     0,
     -57,     0,     0,   -57,     0,   -53,   -53,   -53,   -53,     0,
     -53,   -53,     0,     0,     0,   -53,     0,     0,   -53,   -53,
     -54,     0,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,
     -54,     0,   -54,   -54,   -54,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,     0,   -54,   -54,   -54,
     -54,     0,   -54,   -54,     0,     0,     0,   -54,     0,     0,
     -54,   -54,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,
       0,     0,   -55,     0,     0,   -55,   -55,   -52,     0,   -52,
     -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,
     -52,   -52,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,
     -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,     0,     0,
       0,     0,     0,     0,   -52,   -52,   -52,   -52,     0,   -52,
     -52,     0,     0,     0,   -52,     0,     0,   -52,   -52,     0,
     -53,   -53,   -53,   -53,     0,   -53,   -53,     0,   -54,   -54,
     -53,   -54,   -54,   -53,   -54,   -54,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -54,   -55,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,   -54,
       0,   -54,   -54,     0,     0,     0,   -54,     0,     0,   -54,
       0,     0,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,
     -52,   -52,   -55,   -52,   -52,   -55,   -52,   -52,   -52,   -52,
     -52,   -52,     0,   -52,   -52,   -52,    -4,     1,     0,     2,
       3,     0,     4,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,     0,   -52,   -52,
     -52,   -52,     0,   -52,   -52,     0,     0,     0,   -52,     0,
       0,   -52,     0,     0,    13,     0,    14,    15,     0,    16,
      17,     0,    -2,    73,    18,     2,     3,    19,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,    -6,    -6,
       0,    -6,    -6,     0,    -6,    -6,    -6,    -6,    -6,    -6,
       0,    -6,    -6,    -6,     0,     0,     0,     0,     0,     0,
      13,     0,    14,    15,     0,    16,    17,     0,     0,     0,
      18,     0,     0,    19,     0,     0,    -6,     0,    -6,    -6,
       0,    -6,    -6,     0,    -7,    -7,    -6,    -7,    -7,    -6,
      -7,    -7,    -7,    -7,    -7,    -7,     0,    -7,    -7,    -7,
      -8,    -8,     0,    -8,    -8,     0,    -8,    -8,    -8,    -8,
      -8,    -8,     0,    -8,    -8,    -8,     0,     0,     0,     0,
       0,     0,    -7,     0,    -7,    -7,     0,    -7,    -7,     0,
       0,     0,    -7,     0,     0,    -7,     0,     0,    -8,     0,
      -8,    -8,     0,    -8,    -8,     0,   -35,   -35,    -8,   -35,
     -35,    -8,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,
     -35,   -35,    -9,    -9,     0,    -9,    -9,     0,    -9,    -9,
      -9,    -9,    -9,    -9,     0,    -9,    -9,    -9,     0,     0,
       0,     0,     0,     0,   -35,     0,   -35,   -35,     0,   -35,
     -35,     0,     0,     0,   -35,     0,     0,   -35,     0,     0,
      -9,     0,    -9,    -9,     0,    -9,    -9,     0,   -34,   -34,
      -9,   -34,   -34,    -9,   -34,   -34,   -34,   -34,   -34,   -34,
       0,   -34,   -34,   -34,   -40,   -40,     0,   -40,   -40,     0,
     -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,
       0,     0,     0,     0,     0,     0,   -34,     0,   -34,   -34,
       0,   -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,
       0,     0,   -40,     0,   -40,   -40,     0,   -40,   -40,     0,
     -41,   -41,   -40,   -41,   -41,   -40,   -41,   -41,   -41,   -41,
     -41,   -41,     0,   -41,   -41,   -41,   -37,   -37,     0,   -37,
     -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,
     -37,   -37,     0,     0,     0,     0,     0,     0,   -41,     0,
     -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,     0,
       0,   -41,     0,     0,   -37,     0,   -37,   -37,     0,   -37,
     -37,     0,   -38,   -38,   -37,   -38,   -38,   -37,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,   -49,   -49,
       0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,     0,     0,     0,     0,     0,     0,
     -38,     0,   -38,   -38,     0,   -38,   -38,     0,     0,     0,
     -38,     0,     0,   -38,     0,     0,   -49,     0,   -49,   -49,
       0,   -49,   -49,     0,   -59,   -59,   -49,   -59,   -59,   -49,
     -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,   -59,
      -5,    -5,     0,    -5,    -5,     0,    -5,    -5,    -5,    -5,
      -5,    -5,     0,    -5,    -5,    -5,     0,     0,     0,     0,
       0,     0,   -59,     0,   -59,   -59,     0,   -59,   -59,     0,
       0,     0,   -59,     0,     0,   -59,     0,     0,    -5,     0,
      -5,    -5,     0,    -5,    -5,     0,   -42,   -42,    -5,   -42,
     -42,    -5,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,
     -42,   -42,   -36,   -36,     0,   -36,   -36,     0,   -36,   -36,
     -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,     0,     0,
       0,     0,     0,     0,   -42,     0,   -42,   -42,     0,   -42,
     -42,     0,     0,     0,   -42,     0,     0,   -42,     0,     0,
     -36,     0,   -36,   -36,     0,   -36,   -36,     0,   -11,   -11,
     -36,   -11,   -11,   -36,   -11,   -11,   -11,   -11,   -11,   -11,
       0,   -11,   -11,   -11,  -128,  -128,     0,  -128,  -128,     0,
    -128,  -128,  -128,  -128,  -128,  -128,     0,  -128,  -128,  -128,
       0,     0,     0,     0,     0,     0,   -11,     0,   -11,   -11,
       0,   -11,   -11,     0,     0,     0,   -11,     0,     0,   -11,
       0,     0,  -128,     0,  -128,  -128,     0,  -128,  -128,     0,
    -129,  -129,  -128,  -129,  -129,  -128,  -129,  -129,  -129,  -129,
    -129,  -129,     0,  -129,  -129,  -129,   -39,   -39,     0,   -39,
     -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,
     -39,   -39,     0,     0,     0,     0,     0,     0,  -129,     0,
    -129,  -129,     0,  -129,  -129,     0,     0,     0,  -129,     0,
       0,  -129,     0,     0,   -39,     0,   -39,   -39,     0,   -39,
     -39,     0,   -14,   -14,   -39,   -14,   -14,   -39,   -14,   -14,
     -14,   -14,   -14,   -14,     0,   -14,   -14,   -14,   -10,   -10,
       0,   -10,   -10,     0,   -10,   -10,   -10,   -10,   -10,   -10,
       0,   -10,   -10,   -10,     0,     0,     0,     0,     0,     0,
     -14,     0,   -14,   -14,     0,   -14,   -14,     0,     0,     0,
     -14,     0,     0,   -14,     0,     0,   -10,     0,   -10,   -10,
       0,   -10,   -10,     0,   -58,   -58,   -10,   -58,   -58,   -10,
     -58,   -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,   -58,
     -26,   -26,     0,   -26,   -26,     0,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,     0,
       0,     0,   -58,     0,   -58,   -58,     0,   -58,   -58,     0,
       0,     0,   -58,     0,     0,   -58,     0,     0,   -26,     0,
     -26,   -26,     0,   -26,   -26,     0,   -13,   -13,   -26,   -13,
     -13,   -26,   -13,   -13,   -13,   -13,   -13,   -13,     0,   -13,
     -13,   -13,   -12,   -12,     0,   -12,   -12,     0,   -12,   -12,
     -12,   -12,   -12,   -12,     0,   -12,   -12,   -12,     0,     0,
       0,     0,     0,     0,   -13,     0,   -13,   -13,     0,   -13,
     -13,     0,     0,     0,   -13,     0,     0,   -13,     0,     0,
     -12,     0,   -12,   -12,     0,   -12,   -12,     0,  -127,  -127,
     -12,  -127,  -127,   -12,  -127,  -127,  -127,  -127,  -127,  -127,
       0,  -127,  -127,  -127,  -123,  -123,     0,  -123,  -123,     0,
    -123,  -123,  -123,  -123,  -123,  -123,     0,  -123,  -123,  -123,
       0,     0,     0,     0,     0,     0,  -127,     0,  -127,  -127,
       0,  -127,  -127,     0,     0,     0,  -127,     0,     0,  -127,
       0,     0,  -123,     0,  -123,  -123,     0,  -123,  -123,     0,
    -126,  -126,  -123,  -126,  -126,  -123,  -126,  -126,  -126,  -126,
    -126,  -126,     0,  -126,  -126,  -126,  -125,  -125,     0,  -125,
    -125,     0,  -125,  -125,  -125,  -125,  -125,  -125,     0,  -125,
    -125,  -125,     0,     0,     0,     0,     0,     0,  -126,     0,
    -126,  -126,     0,  -126,  -126,     0,     0,     0,  -126,     0,
       0,  -126,     0,     0,  -125,     0,  -125,  -125,     0,  -125,
    -125,     0,  -124,  -124,  -125,  -124,  -124,  -125,  -124,  -124,
    -124,  -124,  -124,  -124,     0,  -124,  -124,  -124,   -48,   -48,
       0,   -48,   -48,     0,   -48,   -48,   -48,   -48,   -48,   -48,
       0,   -48,   -48,   -48,     0,     0,     0,     0,     0,     0,
    -124,     0,  -124,  -124,     0,  -124,  -124,     0,     0,     0,
    -124,     0,     0,  -124,     0,     0,   -48,     0,   -48,   -48,
       0,   -48,   -48,     0,   -47,   -47,   -48,   -47,   -47,   -48,
     -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,
     -46,   -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,
     -46,   -46,     0,   -46,   -46,   -46,     0,     0,     0,     0,
       0,     0,   -47,     0,   -47,   -47,     0,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,     0,     0,   -46,     0,
     -46,   -46,     0,   -46,   -46,     0,   -44,   -44,   -46,   -44,
     -44,   -46,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -56,   -56,     0,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,     0,     0,
       0,     0,     0,     0,   -44,     0,   -44,   -44,     0,   -44,
     -44,     0,     0,     0,   -44,     0,     0,   -44,     0,     0,
     -56,     0,   -56,   -56,     0,   -56,   -56,     0,   -57,   -57,
     -56,   -57,   -57,   -56,   -57,   -57,   -57,   -57,   -57,   -57,
       0,   -57,   -57,   -57,   -16,   -16,     0,   -16,   -16,     0,
     -16,   -16,   -16,   -16,   -16,   -16,     0,   -16,   -16,   -16,
       0,     0,     0,     0,     0,     0,   -57,     0,   -57,   -57,
       0,   -57,   -57,     0,     0,     0,   -57,     0,     0,   -57,
       0,     0,   -16,     0,   -16,   -16,     0,   -16,   -16,     0,
     -53,   -53,   -16,   -53,   -53,   -16,   -53,   -53,   -53,   -53,
     -53,   -53,     0,   -53,   -53,   -53,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,
     -54,   -54,     0,     0,     0,     0,     0,     0,   -53,     0,
     -53,   -53,     0,   -53,   -53,     0,     0,     0,   -53,     0,
       0,   -53,     0,     0,   -54,     0,   -54,   -54,     0,   -54,
     -54,     0,   -55,   -55,   -54,   -55,   -55,   -54,   -55,   -55,
     -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -52,   -52,
       0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   -52,     0,     0,     0,     0,     0,     0,
     -55,     0,   -55,   -55,     0,   -55,   -55,     0,     0,     0,
     -55,     0,     0,   -55,     0,     0,   -52,     0,   -52,   -52,
       0,   -52,   -52,    65,     0,     0,   -52,     0,   232,   -52,
       0,     7,     8,     9,    67,    10,    11,    12,     0,   232,
       0,     0,     7,     8,     9,    69,    10,    11,    12,     0,
     233,     0,     0,   234,   235,   236,     0,   237,   238,   239,
       0,     0,     0,     0,     0,    16,    17,     0,     0,     0,
      52,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,    52,     0,     0,     0,   105,     0,   240,   241,     0,
     233,     0,   242,   234,   235,   236,   121,   237,   238,   239,
       0,   232,     0,     0,     7,     8,     9,   123,    10,    11,
      12,     0,   232,     0,     0,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,   240,   241,     0,
       0,     0,   242,     0,     0,     0,     0,     0,    16,    17,
       0,     0,     0,    52,     0,     0,     0,   125,     0,    16,
      17,     0,   232,     0,    52,     7,     8,     9,   127,    10,
      11,    12,     0,   232,     0,     0,     7,     8,     9,   129,
      10,    11,    12,     0,   232,     0,     0,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,    52,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,    52,     0,     0,     0,   131,
       0,    16,    17,     0,   232,     0,    52,     7,     8,     9,
     133,    10,    11,    12,     0,   232,     0,     0,     7,     8,
       9,   135,    10,    11,    12,     0,   232,     0,     0,     7,
       8,     9,     0,    10,    11,    12,     0,     0,     0,     0,
       0,    16,    17,     0,     0,     0,    52,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,    52,     0,     0,
       0,   137,     0,    16,    17,     0,   232,     0,    52,     7,
       8,     9,   139,    10,    11,    12,     0,   232,     0,     0,
       7,     8,     9,   141,    10,    11,    12,     0,   232,     0,
       0,     7,     8,     9,     0,    10,    11,    12,     0,     0,
       0,     0,     0,    16,    17,     0,     0,     0,    52,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     0,    52,
       0,     0,     0,   143,     0,    16,    17,     0,   232,     0,
      52,     7,     8,     9,   145,    10,    11,    12,     0,   232,
       0,     0,     7,     8,     9,   147,    10,    11,    12,     0,
     232,     0,     0,     7,     8,     9,     0,    10,    11,    12,
       0,     0,     0,     0,     0,    16,    17,     0,     0,     0,
      52,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,    52,     0,     0,     0,   149,     0,    16,    17,     0,
     232,     0,    52,     7,     8,     9,   364,    10,    11,    12,
       0,   233,     0,     0,   234,   235,   236,   366,   237,   238,
     239,     0,   233,     0,     0,   234,   235,   236,     0,   237,
     238,   239,     0,     0,     0,     0,     0,    16,    17,     0,
       0,     0,    52,     0,     0,     0,     0,     0,   240,   241,
       0,     0,     0,   242,     0,     0,     0,   368,     0,   240,
     241,     0,   233,     0,   242,   234,   235,   236,   370,   237,
     238,   239,     0,   233,     0,     0,   234,   235,   236,   372,
     237,   238,   239,     0,   233,     0,     0,   234,   235,   236,
       0,   237,   238,   239,     0,     0,     0,     0,     0,   240,
     241,     0,     0,     0,   242,     0,     0,     0,     0,     0,
     240,   241,     0,     0,     0,   242,     0,     0,     0,   378,
       0,   240,   241,     0,   233,     0,   242,   234,   235,   236,
     380,   237,   238,   239,     0,   233,     0,     0,   234,   235,
     236,   382,   237,   238,   239,     0,   233,     0,     0,   234,
     235,   236,     0,   237,   238,   239,     0,     0,     0,     0,
       0,   240,   241,     0,     0,     0,   242,     0,     0,     0,
       0,     0,   240,   241,     0,     0,     0,   242,     0,     0,
       0,   384,     0,   240,   241,     0,   233,     0,   242,   234,
     235,   236,   386,   237,   238,   239,     0,   233,     0,     0,
     234,   235,   236,   388,   237,   238,   239,     0,   233,     0,
       0,   234,   235,   236,     0,   237,   238,   239,     0,     0,
       0,     0,     0,   240,   241,     0,     0,     0,   242,     0,
       0,     0,     0,     0,   240,   241,     0,     0,     0,   242,
       0,     0,     0,   390,     0,   240,   241,     0,   233,     0,
     242,   234,   235,   236,   392,   237,   238,   239,     0,   233,
       0,     0,   234,   235,   236,   394,   237,   238,   239,     0,
     233,     0,     0,   234,   235,   236,     0,   237,   238,   239,
       0,     0,     0,     0,     0,   240,   241,     0,     0,     0,
     242,     0,     0,     0,     0,     0,   240,   241,     0,     0,
       0,   242,     0,     0,     0,   396,     0,   240,   241,     0,
     233,     0,   242,   234,   235,   236,   398,   237,   238,   239,
       0,   233,     0,     0,   234,   235,   236,   400,   237,   238,
     239,     0,   233,     0,     0,   234,   235,   236,     0,   237,
     238,   239,     0,     0,     0,     0,     0,   240,   241,     0,
       0,     0,   242,     0,     0,     0,     0,     0,   240,   241,
       0,     0,     0,   242,     0,     0,     0,   402,     0,   240,
     241,     0,   233,     0,   242,   234,   235,   236,   404,   237,
     238,   239,     0,   233,     0,     0,   234,   235,   236,   406,
     237,   238,   239,     0,   233,     0,     0,   234,   235,   236,
       0,   237,   238,   239,     0,     0,     0,     0,     0,   240,
     241,     0,     0,     0,   242,     0,     0,     0,     0,     0,
     240,   241,     0,     0,     0,   242,     0,     0,     0,   416,
       0,   240,   241,     0,   233,     0,   242,   234,   235,   236,
     421,   237,   238,   239,     0,   288,     0,     0,   289,   290,
     291,   423,   292,   293,   294,     0,   288,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,     0,
       0,   240,   241,     0,     0,     0,   242,     0,     0,     0,
       0,     0,   295,   296,     0,     0,     0,   297,     0,     0,
       0,   425,     0,   295,   296,     0,   288,     0,   297,   289,
     290,   291,   427,   292,   293,   294,     0,   288,     0,     0,
     289,   290,   291,   429,   292,   293,   294,     0,   288,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,     0,     0,   295,   296,     0,     0,     0,   297,     0,
       0,     0,     0,     0,   295,   296,     0,     0,     0,   297,
       0,     0,     0,   444,     0,   295,   296,     0,   233,     0,
     297,   234,   235,   236,   448,   237,   238,   239,     0,   322,
       0,     0,   323,   324,   325,   450,   326,   327,   328,     0,
     322,     0,     0,   323,   324,   325,     0,   326,   327,   328,
       0,     0,     0,     0,     0,   240,   241,     0,     0,     0,
     242,     0,     0,     0,     0,     0,   329,   330,     0,     0,
       0,   331,     0,     0,     0,   452,     0,   329,   330,     0,
     322,     0,   331,   323,   324,   325,   454,   326,   327,   328,
       0,   322,     0,     0,   323,   324,   325,   456,   326,   327,
     328,     0,   322,     0,     0,   323,   324,   325,     0,   326,
     327,   328,     0,     0,     0,     0,     0,   329,   330,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   329,   330,
       0,     0,     0,   331,     0,     0,     0,   478,     0,   329,
     330,     0,   288,     0,   331,   289,   290,   291,   480,   292,
     293,   294,     0,   288,     0,     0,   289,   290,   291,   482,
     292,   293,   294,     0,   288,     0,     0,   289,   290,   291,
       0,   292,   293,   294,     0,     0,     0,     0,     0,   295,
     296,     0,     0,     0,   297,     0,     0,     0,     0,     0,
     295,   296,     0,     0,     0,   297,     0,     0,     0,   484,
       0,   295,   296,     0,   288,     0,   297,   289,   290,   291,
     486,   292,   293,   294,     0,   288,     0,     0,   289,   290,
     291,   488,   292,   293,   294,     0,   288,     0,     0,   289,
     290,   291,     0,   292,   293,   294,     0,     0,     0,     0,
       0,   295,   296,     0,     0,     0,   297,     0,     0,     0,
       0,     0,   295,   296,     0,     0,     0,   297,     0,     0,
       0,   490,     0,   295,   296,     0,   288,     0,   297,   289,
     290,   291,   492,   292,   293,   294,     0,   288,     0,     0,
     289,   290,   291,   494,   292,   293,   294,     0,   288,     0,
       0,   289,   290,   291,     0,   292,   293,   294,     0,     0,
       0,     0,     0,   295,   296,     0,     0,     0,   297,     0,
       0,     0,     0,     0,   295,   296,     0,     0,     0,   297,
       0,     0,     0,   496,     0,   295,   296,     0,   288,     0,
     297,   289,   290,   291,   498,   292,   293,   294,     0,   288,
       0,     0,   289,   290,   291,   500,   292,   293,   294,     0,
     288,     0,     0,   289,   290,   291,     0,   292,   293,   294,
       0,     0,     0,     0,     0,   295,   296,     0,     0,     0,
     297,     0,     0,     0,     0,     0,   295,   296,     0,     0,
       0,   297,     0,     0,     0,   502,     0,   295,   296,     0,
     288,     0,   297,   289,   290,   291,   504,   292,   293,   294,
       0,   288,     0,     0,   289,   290,   291,   506,   292,   293,
     294,     0,   288,     0,     0,   289,   290,   291,     0,   292,
     293,   294,     0,     0,     0,     0,     0,   295,   296,     0,
       0,     0,   297,     0,     0,     0,     0,     0,   295,   296,
       0,     0,     0,   297,     0,     0,     0,   520,     0,   295,
     296,     0,   233,     0,   297,   234,   235,   236,   538,   237,
     238,   239,     0,   233,     0,     0,   234,   235,   236,   545,
     237,   238,   239,     0,   322,     0,     0,   323,   324,   325,
       0,   326,   327,   328,     0,     0,     0,     0,     0,   240,
     241,     0,     0,     0,   242,     0,     0,     0,     0,     0,
     240,   241,     0,     0,     0,   242,     0,     0,     0,   547,
       0,   329,   330,     0,   322,     0,   331,   323,   324,   325,
     549,   326,   327,   328,     0,   322,     0,     0,   323,   324,
     325,   551,   326,   327,   328,     0,   322,     0,     0,   323,
     324,   325,     0,   326,   327,   328,     0,     0,     0,     0,
       0,   329,   330,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   329,   330,     0,     0,     0,   331,     0,     0,
       0,   553,     0,   329,   330,     0,   322,     0,   331,   323,
     324,   325,   555,   326,   327,   328,     0,   322,     0,     0,
     323,   324,   325,   557,   326,   327,   328,     0,   322,     0,
       0,   323,   324,   325,     0,   326,   327,   328,     0,     0,
       0,     0,     0,   329,   330,     0,     0,     0,   331,     0,
       0,     0,     0,     0,   329,   330,     0,     0,     0,   331,
       0,     0,     0,   559,     0,   329,   330,     0,   322,     0,
     331,   323,   324,   325,   561,   326,   327,   328,     0,   322,
       0,     0,   323,   324,   325,   563,   326,   327,   328,     0,
     322,     0,     0,   323,   324,   325,     0,   326,   327,   328,
       0,     0,     0,     0,     0,   329,   330,     0,     0,     0,
     331,     0,     0,     0,     0,     0,   329,   330,     0,     0,
       0,   331,     0,     0,     0,   565,     0,   329,   330,     0,
     322,     0,   331,   323,   324,   325,   567,   326,   327,   328,
       0,   322,     0,     0,   323,   324,   325,   569,   326,   327,
     328,     0,   322,     0,     0,   323,   324,   325,     0,   326,
     327,   328,     0,     0,     0,     0,     0,   329,   330,     0,
       0,     0,   331,     0,     0,     0,     0,     0,   329,   330,
       0,     0,     0,   331,     0,     0,     0,   571,     0,   329,
     330,     0,   322,     0,   331,   323,   324,   325,   573,   326,
     327,   328,     0,   322,     0,     0,   323,   324,   325,     0,
     326,   327,   328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   329,
     330,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     329,   330,  -120,  -120,  -120,   331,  -120,  -120,     0,     0,
       0,     0,  -120,  -120,  -120,  -120,  -120,  -120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -120,  -120,
    -120,  -120,     0,     0,  -120,  -120,  -119,  -119,  -119,     0,
    -119,  -119,     0,     0,     0,     0,  -119,  -119,  -119,  -119,
    -119,  -119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -119,  -119,  -119,  -119,     0,     0,  -119,  -119,
    -118,  -118,  -118,     0,  -118,  -118,     0,     0,     0,     0,
    -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -118,  -118,  -118,  -118,
       0,     0,  -118,  -118,   -64,   -64,   -64,     0,   -64,   -64,
       0,     0,     0,     0,   -64,   -64,   -64,   -64,   -64,   -64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -64,   -64,   -64,   -64,     0,     0,   -64,   -64,   -65,   -65,
     -65,     0,   -65,   -65,     0,     0,     0,     0,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,     0,     0,
     -65,   -65,   -66,   -66,   -66,     0,   -66,   -66,     0,     0,
       0,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -66,   -66,
     -66,   -66,     0,     0,   -66,   -66,   -67,   -67,   -67,     0,
     -67,   -67,     0,     0,     0,     0,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,   -67,     0,     0,   -67,   -67,
     -68,   -68,   -68,     0,   -68,   -68,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
       0,     0,   -68,   -68,  -115,  -115,  -115,     0,  -115,  -115,
       0,     0,     0,     0,  -115,  -115,  -115,  -115,  -115,  -115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -115,  -115,  -115,  -115,     0,     0,  -115,  -115,  -116,  -116,
    -116,     0,  -116,  -116,     0,     0,     0,     0,  -116,  -116,
    -116,  -116,  -116,  -116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -116,  -116,  -116,  -116,     0,     0,
    -116,  -116,  -117,  -117,  -117,     0,  -117,  -117,     0,     0,
       0,     0,  -117,  -117,  -117,  -117,  -117,  -117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -117,  -117,
    -117,  -117,     0,     0,  -117,  -117,   -69,   -69,   -69,     0,
     -69,   -69,     0,     0,     0,     0,   -69,   -69,   -69,   -69,
     -69,   -69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,     0,     0,   -69,   -69,
    -110,  -110,  -110,     0,  -110,  -110,     0,     0,     0,     0,
    -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -110,  -110,  -110,  -110,
       0,     0,  -110,  -110,  -105,  -105,  -105,     0,  -105,  -105,
       0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,  -105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -105,  -105,  -105,  -105,     0,     0,  -105,  -105,  -111,  -111,
    -111,     0,  -111,  -111,     0,     0,     0,     0,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -111,  -111,  -111,  -111,     0,     0,
    -111,  -111,  -106,  -106,  -106,     0,  -106,  -106,     0,     0,
       0,     0,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -106,  -106,
    -106,  -106,     0,     0,  -106,  -106,  -112,  -112,  -112,     0,
    -112,  -112,     0,     0,     0,     0,  -112,  -112,  -112,  -112,
    -112,  -112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -112,  -112,  -112,  -112,     0,     0,  -112,  -112,
    -107,  -107,  -107,     0,  -107,  -107,     0,     0,     0,     0,
    -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -107,  -107,  -107,  -107,
       0,     0,  -107,  -107,  -113,  -113,  -113,     0,  -113,  -113,
       0,     0,     0,     0,  -113,  -113,  -113,  -113,  -113,  -113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -113,  -113,  -113,  -113,     0,     0,  -113,  -113,  -108,  -108,
    -108,     0,  -108,  -108,     0,     0,     0,     0,  -108,  -108,
    -108,  -108,  -108,  -108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -108,  -108,  -108,  -108,     0,     0,
    -108,  -108,  -114,  -114,  -114,     0,  -114,  -114,     0,     0,
       0,     0,  -114,  -114,  -114,  -114,  -114,  -114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -114,  -114,
    -114,  -114,     0,     0,  -114,  -114,  -109,  -109,  -109,     0,
    -109,  -109,     0,     0,     0,     0,  -109,  -109,  -109,  -109,
    -109,  -109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -109,  -109,  -109,  -109,     0,     0,  -109,  -109,
     -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,     0,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,
       0,     0,   -72,   -72,  -102,  -102,  -102,     0,  -102,  -102,
       0,     0,     0,     0,  -102,  -102,  -102,  -102,  -102,  -102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -102,  -102,  -102,  -102,     0,     0,  -102,  -102,   345,   346,
     347,     0,   -99,   -99,     0,     0,     0,     0,   -99,   -99,
     -99,   -99,   -99,   -99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   356,   357,   358,   359,     0,     0,
     -99,   -99,  -103,  -103,  -103,     0,  -103,  -103,     0,     0,
       0,     0,  -103,  -103,  -103,  -103,  -103,  -103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -103,  -103,
    -103,  -103,     0,     0,  -103,  -103,  -100,   346,   347,     0,
    -100,  -100,     0,     0,     0,     0,  -100,  -100,  -100,  -100,
    -100,  -100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,   357,   358,   359,     0,     0,  -100,  -100,
    -104,  -104,  -104,     0,  -104,  -104,     0,     0,     0,     0,
    -104,  -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -104,  -104,  -104,  -104,
       0,     0,  -104,  -104,  -101,  -101,   347,     0,  -101,  -101,
       0,     0,     0,     0,  -101,  -101,  -101,  -101,  -101,  -101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,   357,   358,   359,     0,     0,  -101,  -101,   -87,   -87,
     -87,     0,   -87,   -87,     0,     0,     0,     0,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -87,   -87,   -87,   -87,     0,     0,
     -87,   -87,   345,   346,   347,     0,   -75,   349,     0,     0,
       0,     0,   350,   351,   352,   353,   354,   355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,   357,
     358,   359,     0,     0,   -75,   -75,   -88,   -88,   -88,     0,
     -88,   -88,     0,     0,     0,     0,   -88,   -88,   -88,   -88,
     -88,   -88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -88,   -88,   -88,   -88,     0,     0,   -88,   -88,
     345,   346,   347,     0,   -76,   -76,     0,     0,     0,     0,
     350,   351,   352,   353,   354,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,   357,   358,   359,
       0,     0,   -76,   -76,   -89,   -89,   -89,     0,   -89,   -89,
       0,     0,     0,     0,   -89,   -89,   -89,   -89,   -89,   -89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -89,   -89,   -89,   -89,     0,     0,   -89,   -89,   345,   346,
     347,     0,   -77,   -77,     0,     0,     0,     0,   -77,   -77,
     352,   353,   354,   355,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   356,   357,   358,   359,     0,     0,
     -77,   -77,   -90,   -90,   -90,     0,   -90,   -90,     0,     0,
       0,     0,   -90,   -90,   -90,   -90,   -90,   -90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -90,   -90,
     -90,   -90,     0,     0,   -90,   -90,   345,   346,   347,     0,
     -78,   -78,     0,     0,     0,     0,   -78,   -78,   352,   353,
     354,   355,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,   357,   358,   359,     0,     0,   -78,   -78,
     -91,   -91,   -91,     0,   -91,   -91,     0,     0,     0,     0,
     -91,   -91,   -91,   -91,   -91,   -91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -91,   -91,   -91,   -91,
       0,     0,   -91,   -91,   345,   346,   347,     0,   -79,   -79,
       0,     0,     0,     0,   -79,   -79,   -79,   -79,   -79,   -79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,   357,   358,   359,     0,     0,   -79,   -79,   -92,   -92,
     -92,     0,   -92,   -92,     0,     0,     0,     0,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -92,   -92,   -92,   -92,     0,     0,
     -92,   -92,   345,   346,   347,     0,   -80,   -80,     0,     0,
       0,     0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,   357,
     358,   359,     0,     0,   -80,   -80,   -93,   -93,   -93,     0,
     -93,   -93,     0,     0,     0,     0,   -93,   -93,   -93,   -93,
     -93,   -93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -93,   -93,   -93,   -93,     0,     0,   -93,   -93,
     345,   346,   347,     0,   -81,   -81,     0,     0,     0,     0,
     -81,   -81,   -81,   -81,   -81,   -81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,   357,   358,   359,
       0,     0,   -81,   -81,   -94,   -94,   -94,     0,   -94,   -94,
       0,     0,     0,     0,   -94,   -94,   -94,   -94,   -94,   -94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -94,   -94,   -94,   -94,     0,     0,   -94,   -94,   345,   346,
     347,     0,   -82,   -82,     0,     0,     0,     0,   -82,   -82,
     -82,   -82,   -82,   -82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   356,   357,   358,   359,     0,     0,
     -82,   -82,   -95,   -95,   -95,     0,   -95,   -95,     0,     0,
       0,     0,   -95,   -95,   -95,   -95,   -95,   -95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -95,   -95,
     -95,   -95,     0,     0,   -95,   -95,   -83,   -83,   -83,     0,
     -83,   -83,     0,     0,     0,     0,   -83,   -83,   -83,   -83,
     -83,   -83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -83,   -83,   358,   359,     0,     0,   -83,   -83,
     -96,   -96,   -96,     0,   -96,   -96,     0,     0,     0,     0,
     -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -96,   -96,   -96,   -96,
       0,     0,   -96,   -96,   -84,   -84,   -84,     0,   -84,   -84,
       0,     0,     0,     0,   -84,   -84,   -84,   -84,   -84,   -84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -84,   -84,   358,   359,     0,     0,   -84,   -84,   -97,   -97,
     -97,     0,   -97,   -97,     0,     0,     0,     0,   -97,   -97,
     -97,   -97,   -97,   -97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -97,   -97,   -97,   -97,     0,     0,
     -97,   -97,   -85,   -85,   -85,     0,   -85,   -85,     0,     0,
       0,     0,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -85,   -85,
     -85,   -85,     0,     0,   -85,   -85,   -98,   -98,   -98,     0,
     -98,   -98,     0,     0,     0,     0,   -98,   -98,   -98,   -98,
     -98,   -98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -98,   -98,   -98,   -98,     0,     0,   -98,   -98,
     -86,   -86,   -86,     0,   -86,   -86,     0,     0,     0,     0,
     -86,   -86,   -86,   -86,   -86,   -86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -86,   -86,   -86,   -86,
       0,     0,   -86,   -86,   -71,   -71,   -71,     0,   -71,   -71,
       0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -71,   -71,   -71,   -71,     0,     0,   -71,   -71,   345,   346,
     347,     0,   348,   349,     0,     0,     0,     0,   350,   351,
     352,   353,   354,   355,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   356,   357,   358,   359,     0,     0,
     -74,   -74,  -122,  -122,  -122,     0,  -122,  -122,     0,     0,
       0,     0,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -122,  -122,
    -122,  -122,     0,     0,  -122,  -122,  -120,  -120,  -120,     0,
    -120,  -120,     0,     0,     0,     0,  -120,  -120,  -120,  -120,
    -120,  -120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -120,  -120,  -120,  -120,  -120,     0,  -120,  -119,
    -119,  -119,     0,  -119,  -119,     0,     0,     0,     0,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -119,  -119,  -119,  -119,  -119,
       0,  -119,  -118,  -118,  -118,     0,  -118,  -118,     0,     0,
       0,     0,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -118,  -118,
    -118,  -118,  -118,     0,  -118,   459,   460,   461,     0,   462,
     463,     0,     0,     0,     0,   464,   465,   466,   467,   468,
     469,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   473,   -63,     0,   -63,   -64,   -64,
     -64,     0,   -64,   -64,     0,     0,     0,     0,   -64,   -64,
     -64,   -64,   -64,   -64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -64,   -64,   -64,   -64,   -64,     0,
     -64,   -65,   -65,   -65,     0,   -65,   -65,     0,     0,     0,
       0,   -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -65,   -65,   -65,
     -65,   -65,     0,   -65,   -66,   -66,   -66,     0,   -66,   -66,
       0,     0,     0,     0,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -66,   -66,   -66,     0,   -66,   -67,   -67,   -67,
       0,   -67,   -67,     0,     0,     0,     0,   -67,   -67,   -67,
     -67,   -67,   -67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -67,   -67,   -67,   -67,   -67,     0,   -67,
     -68,   -68,   -68,     0,   -68,   -68,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,     0,   -68,  -115,  -115,  -115,     0,  -115,  -115,     0,
       0,     0,     0,  -115,  -115,  -115,  -115,  -115,  -115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -115,
    -115,  -115,  -115,  -115,     0,  -115,  -116,  -116,  -116,     0,
    -116,  -116,     0,     0,     0,     0,  -116,  -116,  -116,  -116,
    -116,  -116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -116,  -116,  -116,  -116,  -116,     0,  -116,  -117,
    -117,  -117,     0,  -117,  -117,     0,     0,     0,     0,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -117,  -117,  -117,  -117,  -117,
       0,  -117,   -69,   -69,   -69,     0,   -69,   -69,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -69,   -69,
     -69,   -69,   -69,     0,   -69,  -110,  -110,  -110,     0,  -110,
    -110,     0,     0,     0,     0,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -110,  -110,  -110,  -110,  -110,     0,  -110,  -105,  -105,
    -105,     0,  -105,  -105,     0,     0,     0,     0,  -105,  -105,
    -105,  -105,  -105,  -105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,     0,
    -105,  -111,  -111,  -111,     0,  -111,  -111,     0,     0,     0,
       0,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -111,  -111,  -111,
    -111,  -111,     0,  -111,  -106,  -106,  -106,     0,  -106,  -106,
       0,     0,     0,     0,  -106,  -106,  -106,  -106,  -106,  -106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -106,  -106,  -106,  -106,  -106,     0,  -106,  -112,  -112,  -112,
       0,  -112,  -112,     0,     0,     0,     0,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -112,  -112,  -112,  -112,  -112,     0,  -112,
    -107,  -107,  -107,     0,  -107,  -107,     0,     0,     0,     0,
    -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -107,  -107,  -107,  -107,
    -107,     0,  -107,  -113,  -113,  -113,     0,  -113,  -113,     0,
       0,     0,     0,  -113,  -113,  -113,  -113,  -113,  -113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -113,
    -113,  -113,  -113,  -113,     0,  -113,  -108,  -108,  -108,     0,
    -108,  -108,     0,     0,     0,     0,  -108,  -108,  -108,  -108,
    -108,  -108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -108,  -108,  -108,  -108,  -108,     0,  -108,  -114,
    -114,  -114,     0,  -114,  -114,     0,     0,     0,     0,  -114,
    -114,  -114,  -114,  -114,  -114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -114,  -114,  -114,  -114,  -114,
       0,  -114,  -109,  -109,  -109,     0,  -109,  -109,     0,     0,
       0,     0,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -109,  -109,
    -109,  -109,  -109,     0,  -109,   -72,   -72,   -72,     0,   -72,
     -72,     0,     0,     0,     0,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,   -72,     0,   -72,   -71,   -71,
     -71,     0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,     0,
     -71,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -102,  -102,  -102,
    -102,  -102,     0,  -102,   459,   460,   461,     0,   -99,   -99,
       0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,   -99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,   471,   472,   473,   -99,     0,   -99,  -103,  -103,  -103,
       0,  -103,  -103,     0,     0,     0,     0,  -103,  -103,  -103,
    -103,  -103,  -103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -103,  -103,  -103,  -103,  -103,     0,  -103,
    -100,   460,   461,     0,  -100,  -100,     0,     0,     0,     0,
    -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,   471,   472,   473,
    -100,     0,  -100,  -104,  -104,  -104,     0,  -104,  -104,     0,
       0,     0,     0,  -104,  -104,  -104,  -104,  -104,  -104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -104,
    -104,  -104,  -104,  -104,     0,  -104,  -101,  -101,   461,     0,
    -101,  -101,     0,     0,     0,     0,  -101,  -101,  -101,  -101,
    -101,  -101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   470,   471,   472,   473,  -101,     0,  -101,   -87,
     -87,   -87,     0,   -87,   -87,     0,     0,     0,     0,   -87,
     -87,   -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -87,   -87,   -87,   -87,   -87,
       0,   -87,   459,   460,   461,     0,   -75,   463,     0,     0,
       0,     0,   464,   465,   466,   467,   468,   469,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   471,
     472,   473,   -75,     0,   -75,   -88,   -88,   -88,     0,   -88,
     -88,     0,     0,     0,     0,   -88,   -88,   -88,   -88,   -88,
     -88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -88,   -88,   -88,   -88,   -88,     0,   -88,   459,   460,
     461,     0,   -76,   -76,     0,     0,     0,     0,   464,   465,
     466,   467,   468,   469,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,   471,   472,   473,   -76,     0,
     -76,   -89,   -89,   -89,     0,   -89,   -89,     0,     0,     0,
       0,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -89,   -89,   -89,
     -89,   -89,     0,   -89,   459,   460,   461,     0,   -77,   -77,
       0,     0,     0,     0,   -77,   -77,   466,   467,   468,   469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,   471,   472,   473,   -77,     0,   -77,   -90,   -90,   -90,
       0,   -90,   -90,     0,     0,     0,     0,   -90,   -90,   -90,
     -90,   -90,   -90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -90,   -90,   -90,   -90,   -90,     0,   -90,
     459,   460,   461,     0,   -78,   -78,     0,     0,     0,     0,
     -78,   -78,   466,   467,   468,   469,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   470,   471,   472,   473,
     -78,     0,   -78,   -91,   -91,   -91,     0,   -91,   -91,     0,
       0,     0,     0,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -91,
     -91,   -91,   -91,   -91,     0,   -91,   459,   460,   461,     0,
     -79,   -79,     0,     0,     0,     0,   -79,   -79,   -79,   -79,
     -79,   -79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   470,   471,   472,   473,   -79,     0,   -79,   -92,
     -92,   -92,     0,   -92,   -92,     0,     0,     0,     0,   -92,
     -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -92,   -92,   -92,   -92,   -92,
       0,   -92,   459,   460,   461,     0,   -80,   -80,     0,     0,
       0,     0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   471,
     472,   473,   -80,     0,   -80,   -93,   -93,   -93,     0,   -93,
     -93,     0,     0,     0,     0,   -93,   -93,   -93,   -93,   -93,
     -93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -93,   -93,   -93,   -93,   -93,     0,   -93,   459,   460,
     461,     0,   -81,   -81,     0,     0,     0,     0,   -81,   -81,
     -81,   -81,   -81,   -81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   470,   471,   472,   473,   -81,     0,
     -81,   -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,
       0,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -94,   -94,   -94,
     -94,   -94,     0,   -94,   459,   460,   461,     0,   -82,   -82,
       0,     0,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,   471,   472,   473,   -82,     0,   -82,   -95,   -95,   -95,
       0,   -95,   -95,     0,     0,     0,     0,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -95,   -95,   -95,   -95,   -95,     0,   -95,
     -83,   -83,   -83,     0,   -83,   -83,     0,     0,     0,     0,
     -83,   -83,   -83,   -83,   -83,   -83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -83,   -83,   472,   473,
     -83,     0,   -83,   -96,   -96,   -96,     0,   -96,   -96,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -96,
     -96,   -96,   -96,   -96,     0,   -96,   -84,   -84,   -84,     0,
     -84,   -84,     0,     0,     0,     0,   -84,   -84,   -84,   -84,
     -84,   -84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -84,   -84,   472,   473,   -84,     0,   -84,   -97,
     -97,   -97,     0,   -97,   -97,     0,     0,     0,     0,   -97,
     -97,   -97,   -97,   -97,   -97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -97,   -97,   -97,   -97,   -97,
       0,   -97,   -85,   -85,   -85,     0,   -85,   -85,     0,     0,
       0,     0,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -85,   -85,
     -85,   -85,   -85,     0,   -85,   -98,   -98,   -98,     0,   -98,
     -98,     0,     0,     0,     0,   -98,   -98,   -98,   -98,   -98,
     -98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -98,   -98,   -98,   -98,   -98,     0,   -98,   -86,   -86,
     -86,     0,   -86,   -86,     0,     0,     0,     0,   -86,   -86,
     -86,   -86,   -86,   -86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -86,   -86,   -86,   -86,   -86,     0,
     -86,   459,   460,   461,     0,   462,   463,     0,     0,     0,
       0,   464,   465,   466,   467,   468,   469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,   471,   472,
     473,   -74,     0,   -74,  -122,  -122,  -122,     0,  -122,  -122,
       0,     0,     0,     0,  -122,  -122,  -122,  -122,  -122,  -122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -122,  -122,  -122,  -122,  -122,     0,  -122,   256,   257,   258,
       0,   259,   260,     0,     0,     0,     0,   261,   262,   263,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,   268,   269,   270,     0,     0,   111,
     256,   257,   258,     0,   259,   260,     0,     0,     0,     0,
     261,   262,   263,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   268,   269,   270,
       0,     0,   162,   256,   257,   258,     0,   259,   260,     0,
       0,     0,     0,   261,   262,   263,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     268,   269,   270,     0,     0,   164,  -120,  -120,  -120,     0,
    -120,  -120,     0,     0,     0,     0,  -120,  -120,  -120,  -120,
    -120,  -120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -120,  -120,  -120,  -120,     0,     0,  -120,  -119,
    -119,  -119,     0,  -119,  -119,     0,     0,     0,     0,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -119,  -119,  -119,  -119,     0,
       0,  -119,  -118,  -118,  -118,     0,  -118,  -118,     0,     0,
       0,     0,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -118,  -118,
    -118,  -118,     0,     0,  -118,   -64,   -64,   -64,     0,   -64,
     -64,     0,     0,     0,     0,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -64,   -64,   -64,   -64,     0,     0,   -64,   -65,   -65,
     -65,     0,   -65,   -65,     0,     0,     0,     0,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,     0,     0,
     -65,   -66,   -66,   -66,     0,   -66,   -66,     0,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
     -66,     0,     0,   -66,   -67,   -67,   -67,     0,   -67,   -67,
       0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -67,   -67,   -67,   -67,     0,     0,   -67,   -68,   -68,   -68,
       0,   -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,     0,     0,   -68,
    -115,  -115,  -115,     0,  -115,  -115,     0,     0,     0,     0,
    -115,  -115,  -115,  -115,  -115,  -115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -115,  -115,  -115,  -115,
       0,     0,  -115,  -116,  -116,  -116,     0,  -116,  -116,     0,
       0,     0,     0,  -116,  -116,  -116,  -116,  -116,  -116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -116,
    -116,  -116,  -116,     0,     0,  -116,  -117,  -117,  -117,     0,
    -117,  -117,     0,     0,     0,     0,  -117,  -117,  -117,  -117,
    -117,  -117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -117,  -117,  -117,  -117,     0,     0,  -117,   -69,
     -69,   -69,     0,   -69,   -69,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -69,   -69,   -69,   -69,     0,
       0,   -69,   256,   257,   258,     0,   259,   260,     0,     0,
       0,     0,   261,   262,   263,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   268,
     269,   270,     0,     0,   -63,  -110,  -110,  -110,     0,  -110,
    -110,     0,     0,     0,     0,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -110,  -110,  -110,  -110,     0,     0,  -110,  -105,  -105,
    -105,     0,  -105,  -105,     0,     0,     0,     0,  -105,  -105,
    -105,  -105,  -105,  -105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -105,  -105,  -105,  -105,     0,     0,
    -105,  -111,  -111,  -111,     0,  -111,  -111,     0,     0,     0,
       0,  -111,  -111,  -111,  -111,  -111,  -111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -111,  -111,  -111,
    -111,     0,     0,  -111,  -106,  -106,  -106,     0,  -106,  -106,
       0,     0,     0,     0,  -106,  -106,  -106,  -106,  -106,  -106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -106,  -106,  -106,  -106,     0,     0,  -106,  -112,  -112,  -112,
       0,  -112,  -112,     0,     0,     0,     0,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -112,  -112,  -112,  -112,     0,     0,  -112,
    -107,  -107,  -107,     0,  -107,  -107,     0,     0,     0,     0,
    -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -107,  -107,  -107,  -107,
       0,     0,  -107,  -113,  -113,  -113,     0,  -113,  -113,     0,
       0,     0,     0,  -113,  -113,  -113,  -113,  -113,  -113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -113,
    -113,  -113,  -113,     0,     0,  -113,  -108,  -108,  -108,     0,
    -108,  -108,     0,     0,     0,     0,  -108,  -108,  -108,  -108,
    -108,  -108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -108,  -108,  -108,  -108,     0,     0,  -108,  -114,
    -114,  -114,     0,  -114,  -114,     0,     0,     0,     0,  -114,
    -114,  -114,  -114,  -114,  -114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -114,  -114,  -114,  -114,     0,
       0,  -114,  -109,  -109,  -109,     0,  -109,  -109,     0,     0,
       0,     0,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -109,  -109,
    -109,  -109,     0,     0,  -109,   256,   257,   258,     0,   259,
     260,     0,     0,     0,     0,   261,   262,   263,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   268,   269,   270,     0,     0,   510,   -72,   -72,
     -72,     0,   -72,   -72,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -72,   -72,   -72,   -72,     0,     0,
     -72,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -102,  -102,  -102,
    -102,     0,     0,  -102,   256,   257,   258,     0,   -99,   -99,
       0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,   -99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   268,   269,   270,     0,     0,   -99,  -103,  -103,  -103,
       0,  -103,  -103,     0,     0,     0,     0,  -103,  -103,  -103,
    -103,  -103,  -103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -103,  -103,  -103,  -103,     0,     0,  -103,
    -100,   257,   258,     0,  -100,  -100,     0,     0,     0,     0,
    -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   268,   269,   270,
       0,     0,  -100,  -104,  -104,  -104,     0,  -104,  -104,     0,
       0,     0,     0,  -104,  -104,  -104,  -104,  -104,  -104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -104,
    -104,  -104,  -104,     0,     0,  -104,  -101,  -101,   258,     0,
    -101,  -101,     0,     0,     0,     0,  -101,  -101,  -101,  -101,
    -101,  -101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,   268,   269,   270,     0,     0,  -101,   -87,
     -87,   -87,     0,   -87,   -87,     0,     0,     0,     0,   -87,
     -87,   -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -87,   -87,   -87,   -87,     0,
       0,   -87,   256,   257,   258,     0,   -75,   260,     0,     0,
       0,     0,   261,   262,   263,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   268,
     269,   270,     0,     0,   -75,   -88,   -88,   -88,     0,   -88,
     -88,     0,     0,     0,     0,   -88,   -88,   -88,   -88,   -88,
     -88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -88,   -88,   -88,   -88,     0,     0,   -88,   256,   257,
     258,     0,   -76,   -76,     0,     0,     0,     0,   261,   262,
     263,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,   268,   269,   270,     0,     0,
     -76,   -89,   -89,   -89,     0,   -89,   -89,     0,     0,     0,
       0,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -89,   -89,   -89,
     -89,     0,     0,   -89,   256,   257,   258,     0,   -77,   -77,
       0,     0,     0,     0,   -77,   -77,   263,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   268,   269,   270,     0,     0,   -77,   -90,   -90,   -90,
       0,   -90,   -90,     0,     0,     0,     0,   -90,   -90,   -90,
     -90,   -90,   -90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -90,   -90,   -90,   -90,     0,     0,   -90,
     256,   257,   258,     0,   -78,   -78,     0,     0,     0,     0,
     -78,   -78,   263,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   268,   269,   270,
       0,     0,   -78,   -91,   -91,   -91,     0,   -91,   -91,     0,
       0,     0,     0,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -91,
     -91,   -91,   -91,     0,     0,   -91,   256,   257,   258,     0,
     -79,   -79,     0,     0,     0,     0,   -79,   -79,   -79,   -79,
     -79,   -79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,   268,   269,   270,     0,     0,   -79,   -92,
     -92,   -92,     0,   -92,   -92,     0,     0,     0,     0,   -92,
     -92,   -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -92,   -92,   -92,   -92,     0,
       0,   -92,   256,   257,   258,     0,   -80,   -80,     0,     0,
       0,     0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   268,
     269,   270,     0,     0,   -80,   -93,   -93,   -93,     0,   -93,
     -93,     0,     0,     0,     0,   -93,   -93,   -93,   -93,   -93,
     -93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -93,   -93,   -93,   -93,     0,     0,   -93,   256,   257,
     258,     0,   -81,   -81,     0,     0,     0,     0,   -81,   -81,
     -81,   -81,   -81,   -81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,   268,   269,   270,     0,     0,
     -81,   -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,
       0,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -94,   -94,   -94,
     -94,     0,     0,   -94,   256,   257,   258,     0,   -82,   -82,
       0,     0,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   268,   269,   270,     0,     0,   -82,   -95,   -95,   -95,
       0,   -95,   -95,     0,     0,     0,     0,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -95,   -95,   -95,   -95,     0,     0,   -95,
     -83,   -83,   -83,     0,   -83,   -83,     0,     0,     0,     0,
     -83,   -83,   -83,   -83,   -83,   -83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -83,   -83,   269,   270,
       0,     0,   -83,   -96,   -96,   -96,     0,   -96,   -96,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -96,
     -96,   -96,   -96,     0,     0,   -96,   -84,   -84,   -84,     0,
     -84,   -84,     0,     0,     0,     0,   -84,   -84,   -84,   -84,
     -84,   -84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -84,   -84,   269,   270,     0,     0,   -84,   -97,
     -97,   -97,     0,   -97,   -97,     0,     0,     0,     0,   -97,
     -97,   -97,   -97,   -97,   -97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -97,   -97,   -97,   -97,     0,
       0,   -97,   -85,   -85,   -85,     0,   -85,   -85,     0,     0,
       0,     0,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -85,   -85,
     -85,   -85,     0,     0,   -85,   -98,   -98,   -98,     0,   -98,
     -98,     0,     0,     0,     0,   -98,   -98,   -98,   -98,   -98,
     -98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -98,   -98,   -98,   -98,     0,     0,   -98,   -86,   -86,
     -86,     0,   -86,   -86,     0,     0,     0,     0,   -86,   -86,
     -86,   -86,   -86,   -86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -86,   -86,   -86,   -86,     0,     0,
     -86,   256,   257,   258,     0,   259,   260,     0,     0,     0,
       0,   261,   262,   263,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,   268,   269,
     270,     0,     0,   528,   256,   257,   258,     0,   259,   260,
       0,     0,     0,     0,   261,   262,   263,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   268,   269,   270,     0,     0,   544,   -71,   -71,   -71,
       0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,   -71,     0,     0,   -71,
     256,   257,   258,     0,   259,   260,     0,     0,     0,     0,
     261,   262,   263,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,   268,   269,   270,
       0,     0,   583,   256,   257,   258,     0,   259,   260,     0,
       0,     0,     0,   261,   262,   263,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     268,   269,   270,     0,     0,   585,   256,   257,   258,     0,
     259,   260,     0,     0,     0,     0,   261,   262,   263,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,   268,   269,   270,     0,     0,   597,   256,
     257,   258,     0,   259,   260,     0,     0,     0,     0,   261,
     262,   263,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,   268,   269,   270,     0,
       0,   599,   256,   257,   258,     0,   259,   260,     0,     0,
       0,     0,   261,   262,   263,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   267,   268,
     269,   270,     0,     0,   -74,  -122,  -122,  -122,     0,  -122,
    -122,     0,     0,     0,     0,  -122,  -122,  -122,  -122,  -122,
    -122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -122,  -122,  -122,  -122,     0,     0,  -122,  -120,  -120,
    -120,     0,  -120,  -120,     0,     0,     0,     0,  -120,  -120,
    -120,  -120,  -120,  -120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -120,  -120,  -120,  -120,  -120,  -119,
    -119,  -119,     0,  -119,  -119,     0,     0,     0,     0,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -119,  -119,  -119,  -119,  -119,
    -118,  -118,  -118,     0,  -118,  -118,     0,     0,     0,     0,
    -118,  -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -118,  -118,  -118,  -118,
    -118,    76,    77,    78,     0,    79,    80,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,
       0,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -64,   -64,
     -64,   -64,   -64,   -65,   -65,   -65,     0,   -65,   -65,     0,
       0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -65,
     -65,   -65,   -65,   -65,   -66,   -66,   -66,     0,   -66,   -66,
       0,     0,     0,     0,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -66,   -66,   -66,   -67,   -67,   -67,     0,   -67,
     -67,     0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,
     -67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,   -68,   -68,   -68,     0,
     -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -68,   -68,   -68,   -68,   -68,  -115,  -115,  -115,
       0,  -115,  -115,     0,     0,     0,     0,  -115,  -115,  -115,
    -115,  -115,  -115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -115,  -115,  -115,  -115,  -115,  -116,  -116,
    -116,     0,  -116,  -116,     0,     0,     0,     0,  -116,  -116,
    -116,  -116,  -116,  -116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -116,  -116,  -116,  -116,  -116,  -117,
    -117,  -117,     0,  -117,  -117,     0,     0,     0,     0,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -117,  -117,  -117,  -117,  -117,
     -69,   -69,   -69,     0,   -69,   -69,     0,     0,     0,     0,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -69,   -69,   -69,   -69,
     -69,  -110,  -110,  -110,     0,  -110,  -110,     0,     0,     0,
       0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,  -110,  -105,  -105,  -105,     0,  -105,  -105,     0,     0,
       0,     0,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -105,  -105,
    -105,  -105,  -105,  -111,  -111,  -111,     0,  -111,  -111,     0,
       0,     0,     0,  -111,  -111,  -111,  -111,  -111,  -111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -111,
    -111,  -111,  -111,  -111,  -106,  -106,  -106,     0,  -106,  -106,
       0,     0,     0,     0,  -106,  -106,  -106,  -106,  -106,  -106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -106,  -106,  -106,  -106,  -106,  -112,  -112,  -112,     0,  -112,
    -112,     0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,
    -112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -112,  -112,  -112,  -112,  -112,  -107,  -107,  -107,     0,
    -107,  -107,     0,     0,     0,     0,  -107,  -107,  -107,  -107,
    -107,  -107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -107,  -107,  -107,  -107,  -107,    76,    77,    78,
       0,    79,    80,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,   -60,  -113,  -113,
    -113,     0,  -113,  -113,     0,     0,     0,     0,  -113,  -113,
    -113,  -113,  -113,  -113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -113,  -113,  -113,  -113,  -113,  -108,
    -108,  -108,     0,  -108,  -108,     0,     0,     0,     0,  -108,
    -108,  -108,  -108,  -108,  -108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -108,  -108,  -108,  -108,  -108,
    -114,  -114,  -114,     0,  -114,  -114,     0,     0,     0,     0,
    -114,  -114,  -114,  -114,  -114,  -114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -114,  -114,  -114,  -114,
    -114,  -109,  -109,  -109,     0,  -109,  -109,     0,     0,     0,
       0,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -109,  -109,  -109,
    -109,  -109,   -72,   -72,   -72,     0,   -72,   -72,     0,     0,
       0,     0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,   -72,    76,    77,    78,     0,    79,    80,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,   -63,   -71,   -71,   -71,     0,   -71,   -71,
       0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -71,   -71,   -71,   -71,   -71,  -102,  -102,  -102,     0,  -102,
    -102,     0,     0,     0,     0,  -102,  -102,  -102,  -102,  -102,
    -102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,    76,    77,    78,     0,
     -99,   -99,     0,     0,     0,     0,   -99,   -99,   -99,   -99,
     -99,   -99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,   -99,  -103,  -103,  -103,
       0,  -103,  -103,     0,     0,     0,     0,  -103,  -103,  -103,
    -103,  -103,  -103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -103,  -103,  -103,  -103,  -103,  -100,    77,
      78,     0,  -100,  -100,     0,     0,     0,     0,  -100,  -100,
    -100,  -100,  -100,  -100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,  -100,  -104,
    -104,  -104,     0,  -104,  -104,     0,     0,     0,     0,  -104,
    -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -104,  -104,  -104,  -104,  -104,
    -101,  -101,    78,     0,  -101,  -101,     0,     0,     0,     0,
    -101,  -101,  -101,  -101,  -101,  -101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
    -101,   -87,   -87,   -87,     0,   -87,   -87,     0,     0,     0,
       0,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -87,   -87,   -87,
     -87,   -87,    76,    77,    78,     0,   -75,    80,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,    90,   -75,   -88,   -88,   -88,     0,   -88,   -88,     0,
       0,     0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -88,
     -88,   -88,   -88,   -88,    76,    77,    78,     0,   -76,   -76,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,   -76,   -89,   -89,   -89,     0,   -89,
     -89,     0,     0,     0,     0,   -89,   -89,   -89,   -89,   -89,
     -89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -89,   -89,   -89,   -89,   -89,    76,    77,    78,     0,
     -77,   -77,     0,     0,     0,     0,   -77,   -77,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,   -77,   -90,   -90,   -90,
       0,   -90,   -90,     0,     0,     0,     0,   -90,   -90,   -90,
     -90,   -90,   -90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -90,   -90,   -90,   -90,   -90,    76,    77,
      78,     0,   -78,   -78,     0,     0,     0,     0,   -78,   -78,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,   -78,   -91,
     -91,   -91,     0,   -91,   -91,     0,     0,     0,     0,   -91,
     -91,   -91,   -91,   -91,   -91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -91,   -91,   -91,   -91,   -91,
      76,    77,    78,     0,   -79,   -79,     0,     0,     0,     0,
     -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
     -79,   -92,   -92,   -92,     0,   -92,   -92,     0,     0,     0,
       0,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -92,   -92,   -92,
     -92,   -92,    76,    77,    78,     0,   -80,   -80,     0,     0,
       0,     0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,    90,   -80,   -93,   -93,   -93,     0,   -93,   -93,     0,
       0,     0,     0,   -93,   -93,   -93,   -93,   -93,   -93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -93,
     -93,   -93,   -93,   -93,    76,    77,    78,     0,   -81,   -81,
       0,     0,     0,     0,   -81,   -81,   -81,   -81,   -81,   -81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,   -81,   -94,   -94,   -94,     0,   -94,
     -94,     0,     0,     0,     0,   -94,   -94,   -94,   -94,   -94,
     -94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -94,   -94,   -94,   -94,   -94,    76,    77,    78,     0,
     -82,   -82,     0,     0,     0,     0,   -82,   -82,   -82,   -82,
     -82,   -82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,    89,    90,   -82,   -95,   -95,   -95,
       0,   -95,   -95,     0,     0,     0,     0,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -95,   -95,   -95,   -95,   -95,   -83,   -83,
     -83,     0,   -83,   -83,     0,     0,     0,     0,   -83,   -83,
     -83,   -83,   -83,   -83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -83,   -83,    89,    90,   -83,   -96,
     -96,   -96,     0,   -96,   -96,     0,     0,     0,     0,   -96,
     -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -96,   -96,   -96,   -96,   -96,
     -84,   -84,   -84,     0,   -84,   -84,     0,     0,     0,     0,
     -84,   -84,   -84,   -84,   -84,   -84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -84,   -84,    89,    90,
     -84,   -97,   -97,   -97,     0,   -97,   -97,     0,     0,     0,
       0,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -97,   -97,   -97,
     -97,   -97,   -85,   -85,   -85,     0,   -85,   -85,     0,     0,
       0,     0,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -85,   -85,
     -85,   -85,   -85,   -98,   -98,   -98,     0,   -98,   -98,     0,
       0,     0,     0,   -98,   -98,   -98,   -98,   -98,   -98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,   -98,   -86,   -86,   -86,     0,   -86,   -86,
       0,     0,     0,     0,   -86,   -86,   -86,   -86,   -86,   -86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -86,   -86,   -86,   -86,   -86,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,   -74,  -122,  -122,  -122,     0,
    -122,  -122,     0,     0,     0,     0,  -122,  -122,  -122,  -122,
    -122,  -122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -122,  -122,  -122,  -122,  -122,    76,    77,    78,
       0,    79,    80,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,   419,    76,    77,
      78,     0,    79,    80,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,   447
};

static const yytype_int16 yycheck[] =
{
       0,   252,   252,   165,   512,   167,     0,    20,     0,     0,
      10,    11,    12,     6,     1,    15,    16,    17,    18,     1,
       1,    21,   530,     1,     6,     1,     1,     1,     6,    21,
      21,     9,    10,    11,    47,    13,    14,    15,    47,     1,
      49,   417,     0,   205,     6,   207,     1,   209,     3,     4,
      50,     6,    52,    47,    47,    20,   307,   307,     6,     1,
      60,    48,    62,     1,    47,    43,    44,    48,   576,   445,
      48,    49,    48,    48,    48,     1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   342,   342,     1,    49,     1,     1,     3,     4,    47,
       6,     7,     8,     9,    10,    11,    48,    13,    14,    15,
      48,     1,   276,     1,     1,     0,     6,    20,    47,     9,
      10,    11,    48,    13,    14,    15,     1,     6,     3,     4,
      47,     6,    38,    39,    40,    41,    21,    43,    44,     6,
      48,     0,    48,    48,    47,    51,    52,     5,     6,     6,
     314,   151,   152,    43,    44,     5,     6,    20,    48,    49,
      48,    48,    21,   163,   164,   165,    47,   167,    47,     5,
       6,   163,   164,    39,    49,     5,     6,    49,    50,     6,
       0,    47,    49,    50,    47,   185,    20,   187,   179,    49,
      47,    49,    50,   185,   194,   187,    47,    49,    49,    49,
      50,    21,   202,     6,   204,   205,   206,   207,   208,   209,
     202,    47,   204,    47,   206,     1,   208,    47,    47,   211,
       6,   212,    49,    50,   224,   225,   226,   227,   113,    47,
      49,    49,   224,   225,   226,   227,    48,   237,   238,   239,
     240,   241,   242,    47,    20,    49,    49,    50,    47,    20,
      49,     3,     4,   415,     6,    49,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    47,    48,    47,    49,   275,    47,    48,   163,   164,
      47,   443,    49,   168,    47,    47,    49,    49,    47,     0,
      49,    49,   292,   293,   294,   295,   296,   297,    49,    50,
     185,     1,   187,    49,    50,    49,    50,    49,    50,    52,
      21,    49,    50,   313,    49,    50,     1,   202,    47,   204,
      47,   206,     1,   208,    49,    50,   326,   327,   328,   329,
     330,   331,    47,    47,    47,    51,    20,    49,    47,   224,
     225,   226,   227,   163,   164,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      49,    49,    49,    49,    20,   185,    49,   187,    49,    47,
      47,    47,     6,    47,    47,     9,    10,    11,    48,    13,
      14,    15,   202,    47,   204,    48,   206,     0,   208,    49,
      47,    49,    47,    20,    48,     1,    49,    49,    49,    49,
      49,    47,     1,    47,   224,   225,   226,   227,    21,    43,
      44,   411,    52,   413,    48,   415,    49,    49,    17,    18,
      19,    20,    21,    22,   586,    49,   588,    49,    27,    28,
      29,    30,    31,    32,    49,    52,    47,    49,   600,   439,
     602,   441,    47,   443,    43,    44,    45,    46,    49,    48,
      49,    50,   163,   164,    47,    47,    47,    47,    47,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   185,   637,   187,   639,    47,   641,
      47,    47,    47,    21,   646,    49,   648,    47,   650,   212,
      49,   202,    49,   204,    49,   206,     1,   208,    49,     0,
      49,     6,     7,     8,     9,    10,    11,    49,    13,    14,
      15,   511,   512,   224,   225,   226,   227,    49,    49,   116,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   529,
     530,    -1,    -1,    38,    39,    40,    41,     1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,
     163,   164,    -1,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,     0,
      -1,    -1,   185,    -1,   187,   575,   576,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,   586,    -1,   588,   202,
      21,   204,    -1,   206,    -1,   208,    -1,    -1,   598,   599,
     600,    -1,   602,    -1,    -1,    -1,   598,   599,    -1,    -1,
      -1,   224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   625,    -1,   627,    -1,    -1,
      -1,    -1,    -1,   625,    -1,   627,    -1,   637,    -1,   639,
      -1,   641,    -1,   643,    -1,   645,   646,   647,   648,   649,
     650,   643,    -1,   645,    -1,   647,    -1,   649,    -1,    -1,
      -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   671,   672,   673,   674,    -1,    -1,    -1,    -1,   671,
     672,   673,   674,    -1,   185,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
     585,   202,    -1,   204,    -1,   206,    -1,   208,    -1,    -1,
      -1,    -1,    -1,   598,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   225,   226,   227,   612,    -1,   614,
      -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     625,    -1,   627,    -1,    -1,    -1,    -1,    -1,    -1,   634,
      -1,   636,    -1,   638,   185,   640,   187,    -1,   643,    -1,
     645,    -1,   647,    -1,   649,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,   204,    -1,   206,    -1,   208,   598,   599,
      -1,    -1,   667,   668,   669,   670,   671,   672,   673,   674,
      -1,    -1,    -1,   224,   225,   226,   227,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,   625,     6,   627,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   643,    -1,   645,    -1,   647,     1,   649,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,   671,   672,   673,   674,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      17,    18,    19,    20,    21,    22,    -1,   598,   599,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
       1,    48,    49,    50,   625,     6,   627,    -1,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,   645,    -1,   647,     1,   649,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    43,    44,    -1,    -1,    47,    48,    -1,     1,
     671,   672,   673,   674,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,   598,   599,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
       1,    -1,   625,    18,   627,     6,    21,    -1,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
     643,    -1,   645,    -1,   647,    -1,   649,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    52,    -1,    -1,
      -1,    42,    43,    44,    -1,    60,    -1,    48,   671,   672,
     673,   674,     1,    -1,     3,     4,    71,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,   598,   599,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,   116,    51,    52,    -1,   120,    -1,    38,    39,    40,
      41,    -1,    43,    44,   625,    -1,   627,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,   643,    -1,   645,    -1,   647,   152,   649,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     165,    27,    28,    29,    30,    31,    32,   598,   599,    -1,
     671,   672,   673,   674,   179,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,   194,
      -1,    -1,    -1,    -1,   625,   200,   627,    -1,    -1,    -1,
     205,    -1,   207,    -1,   209,    -1,    -1,   212,    -1,    -1,
      -1,    -1,   643,    -1,   645,    -1,   647,    -1,   649,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,   239,   240,   241,   242,    -1,    -1,
     671,   672,   673,   674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    -1,    -1,    -1,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,    -1,    -1,    -1,     1,    -1,   292,   293,   294,
     295,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,   313,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,   326,   327,   328,   329,   330,   331,    43,    44,    45,
      46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,   409,    -1,   411,    48,   413,    -1,
      51,    52,   417,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,   437,    -1,   439,    -1,   441,    -1,    18,     1,
     445,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,    -1,
      50,    -1,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      60,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,   511,   512,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   529,   530,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,   576,   152,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   586,    -1,    -1,    -1,   165,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,   600,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    43,    44,    45,    46,    -1,
      48,    49,    -1,    -1,    -1,   205,    -1,   207,    -1,   209,
      -1,    -1,   637,    -1,   639,    -1,   641,    -1,    -1,    -1,
      -1,   646,    -1,   648,    -1,   650,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,     1,    -1,    -1,   275,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,   296,   297,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    38,
      39,    40,    41,   313,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,   326,   327,   328,   329,
     330,   331,    -1,    -1,    -1,    43,    44,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,   411,    51,   413,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
      -1,   441,    -1,    18,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,    -1,    50,    -1,    52,    -1,    -1,
      -1,    38,    39,    40,    41,    60,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   511,   512,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,   529,
     530,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   575,   576,   152,     1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,   586,    -1,    -1,    -1,
     165,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
     600,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
     205,    -1,   207,    -1,   209,    -1,    -1,   637,    -1,   639,
      -1,   641,    -1,    -1,    -1,    -1,   646,    -1,   648,    -1,
     650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    -1,     1,    -1,    -1,
     275,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,   292,   293,   294,
     295,   296,   297,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    38,    39,    40,    41,   313,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      -1,   326,   327,   328,   329,   330,   331,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,   411,    48,   413,    -1,
      51,    52,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   439,    -1,   441,    -1,    18,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,    -1,
      50,    -1,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      60,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,   511,   512,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   529,   530,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,   576,   152,     1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,   586,    -1,    -1,    -1,   165,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,   600,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,   205,    -1,   207,    -1,   209,
      -1,    -1,   637,    -1,   639,    -1,   641,    -1,    -1,    -1,
      -1,   646,    -1,   648,    -1,   650,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,     1,    -1,    -1,   275,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,   296,   297,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    38,
      39,    40,    41,   313,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,   326,   327,   328,   329,
     330,   331,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,   411,    51,   413,    -1,    38,    39,    40,    41,    -1,
      43,    44,    17,    18,    19,    48,    21,    22,    51,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,   439,
      -1,   441,    -1,    18,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    -1,    -1,    -1,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,    -1,    50,    -1,    52,    -1,    -1,
       0,     1,    -1,     3,     4,    60,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,   511,   512,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,   529,
     530,    51,    -1,    -1,    43,    44,    -1,    -1,    47,    48,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,   575,   576,   152,    38,    39,
      40,    41,    -1,    43,    44,    -1,   586,    -1,    48,    -1,
     165,    51,    -1,    38,    39,    40,    41,    -1,    43,    44,
     600,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,     6,    -1,   194,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
     205,    -1,   207,    -1,   209,    -1,    -1,   637,    -1,   639,
      -1,   641,    -1,    -1,    -1,    -1,   646,    -1,   648,    -1,
     650,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    -1,     1,    -1,    -1,
     275,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,   292,   293,   294,
     295,   296,   297,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    38,    39,    40,    41,   313,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      -1,   326,   327,   328,   329,   330,   331,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,   411,    48,   413,    -1,
      51,    52,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   439,    -1,   441,    -1,    18,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,    -1,
      50,    -1,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      60,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,   511,   512,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   529,   530,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,   576,   152,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   586,    -1,    -1,    -1,   165,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,   600,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,   205,    -1,   207,    -1,   209,
      -1,    -1,   637,    -1,   639,    -1,   641,    -1,    -1,    -1,
      -1,   646,    -1,   648,    -1,   650,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,     1,    -1,    -1,   275,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,   296,   297,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    38,
      -1,    40,    41,   313,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,   326,   327,   328,   329,
     330,   331,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,   411,    51,   413,    -1,    38,    39,    40,    41,    -1,
      43,    44,    17,    18,    19,    48,    21,    22,    51,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,   439,
      -1,   441,    -1,    18,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    -1,    -1,    -1,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,    -1,    50,    -1,    52,    -1,    -1,
       0,     1,    -1,     3,     4,    60,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,   511,   512,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,   529,
     530,    51,    -1,    -1,    43,    44,    -1,    -1,    47,    48,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,   575,   576,   152,    38,    39,
      40,    41,    -1,    43,    44,    -1,   586,    -1,    48,    -1,
     165,    51,    -1,    38,    39,    40,    41,    -1,    43,    44,
     600,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,     6,    -1,   194,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
     205,    -1,   207,    -1,   209,    -1,    -1,   637,    -1,   639,
      -1,   641,    -1,    -1,    -1,    -1,   646,    -1,   648,    -1,
     650,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    -1,     1,    -1,    -1,
     275,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,   292,   293,   294,
     295,   296,   297,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    38,    -1,    40,    41,   313,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      -1,   326,   327,   328,   329,   330,   331,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,   411,    48,   413,    -1,
      51,    52,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   439,    -1,   441,    -1,    18,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,    -1,
      50,    -1,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      60,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,   511,   512,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   529,   530,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,   576,   152,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   586,    -1,    -1,    -1,   165,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,   600,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,   205,    -1,   207,    -1,   209,
      -1,    -1,   637,    -1,   639,    -1,   641,    -1,    -1,    -1,
      -1,   646,    -1,   648,    -1,   650,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,     1,    -1,    -1,   275,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,   296,   297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,   313,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,   326,   327,   328,   329,
     330,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,   411,    51,   413,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
      -1,   441,    -1,    18,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,    -1,    50,    -1,    52,    -1,    -1,
      -1,    38,    39,    40,    41,    60,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   511,   512,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,   529,
     530,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   575,   576,   152,    -1,     1,
      -1,    -1,    -1,    -1,     6,    -1,   586,     9,    10,    11,
     165,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
     600,    -1,     1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,   194,
      -1,    43,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,
     205,    -1,   207,    -1,   209,    -1,    -1,   637,    -1,   639,
      -1,   641,    -1,    -1,    43,    44,   646,    -1,   648,    48,
     650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    -1,     1,    -1,    -1,
     275,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,   292,   293,   294,
     295,   296,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   313,    43,
      44,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,   326,   327,   328,   329,   330,   331,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,    -1,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,   411,    51,   413,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   439,    -1,   441,    -1,    18,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,    -1,
      50,    -1,    52,    -1,    -1,    -1,    38,    39,    40,    41,
      60,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,   511,   512,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,   529,   530,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     575,   576,   152,    -1,     1,    -1,    -1,    -1,    -1,     6,
      -1,   586,     9,    10,    11,   165,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,   600,    -1,     1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,   194,    -1,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    -1,   205,    -1,   207,    -1,   209,
      -1,    -1,   637,    -1,   639,    -1,   641,    -1,    -1,    43,
      44,   646,    -1,   648,    48,   650,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,    -1,     1,    -1,    -1,   275,    -1,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,   295,   296,   297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   313,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,   326,   327,   328,   329,
     330,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,   411,    48,   413,    -1,    51,    52,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,
       1,   441,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,   511,   512,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,   529,
     530,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
       1,    48,    -1,    -1,    51,     6,    -1,    -1,     9,    10,
      11,    -1,    13,    14,    15,   575,   576,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,   586,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
     600,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,    -1,   637,    -1,   639,
      -1,   641,    -1,    -1,    -1,    -1,   646,    -1,   648,    -1,
     650,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
       0,     1,    48,     3,     4,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,     0,     1,    48,     3,     4,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,     0,     1,
      48,     3,     4,    51,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
       0,     1,    48,     3,     4,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,     0,     1,    48,     3,     4,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,     0,     1,    48,     3,
       4,    51,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,     0,     1,
      48,     3,     4,    51,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
       0,     1,    48,     3,     4,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,     0,     1,    48,     3,     4,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,     0,     1,    48,     3,
       4,    51,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,     0,     1,
      48,     3,     4,    51,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
       0,     1,    48,     3,     4,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,     0,     1,    48,     3,     4,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,     0,     1,    48,     3,
       4,    51,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,     0,     1,
      48,     3,     4,    51,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
       0,     1,    48,     3,     4,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,     0,     1,    48,     3,     4,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,     0,     1,    48,     3,
       4,    51,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,     0,     1,
      48,     3,     4,    51,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,
       0,     1,    48,     3,     4,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,     0,     1,    48,     3,     4,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,
      -1,    43,    44,     1,    -1,    -1,    48,    -1,     6,    51,
      -1,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
      -1,    -1,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,     1,    -1,    43,    44,    -1,
       6,    -1,    48,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,    -1,    -1,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,     1,    -1,    43,
      44,    -1,     6,    -1,    48,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,     1,
      -1,    43,    44,    -1,     6,    -1,    48,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,    -1,    -1,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,     1,    -1,    43,    44,    -1,     6,    -1,    48,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,     1,    -1,    43,    44,    -1,     6,    -1,
      48,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
      -1,    -1,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,     1,    -1,    43,    44,    -1,
       6,    -1,    48,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,    -1,    -1,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,     1,    -1,    43,
      44,    -1,     6,    -1,    48,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,     1,
      -1,    43,    44,    -1,     6,    -1,    48,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,    -1,    -1,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,     1,    -1,    43,    44,    -1,     6,    -1,    48,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,     1,    -1,    43,    44,    -1,     6,    -1,
      48,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
      -1,    -1,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,     1,    -1,    43,    44,    -1,
       6,    -1,    48,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,    -1,    -1,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,     1,    -1,    43,
      44,    -1,     6,    -1,    48,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,     1,
      -1,    43,    44,    -1,     6,    -1,    48,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,    -1,    -1,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,     1,    -1,    43,    44,    -1,     6,    -1,    48,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,     1,    -1,    43,    44,    -1,     6,    -1,
      48,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
      -1,    -1,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,     1,    -1,    43,    44,    -1,
       6,    -1,    48,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,    -1,    -1,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,     1,    -1,    43,
      44,    -1,     6,    -1,    48,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,     1,
      -1,    43,    44,    -1,     6,    -1,    48,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,    -1,    -1,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,     1,    -1,    43,    44,    -1,     6,    -1,    48,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,     1,    -1,    43,    44,    -1,     6,    -1,
      48,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
      -1,    -1,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,     1,    -1,    43,    44,    -1,
       6,    -1,    48,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,    -1,    -1,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,     1,    -1,    43,
      44,    -1,     6,    -1,    48,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,     1,
      -1,    43,    44,    -1,     6,    -1,    48,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,    -1,    -1,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,     1,    -1,    43,    44,    -1,     6,    -1,    48,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,    -1,    -1,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,     1,    -1,    43,    44,    -1,     6,    -1,
      48,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
      -1,    -1,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,     1,    -1,    43,    44,    -1,
       6,    -1,    48,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,    -1,    -1,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,     1,    -1,    43,
      44,    -1,     6,    -1,    48,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,    17,    18,    19,    48,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    50,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    50,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    17,    18,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    38,    40,    41,    43,    44,    48,    51,
      54,    55,    56,    57,    58,    63,    68,    69,    70,    72,
      73,    75,    76,    78,    79,    80,    81,    82,    83,    84,
      85,    87,    90,    91,    47,     5,     5,     1,    48,     1,
      48,     1,    48,    75,    90,     1,    75,     1,    75,     1,
      48,     1,    48,     1,    75,     1,    75,     1,    75,     1,
      75,    64,     0,     1,    56,    47,    17,    18,    19,    21,
      22,    27,    28,    29,    30,    31,    32,    43,    44,    45,
      46,    47,     1,    77,    86,    90,    47,    90,    47,     1,
      90,    47,     1,    42,    75,     1,    75,     1,    74,    75,
      49,    49,     1,    39,    57,    65,    66,    67,    68,    71,
      91,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,    20,    48,    20,    47,    20,    47,    48,    49,    49,
      49,    49,    49,    49,    49,    47,    49,    47,    39,    68,
      52,    67,    90,    75,    75,    88,    89,     1,     1,    59,
      47,    47,    47,    47,    47,    39,    68,    39,    68,    74,
       1,    74,    68,    49,    50,     1,    60,    61,    62,    90,
      91,    68,    39,    68,    39,    47,    49,    47,    49,    47,
      75,    49,    50,    90,    68,    68,    74,    68,    74,    68,
       1,    74,    63,    62,    49,    49,    49,    49,    68,    68,
      68,    68,     6,     6,     9,    10,    11,    13,    14,    15,
      43,    44,    48,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    90,     6,     6,     6,    17,    18,    19,    21,
      22,    27,    28,    29,    30,    31,    32,    43,    44,    45,
      46,     7,     8,    38,    40,    48,    51,    63,    69,    70,
      72,    73,    75,    87,    90,    47,     1,    47,     6,     9,
      10,    11,    13,    14,    15,    43,    44,    48,    76,    78,
      79,    80,    81,    82,    83,    84,    85,    90,     1,     7,
       8,    38,    40,    48,    51,    63,    69,    70,    72,    73,
      75,    87,     6,     9,    10,    11,    13,    14,    15,    43,
      44,    48,    75,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    90,    20,    47,    17,    18,    19,    21,    22,
      27,    28,    29,    30,    31,    32,    43,    44,    45,    46,
       3,     4,     6,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,    75,     1,    77,    86,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    48,
       1,    48,     1,    48,     1,    48,     1,    64,    47,    47,
      90,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,    75,     1,    77,    86,    47,     1,    48,     1,    48,
       1,    48,     1,    48,     1,    64,    47,    47,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,    75,    17,
      18,    19,    21,    22,    27,    28,    29,    30,    31,    32,
      43,    44,    45,    46,     1,    77,    86,     1,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     5,     5,
      49,    20,    48,    47,     1,    90,    47,     1,    42,    75,
       1,    75,     1,    74,    49,    65,    20,    47,    49,    20,
      48,    47,     1,    90,    47,     1,    42,    75,     1,    75,
       1,    74,    49,    65,    49,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,    20,    48,    75,    88,    49,
      49,    49,    49,    49,    49,    49,    47,    49,    47,    52,
       1,    75,    88,    49,    49,    49,    49,    49,    49,    49,
      47,    49,    47,    52,    75,    88,    49,    47,    47,    47,
      47,    47,    39,    68,    39,    68,    74,     1,    74,    49,
      47,    47,    47,    47,    47,    39,    68,    39,    68,    74,
       1,    74,    49,    68,    39,    68,    39,    47,    49,    47,
      49,    47,    68,    39,    68,    39,    47,    49,    47,    49,
      47,    68,    68,    74,    68,    74,    68,     1,    74,    68,
      68,    74,    68,    74,    68,     1,    74,    49,    49,    49,
      49,    49,    49,    49,    49,    68,    68,    68,    68,    68,
      68,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    59,    58,    60,    60,    61,
      61,    61,    62,    62,    62,    64,    63,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    77,    76,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    81,    81,    81,    82,    83,
      84,    86,    85,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    89,    89,    90,    91,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     0,     7,     0,     1,     3,
       1,     1,     2,     1,     1,     0,     4,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     3,
       1,     1,     2,     5,     7,     5,     7,     6,     6,     2,
       2,     3,     9,     9,     9,     9,     7,     7,     4,     2,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     0,     5,     5,     5,     5,     5,     5,     3,     3,
       0,     1,     3,     1,     1,     1,     1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_INT_TOKEN: /* INT_TOKEN  */
#line 126 "./src/bison.y"
           {
    if(((*yyvaluep).string))
        free(((*yyvaluep).string));
}
#line 4941 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 126 "./src/bison.y"
           {
    if(((*yyvaluep).string))
        free(((*yyvaluep).string));
}
#line 4950 "bison.tab.c"
        break;

    case YYSYMBOL_LIST_TOKEN: /* LIST_TOKEN  */
#line 126 "./src/bison.y"
           {
    if(((*yyvaluep).string))
        free(((*yyvaluep).string));
}
#line 4959 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 4968 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 4977 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 4986 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 4995 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5004 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5013 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5022 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5031 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5040 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5049 "bison.tab.c"
        break;

    case YYSYMBOL_59_1: /* @1  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5058 "bison.tab.c"
        break;

    case YYSYMBOL_optListParams: /* optListParams  */
#line 121 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5067 "bison.tab.c"
        break;

    case YYSYMBOL_listParams: /* listParams  */
#line 121 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5076 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5085 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5094 "bison.tab.c"
        break;

    case YYSYMBOL_optListCodeBlock: /* optListCodeBlock  */
#line 121 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5103 "bison.tab.c"
        break;

    case YYSYMBOL_listCodeBlock: /* listCodeBlock  */
#line 121 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5112 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5121 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5130 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5139 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5148 "bison.tab.c"
        break;

    case YYSYMBOL_elseError: /* elseError  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5157 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5166 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5175 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5184 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5193 "bison.tab.c"
        break;

    case YYSYMBOL_assignArith: /* assignArith  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5202 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5211 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5220 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5229 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5238 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5247 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5256 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5265 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5274 "bison.tab.c"
        break;

    case YYSYMBOL_ioCommand: /* ioCommand  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5283 "bison.tab.c"
        break;

    case YYSYMBOL_optListExpression: /* optListExpression  */
#line 121 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5292 "bison.tab.c"
        break;

    case YYSYMBOL_listExpression: /* listExpression  */
#line 121 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5301 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5310 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 116 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5319 "bison.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* startProgram: error  */
#line 138 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected error || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 5617 "bison.tab.c"
    break;

  case 4: /* startProgram: %empty  */
#line 142 "./src/bison.y"
             {
        SHOW_SYNTAX_ERROR("empty translation unit\n");
    }
#line 5625 "bison.tab.c"
    break;

  case 5: /* declarationList: declarationList declaration  */
#line 148 "./src/bison.y"
                                {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 5633 "bison.tab.c"
    break;

  case 6: /* declarationList: declaration  */
#line 151 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 5641 "bison.tab.c"
    break;

  case 7: /* declaration: variableDeclare  */
#line 157 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5649 "bison.tab.c"
    break;

  case 8: /* declaration: functionDeclare  */
#line 160 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5657 "bison.tab.c"
    break;

  case 9: /* declaration: statement  */
#line 165 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("an statement is not permitted at this top level || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5667 "bison.tab.c"
    break;

  case 10: /* variableDeclare: type id ';'  */
#line 173 "./src/bison.y"
                {
        // printf("current_context_var: %p || name: %s\n", (void *) current_context, $2->context->name);
        Symbol *sym_declared = lookup_symbol_context((yyvsp[-1].astnode)->context->name, current_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("variable redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
            (yyval.astnode) = NULL;
            delete_astnode((yyvsp[-2].astnode));
            delete_astnode((yyvsp[-1].astnode));
        } else {
            Symbol *sym_ret;
            sym_ret = list_symbol_insert((yyvsp[-2].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[-1].astnode)->context->name, 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, VARIABLE);
            sym_ret->variable_tac = temporary_count++;
            (yyval.astnode) = create_astnode_context(AST_VAR_DECLARE, "variable declare", (yylsp[-2]));
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
            (yyvsp[-1].astnode)->context->dtype = (yyvsp[-2].astnode)->context->dtype;
            (yyvsp[-1].astnode)->context->sym_ref = sym_ret;
        }
    }
#line 5691 "bison.tab.c"
    break;

  case 11: /* variableDeclare: type ';'  */
#line 194 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("useless type name in empty declaration || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5701 "bison.tab.c"
    break;

  case 12: /* variableDeclare: type id ASSIGN_TOKEN error  */
#line 200 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 5712 "bison.tab.c"
    break;

  case 13: /* variableDeclare: id id ASSIGN_TOKEN error  */
#line 207 "./src/bison.y"
                               {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 5723 "bison.tab.c"
    break;

  case 14: /* variableDeclare: id id ';'  */
#line 214 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5734 "bison.tab.c"
    break;

  case 15: /* @1: %empty  */
#line 223 "./src/bison.y"
                         {
        (yyval.astnode) = (yyvsp[-1].astnode);
        // printf("current_context_func: %p || name: %s\n", (void *) current_context, $2->context->name);
        last_context = current_context;

        Symbol *sym_declared = lookup_symbol_context((yyvsp[-1].astnode)->context->name, last_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("function redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
            
        } else {
            Symbol *sym_ret;
            sym_ret = list_symbol_insert((yyvsp[-2].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[-1].astnode)->context->name, 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, FUNCTION);
            isFunctionContext = 1;
            insert_list_element(list_context, create_node(create_symbol_table()));
            Element *iterator;

            for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
                current_context = iterator->value;
            }
            insert_children(current_context, last_context);
            // sym_ret = list_symbol_insert($1->context->type, ((SymbolTable *)current_context->value)->symbols, $2->context->name, 0, @2.first_line, @2.first_column, FUNCTION);
            (yyvsp[-1].astnode)->context->dtype = (yyvsp[-2].astnode)->context->dtype;
            (yyvsp[-1].astnode)->context->sym_ref = sym_ret;
        }
    }
#line 5764 "bison.tab.c"
    break;

  case 16: /* functionDeclare: type id '(' @1 optListParams ')' compoundStatement  */
#line 247 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_FUNC_DECLARE, "func declare", (yyloc));
        (yyvsp[-5].astnode)->context->last_temp = temporary_count;
        if((yyvsp[-6].astnode))
            insert_kid((yyvsp[-6].astnode), (yyval.astnode));
        if((yyvsp[-3].astnode)){
            insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        }
        if((yyvsp[-2].list)){ /* Se existir parametros insira */
            // Cria um noh que recebe os parametros
            AstNode *params = create_astnode_context(AST_LIST_PARAM, "params", (yylsp[-2]));

            // Percorre a lista de parametros inserindo os parametros no noh params
            while((yyvsp[-2].list)->size) {
                AstNode *aux = remove_first_element_list((yyvsp[-2].list));
                insert_kid(aux, params);
            }
            delete_list((yyvsp[-2].list), delete_list_astnode);
            insert_kid(params, (yyval.astnode));
        }
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5791 "bison.tab.c"
    break;

  case 17: /* optListParams: %empty  */
#line 272 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 5799 "bison.tab.c"
    break;

  case 19: /* listParams: listParams ',' param  */
#line 279 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 5808 "bison.tab.c"
    break;

  case 20: /* listParams: param  */
#line 283 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 5817 "bison.tab.c"
    break;

  case 21: /* listParams: error  */
#line 289 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected params || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.list) = NULL;
    }
#line 5826 "bison.tab.c"
    break;

  case 22: /* param: type id  */
#line 296 "./src/bison.y"
            {
        Symbol *sym_declared = lookup_symbol_context((yyvsp[0].astnode)->context->name, current_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("param redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            
            (yyval.astnode) = NULL;
            delete_astnode((yyvsp[-1].astnode));
            delete_astnode((yyvsp[0].astnode));
        } else {
            Symbol *sym_ret;
            sym_ret = list_symbol_insert((yyvsp[-1].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[0].astnode)->context->name, 0, (yylsp[0]).first_line, (yylsp[0]).first_column, VARIABLE);
            sym_ret->variable_tac = temporary_count++;
            (yyval.astnode) = create_astnode_context(AST_PARAM, "param", (yyloc));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
            (yyvsp[0].astnode)->context->dtype = (yyvsp[-1].astnode)->context->dtype;
            (yyval.astnode)->context->dtype = (yyvsp[-1].astnode)->context->dtype;
            (yyvsp[0].astnode)->context->sym_ref = sym_ret;
        }
    }
#line 5851 "bison.tab.c"
    break;

  case 23: /* param: type  */
#line 318 "./src/bison.y"
           {
        SHOW_SYNTAX_ERROR("after '%s' expected identifier || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5861 "bison.tab.c"
    break;

  case 24: /* param: id  */
#line 324 "./src/bison.y"
         {
        SHOW_SYNTAX_ERROR("expected type to '%s' || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5871 "bison.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 332 "./src/bison.y"
        {
        // printf("current_context_compound: %p\n", (void *) current_context);
        if(!isFunctionContext){
            last_context = current_context;
            insert_list_element(list_context, create_node(create_symbol_table()));
            Element *iterator;

            for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
                current_context = iterator->value;
            }
            // printf("current_context: %p || last_context: %p\n", (void *) current_context, (void *) last_context);
            insert_children(current_context, last_context);
        }
        isFunctionContext = 0;
    }
#line 5891 "bison.tab.c"
    break;

  case 26: /* compoundStatement: '{' $@2 optListCodeBlock '}'  */
#line 346 "./src/bison.y"
                           {
        (yyval.astnode) = create_astnode_context(AST_STATE_COMPOUND, "compound statement", (yyloc));
        if((yyvsp[-1].list)){ /* Se existir code block insira */
            // Cria um noh que recebe os code blocks
            AstNode *codeblocks = create_astnode_context(AST_CODE_BLOCK, "code block", (yylsp[-1]));

            // Percorre a lista de code blocks inserindo os code blocks no noh code blocks
            while((yyvsp[-1].list)->size) {
                AstNode *aux = remove_first_element_list((yyvsp[-1].list));
                insert_kid(aux, codeblocks);
            }
            delete_list((yyvsp[-1].list), delete_list_astnode);
            insert_kid(codeblocks, (yyval.astnode));
        }
        // printf("Atualizando current_context: %p || pai: %p\n", (void *) current_context, (void *) current_context->father);
        current_context = current_context->father;
        // printf("Depois current_context: %p || pai: %p\n", (void *) current_context, (void *) current_context->father);
    }
#line 5914 "bison.tab.c"
    break;

  case 27: /* optListCodeBlock: %empty  */
#line 367 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 5922 "bison.tab.c"
    break;

  case 29: /* listCodeBlock: listCodeBlock codeBlock  */
#line 374 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 5931 "bison.tab.c"
    break;

  case 30: /* listCodeBlock: codeBlock  */
#line 378 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 5940 "bison.tab.c"
    break;

  case 31: /* codeBlock: statement  */
#line 385 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5948 "bison.tab.c"
    break;

  case 32: /* codeBlock: variableDeclare  */
#line 388 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
        // $$ = create_astnode_context(AST_CODE_BLOCK, "", @$);
        // insert_kid($1, $$);
    }
#line 5958 "bison.tab.c"
    break;

  case 34: /* statement: flowExpression  */
#line 397 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5966 "bison.tab.c"
    break;

  case 35: /* statement: compoundStatement  */
#line 400 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5974 "bison.tab.c"
    break;

  case 36: /* statement: expression ';'  */
#line 403 "./src/bison.y"
                     {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 5982 "bison.tab.c"
    break;

  case 37: /* statement: ioCommand  */
#line 406 "./src/bison.y"
                {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5990 "bison.tab.c"
    break;

  case 38: /* statement: error ';'  */
#line 411 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 5999 "bison.tab.c"
    break;

  case 39: /* statement: '(' error ')'  */
#line 416 "./src/bison.y"
                    {
        SHOW_SYNTAX_ERROR("expected expression before ')' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6008 "bison.tab.c"
    break;

  case 40: /* flowExpression: condExpression  */
#line 423 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6016 "bison.tab.c"
    break;

  case 41: /* flowExpression: interationExpression  */
#line 426 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6024 "bison.tab.c"
    break;

  case 42: /* flowExpression: returnExpression ';'  */
#line 429 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 6032 "bison.tab.c"
    break;

  case 43: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 435 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "if cond expression", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6042 "bison.tab.c"
    break;

  case 44: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 440 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "ifelse cond expression", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6053 "bison.tab.c"
    break;

  case 45: /* condExpression: IF_TOKEN '(' error ')' statement  */
#line 448 "./src/bison.y"
                                                      {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6063 "bison.tab.c"
    break;

  case 46: /* condExpression: IF_TOKEN '(' error ')' statement ELSE_TOKEN statement  */
#line 454 "./src/bison.y"
                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6074 "bison.tab.c"
    break;

  case 47: /* condExpression: IF_TOKEN '(' expression ')' ELSE_TOKEN statement  */
#line 461 "./src/bison.y"
                                                       {
        SHOW_SYNTAX_ERROR("expected expression before 'else' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6085 "bison.tab.c"
    break;

  case 48: /* condExpression: IF_TOKEN '(' error ')' ELSE_TOKEN statement  */
#line 468 "./src/bison.y"
                                                  {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6095 "bison.tab.c"
    break;

  case 49: /* condExpression: IF_TOKEN error  */
#line 474 "./src/bison.y"
                     {
        SHOW_SYNTAX_ERROR("expected '(' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6104 "bison.tab.c"
    break;

  case 50: /* elseError: ELSE_TOKEN statement  */
#line 483 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6114 "bison.tab.c"
    break;

  case 51: /* elseError: error ELSE_TOKEN statement  */
#line 489 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6124 "bison.tab.c"
    break;

  case 52: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 497 "./src/bison.y"
                                                                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ITERATION, "interation expression", (yyloc));
        if((yyvsp[-6].astnode))
            insert_kid((yyvsp[-6].astnode), (yyval.astnode));
        if((yyvsp[-4].astnode))
            insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        if((yyvsp[-2].astnode))
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6139 "bison.tab.c"
    break;

  case 53: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ';' optExpression ')' statement  */
#line 509 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6151 "bison.tab.c"
    break;

  case 54: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ';' optExpression ')' statement  */
#line 517 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6163 "bison.tab.c"
    break;

  case 55: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' error ')' statement  */
#line 525 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6175 "bison.tab.c"
    break;

  case 56: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ')' statement  */
#line 533 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6186 "bison.tab.c"
    break;

  case 57: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ')' statement  */
#line 540 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6197 "bison.tab.c"
    break;

  case 58: /* interationExpression: FOR_TOKEN '(' error ')'  */
#line 547 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6206 "bison.tab.c"
    break;

  case 59: /* interationExpression: FOR_TOKEN error  */
#line 552 "./src/bison.y"
                      {
        SHOW_SYNTAX_ERROR("expected '(' token after 'for' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6215 "bison.tab.c"
    break;

  case 60: /* returnExpression: RETURN_TOKEN expression  */
#line 559 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6224 "bison.tab.c"
    break;

  case 61: /* returnExpression: RETURN_TOKEN error  */
#line 565 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'return' with no value, in function returning non-void || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6233 "bison.tab.c"
    break;

  case 62: /* optExpression: %empty  */
#line 572 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 6241 "bison.tab.c"
    break;

  case 63: /* optExpression: expression  */
#line 575 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6249 "bison.tab.c"
    break;

  case 64: /* expression: assignArith  */
#line 581 "./src/bison.y"
                {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6257 "bison.tab.c"
    break;

  case 65: /* expression: binArith  */
#line 584 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6265 "bison.tab.c"
    break;

  case 66: /* expression: listArith  */
#line 587 "./src/bison.y"
                {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6273 "bison.tab.c"
    break;

  case 67: /* expression: unaArith  */
#line 590 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6281 "bison.tab.c"
    break;

  case 68: /* expression: constant  */
#line 593 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6289 "bison.tab.c"
    break;

  case 69: /* expression: funcCall  */
#line 596 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6297 "bison.tab.c"
    break;

  case 70: /* expression: id  */
#line 599 "./src/bison.y"
         {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            (yyval.astnode) = NULL;
        } else {
            (yyval.astnode) = (yyvsp[0].astnode);
            (yyval.astnode)->context->dtype = (yyvsp[0].astnode)->context->dtype;
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
        }
    }
#line 6313 "bison.tab.c"
    break;

  case 71: /* expression: '(' expression ')'  */
#line 610 "./src/bison.y"
                         {
        (yyval.astnode) = (yyvsp[-1].astnode);
        // $$ = create_astnode_context(AST_EXPRESSION, "(exp)", @$);
        // insert_kid($2, $$);
    }
#line 6323 "bison.tab.c"
    break;

  case 72: /* expression: id error  */
#line 617 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyvsp[-1].astnode) = NULL;
        (yyval.astnode) = NULL;
    }
#line 6334 "bison.tab.c"
    break;

  case 73: /* $@3: %empty  */
#line 626 "./src/bison.y"
       {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        } else {
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
        }
    }
#line 6347 "bison.tab.c"
    break;

  case 74: /* assignArith: id $@3 ASSIGN_TOKEN expression  */
#line 633 "./src/bison.y"
                              {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign", (yyloc));
        (yyval.astnode)->context->operation = strdup("=");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6358 "bison.tab.c"
    break;

  case 75: /* binArith: expression OR_TOKEN expression  */
#line 642 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}", (yyloc));
        (yyval.astnode)->context->operation = strdup("||");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6369 "bison.tab.c"
    break;

  case 76: /* binArith: expression AND_TOKEN expression  */
#line 648 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}", (yyloc));
        (yyval.astnode)->context->operation = strdup("&&");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6380 "bison.tab.c"
    break;

  case 77: /* binArith: expression EQUAL_TOKEN expression  */
#line 654 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}", (yyloc));
        (yyval.astnode)->context->operation = strdup("==");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6391 "bison.tab.c"
    break;

  case 78: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 660 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}", (yyloc));
        (yyval.astnode)->context->operation = strdup("!=");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6402 "bison.tab.c"
    break;

  case 79: /* binArith: expression LESS_TOKEN expression  */
#line 666 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}", (yyloc));
        (yyval.astnode)->context->operation = strdup("<");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6413 "bison.tab.c"
    break;

  case 80: /* binArith: expression LE_EQ_TOKEN expression  */
#line 672 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}", (yyloc));
        (yyval.astnode)->context->operation = strdup("<=");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6424 "bison.tab.c"
    break;

  case 81: /* binArith: expression GREAT_TOKEN expression  */
#line 678 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}", (yyloc));
        (yyval.astnode)->context->operation = strdup(">");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6435 "bison.tab.c"
    break;

  case 82: /* binArith: expression GR_EQ_TOKEN expression  */
#line 684 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}", (yyloc));
        (yyval.astnode)->context->operation = strdup(">=");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6446 "bison.tab.c"
    break;

  case 83: /* binArith: expression '+' expression  */
#line 690 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}", (yyloc));
        (yyval.astnode)->context->operation = strdup("+");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6457 "bison.tab.c"
    break;

  case 84: /* binArith: expression '-' expression  */
#line 696 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}", (yyloc));
        (yyval.astnode)->context->operation = strdup("-");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6468 "bison.tab.c"
    break;

  case 85: /* binArith: expression '*' expression  */
#line 702 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}", (yyloc));
        (yyval.astnode)->context->operation = strdup("*");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6479 "bison.tab.c"
    break;

  case 86: /* binArith: expression '/' expression  */
#line 708 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}", (yyloc));
        (yyval.astnode)->context->operation = strdup("/");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6490 "bison.tab.c"
    break;

  case 87: /* binArith: expression OR_TOKEN error  */
#line 715 "./src/bison.y"
                                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6500 "bison.tab.c"
    break;

  case 88: /* binArith: expression AND_TOKEN error  */
#line 720 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6510 "bison.tab.c"
    break;

  case 89: /* binArith: expression EQUAL_TOKEN error  */
#line 725 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6520 "bison.tab.c"
    break;

  case 90: /* binArith: expression DIFF_EQ_TOKEN error  */
#line 730 "./src/bison.y"
                                     {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6530 "bison.tab.c"
    break;

  case 91: /* binArith: expression LESS_TOKEN error  */
#line 735 "./src/bison.y"
                                  {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6540 "bison.tab.c"
    break;

  case 92: /* binArith: expression LE_EQ_TOKEN error  */
#line 740 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6550 "bison.tab.c"
    break;

  case 93: /* binArith: expression GREAT_TOKEN error  */
#line 745 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6560 "bison.tab.c"
    break;

  case 94: /* binArith: expression GR_EQ_TOKEN error  */
#line 750 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6570 "bison.tab.c"
    break;

  case 95: /* binArith: expression '+' error  */
#line 755 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6580 "bison.tab.c"
    break;

  case 96: /* binArith: expression '-' error  */
#line 760 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6590 "bison.tab.c"
    break;

  case 97: /* binArith: expression '*' error  */
#line 765 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6600 "bison.tab.c"
    break;

  case 98: /* binArith: expression '/' error  */
#line 770 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6610 "bison.tab.c"
    break;

  case 99: /* listArith: expression MAP_TOKEN expression  */
#line 778 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}", (yyloc));
        (yyval.astnode)->context->operation = strdup(">>");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6621 "bison.tab.c"
    break;

  case 100: /* listArith: expression FILTER_TOKEN expression  */
#line 784 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}", (yyloc));
        (yyval.astnode)->context->operation = strdup("<<");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6632 "bison.tab.c"
    break;

  case 101: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 790 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}", (yyloc));
        (yyval.astnode)->context->operation = strdup(":");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6643 "bison.tab.c"
    break;

  case 102: /* listArith: expression MAP_TOKEN error  */
#line 797 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6653 "bison.tab.c"
    break;

  case 103: /* listArith: expression FILTER_TOKEN error  */
#line 802 "./src/bison.y"
                                    {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6663 "bison.tab.c"
    break;

  case 104: /* listArith: expression CONSTRUCTOR_LIST_TOKEN error  */
#line 807 "./src/bison.y"
                                              {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6673 "bison.tab.c"
    break;

  case 105: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 815 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}", (yyloc));
        (yyval.astnode)->context->operation = strdup("!");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6683 "bison.tab.c"
    break;

  case 106: /* unaArith: QUESTION_TOKEN expression  */
#line 820 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}", (yyloc));
        (yyval.astnode)->context->operation = strdup("?");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6693 "bison.tab.c"
    break;

  case 107: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 825 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}", (yyloc));
        (yyval.astnode)->context->operation = strdup("%");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6703 "bison.tab.c"
    break;

  case 108: /* unaArith: '+' expression  */
#line 830 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}", (yyloc));
        (yyval.astnode)->context->operation = strdup("+");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6713 "bison.tab.c"
    break;

  case 109: /* unaArith: '-' expression  */
#line 835 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}", (yyloc));
        (yyval.astnode)->context->operation = strdup("-");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6723 "bison.tab.c"
    break;

  case 110: /* unaArith: EXCLAMATION_TOKEN error  */
#line 841 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6732 "bison.tab.c"
    break;

  case 111: /* unaArith: QUESTION_TOKEN error  */
#line 845 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6741 "bison.tab.c"
    break;

  case 112: /* unaArith: PERCENTAGE_TOKEN error  */
#line 849 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6750 "bison.tab.c"
    break;

  case 113: /* unaArith: '+' error  */
#line 853 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6759 "bison.tab.c"
    break;

  case 114: /* unaArith: '-' error  */
#line 857 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6768 "bison.tab.c"
    break;

  case 115: /* constant: constantInteger  */
#line 864 "./src/bison.y"
                    {
        // $$ = create_astnode_context(AST_CONSTANT, "constant int", @$);
        // $$->context->dtype = DTYPE_INT;
        // insert_kid($1, $$);
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6779 "bison.tab.c"
    break;

  case 116: /* constant: constantReal  */
#line 870 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6787 "bison.tab.c"
    break;

  case 117: /* constant: constantNIL  */
#line 873 "./src/bison.y"
                  {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6795 "bison.tab.c"
    break;

  case 118: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 879 "./src/bison.y"
                           {
        (yyvsp[0].astnode)->context->dtype = DTYPE_INT;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6804 "bison.tab.c"
    break;

  case 119: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 886 "./src/bison.y"
                        {
        (yyvsp[0].astnode)->context->dtype = DTYPE_FLOAT;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6813 "bison.tab.c"
    break;

  case 120: /* constantNIL: NIL_TOKEN  */
#line 893 "./src/bison.y"
              {
        (yyvsp[0].astnode)->context->dtype = DTYPE_LIST;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6822 "bison.tab.c"
    break;

  case 121: /* $@4: %empty  */
#line 900 "./src/bison.y"
       {
       Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        } else {
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
        }
    }
#line 6835 "bison.tab.c"
    break;

  case 122: /* funcCall: id $@4 '(' optListExpression ')'  */
#line 907 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        if((yyvsp[-1].list)){
            AstNode *arguments = create_astnode_context(AST_CODE_BLOCK, "arguments", (yylsp[-1]));

            while((yyvsp[-1].list)->size) {
                AstNode *aux = remove_first_element_list((yyvsp[-1].list));
                insert_kid(aux, arguments);
            }
            delete_list((yyvsp[-1].list), delete_list_astnode);
            insert_kid(arguments, (yyval.astnode));
        }
    }
#line 6854 "bison.tab.c"
    break;

  case 123: /* ioCommand: READ_TOKEN '(' id ')' ';'  */
#line 924 "./src/bison.y"
                              {
        Symbol *has_sym = lookup_symbol((yyvsp[-2].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[-2].astnode)->context->name, (yylsp[-2]).first_line, (yylsp[-2]).first_column);
            (yyval.astnode) = NULL;
        } else {
            (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "read call", (yyloc));
            insert_kid((yyvsp[-4].astnode), (yyval.astnode));
            (yyvsp[-2].astnode)->context->sym_ref = has_sym;
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        }
    }
#line 6871 "bison.tab.c"
    break;

  case 124: /* ioCommand: WRITE_TOKEN '(' expression ')' ';'  */
#line 936 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "write call", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
    }
#line 6881 "bison.tab.c"
    break;

  case 125: /* ioCommand: WRITE_TOKEN '(' STRING_TOKEN ')' ';'  */
#line 941 "./src/bison.y"
                                           {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "write call", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
    }
#line 6891 "bison.tab.c"
    break;

  case 126: /* ioCommand: WRITE_TOKEN '(' error ')' ';'  */
#line 948 "./src/bison.y"
                                    {
       SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
       delete_astnode((yyvsp[-4].astnode));
       (yyval.astnode) = NULL;
    }
#line 6901 "bison.tab.c"
    break;

  case 127: /* ioCommand: READ_TOKEN '(' error ')' ';'  */
#line 955 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        (yyval.astnode) = NULL;
    }
#line 6911 "bison.tab.c"
    break;

  case 128: /* ioCommand: READ_TOKEN error ';'  */
#line 960 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected '(' token after 'read' || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6921 "bison.tab.c"
    break;

  case 129: /* ioCommand: WRITE_TOKEN error ';'  */
#line 965 "./src/bison.y"
                            {
        SHOW_SYNTAX_ERROR("expected '(' token after 'write' || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6931 "bison.tab.c"
    break;

  case 130: /* optListExpression: %empty  */
#line 973 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 6939 "bison.tab.c"
    break;

  case 132: /* listExpression: listExpression ',' expression  */
#line 980 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 6948 "bison.tab.c"
    break;

  case 133: /* listExpression: expression  */
#line 984 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 6957 "bison.tab.c"
    break;

  case 134: /* id: ID_TOKEN  */
#line 991 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6965 "bison.tab.c"
    break;

  case 135: /* type: INT_TOKEN  */
#line 997 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT, (yyvsp[0].string), (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_INT;
        free((yyvsp[0].string));
    }
#line 6975 "bison.tab.c"
    break;

  case 136: /* type: FLOAT_TOKEN  */
#line 1002 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT, (yyvsp[0].string), (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_FLOAT;
        free((yyvsp[0].string));
    }
#line 6985 "bison.tab.c"
    break;

  case 137: /* type: INT_TOKEN LIST_TOKEN  */
#line 1007 "./src/bison.y"
                           {
        char *str = (char *) calloc((strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 10), sizeof(char));
        strcat(str, (yyvsp[-1].string));
        strcat(str, " ");
        strcat(str, (yyvsp[0].string));
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT_LIST, str, (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_INT_LIST;
        free(str);
        free((yyvsp[-1].string));
        free((yyvsp[0].string));
    }
#line 7001 "bison.tab.c"
    break;

  case 138: /* type: FLOAT_TOKEN LIST_TOKEN  */
#line 1018 "./src/bison.y"
                             {
        char *str = (char *) calloc((strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 10), sizeof(char));
        strcat(str, (yyvsp[-1].string));
        strcat(str, " ");
        strcat(str, (yyvsp[0].string));
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT_LIST, str, (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_FLOAT_LIST;
        free(str);
        free((yyvsp[-1].string));
        free((yyvsp[0].string));
    }
#line 7017 "bison.tab.c"
    break;


#line 7021 "bison.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1031 "./src/bison.y"


void yyerror(const char *error_msg){
    // if (error_msg) {
    //     printf(RED"Line: %d || Column: %d || "RESET, num_line, num_col);
    //     printf(RED"Error: %s || Error count: %d \n"RESET, error_msg, error);
    // }

    if(!error_msg)
        erros++;
}

/* 
*   O primeiro node ja deleta os nodes subsequentes, 
*   assim nao eh necessario deletar os elementos da lista. 
*/
void delete_single_node(Element *node){
    if(!node)
        return;
}

void delete_tree_symbol_table(void *sym){
    SymbolTable *table = sym;
    delete_symbol_table(table, delete_list_symbol_table);
}

void delete_list_treenode(Element *elem){
    TreeNode *node = elem->value;
    delete_node(node, delete_single_node, delete_tree_symbol_table);
}

int main(int argc, char **argv){
    if(argc < 2){
        printf(RED"Error: It is necessary to inform the file path\n"RESET);
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        printf(RED"Error: Unable to open file\n"RESET);
        return 0;
    }

    yyin = fp;
    root = create_astnode_context(AST_ROOT, "root", yylloc);
    node_aux = create_list();

    list_context = create_list();
    insert_list_element(list_context, create_node(create_symbol_table()));
    global_context = list_context->first->value;
    current_context = global_context;

    yyparse();

    Symbol *sym_main = lookup_symbol("main", current_context);
    /* Verifica se existe main na tabela de simbolos */
    if(sym_main){
        if(!sym_main->isfunction) {
            SEMANTIC_ERROR("main is not a function\n");
        } else {
            AstNode *main = lookup_node(root, "main");
            AstNode *father = main->father;
            AstNode *params = lookup_node(father, "params");
            Element *it;
            int has_int = 0;
            for(it = father->kids->first; it != NULL; it = it->next){
                if(!strcmp(((AstNode *) it->value)->context->name, "int")){
                    has_int = 1;
                }
            }
            if(!has_int)
                SEMANTIC_ERROR("return type of 'main' is not 'int'\n");
            if(params)
                SEMANTIC_ERROR("'main' takes only zero arguments\n");
        }
    } else {
        SEMANTIC_ERROR("undefined reference to function main\n");
    }

    sem_eval(root);

    if(root->kids->size > 0) {
        printf("\n##################### %s #####################\n", "Abstract Syntax Tree");
        print_tree(root, 0);
        printf("\n");
    } else 
        printf(RED"AST error: " RESET "unable to print AST\n");

    Element *iterator;
    /* TODO: Arrumar if */
    if(((SymbolTable *)((TreeNode *) list_context->first->value)->value)->symbols->size > 0){
        for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
            if(((SymbolTable *)((TreeNode *)iterator->value)->value)->symbols->size > 0) {
                printf("########################## %s #########################\n", "Symbol Table");
                printf("# %-14s || %11s || %-10s || %4s || %6s #\n", "Type", "Symbol Kind", "ID", "Line", "Column");
                print_list(((SymbolTable *)((TreeNode *)iterator->value)->value)->symbols, print_symbol_list);
                printf("#################################################################\n");
            }
        }
    } else 
        printf(RED"Symbol Table error: " RESET "unable to print symbol table\n");

    if(erros > 0)
        printf(RED"Error count: "RESET"%d\n", erros);
    else {
        FILE *output = fopen("teste.tac", "w+");
        code_gen(root, output);
        fclose(output);
    }

    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_list(list_context, delete_list_treenode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
