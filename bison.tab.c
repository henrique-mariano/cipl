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

    // extern int num_line, num_col;

    int erros = 0;

    int semantic_error = 0;

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

#line 116 "bison.tab.c"

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
  YYSYMBOL_88_5 = 88,                      /* @5  */
  YYSYMBOL_optListExpression = 89,         /* optListExpression  */
  YYSYMBOL_listExpression = 90,            /* listExpression  */
  YYSYMBOL_id = 91,                        /* id  */
  YYSYMBOL_type = 92                       /* type  */
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
#define YYLAST   17515

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  677

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
       0,   131,   131,   135,   139,   145,   148,   154,   157,   162,
     170,   191,   197,   204,   211,   220,   220,   279,   282,   286,
     290,   296,   303,   324,   330,   338,   338,   373,   376,   380,
     384,   391,   394,   399,   403,   406,   409,   412,   417,   422,
     429,   432,   435,   441,   446,   454,   460,   467,   474,   480,
     489,   495,   503,   515,   523,   531,   539,   546,   553,   558,
     565,   571,   578,   581,   587,   590,   593,   596,   599,   602,
     605,   616,   623,   632,   632,   648,   654,   660,   666,   672,
     678,   684,   690,   696,   702,   708,   714,   721,   726,   731,
     736,   741,   746,   751,   756,   761,   766,   771,   776,   784,
     790,   796,   803,   808,   813,   821,   826,   831,   836,   841,
     847,   851,   855,   859,   863,   870,   876,   879,   885,   892,
     899,   906,   906,   931,   931,   945,   950,   957,   963,   970,
     975,   980,   985,   993,   996,  1000,  1004,  1011,  1017,  1022,
    1027,  1038
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
  "$@4", "ioCommand", "@5", "optListExpression", "listExpression", "id",
  "type", YY_NULLPTR
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

#define YYPACT_NINF (-506)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-142)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6385,    14,   141,   173,  7982,    18,    23, 15608, 15639, 15670,
    2377,  2492,  2847,    26,    27,  3202,  3557,  3912,  4267,   118,
      20,  6401,  6447,  6463,  6509,  6525,  6571,  6587,  6633,  6649,
     -21, 15701, 15732, 15763, 15794, 15825, 15856, 15887, 15918, 15949,
   15980,  6695,  8014,   103,  6711,   147,   223,   -15,   117,    73,
     551, 16011,  1987, 16042,  2632, 16073, 16104, 16135, 16166,  6757,
    4677,  6773,   999,   135, 16197, 16228, 16259, 16290, 16321,   172,
   13397,   649,  -506,   232,  6819,  6835,  8062,  8073,  8084,  8124,
    8135,  8146,  8186,  8197,  8208,  8248,  8259,  8270,  8310,  8321,
    8332,  6881, 16352,   230,   194,   140,  6897,    -7,  6943,   220,
     225,  6959,   261,   265, 13430,   267, 13463,    67,   242, 16383,
    7005, 16414,   134,  7885,  1416,   144,  1658,  1717,  1771,  2013,
     228, 16445, 16476, 16507, 16538, 16569, 16600, 16631, 16662, 16693,
   16724, 16755, 16786, 16817, 16848, 16879, 16910, 16941, 16972, 17003,
   17034, 17065, 17096, 17127, 17158, 17189, 17220, 17251, 17282, 17313,
   17344,  2023,   778,   322,  7021,   330,  7067,    42,  2075,   269,
    2366,  7083,  7129,  7702,  7748,  1632,  7145,  1064,  7885,  2126,
    7191,  2427,   148, 17375,  3342,   285,   238,  7207,  7253,    50,
    7269,  7315,  7331,  7931,  2481,  7931,  2723,   166,   200,   295,
    2782, 17406,  2192,   255,   309,   257,   259,   272,   195,  7377,
    7931,  7393,  7931,  1837,  7931,  1837,  7931,    24,  3697,   318,
       3,   313,  7439,  7455,   311,  7501,   324,  7517,   325,   326,
    7563,   315,  7931,  7931,  7931,  7931,  7579,  7625,  7641,  7687,
    2987,  1922, 13496, 13529, 13562,  8372,  8383,  8394,  8434,  8445,
    1987, 13595, 13628, 13661, 13694, 13727, 13760, 13793, 13826, 13859,
    2277,   196,    16,   328,  8456,  8496,  8507,  8518,  8558,  8569,
    8580,  8620,  8631,  8642,  8682,  8693,  8704,  8744,  8755,    46,
      48,    54,    69,  8766,   118,  2836,  3078,  3137,  3191,   332,
   17437,  3433,  8014,  3492,   334,  3546,   854,  4052,  4407,  9680,
    8806,  8817,  8828,  8868,  8879,  1987,  9714,  9748,  9782,  9816,
    9850,  9884,  9918,  9952,  9986,  1122,   336,    94,   129,   138,
     142,  8890,   118,  3788,  3850,  4143,  4205,   337, 17468,  4479,
    1211, 11516, 11549, 11582,  8930,  8941,  8952,  8992,  9003,  1987,
   11615, 11648, 11681, 11714, 11747, 11780, 11813, 11846, 11879, 11912,
    1568,   370,  3901,  9014,  9054,  9065,  9076,  9116,  9127,  9138,
    9178,  9189,  9200,  9240,  9251,  9262,  9302,  9313,   149,   169,
     317, 13892, 13925, 13958, 13991, 14024, 14057, 14090, 14123, 14156,
   14189, 14222, 14255, 14288,   366,   339, 14321, 14354, 14387, 14420,
   14453, 14486, 14519, 14552, 14585, 14618, 14651, 14684, 14717, 14750,
   14783, 14816, 14849, 14882, 14915, 14948, 14981, 15014, 15047, 15080,
   15113, 15146, 15179, 15212, 15245, 15278,   341,   183,   342,   716,
    4256,  9324,  4494,  1281,   343,   649,  4557,  4611,   231, 10020,
   10054, 10088, 10122, 10156, 10190, 10224, 10258, 10292, 10326, 15311,
   10360,   373,   346,  4631,   348,   240,   349,   819,  4699,  9364,
    4765,  1480,   353,   649,  4781,  4827, 11945, 11978, 12011, 12044,
   12077, 12110, 12143, 12176, 12209, 12242, 15344,  9375,  9386,  9426,
    9437,  9448,  9488,  9499,  9510,  9550,  9561,  9572,  9612,  9623,
    9634,  9674, 12275,   377,   355,  4842, 10394, 10428, 10462, 10496,
   10530, 10564, 10598, 10632, 10666, 10700, 10734, 10768, 10802, 10836,
   10870, 10904, 10938, 10972, 11006, 11040, 11074, 11108, 11142, 11176,
   11210, 11244, 11278, 11312, 11346, 11380,   203,   222, 15377,  1987,
     778,  4894,   356,   225,  4909,   358,   359, 15410,   365, 15443,
     233,   357,  4961,   363,   415,  4976, 11414,  2192,   778,  5029,
     368,   225,  5045,   369,   371, 15476,   372, 15509,   236,   375,
    5091,   367, 12308, 12341, 12374, 12407, 12440, 12473, 12506, 12539,
   12572, 12605, 12638, 12671, 12704, 12737, 12770, 12803, 12836, 12869,
   12902, 12935, 12968, 13001, 13034, 13067, 13100, 13133, 13166, 13199,
   13232, 13265, 13298,  2228,   778, 15542,   374,    97,   376,  1053,
    5106,  5158,  7763,  7809,  1632,  5173,  1782,  5225,  5240, 11448,
     379,  1303,   381,  1365,  5293,  5309,  7824,  7870,  1632,  5355,
    2137,  5371, 13331,   383, 15575,  5417,  5432,  5484,  7885,  5499,
    7885,  5551,   237,   250,   387, 11482,  5567,  5613,  5629,  7946,
    5675,  7946,  5691,   253,   254,   388, 13364,  5737,  7885,  5752,
    7885,  1837,  7885,  1837,  7885,   671,  5805,  7946,  5821,  7946,
    1837,  7946,  1837,  7946,   988,  5867,  5882,   389,  5934,   391,
    5949,   393,   394,  6002,  6018,   395,  6064,   396,  6080,   397,
     398,  7885,  7885,  7885,  7885,  7946,  7946,  7946,  7946,  6126,
    6141,  6193,  6208,  6261,  6277,  6323,  6339
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
       0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -506,  -506,  -506,   403,    44,  -506,  -506,  -506,  -506,   216,
       8,  -270,  -384,  -506,   338,   113,   176,   227,  -506,   312,
     320,   165,     0,  1280,  -248,  1635,  1990,  2345,  2700,  3055,
    3410,  3765,  4120,  -247,   385,  -416,  -505,  -506,   924,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,   114,    24,   179,   194,   195,   196,
     275,    71,   115,   116,   117,   118,   276,   277,   119,   278,
     279,   108,   280,    32,    93,    33,    34,    35,    36,    37,
      38,    39,    40,    94,   281,   159,   175,   176,    54,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    43,   374,   375,   415,   576,   358,   359,    25,   360,
      53,    56,    58,   155,    -3,    64,    66,    68,    70,    47,
      72,    31,    43,   590,    49,   218,    75,    59,    61,    25,
     231,   523,    98,   232,   233,   234,  -137,   235,   236,   237,
     156,   157,   443,   -15,    23,   -15,   -15,   406,   -15,   408,
     104,   193,    70,   358,   359,   410,   360,   431,   432,   541,
     106,    44,   109,  -137,  -137,    23,    48,   238,   239,   603,
     412,    50,   240,   -62,    60,    62,   122,   124,   126,   128,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   -15,   473,   474,   407,   434,   409,   578,  -129,   -17,
    -129,  -129,   411,  -129,  -129,  -129,  -129,  -129,  -129,   252,
    -129,  -129,  -129,    26,   165,   592,   166,   413,    99,   -25,
     101,   -25,   -25,   253,   -25,   -25,   -25,   -25,   -25,   -25,
     436,   -25,   -25,   -25,    26,  -129,  -129,  -129,  -129,   438,
    -129,  -129,   435,   440,   605,  -129,    45,  -138,  -129,  -129,
      96,   173,   174,  -140,   506,  -138,   -25,   -25,   -25,   -25,
     153,   -25,   -25,   318,   318,   330,   -25,   109,   341,   -25,
     -25,   313,   313,   168,   507,  -139,    27,   437,    46,  -139,
     198,   283,   -61,    31,   512,    31,   439,   154,  -138,   253,
     441,    25,   208,    25,  -140,   342,   170,    27,  -138,  -138,
      31,   360,    31,   361,    31,   361,    31,   361,    25,  -140,
      25,   198,    25,   203,    25,   204,  -137,   220,  -139,  -139,
    -139,   110,    31,    31,    31,    31,   169,    28,  -141,  -141,
      25,    25,    25,    25,   251,   363,   365,   367,   369,   371,
     372,   530,   152,  -137,   -23,   -23,   253,   205,    28,   206,
     151,   524,  -140,  -140,   377,   379,   381,   383,   385,   387,
     389,   391,   393,   395,   397,   399,   401,   403,   405,   158,
    -141,  -141,  -141,    70,  -123,   285,   184,   186,   525,    44,
     584,   190,   585,   598,   631,   599,   632,  -134,   192,   167,
     420,   422,   424,   426,   428,   429,   199,   633,   201,   634,
     640,   642,   641,   643,   -21,   -21,   -18,   210,   -20,   -20,
     160,    70,    29,   212,   161,   213,   163,   215,   181,   217,
      30,   -24,   -24,   177,   447,   449,   451,   453,   455,   456,
     187,   178,   189,    29,   191,   226,   227,   228,   229,   314,
     314,    30,   207,   477,   479,   481,   483,   485,   487,   489,
     491,   493,   495,   497,   499,   501,   503,   505,   209,    27,
     222,    27,   -22,   -22,   -19,   -19,  -137,  -137,   214,    19,
     216,   475,   219,   223,   224,   225,    27,  -137,    27,   416,
      27,   283,    27,   433,   444,    41,   509,   510,   511,   514,
     315,   315,   522,   527,   528,   529,   532,   573,    27,    27,
      27,    27,   540,   574,   586,   577,    41,   579,   580,   517,
      28,   519,    28,   109,   582,   587,   588,   591,   593,   601,
     594,   596,   600,   604,    74,   606,   221,    28,   615,    28,
     617,    28,   626,    28,   635,   644,     0,   535,   661,   537,
     662,   109,   663,   664,   665,   666,   667,   668,     0,    28,
      28,    28,    28,     0,   171,     0,     0,   544,   546,   548,
     550,   552,   554,   556,   558,   560,   562,   564,   566,   568,
     570,   572,     0,     0,     0,   316,   316,     0,     0,     0,
       0,     0,     0,   317,   317,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,    29,     0,     0,
       0,     0,     0,    30,     0,    30,     0,     0,     0,   575,
     174,     0,    29,     0,    29,     0,    29,     0,    29,     0,
      30,     0,    30,     0,    30,     0,    30,   589,   174,     0,
       0,     0,     0,     0,    29,    29,    29,    29,     0,     0,
       0,     0,    30,    30,    30,    30,     0,     0,   319,   319,
       0,     0,   102,     0,     0,     0,     0,   231,     0,     0,
     232,   233,   234,     0,   235,   236,   237,     0,    41,     0,
      41,     0,     0,   602,   174,     0,     0,     0,   521,     0,
       0,     0,     0,     0,   330,    41,   109,    41,     0,    41,
       0,    41,     0,   103,   238,   239,   318,   318,   330,   240,
     109,     0,     0,     0,   313,   313,   539,    41,    41,    41,
      41,     0,     0,     0,     0,     0,     0,     0,     0,   318,
       0,   318,     0,     0,     0,     0,     0,   313,     0,   313,
       0,   361,     0,   361,     0,   361,     0,   318,     0,   318,
     361,   318,   361,   318,   361,   313,     0,   313,     0,   313,
     112,   313,     2,     3,     0,     4,   269,   270,     7,     8,
       9,     0,    10,    11,    12,   318,   318,   318,   318,     0,
       0,     0,   651,   313,   313,   313,   313,   231,     0,     0,
     232,   233,   234,     0,   235,   236,   237,   271,   113,   272,
      15,     0,    16,    17,     0,   609,   611,   273,     0,     0,
     274,   -27,     0,     0,     0,     0,     0,     0,     0,   620,
     622,     0,     0,     0,   238,   239,     0,   515,     0,   240,
     -62,   627,   231,   629,     0,   232,   233,   234,     0,   235,
     236,   237,   636,     0,   638,     0,     0,     0,     0,     0,
       0,   645,     0,   646,     0,   648,     0,   650,     0,   612,
     653,   614,   654,     0,   656,     0,   658,     0,   516,   238,
     239,     0,     0,   623,   240,   625,     0,     0,     0,     0,
       0,     0,   314,   314,   669,   670,   671,   672,   673,   674,
     675,   676,     0,     0,   286,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,   314,   647,   314,   649,     0,
     652,     0,     0,     0,     0,   655,     0,   657,     0,   660,
       0,     0,     0,   314,     0,   314,     0,   314,     0,   314,
     533,   293,   294,   315,   315,   231,   295,  -133,   232,   233,
     234,     0,   235,   236,   237,     0,     0,     0,     0,     0,
       0,   314,   314,   314,   314,     0,   315,     0,   315,     0,
       0,     0,     0,     0,     0,  -137,     0,     0,     0,     0,
       0,   534,   238,   239,   315,     0,   315,   240,   315,     0,
     315,  -137,  -137,  -137,  -137,  -137,  -137,     0,     0,     0,
       0,  -137,  -137,  -137,  -137,  -137,  -137,     0,     0,     0,
       0,     0,   315,   315,   315,   315,     0,  -137,  -137,  -137,
    -137,     0,  -137,  -137,  -137,     0,     0,     0,   316,   316,
       0,     0,     0,     0,     0,     0,   317,   317,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   316,     0,   316,     0,     0,     0,     0,     0,   317,
       0,   317,   250,     0,     0,    42,     0,     0,     0,   316,
       0,   316,     0,   316,     0,   316,     0,   317,     0,   317,
       0,   317,     0,   317,     0,     0,    95,    97,     0,     0,
       0,     0,   100,     0,   250,     0,   250,   316,   316,   316,
     316,   319,   319,     0,   250,   317,   317,   317,   317,   659,
       0,     0,     0,     0,   231,   282,     0,   232,   233,   234,
     107,   235,   236,   237,   319,   230,   319,     0,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,   319,     0,   319,     0,   319,     0,   319,     0,
       0,   238,   239,     0,     0,     0,   240,   -62,     0,     0,
     282,     0,    16,    17,   172,     0,   -62,    52,     0,     0,
     319,   319,   319,   319,  -127,     0,  -127,  -127,     0,  -127,
    -127,  -127,  -127,  -127,  -127,   188,  -127,  -127,  -127,     0,
     230,     0,     0,     7,     8,     9,   305,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   340,
       0,  -127,  -127,  -127,  -127,     0,  -127,  -127,     0,     0,
     607,  -127,     0,   197,  -127,  -127,     0,    16,    17,     0,
       0,   -62,    52,     0,     0,     0,   305,     0,     0,     0,
       0,     0,   211,   430,     0,     0,     0,   250,     0,   250,
       0,   250,     0,     0,   197,     0,     0,     0,     0,   -70,
     -70,   -70,   -73,   -70,   -70,     0,     0,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,   250,
     250,   250,   250,   250,   250,   -70,   -70,   -70,   -70,     0,
    -121,   -70,   -70,     0,     0,     0,     0,     0,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,     0,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,  -137,     0,   305,   305,   305,   305,   305,   250,
       0,     0,     0,     0,     0,     0,     0,     0,  -137,  -137,
    -137,  -137,  -137,  -137,     0,   250,     0,     0,  -137,  -137,
    -137,  -137,  -137,  -137,     0,     0,     0,     0,   340,   340,
     340,   340,   340,   250,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,     0,     0,     0,     0,     0,     0,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   520,     0,     0,     0,     0,   230,     0,     0,
       7,     8,     9,     0,    10,    11,    12,     0,   241,     0,
       0,     0,     0,  -129,  -129,     0,  -129,  -129,     0,  -129,
    -129,  -129,  -129,  -129,  -129,     0,  -129,  -129,  -129,     0,
       0,     0,     0,     0,    16,    17,     0,     0,   -62,    52,
     241,   513,   241,   250,     0,   250,     0,     0,     0,   282,
     241,  -129,  -129,  -129,  -129,     0,  -129,  -129,     0,     0,
     616,  -129,     0,     0,  -129,     0,     0,     0,     0,   531,
       0,   250,     0,   250,     0,  -127,  -127,   282,  -127,  -127,
       0,  -127,  -127,  -127,  -127,  -127,  -127,     0,  -127,  -127,
    -127,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,     0,     0,     0,     0,
       0,     0,     0,  -127,  -127,  -127,  -127,     0,  -127,  -127,
       0,     0,   618,  -127,     0,     0,  -127,   -32,     0,   -32,
     -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,
     -32,   -32,   296,   250,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   331,     0,     0,     0,     0,
       0,   305,   305,     0,   -32,   -32,   -32,   -32,     0,   -32,
     -32,     0,     0,     0,   -32,     0,     0,   -32,   -32,     0,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,   538,     0,   241,     0,   241,   230,   241,     0,     7,
       8,     9,     0,    10,    11,    12,     0,   340,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   340,     0,
       0,     0,     0,     0,     0,   241,   241,   241,   241,   241,
     241,     0,   340,    16,    17,     0,     0,   -62,    52,     0,
       0,     0,     0,     0,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,     0,
       0,     0,     0,   241,     0,   250,     0,   250,     0,   250,
       0,     0,     0,     0,   250,     0,   250,     0,   250,   472,
     296,   296,   296,   296,   296,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -70,   -70,   -70,   -73,   -70,
     -70,   241,     0,     0,     0,   -70,   -70,   -70,   -70,   -70,
     -70,     0,     0,     0,   331,   331,   331,   331,   331,   241,
       0,   -70,   -70,   -70,   -70,   -70,  -121,   -70,     0,     0,
       0,     0,     0,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   320,     0,
       0,   321,   322,   323,     0,   324,   325,   326,     0,     0,
       0,     0,     0,   242,     0,     0,     0,     0,     0,   112,
       0,     2,     3,     0,     4,   269,   270,     7,     8,     9,
       0,    10,    11,    12,     0,   327,   328,     0,     0,   -62,
     329,   -62,     0,     0,     0,   242,     0,   242,     0,   241,
       0,   241,     0,     0,     0,   242,   271,   113,   272,    15,
       0,    16,    17,     0,     0,     0,   273,     0,     0,   274,
     -28,     0,     0,     0,     0,     0,     0,   241,   -30,   241,
     -30,   -30,     0,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,   -30,     0,     0,     0,     0,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,     0,     0,     0,   -30,   -30,   -30,   -30,     0,
     -30,   -30,     0,     0,     0,   -30,     0,     0,   -30,   -30,
       0,     0,   -31,     0,   -31,   -31,     0,   -31,   -31,   -31,
     -31,   -31,   -31,   613,   -31,   -31,   -31,   297,   230,   241,
     296,     7,     8,     9,     0,    10,    11,    12,     0,     0,
     332,     0,     0,     0,     0,     0,     0,   296,   296,   -31,
     -31,   -31,   -31,     0,   -31,   -31,     0,     0,     0,   -31,
       0,     0,   -31,   -31,     0,    16,    17,   297,     0,   -62,
      52,     0,     0,     0,     0,     0,     0,     0,   242,     0,
     242,     0,   242,   231,     0,     0,   232,   233,   234,     0,
     235,   236,   237,   331,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,     0,     0,
     242,   242,   242,   242,   242,   242,     0,     0,   331,     0,
     238,   239,     0,     0,     0,   240,   -62,     0,     0,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,     0,     0,     0,     0,   242,     0,
       0,   241,     0,   241,     0,   241,     0,     0,     0,     0,
     241,     0,   241,  -137,   241,   297,   297,   297,   297,   297,
     242,     0,     0,     0,     0,     0,     0,     0,     0,  -137,
    -137,  -137,  -137,  -137,  -137,     0,   242,     0,     0,  -137,
    -137,  -137,  -137,  -137,  -137,     0,     0,     0,     0,   332,
     332,   332,   332,   332,   242,  -137,  -137,  -137,  -137,     0,
    -137,  -137,     0,     0,     0,     0,     0,     0,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   231,     0,     0,   232,   233,   234,     0,
     235,   236,   237,     0,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,   -33,     0,   -33,   -33,     0,   -33,
     -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,   230,
     238,   239,     7,     8,     9,   240,    10,    11,    12,     0,
     243,     0,   243,     0,   242,     0,   242,     0,     0,     0,
     243,   -33,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,
       0,   -33,     0,     0,   -33,   -33,    16,    17,     0,     0,
       0,    52,   242,     0,   242,  -129,  -129,     0,  -129,  -129,
       0,  -129,  -129,  -129,  -129,  -129,  -129,     0,  -129,  -129,
    -129,     0,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,     0,     0,     0,
       0,     0,     0,  -129,     0,  -129,  -129,     0,  -129,  -129,
       0,     0,   180,  -129,     0,     0,  -129,   -50,     0,   -50,
     -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,   624,   -50,
     -50,   -50,   298,   230,   242,   297,     7,     8,     9,     0,
      10,    11,    12,     0,     0,   333,     0,     0,     0,     0,
       0,     0,   297,   297,   -50,   -50,   -50,   -50,     0,   -50,
     -50,     0,     0,     0,   -50,     0,     0,   -50,   -50,     0,
      16,    17,   298,     0,   -62,    52,     0,     0,     0,     0,
       0,     0,     0,   243,     0,   243,     0,   243,   286,     0,
       0,   287,   288,   289,     0,   290,   291,   292,   332,   297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   332,
       0,     0,     0,     0,     0,   243,   243,   243,   243,   243,
     243,     0,     0,   332,   320,   293,   294,   321,   322,   323,
     295,   324,   325,   326,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,     0,
       0,     0,     0,   243,     0,     0,   242,     0,   242,     0,
     242,   327,   328,     0,     0,   242,   329,   242,   373,   242,
     298,   298,   298,   298,   298,   243,     0,     0,     0,     0,
       0,     0,     0,     0,   -70,   -70,   -70,   -73,   -70,   -70,
       0,   243,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,     0,     0,   333,   333,   333,   333,   333,   243,
     -70,   -70,   -70,   -70,     0,  -121,   -70,     0,     0,     0,
       0,     0,     0,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,     0,     0,  -127,  -127,     0,  -127,
    -127,     0,  -127,  -127,  -127,  -127,  -127,  -127,    51,  -127,
    -127,  -127,     0,   230,     0,     0,     7,     8,     9,     0,
      10,    11,    12,     0,     0,   244,     0,   244,     0,   243,
       0,   243,     0,     0,  -127,   244,  -127,  -127,     0,  -127,
    -127,     0,     0,   182,  -127,     0,     0,  -127,     0,     0,
      16,    17,     0,     0,     0,    52,     0,   243,   -29,   243,
     -29,   -29,     0,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,   -29,   -29,     0,     0,     0,     0,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,     0,     0,     0,   -29,   -29,   -29,   -29,     0,
     -29,   -29,     0,     0,     0,   -29,     0,     0,   -29,   -29,
       0,   -45,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,
     -45,   -45,   -45,    55,   -45,   -45,   -45,   299,   230,   243,
     298,     7,     8,     9,     0,    10,    11,    12,     0,     0,
     334,     0,     0,     0,     0,     0,     0,   298,   298,   -45,
     200,   -45,   -45,     0,   -45,   -45,     0,     0,     0,   -45,
       0,     0,   -45,     0,     0,    16,    17,   299,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,   244,     0,
     244,     0,   244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   333,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,     0,
     244,   244,   244,   244,   244,   244,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,     0,     0,     0,     0,   244,     0,
       0,   243,     0,   243,     0,   243,     0,     0,     0,     0,
     243,     0,   243,    92,   243,   299,   299,   299,   299,   299,
     244,     0,     0,     0,     0,     0,     0,     0,     0,   -70,
     -70,   -70,   -73,   -70,   -70,     0,   244,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,   334,
     334,   334,   334,   334,   244,   -70,   -70,   -70,   -70,   -70,
    -121,     0,     0,     0,     0,     0,     0,     0,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,   -43,   -43,     0,   -43,   -43,     0,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,     0,   245,     0,   244,     0,   244,     0,     0,     0,
     245,   -43,   202,   -43,   -43,     0,   -43,   -43,     0,     0,
       0,   -43,     0,     0,   -43,     0,     0,     0,     0,     0,
       0,     0,   244,   -51,   244,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,     0,     0,
       0,     0,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,     0,     0,     0,
     -51,   -51,   -51,   -51,     0,   -51,   -51,     0,     0,     0,
     -51,     0,     0,   -51,   -51,     0,     0,   -35,     0,   -35,
     -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,    57,   -35,
     -35,   -35,   300,   230,   244,   299,     7,     8,     9,     0,
      10,    11,    12,     0,     0,   335,     0,     0,     0,     0,
       0,     0,   299,   299,   -35,   -35,   -35,   -35,     0,   -35,
     -35,     0,     0,     0,   -35,     0,     0,   -35,   -35,     0,
      16,    17,   300,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,   245,     0,   245,     0,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   334,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,   245,   245,   245,   245,   245,
     245,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,     0,
       0,     0,     0,   245,     0,     0,   244,     0,   244,     0,
     244,     0,     0,     0,     0,   244,     0,   244,  -137,   244,
     300,   300,   300,   300,   300,   245,     0,     0,     0,     0,
       0,     0,     0,     0,  -137,  -137,  -137,  -137,  -137,  -137,
       0,   245,     0,     0,  -137,  -137,  -137,  -137,  -137,  -137,
       0,     0,     0,     0,   335,   335,   335,   335,   335,   245,
    -137,  -137,  -137,  -137,  -137,  -137,     0,     0,     0,     0,
       0,     0,     0,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,     0,     0,     0,     0,     0,   -34,
       0,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,
       0,   -34,   -34,   -34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,   246,     0,   245,
       0,   245,     0,     0,     0,   246,   -34,   -34,   -34,   -34,
       0,   -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,
     -34,     0,     0,     0,     0,     0,     0,   245,   -40,   245,
     -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,     0,     0,     0,     0,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,     0,     0,     0,   -40,   -40,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,   -40,
       0,     0,   -41,     0,   -41,   -41,     0,   -41,   -41,   -41,
     -41,   -41,   -41,    63,   -41,   -41,   -41,   301,   230,   245,
     300,     7,     8,     9,     0,    10,    11,    12,     0,     0,
     336,     0,     0,     0,     0,     0,     0,   300,   300,   -41,
     -41,   -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,
       0,     0,   -41,   -41,     0,    16,    17,   301,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,   246,     0,
     246,     0,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   335,   300,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   335,     0,     0,     0,     0,     0,
     246,   246,   246,   246,   246,   246,     0,     0,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,     0,     0,     0,     0,   246,     0,
       0,   245,     0,   245,     0,   245,     0,     0,     0,     0,
     245,     0,   245,     0,   245,   301,   301,   301,   301,   301,
     246,     0,     0,     0,     0,     0,     0,     0,     0,   343,
     344,   345,     0,   346,   347,     0,   246,     0,     0,   348,
     349,   350,   351,   352,   353,     0,     0,     0,     0,   336,
     336,   336,   336,   336,   246,   354,   355,   356,   357,     0,
       0,  -136,  -136,     0,     0,     0,     0,     0,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,     0,
       0,     0,     0,     0,   -37,     0,   -37,   -37,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,     0,   247,     0,   246,     0,   246,     0,     0,     0,
     247,   -37,   -37,   -37,   -37,     0,   -37,   -37,     0,     0,
       0,   -37,     0,     0,   -37,   -37,     0,     0,     0,     0,
       0,     0,   246,   -38,   246,   -38,   -38,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,     0,     0,
       0,     0,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,     0,     0,     0,
     -38,   -38,   -38,   -38,     0,   -38,   -38,     0,     0,     0,
     -38,     0,     0,   -38,   -38,     0,     0,   -11,     0,   -11,
     -11,     0,   -11,   -11,   -11,   -11,   -11,   -11,    65,   -11,
     -11,   -11,   302,   230,   246,   301,     7,     8,     9,     0,
      10,    11,    12,     0,     0,   337,     0,     0,     0,     0,
       0,     0,   301,   301,   -11,   -11,   -11,   -11,     0,   -11,
     -11,     0,     0,     0,   -11,     0,     0,   -11,   -11,     0,
      16,    17,   302,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,   247,     0,   247,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,     0,     0,     0,   247,   247,   247,   247,   247,
     247,     0,     0,   336,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,     0,
       0,     0,     0,   247,     0,     0,   246,     0,   246,     0,
     246,     0,     0,     0,     0,   246,     0,   246,     0,   246,
     302,   302,   302,   302,   302,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   343,   344,   345,     0,   346,   347,
       0,   247,     0,     0,   348,   349,   350,   351,   352,   353,
       0,     0,     0,     0,   337,   337,   337,   337,   337,   247,
     354,   355,   356,   357,     0,     0,  -135,  -135,     0,     0,
       0,     0,     0,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,     0,     0,     0,     0,   -35,   -35,
       0,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,     0,   248,     0,   247,
       0,   247,     0,     0,     0,   248,   -35,   -35,   -35,   -35,
       0,   -35,   -35,     0,     0,     0,   -35,     0,     0,   -35,
       0,     0,     0,     0,     0,     0,     0,   247,     0,   247,
     -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,   -34,   -34,     0,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,     0,     0,     0,     0,     0,     0,   -34,   -34,
     -34,   -34,     0,   -34,   -34,     0,     0,     0,   -34,     0,
       0,   -34,   -10,     0,   -10,   -10,     0,   -10,   -10,   -10,
     -10,   -10,   -10,    67,   -10,   -10,   -10,   303,   230,   247,
     302,     7,     8,     9,     0,    10,    11,    12,     0,     0,
     338,     0,     0,     0,     0,     0,     0,   302,   302,   -10,
     -10,   -10,   -10,     0,   -10,   -10,     0,     0,     0,   -10,
       0,     0,   -10,   -10,     0,    16,    17,   303,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,   248,     0,
     248,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   337,   302,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   337,     0,     0,     0,     0,     0,
     248,   248,   248,   248,   248,   248,     0,     0,   337,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,     0,     0,     0,     0,   248,     0,
       0,   247,     0,   247,     0,   247,     0,     0,     0,     0,
     247,     0,   247,     0,   247,   303,   303,   303,   303,   303,
     248,     0,     0,     0,     0,     0,     0,     0,     0,  -120,
    -120,  -120,     0,  -120,  -120,     0,   248,     0,     0,  -120,
    -120,  -120,  -120,  -120,  -120,     0,     0,     0,     0,   338,
     338,   338,   338,   338,   248,  -120,  -120,  -120,  -120,     0,
       0,  -120,  -120,     0,     0,     0,     0,     0,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,     0,
       0,     0,     0,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,   249,     0,   248,     0,   248,     0,     0,     0,
     249,   -40,   -40,   -40,   -40,     0,   -40,   -40,     0,     0,
       0,   -40,     0,     0,   -40,     0,     0,     0,     0,     0,
       0,     0,   248,     0,   248,   -41,   -41,     0,   -41,   -41,
       0,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,   -41,
     -41,     0,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,     0,     0,     0,
       0,     0,     0,   -41,   -41,   -41,   -41,     0,   -41,   -41,
       0,     0,     0,   -41,     0,     0,   -41,   -49,     0,   -49,
     -49,     0,   -49,   -49,   -49,   -49,   -49,   -49,    69,   -49,
     -49,   -49,   304,   231,   248,   303,   232,   233,   234,     0,
     235,   236,   237,     0,     0,   339,     0,     0,     0,     0,
       0,     0,   303,   303,   -49,   -49,   -49,   -49,     0,   -49,
     -49,     0,     0,     0,   -49,     0,     0,   -49,   -49,     0,
     238,   239,   304,     0,     0,   240,     0,     0,     0,     0,
       0,     0,     0,   249,     0,   249,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,     0,     0,     0,     0,   249,   249,   249,   249,   249,
     249,     0,     0,   338,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,     0,
       0,     0,     0,   249,     0,     0,   248,     0,   248,     0,
     248,     0,     0,     0,     0,   248,     0,   248,     0,   248,
     304,   304,   304,   304,   304,   249,     0,     0,     0,     0,
       0,     0,     0,     0,  -119,  -119,  -119,     0,  -119,  -119,
       0,   249,     0,     0,  -119,  -119,  -119,  -119,  -119,  -119,
       0,     0,     0,     0,   339,   339,   339,   339,   339,   249,
    -119,  -119,  -119,  -119,     0,     0,  -119,  -119,     0,     0,
       0,     0,     0,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,     0,   -37,
     -37,     0,   -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -37,   -37,   -59,     0,   -59,   -59,     0,
     -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,   -59,
       0,     0,     0,     0,     0,     0,     0,   -37,   -37,   -37,
     -37,     0,   -37,   -37,     0,     0,     0,   -37,     0,   249,
     -37,   249,   -59,   -59,   -59,   -59,     0,   -59,   -59,     0,
       0,     0,   -59,     0,     0,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   -42,   249,
     -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,
     -42,   -42,   -42,     0,     0,     0,     0,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,     0,     0,     0,   -42,   -42,   -42,   -42,     0,
     -42,   -42,     0,     0,     0,   -42,     0,     0,   -42,   -42,
       0,     0,   -36,     0,   -36,   -36,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,   -36,   -36,     0,     0,   249,
     304,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   -38,   304,   304,   -36,
     -36,   -36,   -36,     0,   -36,   -36,     0,     0,     0,   -36,
       0,     0,   -36,   -36,     0,     0,     0,     0,     0,   -38,
     -38,   -38,   -38,     0,   -38,   -38,     0,     0,   105,   -38,
       0,     0,   -38,   231,     0,     0,   232,   233,   234,     0,
     235,   236,   237,   339,   304,     0,     0,     0,     0,   -49,
     -49,     0,   -49,   -49,   339,   -49,   -49,   -49,   -49,   -49,
     -49,     0,   -49,   -49,   -49,     0,     0,     0,   339,     0,
     238,   239,     0,     0,     0,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -49,   -49,   -49,
     -49,     0,   -49,   -49,     0,     0,     0,   -49,     0,     0,
     -49,   249,     0,   249,     0,   249,     0,     0,     0,     0,
     249,     0,   249,     0,   249,   -59,   -59,     0,   -59,   -59,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,
     -59,   -42,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -42,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,   -59,     0,   -59,   -59,
       0,     0,     0,   -59,     0,     0,   -59,     0,     0,   -42,
     -42,   -42,   -42,     0,   -42,   -42,     0,   -36,   -36,   -42,
     -36,   -36,   -42,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,   -36,   -36,   -12,     0,   -12,   -12,     0,   -12,   -12,
     -12,   -12,   -12,   -12,     0,   -12,   -12,   -12,     0,     0,
       0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,     0,
     -36,   -36,     0,     0,     0,   -36,     0,     0,   -36,     0,
     -12,   -12,   -12,   -12,     0,   -12,   -12,     0,     0,     0,
     -12,     0,     0,   -12,   -12,  -131,     0,  -131,  -131,     0,
    -131,  -131,  -131,  -131,  -131,  -131,     0,  -131,  -131,  -131,
    -132,     0,  -132,  -132,     0,  -132,  -132,  -132,  -132,  -132,
    -132,     0,  -132,  -132,  -132,     0,     0,     0,     0,     0,
       0,     0,  -131,  -131,  -131,  -131,     0,  -131,  -131,     0,
       0,     0,  -131,     0,     0,  -131,  -131,  -132,  -132,  -132,
    -132,     0,  -132,  -132,     0,     0,     0,  -132,     0,     0,
    -132,  -132,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,   -39,   -39,   -39,   -14,     0,   -14,
     -14,     0,   -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,
     -14,   -14,     0,     0,     0,     0,     0,     0,     0,   -39,
     -39,   -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,
       0,     0,   -39,   -39,   -14,   -14,   -14,   -14,     0,   -14,
     -14,     0,     0,     0,   -14,     0,     0,   -14,   -14,  -131,
    -131,     0,  -131,  -131,     0,  -131,  -131,  -131,  -131,  -131,
    -131,     0,  -131,  -131,  -131,  -132,  -132,     0,  -132,  -132,
       0,  -132,  -132,  -132,  -132,  -132,  -132,     0,  -132,  -132,
    -132,     0,     0,     0,     0,     0,     0,  -131,  -131,  -131,
    -131,     0,  -131,  -131,     0,     0,     0,  -131,     0,     0,
    -131,     0,     0,  -132,  -132,  -132,  -132,     0,  -132,  -132,
       0,   -39,   -39,  -132,   -39,   -39,  -132,   -39,   -39,   -39,
     -39,   -39,   -39,     0,   -39,   -39,   -39,  -126,     0,  -126,
    -126,     0,  -126,  -126,  -126,  -126,  -126,  -126,     0,  -126,
    -126,  -126,     0,     0,     0,     0,     0,     0,     0,   -39,
     -39,   -39,   -39,     0,   -39,   -39,     0,     0,     0,   -39,
       0,     0,   -39,     0,  -126,  -126,  -126,  -126,     0,  -126,
    -126,     0,     0,     0,  -126,     0,     0,  -126,  -126,  -125,
       0,  -125,  -125,     0,  -125,  -125,  -125,  -125,  -125,  -125,
       0,  -125,  -125,  -125,   -58,     0,   -58,   -58,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,   -58,     0,
       0,     0,     0,     0,     0,     0,  -125,  -125,  -125,  -125,
       0,  -125,  -125,     0,     0,     0,  -125,     0,     0,  -125,
    -125,   -58,   -58,   -58,   -58,     0,   -58,   -58,     0,     0,
       0,   -58,     0,     0,   -58,   -58,   -26,     0,   -26,   -26,
       0,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   -13,     0,   -13,   -13,     0,   -13,   -13,   -13,   -13,
     -13,   -13,     0,   -13,   -13,   -13,     0,     0,     0,     0,
       0,     0,     0,   -26,   -26,   -26,   -26,     0,   -26,   -26,
       0,     0,     0,   -26,     0,     0,   -26,   -26,   -13,   -13,
     -13,   -13,     0,   -13,   -13,     0,     0,     0,   -13,     0,
       0,   -13,   -13,  -126,  -126,     0,  -126,  -126,     0,  -126,
    -126,  -126,  -126,  -126,  -126,     0,  -126,  -126,  -126,  -125,
    -125,     0,  -125,  -125,     0,  -125,  -125,  -125,  -125,  -125,
    -125,     0,  -125,  -125,  -125,     0,     0,     0,     0,     0,
       0,  -126,  -126,  -126,  -126,     0,  -126,  -126,     0,     0,
       0,  -126,     0,     0,  -126,     0,     0,  -125,  -125,  -125,
    -125,     0,  -125,  -125,     0,   -58,   -58,  -125,   -58,   -58,
    -125,   -58,   -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,
     -58,   -26,   -26,     0,   -26,   -26,     0,   -26,   -26,   -26,
     -26,   -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,
       0,     0,     0,   -58,   -58,   -58,   -58,     0,   -58,   -58,
       0,     0,     0,   -58,     0,     0,   -58,     0,     0,   -26,
     -26,   -26,   -26,     0,   -26,   -26,     0,     0,  -130,   -26,
    -130,  -130,   -26,  -130,  -130,  -130,  -130,  -130,  -130,     0,
    -130,  -130,  -130,  -124,     0,  -124,  -124,     0,  -124,  -124,
    -124,  -124,  -124,  -124,     0,  -124,  -124,  -124,     0,     0,
       0,     0,     0,     0,     0,  -130,  -130,  -130,  -130,     0,
    -130,  -130,     0,     0,     0,  -130,     0,     0,  -130,  -130,
    -124,  -124,  -124,  -124,     0,  -124,  -124,     0,     0,     0,
    -124,     0,     0,  -124,  -124,  -128,     0,  -128,  -128,     0,
    -128,  -128,  -128,  -128,  -128,  -128,     0,  -128,  -128,  -128,
     -45,     0,   -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,     0,     0,     0,     0,     0,
       0,     0,  -128,  -128,  -128,  -128,     0,  -128,  -128,     0,
       0,     0,  -128,     0,     0,  -128,  -128,   -45,   628,   -45,
     -45,     0,   -45,   -45,     0,     0,     0,   -45,     0,     0,
     -45,   -45,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -43,  -130,  -130,     0,
    -130,  -130,     0,  -130,  -130,  -130,  -130,  -130,  -130,     0,
    -130,  -130,  -130,     0,     0,     0,     0,     0,     0,   -43,
     630,   -43,   -43,     0,   -43,   -43,     0,     0,     0,   -43,
       0,     0,   -43,   -43,     0,  -130,  -130,  -130,  -130,     0,
    -130,  -130,     0,  -124,  -124,  -130,  -124,  -124,  -130,  -124,
    -124,  -124,  -124,  -124,  -124,     0,  -124,  -124,  -124,  -128,
    -128,     0,  -128,  -128,     0,  -128,  -128,  -128,  -128,  -128,
    -128,     0,  -128,  -128,  -128,     0,     0,     0,     0,     0,
       0,  -124,  -124,  -124,  -124,     0,  -124,  -124,     0,     0,
       0,  -124,     0,     0,  -124,     0,     0,  -128,  -128,  -128,
    -128,     0,  -128,  -128,     0,   -45,   -45,  -128,   -45,   -45,
    -128,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,
     -45,   -43,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -43,     0,     0,     0,
       0,     0,     0,   -45,   637,   -45,   -45,     0,   -45,   -45,
       0,     0,     0,   -45,     0,     0,   -45,     0,     0,   -43,
     639,   -43,   -43,     0,   -43,   -43,     0,     0,   -48,   -43,
     -48,   -48,   -43,   -48,   -48,   -48,   -48,   -48,   -48,     0,
     -48,   -48,   -48,   -47,     0,   -47,   -47,     0,   -47,   -47,
     -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,     0,     0,
       0,     0,     0,     0,     0,   -48,   -48,   -48,   -48,     0,
     -48,   -48,     0,     0,     0,   -48,     0,     0,   -48,   -48,
     -47,   -47,   -47,   -47,     0,   -47,   -47,     0,     0,     0,
     -47,     0,     0,   -47,   -47,   -48,   -48,     0,   -48,   -48,
       0,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -48,   -47,   -47,     0,   -47,   -47,     0,   -47,   -47,   -47,
     -47,   -47,   -47,     0,   -47,   -47,   -47,     0,     0,     0,
       0,     0,     0,   -48,   -48,   -48,   -48,     0,   -48,   -48,
       0,     0,     0,   -48,     0,     0,   -48,     0,     0,   -47,
     -47,   -47,   -47,     0,   -47,   -47,     0,     0,   -46,   -47,
     -46,   -46,   -47,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,   -46,   -44,     0,   -44,   -44,     0,   -44,   -44,
     -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,     0,     0,
       0,     0,     0,     0,     0,   -46,   -46,   -46,   -46,     0,
     -46,   -46,     0,     0,     0,   -46,     0,     0,   -46,   -46,
     -44,   -44,   -44,   -44,     0,   -44,   -44,     0,     0,     0,
     -44,     0,     0,   -44,   -44,   -56,     0,   -56,   -56,     0,
     -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,
     -57,     0,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,
     -57,     0,   -57,   -57,   -57,     0,     0,     0,     0,     0,
       0,     0,   -56,   -56,   -56,   -56,     0,   -56,   -56,     0,
       0,     0,   -56,     0,     0,   -56,   -56,   -57,   -57,   -57,
     -57,     0,   -57,   -57,     0,     0,     0,   -57,     0,     0,
     -57,   -57,   -46,   -46,     0,   -46,   -46,     0,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -44,   -44,
       0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,     0,     0,     0,     0,     0,     0,
     -46,   -46,   -46,   -46,     0,   -46,   -46,     0,     0,     0,
     -46,     0,     0,   -46,     0,     0,   -44,   -44,   -44,   -44,
       0,   -44,   -44,     0,   -56,   -56,   -44,   -56,   -56,   -44,
     -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,
     -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,   -57,
     -57,   -57,     0,   -57,   -57,   -57,     0,     0,     0,     0,
       0,     0,   -56,   -56,   -56,   -56,     0,   -56,   -56,     0,
       0,     0,   -56,     0,     0,   -56,     0,     0,   -57,   -57,
     -57,   -57,     0,   -57,   -57,     0,     0,   -53,   -57,   -53,
     -53,   -57,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,
     -53,   -53,   -54,     0,   -54,   -54,     0,   -54,   -54,   -54,
     -54,   -54,   -54,     0,   -54,   -54,   -54,     0,     0,     0,
       0,     0,     0,     0,   -53,   -53,   -53,   -53,     0,   -53,
     -53,     0,     0,     0,   -53,     0,     0,   -53,   -53,   -54,
     -54,   -54,   -54,     0,   -54,   -54,     0,     0,     0,   -54,
       0,     0,   -54,   -54,   -55,     0,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -52,
       0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   -52,     0,     0,     0,     0,     0,     0,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,
       0,   -55,     0,     0,   -55,   -55,   -52,   -52,   -52,   -52,
       0,   -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,
     -52,   -53,   -53,     0,   -53,   -53,     0,   -53,   -53,   -53,
     -53,   -53,   -53,     0,   -53,   -53,   -53,   -54,   -54,     0,
     -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,
     -54,   -54,   -54,     0,     0,     0,     0,     0,     0,   -53,
     -53,   -53,   -53,     0,   -53,   -53,     0,     0,     0,   -53,
       0,     0,   -53,     0,     0,   -54,   -54,   -54,   -54,     0,
     -54,   -54,     0,   -55,   -55,   -54,   -55,   -55,   -54,   -55,
     -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -52,
     -52,     0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,
     -52,     0,   -52,   -52,   -52,     0,     0,     0,     0,     0,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,     0,
       0,   -55,     0,     0,   -55,     0,     0,   -52,   -52,   -52,
     -52,     0,   -52,   -52,     0,    -4,     1,   -52,     2,     3,
     -52,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    -2,    73,     0,     2,     3,     0,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,     0,    13,     0,    14,    15,     0,    16,    17,
       0,     0,     0,    18,     0,     0,    19,     0,     0,    13,
       0,    14,    15,     0,    16,    17,     0,    -6,    -6,    18,
      -6,    -6,    19,    -6,    -6,    -6,    -6,    -6,    -6,     0,
      -6,    -6,    -6,    -7,    -7,     0,    -7,    -7,     0,    -7,
      -7,    -7,    -7,    -7,    -7,     0,    -7,    -7,    -7,     0,
       0,     0,     0,     0,     0,    -6,     0,    -6,    -6,     0,
      -6,    -6,     0,     0,     0,    -6,     0,     0,    -6,     0,
       0,    -7,     0,    -7,    -7,     0,    -7,    -7,     0,    -8,
      -8,    -7,    -8,    -8,    -7,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,    -8,    -8,   -35,   -35,     0,   -35,   -35,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,
     -35,     0,     0,     0,     0,     0,     0,    -8,     0,    -8,
      -8,     0,    -8,    -8,     0,     0,     0,    -8,     0,     0,
      -8,     0,     0,   -35,     0,   -35,   -35,     0,   -35,   -35,
       0,    -9,    -9,   -35,    -9,    -9,   -35,    -9,    -9,    -9,
      -9,    -9,    -9,     0,    -9,    -9,    -9,   -34,   -34,     0,
     -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,   -34,   -34,     0,     0,     0,     0,     0,     0,    -9,
       0,    -9,    -9,     0,    -9,    -9,     0,     0,     0,    -9,
       0,     0,    -9,     0,     0,   -34,     0,   -34,   -34,     0,
     -34,   -34,     0,   -40,   -40,   -34,   -40,   -40,   -34,   -40,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -41,
     -41,     0,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   -41,   -41,   -41,     0,     0,     0,     0,     0,
       0,   -40,     0,   -40,   -40,     0,   -40,   -40,     0,     0,
       0,   -40,     0,     0,   -40,     0,     0,   -41,     0,   -41,
     -41,     0,   -41,   -41,     0,   -37,   -37,   -41,   -37,   -37,
     -41,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,
     -37,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   -38,     0,     0,     0,
       0,     0,     0,   -37,     0,   -37,   -37,     0,   -37,   -37,
       0,     0,     0,   -37,     0,     0,   -37,     0,     0,   -38,
       0,   -38,   -38,     0,   -38,   -38,     0,   -49,   -49,   -38,
     -49,   -49,   -38,   -49,   -49,   -49,   -49,   -49,   -49,     0,
     -49,   -49,   -49,   -59,   -59,     0,   -59,   -59,     0,   -59,
     -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,   -59,     0,
       0,     0,     0,     0,     0,   -49,     0,   -49,   -49,     0,
     -49,   -49,     0,     0,     0,   -49,     0,     0,   -49,     0,
       0,   -59,     0,   -59,   -59,     0,   -59,   -59,     0,    -5,
      -5,   -59,    -5,    -5,   -59,    -5,    -5,    -5,    -5,    -5,
      -5,     0,    -5,    -5,    -5,   -42,   -42,     0,   -42,   -42,
       0,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,
     -42,     0,     0,     0,     0,     0,     0,    -5,     0,    -5,
      -5,     0,    -5,    -5,     0,     0,     0,    -5,     0,     0,
      -5,     0,     0,   -42,     0,   -42,   -42,     0,   -42,   -42,
       0,   -36,   -36,   -42,   -36,   -36,   -42,   -36,   -36,   -36,
     -36,   -36,   -36,     0,   -36,   -36,   -36,   -11,   -11,     0,
     -11,   -11,     0,   -11,   -11,   -11,   -11,   -11,   -11,     0,
     -11,   -11,   -11,     0,     0,     0,     0,     0,     0,   -36,
       0,   -36,   -36,     0,   -36,   -36,     0,     0,     0,   -36,
       0,     0,   -36,     0,     0,   -11,     0,   -11,   -11,     0,
     -11,   -11,     0,  -131,  -131,   -11,  -131,  -131,   -11,  -131,
    -131,  -131,  -131,  -131,  -131,     0,  -131,  -131,  -131,  -132,
    -132,     0,  -132,  -132,     0,  -132,  -132,  -132,  -132,  -132,
    -132,     0,  -132,  -132,  -132,     0,     0,     0,     0,     0,
       0,  -131,     0,  -131,  -131,     0,  -131,  -131,     0,     0,
       0,  -131,     0,     0,  -131,     0,     0,  -132,     0,  -132,
    -132,     0,  -132,  -132,     0,   -39,   -39,  -132,   -39,   -39,
    -132,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,
     -39,   -14,   -14,     0,   -14,   -14,     0,   -14,   -14,   -14,
     -14,   -14,   -14,     0,   -14,   -14,   -14,     0,     0,     0,
       0,     0,     0,   -39,     0,   -39,   -39,     0,   -39,   -39,
       0,     0,     0,   -39,     0,     0,   -39,     0,     0,   -14,
       0,   -14,   -14,     0,   -14,   -14,     0,   -10,   -10,   -14,
     -10,   -10,   -14,   -10,   -10,   -10,   -10,   -10,   -10,     0,
     -10,   -10,   -10,  -126,  -126,     0,  -126,  -126,     0,  -126,
    -126,  -126,  -126,  -126,  -126,     0,  -126,  -126,  -126,     0,
       0,     0,     0,     0,     0,   -10,     0,   -10,   -10,     0,
     -10,   -10,     0,     0,     0,   -10,     0,     0,   -10,     0,
       0,  -126,     0,  -126,  -126,     0,  -126,  -126,     0,  -125,
    -125,  -126,  -125,  -125,  -126,  -125,  -125,  -125,  -125,  -125,
    -125,     0,  -125,  -125,  -125,   -58,   -58,     0,   -58,   -58,
       0,   -58,   -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,
     -58,     0,     0,     0,     0,     0,     0,  -125,     0,  -125,
    -125,     0,  -125,  -125,     0,     0,     0,  -125,     0,     0,
    -125,     0,     0,   -58,     0,   -58,   -58,     0,   -58,   -58,
       0,   -26,   -26,   -58,   -26,   -26,   -58,   -26,   -26,   -26,
     -26,   -26,   -26,     0,   -26,   -26,   -26,   -13,   -13,     0,
     -13,   -13,     0,   -13,   -13,   -13,   -13,   -13,   -13,     0,
     -13,   -13,   -13,     0,     0,     0,     0,     0,     0,   -26,
       0,   -26,   -26,     0,   -26,   -26,     0,     0,     0,   -26,
       0,     0,   -26,     0,     0,   -13,     0,   -13,   -13,     0,
     -13,   -13,     0,   -12,   -12,   -13,   -12,   -12,   -13,   -12,
     -12,   -12,   -12,   -12,   -12,     0,   -12,   -12,   -12,  -130,
    -130,     0,  -130,  -130,     0,  -130,  -130,  -130,  -130,  -130,
    -130,     0,  -130,  -130,  -130,     0,     0,     0,     0,     0,
       0,   -12,     0,   -12,   -12,     0,   -12,   -12,     0,     0,
       0,   -12,     0,     0,   -12,     0,     0,  -130,     0,  -130,
    -130,     0,  -130,  -130,     0,  -124,  -124,  -130,  -124,  -124,
    -130,  -124,  -124,  -124,  -124,  -124,  -124,     0,  -124,  -124,
    -124,  -128,  -128,     0,  -128,  -128,     0,  -128,  -128,  -128,
    -128,  -128,  -128,     0,  -128,  -128,  -128,     0,     0,     0,
       0,     0,     0,  -124,     0,  -124,  -124,     0,  -124,  -124,
       0,     0,     0,  -124,     0,     0,  -124,     0,     0,  -128,
       0,  -128,  -128,     0,  -128,  -128,     0,   -48,   -48,  -128,
     -48,   -48,  -128,   -48,   -48,   -48,   -48,   -48,   -48,     0,
     -48,   -48,   -48,   -47,   -47,     0,   -47,   -47,     0,   -47,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,     0,
       0,     0,     0,     0,     0,   -48,     0,   -48,   -48,     0,
     -48,   -48,     0,     0,     0,   -48,     0,     0,   -48,     0,
       0,   -47,     0,   -47,   -47,     0,   -47,   -47,     0,   -46,
     -46,   -47,   -46,   -46,   -47,   -46,   -46,   -46,   -46,   -46,
     -46,     0,   -46,   -46,   -46,   -44,   -44,     0,   -44,   -44,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,
     -44,     0,     0,     0,     0,     0,     0,   -46,     0,   -46,
     -46,     0,   -46,   -46,     0,     0,     0,   -46,     0,     0,
     -46,     0,     0,   -44,     0,   -44,   -44,     0,   -44,   -44,
       0,   -56,   -56,   -44,   -56,   -56,   -44,   -56,   -56,   -56,
     -56,   -56,   -56,     0,   -56,   -56,   -56,   -57,   -57,     0,
     -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,     0,
     -57,   -57,   -57,     0,     0,     0,     0,     0,     0,   -56,
       0,   -56,   -56,     0,   -56,   -56,     0,     0,     0,   -56,
       0,     0,   -56,     0,     0,   -57,     0,   -57,   -57,     0,
     -57,   -57,     0,   -16,   -16,   -57,   -16,   -16,   -57,   -16,
     -16,   -16,   -16,   -16,   -16,     0,   -16,   -16,   -16,   -53,
     -53,     0,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,
     -53,     0,   -53,   -53,   -53,     0,     0,     0,     0,     0,
       0,   -16,     0,   -16,   -16,     0,   -16,   -16,     0,     0,
       0,   -16,     0,     0,   -16,     0,     0,   -53,     0,   -53,
     -53,     0,   -53,   -53,     0,   -54,   -54,   -53,   -54,   -54,
     -53,   -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,
     -54,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,   -55,
     -55,   -55,   -55,     0,   -55,   -55,   -55,     0,     0,     0,
       0,     0,     0,   -54,     0,   -54,   -54,     0,   -54,   -54,
       0,     0,     0,   -54,     0,     0,   -54,     0,     0,   -55,
       0,   -55,   -55,     0,   -55,   -55,     0,   -52,   -52,   -55,
     -52,   -52,   -55,   -52,   -52,   -52,   -52,   -52,   -52,     0,
     -52,   -52,   -52,   306,     0,     0,     0,     0,   230,   307,
     308,     7,     8,     9,     0,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,   -52,     0,   -52,   -52,     0,
     -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,     0,
     309,   183,   310,    15,     0,    16,    17,     0,     0,   306,
     311,     0,     0,   312,   230,   307,   308,     7,     8,     9,
       0,    10,    11,    12,   284,     0,     0,     0,     0,   230,
     269,   270,     7,     8,     9,     0,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,   309,   185,   310,    15,
       0,    16,    17,     0,     0,     0,   311,     0,     0,   312,
       0,   271,   608,   272,    15,     0,    16,    17,     0,     0,
     284,   273,     0,     0,   274,   230,   269,   270,     7,     8,
       9,     0,    10,    11,    12,   306,     0,     0,     0,     0,
     230,   307,   308,     7,     8,     9,     0,    10,    11,    12,
       0,     0,     0,     0,     0,     0,     0,   271,   610,   272,
      15,     0,    16,    17,     0,     0,     0,   273,     0,     0,
     274,     0,   309,   619,   310,    15,     0,    16,    17,     0,
       0,   306,   311,     0,     0,   312,   230,   307,   308,     7,
       8,     9,     0,    10,    11,    12,   284,     0,     0,     0,
       0,   230,   269,   270,     7,     8,     9,     0,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,   309,   621,
     310,    15,     0,    16,    17,     0,     0,     0,   311,     0,
       0,   312,     0,   271,     0,   272,    15,     0,    16,    17,
       0,     0,    73,   273,     0,     0,   274,   230,     5,     6,
       7,     8,     9,     0,    10,    11,    12,   306,     0,     0,
       0,     0,   230,   307,   308,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    15,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,  -137,   309,     0,   310,    15,  -137,    16,
      17,     0,     0,     0,   311,     0,     0,   312,     0,  -137,
    -137,  -137,  -137,  -137,  -137,     0,     0,     0,     0,  -137,
    -137,  -137,  -137,  -137,  -137,    92,     0,     0,     0,     0,
     251,     0,     0,     0,     0,  -137,  -137,  -137,  -137,  -137,
    -137,   -70,   -70,   -70,   -73,   -70,   -70,     0,     0,     0,
       0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -70,   -70,   -70,
     -70,   -70,  -121,   121,     0,     0,     0,     0,   230,     0,
       0,     7,     8,     9,   123,    10,    11,    12,     0,   230,
       0,     0,     7,     8,     9,   125,    10,    11,    12,     0,
     230,     0,     0,     7,     8,     9,     0,    10,    11,    12,
       0,     0,     0,     0,     0,    16,    17,     0,     0,     0,
      52,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,    52,     0,     0,     0,   127,     0,    16,    17,     0,
     230,     0,    52,     7,     8,     9,   129,    10,    11,    12,
       0,   230,     0,     0,     7,     8,     9,   131,    10,    11,
      12,     0,   230,     0,     0,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,    16,    17,     0,
       0,     0,    52,     0,     0,     0,     0,     0,    16,    17,
       0,     0,     0,    52,     0,     0,     0,   133,     0,    16,
      17,     0,   230,     0,    52,     7,     8,     9,   135,    10,
      11,    12,     0,   230,     0,     0,     7,     8,     9,   137,
      10,    11,    12,     0,   230,     0,     0,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,    52,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,    52,     0,     0,     0,   139,
       0,    16,    17,     0,   230,     0,    52,     7,     8,     9,
     141,    10,    11,    12,     0,   230,     0,     0,     7,     8,
       9,   143,    10,    11,    12,     0,   230,     0,     0,     7,
       8,     9,     0,    10,    11,    12,     0,     0,     0,     0,
       0,    16,    17,     0,     0,     0,    52,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,    52,     0,     0,
       0,   145,     0,    16,    17,     0,   230,     0,    52,     7,
       8,     9,   147,    10,    11,    12,     0,   230,     0,     0,
       7,     8,     9,   149,    10,    11,    12,     0,   230,     0,
       0,     7,     8,     9,     0,    10,    11,    12,     0,     0,
       0,     0,     0,    16,    17,     0,     0,     0,    52,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     0,    52,
       0,     0,     0,   362,     0,    16,    17,     0,   231,     0,
      52,   232,   233,   234,   364,   235,   236,   237,     0,   231,
       0,     0,   232,   233,   234,   366,   235,   236,   237,     0,
     231,     0,     0,   232,   233,   234,     0,   235,   236,   237,
       0,     0,     0,     0,     0,   238,   239,     0,     0,     0,
     240,     0,     0,     0,     0,     0,   238,   239,     0,     0,
       0,   240,     0,     0,     0,   368,     0,   238,   239,     0,
     231,     0,   240,   232,   233,   234,   370,   235,   236,   237,
       0,   231,     0,     0,   232,   233,   234,   376,   235,   236,
     237,     0,   231,     0,     0,   232,   233,   234,     0,   235,
     236,   237,     0,     0,     0,     0,     0,   238,   239,     0,
       0,     0,   240,     0,     0,     0,     0,     0,   238,   239,
       0,     0,     0,   240,     0,     0,     0,   378,     0,   238,
     239,     0,   231,     0,   240,   232,   233,   234,   380,   235,
     236,   237,     0,   231,     0,     0,   232,   233,   234,   382,
     235,   236,   237,     0,   231,     0,     0,   232,   233,   234,
       0,   235,   236,   237,     0,     0,     0,     0,     0,   238,
     239,     0,     0,     0,   240,     0,     0,     0,     0,     0,
     238,   239,     0,     0,     0,   240,     0,     0,     0,   384,
       0,   238,   239,     0,   231,     0,   240,   232,   233,   234,
     386,   235,   236,   237,     0,   231,     0,     0,   232,   233,
     234,   388,   235,   236,   237,     0,   231,     0,     0,   232,
     233,   234,     0,   235,   236,   237,     0,     0,     0,     0,
       0,   238,   239,     0,     0,     0,   240,     0,     0,     0,
       0,     0,   238,   239,     0,     0,     0,   240,     0,     0,
       0,   390,     0,   238,   239,     0,   231,     0,   240,   232,
     233,   234,   392,   235,   236,   237,     0,   231,     0,     0,
     232,   233,   234,   394,   235,   236,   237,     0,   231,     0,
       0,   232,   233,   234,     0,   235,   236,   237,     0,     0,
       0,     0,     0,   238,   239,     0,     0,     0,   240,     0,
       0,     0,     0,     0,   238,   239,     0,     0,     0,   240,
       0,     0,     0,   396,     0,   238,   239,     0,   231,     0,
     240,   232,   233,   234,   398,   235,   236,   237,     0,   231,
       0,     0,   232,   233,   234,   400,   235,   236,   237,     0,
     231,     0,     0,   232,   233,   234,     0,   235,   236,   237,
       0,     0,     0,     0,     0,   238,   239,     0,     0,     0,
     240,     0,     0,     0,     0,     0,   238,   239,     0,     0,
       0,   240,     0,     0,     0,   402,     0,   238,   239,     0,
     231,     0,   240,   232,   233,   234,   404,   235,   236,   237,
       0,   231,     0,     0,   232,   233,   234,   414,   235,   236,
     237,     0,   231,     0,     0,   232,   233,   234,     0,   235,
     236,   237,     0,     0,     0,     0,     0,   238,   239,     0,
       0,     0,   240,     0,     0,     0,     0,     0,   238,   239,
       0,     0,     0,   240,     0,     0,     0,   419,     0,   238,
     239,     0,   286,     0,   240,   287,   288,   289,   421,   290,
     291,   292,     0,   286,     0,     0,   287,   288,   289,   423,
     290,   291,   292,     0,   286,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,     0,     0,     0,     0,   293,
     294,     0,     0,     0,   295,     0,     0,     0,     0,     0,
     293,   294,     0,     0,     0,   295,     0,     0,     0,   425,
       0,   293,   294,     0,   286,     0,   295,   287,   288,   289,
     427,   290,   291,   292,     0,   286,     0,     0,   287,   288,
     289,   442,   290,   291,   292,     0,   231,     0,     0,   232,
     233,   234,     0,   235,   236,   237,     0,     0,     0,     0,
       0,   293,   294,     0,     0,     0,   295,     0,     0,     0,
       0,     0,   293,   294,     0,     0,     0,   295,     0,     0,
       0,   446,     0,   238,   239,     0,   320,     0,   240,   321,
     322,   323,   448,   324,   325,   326,     0,   320,     0,     0,
     321,   322,   323,   450,   324,   325,   326,     0,   320,     0,
       0,   321,   322,   323,     0,   324,   325,   326,     0,     0,
       0,     0,     0,   327,   328,     0,     0,     0,   329,     0,
       0,     0,     0,     0,   327,   328,     0,     0,     0,   329,
       0,     0,     0,   452,     0,   327,   328,     0,   320,     0,
     329,   321,   322,   323,   454,   324,   325,   326,     0,   320,
       0,     0,   321,   322,   323,   476,   324,   325,   326,     0,
     286,     0,     0,   287,   288,   289,     0,   290,   291,   292,
       0,     0,     0,     0,     0,   327,   328,     0,     0,     0,
     329,     0,     0,     0,     0,     0,   327,   328,     0,     0,
       0,   329,     0,     0,     0,   478,     0,   293,   294,     0,
     286,     0,   295,   287,   288,   289,   480,   290,   291,   292,
       0,   286,     0,     0,   287,   288,   289,   482,   290,   291,
     292,     0,   286,     0,     0,   287,   288,   289,     0,   290,
     291,   292,     0,     0,     0,     0,     0,   293,   294,     0,
       0,     0,   295,     0,     0,     0,     0,     0,   293,   294,
       0,     0,     0,   295,     0,     0,     0,   484,     0,   293,
     294,     0,   286,     0,   295,   287,   288,   289,   486,   290,
     291,   292,     0,   286,     0,     0,   287,   288,   289,   488,
     290,   291,   292,     0,   286,     0,     0,   287,   288,   289,
       0,   290,   291,   292,     0,     0,     0,     0,     0,   293,
     294,     0,     0,     0,   295,     0,     0,     0,     0,     0,
     293,   294,     0,     0,     0,   295,     0,     0,     0,   490,
       0,   293,   294,     0,   286,     0,   295,   287,   288,   289,
     492,   290,   291,   292,     0,   286,     0,     0,   287,   288,
     289,   494,   290,   291,   292,     0,   286,     0,     0,   287,
     288,   289,     0,   290,   291,   292,     0,     0,     0,     0,
       0,   293,   294,     0,     0,     0,   295,     0,     0,     0,
       0,     0,   293,   294,     0,     0,     0,   295,     0,     0,
       0,   496,     0,   293,   294,     0,   286,     0,   295,   287,
     288,   289,   498,   290,   291,   292,     0,   286,     0,     0,
     287,   288,   289,   500,   290,   291,   292,     0,   286,     0,
       0,   287,   288,   289,     0,   290,   291,   292,     0,     0,
       0,     0,     0,   293,   294,     0,     0,     0,   295,     0,
       0,     0,     0,     0,   293,   294,     0,     0,     0,   295,
       0,     0,     0,   502,     0,   293,   294,     0,   286,     0,
     295,   287,   288,   289,   504,   290,   291,   292,     0,   286,
       0,     0,   287,   288,   289,   518,   290,   291,   292,     0,
     231,     0,     0,   232,   233,   234,     0,   235,   236,   237,
       0,     0,     0,     0,     0,   293,   294,     0,     0,     0,
     295,     0,     0,     0,     0,     0,   293,   294,     0,     0,
       0,   295,     0,     0,     0,   536,     0,   238,   239,     0,
     231,     0,   240,   232,   233,   234,   543,   235,   236,   237,
       0,   320,     0,     0,   321,   322,   323,   545,   324,   325,
     326,     0,   320,     0,     0,   321,   322,   323,     0,   324,
     325,   326,     0,     0,     0,     0,     0,   238,   239,     0,
       0,     0,   240,     0,     0,     0,     0,     0,   327,   328,
       0,     0,     0,   329,     0,     0,     0,   547,     0,   327,
     328,     0,   320,     0,   329,   321,   322,   323,   549,   324,
     325,   326,     0,   320,     0,     0,   321,   322,   323,   551,
     324,   325,   326,     0,   320,     0,     0,   321,   322,   323,
       0,   324,   325,   326,     0,     0,     0,     0,     0,   327,
     328,     0,     0,     0,   329,     0,     0,     0,     0,     0,
     327,   328,     0,     0,     0,   329,     0,     0,     0,   553,
       0,   327,   328,     0,   320,     0,   329,   321,   322,   323,
     555,   324,   325,   326,     0,   320,     0,     0,   321,   322,
     323,   557,   324,   325,   326,     0,   320,     0,     0,   321,
     322,   323,     0,   324,   325,   326,     0,     0,     0,     0,
       0,   327,   328,     0,     0,     0,   329,     0,     0,     0,
       0,     0,   327,   328,     0,     0,     0,   329,     0,     0,
       0,   559,     0,   327,   328,     0,   320,     0,   329,   321,
     322,   323,   561,   324,   325,   326,     0,   320,     0,     0,
     321,   322,   323,   563,   324,   325,   326,     0,   320,     0,
       0,   321,   322,   323,     0,   324,   325,   326,     0,     0,
       0,     0,     0,   327,   328,     0,     0,     0,   329,     0,
       0,     0,     0,     0,   327,   328,     0,     0,     0,   329,
       0,     0,     0,   565,     0,   327,   328,     0,   320,     0,
     329,   321,   322,   323,   567,   324,   325,   326,     0,   320,
       0,     0,   321,   322,   323,   569,   324,   325,   326,     0,
     320,     0,     0,   321,   322,   323,     0,   324,   325,   326,
       0,     0,     0,     0,     0,   327,   328,     0,     0,     0,
     329,     0,     0,     0,     0,     0,   327,   328,     0,     0,
       0,   329,     0,     0,     0,   571,     0,   327,   328,     0,
     320,     0,   329,   321,   322,   323,     0,   324,   325,   326,
       0,     0,     0,     0,     0,     0,     0,  -118,  -118,  -118,
       0,  -118,  -118,     0,     0,     0,     0,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,     0,   327,   328,     0,
       0,     0,   329,  -118,  -118,  -118,  -118,     0,     0,  -118,
    -118,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,     0,
       0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -64,   -64,   -64,
     -64,     0,     0,   -64,   -64,   -65,   -65,   -65,     0,   -65,
     -65,     0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,
     -65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -65,   -65,   -65,   -65,     0,     0,   -65,   -65,   -66,
     -66,   -66,     0,   -66,   -66,     0,     0,     0,     0,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,   -66,     0,
       0,   -66,   -66,   -67,   -67,   -67,     0,   -67,   -67,     0,
       0,     0,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -67,
     -67,   -67,   -67,     0,     0,   -67,   -67,   -68,   -68,   -68,
       0,   -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,     0,     0,   -68,
     -68,  -115,  -115,  -115,     0,  -115,  -115,     0,     0,     0,
       0,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -115,  -115,  -115,
    -115,     0,     0,  -115,  -115,  -116,  -116,  -116,     0,  -116,
    -116,     0,     0,     0,     0,  -116,  -116,  -116,  -116,  -116,
    -116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -116,  -116,  -116,  -116,     0,     0,  -116,  -116,  -117,
    -117,  -117,     0,  -117,  -117,     0,     0,     0,     0,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -117,  -117,  -117,  -117,     0,
       0,  -117,  -117,   -69,   -69,   -69,     0,   -69,   -69,     0,
       0,     0,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,     0,     0,   -69,   -69,  -110,  -110,  -110,
       0,  -110,  -110,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,  -110,  -110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -110,  -110,  -110,  -110,     0,     0,  -110,
    -110,  -105,  -105,  -105,     0,  -105,  -105,     0,     0,     0,
       0,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -105,  -105,  -105,
    -105,     0,     0,  -105,  -105,  -111,  -111,  -111,     0,  -111,
    -111,     0,     0,     0,     0,  -111,  -111,  -111,  -111,  -111,
    -111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -111,  -111,  -111,  -111,     0,     0,  -111,  -111,  -106,
    -106,  -106,     0,  -106,  -106,     0,     0,     0,     0,  -106,
    -106,  -106,  -106,  -106,  -106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -106,  -106,  -106,  -106,     0,
       0,  -106,  -106,  -112,  -112,  -112,     0,  -112,  -112,     0,
       0,     0,     0,  -112,  -112,  -112,  -112,  -112,  -112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -112,
    -112,  -112,  -112,     0,     0,  -112,  -112,  -107,  -107,  -107,
       0,  -107,  -107,     0,     0,     0,     0,  -107,  -107,  -107,
    -107,  -107,  -107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -107,  -107,  -107,  -107,     0,     0,  -107,
    -107,  -113,  -113,  -113,     0,  -113,  -113,     0,     0,     0,
       0,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -113,  -113,  -113,
    -113,     0,     0,  -113,  -113,  -108,  -108,  -108,     0,  -108,
    -108,     0,     0,     0,     0,  -108,  -108,  -108,  -108,  -108,
    -108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -108,  -108,  -108,  -108,     0,     0,  -108,  -108,  -114,
    -114,  -114,     0,  -114,  -114,     0,     0,     0,     0,  -114,
    -114,  -114,  -114,  -114,  -114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -114,  -114,  -114,  -114,     0,
       0,  -114,  -114,  -109,  -109,  -109,     0,  -109,  -109,     0,
       0,     0,     0,  -109,  -109,  -109,  -109,  -109,  -109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -109,
    -109,  -109,  -109,     0,     0,  -109,  -109,   -72,   -72,   -72,
       0,   -72,   -72,     0,     0,     0,     0,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -72,   -72,   -72,   -72,     0,     0,   -72,
     -72,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -102,  -102,  -102,
    -102,     0,     0,  -102,  -102,   343,   344,   345,     0,   -99,
     -99,     0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,
     -99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   356,   357,     0,     0,   -99,   -99,  -103,
    -103,  -103,     0,  -103,  -103,     0,     0,     0,     0,  -103,
    -103,  -103,  -103,  -103,  -103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -103,  -103,  -103,  -103,     0,
       0,  -103,  -103,  -100,   344,   345,     0,  -100,  -100,     0,
       0,     0,     0,  -100,  -100,  -100,  -100,  -100,  -100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   354,
     355,   356,   357,     0,     0,  -100,  -100,  -104,  -104,  -104,
       0,  -104,  -104,     0,     0,     0,     0,  -104,  -104,  -104,
    -104,  -104,  -104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -104,  -104,  -104,  -104,     0,     0,  -104,
    -104,  -101,  -101,   345,     0,  -101,  -101,     0,     0,     0,
       0,  -101,  -101,  -101,  -101,  -101,  -101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   355,   356,
     357,     0,     0,  -101,  -101,   -87,   -87,   -87,     0,   -87,
     -87,     0,     0,     0,     0,   -87,   -87,   -87,   -87,   -87,
     -87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -87,   -87,   -87,   -87,     0,     0,   -87,   -87,   343,
     344,   345,     0,   -75,   347,     0,     0,     0,     0,   348,
     349,   350,   351,   352,   353,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,   355,   356,   357,     0,
       0,   -75,   -75,   -88,   -88,   -88,     0,   -88,   -88,     0,
       0,     0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -88,
     -88,   -88,   -88,     0,     0,   -88,   -88,   343,   344,   345,
       0,   -76,   -76,     0,     0,     0,     0,   348,   349,   350,
     351,   352,   353,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   354,   355,   356,   357,     0,     0,   -76,
     -76,   -89,   -89,   -89,     0,   -89,   -89,     0,     0,     0,
       0,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -89,   -89,   -89,
     -89,     0,     0,   -89,   -89,   343,   344,   345,     0,   -77,
     -77,     0,     0,     0,     0,   -77,   -77,   350,   351,   352,
     353,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   356,   357,     0,     0,   -77,   -77,   -90,
     -90,   -90,     0,   -90,   -90,     0,     0,     0,     0,   -90,
     -90,   -90,   -90,   -90,   -90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -90,   -90,   -90,   -90,     0,
       0,   -90,   -90,   343,   344,   345,     0,   -78,   -78,     0,
       0,     0,     0,   -78,   -78,   350,   351,   352,   353,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   354,
     355,   356,   357,     0,     0,   -78,   -78,   -91,   -91,   -91,
       0,   -91,   -91,     0,     0,     0,     0,   -91,   -91,   -91,
     -91,   -91,   -91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -91,   -91,   -91,   -91,     0,     0,   -91,
     -91,   343,   344,   345,     0,   -79,   -79,     0,     0,     0,
       0,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   355,   356,
     357,     0,     0,   -79,   -79,   -92,   -92,   -92,     0,   -92,
     -92,     0,     0,     0,     0,   -92,   -92,   -92,   -92,   -92,
     -92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -92,   -92,   -92,   -92,     0,     0,   -92,   -92,   343,
     344,   345,     0,   -80,   -80,     0,     0,     0,     0,   -80,
     -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,   355,   356,   357,     0,
       0,   -80,   -80,   -93,   -93,   -93,     0,   -93,   -93,     0,
       0,     0,     0,   -93,   -93,   -93,   -93,   -93,   -93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -93,
     -93,   -93,   -93,     0,     0,   -93,   -93,   343,   344,   345,
       0,   -81,   -81,     0,     0,     0,     0,   -81,   -81,   -81,
     -81,   -81,   -81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   354,   355,   356,   357,     0,     0,   -81,
     -81,   -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,
       0,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -94,   -94,   -94,
     -94,     0,     0,   -94,   -94,   343,   344,   345,     0,   -82,
     -82,     0,     0,     0,     0,   -82,   -82,   -82,   -82,   -82,
     -82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   356,   357,     0,     0,   -82,   -82,   -95,
     -95,   -95,     0,   -95,   -95,     0,     0,     0,     0,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -95,   -95,   -95,   -95,     0,
       0,   -95,   -95,   -83,   -83,   -83,     0,   -83,   -83,     0,
       0,     0,     0,   -83,   -83,   -83,   -83,   -83,   -83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -83,
     -83,   356,   357,     0,     0,   -83,   -83,   -96,   -96,   -96,
       0,   -96,   -96,     0,     0,     0,     0,   -96,   -96,   -96,
     -96,   -96,   -96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,     0,     0,   -96,
     -96,   -84,   -84,   -84,     0,   -84,   -84,     0,     0,     0,
       0,   -84,   -84,   -84,   -84,   -84,   -84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -84,   -84,   356,
     357,     0,     0,   -84,   -84,   -97,   -97,   -97,     0,   -97,
     -97,     0,     0,     0,     0,   -97,   -97,   -97,   -97,   -97,
     -97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -97,   -97,   -97,   -97,     0,     0,   -97,   -97,   -85,
     -85,   -85,     0,   -85,   -85,     0,     0,     0,     0,   -85,
     -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -85,   -85,   -85,   -85,     0,
       0,   -85,   -85,   -98,   -98,   -98,     0,   -98,   -98,     0,
       0,     0,     0,   -98,   -98,   -98,   -98,   -98,   -98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,     0,     0,   -98,   -98,   -86,   -86,   -86,
       0,   -86,   -86,     0,     0,     0,     0,   -86,   -86,   -86,
     -86,   -86,   -86,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -86,   -86,   -86,   -86,     0,     0,   -86,
     -86,   -71,   -71,   -71,     0,   -71,   -71,     0,     0,     0,
       0,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,     0,     0,   -71,   -71,   343,   344,   345,     0,   346,
     347,     0,     0,     0,     0,   348,   349,   350,   351,   352,
     353,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   356,   357,     0,     0,   -74,   -74,  -122,
    -122,  -122,     0,  -122,  -122,     0,     0,     0,     0,  -122,
    -122,  -122,  -122,  -122,  -122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -122,  -122,  -122,  -122,     0,
       0,  -122,  -122,  -120,  -120,  -120,     0,  -120,  -120,     0,
       0,     0,     0,  -120,  -120,  -120,  -120,  -120,  -120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -120,
    -120,  -120,  -120,  -120,     0,  -120,  -119,  -119,  -119,     0,
    -119,  -119,     0,     0,     0,     0,  -119,  -119,  -119,  -119,
    -119,  -119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -119,  -119,  -119,  -119,  -119,     0,  -119,  -118,
    -118,  -118,     0,  -118,  -118,     0,     0,     0,     0,  -118,
    -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -118,  -118,  -118,  -118,  -118,
       0,  -118,   457,   458,   459,     0,   460,   461,     0,     0,
       0,     0,   462,   463,   464,   465,   466,   467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   468,   469,
     470,   471,   -63,     0,   -63,   -64,   -64,   -64,     0,   -64,
     -64,     0,     0,     0,     0,   -64,   -64,   -64,   -64,   -64,
     -64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -64,   -64,   -64,   -64,   -64,     0,   -64,   -65,   -65,
     -65,     0,   -65,   -65,     0,     0,     0,     0,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,     0,
     -65,   -66,   -66,   -66,     0,   -66,   -66,     0,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
     -66,   -66,     0,   -66,   -67,   -67,   -67,     0,   -67,   -67,
       0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -67,   -67,   -67,   -67,   -67,     0,   -67,   -68,   -68,   -68,
       0,   -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,   -68,     0,   -68,
    -115,  -115,  -115,     0,  -115,  -115,     0,     0,     0,     0,
    -115,  -115,  -115,  -115,  -115,  -115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -115,  -115,  -115,  -115,
    -115,     0,  -115,  -116,  -116,  -116,     0,  -116,  -116,     0,
       0,     0,     0,  -116,  -116,  -116,  -116,  -116,  -116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -116,
    -116,  -116,  -116,  -116,     0,  -116,  -117,  -117,  -117,     0,
    -117,  -117,     0,     0,     0,     0,  -117,  -117,  -117,  -117,
    -117,  -117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -117,  -117,  -117,  -117,  -117,     0,  -117,   -69,
     -69,   -69,     0,   -69,   -69,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -69,   -69,   -69,   -69,   -69,
       0,   -69,  -110,  -110,  -110,     0,  -110,  -110,     0,     0,
       0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -110,  -110,
    -110,  -110,  -110,     0,  -110,  -105,  -105,  -105,     0,  -105,
    -105,     0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,
    -105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -105,  -105,  -105,  -105,  -105,     0,  -105,  -111,  -111,
    -111,     0,  -111,  -111,     0,     0,     0,     0,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -111,  -111,  -111,  -111,  -111,     0,
    -111,  -106,  -106,  -106,     0,  -106,  -106,     0,     0,     0,
       0,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -106,  -106,  -106,
    -106,  -106,     0,  -106,  -112,  -112,  -112,     0,  -112,  -112,
       0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,  -112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -112,  -112,  -112,  -112,  -112,     0,  -112,  -107,  -107,  -107,
       0,  -107,  -107,     0,     0,     0,     0,  -107,  -107,  -107,
    -107,  -107,  -107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -107,  -107,  -107,  -107,  -107,     0,  -107,
    -113,  -113,  -113,     0,  -113,  -113,     0,     0,     0,     0,
    -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -113,  -113,  -113,  -113,
    -113,     0,  -113,  -108,  -108,  -108,     0,  -108,  -108,     0,
       0,     0,     0,  -108,  -108,  -108,  -108,  -108,  -108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -108,
    -108,  -108,  -108,  -108,     0,  -108,  -114,  -114,  -114,     0,
    -114,  -114,     0,     0,     0,     0,  -114,  -114,  -114,  -114,
    -114,  -114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -114,  -114,  -114,  -114,  -114,     0,  -114,  -109,
    -109,  -109,     0,  -109,  -109,     0,     0,     0,     0,  -109,
    -109,  -109,  -109,  -109,  -109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -109,  -109,  -109,  -109,  -109,
       0,  -109,   -72,   -72,   -72,     0,   -72,   -72,     0,     0,
       0,     0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,   -72,     0,   -72,   -71,   -71,   -71,     0,   -71,
     -71,     0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -71,   -71,   -71,   -71,   -71,     0,   -71,  -102,  -102,
    -102,     0,  -102,  -102,     0,     0,     0,     0,  -102,  -102,
    -102,  -102,  -102,  -102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -102,  -102,  -102,  -102,  -102,     0,
    -102,   457,   458,   459,     0,   -99,   -99,     0,     0,     0,
       0,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   468,   469,   470,
     471,   -99,     0,   -99,  -103,  -103,  -103,     0,  -103,  -103,
       0,     0,     0,     0,  -103,  -103,  -103,  -103,  -103,  -103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -103,  -103,  -103,  -103,  -103,     0,  -103,  -100,   458,   459,
       0,  -100,  -100,     0,     0,     0,     0,  -100,  -100,  -100,
    -100,  -100,  -100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,   469,   470,   471,  -100,     0,  -100,
    -104,  -104,  -104,     0,  -104,  -104,     0,     0,     0,     0,
    -104,  -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -104,  -104,  -104,  -104,
    -104,     0,  -104,  -101,  -101,   459,     0,  -101,  -101,     0,
       0,     0,     0,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
     469,   470,   471,  -101,     0,  -101,   -87,   -87,   -87,     0,
     -87,   -87,     0,     0,     0,     0,   -87,   -87,   -87,   -87,
     -87,   -87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -87,   -87,   -87,   -87,   -87,     0,   -87,   457,
     458,   459,     0,   -75,   461,     0,     0,     0,     0,   462,
     463,   464,   465,   466,   467,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,   469,   470,   471,   -75,
       0,   -75,   -88,   -88,   -88,     0,   -88,   -88,     0,     0,
       0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -88,   -88,
     -88,   -88,   -88,     0,   -88,   457,   458,   459,     0,   -76,
     -76,     0,     0,     0,     0,   462,   463,   464,   465,   466,
     467,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   469,   470,   471,   -76,     0,   -76,   -89,   -89,
     -89,     0,   -89,   -89,     0,     0,     0,     0,   -89,   -89,
     -89,   -89,   -89,   -89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -89,   -89,   -89,   -89,   -89,     0,
     -89,   457,   458,   459,     0,   -77,   -77,     0,     0,     0,
       0,   -77,   -77,   464,   465,   466,   467,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   468,   469,   470,
     471,   -77,     0,   -77,   -90,   -90,   -90,     0,   -90,   -90,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -90,   -90,   -90,   -90,   -90,     0,   -90,   457,   458,   459,
       0,   -78,   -78,     0,     0,     0,     0,   -78,   -78,   464,
     465,   466,   467,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,   469,   470,   471,   -78,     0,   -78,
     -91,   -91,   -91,     0,   -91,   -91,     0,     0,     0,     0,
     -91,   -91,   -91,   -91,   -91,   -91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -91,   -91,   -91,   -91,
     -91,     0,   -91,   457,   458,   459,     0,   -79,   -79,     0,
       0,     0,     0,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
     469,   470,   471,   -79,     0,   -79,   -92,   -92,   -92,     0,
     -92,   -92,     0,     0,     0,     0,   -92,   -92,   -92,   -92,
     -92,   -92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -92,   -92,   -92,   -92,   -92,     0,   -92,   457,
     458,   459,     0,   -80,   -80,     0,     0,     0,     0,   -80,
     -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,   469,   470,   471,   -80,
       0,   -80,   -93,   -93,   -93,     0,   -93,   -93,     0,     0,
       0,     0,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -93,   -93,
     -93,   -93,   -93,     0,   -93,   457,   458,   459,     0,   -81,
     -81,     0,     0,     0,     0,   -81,   -81,   -81,   -81,   -81,
     -81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   469,   470,   471,   -81,     0,   -81,   -94,   -94,
     -94,     0,   -94,   -94,     0,     0,     0,     0,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -94,   -94,   -94,   -94,   -94,     0,
     -94,   457,   458,   459,     0,   -82,   -82,     0,     0,     0,
       0,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   468,   469,   470,
     471,   -82,     0,   -82,   -95,   -95,   -95,     0,   -95,   -95,
       0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -95,   -95,   -95,   -95,   -95,     0,   -95,   -83,   -83,   -83,
       0,   -83,   -83,     0,     0,     0,     0,   -83,   -83,   -83,
     -83,   -83,   -83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -83,   -83,   470,   471,   -83,     0,   -83,
     -96,   -96,   -96,     0,   -96,   -96,     0,     0,     0,     0,
     -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -96,   -96,   -96,   -96,
     -96,     0,   -96,   -84,   -84,   -84,     0,   -84,   -84,     0,
       0,     0,     0,   -84,   -84,   -84,   -84,   -84,   -84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -84,
     -84,   470,   471,   -84,     0,   -84,   -97,   -97,   -97,     0,
     -97,   -97,     0,     0,     0,     0,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -97,   -97,   -97,   -97,   -97,     0,   -97,   -85,
     -85,   -85,     0,   -85,   -85,     0,     0,     0,     0,   -85,
     -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -85,   -85,   -85,   -85,   -85,
       0,   -85,   -98,   -98,   -98,     0,   -98,   -98,     0,     0,
       0,     0,   -98,   -98,   -98,   -98,   -98,   -98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -98,   -98,
     -98,   -98,   -98,     0,   -98,   -86,   -86,   -86,     0,   -86,
     -86,     0,     0,     0,     0,   -86,   -86,   -86,   -86,   -86,
     -86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -86,   -86,   -86,   -86,   -86,     0,   -86,   457,   458,
     459,     0,   460,   461,     0,     0,     0,     0,   462,   463,
     464,   465,   466,   467,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,   469,   470,   471,   -74,     0,
     -74,  -122,  -122,  -122,     0,  -122,  -122,     0,     0,     0,
       0,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -122,  -122,  -122,
    -122,  -122,     0,  -122,   254,   255,   256,     0,   257,   258,
       0,     0,     0,     0,   259,   260,   261,   262,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,   266,   267,   268,     0,     0,   111,   254,   255,   256,
       0,   257,   258,     0,     0,     0,     0,   259,   260,   261,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,   268,     0,     0,   162,
     254,   255,   256,     0,   257,   258,     0,     0,     0,     0,
     259,   260,   261,   262,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,   268,
       0,     0,   164,  -120,  -120,  -120,     0,  -120,  -120,     0,
       0,     0,     0,  -120,  -120,  -120,  -120,  -120,  -120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -120,
    -120,  -120,  -120,     0,     0,  -120,  -119,  -119,  -119,     0,
    -119,  -119,     0,     0,     0,     0,  -119,  -119,  -119,  -119,
    -119,  -119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -119,  -119,  -119,  -119,     0,     0,  -119,  -118,
    -118,  -118,     0,  -118,  -118,     0,     0,     0,     0,  -118,
    -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -118,  -118,  -118,  -118,     0,
       0,  -118,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,
       0,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -64,   -64,
     -64,   -64,     0,     0,   -64,   -65,   -65,   -65,     0,   -65,
     -65,     0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,
     -65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -65,   -65,   -65,   -65,     0,     0,   -65,   -66,   -66,
     -66,     0,   -66,   -66,     0,     0,     0,     0,   -66,   -66,
     -66,   -66,   -66,   -66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -66,   -66,   -66,   -66,     0,     0,
     -66,   -67,   -67,   -67,     0,   -67,   -67,     0,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -67,   -67,   -67,
     -67,     0,     0,   -67,   -68,   -68,   -68,     0,   -68,   -68,
       0,     0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,     0,     0,   -68,  -115,  -115,  -115,
       0,  -115,  -115,     0,     0,     0,     0,  -115,  -115,  -115,
    -115,  -115,  -115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -115,  -115,  -115,  -115,     0,     0,  -115,
    -116,  -116,  -116,     0,  -116,  -116,     0,     0,     0,     0,
    -116,  -116,  -116,  -116,  -116,  -116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -116,  -116,  -116,  -116,
       0,     0,  -116,  -117,  -117,  -117,     0,  -117,  -117,     0,
       0,     0,     0,  -117,  -117,  -117,  -117,  -117,  -117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -117,
    -117,  -117,  -117,     0,     0,  -117,   -69,   -69,   -69,     0,
     -69,   -69,     0,     0,     0,     0,   -69,   -69,   -69,   -69,
     -69,   -69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,     0,     0,   -69,   254,
     255,   256,     0,   257,   258,     0,     0,     0,     0,   259,
     260,   261,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,   268,     0,
       0,   -63,  -110,  -110,  -110,     0,  -110,  -110,     0,     0,
       0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -110,  -110,
    -110,  -110,     0,     0,  -110,  -105,  -105,  -105,     0,  -105,
    -105,     0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,
    -105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -105,  -105,  -105,  -105,     0,     0,  -105,  -111,  -111,
    -111,     0,  -111,  -111,     0,     0,     0,     0,  -111,  -111,
    -111,  -111,  -111,  -111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -111,  -111,  -111,  -111,     0,     0,
    -111,  -106,  -106,  -106,     0,  -106,  -106,     0,     0,     0,
       0,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -106,  -106,  -106,
    -106,     0,     0,  -106,  -112,  -112,  -112,     0,  -112,  -112,
       0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,  -112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -112,  -112,  -112,  -112,     0,     0,  -112,  -107,  -107,  -107,
       0,  -107,  -107,     0,     0,     0,     0,  -107,  -107,  -107,
    -107,  -107,  -107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -107,  -107,  -107,  -107,     0,     0,  -107,
    -113,  -113,  -113,     0,  -113,  -113,     0,     0,     0,     0,
    -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -113,  -113,  -113,  -113,
       0,     0,  -113,  -108,  -108,  -108,     0,  -108,  -108,     0,
       0,     0,     0,  -108,  -108,  -108,  -108,  -108,  -108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -108,
    -108,  -108,  -108,     0,     0,  -108,  -114,  -114,  -114,     0,
    -114,  -114,     0,     0,     0,     0,  -114,  -114,  -114,  -114,
    -114,  -114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -114,  -114,  -114,  -114,     0,     0,  -114,  -109,
    -109,  -109,     0,  -109,  -109,     0,     0,     0,     0,  -109,
    -109,  -109,  -109,  -109,  -109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -109,  -109,  -109,  -109,     0,
       0,  -109,   254,   255,   256,     0,   257,   258,     0,     0,
       0,     0,   259,   260,   261,   262,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   266,
     267,   268,     0,     0,   508,   -72,   -72,   -72,     0,   -72,
     -72,     0,     0,     0,     0,   -72,   -72,   -72,   -72,   -72,
     -72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,     0,     0,   -72,  -102,  -102,
    -102,     0,  -102,  -102,     0,     0,     0,     0,  -102,  -102,
    -102,  -102,  -102,  -102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -102,  -102,  -102,  -102,     0,     0,
    -102,   254,   255,   256,     0,   -99,   -99,     0,     0,     0,
       0,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
     268,     0,     0,   -99,  -103,  -103,  -103,     0,  -103,  -103,
       0,     0,     0,     0,  -103,  -103,  -103,  -103,  -103,  -103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -103,  -103,  -103,  -103,     0,     0,  -103,  -100,   255,   256,
       0,  -100,  -100,     0,     0,     0,     0,  -100,  -100,  -100,
    -100,  -100,  -100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,   268,     0,     0,  -100,
    -104,  -104,  -104,     0,  -104,  -104,     0,     0,     0,     0,
    -104,  -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -104,  -104,  -104,  -104,
       0,     0,  -104,  -101,  -101,   256,     0,  -101,  -101,     0,
       0,     0,     0,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,   268,     0,     0,  -101,   -87,   -87,   -87,     0,
     -87,   -87,     0,     0,     0,     0,   -87,   -87,   -87,   -87,
     -87,   -87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -87,   -87,   -87,   -87,     0,     0,   -87,   254,
     255,   256,     0,   -75,   258,     0,     0,     0,     0,   259,
     260,   261,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,   268,     0,
       0,   -75,   -88,   -88,   -88,     0,   -88,   -88,     0,     0,
       0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -88,   -88,
     -88,   -88,     0,     0,   -88,   254,   255,   256,     0,   -76,
     -76,     0,     0,     0,     0,   259,   260,   261,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,   268,     0,     0,   -76,   -89,   -89,
     -89,     0,   -89,   -89,     0,     0,     0,     0,   -89,   -89,
     -89,   -89,   -89,   -89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -89,   -89,   -89,   -89,     0,     0,
     -89,   254,   255,   256,     0,   -77,   -77,     0,     0,     0,
       0,   -77,   -77,   261,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
     268,     0,     0,   -77,   -90,   -90,   -90,     0,   -90,   -90,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -90,   -90,   -90,   -90,     0,     0,   -90,   254,   255,   256,
       0,   -78,   -78,     0,     0,     0,     0,   -78,   -78,   261,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,   268,     0,     0,   -78,
     -91,   -91,   -91,     0,   -91,   -91,     0,     0,     0,     0,
     -91,   -91,   -91,   -91,   -91,   -91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -91,   -91,   -91,   -91,
       0,     0,   -91,   254,   255,   256,     0,   -79,   -79,     0,
       0,     0,     0,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,   268,     0,     0,   -79,   -92,   -92,   -92,     0,
     -92,   -92,     0,     0,     0,     0,   -92,   -92,   -92,   -92,
     -92,   -92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -92,   -92,   -92,   -92,     0,     0,   -92,   254,
     255,   256,     0,   -80,   -80,     0,     0,     0,     0,   -80,
     -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,   268,     0,
       0,   -80,   -93,   -93,   -93,     0,   -93,   -93,     0,     0,
       0,     0,   -93,   -93,   -93,   -93,   -93,   -93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -93,   -93,
     -93,   -93,     0,     0,   -93,   254,   255,   256,     0,   -81,
     -81,     0,     0,     0,     0,   -81,   -81,   -81,   -81,   -81,
     -81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,   267,   268,     0,     0,   -81,   -94,   -94,
     -94,     0,   -94,   -94,     0,     0,     0,     0,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -94,   -94,   -94,   -94,     0,     0,
     -94,   254,   255,   256,     0,   -82,   -82,     0,     0,     0,
       0,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
     268,     0,     0,   -82,   -95,   -95,   -95,     0,   -95,   -95,
       0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -95,   -95,   -95,   -95,     0,     0,   -95,   -83,   -83,   -83,
       0,   -83,   -83,     0,     0,     0,     0,   -83,   -83,   -83,
     -83,   -83,   -83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -83,   -83,   267,   268,     0,     0,   -83,
     -96,   -96,   -96,     0,   -96,   -96,     0,     0,     0,     0,
     -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -96,   -96,   -96,   -96,
       0,     0,   -96,   -84,   -84,   -84,     0,   -84,   -84,     0,
       0,     0,     0,   -84,   -84,   -84,   -84,   -84,   -84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -84,
     -84,   267,   268,     0,     0,   -84,   -97,   -97,   -97,     0,
     -97,   -97,     0,     0,     0,     0,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -97,   -97,   -97,   -97,     0,     0,   -97,   -85,
     -85,   -85,     0,   -85,   -85,     0,     0,     0,     0,   -85,
     -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -85,   -85,   -85,   -85,     0,
       0,   -85,   -98,   -98,   -98,     0,   -98,   -98,     0,     0,
       0,     0,   -98,   -98,   -98,   -98,   -98,   -98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -98,   -98,
     -98,   -98,     0,     0,   -98,   -86,   -86,   -86,     0,   -86,
     -86,     0,     0,     0,     0,   -86,   -86,   -86,   -86,   -86,
     -86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -86,   -86,   -86,   -86,     0,     0,   -86,   254,   255,
     256,     0,   257,   258,     0,     0,     0,     0,   259,   260,
     261,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,   266,   267,   268,     0,     0,
     526,   254,   255,   256,     0,   257,   258,     0,     0,     0,
       0,   259,   260,   261,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   266,   267,
     268,     0,     0,   542,   -71,   -71,   -71,     0,   -71,   -71,
       0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -71,   -71,   -71,   -71,     0,     0,   -71,   254,   255,   256,
       0,   257,   258,     0,     0,     0,     0,   259,   260,   261,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,   266,   267,   268,     0,     0,   581,
     254,   255,   256,     0,   257,   258,     0,     0,     0,     0,
     259,   260,   261,   262,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,   266,   267,   268,
       0,     0,   583,   254,   255,   256,     0,   257,   258,     0,
       0,     0,     0,   259,   260,   261,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,   268,     0,     0,   595,   254,   255,   256,     0,
     257,   258,     0,     0,     0,     0,   259,   260,   261,   262,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   266,   267,   268,     0,     0,   597,   254,
     255,   256,     0,   257,   258,     0,     0,     0,     0,   259,
     260,   261,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,   266,   267,   268,     0,
       0,   -74,  -122,  -122,  -122,     0,  -122,  -122,     0,     0,
       0,     0,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -122,  -122,
    -122,  -122,     0,     0,  -122,  -120,  -120,  -120,     0,  -120,
    -120,     0,     0,     0,     0,  -120,  -120,  -120,  -120,  -120,
    -120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -120,  -120,  -120,  -120,  -120,  -119,  -119,  -119,     0,
    -119,  -119,     0,     0,     0,     0,  -119,  -119,  -119,  -119,
    -119,  -119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -119,  -119,  -119,  -119,  -119,  -118,  -118,  -118,
       0,  -118,  -118,     0,     0,     0,     0,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -118,  -118,  -118,  -118,  -118,    76,    77,
      78,     0,    79,    80,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    89,    90,    91,   -64,
     -64,   -64,     0,   -64,   -64,     0,     0,     0,     0,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -64,   -64,   -64,   -64,   -64,
     -65,   -65,   -65,     0,   -65,   -65,     0,     0,     0,     0,
     -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -65,   -65,   -65,   -65,
     -65,   -66,   -66,   -66,     0,   -66,   -66,     0,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -66,   -66,   -66,
     -66,   -66,   -67,   -67,   -67,     0,   -67,   -67,     0,     0,
       0,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -67,   -67,
     -67,   -67,   -67,   -68,   -68,   -68,     0,   -68,   -68,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -68,
     -68,   -68,   -68,   -68,  -115,  -115,  -115,     0,  -115,  -115,
       0,     0,     0,     0,  -115,  -115,  -115,  -115,  -115,  -115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -115,  -115,  -115,  -115,  -115,  -116,  -116,  -116,     0,  -116,
    -116,     0,     0,     0,     0,  -116,  -116,  -116,  -116,  -116,
    -116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -116,  -116,  -116,  -116,  -116,  -117,  -117,  -117,     0,
    -117,  -117,     0,     0,     0,     0,  -117,  -117,  -117,  -117,
    -117,  -117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -117,  -117,  -117,  -117,  -117,   -69,   -69,   -69,
       0,   -69,   -69,     0,     0,     0,     0,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -69,   -69,   -69,   -69,   -69,  -110,  -110,
    -110,     0,  -110,  -110,     0,     0,     0,     0,  -110,  -110,
    -110,  -110,  -110,  -110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -110,  -110,  -110,  -110,  -110,  -105,
    -105,  -105,     0,  -105,  -105,     0,     0,     0,     0,  -105,
    -105,  -105,  -105,  -105,  -105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,
    -111,  -111,  -111,     0,  -111,  -111,     0,     0,     0,     0,
    -111,  -111,  -111,  -111,  -111,  -111,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -111,  -111,  -111,  -111,
    -111,  -106,  -106,  -106,     0,  -106,  -106,     0,     0,     0,
       0,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -106,  -106,  -106,
    -106,  -106,  -112,  -112,  -112,     0,  -112,  -112,     0,     0,
       0,     0,  -112,  -112,  -112,  -112,  -112,  -112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -112,  -112,
    -112,  -112,  -112,  -107,  -107,  -107,     0,  -107,  -107,     0,
       0,     0,     0,  -107,  -107,  -107,  -107,  -107,  -107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -107,
    -107,  -107,  -107,  -107,    76,    77,    78,     0,    79,    80,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,   -60,  -113,  -113,  -113,     0,  -113,
    -113,     0,     0,     0,     0,  -113,  -113,  -113,  -113,  -113,
    -113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -113,  -113,  -113,  -113,  -113,  -108,  -108,  -108,     0,
    -108,  -108,     0,     0,     0,     0,  -108,  -108,  -108,  -108,
    -108,  -108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -108,  -108,  -108,  -108,  -108,  -114,  -114,  -114,
       0,  -114,  -114,     0,     0,     0,     0,  -114,  -114,  -114,
    -114,  -114,  -114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -114,  -114,  -114,  -114,  -114,  -109,  -109,
    -109,     0,  -109,  -109,     0,     0,     0,     0,  -109,  -109,
    -109,  -109,  -109,  -109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -109,  -109,  -109,  -109,  -109,   -72,
     -72,   -72,     0,   -72,   -72,     0,     0,     0,     0,   -72,
     -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,   -72,
      76,    77,    78,     0,    79,    80,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,    88,    89,    90,
     -63,   -71,   -71,   -71,     0,   -71,   -71,     0,     0,     0,
       0,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,
       0,     0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -102,  -102,
    -102,  -102,  -102,    76,    77,    78,     0,   -99,   -99,     0,
       0,     0,     0,   -99,   -99,   -99,   -99,   -99,   -99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,   -99,  -103,  -103,  -103,     0,  -103,  -103,
       0,     0,     0,     0,  -103,  -103,  -103,  -103,  -103,  -103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -103,  -103,  -103,  -103,  -103,  -100,    77,    78,     0,  -100,
    -100,     0,     0,     0,     0,  -100,  -100,  -100,  -100,  -100,
    -100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,  -100,  -104,  -104,  -104,     0,
    -104,  -104,     0,     0,     0,     0,  -104,  -104,  -104,  -104,
    -104,  -104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -104,  -104,  -104,  -104,  -104,  -101,  -101,    78,
       0,  -101,  -101,     0,     0,     0,     0,  -101,  -101,  -101,
    -101,  -101,  -101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,  -101,   -87,   -87,
     -87,     0,   -87,   -87,     0,     0,     0,     0,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -87,   -87,   -87,   -87,   -87,    76,
      77,    78,     0,   -75,    80,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,   -75,
     -88,   -88,   -88,     0,   -88,   -88,     0,     0,     0,     0,
     -88,   -88,   -88,   -88,   -88,   -88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -88,   -88,   -88,   -88,
     -88,    76,    77,    78,     0,   -76,   -76,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,   -76,   -89,   -89,   -89,     0,   -89,   -89,     0,     0,
       0,     0,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -89,   -89,
     -89,   -89,   -89,    76,    77,    78,     0,   -77,   -77,     0,
       0,     0,     0,   -77,   -77,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,   -77,   -90,   -90,   -90,     0,   -90,   -90,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -90,   -90,   -90,   -90,   -90,    76,    77,    78,     0,   -78,
     -78,     0,     0,     0,     0,   -78,   -78,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,   -78,   -91,   -91,   -91,     0,
     -91,   -91,     0,     0,     0,     0,   -91,   -91,   -91,   -91,
     -91,   -91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -91,   -91,   -91,   -91,   -91,    76,    77,    78,
       0,   -79,   -79,     0,     0,     0,     0,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,   -79,   -92,   -92,
     -92,     0,   -92,   -92,     0,     0,     0,     0,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -92,   -92,   -92,   -92,   -92,    76,
      77,    78,     0,   -80,   -80,     0,     0,     0,     0,   -80,
     -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,   -80,
     -93,   -93,   -93,     0,   -93,   -93,     0,     0,     0,     0,
     -93,   -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -93,   -93,   -93,   -93,
     -93,    76,    77,    78,     0,   -81,   -81,     0,     0,     0,
       0,   -81,   -81,   -81,   -81,   -81,   -81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,   -81,   -94,   -94,   -94,     0,   -94,   -94,     0,     0,
       0,     0,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -94,   -94,
     -94,   -94,   -94,    76,    77,    78,     0,   -82,   -82,     0,
       0,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    90,   -82,   -95,   -95,   -95,     0,   -95,   -95,
       0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -95,   -95,   -95,   -95,   -95,   -83,   -83,   -83,     0,   -83,
     -83,     0,     0,     0,     0,   -83,   -83,   -83,   -83,   -83,
     -83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -83,   -83,    89,    90,   -83,   -96,   -96,   -96,     0,
     -96,   -96,     0,     0,     0,     0,   -96,   -96,   -96,   -96,
     -96,   -96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -96,   -96,   -96,   -96,   -96,   -84,   -84,   -84,
       0,   -84,   -84,     0,     0,     0,     0,   -84,   -84,   -84,
     -84,   -84,   -84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -84,   -84,    89,    90,   -84,   -97,   -97,
     -97,     0,   -97,   -97,     0,     0,     0,     0,   -97,   -97,
     -97,   -97,   -97,   -97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -97,   -97,   -97,   -97,   -97,   -85,
     -85,   -85,     0,   -85,   -85,     0,     0,     0,     0,   -85,
     -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -85,   -85,   -85,   -85,   -85,
     -98,   -98,   -98,     0,   -98,   -98,     0,     0,     0,     0,
     -98,   -98,   -98,   -98,   -98,   -98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -98,   -98,   -98,   -98,
     -98,   -86,   -86,   -86,     0,   -86,   -86,     0,     0,     0,
       0,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -86,   -86,   -86,
     -86,   -86,    76,    77,    78,     0,    79,    80,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
      89,    90,   -74,  -122,  -122,  -122,     0,  -122,  -122,     0,
       0,     0,     0,  -122,  -122,  -122,  -122,  -122,  -122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -122,
    -122,  -122,  -122,  -122,    76,    77,    78,     0,    79,    80,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,    88,    89,    90,   417,    76,    77,    78,     0,    79,
      80,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    88,    89,    90,   445
};

static const yytype_int16 yycheck[] =
{
       0,     0,   250,   250,   274,   510,     3,     4,     0,     6,
      10,    11,    12,    20,     0,    15,    16,    17,    18,     1,
       0,    21,    21,   528,     1,     1,    47,     1,     1,    21,
       6,   415,    47,     9,    10,    11,    20,    13,    14,    15,
      47,    48,   312,     1,     0,     3,     4,     1,     6,     1,
      50,     1,    52,     3,     4,     1,     6,   305,   305,   443,
      60,    47,    62,    47,    48,    21,    48,    43,    44,   574,
       1,    48,    48,    49,    48,    48,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    49,   340,   340,    48,     1,    48,   513,     1,    49,
       3,     4,    48,     6,     7,     8,     9,    10,    11,     6,
      13,    14,    15,     0,    47,   531,    49,    48,     1,     1,
      47,     3,     4,     6,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    21,    38,    39,    40,    41,     1,
      43,    44,    48,     1,    47,    48,     5,     6,    51,    52,
      47,   151,   152,     6,     5,     6,    38,    39,    40,    41,
      20,    43,    44,   163,   164,   165,    48,   167,    20,    51,
      52,   163,   164,    39,     5,     6,     0,    48,     5,     6,
     179,    47,    47,   183,     1,   185,    48,    47,    47,     6,
      48,   183,   192,   185,    47,    47,    52,    21,    49,    50,
     200,     6,   202,   203,   204,   205,   206,   207,   200,     6,
     202,   210,   204,    47,   206,    49,    20,   209,    49,    50,
      47,    49,   222,   223,   224,   225,   113,     0,     6,     6,
     222,   223,   224,   225,     6,   235,   236,   237,   238,   239,
     240,     1,    48,    47,    49,    50,     6,    47,    21,    49,
      20,    20,    49,    50,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    49,
      47,    49,    50,   273,    49,    47,   163,   164,    47,    47,
      47,   168,    49,    47,    47,    49,    49,    49,    50,    47,
     290,   291,   292,   293,   294,   295,   183,    47,   185,    49,
      47,    47,    49,    49,    49,    50,    49,    50,    49,    50,
      49,   311,     0,   200,    49,   202,    49,   204,    49,   206,
       0,    49,    50,     1,   324,   325,   326,   327,   328,   329,
     165,     1,   167,    21,    49,   222,   223,   224,   225,   163,
     164,    21,    47,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    49,   183,
      49,   185,    49,    50,    49,    50,    49,    50,   203,    51,
     205,     1,   207,    49,    49,    49,   200,    49,   202,    47,
     204,    47,   206,    47,    47,     0,    20,    48,    47,    47,
     163,   164,    49,    20,    48,    47,    47,    20,   222,   223,
     224,   225,    49,    48,    47,    49,    21,    49,    49,   409,
     183,   411,   185,   413,    49,    52,     1,    49,    49,    52,
      49,    49,    47,    49,    21,    49,   210,   200,    49,   202,
      49,   204,    49,   206,    47,    47,    -1,   437,    49,   439,
      49,   441,    49,    49,    49,    49,    49,    49,    -1,   222,
     223,   224,   225,    -1,   116,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,   163,   164,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,    -1,   185,    -1,    -1,
      -1,    -1,    -1,   183,    -1,   185,    -1,    -1,    -1,   509,
     510,    -1,   200,    -1,   202,    -1,   204,    -1,   206,    -1,
     200,    -1,   202,    -1,   204,    -1,   206,   527,   528,    -1,
      -1,    -1,    -1,    -1,   222,   223,   224,   225,    -1,    -1,
      -1,    -1,   222,   223,   224,   225,    -1,    -1,   163,   164,
      -1,    -1,     1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    -1,   183,    -1,
     185,    -1,    -1,   573,   574,    -1,    -1,    -1,   413,    -1,
      -1,    -1,    -1,    -1,   584,   200,   586,   202,    -1,   204,
      -1,   206,    -1,    42,    43,    44,   596,   597,   598,    48,
     600,    -1,    -1,    -1,   596,   597,   441,   222,   223,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,
      -1,   621,    -1,    -1,    -1,    -1,    -1,   619,    -1,   621,
      -1,   631,    -1,   633,    -1,   635,    -1,   637,    -1,   639,
     640,   641,   642,   643,   644,   637,    -1,   639,    -1,   641,
       1,   643,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,   665,   666,   667,   668,    -1,
      -1,    -1,     1,   665,   666,   667,   668,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    38,    39,    40,
      41,    -1,    43,    44,    -1,   582,   583,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,
     597,    -1,    -1,    -1,    43,    44,    -1,     1,    -1,    48,
      49,   608,     6,   610,    -1,     9,    10,    11,    -1,    13,
      14,    15,   619,    -1,   621,    -1,    -1,    -1,    -1,    -1,
      -1,   628,    -1,   630,    -1,   632,    -1,   634,    -1,   584,
     637,   586,   639,    -1,   641,    -1,   643,    -1,    42,    43,
      44,    -1,    -1,   598,    48,   600,    -1,    -1,    -1,    -1,
      -1,    -1,   596,   597,   661,   662,   663,   664,   665,   666,
     667,   668,    -1,    -1,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    -1,   619,   631,   621,   633,    -1,
     635,    -1,    -1,    -1,    -1,   640,    -1,   642,    -1,   644,
      -1,    -1,    -1,   637,    -1,   639,    -1,   641,    -1,   643,
       1,    43,    44,   596,   597,     6,    48,    49,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,   665,   666,   667,   668,    -1,   619,    -1,   621,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,   637,    -1,   639,    48,   641,    -1,
     643,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,   665,   666,   667,   668,    -1,    43,    44,    45,
      46,    -1,    48,    49,    50,    -1,    -1,    -1,   596,   597,
      -1,    -1,    -1,    -1,    -1,    -1,   596,   597,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,
      -1,   619,    -1,   621,    -1,    -1,    -1,    -1,    -1,   619,
      -1,   621,    18,    -1,    -1,    21,    -1,    -1,    -1,   637,
      -1,   639,    -1,   641,    -1,   643,    -1,   637,    -1,   639,
      -1,   641,    -1,   643,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    52,   665,   666,   667,
     668,   596,   597,    -1,    60,   665,   666,   667,   668,     1,
      -1,    -1,    -1,    -1,     6,    71,    -1,     9,    10,    11,
       1,    13,    14,    15,   619,     6,   621,    -1,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   637,    -1,   639,    -1,   641,    -1,   643,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,
     116,    -1,    43,    44,   120,    -1,    47,    48,    -1,    -1,
     665,   666,   667,   668,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,    -1,    -1,     9,    10,    11,   152,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      47,    48,    -1,   179,    51,    52,    -1,    43,    44,    -1,
      -1,    47,    48,    -1,    -1,    -1,   192,    -1,    -1,    -1,
      -1,    -1,   198,     1,    -1,    -1,    -1,   203,    -1,   205,
      -1,   207,    -1,    -1,   210,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,   235,
     236,   237,   238,   239,   240,    43,    44,    45,    46,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,    -1,    -1,    -1,    -1,   273,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   282,    -1,    -1,    -1,
      -1,    -1,     1,    -1,   290,   291,   292,   293,   294,   295,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,   311,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,   324,   325,
     326,   327,   328,   329,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,     1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    -1,    18,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    47,    48,
      50,   407,    52,   409,    -1,   411,    -1,    -1,    -1,   415,
      60,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    51,    -1,    -1,    -1,    -1,   435,
      -1,   437,    -1,   439,    -1,     0,     1,   443,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    51,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,   152,   509,   510,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,   527,   528,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,   203,    -1,   205,     6,   207,    -1,     9,
      10,    11,    -1,    13,    14,    15,    -1,   573,   574,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,    -1,   598,    43,    44,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,   631,    -1,   633,    -1,   635,
      -1,    -1,    -1,    -1,   640,    -1,   642,    -1,   644,     1,
     290,   291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,   311,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,   324,   325,   326,   327,   328,   329,
      -1,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    43,    44,    -1,    -1,    47,
      48,    49,    -1,    -1,    -1,    50,    -1,    52,    -1,   409,
      -1,   411,    -1,    -1,    -1,    60,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,   437,     1,   439,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,   152,     6,   509,
     510,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    43,    44,   192,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     205,    -1,   207,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,   573,   574,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
     235,   236,   237,   238,   239,   240,    -1,    -1,   598,    -1,
      43,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    -1,    -1,    -1,    -1,   273,    -1,
      -1,   631,    -1,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,    -1,   642,     1,   644,   290,   291,   292,   293,   294,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,   311,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,   324,
     325,   326,   327,   328,   329,    43,    44,    45,    46,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     6,
      43,    44,     9,    10,    11,    48,    13,    14,    15,    -1,
      50,    -1,    52,    -1,   409,    -1,   411,    -1,    -1,    -1,
      60,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    43,    44,    -1,    -1,
      -1,    48,   437,    -1,   439,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    51,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,   152,     6,   509,   510,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   527,   528,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      43,    44,   192,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    -1,   207,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,   573,   574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,    -1,    -1,   598,     6,    43,    44,     9,    10,    11,
      48,    13,    14,    15,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,    -1,   631,    -1,   633,    -1,
     635,    43,    44,    -1,    -1,   640,    48,   642,     1,   644,
     290,   291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,   311,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,   329,
      43,    44,    45,    46,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    50,    -1,    52,    -1,   409,
      -1,   411,    -1,    -1,    38,    60,    40,    41,    -1,    43,
      44,    -1,    -1,    47,    48,    -1,    -1,    51,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,   437,     1,   439,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,   152,     6,   509,
     510,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    43,    44,   192,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   573,   574,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
     235,   236,   237,   238,   239,   240,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    -1,    -1,    -1,    -1,   273,    -1,
      -1,   631,    -1,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,    -1,   642,     1,   644,   290,   291,   292,   293,   294,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,   311,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,   324,
     325,   326,   327,   328,   329,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,   409,    -1,   411,    -1,    -1,    -1,
      60,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,     1,   439,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,   152,     6,   509,   510,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   527,   528,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      43,    44,   192,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,    -1,    -1,   598,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,    -1,   631,    -1,   633,    -1,
     635,    -1,    -1,    -1,    -1,   640,    -1,   642,     1,   644,
     290,   291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,   311,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,   329,
      43,    44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,   409,
      -1,   411,    -1,    -1,    -1,    60,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,   437,     1,   439,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,   152,     6,   509,
     510,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    43,    44,   192,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   573,   574,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
     235,   236,   237,   238,   239,   240,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    -1,    -1,    -1,    -1,   273,    -1,
      -1,   631,    -1,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,    -1,   642,    -1,   644,   290,   291,   292,   293,   294,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,   311,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,   324,
     325,   326,   327,   328,   329,    43,    44,    45,    46,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,   409,    -1,   411,    -1,    -1,    -1,
      60,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,   437,     1,   439,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,   152,     6,   509,   510,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   527,   528,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      43,    44,   192,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,    -1,    -1,   598,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,    -1,   631,    -1,   633,    -1,
     635,    -1,    -1,    -1,    -1,   640,    -1,   642,    -1,   644,
     290,   291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      -1,   311,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,   329,
      43,    44,    45,    46,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    52,    -1,   409,
      -1,   411,    -1,    -1,    -1,    60,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,   439,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,   152,     6,   509,
     510,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
     165,    -1,    -1,    -1,    -1,    -1,    -1,   527,   528,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    43,    44,   192,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,
     205,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   573,   574,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,
     235,   236,   237,   238,   239,   240,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    -1,    -1,    -1,    -1,   273,    -1,
      -1,   631,    -1,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,    -1,   642,    -1,   644,   290,   291,   292,   293,   294,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    -1,   311,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,   324,
     325,   326,   327,   328,   329,    43,    44,    45,    46,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    -1,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    52,    -1,   409,    -1,   411,    -1,    -1,    -1,
      60,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   437,    -1,   439,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,   152,     6,   509,   510,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,   165,    -1,    -1,    -1,    -1,
      -1,    -1,   527,   528,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      43,    44,   192,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    -1,   207,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      -1,    -1,    -1,    -1,    -1,   235,   236,   237,   238,   239,
     240,    -1,    -1,   598,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,    -1,
      -1,    -1,    -1,   273,    -1,    -1,   631,    -1,   633,    -1,
     635,    -1,    -1,    -1,    -1,   640,    -1,   642,    -1,   644,
     290,   291,   292,   293,   294,   295,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      -1,   311,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,   324,   325,   326,   327,   328,   329,
      43,    44,    45,    46,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    -1,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,   409,
      51,   411,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   437,     1,   439,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,   509,
     510,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,   527,   528,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,     1,    48,
      -1,    -1,    51,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,   573,   574,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,     4,   584,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,   598,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,   631,    -1,   633,    -1,   635,    -1,    -1,    -1,    -1,
     640,    -1,   642,    -1,   644,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     0,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,     1,    48,     3,
       4,    51,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
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
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      38,    39,    40,    41,    -1,    43,    44,    -1,    -1,     1,
      48,    -1,    -1,    51,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
       1,    48,    -1,    -1,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    38,    39,    40,    41,    -1,    43,    44,    -1,
      -1,     1,    48,    -1,    -1,    51,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    38,    -1,    40,    41,    -1,    43,    44,
      -1,    -1,     1,    48,    -1,    -1,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,     1,    38,    -1,    40,    41,     6,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,     1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,     1,    -1,    -1,    -1,    -1,     6,    -1,
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
       6,    -1,    48,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    -1,    -1,    49,    50,    17,    18,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,
      50,    17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    -1,    49,    50,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    17,
      18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    17,    18,    19,    -1,    21,    22,    -1,
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
      -1,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    38,    40,    41,    43,    44,    48,    51,
      54,    55,    56,    57,    58,    63,    68,    69,    70,    72,
      73,    75,    76,    78,    79,    80,    81,    82,    83,    84,
      85,    87,    91,    92,    47,     5,     5,     1,    48,     1,
      48,     1,    48,    75,    91,     1,    75,     1,    75,     1,
      48,     1,    48,     1,    75,     1,    75,     1,    75,     1,
      75,    64,     0,     1,    56,    47,    17,    18,    19,    21,
      22,    27,    28,    29,    30,    31,    32,    43,    44,    45,
      46,    47,     1,    77,    86,    91,    47,    91,    47,     1,
      91,    47,     1,    42,    75,     1,    75,     1,    74,    75,
      49,    49,     1,    39,    57,    65,    66,    67,    68,    71,
      92,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,    20,    48,    20,    47,    20,    47,    48,    49,    88,
      49,    49,    49,    49,    49,    47,    49,    47,    39,    68,
      52,    67,    91,    75,    75,    89,    90,     1,     1,    59,
      47,    49,    47,    39,    68,    39,    68,    74,     1,    74,
      68,    49,    50,     1,    60,    61,    62,    91,    92,    68,
      39,    68,    39,    47,    49,    47,    49,    47,    75,    49,
      50,    91,    68,    68,    74,    68,    74,    68,     1,    74,
      63,    62,    49,    49,    49,    49,    68,    68,    68,    68,
       6,     6,     9,    10,    11,    13,    14,    15,    43,    44,
      48,    76,    78,    79,    80,    81,    82,    83,    84,    85,
      91,     6,     6,     6,    17,    18,    19,    21,    22,    27,
      28,    29,    30,    31,    32,    43,    44,    45,    46,     7,
       8,    38,    40,    48,    51,    63,    69,    70,    72,    73,
      75,    87,    91,    47,     1,    47,     6,     9,    10,    11,
      13,    14,    15,    43,    44,    48,    76,    78,    79,    80,
      81,    82,    83,    84,    85,    91,     1,     7,     8,    38,
      40,    48,    51,    63,    69,    70,    72,    73,    75,    87,
       6,     9,    10,    11,    13,    14,    15,    43,    44,    48,
      75,    76,    78,    79,    80,    81,    82,    83,    84,    85,
      91,    20,    47,    17,    18,    19,    21,    22,    27,    28,
      29,    30,    31,    32,    43,    44,    45,    46,     3,     4,
       6,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,    75,     1,    77,    86,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    48,     1,    48,
       1,    48,     1,    48,     1,    64,    47,    47,    91,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,    75,
       1,    77,    86,    47,     1,    48,     1,    48,     1,    48,
       1,    48,     1,    64,    47,    47,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,    75,    17,    18,    19,
      21,    22,    27,    28,    29,    30,    31,    32,    43,    44,
      45,    46,     1,    77,    86,     1,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
       1,    75,     1,    75,     1,    75,     5,     5,    49,    20,
      48,    47,     1,    91,    47,     1,    42,    75,     1,    75,
       1,    74,    49,    65,    20,    47,    49,    20,    48,    47,
       1,    91,    47,     1,    42,    75,     1,    75,     1,    74,
      49,    65,    49,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,    20,    48,    75,    89,    49,    88,    49,
      49,    49,    49,    49,    47,    49,    47,    52,     1,    75,
      89,    49,    88,    49,    49,    49,    49,    49,    47,    49,
      47,    52,    75,    89,    49,    47,    49,    47,    39,    68,
      39,    68,    74,     1,    74,    49,    47,    49,    47,    39,
      68,    39,    68,    74,     1,    74,    49,    68,    39,    68,
      39,    47,    49,    47,    49,    47,    68,    39,    68,    39,
      47,    49,    47,    49,    47,    68,    68,    74,    68,    74,
      68,     1,    74,    68,    68,    74,    68,    74,    68,     1,
      74,    49,    49,    49,    49,    49,    49,    49,    49,    68,
      68,    68,    68,    68,    68,    68,    68
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
      84,    86,    85,    88,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    89,    89,    90,    90,    91,    92,    92,
      92,    92
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
       1,     0,     5,     0,     5,     4,     4,     4,     5,     4,
       5,     3,     3,     0,     1,     3,     1,     1,     1,     1,
       2,     2
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
#line 123 "./src/bison.y"
           {
    if(((*yyvaluep).string))
        free(((*yyvaluep).string));
}
#line 5000 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 123 "./src/bison.y"
           {
    if(((*yyvaluep).string))
        free(((*yyvaluep).string));
}
#line 5009 "bison.tab.c"
        break;

    case YYSYMBOL_LIST_TOKEN: /* LIST_TOKEN  */
#line 123 "./src/bison.y"
           {
    if(((*yyvaluep).string))
        free(((*yyvaluep).string));
}
#line 5018 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5027 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5036 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5045 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5054 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5063 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5072 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5081 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5090 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5099 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5108 "bison.tab.c"
        break;

    case YYSYMBOL_59_1: /* @1  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5117 "bison.tab.c"
        break;

    case YYSYMBOL_optListParams: /* optListParams  */
#line 118 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5126 "bison.tab.c"
        break;

    case YYSYMBOL_listParams: /* listParams  */
#line 118 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5135 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5144 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5153 "bison.tab.c"
        break;

    case YYSYMBOL_optListCodeBlock: /* optListCodeBlock  */
#line 118 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5162 "bison.tab.c"
        break;

    case YYSYMBOL_listCodeBlock: /* listCodeBlock  */
#line 118 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5171 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5180 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5189 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5198 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5207 "bison.tab.c"
        break;

    case YYSYMBOL_elseError: /* elseError  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5216 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5225 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5234 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5243 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5252 "bison.tab.c"
        break;

    case YYSYMBOL_assignArith: /* assignArith  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5261 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5270 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5279 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5288 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5297 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5306 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5315 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5324 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5333 "bison.tab.c"
        break;

    case YYSYMBOL_ioCommand: /* ioCommand  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5342 "bison.tab.c"
        break;

    case YYSYMBOL_88_5: /* @5  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5351 "bison.tab.c"
        break;

    case YYSYMBOL_optListExpression: /* optListExpression  */
#line 118 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5360 "bison.tab.c"
        break;

    case YYSYMBOL_listExpression: /* listExpression  */
#line 118 "./src/bison.y"
           {
    if(((*yyvaluep).list))
        delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5369 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5378 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 113 "./src/bison.y"
           {
    if(((*yyvaluep).astnode))
        delete_astnode(((*yyvaluep).astnode));
}
#line 5387 "bison.tab.c"
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
#line 135 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected error || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 5685 "bison.tab.c"
    break;

  case 4: /* startProgram: %empty  */
#line 139 "./src/bison.y"
             {
        SHOW_SYNTAX_ERROR("empty translation unit\n");
    }
#line 5693 "bison.tab.c"
    break;

  case 5: /* declarationList: declarationList declaration  */
#line 145 "./src/bison.y"
                                {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 5701 "bison.tab.c"
    break;

  case 6: /* declarationList: declaration  */
#line 148 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 5709 "bison.tab.c"
    break;

  case 7: /* declaration: variableDeclare  */
#line 154 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5717 "bison.tab.c"
    break;

  case 8: /* declaration: functionDeclare  */
#line 157 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5725 "bison.tab.c"
    break;

  case 9: /* declaration: statement  */
#line 162 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("an statement is not permitted at this top level || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5735 "bison.tab.c"
    break;

  case 10: /* variableDeclare: type id ';'  */
#line 170 "./src/bison.y"
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
            (yyval.astnode) = create_astnode_context(AST_VAR_DECLARE, "variable declare", (yylsp[-2]));
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
            (yyvsp[-1].astnode)->context->dtype = (yyvsp[-2].astnode)->context->dtype;
            (yyvsp[-1].astnode)->context->sym_ref = sym_ret;
        }
    }
#line 5759 "bison.tab.c"
    break;

  case 11: /* variableDeclare: type ';'  */
#line 191 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("useless type name in empty declaration || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5769 "bison.tab.c"
    break;

  case 12: /* variableDeclare: type id ASSIGN_TOKEN error  */
#line 197 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 5780 "bison.tab.c"
    break;

  case 13: /* variableDeclare: id id ASSIGN_TOKEN error  */
#line 204 "./src/bison.y"
                               {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 5791 "bison.tab.c"
    break;

  case 14: /* variableDeclare: id id ';'  */
#line 211 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5802 "bison.tab.c"
    break;

  case 15: /* @1: %empty  */
#line 220 "./src/bison.y"
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
#line 5832 "bison.tab.c"
    break;

  case 16: /* functionDeclare: type id '(' @1 optListParams ')' compoundStatement  */
#line 244 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_FUNC_DECLARE, "func declare", (yyloc));
        
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
        // AstNode *ret = lookup_node($7, "return");
        // if(ret){
        //     int val = sem_check(FIRST_SON(ret));
        //     if($1->context->dtype != val){
        //         if((val == 1 || val == 2) && val >= 4){
        //             SEMANTIC_ERROR("returning '%s' from a function with return type '%s' || line: %d, column: %d\n", error_string_type(val), error_string_type($1->context->dtype), @1.first_line, @1.first_column);
        //         }
        //         // Cast
        //     }
        // }
    }
#line 5869 "bison.tab.c"
    break;

  case 17: /* optListParams: %empty  */
#line 279 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 5877 "bison.tab.c"
    break;

  case 19: /* listParams: listParams ',' param  */
#line 286 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 5886 "bison.tab.c"
    break;

  case 20: /* listParams: param  */
#line 290 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 5895 "bison.tab.c"
    break;

  case 21: /* listParams: error  */
#line 296 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected params || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.list) = NULL;
    }
#line 5904 "bison.tab.c"
    break;

  case 22: /* param: type id  */
#line 303 "./src/bison.y"
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
            (yyval.astnode) = create_astnode_context(AST_PARAM, "param", (yyloc));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
            (yyvsp[0].astnode)->context->dtype = (yyvsp[-1].astnode)->context->dtype;
            (yyval.astnode)->context->dtype = (yyvsp[-1].astnode)->context->dtype;
            (yyvsp[0].astnode)->context->sym_ref = sym_ret;
        }
    }
#line 5928 "bison.tab.c"
    break;

  case 23: /* param: type  */
#line 324 "./src/bison.y"
           {
        SHOW_SYNTAX_ERROR("after '%s' expected identifier || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5938 "bison.tab.c"
    break;

  case 24: /* param: id  */
#line 330 "./src/bison.y"
         {
        SHOW_SYNTAX_ERROR("expected type to '%s' || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5948 "bison.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 338 "./src/bison.y"
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
#line 5968 "bison.tab.c"
    break;

  case 26: /* compoundStatement: '{' $@2 optListCodeBlock '}'  */
#line 352 "./src/bison.y"
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
#line 5991 "bison.tab.c"
    break;

  case 27: /* optListCodeBlock: %empty  */
#line 373 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 5999 "bison.tab.c"
    break;

  case 29: /* listCodeBlock: listCodeBlock codeBlock  */
#line 380 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 6008 "bison.tab.c"
    break;

  case 30: /* listCodeBlock: codeBlock  */
#line 384 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 6017 "bison.tab.c"
    break;

  case 31: /* codeBlock: statement  */
#line 391 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6025 "bison.tab.c"
    break;

  case 32: /* codeBlock: variableDeclare  */
#line 394 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
        // $$ = create_astnode_context(AST_CODE_BLOCK, "", @$);
        // insert_kid($1, $$);
    }
#line 6035 "bison.tab.c"
    break;

  case 34: /* statement: flowExpression  */
#line 403 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6043 "bison.tab.c"
    break;

  case 35: /* statement: compoundStatement  */
#line 406 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6051 "bison.tab.c"
    break;

  case 36: /* statement: expression ';'  */
#line 409 "./src/bison.y"
                     {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 6059 "bison.tab.c"
    break;

  case 37: /* statement: ioCommand  */
#line 412 "./src/bison.y"
                {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6067 "bison.tab.c"
    break;

  case 38: /* statement: error ';'  */
#line 417 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6076 "bison.tab.c"
    break;

  case 39: /* statement: '(' error ')'  */
#line 422 "./src/bison.y"
                    {
        SHOW_SYNTAX_ERROR("expected expression before ')' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6085 "bison.tab.c"
    break;

  case 40: /* flowExpression: condExpression  */
#line 429 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6093 "bison.tab.c"
    break;

  case 41: /* flowExpression: interationExpression  */
#line 432 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6101 "bison.tab.c"
    break;

  case 42: /* flowExpression: returnExpression ';'  */
#line 435 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 6109 "bison.tab.c"
    break;

  case 43: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 441 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "if cond expression", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6119 "bison.tab.c"
    break;

  case 44: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 446 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "ifelse cond expression", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6130 "bison.tab.c"
    break;

  case 45: /* condExpression: IF_TOKEN '(' error ')' statement  */
#line 454 "./src/bison.y"
                                                      {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6140 "bison.tab.c"
    break;

  case 46: /* condExpression: IF_TOKEN '(' error ')' statement ELSE_TOKEN statement  */
#line 460 "./src/bison.y"
                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6151 "bison.tab.c"
    break;

  case 47: /* condExpression: IF_TOKEN '(' expression ')' ELSE_TOKEN statement  */
#line 467 "./src/bison.y"
                                                       {
        SHOW_SYNTAX_ERROR("expected expression before 'else' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6162 "bison.tab.c"
    break;

  case 48: /* condExpression: IF_TOKEN '(' error ')' ELSE_TOKEN statement  */
#line 474 "./src/bison.y"
                                                  {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6172 "bison.tab.c"
    break;

  case 49: /* condExpression: IF_TOKEN error  */
#line 480 "./src/bison.y"
                     {
        SHOW_SYNTAX_ERROR("expected '(' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6181 "bison.tab.c"
    break;

  case 50: /* elseError: ELSE_TOKEN statement  */
#line 489 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6191 "bison.tab.c"
    break;

  case 51: /* elseError: error ELSE_TOKEN statement  */
#line 495 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6201 "bison.tab.c"
    break;

  case 52: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 503 "./src/bison.y"
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
#line 6216 "bison.tab.c"
    break;

  case 53: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ';' optExpression ')' statement  */
#line 515 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6228 "bison.tab.c"
    break;

  case 54: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ';' optExpression ')' statement  */
#line 523 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6240 "bison.tab.c"
    break;

  case 55: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' error ')' statement  */
#line 531 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6252 "bison.tab.c"
    break;

  case 56: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ')' statement  */
#line 539 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6263 "bison.tab.c"
    break;

  case 57: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ')' statement  */
#line 546 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6274 "bison.tab.c"
    break;

  case 58: /* interationExpression: FOR_TOKEN '(' error ')'  */
#line 553 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6283 "bison.tab.c"
    break;

  case 59: /* interationExpression: FOR_TOKEN error  */
#line 558 "./src/bison.y"
                      {
        SHOW_SYNTAX_ERROR("expected '(' token after 'for' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6292 "bison.tab.c"
    break;

  case 60: /* returnExpression: RETURN_TOKEN expression  */
#line 565 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6301 "bison.tab.c"
    break;

  case 61: /* returnExpression: RETURN_TOKEN error  */
#line 571 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'return' with no value, in function returning non-void || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6310 "bison.tab.c"
    break;

  case 62: /* optExpression: %empty  */
#line 578 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 6318 "bison.tab.c"
    break;

  case 63: /* optExpression: expression  */
#line 581 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6326 "bison.tab.c"
    break;

  case 64: /* expression: assignArith  */
#line 587 "./src/bison.y"
                {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6334 "bison.tab.c"
    break;

  case 65: /* expression: binArith  */
#line 590 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6342 "bison.tab.c"
    break;

  case 66: /* expression: listArith  */
#line 593 "./src/bison.y"
                {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6350 "bison.tab.c"
    break;

  case 67: /* expression: unaArith  */
#line 596 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6358 "bison.tab.c"
    break;

  case 68: /* expression: constant  */
#line 599 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6366 "bison.tab.c"
    break;

  case 69: /* expression: funcCall  */
#line 602 "./src/bison.y"
               {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6374 "bison.tab.c"
    break;

  case 70: /* expression: id  */
#line 605 "./src/bison.y"
         {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            
        } else {
            (yyval.astnode) = (yyvsp[0].astnode);
            (yyval.astnode)->context->dtype = (yyvsp[0].astnode)->context->dtype;
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
        }
    }
#line 6390 "bison.tab.c"
    break;

  case 71: /* expression: '(' expression ')'  */
#line 616 "./src/bison.y"
                         {
        (yyval.astnode) = (yyvsp[-1].astnode);
        // $$ = create_astnode_context(AST_EXPRESSION, "(exp)", @$);
        // insert_kid($2, $$);
    }
#line 6400 "bison.tab.c"
    break;

  case 72: /* expression: id error  */
#line 623 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyvsp[-1].astnode) = NULL;
        (yyval.astnode) = NULL;
    }
#line 6411 "bison.tab.c"
    break;

  case 73: /* $@3: %empty  */
#line 632 "./src/bison.y"
       {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        } else {
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
        }
    }
#line 6424 "bison.tab.c"
    break;

  case 74: /* assignArith: id $@3 ASSIGN_TOKEN expression  */
#line 639 "./src/bison.y"
                              {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign", (yyloc));
        (yyval.astnode)->context->operation = strdup("=");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6435 "bison.tab.c"
    break;

  case 75: /* binArith: expression OR_TOKEN expression  */
#line 648 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}", (yyloc));
        (yyval.astnode)->context->operation = strdup("||");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6446 "bison.tab.c"
    break;

  case 76: /* binArith: expression AND_TOKEN expression  */
#line 654 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}", (yyloc));
        (yyval.astnode)->context->operation = strdup("&&");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6457 "bison.tab.c"
    break;

  case 77: /* binArith: expression EQUAL_TOKEN expression  */
#line 660 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}", (yyloc));
        (yyval.astnode)->context->operation = strdup("==");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6468 "bison.tab.c"
    break;

  case 78: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 666 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}", (yyloc));
        (yyval.astnode)->context->operation = strdup("!=");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6479 "bison.tab.c"
    break;

  case 79: /* binArith: expression LESS_TOKEN expression  */
#line 672 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}", (yyloc));
        (yyval.astnode)->context->operation = strdup("<");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6490 "bison.tab.c"
    break;

  case 80: /* binArith: expression LE_EQ_TOKEN expression  */
#line 678 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}", (yyloc));
        (yyval.astnode)->context->operation = strdup("<=");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6501 "bison.tab.c"
    break;

  case 81: /* binArith: expression GREAT_TOKEN expression  */
#line 684 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}", (yyloc));
        (yyval.astnode)->context->operation = strdup(">");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6512 "bison.tab.c"
    break;

  case 82: /* binArith: expression GR_EQ_TOKEN expression  */
#line 690 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}", (yyloc));
        (yyval.astnode)->context->operation = strdup(">=");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6523 "bison.tab.c"
    break;

  case 83: /* binArith: expression '+' expression  */
#line 696 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}", (yyloc));
        (yyval.astnode)->context->operation = strdup("+");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6534 "bison.tab.c"
    break;

  case 84: /* binArith: expression '-' expression  */
#line 702 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}", (yyloc));
        (yyval.astnode)->context->operation = strdup("-");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6545 "bison.tab.c"
    break;

  case 85: /* binArith: expression '*' expression  */
#line 708 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}", (yyloc));
        (yyval.astnode)->context->operation = strdup("*");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6556 "bison.tab.c"
    break;

  case 86: /* binArith: expression '/' expression  */
#line 714 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}", (yyloc));
        (yyval.astnode)->context->operation = strdup("/");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6567 "bison.tab.c"
    break;

  case 87: /* binArith: expression OR_TOKEN error  */
#line 721 "./src/bison.y"
                                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6577 "bison.tab.c"
    break;

  case 88: /* binArith: expression AND_TOKEN error  */
#line 726 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6587 "bison.tab.c"
    break;

  case 89: /* binArith: expression EQUAL_TOKEN error  */
#line 731 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6597 "bison.tab.c"
    break;

  case 90: /* binArith: expression DIFF_EQ_TOKEN error  */
#line 736 "./src/bison.y"
                                     {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6607 "bison.tab.c"
    break;

  case 91: /* binArith: expression LESS_TOKEN error  */
#line 741 "./src/bison.y"
                                  {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6617 "bison.tab.c"
    break;

  case 92: /* binArith: expression LE_EQ_TOKEN error  */
#line 746 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6627 "bison.tab.c"
    break;

  case 93: /* binArith: expression GREAT_TOKEN error  */
#line 751 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6637 "bison.tab.c"
    break;

  case 94: /* binArith: expression GR_EQ_TOKEN error  */
#line 756 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6647 "bison.tab.c"
    break;

  case 95: /* binArith: expression '+' error  */
#line 761 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6657 "bison.tab.c"
    break;

  case 96: /* binArith: expression '-' error  */
#line 766 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6667 "bison.tab.c"
    break;

  case 97: /* binArith: expression '*' error  */
#line 771 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6677 "bison.tab.c"
    break;

  case 98: /* binArith: expression '/' error  */
#line 776 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6687 "bison.tab.c"
    break;

  case 99: /* listArith: expression MAP_TOKEN expression  */
#line 784 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}", (yyloc));
        (yyval.astnode)->context->operation = strdup(">>");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6698 "bison.tab.c"
    break;

  case 100: /* listArith: expression FILTER_TOKEN expression  */
#line 790 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}", (yyloc));
        (yyval.astnode)->context->operation = strdup("<<");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6709 "bison.tab.c"
    break;

  case 101: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 796 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}", (yyloc));
        (yyval.astnode)->context->operation = strdup(":");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6720 "bison.tab.c"
    break;

  case 102: /* listArith: expression MAP_TOKEN error  */
#line 803 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6730 "bison.tab.c"
    break;

  case 103: /* listArith: expression FILTER_TOKEN error  */
#line 808 "./src/bison.y"
                                    {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6740 "bison.tab.c"
    break;

  case 104: /* listArith: expression CONSTRUCTOR_LIST_TOKEN error  */
#line 813 "./src/bison.y"
                                              {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6750 "bison.tab.c"
    break;

  case 105: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 821 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}", (yyloc));
        (yyval.astnode)->context->operation = strdup("!");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6760 "bison.tab.c"
    break;

  case 106: /* unaArith: QUESTION_TOKEN expression  */
#line 826 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}", (yyloc));
        (yyval.astnode)->context->operation = strdup("?");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6770 "bison.tab.c"
    break;

  case 107: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 831 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}", (yyloc));
        (yyval.astnode)->context->operation = strdup("%");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6780 "bison.tab.c"
    break;

  case 108: /* unaArith: '+' expression  */
#line 836 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}", (yyloc));
        (yyval.astnode)->context->operation = strdup("+");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6790 "bison.tab.c"
    break;

  case 109: /* unaArith: '-' expression  */
#line 841 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}", (yyloc));
        (yyval.astnode)->context->operation = strdup("-");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6800 "bison.tab.c"
    break;

  case 110: /* unaArith: EXCLAMATION_TOKEN error  */
#line 847 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6809 "bison.tab.c"
    break;

  case 111: /* unaArith: QUESTION_TOKEN error  */
#line 851 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6818 "bison.tab.c"
    break;

  case 112: /* unaArith: PERCENTAGE_TOKEN error  */
#line 855 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6827 "bison.tab.c"
    break;

  case 113: /* unaArith: '+' error  */
#line 859 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6836 "bison.tab.c"
    break;

  case 114: /* unaArith: '-' error  */
#line 863 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6845 "bison.tab.c"
    break;

  case 115: /* constant: constantInteger  */
#line 870 "./src/bison.y"
                    {
        // $$ = create_astnode_context(AST_CONSTANT, "constant int", @$);
        // $$->context->dtype = DTYPE_INT;
        // insert_kid($1, $$);
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6856 "bison.tab.c"
    break;

  case 116: /* constant: constantReal  */
#line 876 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6864 "bison.tab.c"
    break;

  case 117: /* constant: constantNIL  */
#line 879 "./src/bison.y"
                  {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6872 "bison.tab.c"
    break;

  case 118: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 885 "./src/bison.y"
                           {
        (yyvsp[0].astnode)->context->dtype = DTYPE_INT;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6881 "bison.tab.c"
    break;

  case 119: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 892 "./src/bison.y"
                        {
        (yyvsp[0].astnode)->context->dtype = DTYPE_FLOAT;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6890 "bison.tab.c"
    break;

  case 120: /* constantNIL: NIL_TOKEN  */
#line 899 "./src/bison.y"
              {
        (yyvsp[0].astnode)->context->dtype = DTYPE_LIST;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6899 "bison.tab.c"
    break;

  case 121: /* $@4: %empty  */
#line 906 "./src/bison.y"
       {
       Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            
        } else {
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
        }
    }
#line 6913 "bison.tab.c"
    break;

  case 122: /* funcCall: id $@4 '(' optListExpression ')'  */
#line 914 "./src/bison.y"
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
#line 6932 "bison.tab.c"
    break;

  case 123: /* @5: %empty  */
#line 931 "./src/bison.y"
                               {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            
        } else {
            (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "read call", (yyloc));
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
            (yyvsp[0].astnode)->context->sym_ref = has_sym;
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
        }
    }
#line 6949 "bison.tab.c"
    break;

  case 124: /* ioCommand: READ_TOKEN '(' id @5 ')'  */
#line 942 "./src/bison.y"
          {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 6957 "bison.tab.c"
    break;

  case 125: /* ioCommand: WRITE_TOKEN '(' expression ')'  */
#line 945 "./src/bison.y"
                                     {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "write call", (yyloc));
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 6967 "bison.tab.c"
    break;

  case 126: /* ioCommand: WRITE_TOKEN '(' STRING_TOKEN ')'  */
#line 950 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "write call", (yyloc));
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 6977 "bison.tab.c"
    break;

  case 127: /* ioCommand: WRITE_TOKEN '(' error ')'  */
#line 957 "./src/bison.y"
                                {
       SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
       delete_astnode((yyvsp[-3].astnode));
       (yyval.astnode) = NULL;
    }
#line 6987 "bison.tab.c"
    break;

  case 128: /* ioCommand: WRITE_TOKEN '(' error ')' ';'  */
#line 963 "./src/bison.y"
                                    {
       SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
       delete_astnode((yyvsp[-4].astnode));
       (yyval.astnode) = NULL;
    }
#line 6997 "bison.tab.c"
    break;

  case 129: /* ioCommand: READ_TOKEN '(' error ')'  */
#line 970 "./src/bison.y"
                               {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        (yyval.astnode) = NULL;
    }
#line 7007 "bison.tab.c"
    break;

  case 130: /* ioCommand: READ_TOKEN '(' error ')' ';'  */
#line 975 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        (yyval.astnode) = NULL;
    }
#line 7017 "bison.tab.c"
    break;

  case 131: /* ioCommand: READ_TOKEN error ';'  */
#line 980 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected '(' token after 'read' || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 7027 "bison.tab.c"
    break;

  case 132: /* ioCommand: WRITE_TOKEN error ';'  */
#line 985 "./src/bison.y"
                            {
        SHOW_SYNTAX_ERROR("expected '(' token after 'write' || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 7037 "bison.tab.c"
    break;

  case 133: /* optListExpression: %empty  */
#line 993 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 7045 "bison.tab.c"
    break;

  case 135: /* listExpression: listExpression ',' expression  */
#line 1000 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 7054 "bison.tab.c"
    break;

  case 136: /* listExpression: expression  */
#line 1004 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 7063 "bison.tab.c"
    break;

  case 137: /* id: ID_TOKEN  */
#line 1011 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 7071 "bison.tab.c"
    break;

  case 138: /* type: INT_TOKEN  */
#line 1017 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT, (yyvsp[0].string), (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_INT;
        free((yyvsp[0].string));
    }
#line 7081 "bison.tab.c"
    break;

  case 139: /* type: FLOAT_TOKEN  */
#line 1022 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT, (yyvsp[0].string), (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_FLOAT;
        free((yyvsp[0].string));
    }
#line 7091 "bison.tab.c"
    break;

  case 140: /* type: INT_TOKEN LIST_TOKEN  */
#line 1027 "./src/bison.y"
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
#line 7107 "bison.tab.c"
    break;

  case 141: /* type: FLOAT_TOKEN LIST_TOKEN  */
#line 1038 "./src/bison.y"
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
#line 7123 "bison.tab.c"
    break;


#line 7127 "bison.tab.c"

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

#line 1051 "./src/bison.y"


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

    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_list(list_context, delete_list_treenode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
