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

    #define FUNCTION 1
    #define VARIABLE 0

    #define RED "\033[1;31m"
    #define RESET "\033[0m"
    #define SEMANTIC_ERROR(__STR_ERR__, ...) \
            printf(RED"Semantic error: "RESET __STR_ERR__, ##__VA_ARGS__);

    extern int error, num_line, num_col;

    int semantic_error = 0;

    // static int symbol_id;

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

    /* Tabela de simbolos */
    // SymbolTable *symbol_table;

    void delete_single_node(Element *node);
    void delete_list_treenode(Element *elem);
    void delete_tree_symbol_table(void *sym);


#line 125 "bison.tab.c"

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
  YYSYMBOL_MAP_TOKEN = 16,                 /* MAP_TOKEN  */
  YYSYMBOL_FILTER_TOKEN = 17,              /* FILTER_TOKEN  */
  YYSYMBOL_CONSTRUCTOR_LIST_TOKEN = 18,    /* CONSTRUCTOR_LIST_TOKEN  */
  YYSYMBOL_ADD_MIN_TOKEN = 19,             /* ADD_MIN_TOKEN  */
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
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_variableDeclare = 56,           /* variableDeclare  */
  YYSYMBOL_functionDeclare = 57,           /* functionDeclare  */
  YYSYMBOL_58_1 = 58,                      /* @1  */
  YYSYMBOL_optListParams = 59,             /* optListParams  */
  YYSYMBOL_listParams = 60,                /* listParams  */
  YYSYMBOL_param = 61,                     /* param  */
  YYSYMBOL_compoundStatement = 62,         /* compoundStatement  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_optListCodeBlock = 64,          /* optListCodeBlock  */
  YYSYMBOL_listCodeBlock = 65,             /* listCodeBlock  */
  YYSYMBOL_codeBlock = 66,                 /* codeBlock  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_flowExpression = 68,            /* flowExpression  */
  YYSYMBOL_condExpression = 69,            /* condExpression  */
  YYSYMBOL_interationExpression = 70,      /* interationExpression  */
  YYSYMBOL_returnExpression = 71,          /* returnExpression  */
  YYSYMBOL_optExpression = 72,             /* optExpression  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_74_3 = 74,                      /* $@3  */
  YYSYMBOL_binArith = 75,                  /* binArith  */
  YYSYMBOL_listArith = 76,                 /* listArith  */
  YYSYMBOL_unaArith = 77,                  /* unaArith  */
  YYSYMBOL_constant = 78,                  /* constant  */
  YYSYMBOL_constantInteger = 79,           /* constantInteger  */
  YYSYMBOL_constantReal = 80,              /* constantReal  */
  YYSYMBOL_constantNIL = 81,               /* constantNIL  */
  YYSYMBOL_constantString = 82,            /* constantString  */
  YYSYMBOL_funcCall = 83,                  /* funcCall  */
  YYSYMBOL_84_4 = 84,                      /* $@4  */
  YYSYMBOL_85_5 = 85,                      /* $@5  */
  YYSYMBOL_optListExpression = 86,         /* optListExpression  */
  YYSYMBOL_listExpression = 87,            /* listExpression  */
  YYSYMBOL_id = 88,                        /* id  */
  YYSYMBOL_type = 89                       /* type  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6893

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  327

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
       0,   125,   125,   128,   134,   137,   143,   162,   162,   209,
     212,   216,   220,   227,   245,   245,   280,   283,   287,   291,
     298,   302,   309,   313,   317,   324,   327,   330,   336,   341,
     350,   363,   370,   373,   379,   379,   390,   394,   398,   402,
     406,   410,   420,   427,   432,   437,   442,   447,   452,   457,
     462,   467,   472,   477,   482,   490,   495,   500,   508,   512,
     516,   520,   524,   531,   535,   539,   543,   550,   556,   562,
     568,   574,   574,   594,   594,   605,   622,   625,   629,   633,
     640,   646,   649,   652,   660
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
  "EXCLAMATION_TOKEN", "QUESTION_TOKEN", "PERCENTAGE_TOKEN", "MAP_TOKEN",
  "FILTER_TOKEN", "CONSTRUCTOR_LIST_TOKEN", "ADD_MIN_TOKEN",
  "ASSIGN_TOKEN", "OR_TOKEN", "AND_TOKEN", "EQ_EXC_TOKEN", "LE_GR_TOKEN",
  "ADD_UNARY_TOKEN", "MIN_UNARY_TOKEN", "EQUAL_TOKEN", "DIFF_EQ_TOKEN",
  "LESS_TOKEN", "LE_EQ_TOKEN", "GREAT_TOKEN", "GR_EQ_TOKEN", "ADD_TOKEN",
  "MIN_TOKEN", "MUL_TOKEN", "DIV_TOKEN", "UNI_OP", "IF_TOKEN",
  "ELSE_TOKEN", "FOR_TOKEN", "RETURN_TOKEN", "STRING_TOKEN", "'+'", "'-'",
  "'*'", "'/'", "';'", "'('", "')'", "','", "'{'", "'}'", "$accept",
  "startProgram", "declaration", "variableDeclare", "functionDeclare",
  "@1", "optListParams", "listParams", "param", "compoundStatement", "$@2",
  "optListCodeBlock", "listCodeBlock", "codeBlock", "statement",
  "flowExpression", "condExpression", "interationExpression",
  "returnExpression", "optExpression", "expression", "$@3", "binArith",
  "listArith", "unaArith", "constant", "constantInteger", "constantReal",
  "constantNIL", "constantString", "funcCall", "$@4", "$@5",
  "optListExpression", "listExpression", "id", "type", YY_NULLPTR
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

#define YYPACT_NINF (-264)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    23,    85,    64,    82,    84,   117,    13,    42,    45,
    -264,   119,    77,   110,   136,     1,     5,     4,    62,   111,
      56,    15,    14,   113,    90,   150,   115,  1492,     7,    21,
    5534,  5566,  5598,  2455,  2455,  2455,    41,    44,  2455,  5630,
    2455,  2455,  2498,  1570,  1673,    26,  1751,  1854,  1932,  2035,
    2109,  2129,    48,  5662,  5694,  5726,  5758,  5790,  5822,  5854,
    5886,  5918,  5950,    -6,    96,   100,  2055,  5982,  6014,  6046,
    2498,    66,  6078,  6110,  6142,  4005,   152,  2179,  2194,  2455,
    2455,  2455,  2455,  2455,  2455,  2455,  2455,  2455,  2455,  2455,
    2455,  2455,  2455,  2455,  2244,   107,    87,    99,    88,  2537,
     102,   127,  4039,   112,  6174,  6206,  6238,  6270,  6302,  6334,
    6366,  6398,  6430,  6462,  6494,  6526,  6558,  6590,  6622,  6654,
    6686,  2455,  2055,   118,  6718,  2508,  2389,    66,  6750,   122,
    6782,  2572,   406,   134,  6814,  2435,  2445,  2259,   133,  2435,
    2309,   129,  5501,    90,  3937,   135,   178,  4073,  4107,  4141,
    2498,  2498,  2498,  4175,  2498,  2498,  2498,  4209,  4243,  4277,
    4311,  4345,  4379,  4413,  4447,  4481,  3971,   137,   151,   300,
     186,   188,  2607,  2642,  2677,  2508,  2508,  2508,  2712,  2508,
    2508,  2498,  2747,  2782,  2817,  2852,  2887,  2922,  2957,  2992,
    3027,   505,  2498,  2498,  2498,  2498,  2498,  2498,  2498,  2498,
    2498,  2498,  2498,  2498,  2498,  2498,  2498,  2324,  2508,  2508,
    2508,  2508,  2508,  2508,  2508,  2508,  2508,  2508,  2508,  2508,
    2508,  2508,  2508,   192,   196,    90,   587,   665,   768,   846,
     199,  6846,  4515,  1492,   100,  2055,  4549,  4583,  4617,  4651,
    4685,  4719,   146,   200,   100,  2055,  3062,  3097,  3132,  3167,
    3202,  4753,   230,   204,  4787,  4821,  4855,  4889,  4923,  4957,
    4991,  5025,  5059,  5093,  5127,  5161,  5195,  5229,  5263,  3237,
    3272,  3307,  3342,  3377,  3412,  3447,  3482,  3517,  3552,  3587,
    3622,  3657,  3692,  3727,  2498,    66,  1492,   949,  1027,   205,
      88,   209,  5297,  2498,  2055,    88,   210,  3762,  2508,  2055,
    5331,   213,   226,  2374,   212,  5365,  5399,   231,   232,  3797,
    3832,   233,  2389,    66,  1130,  5433,  5467,  3867,  3902,  1208,
     236,  2389,  2445,  1311,   235,  2389,  1389
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
    -264,  -264,   276,    30,  -264,  -264,  -264,  -264,   263,   -19,
    -142,  -226,  -264,   242,   -92,   -90,   -82,   -80,   -70,   -66,
     183,  -160,   364,   545,   726,   907,  1088,  1269,  1450,  1631,
    1812,  -146,  -263,  -119,  -264,    -7,    49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,    43,     6,    16,    17,    18,    19,    44,
      27,    45,    46,    47,    48,    49,    50,    51,    52,   103,
      53,    95,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    96,   123,   100,   101,    63,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,   233,    25,   129,    -7,    -7,   242,   289,     1,     2,
     -41,   -41,   -41,    23,   -34,   -41,   -41,     1,     2,    12,
     243,   -41,   -41,   -41,   -41,   -41,   -41,   304,     8,   -81,
       5,   252,   308,     5,   132,   166,   227,   -41,   -41,   -41,
     -41,   -41,   -71,   137,   228,   253,   229,   140,   -83,     7,
      -7,   -84,     7,    21,    -9,    65,   230,    97,    98,   191,
     302,   133,   141,   166,    10,    20,    24,     1,     2,    66,
     138,    20,   142,    28,    29,    30,    31,    32,    76,    33,
      34,    35,    -3,   286,    -4,    -3,    -3,    -4,    -4,    70,
       9,   -82,    71,   -14,   -14,    78,   -14,   -14,   -14,   -14,
     -14,   -14,   167,   -14,   -14,   -14,   168,   226,    39,    40,
      41,   -10,    22,   -32,    42,   191,   291,    -5,   191,    -2,
      -5,    -5,    -2,    -2,   -80,   -80,   296,   121,   -14,   166,
     -14,   -14,   -14,   -14,   -14,   122,    -6,   -73,   -14,    -6,
      -6,   -14,   -14,   166,   166,   166,   207,   166,   166,   166,
      -8,   124,   -15,    -8,    -8,   -15,   -15,    14,    15,   127,
     -12,   -12,   -13,   -13,   -11,   -11,   293,   130,   191,   191,
     191,   134,   191,   191,   166,   307,   -77,   125,   -80,   -80,
     311,   136,   139,   234,   -80,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     -80,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,    67,    68,    69,   301,
     319,    72,   227,    73,    74,    75,   235,   290,   191,   323,
     228,   227,   229,   326,   244,   227,   245,   295,   191,   228,
     284,   229,   230,   228,   285,   229,   287,   320,   294,    99,
     298,   230,   299,   102,   104,   230,   324,   303,   305,   309,
     313,   315,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   166,   314,    11,
     316,   317,   318,   322,   325,    26,   166,   191,    77,     0,
       0,   191,   191,   226,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,   128,    99,   226,     0,   131,   231,
     104,     0,     0,     0,     0,   166,   -80,   -80,   -80,   232,
     -80,   -80,   -80,     0,     0,     0,     0,   -80,   -80,   -80,
     -80,   -80,   -80,   236,   237,   238,     0,   239,   240,   241,
       0,     0,     0,   -80,   -80,   -80,   -80,     0,   -80,   -80,
     -80,     0,     0,     0,     0,     0,     0,     0,   246,   247,
     248,     0,   249,   250,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
       0,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   157,     0,     0,   -28,
     -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,    99,   -28,
     -28,   -28,     0,     0,     0,     0,     0,     0,    99,     0,
     182,     0,     0,     0,   157,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -28,   135,   -28,   -28,   -28,   -28,
     -28,     0,     0,     0,   -28,     0,     0,   -28,   -28,     0,
       0,     0,     0,     0,     0,     0,     0,   300,   104,     0,
       0,     0,     0,     0,     0,     0,   306,    99,     0,     0,
       0,   310,    99,     0,     0,     0,   182,     0,     0,   182,
       0,     0,     0,     0,     0,   231,   104,     0,     0,     0,
     157,     0,     0,     0,   231,   232,     0,     0,   231,     0,
       0,     0,     0,     0,   157,   157,   157,     0,   157,   157,
     157,   -41,   -41,   -41,     0,   -34,   -41,   -41,     0,     0,
       0,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,   182,
     182,   182,     0,   182,   182,   157,     0,     0,   -41,   -41,
     -41,   -41,     0,   -71,   -41,   -41,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,     0,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   158,     0,     0,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,   182,
     -23,   -23,   -23,     0,     0,     0,     0,     0,     0,   182,
       0,   183,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,     0,     0,   -23,     0,     0,   -23,   -23,
       0,     0,     0,     0,     0,     0,     0,     0,   157,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   182,     0,
       0,     0,   182,   182,     0,     0,     0,   183,   -22,   -22,
     183,   -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,
     -22,   158,     0,     0,     0,     0,   157,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   158,   158,     0,   158,
     158,   158,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
       0,     0,     0,   -22,     0,     0,   -22,   -22,     0,     0,
     183,   183,   183,     0,   183,   183,   158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,     0,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   159,     0,
       0,   -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,   -25,
     183,   -25,   -25,   -25,     0,     0,     0,     0,     0,     0,
     183,     0,   184,     0,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,     0,     0,     0,   -25,     0,     0,   -25,
     -25,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   183,
       0,     0,     0,   183,   183,     0,     0,     0,   184,   -26,
     -26,   184,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,
     -26,   -26,   159,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   159,   159,     0,
     159,   159,   159,     0,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,     0,     0,     0,   -26,     0,     0,   -26,   -26,     0,
       0,   184,   184,   184,     0,   184,   184,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,     0,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   160,
       0,     0,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,
     -27,   184,   -27,   -27,   -27,     0,     0,     0,     0,     0,
       0,   184,     0,   185,     0,     0,     0,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,     0,     0,   -27,     0,     0,
     -27,   -27,     0,     0,     0,     0,     0,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     184,     0,     0,     0,   184,   184,     0,     0,     0,   185,
     -24,   -24,   185,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -24,   -24,   -24,   160,     0,     0,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   160,   160,
       0,   160,   160,   160,     0,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,     0,     0,   -24,     0,     0,   -24,   -24,
       0,     0,   185,   185,   185,     0,   185,   185,   160,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,     0,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     161,     0,     0,   -15,   -15,     0,   -15,   -15,   -15,   -15,
     -15,   -15,   185,   -15,   -15,   -15,     0,     0,     0,     0,
       0,     0,   185,     0,   186,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,     0,     0,     0,   -15,     0,
       0,   -15,   -15,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   185,     0,     0,     0,   185,   185,     0,     0,     0,
     186,   -28,   -28,   186,   -28,   -28,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   -28,   161,     0,     0,     0,     0,   160,
       0,     0,     0,     0,     0,     0,     0,     0,   161,   161,
     161,     0,   161,   161,   161,     0,   -28,   321,   -28,   -28,
     -28,   -28,   -28,     0,     0,     0,   -28,     0,     0,   -28,
     -28,     0,     0,   186,   186,   186,     0,   186,   186,   161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,     0,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   162,     0,     0,   -29,   -29,     0,   -29,   -29,   -29,
     -29,   -29,   -29,   186,   -29,   -29,   -29,     0,     0,     0,
       0,     0,     0,   186,     0,   187,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,     0,     0,     0,   -29,
       0,     0,   -29,   -29,     0,     0,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   186,     0,     0,     0,   186,   186,     0,     0,
       0,   187,   -30,   -30,   187,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,   -30,   162,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     162,   162,     0,   162,   162,   162,     0,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,     0,     0,     0,   -30,     0,     0,
     -30,   -30,     0,     0,   187,   187,   187,     0,   187,   187,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,     0,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   163,     0,     0,     1,     2,     0,   142,    28,
      29,    30,    31,    32,   187,    33,    34,    35,     0,     0,
       0,     0,     0,     0,   187,     0,   188,     0,     0,     0,
     163,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,    37,    38,    39,    40,    41,     0,     0,     0,
      42,     0,     0,   143,   -16,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   187,     0,     0,     0,   187,   187,     0,
       0,     0,   188,   -21,   -21,   188,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,   -21,   -21,   163,     0,     0,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
     163,   163,   163,     0,   163,   163,   163,     0,   -21,     0,
     -21,   -21,   -21,   -21,   -21,     0,     0,     0,   -21,     0,
       0,   -21,   -21,     0,     0,   188,   188,   188,     0,   188,
     188,   163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,     0,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   164,     0,     0,   -23,   -23,     0,   -23,
     -23,   -23,   -23,   -23,   -23,   188,   -23,   -23,   -23,     0,
       0,     0,     0,     0,     0,   188,     0,   189,     0,     0,
       0,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -23,     0,   -23,   -23,   -23,   -23,   -23,     0,     0,
       0,   -23,     0,     0,   -23,   -23,     0,     0,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   188,     0,     0,     0,   188,   188,
       0,     0,     0,   189,     1,     2,   189,   142,    28,    29,
      30,    31,    32,     0,    33,    34,    35,   164,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   164,   164,     0,   164,   164,   164,     0,    36,
       0,    37,    38,    39,    40,    41,     0,     0,     0,    42,
       0,     0,   143,   -17,     0,     0,   189,   189,   189,     0,
     189,   189,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,     0,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   165,     0,     0,   -19,   -19,     0,
     -19,   -19,   -19,   -19,   -19,   -19,   189,   -19,   -19,   -19,
       0,     0,     0,     0,     0,     0,   189,     0,   190,     0,
       0,     0,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -19,     0,   -19,   -19,   -19,   -19,   -19,     0,
       0,     0,   -19,     0,     0,   -19,   -19,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   189,     0,     0,     0,   189,
     189,     0,     0,     0,   190,   -20,   -20,   190,   -20,   -20,
     -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,   165,     0,
       0,     0,     0,   164,     0,     0,     0,     0,     0,     0,
       0,     0,   165,   165,   165,     0,   165,   165,   165,     0,
     -20,     0,   -20,   -20,   -20,   -20,   -20,     0,     0,     0,
     -20,     0,     0,   -20,   -20,     0,     0,   190,   190,   190,
       0,   190,   190,   165,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,     0,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,     0,     0,     0,   -22,   -22,
       0,   -22,   -22,   -22,   -22,   -22,   -22,   190,   -22,   -22,
     -22,     0,     0,     0,     0,     0,     0,   190,     0,     0,
       0,   169,   170,   171,   172,   173,   174,     0,   175,   176,
     177,     0,     0,   -22,     0,   -22,   -22,   -22,   -22,   -22,
       0,     0,     0,   -22,     0,     0,   -22,   -22,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   178,   179,   180,
       0,     0,     0,   181,   -76,   165,   190,     0,     0,     0,
     190,   190,   -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,
     -25,     0,   -25,   -25,   -25,     0,     0,     0,     0,     0,
       0,     0,   -26,   -26,   165,   -26,   -26,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,     0,     0,   -25,     0,   -25,
     -25,   -25,   -25,   -25,     0,     0,     0,   -25,     0,     0,
     -25,   -25,     0,     0,     0,     0,     0,   -26,     0,   -26,
     -26,   -26,   -26,   -26,     0,     0,     0,   -26,     0,     0,
     -26,   -26,   -18,   -18,     0,   -18,   -18,   -18,   -18,   -18,
     -18,     0,   -18,   -18,   -18,     0,     0,   -27,   -27,     0,
     -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,
       0,     0,     0,     0,     0,     0,     0,   -18,     0,   -18,
     -18,   -18,   -18,   -18,     0,     0,     0,   -18,     0,     0,
     -18,   -18,   -27,     0,   -27,   -27,   -27,   -27,   -27,     0,
       0,     0,   -27,     0,     0,   -27,   -27,   -24,   -24,     0,
     -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,
       0,     0,   -29,   -29,     0,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,     0,     0,     0,     0,     0,
       0,     0,   -24,     0,   -24,   -24,   -24,   -24,   -24,     0,
       0,     0,   -24,     0,     0,   -24,   -24,   -29,     0,   -29,
     -29,   -29,   -29,   -29,     0,     0,     0,   -29,     0,     0,
     -29,   -29,   -30,   -30,     0,   -30,   -30,   -30,   -30,   -30,
     -30,     0,   -30,   -30,   -30,     0,     0,    -6,    -6,     0,
      -6,    -6,    -6,    -6,    -6,    -6,     0,    -6,    -6,    -6,
       0,     0,     0,     0,     0,     0,     0,   -30,     0,   -30,
     -30,   -30,   -30,   -30,     0,     0,     0,   -30,     0,     0,
     -30,   -30,    -6,     0,    -6,    -6,    -6,    -6,    -6,     0,
       0,     0,    -6,     0,     0,    -6,    -6,   -15,   -15,     0,
     -15,   -15,   -15,   -15,   -15,   -15,     0,   -15,   -15,   -15,
       0,     0,     0,     0,     0,   142,    28,    29,    30,    31,
      32,     0,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,   -15,     0,   -15,   -15,   -15,   -15,   -15,     0,
       0,     0,   -15,     0,     0,   -15,   -15,   223,     0,   224,
      38,    39,    40,    41,     0,     0,     0,    42,     0,     0,
     225,   142,    28,    29,    30,    31,    32,     0,    33,    34,
      35,   144,   145,   146,   147,   148,   149,     0,   150,   151,
     152,   142,    28,    29,    30,    31,    32,     0,    33,    34,
      35,     0,     0,    36,     0,    37,    38,    39,    40,    41,
       0,     0,     0,    42,     0,     0,   143,   153,   154,   155,
       0,     0,     0,   156,   -32,     0,     0,    39,    40,    41,
       0,     0,     0,    42,   144,   145,   146,   147,   148,   149,
       0,   150,   151,   152,   169,   170,   171,   172,   173,   174,
       0,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   155,     0,     0,     0,   156,     0,     0,     0,
     178,   179,   180,   208,   209,   210,   181,     0,   211,   212,
       0,     0,     0,     0,   213,   214,   215,   216,   217,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -79,   -79,   208,   209,
     210,     0,     0,   211,   212,     0,     0,     0,     0,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -78,   -78,   -69,   -69,   -69,     0,     0,   -69,   -69,
       0,     0,     0,     0,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -69,   -69,   -69,   -69,     0,     0,   -69,   -69,   -68,   -68,
     -68,     0,     0,   -68,   -68,     0,     0,     0,     0,   -68,
     -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -68,   -68,   -68,   -68,     0,
       0,   -68,   -68,   -67,   -67,   -67,     0,     0,   -67,   -67,
       0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,   -67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -67,   -67,   -67,   -67,     0,     0,   -67,   -67,   -70,   -70,
     -70,     0,     0,   -70,   -70,     0,     0,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -70,   -70,   -70,   -70,     0,
       0,   -70,   -70,   -36,   -36,   -36,     0,     0,   -36,   -36,
       0,     0,     0,     0,   -36,   -36,   -36,   -36,   -36,   -36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -36,   -36,   -36,   -36,     0,     0,   -36,   -36,   -37,   -37,
     -37,     0,     0,   -37,   -37,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,     0,
       0,   -37,   -37,   -38,   -38,   -38,     0,     0,   -38,   -38,
       0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -38,   -38,   -38,   -38,     0,     0,   -38,   -38,   -39,   -39,
     -39,     0,     0,   -39,   -39,     0,     0,     0,     0,   -39,
     -39,   -39,   -39,   -39,   -39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -39,   -39,   -39,   -39,     0,
       0,   -39,   -39,   -63,   -63,   -63,     0,     0,   -63,   -63,
       0,     0,     0,     0,   -63,   -63,   -63,   -63,   -63,   -63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -63,   -63,   -63,   -63,     0,     0,   -63,   -63,   -64,   -64,
     -64,     0,     0,   -64,   -64,     0,     0,     0,     0,   -64,
     -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -64,   -64,   -64,   -64,     0,
       0,   -64,   -64,   -65,   -65,   -65,     0,     0,   -65,   -65,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -65,   -65,   -65,   -65,     0,     0,   -65,   -65,   -66,   -66,
     -66,     0,     0,   -66,   -66,     0,     0,     0,     0,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,   -66,     0,
       0,   -66,   -66,   -40,   -40,   -40,     0,     0,   -40,   -40,
       0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,   -40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -40,   -40,   -40,   -40,     0,     0,   -40,   -40,   -58,   -58,
     -58,     0,     0,   -58,   -58,     0,     0,     0,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -58,   -58,   -58,   -58,     0,
       0,   -58,   -58,   -59,   -59,   -59,     0,     0,   -59,   -59,
       0,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -59,   -59,   -59,   -59,     0,     0,   -59,   -59,   -60,   -60,
     -60,     0,     0,   -60,   -60,     0,     0,     0,     0,   -60,
     -60,   -60,   -60,   -60,   -60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -60,   -60,   -60,   -60,     0,
       0,   -60,   -60,   -61,   -61,   -61,     0,     0,   -61,   -61,
       0,     0,     0,     0,   -61,   -61,   -61,   -61,   -61,   -61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -61,   -61,   -61,   -61,     0,     0,   -61,   -61,   -62,   -62,
     -62,     0,     0,   -62,   -62,     0,     0,     0,     0,   -62,
     -62,   -62,   -62,   -62,   -62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -62,   -62,   -62,   -62,     0,
       0,   -62,   -62,   -55,   209,   210,     0,     0,   -55,   -55,
       0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -55,   -55,   -56,   -56,
     210,     0,     0,   -56,   -56,     0,     0,     0,     0,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -56,   -56,   -57,   -57,   -57,     0,     0,   -57,   -57,
       0,     0,     0,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -57,   -57,   208,   209,
     210,     0,     0,   -43,   212,     0,     0,     0,     0,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -43,   -43,   208,   209,   210,     0,     0,   -44,   -44,
       0,     0,     0,     0,   213,   214,   215,   216,   217,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -44,   -44,   208,   209,
     210,     0,     0,   -45,   -45,     0,     0,     0,     0,   -45,
     -45,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -45,   -45,   208,   209,   210,     0,     0,   -46,   -46,
       0,     0,     0,     0,   -46,   -46,   215,   216,   217,   218,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -46,   -46,   208,   209,
     210,     0,     0,   -47,   -47,     0,     0,     0,     0,   -47,
     -47,   -47,   -47,   -47,   -47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -47,   -47,   208,   209,   210,     0,     0,   -48,   -48,
       0,     0,     0,     0,   -48,   -48,   -48,   -48,   -48,   -48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -48,   -48,   208,   209,
     210,     0,     0,   -49,   -49,     0,     0,     0,     0,   -49,
     -49,   -49,   -49,   -49,   -49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -49,   -49,   208,   209,   210,     0,     0,   -50,   -50,
       0,     0,     0,     0,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   220,   221,   222,     0,     0,   -50,   -50,   -51,   -51,
     -51,     0,     0,   -51,   -51,     0,     0,     0,     0,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -51,   -51,   221,   222,     0,
       0,   -51,   -51,   -52,   -52,   -52,     0,     0,   -52,   -52,
       0,     0,     0,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -52,   -52,   221,   222,     0,     0,   -52,   -52,   -53,   -53,
     -53,     0,     0,   -53,   -53,     0,     0,     0,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -53,   -53,   -53,   -53,     0,
       0,   -53,   -53,   -54,   -54,   -54,     0,     0,   -54,   -54,
       0,     0,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -54,   -54,   -54,   -54,     0,     0,   -54,   -54,   -42,   -42,
     -42,     0,     0,   -42,   -42,     0,     0,     0,     0,   -42,
     -42,   -42,   -42,   -42,   -42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -42,   -42,   -42,   -42,     0,
       0,   -42,   -42,   -75,   -75,   -75,     0,     0,   -75,   -75,
       0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -75,   -75,   -75,   -75,     0,     0,   -75,   -75,   208,   209,
     210,     0,     0,   211,   212,     0,     0,     0,     0,   213,
     214,   215,   216,   217,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   221,   222,     0,
       0,   -35,   -35,   -74,   -74,   -74,     0,     0,   -74,   -74,
       0,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,   -74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -74,   -74,   -74,   -74,     0,     0,   -74,   -74,   -72,   -72,
     -72,     0,     0,   -72,   -72,     0,     0,     0,     0,   -72,
     -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,     0,
       0,   -72,   -72,   -80,   -80,   -80,     0,   -80,   -80,   -80,
       0,     0,     0,     0,   -80,   -80,   -80,   -80,   -80,   -80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -80,   -80,   -80,   -80,     0,   -80,   -80,   -41,   -41,   -41,
       0,   -34,   -41,   -41,     0,     0,     0,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -41,   -41,   -41,   -41,     0,   -71,
     -41,   192,   193,   194,     0,     0,   195,   196,     0,     0,
       0,     0,   197,   198,   199,   200,   201,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   204,
     205,   206,     0,     0,   105,   192,   193,   194,     0,     0,
     195,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   204,   205,   206,     0,     0,   126,   -69,
     -69,   -69,     0,     0,   -69,   -69,     0,     0,     0,     0,
     -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -69,   -69,   -69,   -69,
       0,     0,   -69,   -68,   -68,   -68,     0,     0,   -68,   -68,
       0,     0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,     0,     0,   -68,   -67,   -67,   -67,
       0,     0,   -67,   -67,     0,     0,     0,     0,   -67,   -67,
     -67,   -67,   -67,   -67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -67,   -67,   -67,   -67,     0,     0,
     -67,   -70,   -70,   -70,     0,     0,   -70,   -70,     0,     0,
       0,     0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -70,   -70,
     -70,   -70,     0,     0,   -70,   -36,   -36,   -36,     0,     0,
     -36,   -36,     0,     0,     0,     0,   -36,   -36,   -36,   -36,
     -36,   -36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -36,   -36,   -36,   -36,     0,     0,   -36,   -37,
     -37,   -37,     0,     0,   -37,   -37,     0,     0,     0,     0,
     -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,
       0,     0,   -37,   -38,   -38,   -38,     0,     0,   -38,   -38,
       0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -38,   -38,   -38,   -38,     0,     0,   -38,   -39,   -39,   -39,
       0,     0,   -39,   -39,     0,     0,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   -39,     0,     0,
     -39,   -63,   -63,   -63,     0,     0,   -63,   -63,     0,     0,
       0,     0,   -63,   -63,   -63,   -63,   -63,   -63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -63,   -63,
     -63,   -63,     0,     0,   -63,   -64,   -64,   -64,     0,     0,
     -64,   -64,     0,     0,     0,     0,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -64,   -64,   -64,   -64,     0,     0,   -64,   -65,
     -65,   -65,     0,     0,   -65,   -65,     0,     0,     0,     0,
     -65,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -65,   -65,   -65,   -65,
       0,     0,   -65,   -66,   -66,   -66,     0,     0,   -66,   -66,
       0,     0,     0,     0,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -66,   -66,   -66,   -66,     0,     0,   -66,   -40,   -40,   -40,
       0,     0,   -40,   -40,     0,     0,     0,     0,   -40,   -40,
     -40,   -40,   -40,   -40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -40,   -40,   -40,   -40,     0,     0,
     -40,   192,   193,   194,     0,     0,   195,   196,     0,     0,
       0,     0,   197,   198,   199,   200,   201,   202,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   204,
     205,   206,     0,     0,   -33,   -58,   -58,   -58,     0,     0,
     -58,   -58,     0,     0,     0,     0,   -58,   -58,   -58,   -58,
     -58,   -58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -58,   -58,   -58,   -58,     0,     0,   -58,   -59,
     -59,   -59,     0,     0,   -59,   -59,     0,     0,     0,     0,
     -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -59,   -59,   -59,   -59,
       0,     0,   -59,   -60,   -60,   -60,     0,     0,   -60,   -60,
       0,     0,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -60,   -60,   -60,   -60,     0,     0,   -60,   -61,   -61,   -61,
       0,     0,   -61,   -61,     0,     0,     0,     0,   -61,   -61,
     -61,   -61,   -61,   -61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -61,   -61,   -61,   -61,     0,     0,
     -61,   -62,   -62,   -62,     0,     0,   -62,   -62,     0,     0,
       0,     0,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -62,   -62,
     -62,   -62,     0,     0,   -62,   192,   193,   194,     0,     0,
     195,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   204,   205,   206,     0,     0,   292,   192,
     193,   194,     0,     0,   195,   196,     0,     0,     0,     0,
     197,   198,   199,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   204,   205,   206,
       0,     0,   297,   -55,   193,   194,     0,     0,   -55,   -55,
       0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   204,   205,   206,     0,     0,   -55,   -56,   -56,   194,
       0,     0,   -56,   -56,     0,     0,     0,     0,   -56,   -56,
     -56,   -56,   -56,   -56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,   205,   206,     0,     0,
     -56,   -57,   -57,   -57,     0,     0,   -57,   -57,     0,     0,
       0,     0,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   204,
     205,   206,     0,     0,   -57,   192,   193,   194,     0,     0,
     -43,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   204,   205,   206,     0,     0,   -43,   192,
     193,   194,     0,     0,   -44,   -44,     0,     0,     0,     0,
     197,   198,   199,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   204,   205,   206,
       0,     0,   -44,   192,   193,   194,     0,     0,   -45,   -45,
       0,     0,     0,     0,   -45,   -45,   199,   200,   201,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   204,   205,   206,     0,     0,   -45,   192,   193,   194,
       0,     0,   -46,   -46,     0,     0,     0,     0,   -46,   -46,
     199,   200,   201,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,   205,   206,     0,     0,
     -46,   192,   193,   194,     0,     0,   -47,   -47,     0,     0,
       0,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   204,
     205,   206,     0,     0,   -47,   192,   193,   194,     0,     0,
     -48,   -48,     0,     0,     0,     0,   -48,   -48,   -48,   -48,
     -48,   -48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   204,   205,   206,     0,     0,   -48,   192,
     193,   194,     0,     0,   -49,   -49,     0,     0,     0,     0,
     -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   204,   205,   206,
       0,     0,   -49,   192,   193,   194,     0,     0,   -50,   -50,
       0,     0,     0,     0,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   204,   205,   206,     0,     0,   -50,   -51,   -51,   -51,
       0,     0,   -51,   -51,     0,     0,     0,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -51,   -51,   205,   206,     0,     0,
     -51,   -52,   -52,   -52,     0,     0,   -52,   -52,     0,     0,
       0,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -52,   -52,
     205,   206,     0,     0,   -52,   -53,   -53,   -53,     0,     0,
     -53,   -53,     0,     0,     0,     0,   -53,   -53,   -53,   -53,
     -53,   -53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -53,   -53,   -53,   -53,     0,     0,   -53,   -54,
     -54,   -54,     0,     0,   -54,   -54,     0,     0,     0,     0,
     -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -54,   -54,   -54,   -54,
       0,     0,   -54,   -42,   -42,   -42,     0,     0,   -42,   -42,
       0,     0,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -42,   -42,   -42,   -42,     0,     0,   -42,   192,   193,   194,
       0,     0,   195,   196,     0,     0,     0,     0,   197,   198,
     199,   200,   201,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,   205,   206,     0,     0,
     312,   -75,   -75,   -75,     0,     0,   -75,   -75,     0,     0,
       0,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -75,   -75,
     -75,   -75,     0,     0,   -75,   192,   193,   194,     0,     0,
     195,   196,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   202,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   204,   205,   206,     0,     0,   -35,   -74,
     -74,   -74,     0,     0,   -74,   -74,     0,     0,     0,     0,
     -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,
       0,     0,   -74,   -72,   -72,   -72,     0,     0,   -72,   -72,
       0,     0,     0,     0,   -72,   -72,   -72,   -72,   -72,   -72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -72,   -72,   -72,   -72,     0,     0,   -72,   -80,   -80,   -80,
       0,   -80,   -80,   -80,     0,     0,     0,     0,   -80,   -80,
     -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -80,   -80,   -80,   -80,   -80,   -80,
     -69,   -69,   -69,     0,     0,   -69,   -69,     0,     0,     0,
       0,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -69,   -69,   -69,
     -69,   -69,   -68,   -68,   -68,     0,     0,   -68,   -68,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -68,
     -68,   -68,   -68,   -68,   -67,   -67,   -67,     0,     0,   -67,
     -67,     0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,
     -67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,   -70,   -70,   -70,     0,
       0,   -70,   -70,     0,     0,     0,     0,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -70,   -70,   -70,   -70,   -70,    79,    80,
      81,     0,     0,    82,    83,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
     -36,   -36,   -36,     0,     0,   -36,   -36,     0,     0,     0,
       0,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,
       0,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,   -37,   -38,   -38,   -38,     0,     0,   -38,
     -38,     0,     0,     0,     0,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -38,   -38,   -38,   -38,   -38,   -39,   -39,   -39,     0,
       0,   -39,   -39,     0,     0,     0,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -63,   -63,
     -63,     0,     0,   -63,   -63,     0,     0,     0,     0,   -63,
     -63,   -63,   -63,   -63,   -63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -63,   -63,   -63,   -63,   -63,
     -64,   -64,   -64,     0,     0,   -64,   -64,     0,     0,     0,
       0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -64,   -64,   -64,
     -64,   -64,   -65,   -65,   -65,     0,     0,   -65,   -65,     0,
       0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -65,
     -65,   -65,   -65,   -65,   -66,   -66,   -66,     0,     0,   -66,
     -66,     0,     0,     0,     0,   -66,   -66,   -66,   -66,   -66,
     -66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -40,   -40,   -40,     0,
       0,   -40,   -40,     0,     0,     0,     0,   -40,   -40,   -40,
     -40,   -40,   -40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -40,   -40,   -40,   -40,   -40,   -58,   -58,
     -58,     0,     0,   -58,   -58,     0,     0,     0,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -58,   -58,   -58,   -58,   -58,
     -59,   -59,   -59,     0,     0,   -59,   -59,     0,     0,     0,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -59,   -59,   -59,
     -59,   -59,   -60,   -60,   -60,     0,     0,   -60,   -60,     0,
       0,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -60,
     -60,   -60,   -60,   -60,    79,    80,    81,     0,     0,    82,
      83,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,   -31,   -61,   -61,   -61,     0,
       0,   -61,   -61,     0,     0,     0,     0,   -61,   -61,   -61,
     -61,   -61,   -61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -61,   -61,   -61,   -61,   -61,   -62,   -62,
     -62,     0,     0,   -62,   -62,     0,     0,     0,     0,   -62,
     -62,   -62,   -62,   -62,   -62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -62,   -62,   -62,   -62,   -62,
      79,    80,    81,     0,     0,    82,    83,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,   -33,   -42,   -42,   -42,     0,     0,   -42,   -42,     0,
       0,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -42,
     -42,   -42,   -42,   -42,   -55,    80,    81,     0,     0,   -55,
     -55,     0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,
     -55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,   -55,   -56,   -56,    81,     0,
       0,   -56,   -56,     0,     0,     0,     0,   -56,   -56,   -56,
     -56,   -56,   -56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,   -56,   -57,   -57,
     -57,     0,     0,   -57,   -57,     0,     0,     0,     0,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,   -57,
      79,    80,    81,     0,     0,   -43,    83,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,   -43,    79,    80,    81,     0,     0,   -44,   -44,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,   -44,    79,    80,    81,     0,     0,   -45,
     -45,     0,     0,     0,     0,   -45,   -45,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,   -45,    79,    80,    81,     0,
       0,   -46,   -46,     0,     0,     0,     0,   -46,   -46,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,   -46,    79,    80,
      81,     0,     0,   -47,   -47,     0,     0,     0,     0,   -47,
     -47,   -47,   -47,   -47,   -47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,   -47,
      79,    80,    81,     0,     0,   -48,   -48,     0,     0,     0,
       0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,   -48,    79,    80,    81,     0,     0,   -49,   -49,     0,
       0,     0,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,   -49,    79,    80,    81,     0,     0,   -50,
     -50,     0,     0,     0,     0,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,   -50,   -51,   -51,   -51,     0,
       0,   -51,   -51,     0,     0,     0,     0,   -51,   -51,   -51,
     -51,   -51,   -51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -51,   -51,    92,    93,   -51,   -52,   -52,
     -52,     0,     0,   -52,   -52,     0,     0,     0,     0,   -52,
     -52,   -52,   -52,   -52,   -52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -52,   -52,    92,    93,   -52,
     -53,   -53,   -53,     0,     0,   -53,   -53,     0,     0,     0,
       0,   -53,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -53,   -53,   -53,
     -53,   -53,   -54,   -54,   -54,     0,     0,   -54,   -54,     0,
       0,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -54,
     -54,   -54,   -54,   -54,   -75,   -75,   -75,     0,     0,   -75,
     -75,     0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,
     -75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -75,   -75,   -75,   -75,   -75,    79,    80,    81,     0,
       0,    82,    83,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,   -35,   -74,   -74,
     -74,     0,     0,   -74,   -74,     0,     0,     0,     0,   -74,
     -74,   -74,   -74,   -74,   -74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,
     -72,   -72,   -72,     0,     0,   -72,   -72,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -72,   -72,   -72,
     -72,   -72,    79,    80,    81,     0,     0,    82,    83,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,   288
};

static const yytype_int16 yycheck[] =
{
       7,   143,    21,   122,     3,     4,   166,   233,     3,     4,
      16,    17,    18,    20,    20,    21,    22,     3,     4,     6,
     166,    27,    28,    29,    30,    31,    32,   290,     5,     6,
       0,   191,   295,     3,   126,    42,   126,    43,    44,    45,
      46,    47,    48,   135,   126,   191,   126,   139,     6,     0,
      49,     6,     3,    49,    49,    48,   126,    64,    65,    66,
     286,   127,     6,    70,     0,    16,    51,     3,     4,    48,
     136,    22,     6,     7,     8,     9,    10,    11,    52,    13,
      14,    15,     0,   225,     0,     3,     4,     3,     4,    48,
       5,     6,    48,     3,     4,    47,     6,     7,     8,     9,
      10,    11,     6,    13,    14,    15,     6,   126,    42,    43,
      44,    49,    50,    47,    48,   122,   235,     0,   125,     0,
       3,     4,     3,     4,    47,    48,   245,    20,    38,   136,
      40,    41,    42,    43,    44,    48,     0,    49,    48,     3,
       4,    51,    52,   150,   151,   152,    47,   154,   155,   156,
       0,    49,     0,     3,     4,     3,     4,    47,    48,    47,
      49,    50,    49,    50,    49,    50,    20,    49,   175,   176,
     177,    49,   179,   180,   181,   294,    49,    50,    49,    50,
     299,    47,    49,    48,    47,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      49,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    33,    34,    35,   285,
     312,    38,   312,    40,    41,    42,    48,   234,   235,   321,
     312,   321,   312,   325,    48,   325,    48,   244,   245,   321,
      48,   321,   312,   325,    48,   325,    47,   313,    48,    66,
      20,   321,    48,    70,    71,   325,   322,    52,    49,    49,
      47,    49,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,   284,    52,     3,
      49,    49,    49,    47,    49,    22,   293,   294,    46,    -1,
      -1,   298,   299,   312,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   321,    -1,   121,   122,   325,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,   322,    16,    17,    18,   136,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,   150,   151,   152,    -1,   154,   155,   156,
      -1,    -1,    -1,    43,    44,    45,    46,    -1,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   175,   176,
     177,    -1,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    42,    -1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,   235,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   293,   294,    -1,    -1,
      -1,   298,   299,    -1,    -1,    -1,   122,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,   312,   313,    -1,    -1,    -1,
     136,    -1,    -1,    -1,   321,   322,    -1,    -1,   325,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,    -1,   154,   155,
     156,    16,    17,    18,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,   175,
     176,   177,    -1,   179,   180,   181,    -1,    -1,    43,    44,
      45,    46,    -1,    48,    49,    50,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    42,    -1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,   235,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,   294,    -1,
      -1,    -1,   298,   299,    -1,    -1,    -1,   122,     3,     4,
     125,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   136,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,   154,
     155,   156,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
     175,   176,   177,    -1,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,    42,    -1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
     235,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,   294,
      -1,    -1,    -1,   298,   299,    -1,    -1,    -1,   122,     3,
       4,   125,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,   136,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,    -1,
     154,   155,   156,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      -1,   175,   176,   177,    -1,   179,   180,   181,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,    42,
      -1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,   235,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    66,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293,
     294,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,   122,
       3,     4,   125,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,   136,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
      -1,   154,   155,   156,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,   175,   176,   177,    -1,   179,   180,   181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      42,    -1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,   235,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    66,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     293,   294,    -1,    -1,    -1,   298,   299,    -1,    -1,    -1,
     122,     3,     4,   125,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,   136,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,    -1,   154,   155,   156,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,   175,   176,   177,    -1,   179,   180,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,    42,    -1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,   235,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    66,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   293,   294,    -1,    -1,    -1,   298,   299,    -1,    -1,
      -1,   122,     3,     4,   125,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,   136,    -1,    -1,    -1,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,    -1,   154,   155,   156,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,   175,   176,   177,    -1,   179,   180,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,    42,    -1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,   235,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,   245,    -1,    66,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   293,   294,    -1,    -1,    -1,   298,   299,    -1,
      -1,    -1,   122,     3,     4,   125,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,   136,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,    -1,   154,   155,   156,    -1,    38,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,   175,   176,   177,    -1,   179,
     180,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,    42,    -1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,   235,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    66,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   284,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   293,   294,    -1,    -1,    -1,   298,   299,
      -1,    -1,    -1,   122,     3,     4,   125,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,   136,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,    -1,   154,   155,   156,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,   175,   176,   177,    -1,
     179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    42,    -1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,   235,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    66,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,   294,    -1,    -1,    -1,   298,
     299,    -1,    -1,    -1,   122,     3,     4,   125,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,   136,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,    -1,   154,   155,   156,    -1,
      38,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    -1,   175,   176,   177,
      -1,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,   235,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   284,    42,    43,    44,
      -1,    -1,    -1,    48,    49,   293,   294,    -1,    -1,    -1,
     298,   299,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,   322,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    42,    43,    44,
      -1,    -1,    -1,    48,    49,    -1,    -1,    42,    43,    44,
      -1,    -1,    -1,    48,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      42,    43,    44,    16,    17,    18,    48,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    50,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      -1,    49,    50,    16,    17,    18,    -1,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    48,    49,    16,    17,    18,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    48,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,    -1,
      49,    16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    -1,    -1,    49,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    -1,    -1,    49,    16,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    16,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    -1,    49,    16,    17,    18,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    16,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    16,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    16,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    54,    55,    56,    57,    89,     5,     5,
       0,    55,     6,    88,    47,    48,    58,    59,    60,    61,
      89,    49,    50,    88,    51,    62,    61,    63,     7,     8,
       9,    10,    11,    13,    14,    15,    38,    40,    41,    42,
      43,    44,    48,    56,    62,    64,    65,    66,    67,    68,
      69,    70,    71,    73,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    88,    89,    48,    48,    73,    73,    73,
      48,    48,    73,    73,    73,    73,    52,    66,    47,    16,
      17,    18,    21,    22,    27,    28,    29,    30,    31,    32,
      43,    44,    45,    46,    47,    74,    84,    88,    88,    73,
      86,    87,    73,    72,    73,    49,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    20,    48,    85,    49,    50,    49,    47,    73,    86,
      49,    73,    67,    72,    49,    39,    47,    67,    72,    49,
      67,     6,     6,    51,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    42,    43,    44,    48,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    88,     6,     6,     6,
       7,     8,     9,    10,    11,    13,    14,    15,    42,    43,
      44,    48,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    88,    16,    17,    18,    21,    22,    27,    28,    29,
      30,    31,    32,    43,    44,    45,    46,    47,    16,    17,
      18,    21,    22,    27,    28,    29,    30,    31,    32,    43,
      44,    45,    46,    38,    40,    51,    62,    68,    69,    70,
      71,    73,    73,    63,    48,    48,    73,    73,    73,    73,
      73,    73,    74,    84,    48,    48,    73,    73,    73,    73,
      73,    73,    74,    84,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    48,    48,    63,    47,    47,    64,
      88,    86,    49,    20,    48,    88,    86,    49,    20,    48,
      73,    72,    64,    52,    85,    49,    73,    86,    85,    49,
      73,    86,    49,    47,    52,    49,    49,    49,    49,    67,
      72,    39,    47,    67,    72,    49,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    58,    57,    59,
      59,    60,    60,    61,    63,    62,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    68,    68,    69,    69,
      70,    71,    72,    72,    74,    73,    73,    73,    73,    73,
      73,    73,    73,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    77,    77,
      77,    77,    77,    78,    78,    78,    78,    79,    80,    81,
      82,    84,    83,    85,    83,    83,    86,    86,    87,    87,
      88,    89,    89,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     0,     7,     0,
       1,     3,     1,     2,     0,     4,     0,     1,     2,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     5,     7,
       9,     2,     0,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     0,     5,     4,     0,     1,     3,     1,
       1,     1,     1,     2,     2
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
    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2757 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2765 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2773 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2781 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2789 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2797 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2805 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2813 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2821 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2829 "bison.tab.c"
        break;

    case YYSYMBOL_58_1: /* @1  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2837 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2845 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2853 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2861 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2869 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2877 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2885 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2893 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2901 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2909 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2917 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2925 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2933 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2941 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2949 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2957 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2965 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2973 "bison.tab.c"
        break;

    case YYSYMBOL_constantString: /* constantString  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2981 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2989 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2997 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 118 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 3005 "bison.tab.c"
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
  case 2: /* startProgram: startProgram declaration  */
#line 125 "./src/bison.y"
                             {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 3303 "bison.tab.c"
    break;

  case 3: /* startProgram: declaration  */
#line 128 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 3311 "bison.tab.c"
    break;

  case 4: /* declaration: variableDeclare  */
#line 134 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3319 "bison.tab.c"
    break;

  case 5: /* declaration: functionDeclare  */
#line 137 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3327 "bison.tab.c"
    break;

  case 6: /* variableDeclare: type id ';'  */
#line 143 "./src/bison.y"
                {
        // printf("current_context_var: %p || name: %s\n", (void *) current_context, $2->context->name);
        Symbol *sym_declared = lookup_symbol_context((yyvsp[-1].astnode)->context->name, current_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("variable redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
            semantic_error = 1;
            (yyval.astnode) = NULL;
            delete_astnode((yyvsp[-2].astnode));
            delete_astnode((yyvsp[-1].astnode));
        } else {
            list_symbol_insert((yyvsp[-2].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[-1].astnode)->context->name, 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, VARIABLE);
            (yyval.astnode) = create_astnode_context(AST_VAR_DECLARE, "variable declare");
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
        }
    }
#line 3348 "bison.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 162 "./src/bison.y"
                         {
        (yyval.astnode) = (yyvsp[-1].astnode);
        // printf("current_context_func: %p || name: %s\n", (void *) current_context, $2->context->name);
        last_context = current_context;

        Symbol *sym_declared = lookup_symbol_context((yyvsp[-1].astnode)->context->name, last_context);

        if(sym_declared != NULL){
            SEMANTIC_ERROR("function redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, (yylsp[-1]).first_line, (yylsp[-1]).first_column);
            semantic_error = 1;
        } else {
            list_symbol_insert((yyvsp[-2].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[-1].astnode)->context->name, 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, FUNCTION);
            isFunctionContext = 1;
            insert_list_element(list_context, create_node(create_symbol_table()));
            Element *iterator;

            for(iterator = list_context->first; iterator != NULL; iterator = iterator->next){
                current_context = iterator->value;
            }
            insert_children(current_context, last_context);
            list_symbol_insert((yyvsp[-2].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[-1].astnode)->context->name, 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, FUNCTION);
        }
    }
#line 3376 "bison.tab.c"
    break;

  case 8: /* functionDeclare: type id '(' @1 optListParams ')' compoundStatement  */
#line 184 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_FUNC_DECLARE, "func declare");
        
        if((yyvsp[-6].astnode))
            insert_kid((yyvsp[-6].astnode), (yyval.astnode));
        if((yyvsp[-3].astnode)){
            insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        }
        if((yyvsp[-2].list)){ /* Se existir parametros insira */
            // Cria um noh que recebe os parametros
            AstNode *params = create_astnode_context(AST_LIST_PARAM, "params");

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
#line 3403 "bison.tab.c"
    break;

  case 9: /* optListParams: %empty  */
#line 209 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3411 "bison.tab.c"
    break;

  case 11: /* listParams: listParams ',' param  */
#line 216 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 3420 "bison.tab.c"
    break;

  case 12: /* listParams: param  */
#line 220 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3429 "bison.tab.c"
    break;

  case 13: /* param: type id  */
#line 227 "./src/bison.y"
            {
        Symbol *sym_declared = lookup_symbol_context((yyvsp[0].astnode)->context->name, current_context);
        if(sym_declared != NULL){
            SEMANTIC_ERROR("param redeclaration of '%s' || line: %d, column: %d\n", sym_declared->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
            (yyval.astnode) = NULL;
            delete_astnode((yyvsp[-1].astnode));
            delete_astnode((yyvsp[0].astnode));
        } else {
            list_symbol_insert((yyvsp[-1].astnode)->context->type, ((SymbolTable *)current_context->value)->symbols, (yyvsp[0].astnode)->context->name, 0, (yylsp[0]).first_line, (yylsp[0]).first_column, VARIABLE);
            (yyval.astnode) = create_astnode_context(AST_PARAM, "param");
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
        }
    }
#line 3449 "bison.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 245 "./src/bison.y"
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
#line 3469 "bison.tab.c"
    break;

  case 15: /* compoundStatement: '{' $@2 optListCodeBlock '}'  */
#line 259 "./src/bison.y"
                           {
        (yyval.astnode) = create_astnode_context(AST_STATE_COMPOUND, "compound statement");
        if((yyvsp[-1].list)){ /* Se existir code block insira */
            // Cria um noh que recebe os code blocks
            AstNode *codeblocks = create_astnode_context(AST_CODE_BLOCK, "code block");

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
#line 3492 "bison.tab.c"
    break;

  case 16: /* optListCodeBlock: %empty  */
#line 280 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3500 "bison.tab.c"
    break;

  case 18: /* listCodeBlock: listCodeBlock codeBlock  */
#line 287 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 3509 "bison.tab.c"
    break;

  case 19: /* listCodeBlock: codeBlock  */
#line 291 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3518 "bison.tab.c"
    break;

  case 20: /* codeBlock: statement  */
#line 298 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3527 "bison.tab.c"
    break;

  case 21: /* codeBlock: variableDeclare  */
#line 302 "./src/bison.y"
                      {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3536 "bison.tab.c"
    break;

  case 22: /* statement: flowExpression  */
#line 309 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3545 "bison.tab.c"
    break;

  case 23: /* statement: compoundStatement  */
#line 313 "./src/bison.y"
                        {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3554 "bison.tab.c"
    break;

  case 24: /* statement: expression ';'  */
#line 317 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3563 "bison.tab.c"
    break;

  case 25: /* flowExpression: condExpression  */
#line 324 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3571 "bison.tab.c"
    break;

  case 26: /* flowExpression: interationExpression  */
#line 327 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3579 "bison.tab.c"
    break;

  case 27: /* flowExpression: returnExpression ';'  */
#line 330 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 3587 "bison.tab.c"
    break;

  case 28: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 336 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3597 "bison.tab.c"
    break;

  case 29: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 341 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3608 "bison.tab.c"
    break;

  case 30: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 350 "./src/bison.y"
                                                                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ITERATION, "interation expression");
        if((yyvsp[-6].astnode))
            insert_kid((yyvsp[-6].astnode), (yyval.astnode));
        if((yyvsp[-4].astnode))
            insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        if((yyvsp[-2].astnode))
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3623 "bison.tab.c"
    break;

  case 31: /* returnExpression: RETURN_TOKEN expression  */
#line 363 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return expression");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3632 "bison.tab.c"
    break;

  case 32: /* optExpression: %empty  */
#line 370 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 3640 "bison.tab.c"
    break;

  case 33: /* optExpression: expression  */
#line 373 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3648 "bison.tab.c"
    break;

  case 34: /* $@3: %empty  */
#line 379 "./src/bison.y"
       {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        }
    }
#line 3660 "bison.tab.c"
    break;

  case 35: /* expression: id $@3 ASSIGN_TOKEN expression  */
#line 385 "./src/bison.y"
                              {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3670 "bison.tab.c"
    break;

  case 36: /* expression: binArith  */
#line 390 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3679 "bison.tab.c"
    break;

  case 37: /* expression: listArith  */
#line 394 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3688 "bison.tab.c"
    break;

  case 38: /* expression: unaArith  */
#line 398 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3697 "bison.tab.c"
    break;

  case 39: /* expression: constant  */
#line 402 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3706 "bison.tab.c"
    break;

  case 40: /* expression: funcCall  */
#line 406 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3715 "bison.tab.c"
    break;

  case 41: /* expression: id  */
#line 410 "./src/bison.y"
         {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        } else {
            (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
        }
    }
#line 3730 "bison.tab.c"
    break;

  case 42: /* expression: '(' expression ')'  */
#line 420 "./src/bison.y"
                         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3739 "bison.tab.c"
    break;

  case 43: /* binArith: expression OR_TOKEN expression  */
#line 427 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3749 "bison.tab.c"
    break;

  case 44: /* binArith: expression AND_TOKEN expression  */
#line 432 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3759 "bison.tab.c"
    break;

  case 45: /* binArith: expression EQUAL_TOKEN expression  */
#line 437 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3769 "bison.tab.c"
    break;

  case 46: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 442 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3779 "bison.tab.c"
    break;

  case 47: /* binArith: expression LESS_TOKEN expression  */
#line 447 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3789 "bison.tab.c"
    break;

  case 48: /* binArith: expression LE_EQ_TOKEN expression  */
#line 452 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3799 "bison.tab.c"
    break;

  case 49: /* binArith: expression GREAT_TOKEN expression  */
#line 457 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3809 "bison.tab.c"
    break;

  case 50: /* binArith: expression GR_EQ_TOKEN expression  */
#line 462 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3819 "bison.tab.c"
    break;

  case 51: /* binArith: expression '+' expression  */
#line 467 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3829 "bison.tab.c"
    break;

  case 52: /* binArith: expression '-' expression  */
#line 472 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3839 "bison.tab.c"
    break;

  case 53: /* binArith: expression '*' expression  */
#line 477 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3849 "bison.tab.c"
    break;

  case 54: /* binArith: expression '/' expression  */
#line 482 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3859 "bison.tab.c"
    break;

  case 55: /* listArith: expression MAP_TOKEN expression  */
#line 490 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3869 "bison.tab.c"
    break;

  case 56: /* listArith: expression FILTER_TOKEN expression  */
#line 495 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3879 "bison.tab.c"
    break;

  case 57: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 500 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3889 "bison.tab.c"
    break;

  case 58: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 508 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3898 "bison.tab.c"
    break;

  case 59: /* unaArith: QUESTION_TOKEN expression  */
#line 512 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3907 "bison.tab.c"
    break;

  case 60: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 516 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3916 "bison.tab.c"
    break;

  case 61: /* unaArith: '+' expression  */
#line 520 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3925 "bison.tab.c"
    break;

  case 62: /* unaArith: '-' expression  */
#line 524 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3934 "bison.tab.c"
    break;

  case 63: /* constant: constantInteger  */
#line 531 "./src/bison.y"
                    {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant int");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3943 "bison.tab.c"
    break;

  case 64: /* constant: constantReal  */
#line 535 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant real");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3952 "bison.tab.c"
    break;

  case 65: /* constant: constantNIL  */
#line 539 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant nil");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3961 "bison.tab.c"
    break;

  case 66: /* constant: constantString  */
#line 543 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant string");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3970 "bison.tab.c"
    break;

  case 67: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 550 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3978 "bison.tab.c"
    break;

  case 68: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 556 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3986 "bison.tab.c"
    break;

  case 69: /* constantNIL: NIL_TOKEN  */
#line 562 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3994 "bison.tab.c"
    break;

  case 70: /* constantString: STRING_TOKEN  */
#line 568 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4002 "bison.tab.c"
    break;

  case 71: /* $@4: %empty  */
#line 574 "./src/bison.y"
       {
       Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        } 
    }
#line 4014 "bison.tab.c"
    break;

  case 72: /* funcCall: id $@4 '(' optListExpression ')'  */
#line 580 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        if((yyvsp[-1].list)){
            AstNode *arguments = create_astnode_context(AST_CODE_BLOCK, "arguments");

            while((yyvsp[-1].list)->size) {
                AstNode *aux = remove_first_element_list((yyvsp[-1].list));
                insert_kid(aux, arguments);
            }
            delete_list((yyvsp[-1].list), delete_list_astnode);
            insert_kid(arguments, (yyval.astnode));
        }
    }
#line 4033 "bison.tab.c"
    break;

  case 73: /* $@5: %empty  */
#line 594 "./src/bison.y"
                        {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        }
    }
#line 4045 "bison.tab.c"
    break;

  case 74: /* funcCall: READ_TOKEN '(' id $@5 ')'  */
#line 600 "./src/bison.y"
          {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
    }
#line 4055 "bison.tab.c"
    break;

  case 75: /* funcCall: WRITE_TOKEN '(' optListExpression ')'  */
#line 605 "./src/bison.y"
                                            {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        if((yyvsp[-1].list)){
            AstNode *arguments = create_astnode_context(AST_CODE_BLOCK, "arguments");

            while((yyvsp[-1].list)->size) {
                AstNode *aux = remove_first_element_list((yyvsp[-1].list));
                insert_kid(aux, arguments);
            }
            delete_list((yyvsp[-1].list), delete_list_astnode);
            insert_kid(arguments, (yyval.astnode));
        }
    }
#line 4074 "bison.tab.c"
    break;

  case 76: /* optListExpression: %empty  */
#line 622 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 4082 "bison.tab.c"
    break;

  case 78: /* listExpression: listExpression ',' expression  */
#line 629 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 4091 "bison.tab.c"
    break;

  case 79: /* listExpression: expression  */
#line 633 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 4100 "bison.tab.c"
    break;

  case 80: /* id: ID_TOKEN  */
#line 640 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4108 "bison.tab.c"
    break;

  case 81: /* type: INT_TOKEN  */
#line 646 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT, (yyvsp[0].string));
    }
#line 4116 "bison.tab.c"
    break;

  case 82: /* type: FLOAT_TOKEN  */
#line 649 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT, (yyvsp[0].string));
    }
#line 4124 "bison.tab.c"
    break;

  case 83: /* type: INT_TOKEN LIST_TOKEN  */
#line 652 "./src/bison.y"
                           {
        char *str = (char *) calloc((strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 10), sizeof(char));
        strcat(str, (yyvsp[-1].string));
        strcat(str, " ");
        strcat(str, (yyvsp[0].string));
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT_LIST, str);
        free(str);
    }
#line 4137 "bison.tab.c"
    break;

  case 84: /* type: FLOAT_TOKEN LIST_TOKEN  */
#line 660 "./src/bison.y"
                             {
        char *str = (char *) calloc((strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 10), sizeof(char));
        strcat(str, (yyvsp[-1].string));
        strcat(str, " ");
        strcat(str, (yyvsp[0].string));
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT_LIST, str);
        free(str);
    }
#line 4150 "bison.tab.c"
    break;


#line 4154 "bison.tab.c"

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

#line 670 "./src/bison.y"


void yyerror(const char *error_msg){
    error++;
    printf(RED"Line: %d || Column: %d || "RESET, num_line, num_col);
    printf(RED"Error: %s || Error count: %d \n"RESET, error_msg, error);
}

/* 
*   O primeiro node ja deleta os nodes subsequentes 
*   e portanto nao precisamos deletar na lista. 
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
    root = create_astnode_context(AST_ROOT, "root");
    node_aux = create_list();

    list_context = create_list();
    insert_list_element(list_context, create_node(create_symbol_table()));
    global_context = list_context->first->value;
    current_context = global_context;

    yyparse();

    Symbol *sym_main = lookup_symbol("main", current_context);

    if(sym_main){
        if(!sym_main->isfunction) 
            printf(RED"Semantic error: Undefined reference to function main\n"RESET);
    } else 
        printf(RED"Semantic error: Undefined reference to function main\n"RESET);

    if(!semantic_error){
        if(root->kids->size > 0) {
            printf("##################### %s #####################\n", "Abstract Syntax Tree");
            print_tree(root, 0);
            printf("\n");
        } else 
            printf(RED"Unable to print AST\n"RESET);
    }

    Element *iterator;
    if(!semantic_error){
        // TODO: Arrumar if
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
            printf(RED"Unable to print Symbol Table\n"RESET);
    }

    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_list(list_context, delete_list_treenode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
