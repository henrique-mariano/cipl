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

    extern int error, num_line, num_col;

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

#line 114 "bison.tab.c"

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
  YYSYMBOL_88_5 = 88,                      /* $@5  */
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
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   18727

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  719

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
       0,   141,   141,   145,   149,   155,   158,   164,   167,   172,
     180,   198,   204,   211,   218,   227,   227,   274,   277,   281,
     285,   291,   298,   315,   321,   329,   329,   364,   367,   371,
     375,   382,   386,   390,   394,   398,   402,   408,   413,   418,
     424,   429,   436,   444,   449,   454,   459,   467,   470,   473,
     479,   484,   492,   498,   505,   512,   518,   527,   533,   541,
     553,   561,   569,   577,   584,   591,   596,   603,   609,   616,
     619,   625,   629,   633,   637,   641,   645,   649,   653,   663,
     669,   677,   677,   691,   696,   701,   706,   711,   716,   721,
     726,   731,   736,   741,   746,   752,   757,   762,   767,   772,
     777,   782,   787,   792,   797,   802,   807,   815,   820,   825,
     831,   836,   841,   849,   854,   859,   864,   869,   875,   879,
     883,   887,   891,   898,   903,   908,   916,   923,   930,   937,
     937,   960,   960,   971,   976,   984,   987,   991,   995,  1002,
    1008,  1013,  1018,  1029
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
  "$@4", "ioCommand", "$@5", "optListExpression", "listExpression", "id",
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

#define YYPACT_NINF (-534)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-144)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    6515,     5,   174,   176,  2918,    13,    56, 16696, 16727, 16758,
    1460,  8054,  8065,    74,    76,  8109,  8120,  8131,  8175,   124,
      35,  6561,  6577,  6623,  6639,  6685,  6701,  6747,  6763,  6809,
       9, 16789, 16820, 16851, 16882, 16913, 16944, 16975, 17006, 17037,
   17068, 17099,  3810,    -2,  6825,    16,   103,    71,    18,    79,
     917, 17130,     7,    75,   379, 17161,  4256, 17192, 17223, 17254,
   17285,  6871,  8186,  6887,  1415,    82, 17316, 17347, 17378, 17409,
   17440,    92, 14221,  1141,  -534,   147,  6933,  6949,  8197,  8241,
    8252,  8263,  8307,  8318,  8329,  8373,  8384,  8395,  8439,  8450,
    8461,  8505,  8516,  6995, 17471,   137,   118,    96,  7011,    -7,
    7057,   155,   195,  7073,   210,   235, 14254,   296,  1555,   264,
   14287,   -11,   278, 17502,  7119, 17533,   -13,   729,  1332,   276,
    1487,  1508,  1683,  1777,   190, 17564, 17595, 17626, 17657, 17688,
   17719, 17750, 17781, 17812, 17843, 17874, 17905, 17936, 17967, 17998,
   18029, 18060, 18091, 18122, 18153, 18184, 18215, 18246, 18277, 18308,
   18339, 18370, 18401, 18432, 18463,  2367,  1198,   329,  7135,   331,
    7181,    27,  1795,   285,  1921,  5594,  9941,   288, 14320,    59,
     713,   247,  7197,  1599,   729,  1938,  7243,  2129,   127, 18494,
   10100,   289,    -6,  7259,  7305,    45,  7321, 18525,  7367,  7383,
    7429, 18556, 18587,  7816,  2223,  7816,  2241,    68,   102,   292,
    2357, 18618,  3044,   150,   297,   261,   266,   268,    95,  7445,
    7816,  7491,  7816,  1865,  7816,  1865,  7816,   464, 10134,   298,
     202,   270,  7507,  7553,   301,  7569,   309,  7615,   310,   326,
    7631,   272,  7816,  7816,  7816,  7816,  7677,  7693,  7739,  7755,
    4702,  5147,   299,   328, 14353, 14386, 14419,  8527,  8571,  8582,
    8593,  8637,   379, 14452, 14485, 14518, 14551, 14584, 14617, 14650,
   14683, 14716, 14749,  7931,   199,    73,   333,  8648,  8659,  8703,
    8714,  8725,  8769,  8780,  8791,  8835,  8846,  8857,  8901,  8912,
    8923,  8967,   104,   105,   110,   111,  8978,   124,  2415,  2430,
    2575,  2669,   330, 18649,  3810,  2687,   337,  2803,   813,   335,
     343, 10168, 10202, 10236,  8989,  9033,  9044,  9055,  9099,   379,
   10270, 10304, 10338, 10372, 10406, 10440, 10474, 10508, 10542, 10576,
    7897,   348,   112,   113,   135,   141,  9110,   124,  2861,  2877,
    3024,  3115,   350, 18680,  2471,   351,   353, 12208, 12241, 12274,
    9121,  9165,  9176,  9187,  9231,   379, 12307, 12340, 12373, 12406,
   12439, 12472, 12505, 12538, 12571, 12604, 12637,  3363,   377,  3133,
    9242,  9253,  9297,  9308,  9319,  9363,  9374,  9385,  9429,  9440,
    9451,  9495,  9506,  9517,  9561,   179,   233,   274, 14782,   296,
    2001, 14815, 14848, 14881, 14914, 14947, 14980, 15013, 15046, 15079,
   15112, 15145, 15178,   384,   366, 15211, 15244, 15277, 15310, 15343,
   15376, 15409, 15442, 15475, 15508, 15541, 15574, 15607, 15640, 15673,
   15706, 15739, 15772, 15805, 15838, 15871, 15904, 15937, 15970, 16003,
   16036, 16069, 16102, 16135, 16168,   378,    19,   382,  1089,  3249,
    9572,  3307,  7977,   375,  1141,  3322,  3467,   245,   296,  2311,
   10610, 10644, 10678, 10712, 10746, 10780, 10814, 10848, 10882, 10916,
   16201, 10950,   406,   385,  3561,   387,    36,   388,  1579,  3579,
    9583,  3695,  7988,   389,  1141,  3753,  3769,   296,  2757, 12670,
   12703, 12736, 12769, 12802, 12835, 12868, 12901, 12934, 12967, 16234,
    9627,  9638,  9649,  9693,  9704,  9715,  9759,  9770,  9781,  9825,
    9836,  9847,  9891,  9902,  9913, 13000,   416,   396,  3913, 10984,
   11018, 11052, 11086, 11120, 11154, 11188, 11222, 11256, 11290, 11324,
   11358, 11392, 11426, 11460, 11494, 11528, 11562, 11596, 11630, 11664,
   11698, 11732, 11766, 11800, 11834, 11868, 11902, 11936, 11970,   148,
     181,   195,   398, 16267, 16300,   379,  1198,  4007,   399,  4025,
     407,   408, 16333,   410, 16366,   162,   404,  4141,   403,   460,
    4199,   195,   414, 16399, 12004,  3044,  1198,  4215,   415,  4362,
     417,   418, 16432,   420, 16465,   217,   429,  4453,   443,   195,
     449, 16498, 13033, 13066, 13099, 13132, 13165, 13198, 13231, 13264,
   13297, 13330, 13363, 13396, 13429, 13462, 13495, 13528, 13561, 13594,
   13627, 13660, 13693, 13726, 13759, 13792, 13825, 13858, 13891, 13924,
   13957, 13990, 14023,  3203,  1198,   450, 16531, 16564, 16597,   451,
     402,   869,  9973, 10005,  1041,  1987,   247,  4471,  7999,  4587,
    4645,   452, 12038, 12072, 12106,   453,   935,  1353, 10037, 10069,
    6044,  7801,   247,  4661,  8043,  4808,   454, 14056, 14089, 14122,
     455, 16630, 16663,  4899,  4917,  5033,  5091,   729,  5106,   729,
    5251,   238,   250,   462, 12140, 12174,  5345,  5363,  5479,  5537,
    7862,  5553,  7862,  5700,   251,   254,   463, 14155, 14188,  5791,
     729,  5809,   729,  1865,   729,  1865,   729,   571,  5879,  7862,
    5925,  7862,  1865,  7862,  1865,  7862,  1260,  5974,  5990,   465,
    6065,   466,  6117,   467,   468,  6133,  6179,   469,  6195,   470,
    6241,   472,   474,   729,   729,   729,   729,  7862,  7862,  7862,
    7862,  6256,  6308,  6323,  6375,  6391,  6437,  6453,  6499
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
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -534,  -534,  -534,   490,    32,  -534,  -534,  -534,  -534,   304,
       8,  -280,  -425,  -534,   405,   119,   186,   327,  -534,   336,
     431,   -25,     0,  1402,  -262,  1848,  2294,  2740,  3186,  3632,
    4078,  4524,  4970,  -261,  5416,  -306,  -533,  -534,   951,     6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    20,    21,    22,   118,    24,   185,   204,   205,   206,
     288,    73,   119,   120,   121,   122,   289,   290,   123,   291,
     292,   112,   293,    32,    95,    33,    34,    35,    36,    37,
      38,    39,    40,    96,    41,   163,   181,   182,    56,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   393,   394,   609,   265,    -3,    43,   434,    25,   548,
      55,    58,    60,   159,    47,    66,    68,    70,    72,   101,
     538,    31,  -142,   625,   266,   266,   174,    43,   -15,    25,
     -15,   -15,    23,   -15,   295,    74,   171,   558,   172,   568,
     160,   161,   266,  -136,   202,    98,   203,   464,   375,   376,
     106,   377,    44,    23,    72,   107,    77,    49,   452,   453,
     321,    48,   110,  -142,   113,   240,   322,   323,     7,     8,
       9,   640,    10,    11,    12,    61,   -15,    63,   126,   128,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   152,   154,  -139,   -17,   496,   497,   324,   193,   325,
      15,   377,    16,    17,    50,   425,   427,   326,   168,  -143,
     327,   429,   431,   455,   457,   213,   157,   214,   100,    26,
    -139,  -139,    62,   108,    64,   -25,   103,   -25,   -25,   -68,
     -25,   -25,   -25,   -25,   -25,   -25,   459,   -25,   -25,   -25,
      26,   114,   461,   158,   -23,   -23,   197,   358,   199,   215,
    -143,   216,   426,   428,  -142,   179,   180,   155,   430,   432,
     456,   458,   -25,   -25,   -25,   -25,   156,   -25,   -25,   333,
     333,   346,   -25,   113,   359,   -25,   -25,   328,   328,    45,
    -140,    46,  -141,   460,   529,  -140,    27,  -143,   224,   462,
     226,   208,   229,    31,    44,    31,   264,  -142,  -142,   -21,
     -21,    25,   218,    25,   162,   375,   376,    27,   377,   616,
      31,   617,    31,   378,    31,   378,    31,   378,    25,  -139,
      25,  -140,    25,  -141,    25,   605,   208,   230,  -140,  -140,
    -143,  -143,    31,    31,    31,    31,   175,   297,   530,  -141,
      25,    25,    25,    25,  -131,   621,  -139,   382,   384,   386,
     388,   390,   391,   334,   335,   336,   337,   338,   339,   164,
     340,   341,   342,   636,   632,   549,   633,   396,   398,   400,
     402,   404,   406,   408,   410,   412,   414,   416,   418,   420,
     422,   424,  -141,  -141,   165,   673,    72,   674,   194,   196,
     343,   344,   550,   200,   -69,   345,   -69,   675,   682,   676,
     683,   684,   266,   685,   441,   443,   445,   447,   449,   450,
     -18,   220,   209,   169,   211,   -20,   -20,   -24,   -24,   -22,
     -22,   -19,   -19,  -139,  -139,   173,    72,    28,   176,   222,
     183,   223,   184,   225,   187,   227,    29,   191,   201,   217,
     470,   472,   474,   476,   478,   479,   219,   379,    28,    19,
     232,   236,   237,   238,   239,   329,   329,    29,   233,   234,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   526,   528,   235,   380,   435,   498,    27,
     533,    27,  -139,   438,   295,   241,   242,   243,   244,   245,
     246,   439,   247,   248,   249,   454,    27,   465,    27,   467,
      27,   468,    27,   -43,   535,   -43,   -43,   546,   -43,   -43,
     -43,   -43,   -43,   -43,   536,   -43,   -43,   -43,    27,    27,
      27,    27,   250,   251,   547,   537,   555,   252,   542,   539,
     544,    30,   113,   556,   557,   559,   603,   566,   567,   553,
     -43,   -43,   -43,   -43,   604,   -43,   -43,   606,   610,   643,
     -43,   618,    30,   -43,   -43,   619,   611,   612,   562,   614,
     564,   620,   113,   622,   626,   228,   627,   628,   571,   630,
     241,   242,   243,   244,   245,   246,   634,   247,   248,   249,
     574,   576,   578,   580,   582,   584,   586,   588,   590,   592,
     594,   596,   598,   600,   602,   635,   330,   330,   637,   641,
     642,   654,   655,   667,   668,   331,   331,   250,   251,   677,
     686,    76,   252,   -69,   703,   704,   705,   706,   707,   708,
      28,   709,    28,   710,   231,   177,     0,     0,     0,    29,
       0,    29,     0,     0,     0,   608,   180,    28,     0,    28,
       0,    28,     0,    28,     0,     0,    29,     0,    29,     0,
      29,     0,    29,     0,     0,   624,   180,     0,     0,    28,
      28,    28,    28,     0,     0,     0,     0,     0,    29,    29,
      29,    29,   693,     0,     0,     0,     0,   241,   242,   243,
     244,   245,   246,     0,   247,   248,   249,     0,     0,     0,
       0,   651,     0,   653,     0,     0,     0,     0,     0,     0,
     332,   332,     0,   639,   180,     0,     0,   664,     0,   666,
       0,     0,     0,     0,   250,   251,   346,     0,   113,   252,
     -69,     0,     0,     0,    30,     0,    30,     0,     0,     0,
     333,   333,   346,     0,   113,     0,     0,     0,   328,   328,
       0,    30,     0,    30,     0,    30,     0,    30,   689,     0,
     691,     0,   694,     0,     0,     0,     0,   697,     0,   699,
     333,   702,   333,    30,    30,    30,    30,     0,   328,     0,
     328,     0,     0,   378,     0,   378,     0,   378,     0,   333,
       0,   333,   378,   333,   378,   333,   378,   328,     0,   328,
       0,   328,     0,   328,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,   333,   333,
     333,     0,     0,     0,   321,   328,   328,   328,   328,   240,
     322,   323,     7,     8,     9,     0,    10,    11,    12,     0,
     296,     0,     0,   648,   650,   240,   282,   283,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,     0,   661,
     663,   324,   195,   325,    15,     0,    16,    17,     0,     0,
       0,   326,     0,     0,   327,     0,   669,   284,   671,   285,
      15,     0,    16,    17,     0,     0,     0,   286,     0,   678,
     287,   680,     0,     0,     0,     0,     0,     0,     0,   687,
       0,   688,     0,   690,     0,   692,     0,     0,   695,     0,
     696,     0,   698,     0,   700,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -139,     0,   329,   329,     0,     0,
       0,     0,   711,   712,   713,   714,   715,   716,   717,   718,
    -139,  -139,  -139,  -139,  -139,  -139,     0,     0,     0,     0,
    -139,  -139,  -139,  -139,  -139,  -139,   329,     0,   329,     0,
       0,     0,     0,     0,     0,     0,  -139,  -139,  -139,  -139,
       0,  -139,  -139,  -139,     0,   329,     0,   329,     0,   329,
     -39,   329,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,
     -39,     0,   -39,   -39,   -39,     0,     0,     0,     0,     0,
       0,     0,     0,   329,   329,   329,   329,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -39,   -39,   -39,
     -39,     0,   -39,   -39,     0,     0,   644,   -39,   104,     0,
     -39,   -39,     0,   241,   242,   243,   244,   245,   246,     0,
     247,   248,   249,     0,     0,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,
     -43,    42,     0,     0,     0,     0,     0,   330,   330,   105,
     250,   251,     0,     0,     0,   252,   331,   331,     0,   263,
       0,     0,    42,   -43,   -43,   -43,   -43,     0,   -43,   -43,
       0,     0,   656,   -43,     0,     0,   -43,   330,     0,   330,
       0,     0,     0,    97,    99,     0,   331,     0,   331,   102,
       0,   263,     0,     0,     0,   263,   330,     0,   330,     0,
     330,     0,   330,   263,     0,   331,     0,   331,     0,   331,
       0,   331,     0,     0,   294,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,   330,   330,   330,     0,     0,
       0,     0,   296,   331,   331,   331,   331,   240,   282,   283,
       7,     8,     9,     0,    10,    11,    12,     0,   102,   263,
       0,   332,   332,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,     0,   178,     0,     0,     0,   284,
     647,   285,    15,     0,    16,    17,     0,     0,     0,   286,
     540,   332,   287,   332,     0,   241,   242,   243,   244,   245,
     246,     0,   247,   248,   249,     0,     0,   320,     0,     0,
     332,     0,   332,     0,   332,     0,   332,     0,     0,     0,
       0,     0,   357,     0,     0,     0,     0,     0,     0,     0,
       0,   541,   250,   251,     0,     0,   207,   252,   332,   332,
     332,   332,   116,     0,     2,     3,     0,     4,   282,   283,
       7,     8,     9,   320,    10,    11,    12,     0,     0,   221,
       0,     0,     0,     0,   263,     0,   263,     0,   263,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,   284,
     117,   285,    15,     0,    16,    17,     0,     0,     0,   286,
       0,     0,   287,   -27,     0,     0,     0,     0,   263,   263,
     263,   263,   263,   263,   298,   299,   300,   301,   302,   303,
       0,   304,   305,   306,     0,     0,     0,     0,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,     0,     0,     0,     0,   263,     0,     0,
       0,   307,   308,     0,     0,   437,   309,  -135,     0,     0,
       0,     0,     0,     0,     0,   320,   320,   320,   320,   320,
     263,   701,     0,     0,     0,     0,   241,   242,   243,   244,
     245,   246,     0,   247,   248,   249,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,   357,   357,   357,   357,   263,     0,     0,     0,
       0,     0,     0,   250,   251,     0,     0,     0,   252,   -69,
       0,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,     0,     0,     0,     0,
     531,   263,     0,   -32,     0,   -32,   -32,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,     0,     0,
       0,     0,     0,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,     0,
     -32,   -32,   -32,   -32,     0,   -32,   -32,   102,     0,   263,
     -32,   263,     0,   -32,   -32,   294,     0,     0,     0,   551,
     263,   -39,   -39,   -39,   -39,     0,   -39,   -39,     0,     0,
     657,   -39,     0,     0,   -39,     0,     0,   102,     0,   263,
       0,   263,     0,     0,     0,   294,   111,     0,   569,   263,
     253,   240,    52,    53,     7,     8,     9,     0,    10,    11,
      12,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,     0,     0,     0,     0,
       0,     0,   253,     0,     0,     0,   253,     0,    16,    17,
       0,    51,   -69,    54,   253,     0,   240,    52,    53,     7,
       8,     9,     0,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,   320,   116,     0,
       2,     3,     0,     4,   282,   283,     7,     8,     9,     0,
      10,    11,    12,    16,    17,     0,   320,   320,    54,   -30,
     253,   -30,   -30,     0,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,   -30,   -30,     0,   284,   117,   285,    15,     0,
      16,    17,     0,     0,     0,   286,     0,     0,   287,   -28,
       0,     0,     0,     0,     0,     0,   -30,   -30,   -30,   -30,
       0,   -30,   -30,     0,   357,   320,   -30,     0,   310,   -30,
     -30,   241,   242,   243,   244,   245,   246,   357,   247,   248,
     249,     0,     0,   347,     0,     0,     0,     0,     0,     0,
     560,     0,     0,   357,     0,   241,   242,   243,   244,   245,
     246,     0,   247,   248,   249,     0,     0,   167,   250,   251,
     198,     0,     0,   252,   310,   240,    52,    53,     7,     8,
       9,     0,    10,    11,    12,   253,     0,   253,     0,   253,
       0,   561,   250,   251,   263,     0,   263,   252,   263,     0,
       0,     0,     0,   263,     0,   263,     0,   263,     0,     0,
       0,     0,    16,    17,     0,     0,   -69,    54,     0,   253,
     253,   253,   253,   253,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   -31,     0,   -31,   -31,   253,   -31,
     -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,     0,
       0,     0,     0,     0,     0,     0,   310,   310,   310,   310,
     310,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -31,   -31,   -31,   -31,     0,   -31,   -31,   253,     0,
       0,   -31,     0,     0,   -31,   -31,     0,     0,     0,     0,
       0,     0,   347,   347,   347,   347,   347,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,     0,   -33,     0,
     -33,   -33,   253,   -33,   -33,   -33,   -33,   -33,   -33,     0,
     -33,   -33,   -33,     0,     0,   -43,   -43,     0,   -43,   -43,
       0,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,
     -43,     0,     0,     0,     0,   -33,   -33,   -33,   -33,     0,
     -33,   -33,     0,     0,     0,   -33,     0,     0,   -33,   -33,
     253,     0,   253,   -43,     0,   -43,   -43,     0,   -43,   -43,
       0,   253,   186,   -43,     0,     0,   -43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,   253,     0,     0,     0,   254,     0,     0,     0,
     253,   241,   242,   243,   244,   245,   246,     0,   247,   248,
     249,     0,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,     0,   254,     0,
       0,     0,   254,     0,     0,     0,     0,     0,   250,   251,
     254,     0,     0,   252,   -69,     0,     0,     0,     0,     0,
       0,   -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,   -39,   -39,   -39,   253,   310,   -57,
       0,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,
       0,   -57,   -57,   -57,     0,     0,   254,   310,   310,   -39,
       0,   -39,   -39,     0,   -39,   -39,     0,     0,   188,   -39,
       0,     0,   -39,     0,     0,     0,   -57,   -57,   -57,   -57,
       0,   -57,   -57,     0,     0,     0,   -57,     0,   296,   -57,
     -57,     0,     0,   240,   282,   283,     7,     8,     9,     0,
      10,    11,    12,     0,   311,   347,   310,   241,   242,   243,
     244,   245,   246,     0,   247,   248,   249,     0,   347,   348,
       0,     0,     0,     0,     0,   284,   649,   285,    15,     0,
      16,    17,     0,     0,   347,   286,     0,     0,   287,     0,
       0,     0,     0,   532,   250,   251,     0,     0,     0,   252,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,   254,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,   253,     0,   253,
       0,     0,     0,     0,   253,     0,   253,     0,   253,     0,
       0,     0,     0,     0,     0,   254,   254,   254,   254,   254,
     254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     -29,     0,   -29,   -29,   254,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,     0,     0,     0,     0,     0,
       0,     0,   311,   311,   311,   311,   311,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   254,     0,     0,   -29,     0,     0,
     -29,   -29,     0,     0,     0,     0,     0,     0,   348,   348,
     348,   348,   348,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   -52,   -52,     0,   -52,   -52,   254,   -52,
     -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,   -52,     0,
       0,   -50,   -50,     0,   -50,   -50,     0,   -50,   -50,   -50,
     -50,   -50,   -50,     0,   -50,   -50,   -50,     0,     0,     0,
       0,   -52,   210,   -52,   -52,     0,   -52,   -52,     0,     0,
       0,   -52,     0,     0,   -52,     0,   254,     0,   254,   -50,
     212,   -50,   -50,     0,   -50,   -50,     0,   254,     0,   -50,
       0,     0,   -50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,   254,     0,
       0,     0,   255,     0,     0,     0,   254,   241,   242,   243,
     244,   245,   246,     0,   247,   248,   249,     0,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,     0,   255,     0,     0,     0,   255,     0,
       0,     0,     0,   552,   250,   251,   255,     0,   -58,   252,
     -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,
     -58,   -58,   -58,   240,    52,    53,     7,     8,     9,     0,
      10,    11,    12,   254,   311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -58,   -58,   -58,   -58,     0,
     -58,   -58,   255,   311,   311,   -58,     0,     0,   -58,   -58,
      16,    17,     0,     0,     0,    54,   -35,     0,   -35,   -35,
       0,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,
     -35,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   -34,   -34,   -34,     0,     0,     0,     0,
     312,   348,   311,   -35,   -35,   -35,   -35,     0,   -35,   -35,
       0,     0,     0,   -35,   348,   349,   -35,   -35,   -34,   -34,
     -34,   -34,  -139,   -34,   -34,     0,     0,     0,   -34,     0,
     348,   -34,   -34,     0,     0,     0,     0,     0,  -139,  -139,
    -139,  -139,  -139,  -139,     0,     0,   312,     0,  -139,  -139,
    -139,  -139,  -139,  -139,     0,     0,     0,   255,     0,   255,
       0,   255,     0,     0,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,   254,     0,   254,     0,   254,     0,     0,     0,     0,
     254,     0,   254,     0,   254,     0,     0,     0,     0,     0,
       0,   255,   255,   255,   255,   255,   255,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   -47,     0,   -47,   -47,
     255,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,
     -47,     0,     0,     0,     0,     0,     0,     0,   312,   312,
     312,   312,   312,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -47,   -47,   -47,   -47,     0,   -47,   -47,
     255,     0,     0,   -47,     0,     0,   -47,   -47,     0,     0,
       0,     0,     0,     0,   349,   349,   349,   349,   349,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,     0,
     -48,     0,   -48,   -48,   255,   -48,   -48,   -48,   -48,   -48,
     -48,     0,   -48,   -48,   -48,     0,     0,     0,   -37,     0,
     -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
     -37,   -37,   -37,     0,     0,     0,     0,   -48,   -48,   -48,
     -48,     0,   -48,   -48,     0,     0,     0,   -48,     0,     0,
     -48,   -48,   255,     0,   255,   -37,   -37,   -37,   -37,     0,
     -37,   -37,     0,   255,     0,   -37,     0,     0,   -37,   -37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,   255,     0,     0,     0,   256,     0,
       0,     0,   255,   241,   242,   243,   244,   245,   246,     0,
     247,   248,   249,     0,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,     0,
     256,     0,     0,     0,   256,     0,     0,     0,     0,   570,
     250,   251,   256,     0,   -11,   252,   -11,   -11,     0,   -11,
     -11,   -11,   -11,   -11,   -11,     0,   -11,   -11,   -11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -11,   -11,   -11,   -11,     0,   -11,   -11,   256,   312,
     312,   -11,     0,     0,   -11,   -11,     0,     0,     0,     0,
       0,   -35,   -35,     0,   -35,   -35,     0,   -35,   -35,   -35,
     -35,   -35,   -35,     0,   -35,   -35,   -35,   -34,   -34,     0,
     -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,   -34,   -34,     0,     0,     0,   313,   349,   312,   -35,
     -35,   -35,   -35,     0,   -35,   -35,     0,     0,     0,   -35,
     349,   350,   -35,     0,     0,   -34,   -34,   -34,   -34,  -139,
     -34,   -34,     0,     0,  -139,   -34,   349,     0,   -34,     0,
       0,     0,     0,     0,     0,  -139,  -139,  -139,  -139,  -139,
    -139,     0,   313,     0,     0,  -139,  -139,  -139,  -139,  -139,
    -139,     0,     0,   256,     0,   256,     0,   256,     0,     0,
       0,  -139,  -139,  -139,  -139,  -139,  -139,   255,     0,   255,
       0,   255,     0,     0,     0,     0,   255,     0,   255,     0,
     255,     0,     0,     0,     0,     0,     0,   256,   256,   256,
     256,   256,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,     0,     0,   -47,   -47,   256,   -47,   -47,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,
       0,     0,     0,     0,   313,   313,   313,   313,   313,   256,
     298,   299,   300,   301,   302,   303,     0,   304,   305,   306,
       0,     0,   -47,   -47,   -47,   -47,   256,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,     0,     0,     0,     0,
     350,   350,   350,   350,   350,   256,     0,   307,   308,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   -48,   -48,     0,   -48,   -48,
     256,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -48,     0,     0,     0,   -10,     0,   -10,   -10,     0,   -10,
     -10,   -10,   -10,   -10,   -10,     0,   -10,   -10,   -10,     0,
       0,     0,     0,   -48,   -48,   -48,   -48,     0,   -48,   -48,
       0,     0,     0,   -48,     0,     0,   -48,     0,   256,     0,
     256,   -10,   -10,   -10,   -10,     0,   -10,   -10,     0,   256,
       0,   -10,     0,     0,   -10,   -10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
     256,     0,     0,     0,   257,     0,     0,     0,   256,   334,
     335,   336,   337,   338,   339,     0,   340,   341,   342,     0,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,     0,   257,     0,     0,     0,
     257,     0,     0,     0,     0,     0,   343,   344,   257,     0,
     -56,   345,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,
     -56,     0,   -56,   -56,   -56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -56,   -56,   -56,
     -56,     0,   -56,   -56,   257,   313,   313,   -56,     0,     0,
     -56,   -56,     0,     0,     0,     0,     0,     0,   -66,     0,
     -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,
     -66,   -66,   -66,   -49,     0,   -49,   -49,     0,   -49,   -49,
     -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,     0,     0,
       0,     0,   314,   350,   313,   -66,   -66,   -66,   -66,     0,
     -66,   -66,     0,     0,     0,   -66,   350,   351,   -66,   -66,
     -49,   -49,   -49,   -49,   495,   -49,   -49,     0,     0,     0,
     -49,     0,   350,   -49,   -49,     0,     0,     0,     0,     0,
     -78,   -78,   -78,   -81,   -78,   -78,     0,     0,   314,     0,
     -78,   -78,   -78,   -78,   -78,   -78,     0,     0,     0,   257,
       0,   257,     0,   257,     0,     0,   -78,   -78,   -78,   -78,
     -78,  -129,   -78,   256,     0,   256,     0,   256,     0,     0,
       0,     0,   256,     0,   256,     0,   256,     0,     0,     0,
       0,     0,     0,   257,   257,   257,   257,   257,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   -36,     0,
     -36,   -36,   257,   -36,   -36,   -36,   -36,   -36,   -36,     0,
     -36,   -36,   -36,     0,     0,     0,     0,     0,     0,     0,
     314,   314,   314,   314,   314,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,     0,
     -36,   -36,   257,     0,     0,   -36,     0,     0,   -36,   -36,
       0,     0,     0,     0,     0,     0,   351,   351,   351,   351,
     351,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   -37,   -37,     0,   -37,   -37,   257,   -37,   -37,   -37,
     -37,   -37,   -37,     0,   -37,   -37,   -37,     0,     0,   -56,
     -56,     0,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,
     -56,     0,   -56,   -56,   -56,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,     0,   -37,   -37,     0,     0,     0,   -37,
       0,     0,   -37,     0,   257,     0,   257,   -56,   -56,   -56,
     -56,     0,   -56,   -56,     0,   257,     0,   -56,     0,     0,
     -56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,   257,     0,     0,     0,
     258,     0,     0,     0,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,     0,   258,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,   258,   -66,   -66,     0,   -66,   -66,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,   -66,   -66,
     -66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,   314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -66,   -66,   -66,   -66,     0,   -66,   -66,
     258,   314,   314,   -66,     0,     0,   -66,     0,     0,     0,
       0,     0,     0,   -49,   -49,     0,   -49,   -49,     0,   -49,
     -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,   -36,     0,     0,     0,   315,   351,
     314,   -49,   -49,   -49,   -49,     0,   -49,   -49,     0,     0,
       0,   -49,   351,   352,   -49,     0,     0,   -36,   -36,   -36,
     -36,    94,   -36,   -36,     0,     0,   264,   -36,   351,     0,
     -36,     0,     0,     0,     0,     0,     0,   -78,   -78,   -78,
     -81,   -78,   -78,     0,   315,     0,     0,   -78,   -78,   -78,
     -78,   -78,   -78,     0,     0,   258,     0,   258,     0,   258,
       0,     0,     0,   -78,   -78,   -78,   -78,   -78,  -129,   257,
       0,   257,     0,   257,     0,     0,     0,     0,   257,     0,
     257,     0,   257,     0,     0,     0,     0,     0,     0,   258,
     258,   258,   258,   258,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   -12,     0,   -12,   -12,   258,   -12,
     -12,   -12,   -12,   -12,   -12,     0,   -12,   -12,   -12,     0,
       0,     0,     0,     0,     0,     0,   315,   315,   315,   315,
     315,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -12,   -12,   -12,   -12,     0,   -12,   -12,   258,     0,
       0,   -12,     0,     0,   -12,   -12,     0,     0,     0,     0,
       0,     0,   352,   352,   352,   352,   352,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,     0,   -45,     0,
     -45,   -45,   258,   -45,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,   -45,     0,     0,     0,   -46,     0,   -46,   -46,
       0,   -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,
     -46,     0,     0,     0,     0,   -45,   -45,   -45,   -45,     0,
     -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,   -45,
     258,     0,   258,   -46,   -46,   -46,   -46,     0,   -46,   -46,
       0,   258,     0,   -46,     0,     0,   -46,   -46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,   258,     0,     0,     0,   259,     0,     0,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,     0,   259,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
     259,     0,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   -38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   259,   315,   315,   -38,
       0,     0,   -38,   -38,     0,     0,     0,     0,     0,     0,
     -14,     0,   -14,   -14,     0,   -14,   -14,   -14,   -14,   -14,
     -14,     0,   -14,   -14,   -14,   -45,   -45,     0,   -45,   -45,
       0,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,
     -45,     0,     0,     0,   316,   352,   315,   -14,   -14,   -14,
     -14,     0,   -14,   -14,     0,     0,     0,   -14,   352,   353,
     -14,   -14,     0,   -45,   -45,   -45,   -45,    94,   -45,   -45,
       0,     0,     0,   -45,   352,     0,   -45,     0,     0,     0,
       0,     0,     0,   -78,   -78,   -78,   -81,   -78,   -78,     0,
     316,     0,     0,   -78,   -78,   -78,   -78,   -78,   -78,     0,
       0,   259,     0,   259,     0,   259,     0,     0,     0,   -78,
     -78,   -78,   -78,   -78,  -129,   258,     0,   258,     0,   258,
       0,     0,     0,     0,   258,     0,   258,     0,   258,     0,
       0,     0,     0,     0,     0,   259,   259,   259,   259,   259,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
       0,     0,   -46,   -46,   259,   -46,   -46,     0,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,     0,     0,
       0,     0,   316,   316,   316,   316,   316,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -46,   -46,   -46,   -46,   259,   -46,   -46,     0,     0,     0,
     -46,     0,     0,   -46,     0,     0,     0,     0,   353,   353,
     353,   353,   353,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   -38,   -38,     0,   -38,   -38,   259,   -38,
     -38,   -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,     0,
       0,     0,   -65,     0,   -65,   -65,     0,   -65,   -65,   -65,
     -65,   -65,   -65,     0,   -65,   -65,   -65,     0,     0,     0,
       0,   -38,   -38,   -38,   -38,     0,   -38,   -38,     0,     0,
       0,   -38,     0,     0,   -38,     0,   259,     0,   259,   -65,
     -65,   -65,   -65,     0,   -65,   -65,     0,   259,     0,   -65,
       0,     0,   -65,   -65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,     0,   259,     0,
       0,     0,   260,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,     0,   260,     0,     0,     0,   260,     0,
       0,     0,     0,     0,     0,     0,   260,     0,   -26,     0,
     -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,     0,
     -26,   -26,   -26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,     0,
     -26,   -26,   260,   316,   316,   -26,     0,     0,   -26,   -26,
       0,     0,     0,     0,     0,     0,   -13,     0,   -13,   -13,
       0,   -13,   -13,   -13,   -13,   -13,   -13,     0,   -13,   -13,
     -13,   -65,   -65,     0,   -65,   -65,     0,   -65,   -65,   -65,
     -65,   -65,   -65,     0,   -65,   -65,   -65,     0,     0,     0,
     317,   353,   316,   -13,   -13,   -13,   -13,     0,   -13,   -13,
       0,     0,     0,   -13,   353,   354,   -13,   -13,     0,   -65,
     -65,   -65,   -65,  -139,   -65,   -65,     0,     0,     0,   -65,
     353,     0,   -65,     0,     0,     0,     0,     0,     0,  -139,
    -139,  -139,  -139,  -139,  -139,     0,   317,     0,     0,  -139,
    -139,  -139,  -139,  -139,  -139,     0,     0,   260,     0,   260,
       0,   260,     0,     0,     0,  -139,  -139,  -139,  -139,  -139,
    -139,   259,     0,   259,     0,   259,     0,     0,     0,     0,
     259,     0,   259,     0,   259,     0,     0,     0,     0,     0,
       0,   260,   260,   260,   260,   260,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,     0,     0,   -26,   -26,
     260,   -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,
       0,   -26,   -26,   -26,     0,     0,     0,     0,   317,   317,
     317,   317,   317,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -26,   -26,   -26,   -26,
     260,   -26,   -26,     0,     0,     0,   -26,     0,     0,   -26,
       0,     0,     0,     0,   354,   354,   354,   354,   354,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,     0,
     -44,     0,   -44,   -44,   260,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,   -44,   -44,     0,     0,     0,   -40,     0,
     -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,     0,     0,     0,     0,   -44,   -44,   -44,
     -44,     0,   -44,   -44,     0,     0,     0,   -44,     0,     0,
     -44,   -44,   260,     0,   260,   -40,   -40,   -40,   -40,     0,
     -40,   -40,     0,   260,     0,   -40,     0,     0,   -40,   -40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,   260,     0,     0,     0,   261,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,     0,
     261,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,   261,     0,   -42,     0,   -42,   -42,     0,   -42,
     -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,   -42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
     317,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -42,   -42,   -42,   -42,     0,   -42,   -42,   261,   317,
     317,   -42,     0,     0,   -42,   -42,     0,     0,     0,     0,
       0,     0,   -41,     0,   -41,   -41,     0,   -41,   -41,   -41,
     -41,   -41,   -41,     0,   -41,   -41,   -41,   -52,     0,   -52,
     -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,
     -52,   -52,     0,     0,     0,     0,   318,   354,   317,   -41,
     -41,   -41,   -41,     0,   -41,   -41,     0,     0,     0,   -41,
     354,   355,   -41,   -41,   -52,   670,   -52,   -52,  -139,   -52,
     -52,     0,     0,     0,   -52,     0,   354,   -52,   -52,     0,
       0,     0,     0,     0,  -139,  -139,  -139,  -139,  -139,  -139,
       0,     0,   318,     0,  -139,  -139,  -139,  -139,  -139,  -139,
       0,     0,     0,   261,     0,   261,     0,   261,     0,     0,
    -139,  -139,  -139,  -139,     0,  -139,  -139,   260,     0,   260,
       0,   260,     0,     0,     0,     0,   260,     0,   260,     0,
     260,     0,     0,     0,     0,     0,     0,   261,   261,   261,
     261,   261,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   -50,     0,   -50,   -50,   261,   -50,   -50,   -50,
     -50,   -50,   -50,     0,   -50,   -50,   -50,     0,     0,     0,
       0,     0,     0,     0,   318,   318,   318,   318,   318,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -50,
     672,   -50,   -50,     0,   -50,   -50,   261,     0,     0,   -50,
       0,     0,   -50,   -50,     0,     0,     0,     0,     0,     0,
     355,   355,   355,   355,   355,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   -44,   -44,     0,   -44,   -44,
     261,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,
     -44,     0,     0,   -40,   -40,     0,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,     0,
       0,     0,     0,   -44,   -44,   -44,   -44,     0,   -44,   -44,
       0,     0,     0,   -44,     0,     0,   -44,     0,   261,     0,
     261,   -40,   -40,   -40,   -40,     0,   -40,   -40,     0,   261,
       0,   -40,     0,     0,   -40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
     261,     0,     0,     0,   262,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,     0,   262,     0,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,   262,   -42,
     -42,     0,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   -42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   262,   318,   318,   -42,     0,     0,
     -42,     0,     0,     0,     0,     0,     0,   -41,   -41,     0,
     -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,
     -41,   -41,   -41,   -52,   -52,     0,   -52,   -52,     0,   -52,
     -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,   -52,     0,
       0,     0,   319,   355,   318,   -41,   -41,   -41,   -41,     0,
     -41,   -41,     0,     0,     0,   -41,   355,   356,   -41,     0,
       0,   -52,   679,   -52,   -52,   189,   -52,   -52,     0,     0,
       0,   -52,   355,     0,   -52,     0,     0,     0,     0,     0,
       0,  -134,  -134,  -134,     0,  -134,  -134,     0,   319,     0,
       0,  -134,  -134,  -134,  -134,  -134,  -134,     0,     0,   262,
       0,   262,     0,   262,     0,     0,     0,  -134,  -134,  -134,
    -134,  -134,     0,   261,     0,   261,     0,   261,     0,     0,
       0,     0,   261,     0,   261,     0,   261,     0,     0,     0,
       0,     0,     0,   262,   262,   262,   262,   262,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,     0,     0,
     -50,   -50,   262,   -50,   -50,     0,   -50,   -50,   -50,   -50,
     -50,   -50,     0,   -50,   -50,   -50,     0,     0,     0,     0,
     319,   319,   319,   319,   319,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -50,   681,
     -50,   -50,   262,   -50,   -50,     0,     0,     0,   -50,     0,
       0,   -50,     0,     0,     0,     0,   356,   356,   356,   356,
     356,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,     0,   -55,     0,   -55,   -55,   262,   -55,   -55,   -55,
     -55,   -55,   -55,     0,   -55,   -55,   -55,     0,     0,     0,
     -54,     0,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,
     -54,     0,   -54,   -54,   -54,     0,     0,     0,     0,   -55,
     -55,   -55,   -55,     0,   -55,   -55,     0,     0,     0,   -55,
       0,     0,   -55,   -55,   262,     0,   262,   -54,   -54,   -54,
     -54,     0,   -54,   -54,     0,   262,     0,   -54,     0,     0,
     -54,   -54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,   262,     0,     0,   -55,
     -55,     0,   -55,   -55,   262,   -55,   -55,   -55,   -55,   -55,
     -55,     0,   -55,   -55,   -55,     0,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,     0,     0,     0,     0,     0,     0,   -55,   -55,   -55,
     -55,     0,   -55,   -55,     0,   -54,   -54,   -55,   -54,   -54,
     -55,   -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,
     -54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -54,   -54,   -54,   -54,     0,   -54,   -54,
       0,   319,   319,   -54,     0,   -53,   -54,   -53,   -53,     0,
     -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,
       0,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,   -51,
     -51,   -51,     0,   -51,   -51,   -51,     0,     0,     0,     0,
       0,     0,   -53,   -53,   -53,   -53,     0,   -53,   -53,   356,
     319,     0,   -53,     0,     0,   -53,   -53,     0,   -51,   -51,
     -51,   -51,   356,   -51,   -51,     0,     0,     0,   -51,     0,
       0,   -51,   -51,     0,     0,   321,     0,     0,   356,     0,
     240,   322,   323,     7,     8,     9,     0,    10,    11,    12,
       0,     0,     0,     0,     0,     0,   -63,     0,   -63,   -63,
       0,   -63,   -63,   -63,   -63,   -63,   -63,     0,   -63,   -63,
     -63,     0,   324,   660,   325,    15,     0,    16,    17,   262,
       0,   262,   326,   262,     0,   327,     0,     0,   262,     0,
     262,     0,   262,   -63,   -63,   -63,   -63,     0,   -63,   -63,
       0,     0,     0,   -63,     0,     0,   -63,   -63,   -64,     0,
     -64,   -64,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,
     -64,   -64,   -64,   -53,   -53,     0,   -53,   -53,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,     0,
       0,     0,     0,     0,     0,   -64,   -64,   -64,   -64,     0,
     -64,   -64,     0,     0,     0,   -64,     0,     0,   -64,   -64,
       0,   -53,   -53,   -53,   -53,     0,   -53,   -53,     0,   -51,
     -51,   -53,   -51,   -51,   -53,   -51,   -51,   -51,   -51,   -51,
     -51,     0,   -51,   -51,   -51,   -63,   -63,     0,   -63,   -63,
       0,   -63,   -63,   -63,   -63,   -63,   -63,     0,   -63,   -63,
     -63,     0,     0,     0,     0,     0,     0,   -51,   -51,   -51,
     -51,     0,   -51,   -51,     0,     0,     0,   -51,     0,     0,
     -51,     0,     0,   -63,   -63,   -63,   -63,     0,   -63,   -63,
       0,   -64,   -64,   -63,   -64,   -64,   -63,   -64,   -64,   -64,
     -64,   -64,   -64,     0,   -64,   -64,   -64,   -60,     0,   -60,
     -60,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,   -60,
     -60,   -60,     0,     0,     0,     0,     0,     0,     0,   -64,
     -64,   -64,   -64,     0,   -64,   -64,     0,     0,     0,   -64,
       0,     0,   -64,     0,   -60,   -60,   -60,   -60,     0,   -60,
     -60,     0,     0,     0,   -60,     0,     0,   -60,   -60,   -61,
       0,   -61,   -61,     0,   -61,   -61,   -61,   -61,   -61,   -61,
       0,   -61,   -61,   -61,   -62,     0,   -62,   -62,     0,   -62,
     -62,   -62,   -62,   -62,   -62,     0,   -62,   -62,   -62,     0,
       0,     0,     0,     0,     0,     0,   -61,   -61,   -61,   -61,
       0,   -61,   -61,     0,     0,     0,   -61,     0,     0,   -61,
     -61,   -62,   -62,   -62,   -62,     0,   -62,   -62,     0,     0,
       0,   -62,     0,     0,   -62,   -62,   -59,     0,   -59,   -59,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,
     -59,   -60,   -60,     0,   -60,   -60,     0,   -60,   -60,   -60,
     -60,   -60,   -60,     0,   -60,   -60,   -60,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,   -59,     0,   -59,   -59,
       0,     0,     0,   -59,     0,     0,   -59,   -59,     0,   -60,
     -60,   -60,   -60,     0,   -60,   -60,     0,   -61,   -61,   -60,
     -61,   -61,   -60,   -61,   -61,   -61,   -61,   -61,   -61,     0,
     -61,   -61,   -61,   -62,   -62,     0,   -62,   -62,     0,   -62,
     -62,   -62,   -62,   -62,   -62,     0,   -62,   -62,   -62,     0,
       0,     0,     0,     0,     0,   -61,   -61,   -61,   -61,     0,
     -61,   -61,     0,     0,     0,   -61,     0,     0,   -61,     0,
       0,   -62,   -62,   -62,   -62,     0,   -62,   -62,     0,   -59,
     -59,   -62,   -59,   -59,   -62,   -59,   -59,   -59,   -59,   -59,
     -59,     0,   -59,   -59,   -59,    -4,     1,     0,     2,     3,
       0,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,     0,     0,     0,     0,     0,   -59,   -59,   -59,
     -59,     0,   -59,   -59,     0,     0,     0,   -59,     0,     0,
     -59,     0,     0,    13,     0,    14,    15,     0,    16,    17,
       0,    -2,    75,    18,     2,     3,    19,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,    -6,    -6,     0,
      -6,    -6,     0,    -6,    -6,    -6,    -6,    -6,    -6,     0,
      -6,    -6,    -6,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    15,     0,    16,    17,     0,     0,     0,    18,
       0,     0,    19,     0,     0,    -6,     0,    -6,    -6,     0,
      -6,    -6,     0,    -7,    -7,    -6,    -7,    -7,    -6,    -7,
      -7,    -7,    -7,    -7,    -7,     0,    -7,    -7,    -7,    -8,
      -8,     0,    -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,
      -8,     0,    -8,    -8,    -8,     0,     0,     0,     0,     0,
       0,    -7,     0,    -7,    -7,     0,    -7,    -7,     0,     0,
       0,    -7,     0,     0,    -7,     0,     0,    -8,     0,    -8,
      -8,     0,    -8,    -8,     0,   -35,   -35,    -8,   -35,   -35,
      -8,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,
     -35,    -9,    -9,     0,    -9,    -9,     0,    -9,    -9,    -9,
      -9,    -9,    -9,     0,    -9,    -9,    -9,     0,     0,     0,
       0,     0,     0,   -35,     0,   -35,   -35,     0,   -35,   -35,
       0,     0,     0,   -35,     0,     0,   -35,     0,     0,    -9,
       0,    -9,    -9,     0,    -9,    -9,     0,   -34,   -34,    -9,
     -34,   -34,    -9,   -34,   -34,   -34,   -34,   -34,   -34,     0,
     -34,   -34,   -34,   -47,   -47,     0,   -47,   -47,     0,   -47,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,     0,
       0,     0,     0,     0,     0,   -34,     0,   -34,   -34,     0,
     -34,   -34,     0,     0,     0,   -34,     0,     0,   -34,     0,
       0,   -47,     0,   -47,   -47,     0,   -47,   -47,     0,   -48,
     -48,   -47,   -48,   -48,   -47,   -48,   -48,   -48,   -48,   -48,
     -48,     0,   -48,   -48,   -48,   -37,   -37,     0,   -37,   -37,
       0,   -37,   -37,   -37,   -37,   -37,   -37,     0,   -37,   -37,
     -37,     0,     0,     0,     0,     0,     0,   -48,     0,   -48,
     -48,     0,   -48,   -48,     0,     0,     0,   -48,     0,     0,
     -48,     0,     0,   -37,     0,   -37,   -37,     0,   -37,   -37,
       0,   -56,   -56,   -37,   -56,   -56,   -37,   -56,   -56,   -56,
     -56,   -56,   -56,     0,   -56,   -56,   -56,   -66,   -66,     0,
     -66,   -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,
     -66,   -66,   -66,     0,     0,     0,     0,     0,     0,   -56,
       0,   -56,   -56,     0,   -56,   -56,     0,     0,     0,   -56,
       0,     0,   -56,     0,     0,   -66,     0,   -66,   -66,     0,
     -66,   -66,     0,    -5,    -5,   -66,    -5,    -5,   -66,    -5,
      -5,    -5,    -5,    -5,    -5,     0,    -5,    -5,    -5,   -49,
     -49,     0,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
     -49,     0,   -49,   -49,   -49,     0,     0,     0,     0,     0,
       0,    -5,     0,    -5,    -5,     0,    -5,    -5,     0,     0,
       0,    -5,     0,     0,    -5,     0,     0,   -49,     0,   -49,
     -49,     0,   -49,   -49,     0,   -36,   -36,   -49,   -36,   -36,
     -49,   -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,
     -36,   -11,   -11,     0,   -11,   -11,     0,   -11,   -11,   -11,
     -11,   -11,   -11,     0,   -11,   -11,   -11,     0,     0,     0,
       0,     0,     0,   -36,     0,   -36,   -36,     0,   -36,   -36,
       0,     0,     0,   -36,     0,     0,   -36,     0,     0,   -11,
       0,   -11,   -11,     0,   -11,   -11,     0,   -45,   -45,   -11,
     -45,   -45,   -11,   -45,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,   -45,   -46,   -46,     0,   -46,   -46,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,     0,
       0,     0,     0,     0,     0,   -45,     0,   -45,   -45,     0,
     -45,   -45,     0,     0,     0,   -45,     0,     0,   -45,     0,
       0,   -46,     0,   -46,   -46,     0,   -46,   -46,     0,   -38,
     -38,   -46,   -38,   -38,   -46,   -38,   -38,   -38,   -38,   -38,
     -38,     0,   -38,   -38,   -38,   -14,   -14,     0,   -14,   -14,
       0,   -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,   -14,
     -14,     0,     0,     0,     0,     0,     0,   -38,     0,   -38,
     -38,     0,   -38,   -38,     0,     0,     0,   -38,     0,     0,
     -38,     0,     0,   -14,     0,   -14,   -14,     0,   -14,   -14,
       0,   -10,   -10,   -14,   -10,   -10,   -14,   -10,   -10,   -10,
     -10,   -10,   -10,     0,   -10,   -10,   -10,   -65,   -65,     0,
     -65,   -65,     0,   -65,   -65,   -65,   -65,   -65,   -65,     0,
     -65,   -65,   -65,     0,     0,     0,     0,     0,     0,   -10,
       0,   -10,   -10,     0,   -10,   -10,     0,     0,     0,   -10,
       0,     0,   -10,     0,     0,   -65,     0,   -65,   -65,     0,
     -65,   -65,     0,   -26,   -26,   -65,   -26,   -26,   -65,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -13,
     -13,     0,   -13,   -13,     0,   -13,   -13,   -13,   -13,   -13,
     -13,     0,   -13,   -13,   -13,     0,     0,     0,     0,     0,
       0,   -26,     0,   -26,   -26,     0,   -26,   -26,     0,     0,
       0,   -26,     0,     0,   -26,     0,     0,   -13,     0,   -13,
     -13,     0,   -13,   -13,     0,   -12,   -12,   -13,   -12,   -12,
     -13,   -12,   -12,   -12,   -12,   -12,   -12,     0,   -12,   -12,
     -12,   -44,   -44,     0,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,   -44,     0,     0,     0,
       0,     0,     0,   -12,     0,   -12,   -12,     0,   -12,   -12,
       0,     0,     0,   -12,     0,     0,   -12,     0,     0,   -44,
       0,   -44,   -44,     0,   -44,   -44,     0,   -40,   -40,   -44,
     -40,   -40,   -44,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,   -42,   -42,     0,   -42,   -42,     0,   -42,
     -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,   -42,     0,
       0,     0,     0,     0,     0,   -40,     0,   -40,   -40,     0,
     -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,     0,
       0,   -42,     0,   -42,   -42,     0,   -42,   -42,     0,   -41,
     -41,   -42,   -41,   -41,   -42,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   -41,   -41,   -41,   -55,   -55,     0,   -55,   -55,
       0,   -55,   -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,
     -55,     0,     0,     0,     0,     0,     0,   -41,     0,   -41,
     -41,     0,   -41,   -41,     0,     0,     0,   -41,     0,     0,
     -41,     0,     0,   -55,     0,   -55,   -55,     0,   -55,   -55,
       0,   -54,   -54,   -55,   -54,   -54,   -55,   -54,   -54,   -54,
     -54,   -54,   -54,     0,   -54,   -54,   -54,   -53,   -53,     0,
     -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,     0,
     -53,   -53,   -53,     0,     0,     0,     0,     0,     0,   -54,
       0,   -54,   -54,     0,   -54,   -54,     0,     0,     0,   -54,
       0,     0,   -54,     0,     0,   -53,     0,   -53,   -53,     0,
     -53,   -53,     0,   -51,   -51,   -53,   -51,   -51,   -53,   -51,
     -51,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -63,
     -63,     0,   -63,   -63,     0,   -63,   -63,   -63,   -63,   -63,
     -63,     0,   -63,   -63,   -63,     0,     0,     0,     0,     0,
       0,   -51,     0,   -51,   -51,     0,   -51,   -51,     0,     0,
       0,   -51,     0,     0,   -51,     0,     0,   -63,     0,   -63,
     -63,     0,   -63,   -63,     0,   -64,   -64,   -63,   -64,   -64,
     -63,   -64,   -64,   -64,   -64,   -64,   -64,     0,   -64,   -64,
     -64,   -16,   -16,     0,   -16,   -16,     0,   -16,   -16,   -16,
     -16,   -16,   -16,     0,   -16,   -16,   -16,     0,     0,     0,
       0,     0,     0,   -64,     0,   -64,   -64,     0,   -64,   -64,
       0,     0,     0,   -64,     0,     0,   -64,     0,     0,   -16,
       0,   -16,   -16,     0,   -16,   -16,     0,   -60,   -60,   -16,
     -60,   -60,   -16,   -60,   -60,   -60,   -60,   -60,   -60,     0,
     -60,   -60,   -60,   -61,   -61,     0,   -61,   -61,     0,   -61,
     -61,   -61,   -61,   -61,   -61,     0,   -61,   -61,   -61,     0,
       0,     0,     0,     0,     0,   -60,     0,   -60,   -60,     0,
     -60,   -60,     0,     0,     0,   -60,     0,     0,   -60,     0,
       0,   -61,     0,   -61,   -61,     0,   -61,   -61,     0,   -62,
     -62,   -61,   -62,   -62,   -61,   -62,   -62,   -62,   -62,   -62,
     -62,     0,   -62,   -62,   -62,   -59,   -59,     0,   -59,   -59,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   -59,
     -59,     0,     0,     0,     0,     0,     0,   -62,     0,   -62,
     -62,     0,   -62,   -62,     0,     0,     0,   -62,     0,     0,
     -62,     0,     0,   -59,     0,   -59,   -59,     0,   -59,   -59,
       0,     0,   321,   -59,     0,     0,   -59,   240,   322,   323,
       7,     8,     9,     0,    10,    11,    12,    75,     0,     0,
       0,     0,   240,     5,     6,     7,     8,     9,     0,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,   324,
     662,   325,    15,     0,    16,    17,     0,     0,     0,   326,
       0,     0,   327,     0,    13,     0,    14,    15,     0,    16,
      17,     0,     0,   321,    18,     0,     0,    19,   240,   322,
     323,     7,     8,     9,     0,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   451,     0,
     324,     0,   325,    15,     0,    16,    17,     0,     0,     0,
     326,     0,     0,   327,   -78,   -78,   -78,   -81,   -78,   -78,
       0,     0,     0,     0,   -78,   -78,   -78,   -78,   -78,   -78,
       0,     0,   392,     0,     0,     0,     0,     0,     0,     0,
     -78,   -78,   -78,   -78,     0,  -129,   -78,   -78,   -78,   -78,
     -78,   -81,   -78,   -78,     0,     0,     0,     0,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -78,   -78,   -78,   -78,   545,  -129,
     -78,     0,     0,   240,    52,    53,     7,     8,     9,   565,
      10,    11,    12,     0,   240,    52,    53,     7,     8,     9,
     652,    10,    11,    12,     0,   240,    52,    53,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,     0,     0,
      16,    17,     0,     0,   -69,    54,     0,     0,     0,     0,
       0,    16,    17,     0,     0,   -69,    54,     0,     0,     0,
       0,     0,    16,    17,   665,     0,   -69,    54,     0,   240,
      52,    53,     7,     8,     9,    57,    10,    11,    12,     0,
     240,    52,    53,     7,     8,     9,    59,    10,    11,    12,
       0,   240,    52,    53,     7,     8,     9,     0,    10,    11,
      12,     0,     0,     0,     0,     0,    16,    17,     0,     0,
     -69,    54,     0,     0,     0,     0,     0,    16,    17,     0,
       0,     0,    54,     0,     0,     0,     0,     0,    16,    17,
      65,     0,     0,    54,     0,   240,    52,    53,     7,     8,
       9,    67,    10,    11,    12,     0,   240,    52,    53,     7,
       8,     9,    69,    10,    11,    12,     0,   240,    52,    53,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,    54,     0,     0,
       0,     0,     0,    16,    17,     0,     0,     0,    54,     0,
       0,     0,     0,     0,    16,    17,    71,     0,     0,    54,
       0,   241,   242,   243,   244,   245,   246,   109,   247,   248,
     249,     0,   241,   242,   243,   244,   245,   246,   125,   247,
     248,   249,     0,   240,    52,    53,     7,     8,     9,     0,
      10,    11,    12,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,   252,     0,     0,     0,     0,     0,   250,
     251,     0,     0,     0,   252,     0,     0,     0,     0,     0,
      16,    17,   127,     0,     0,    54,     0,   240,    52,    53,
       7,     8,     9,   129,    10,    11,    12,     0,   240,    52,
      53,     7,     8,     9,   131,    10,    11,    12,     0,   240,
      52,    53,     7,     8,     9,     0,    10,    11,    12,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     0,    54,
       0,     0,     0,     0,     0,    16,    17,     0,     0,     0,
      54,     0,     0,     0,     0,     0,    16,    17,   133,     0,
       0,    54,     0,   240,    52,    53,     7,     8,     9,   135,
      10,    11,    12,     0,   240,    52,    53,     7,     8,     9,
     137,    10,    11,    12,     0,   240,    52,    53,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,    54,     0,     0,     0,     0,
       0,    16,    17,     0,     0,     0,    54,     0,     0,     0,
       0,     0,    16,    17,   139,     0,     0,    54,     0,   240,
      52,    53,     7,     8,     9,   141,    10,    11,    12,     0,
     240,    52,    53,     7,     8,     9,   143,    10,    11,    12,
       0,   240,    52,    53,     7,     8,     9,     0,    10,    11,
      12,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,    54,     0,     0,     0,     0,     0,    16,    17,     0,
       0,     0,    54,     0,     0,     0,     0,     0,    16,    17,
     145,     0,     0,    54,     0,   240,    52,    53,     7,     8,
       9,   147,    10,    11,    12,     0,   240,    52,    53,     7,
       8,     9,   149,    10,    11,    12,     0,   240,    52,    53,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,    54,     0,     0,
       0,     0,     0,    16,    17,     0,     0,     0,    54,     0,
       0,     0,     0,     0,    16,    17,   151,     0,     0,    54,
       0,   240,    52,    53,     7,     8,     9,   153,    10,    11,
      12,     0,   240,    52,    53,     7,     8,     9,   381,    10,
      11,    12,     0,   241,   242,   243,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,     0,     0,    16,    17,
       0,     0,     0,    54,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,    54,     0,     0,     0,     0,     0,
     250,   251,   383,     0,     0,   252,     0,   241,   242,   243,
     244,   245,   246,   385,   247,   248,   249,     0,   241,   242,
     243,   244,   245,   246,   387,   247,   248,   249,     0,   241,
     242,   243,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,     0,     0,   250,   251,     0,     0,     0,   252,
       0,     0,     0,     0,     0,   250,   251,     0,     0,     0,
     252,     0,     0,     0,     0,     0,   250,   251,   389,     0,
       0,   252,     0,   241,   242,   243,   244,   245,   246,   395,
     247,   248,   249,     0,   241,   242,   243,   244,   245,   246,
     397,   247,   248,   249,     0,   241,   242,   243,   244,   245,
     246,     0,   247,   248,   249,     0,     0,     0,     0,     0,
     250,   251,     0,     0,     0,   252,     0,     0,     0,     0,
       0,   250,   251,     0,     0,     0,   252,     0,     0,     0,
       0,     0,   250,   251,   399,     0,     0,   252,     0,   241,
     242,   243,   244,   245,   246,   401,   247,   248,   249,     0,
     241,   242,   243,   244,   245,   246,   403,   247,   248,   249,
       0,   241,   242,   243,   244,   245,   246,     0,   247,   248,
     249,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,   252,     0,     0,     0,     0,     0,   250,   251,     0,
       0,     0,   252,     0,     0,     0,     0,     0,   250,   251,
     405,     0,     0,   252,     0,   241,   242,   243,   244,   245,
     246,   407,   247,   248,   249,     0,   241,   242,   243,   244,
     245,   246,   409,   247,   248,   249,     0,   241,   242,   243,
     244,   245,   246,     0,   247,   248,   249,     0,     0,     0,
       0,     0,   250,   251,     0,     0,     0,   252,     0,     0,
       0,     0,     0,   250,   251,     0,     0,     0,   252,     0,
       0,     0,     0,     0,   250,   251,   411,     0,     0,   252,
       0,   241,   242,   243,   244,   245,   246,   413,   247,   248,
     249,     0,   241,   242,   243,   244,   245,   246,   415,   247,
     248,   249,     0,   241,   242,   243,   244,   245,   246,     0,
     247,   248,   249,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,   252,     0,     0,     0,     0,     0,   250,
     251,     0,     0,     0,   252,     0,     0,     0,     0,     0,
     250,   251,   417,     0,     0,   252,     0,   241,   242,   243,
     244,   245,   246,   419,   247,   248,   249,     0,   241,   242,
     243,   244,   245,   246,   421,   247,   248,   249,     0,   241,
     242,   243,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,     0,     0,   250,   251,     0,     0,     0,   252,
       0,     0,     0,     0,     0,   250,   251,     0,     0,     0,
     252,     0,     0,     0,     0,     0,   250,   251,   423,     0,
       0,   252,     0,   241,   242,   243,   244,   245,   246,   433,
     247,   248,   249,     0,   241,   242,   243,   244,   245,   246,
     440,   247,   248,   249,     0,   298,   299,   300,   301,   302,
     303,     0,   304,   305,   306,     0,     0,     0,     0,     0,
     250,   251,     0,     0,     0,   252,     0,     0,     0,     0,
       0,   250,   251,     0,     0,     0,   252,     0,     0,     0,
       0,     0,   307,   308,   442,     0,     0,   309,     0,   298,
     299,   300,   301,   302,   303,   444,   304,   305,   306,     0,
     298,   299,   300,   301,   302,   303,   446,   304,   305,   306,
       0,   298,   299,   300,   301,   302,   303,     0,   304,   305,
     306,     0,     0,     0,     0,     0,   307,   308,     0,     0,
       0,   309,     0,     0,     0,     0,     0,   307,   308,     0,
       0,     0,   309,     0,     0,     0,     0,     0,   307,   308,
     448,     0,     0,   309,     0,   298,   299,   300,   301,   302,
     303,   463,   304,   305,   306,     0,   241,   242,   243,   244,
     245,   246,   469,   247,   248,   249,     0,   334,   335,   336,
     337,   338,   339,     0,   340,   341,   342,     0,     0,     0,
       0,     0,   307,   308,     0,     0,     0,   309,     0,     0,
       0,     0,     0,   250,   251,     0,     0,     0,   252,     0,
       0,     0,     0,     0,   343,   344,   471,     0,     0,   345,
       0,   334,   335,   336,   337,   338,   339,   473,   340,   341,
     342,     0,   334,   335,   336,   337,   338,   339,   475,   340,
     341,   342,     0,   334,   335,   336,   337,   338,   339,     0,
     340,   341,   342,     0,     0,     0,     0,     0,   343,   344,
       0,     0,     0,   345,     0,     0,     0,     0,     0,   343,
     344,     0,     0,     0,   345,     0,     0,     0,     0,     0,
     343,   344,   477,     0,     0,   345,     0,   334,   335,   336,
     337,   338,   339,   499,   340,   341,   342,     0,   298,   299,
     300,   301,   302,   303,   501,   304,   305,   306,     0,   298,
     299,   300,   301,   302,   303,     0,   304,   305,   306,     0,
       0,     0,     0,     0,   343,   344,     0,     0,     0,   345,
       0,     0,     0,     0,     0,   307,   308,     0,     0,     0,
     309,     0,     0,     0,     0,     0,   307,   308,   503,     0,
       0,   309,     0,   298,   299,   300,   301,   302,   303,   505,
     304,   305,   306,     0,   298,   299,   300,   301,   302,   303,
     507,   304,   305,   306,     0,   298,   299,   300,   301,   302,
     303,     0,   304,   305,   306,     0,     0,     0,     0,     0,
     307,   308,     0,     0,     0,   309,     0,     0,     0,     0,
       0,   307,   308,     0,     0,     0,   309,     0,     0,     0,
       0,     0,   307,   308,   509,     0,     0,   309,     0,   298,
     299,   300,   301,   302,   303,   511,   304,   305,   306,     0,
     298,   299,   300,   301,   302,   303,   513,   304,   305,   306,
       0,   298,   299,   300,   301,   302,   303,     0,   304,   305,
     306,     0,     0,     0,     0,     0,   307,   308,     0,     0,
       0,   309,     0,     0,     0,     0,     0,   307,   308,     0,
       0,     0,   309,     0,     0,     0,     0,     0,   307,   308,
     515,     0,     0,   309,     0,   298,   299,   300,   301,   302,
     303,   517,   304,   305,   306,     0,   298,   299,   300,   301,
     302,   303,   519,   304,   305,   306,     0,   298,   299,   300,
     301,   302,   303,     0,   304,   305,   306,     0,     0,     0,
       0,     0,   307,   308,     0,     0,     0,   309,     0,     0,
       0,     0,     0,   307,   308,     0,     0,     0,   309,     0,
       0,     0,     0,     0,   307,   308,   521,     0,     0,   309,
       0,   298,   299,   300,   301,   302,   303,   523,   304,   305,
     306,     0,   298,   299,   300,   301,   302,   303,   525,   304,
     305,   306,     0,   298,   299,   300,   301,   302,   303,     0,
     304,   305,   306,     0,     0,     0,     0,     0,   307,   308,
       0,     0,     0,   309,     0,     0,     0,     0,     0,   307,
     308,     0,     0,     0,   309,     0,     0,     0,     0,     0,
     307,   308,   527,     0,     0,   309,     0,   298,   299,   300,
     301,   302,   303,   543,   304,   305,   306,     0,   241,   242,
     243,   244,   245,   246,   563,   247,   248,   249,     0,   241,
     242,   243,   244,   245,   246,     0,   247,   248,   249,     0,
       0,     0,     0,     0,   307,   308,     0,     0,     0,   309,
       0,     0,     0,     0,     0,   250,   251,     0,     0,     0,
     252,     0,     0,     0,     0,     0,   250,   251,   573,     0,
       0,   252,     0,   334,   335,   336,   337,   338,   339,   575,
     340,   341,   342,     0,   334,   335,   336,   337,   338,   339,
     577,   340,   341,   342,     0,   334,   335,   336,   337,   338,
     339,     0,   340,   341,   342,     0,     0,     0,     0,     0,
     343,   344,     0,     0,     0,   345,     0,     0,     0,     0,
       0,   343,   344,     0,     0,     0,   345,     0,     0,     0,
       0,     0,   343,   344,   579,     0,     0,   345,     0,   334,
     335,   336,   337,   338,   339,   581,   340,   341,   342,     0,
     334,   335,   336,   337,   338,   339,   583,   340,   341,   342,
       0,   334,   335,   336,   337,   338,   339,     0,   340,   341,
     342,     0,     0,     0,     0,     0,   343,   344,     0,     0,
       0,   345,     0,     0,     0,     0,     0,   343,   344,     0,
       0,     0,   345,     0,     0,     0,     0,     0,   343,   344,
     585,     0,     0,   345,     0,   334,   335,   336,   337,   338,
     339,   587,   340,   341,   342,     0,   334,   335,   336,   337,
     338,   339,   589,   340,   341,   342,     0,   334,   335,   336,
     337,   338,   339,     0,   340,   341,   342,     0,     0,     0,
       0,     0,   343,   344,     0,     0,     0,   345,     0,     0,
       0,     0,     0,   343,   344,     0,     0,     0,   345,     0,
       0,     0,     0,     0,   343,   344,   591,     0,     0,   345,
       0,   334,   335,   336,   337,   338,   339,   593,   340,   341,
     342,     0,   334,   335,   336,   337,   338,   339,   595,   340,
     341,   342,     0,   334,   335,   336,   337,   338,   339,     0,
     340,   341,   342,     0,     0,     0,     0,     0,   343,   344,
       0,     0,     0,   345,     0,     0,     0,     0,     0,   343,
     344,     0,     0,     0,   345,     0,     0,     0,     0,     0,
     343,   344,   597,     0,     0,   345,     0,   334,   335,   336,
     337,   338,   339,   599,   340,   341,   342,     0,   334,   335,
     336,   337,   338,   339,   601,   340,   341,   342,     0,   334,
     335,   336,   337,   338,   339,     0,   340,   341,   342,     0,
       0,     0,     0,     0,   343,   344,     0,     0,     0,   345,
       0,     0,   190,     0,     0,   343,   344,     0,     0,     0,
     345,     0,     0,     0,     0,     0,   343,   344,  -133,  -133,
    -133,   345,  -133,  -133,     0,     0,     0,     0,  -133,  -133,
    -133,  -133,  -133,  -133,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -133,  -133,  -133,  -133,  -133,     0,
    -134,  -134,  -134,     0,  -134,  -134,     0,     0,     0,     0,
    -134,  -134,  -134,  -134,  -134,  -134,   646,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -134,  -134,  -134,  -134,
    -134,     0,  -133,  -133,  -133,     0,  -133,  -133,     0,     0,
       0,     0,  -133,  -133,  -133,  -133,  -133,  -133,   658,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -133,  -133,
    -133,  -133,  -133,     0,  -134,  -134,  -134,     0,  -134,  -134,
       0,     0,     0,     0,  -134,  -134,  -134,  -134,  -134,  -134,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -134,  -134,  -134,  -134,  -134,     0,  -133,  -133,  -133,     0,
    -133,  -133,     0,     0,     0,     0,  -133,  -133,  -133,  -133,
    -133,  -133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -133,  -133,  -133,  -133,  -133,   360,   361,   362,
       0,   363,   364,     0,     0,     0,     0,   365,   366,   367,
     368,   369,   370,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   373,   374,     0,     0,  -138,
    -138,   360,   361,   362,     0,   363,   364,     0,     0,     0,
       0,   365,   366,   367,   368,   369,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,   372,   373,
     374,     0,     0,  -137,  -137,  -128,  -128,  -128,     0,  -128,
    -128,     0,     0,     0,     0,  -128,  -128,  -128,  -128,  -128,
    -128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -128,  -128,  -128,  -128,     0,     0,  -128,  -128,  -127,
    -127,  -127,     0,  -127,  -127,     0,     0,     0,     0,  -127,
    -127,  -127,  -127,  -127,  -127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -127,  -127,  -127,  -127,     0,
       0,  -127,  -127,  -126,  -126,  -126,     0,  -126,  -126,     0,
       0,     0,     0,  -126,  -126,  -126,  -126,  -126,  -126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -126,
    -126,  -126,  -126,     0,     0,  -126,  -126,   -71,   -71,   -71,
       0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,   -71,     0,     0,   -71,
     -71,   -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -72,   -72,   -72,
     -72,     0,     0,   -72,   -72,   -73,   -73,   -73,     0,   -73,
     -73,     0,     0,     0,     0,   -73,   -73,   -73,   -73,   -73,
     -73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -73,   -73,   -73,   -73,     0,     0,   -73,   -73,   -74,
     -74,   -74,     0,   -74,   -74,     0,     0,     0,     0,   -74,
     -74,   -74,   -74,   -74,   -74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,     0,
       0,   -74,   -74,   -75,   -75,   -75,     0,   -75,   -75,     0,
       0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -75,
     -75,   -75,   -75,     0,     0,   -75,   -75,  -123,  -123,  -123,
       0,  -123,  -123,     0,     0,     0,     0,  -123,  -123,  -123,
    -123,  -123,  -123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -123,  -123,  -123,  -123,     0,     0,  -123,
    -123,  -124,  -124,  -124,     0,  -124,  -124,     0,     0,     0,
       0,  -124,  -124,  -124,  -124,  -124,  -124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -124,  -124,  -124,
    -124,     0,     0,  -124,  -124,  -125,  -125,  -125,     0,  -125,
    -125,     0,     0,     0,     0,  -125,  -125,  -125,  -125,  -125,
    -125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -125,  -125,  -125,  -125,     0,     0,  -125,  -125,   -76,
     -76,   -76,     0,   -76,   -76,     0,     0,     0,     0,   -76,
     -76,   -76,   -76,   -76,   -76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -76,   -76,   -76,   -76,     0,
       0,   -76,   -76,   -77,   -77,   -77,     0,   -77,   -77,     0,
       0,     0,     0,   -77,   -77,   -77,   -77,   -77,   -77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -77,
     -77,   -77,   -77,     0,     0,   -77,   -77,  -118,  -118,  -118,
       0,  -118,  -118,     0,     0,     0,     0,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -118,  -118,  -118,  -118,     0,     0,  -118,
    -118,  -113,  -113,  -113,     0,  -113,  -113,     0,     0,     0,
       0,  -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -113,  -113,  -113,
    -113,     0,     0,  -113,  -113,  -119,  -119,  -119,     0,  -119,
    -119,     0,     0,     0,     0,  -119,  -119,  -119,  -119,  -119,
    -119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -119,  -119,  -119,  -119,     0,     0,  -119,  -119,  -114,
    -114,  -114,     0,  -114,  -114,     0,     0,     0,     0,  -114,
    -114,  -114,  -114,  -114,  -114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -114,  -114,  -114,  -114,     0,
       0,  -114,  -114,  -120,  -120,  -120,     0,  -120,  -120,     0,
       0,     0,     0,  -120,  -120,  -120,  -120,  -120,  -120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -120,
    -120,  -120,  -120,     0,     0,  -120,  -120,  -115,  -115,  -115,
       0,  -115,  -115,     0,     0,     0,     0,  -115,  -115,  -115,
    -115,  -115,  -115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -115,  -115,  -115,  -115,     0,     0,  -115,
    -115,  -121,  -121,  -121,     0,  -121,  -121,     0,     0,     0,
       0,  -121,  -121,  -121,  -121,  -121,  -121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -121,  -121,  -121,
    -121,     0,     0,  -121,  -121,  -116,  -116,  -116,     0,  -116,
    -116,     0,     0,     0,     0,  -116,  -116,  -116,  -116,  -116,
    -116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -116,  -116,  -116,  -116,     0,     0,  -116,  -116,  -122,
    -122,  -122,     0,  -122,  -122,     0,     0,     0,     0,  -122,
    -122,  -122,  -122,  -122,  -122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -122,  -122,  -122,  -122,     0,
       0,  -122,  -122,  -117,  -117,  -117,     0,  -117,  -117,     0,
       0,     0,     0,  -117,  -117,  -117,  -117,  -117,  -117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -117,
    -117,  -117,  -117,     0,     0,  -117,  -117,   -80,   -80,   -80,
       0,   -80,   -80,     0,     0,     0,     0,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -80,   -80,   -80,   -80,     0,     0,   -80,
     -80,  -110,  -110,  -110,     0,  -110,  -110,     0,     0,     0,
       0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,     0,     0,  -110,  -110,  -107,   361,   362,     0,  -107,
    -107,     0,     0,     0,     0,  -107,  -107,  -107,  -107,  -107,
    -107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,   372,   373,   374,     0,     0,  -107,  -107,  -111,
    -111,  -111,     0,  -111,  -111,     0,     0,     0,     0,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -111,  -111,  -111,  -111,     0,
       0,  -111,  -111,  -108,  -108,   362,     0,  -108,  -108,     0,
       0,     0,     0,  -108,  -108,  -108,  -108,  -108,  -108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,   373,   374,     0,     0,  -108,  -108,  -112,  -112,  -112,
       0,  -112,  -112,     0,     0,     0,     0,  -112,  -112,  -112,
    -112,  -112,  -112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -112,  -112,  -112,  -112,     0,     0,  -112,
    -112,  -109,  -109,  -109,     0,  -109,  -109,     0,     0,     0,
       0,  -109,  -109,  -109,  -109,  -109,  -109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,   372,   373,
     374,     0,     0,  -109,  -109,   -95,   -95,   -95,     0,   -95,
     -95,     0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,
     -95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -95,   -95,   -95,   -95,     0,     0,   -95,   -95,   360,
     361,   362,     0,   -83,   364,     0,     0,     0,     0,   365,
     366,   367,   368,   369,   370,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   371,   372,   373,   374,     0,
       0,   -83,   -83,   -96,   -96,   -96,     0,   -96,   -96,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -96,
     -96,   -96,   -96,     0,     0,   -96,   -96,   360,   361,   362,
       0,   -84,   -84,     0,     0,     0,     0,   365,   366,   367,
     368,   369,   370,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   373,   374,     0,     0,   -84,
     -84,   -97,   -97,   -97,     0,   -97,   -97,     0,     0,     0,
       0,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -97,   -97,   -97,
     -97,     0,     0,   -97,   -97,   360,   361,   362,     0,   -85,
     -85,     0,     0,     0,     0,   -85,   -85,   367,   368,   369,
     370,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,   372,   373,   374,     0,     0,   -85,   -85,   -98,
     -98,   -98,     0,   -98,   -98,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,   -98,   -98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -98,   -98,   -98,   -98,     0,
       0,   -98,   -98,   360,   361,   362,     0,   -86,   -86,     0,
       0,     0,     0,   -86,   -86,   367,   368,   369,   370,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,   373,   374,     0,     0,   -86,   -86,   -99,   -99,   -99,
       0,   -99,   -99,     0,     0,     0,     0,   -99,   -99,   -99,
     -99,   -99,   -99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -99,   -99,   -99,   -99,     0,     0,   -99,
     -99,   360,   361,   362,     0,   -87,   -87,     0,     0,     0,
       0,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,   372,   373,
     374,     0,     0,   -87,   -87,  -100,  -100,  -100,     0,  -100,
    -100,     0,     0,     0,     0,  -100,  -100,  -100,  -100,  -100,
    -100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -100,  -100,  -100,  -100,     0,     0,  -100,  -100,   360,
     361,   362,     0,   -88,   -88,     0,     0,     0,     0,   -88,
     -88,   -88,   -88,   -88,   -88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   371,   372,   373,   374,     0,
       0,   -88,   -88,  -101,  -101,  -101,     0,  -101,  -101,     0,
       0,     0,     0,  -101,  -101,  -101,  -101,  -101,  -101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -101,
    -101,  -101,  -101,     0,     0,  -101,  -101,   360,   361,   362,
       0,   -89,   -89,     0,     0,     0,     0,   -89,   -89,   -89,
     -89,   -89,   -89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   373,   374,     0,     0,   -89,
     -89,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -102,  -102,  -102,
    -102,     0,     0,  -102,  -102,   360,   361,   362,     0,   -90,
     -90,     0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,
     -90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,   372,   373,   374,     0,     0,   -90,   -90,  -103,
    -103,  -103,     0,  -103,  -103,     0,     0,     0,     0,  -103,
    -103,  -103,  -103,  -103,  -103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -103,  -103,  -103,  -103,     0,
       0,  -103,  -103,   -91,   -91,   -91,     0,   -91,   -91,     0,
       0,     0,     0,   -91,   -91,   -91,   -91,   -91,   -91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -91,
     -91,   373,   374,     0,     0,   -91,   -91,  -104,  -104,  -104,
       0,  -104,  -104,     0,     0,     0,     0,  -104,  -104,  -104,
    -104,  -104,  -104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -104,  -104,  -104,  -104,     0,     0,  -104,
    -104,   -92,   -92,   -92,     0,   -92,   -92,     0,     0,     0,
       0,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -92,   -92,   373,
     374,     0,     0,   -92,   -92,  -105,  -105,  -105,     0,  -105,
    -105,     0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,
    -105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -105,  -105,  -105,  -105,     0,     0,  -105,  -105,   -93,
     -93,   -93,     0,   -93,   -93,     0,     0,     0,     0,   -93,
     -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -93,   -93,   -93,   -93,     0,
       0,   -93,   -93,  -106,  -106,  -106,     0,  -106,  -106,     0,
       0,     0,     0,  -106,  -106,  -106,  -106,  -106,  -106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -106,
    -106,  -106,  -106,     0,     0,  -106,  -106,   -94,   -94,   -94,
       0,   -94,   -94,     0,     0,     0,     0,   -94,   -94,   -94,
     -94,   -94,   -94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -94,   -94,   -94,   -94,     0,     0,   -94,
     -94,   -79,   -79,   -79,     0,   -79,   -79,     0,     0,     0,
       0,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -79,   -79,   -79,
     -79,     0,     0,   -79,   -79,  -134,  -134,  -134,     0,  -134,
    -134,     0,     0,     0,     0,  -134,  -134,  -134,  -134,  -134,
    -134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -134,  -134,  -134,  -134,     0,     0,  -134,  -134,  -133,
    -133,  -133,     0,  -133,  -133,     0,     0,     0,     0,  -133,
    -133,  -133,  -133,  -133,  -133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -133,  -133,  -133,  -133,     0,
       0,  -133,  -133,   360,   361,   362,     0,   363,   364,     0,
       0,     0,     0,   365,   366,   367,   368,   369,   370,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,   373,   374,     0,     0,   -82,   -82,  -132,  -132,  -132,
       0,  -132,  -132,     0,     0,     0,     0,  -132,  -132,  -132,
    -132,  -132,  -132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -132,  -132,  -132,  -132,     0,     0,  -132,
    -132,  -130,  -130,  -130,     0,  -130,  -130,     0,     0,     0,
       0,  -130,  -130,  -130,  -130,  -130,  -130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -130,  -130,  -130,
    -130,     0,     0,  -130,  -130,  -128,  -128,  -128,     0,  -128,
    -128,     0,     0,     0,     0,  -128,  -128,  -128,  -128,  -128,
    -128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -128,  -128,  -128,  -128,  -128,     0,  -128,  -127,  -127,
    -127,     0,  -127,  -127,     0,     0,     0,     0,  -127,  -127,
    -127,  -127,  -127,  -127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -127,  -127,  -127,  -127,  -127,     0,
    -127,  -126,  -126,  -126,     0,  -126,  -126,     0,     0,     0,
       0,  -126,  -126,  -126,  -126,  -126,  -126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -126,  -126,  -126,
    -126,  -126,     0,  -126,   480,   481,   482,     0,   483,   484,
       0,     0,     0,     0,   485,   486,   487,   488,   489,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,   492,   493,   494,   -70,     0,   -70,   -71,   -71,   -71,
       0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,   -71,   -71,     0,   -71,
     -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,     0,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,
     -72,     0,   -72,   -73,   -73,   -73,     0,   -73,   -73,     0,
       0,     0,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -73,
     -73,   -73,   -73,   -73,     0,   -73,   -74,   -74,   -74,     0,
     -74,   -74,     0,     0,     0,     0,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -74,   -74,   -74,   -74,   -74,     0,   -74,   -75,
     -75,   -75,     0,   -75,   -75,     0,     0,     0,     0,   -75,
     -75,   -75,   -75,   -75,   -75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,
       0,   -75,  -123,  -123,  -123,     0,  -123,  -123,     0,     0,
       0,     0,  -123,  -123,  -123,  -123,  -123,  -123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -123,  -123,
    -123,  -123,  -123,     0,  -123,  -124,  -124,  -124,     0,  -124,
    -124,     0,     0,     0,     0,  -124,  -124,  -124,  -124,  -124,
    -124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -124,  -124,  -124,  -124,  -124,     0,  -124,  -125,  -125,
    -125,     0,  -125,  -125,     0,     0,     0,     0,  -125,  -125,
    -125,  -125,  -125,  -125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -125,  -125,  -125,  -125,  -125,     0,
    -125,   -76,   -76,   -76,     0,   -76,   -76,     0,     0,     0,
       0,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -76,   -76,   -76,
     -76,   -76,     0,   -76,   -77,   -77,   -77,     0,   -77,   -77,
       0,     0,     0,     0,   -77,   -77,   -77,   -77,   -77,   -77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -77,   -77,   -77,   -77,   -77,     0,   -77,  -118,  -118,  -118,
       0,  -118,  -118,     0,     0,     0,     0,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -118,  -118,  -118,  -118,  -118,     0,  -118,
    -113,  -113,  -113,     0,  -113,  -113,     0,     0,     0,     0,
    -113,  -113,  -113,  -113,  -113,  -113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -113,  -113,  -113,  -113,
    -113,     0,  -113,  -119,  -119,  -119,     0,  -119,  -119,     0,
       0,     0,     0,  -119,  -119,  -119,  -119,  -119,  -119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -119,
    -119,  -119,  -119,  -119,     0,  -119,  -114,  -114,  -114,     0,
    -114,  -114,     0,     0,     0,     0,  -114,  -114,  -114,  -114,
    -114,  -114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -114,  -114,  -114,  -114,  -114,     0,  -114,  -120,
    -120,  -120,     0,  -120,  -120,     0,     0,     0,     0,  -120,
    -120,  -120,  -120,  -120,  -120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -120,  -120,  -120,  -120,  -120,
       0,  -120,  -115,  -115,  -115,     0,  -115,  -115,     0,     0,
       0,     0,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -115,  -115,
    -115,  -115,  -115,     0,  -115,  -121,  -121,  -121,     0,  -121,
    -121,     0,     0,     0,     0,  -121,  -121,  -121,  -121,  -121,
    -121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -121,  -121,  -121,  -121,  -121,     0,  -121,  -116,  -116,
    -116,     0,  -116,  -116,     0,     0,     0,     0,  -116,  -116,
    -116,  -116,  -116,  -116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -116,  -116,  -116,  -116,  -116,     0,
    -116,  -122,  -122,  -122,     0,  -122,  -122,     0,     0,     0,
       0,  -122,  -122,  -122,  -122,  -122,  -122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -122,  -122,  -122,
    -122,  -122,     0,  -122,  -117,  -117,  -117,     0,  -117,  -117,
       0,     0,     0,     0,  -117,  -117,  -117,  -117,  -117,  -117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -117,  -117,  -117,  -117,  -117,     0,  -117,   -80,   -80,   -80,
       0,   -80,   -80,     0,     0,     0,     0,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -80,   -80,   -80,   -80,   -80,     0,   -80,
     -79,   -79,   -79,     0,   -79,   -79,     0,     0,     0,     0,
     -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -79,   -79,   -79,   -79,
     -79,     0,   -79,  -110,  -110,  -110,     0,  -110,  -110,     0,
       0,     0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -110,
    -110,  -110,  -110,  -110,     0,  -110,  -107,   481,   482,     0,
    -107,  -107,     0,     0,     0,     0,  -107,  -107,  -107,  -107,
    -107,  -107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   492,   493,   494,  -107,     0,  -107,  -111,
    -111,  -111,     0,  -111,  -111,     0,     0,     0,     0,  -111,
    -111,  -111,  -111,  -111,  -111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -111,  -111,  -111,  -111,  -111,
       0,  -111,  -108,  -108,   482,     0,  -108,  -108,     0,     0,
       0,     0,  -108,  -108,  -108,  -108,  -108,  -108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,   494,  -108,     0,  -108,  -112,  -112,  -112,     0,  -112,
    -112,     0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,
    -112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -112,  -112,  -112,  -112,  -112,     0,  -112,  -109,  -109,
    -109,     0,  -109,  -109,     0,     0,     0,     0,  -109,  -109,
    -109,  -109,  -109,  -109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,   494,  -109,     0,
    -109,   -95,   -95,   -95,     0,   -95,   -95,     0,     0,     0,
       0,   -95,   -95,   -95,   -95,   -95,   -95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -95,   -95,   -95,
     -95,   -95,     0,   -95,   480,   481,   482,     0,   -83,   484,
       0,     0,     0,     0,   485,   486,   487,   488,   489,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,   492,   493,   494,   -83,     0,   -83,   -96,   -96,   -96,
       0,   -96,   -96,     0,     0,     0,     0,   -96,   -96,   -96,
     -96,   -96,   -96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,   -96,     0,   -96,
     480,   481,   482,     0,   -84,   -84,     0,     0,     0,     0,
     485,   486,   487,   488,   489,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   492,   493,   494,
     -84,     0,   -84,   -97,   -97,   -97,     0,   -97,   -97,     0,
       0,     0,     0,   -97,   -97,   -97,   -97,   -97,   -97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -97,
     -97,   -97,   -97,   -97,     0,   -97,   480,   481,   482,     0,
     -85,   -85,     0,     0,     0,     0,   -85,   -85,   487,   488,
     489,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   492,   493,   494,   -85,     0,   -85,   -98,
     -98,   -98,     0,   -98,   -98,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,   -98,   -98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -98,   -98,   -98,   -98,   -98,
       0,   -98,   480,   481,   482,     0,   -86,   -86,     0,     0,
       0,     0,   -86,   -86,   487,   488,   489,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,   494,   -86,     0,   -86,   -99,   -99,   -99,     0,   -99,
     -99,     0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,
     -99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -99,   -99,   -99,   -99,   -99,     0,   -99,   480,   481,
     482,     0,   -87,   -87,     0,     0,     0,     0,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,   494,   -87,     0,
     -87,  -100,  -100,  -100,     0,  -100,  -100,     0,     0,     0,
       0,  -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -100,  -100,  -100,
    -100,  -100,     0,  -100,   480,   481,   482,     0,   -88,   -88,
       0,     0,     0,     0,   -88,   -88,   -88,   -88,   -88,   -88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,   492,   493,   494,   -88,     0,   -88,  -101,  -101,  -101,
       0,  -101,  -101,     0,     0,     0,     0,  -101,  -101,  -101,
    -101,  -101,  -101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -101,  -101,  -101,  -101,  -101,     0,  -101,
     480,   481,   482,     0,   -89,   -89,     0,     0,     0,     0,
     -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,   492,   493,   494,
     -89,     0,   -89,  -102,  -102,  -102,     0,  -102,  -102,     0,
       0,     0,     0,  -102,  -102,  -102,  -102,  -102,  -102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -102,
    -102,  -102,  -102,  -102,     0,  -102,   480,   481,   482,     0,
     -90,   -90,     0,     0,     0,     0,   -90,   -90,   -90,   -90,
     -90,   -90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   491,   492,   493,   494,   -90,     0,   -90,  -103,
    -103,  -103,     0,  -103,  -103,     0,     0,     0,     0,  -103,
    -103,  -103,  -103,  -103,  -103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -103,  -103,  -103,  -103,  -103,
       0,  -103,   -91,   -91,   -91,     0,   -91,   -91,     0,     0,
       0,     0,   -91,   -91,   -91,   -91,   -91,   -91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -91,   -91,
     493,   494,   -91,     0,   -91,  -104,  -104,  -104,     0,  -104,
    -104,     0,     0,     0,     0,  -104,  -104,  -104,  -104,  -104,
    -104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -104,  -104,  -104,  -104,  -104,     0,  -104,   -92,   -92,
     -92,     0,   -92,   -92,     0,     0,     0,     0,   -92,   -92,
     -92,   -92,   -92,   -92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -92,   -92,   493,   494,   -92,     0,
     -92,  -105,  -105,  -105,     0,  -105,  -105,     0,     0,     0,
       0,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -105,  -105,  -105,
    -105,  -105,     0,  -105,   -93,   -93,   -93,     0,   -93,   -93,
       0,     0,     0,     0,   -93,   -93,   -93,   -93,   -93,   -93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -93,   -93,   -93,   -93,   -93,     0,   -93,  -106,  -106,  -106,
       0,  -106,  -106,     0,     0,     0,     0,  -106,  -106,  -106,
    -106,  -106,  -106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -106,  -106,  -106,  -106,  -106,     0,  -106,
     -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,     0,
     -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -94,   -94,   -94,   -94,
     -94,     0,   -94,  -134,  -134,  -134,     0,  -134,  -134,     0,
       0,     0,     0,  -134,  -134,  -134,  -134,  -134,  -134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -134,
    -134,  -134,  -134,  -134,     0,  -134,  -133,  -133,  -133,     0,
    -133,  -133,     0,     0,     0,     0,  -133,  -133,  -133,  -133,
    -133,  -133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -133,  -133,  -133,  -133,  -133,     0,  -133,   480,
     481,   482,     0,   483,   484,     0,     0,     0,     0,   485,
     486,   487,   488,   489,   490,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,   492,   493,   494,   -82,
       0,   -82,  -132,  -132,  -132,     0,  -132,  -132,     0,     0,
       0,     0,  -132,  -132,  -132,  -132,  -132,  -132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -132,  -132,
    -132,  -132,  -132,     0,  -132,  -130,  -130,  -130,     0,  -130,
    -130,     0,     0,     0,     0,  -130,  -130,  -130,  -130,  -130,
    -130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -130,  -130,  -130,  -130,  -130,     0,  -130,   267,   268,
     269,     0,   270,   271,     0,     0,     0,     0,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   279,   280,   281,     0,     0,
     115,   267,   268,   269,     0,   270,   271,     0,     0,     0,
       0,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,   280,
     281,     0,     0,   166,   267,   268,   269,     0,   270,   271,
       0,     0,     0,     0,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   279,   280,   281,     0,     0,   170,   267,   268,   269,
       0,   270,   271,     0,     0,     0,     0,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,   280,   281,     0,     0,   192,
    -128,  -128,  -128,     0,  -128,  -128,     0,     0,     0,     0,
    -128,  -128,  -128,  -128,  -128,  -128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -128,  -128,  -128,  -128,
       0,     0,  -128,  -127,  -127,  -127,     0,  -127,  -127,     0,
       0,     0,     0,  -127,  -127,  -127,  -127,  -127,  -127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -127,
    -127,  -127,  -127,     0,     0,  -127,  -126,  -126,  -126,     0,
    -126,  -126,     0,     0,     0,     0,  -126,  -126,  -126,  -126,
    -126,  -126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -126,  -126,  -126,  -126,     0,     0,  -126,   -71,
     -71,   -71,     0,   -71,   -71,     0,     0,     0,     0,   -71,
     -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -71,   -71,   -71,   -71,     0,
       0,   -71,   -72,   -72,   -72,     0,   -72,   -72,     0,     0,
       0,     0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,     0,     0,   -72,   -73,   -73,   -73,     0,   -73,
     -73,     0,     0,     0,     0,   -73,   -73,   -73,   -73,   -73,
     -73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -73,   -73,   -73,   -73,     0,     0,   -73,   -74,   -74,
     -74,     0,   -74,   -74,     0,     0,     0,     0,   -74,   -74,
     -74,   -74,   -74,   -74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -74,   -74,   -74,   -74,     0,     0,
     -74,   -75,   -75,   -75,     0,   -75,   -75,     0,     0,     0,
       0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -75,   -75,   -75,
     -75,     0,     0,   -75,  -123,  -123,  -123,     0,  -123,  -123,
       0,     0,     0,     0,  -123,  -123,  -123,  -123,  -123,  -123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -123,  -123,  -123,  -123,     0,     0,  -123,  -124,  -124,  -124,
       0,  -124,  -124,     0,     0,     0,     0,  -124,  -124,  -124,
    -124,  -124,  -124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -124,  -124,  -124,  -124,     0,     0,  -124,
    -125,  -125,  -125,     0,  -125,  -125,     0,     0,     0,     0,
    -125,  -125,  -125,  -125,  -125,  -125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -125,  -125,  -125,  -125,
       0,     0,  -125,   -76,   -76,   -76,     0,   -76,   -76,     0,
       0,     0,     0,   -76,   -76,   -76,   -76,   -76,   -76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -76,
     -76,   -76,   -76,     0,     0,   -76,   -77,   -77,   -77,     0,
     -77,   -77,     0,     0,     0,     0,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -77,   -77,   -77,   -77,     0,     0,   -77,   267,
     268,   269,     0,   270,   271,     0,     0,     0,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   279,   280,   281,     0,
       0,   -70,  -118,  -118,  -118,     0,  -118,  -118,     0,     0,
       0,     0,  -118,  -118,  -118,  -118,  -118,  -118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -118,  -118,
    -118,  -118,     0,     0,  -118,  -113,  -113,  -113,     0,  -113,
    -113,     0,     0,     0,     0,  -113,  -113,  -113,  -113,  -113,
    -113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -113,  -113,  -113,  -113,     0,     0,  -113,  -119,  -119,
    -119,     0,  -119,  -119,     0,     0,     0,     0,  -119,  -119,
    -119,  -119,  -119,  -119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -119,  -119,  -119,  -119,     0,     0,
    -119,  -114,  -114,  -114,     0,  -114,  -114,     0,     0,     0,
       0,  -114,  -114,  -114,  -114,  -114,  -114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -114,  -114,  -114,
    -114,     0,     0,  -114,  -120,  -120,  -120,     0,  -120,  -120,
       0,     0,     0,     0,  -120,  -120,  -120,  -120,  -120,  -120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -120,  -120,  -120,  -120,     0,     0,  -120,  -115,  -115,  -115,
       0,  -115,  -115,     0,     0,     0,     0,  -115,  -115,  -115,
    -115,  -115,  -115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -115,  -115,  -115,  -115,     0,     0,  -115,
    -121,  -121,  -121,     0,  -121,  -121,     0,     0,     0,     0,
    -121,  -121,  -121,  -121,  -121,  -121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -121,  -121,  -121,  -121,
       0,     0,  -121,  -116,  -116,  -116,     0,  -116,  -116,     0,
       0,     0,     0,  -116,  -116,  -116,  -116,  -116,  -116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -116,
    -116,  -116,  -116,     0,     0,  -116,  -122,  -122,  -122,     0,
    -122,  -122,     0,     0,     0,     0,  -122,  -122,  -122,  -122,
    -122,  -122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -122,  -122,  -122,  -122,     0,     0,  -122,  -117,
    -117,  -117,     0,  -117,  -117,     0,     0,     0,     0,  -117,
    -117,  -117,  -117,  -117,  -117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -117,  -117,  -117,  -117,     0,
       0,  -117,   267,   268,   269,     0,   270,   271,     0,     0,
       0,     0,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,   279,
     280,   281,     0,     0,   534,   -80,   -80,   -80,     0,   -80,
     -80,     0,     0,     0,     0,   -80,   -80,   -80,   -80,   -80,
     -80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -80,   -80,   -80,   -80,     0,     0,   -80,  -110,  -110,
    -110,     0,  -110,  -110,     0,     0,     0,     0,  -110,  -110,
    -110,  -110,  -110,  -110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -110,  -110,  -110,  -110,     0,     0,
    -110,  -107,   268,   269,     0,  -107,  -107,     0,     0,     0,
       0,  -107,  -107,  -107,  -107,  -107,  -107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,   280,
     281,     0,     0,  -107,  -111,  -111,  -111,     0,  -111,  -111,
       0,     0,     0,     0,  -111,  -111,  -111,  -111,  -111,  -111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -111,  -111,  -111,  -111,     0,     0,  -111,  -108,  -108,   269,
       0,  -108,  -108,     0,     0,     0,     0,  -108,  -108,  -108,
    -108,  -108,  -108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,   280,   281,     0,     0,  -108,
    -112,  -112,  -112,     0,  -112,  -112,     0,     0,     0,     0,
    -112,  -112,  -112,  -112,  -112,  -112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -112,  -112,  -112,  -112,
       0,     0,  -112,  -109,  -109,  -109,     0,  -109,  -109,     0,
       0,     0,     0,  -109,  -109,  -109,  -109,  -109,  -109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     279,   280,   281,     0,     0,  -109,   -95,   -95,   -95,     0,
     -95,   -95,     0,     0,     0,     0,   -95,   -95,   -95,   -95,
     -95,   -95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -95,   -95,   -95,   -95,     0,     0,   -95,   267,
     268,   269,     0,   -83,   271,     0,     0,     0,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   279,   280,   281,     0,
       0,   -83,   -96,   -96,   -96,     0,   -96,   -96,     0,     0,
       0,     0,   -96,   -96,   -96,   -96,   -96,   -96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -96,   -96,
     -96,   -96,     0,     0,   -96,   267,   268,   269,     0,   -84,
     -84,     0,     0,     0,     0,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,   280,   281,     0,     0,   -84,   -97,   -97,
     -97,     0,   -97,   -97,     0,     0,     0,     0,   -97,   -97,
     -97,   -97,   -97,   -97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -97,   -97,   -97,   -97,     0,     0,
     -97,   267,   268,   269,     0,   -85,   -85,     0,     0,     0,
       0,   -85,   -85,   274,   275,   276,   277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,   280,
     281,     0,     0,   -85,   -98,   -98,   -98,     0,   -98,   -98,
       0,     0,     0,     0,   -98,   -98,   -98,   -98,   -98,   -98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -98,   -98,   -98,   -98,     0,     0,   -98,   267,   268,   269,
       0,   -86,   -86,     0,     0,     0,     0,   -86,   -86,   274,
     275,   276,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,   280,   281,     0,     0,   -86,
     -99,   -99,   -99,     0,   -99,   -99,     0,     0,     0,     0,
     -99,   -99,   -99,   -99,   -99,   -99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -99,   -99,   -99,   -99,
       0,     0,   -99,   267,   268,   269,     0,   -87,   -87,     0,
       0,     0,     0,   -87,   -87,   -87,   -87,   -87,   -87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     279,   280,   281,     0,     0,   -87,  -100,  -100,  -100,     0,
    -100,  -100,     0,     0,     0,     0,  -100,  -100,  -100,  -100,
    -100,  -100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -100,  -100,  -100,  -100,     0,     0,  -100,   267,
     268,   269,     0,   -88,   -88,     0,     0,     0,     0,   -88,
     -88,   -88,   -88,   -88,   -88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   279,   280,   281,     0,
       0,   -88,  -101,  -101,  -101,     0,  -101,  -101,     0,     0,
       0,     0,  -101,  -101,  -101,  -101,  -101,  -101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -101,  -101,
    -101,  -101,     0,     0,  -101,   267,   268,   269,     0,   -89,
     -89,     0,     0,     0,     0,   -89,   -89,   -89,   -89,   -89,
     -89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,   280,   281,     0,     0,   -89,  -102,  -102,
    -102,     0,  -102,  -102,     0,     0,     0,     0,  -102,  -102,
    -102,  -102,  -102,  -102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -102,  -102,  -102,  -102,     0,     0,
    -102,   267,   268,   269,     0,   -90,   -90,     0,     0,     0,
       0,   -90,   -90,   -90,   -90,   -90,   -90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,   280,
     281,     0,     0,   -90,  -103,  -103,  -103,     0,  -103,  -103,
       0,     0,     0,     0,  -103,  -103,  -103,  -103,  -103,  -103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -103,  -103,  -103,  -103,     0,     0,  -103,   -91,   -91,   -91,
       0,   -91,   -91,     0,     0,     0,     0,   -91,   -91,   -91,
     -91,   -91,   -91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -91,   -91,   280,   281,     0,     0,   -91,
    -104,  -104,  -104,     0,  -104,  -104,     0,     0,     0,     0,
    -104,  -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -104,  -104,  -104,  -104,
       0,     0,  -104,   -92,   -92,   -92,     0,   -92,   -92,     0,
       0,     0,     0,   -92,   -92,   -92,   -92,   -92,   -92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -92,
     -92,   280,   281,     0,     0,   -92,  -105,  -105,  -105,     0,
    -105,  -105,     0,     0,     0,     0,  -105,  -105,  -105,  -105,
    -105,  -105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -105,  -105,  -105,  -105,     0,     0,  -105,   -93,
     -93,   -93,     0,   -93,   -93,     0,     0,     0,     0,   -93,
     -93,   -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -93,   -93,   -93,   -93,     0,
       0,   -93,  -106,  -106,  -106,     0,  -106,  -106,     0,     0,
       0,     0,  -106,  -106,  -106,  -106,  -106,  -106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -106,  -106,
    -106,  -106,     0,     0,  -106,   -94,   -94,   -94,     0,   -94,
     -94,     0,     0,     0,     0,   -94,   -94,   -94,   -94,   -94,
     -94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -94,   -94,   -94,   -94,     0,     0,   -94,   267,   268,
     269,     0,   270,   271,     0,     0,     0,     0,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   279,   280,   281,     0,     0,
     554,   267,   268,   269,     0,   270,   271,     0,     0,     0,
       0,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,   280,
     281,     0,     0,   572,   267,   268,   269,     0,   270,   271,
       0,     0,     0,     0,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   279,   280,   281,     0,     0,   607,   -79,   -79,   -79,
       0,   -79,   -79,     0,     0,     0,     0,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -79,   -79,   -79,   -79,     0,     0,   -79,
     267,   268,   269,     0,   270,   271,     0,     0,     0,     0,
     272,   273,   274,   275,   276,   277,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,   279,   280,   281,
       0,     0,   613,   267,   268,   269,     0,   270,   271,     0,
       0,     0,     0,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     279,   280,   281,     0,     0,   615,   267,   268,   269,     0,
     270,   271,     0,     0,     0,     0,   272,   273,   274,   275,
     276,   277,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   279,   280,   281,     0,     0,   623,   267,
     268,   269,     0,   270,   271,     0,     0,     0,     0,   272,
     273,   274,   275,   276,   277,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   279,   280,   281,     0,
       0,   629,   267,   268,   269,     0,   270,   271,     0,     0,
       0,     0,   272,   273,   274,   275,   276,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,   279,
     280,   281,     0,     0,   631,   267,   268,   269,     0,   270,
     271,     0,     0,     0,     0,   272,   273,   274,   275,   276,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,   280,   281,     0,     0,   638,  -134,  -134,
    -134,     0,  -134,  -134,     0,     0,     0,     0,  -134,  -134,
    -134,  -134,  -134,  -134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -134,  -134,  -134,  -134,     0,     0,
    -134,  -133,  -133,  -133,     0,  -133,  -133,     0,     0,     0,
       0,  -133,  -133,  -133,  -133,  -133,  -133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -133,  -133,  -133,
    -133,     0,     0,  -133,   267,   268,   269,     0,   270,   271,
       0,     0,     0,     0,   272,   273,   274,   275,   276,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   279,   280,   281,     0,     0,   -82,  -132,  -132,  -132,
       0,  -132,  -132,     0,     0,     0,     0,  -132,  -132,  -132,
    -132,  -132,  -132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -132,  -132,  -132,  -132,     0,     0,  -132,
    -130,  -130,  -130,     0,  -130,  -130,     0,     0,     0,     0,
    -130,  -130,  -130,  -130,  -130,  -130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -130,  -130,  -130,  -130,
       0,     0,  -130,  -128,  -128,  -128,     0,  -128,  -128,     0,
       0,     0,     0,  -128,  -128,  -128,  -128,  -128,  -128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -128,
    -128,  -128,  -128,  -128,  -127,  -127,  -127,     0,  -127,  -127,
       0,     0,     0,     0,  -127,  -127,  -127,  -127,  -127,  -127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -127,  -127,  -127,  -127,  -127,  -126,  -126,  -126,     0,  -126,
    -126,     0,     0,     0,     0,  -126,  -126,  -126,  -126,  -126,
    -126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -126,  -126,  -126,  -126,  -126,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,    93,   -71,   -71,   -71,
       0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,   -71,   -71,   -72,   -72,
     -72,     0,   -72,   -72,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,   -72,   -72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -72,   -72,   -72,   -72,   -72,   -73,
     -73,   -73,     0,   -73,   -73,     0,     0,     0,     0,   -73,
     -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -73,   -73,   -73,   -73,   -73,
     -74,   -74,   -74,     0,   -74,   -74,     0,     0,     0,     0,
     -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -74,   -74,   -74,   -74,
     -74,   -75,   -75,   -75,     0,   -75,   -75,     0,     0,     0,
       0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -75,   -75,   -75,
     -75,   -75,  -123,  -123,  -123,     0,  -123,  -123,     0,     0,
       0,     0,  -123,  -123,  -123,  -123,  -123,  -123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -123,  -123,
    -123,  -123,  -123,  -124,  -124,  -124,     0,  -124,  -124,     0,
       0,     0,     0,  -124,  -124,  -124,  -124,  -124,  -124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -124,
    -124,  -124,  -124,  -124,  -125,  -125,  -125,     0,  -125,  -125,
       0,     0,     0,     0,  -125,  -125,  -125,  -125,  -125,  -125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -125,  -125,  -125,  -125,  -125,   -76,   -76,   -76,     0,   -76,
     -76,     0,     0,     0,     0,   -76,   -76,   -76,   -76,   -76,
     -76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -76,   -76,   -76,   -76,   -76,   -77,   -77,   -77,     0,
     -77,   -77,     0,     0,     0,     0,   -77,   -77,   -77,   -77,
     -77,   -77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -77,   -77,   -77,   -77,   -77,  -118,  -118,  -118,
       0,  -118,  -118,     0,     0,     0,     0,  -118,  -118,  -118,
    -118,  -118,  -118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -118,  -118,  -118,  -118,  -118,  -113,  -113,
    -113,     0,  -113,  -113,     0,     0,     0,     0,  -113,  -113,
    -113,  -113,  -113,  -113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -113,  -113,  -113,  -113,  -113,  -119,
    -119,  -119,     0,  -119,  -119,     0,     0,     0,     0,  -119,
    -119,  -119,  -119,  -119,  -119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -119,  -119,  -119,  -119,  -119,
    -114,  -114,  -114,     0,  -114,  -114,     0,     0,     0,     0,
    -114,  -114,  -114,  -114,  -114,  -114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -114,  -114,  -114,  -114,
    -114,  -120,  -120,  -120,     0,  -120,  -120,     0,     0,     0,
       0,  -120,  -120,  -120,  -120,  -120,  -120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -120,  -120,  -120,
    -120,  -120,  -115,  -115,  -115,     0,  -115,  -115,     0,     0,
       0,     0,  -115,  -115,  -115,  -115,  -115,  -115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -115,  -115,
    -115,  -115,  -115,    78,    79,    80,     0,    81,    82,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,   -67,  -121,  -121,  -121,     0,  -121,  -121,
       0,     0,     0,     0,  -121,  -121,  -121,  -121,  -121,  -121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -121,  -121,  -121,  -121,  -121,  -116,  -116,  -116,     0,  -116,
    -116,     0,     0,     0,     0,  -116,  -116,  -116,  -116,  -116,
    -116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -116,  -116,  -116,  -116,  -116,  -122,  -122,  -122,     0,
    -122,  -122,     0,     0,     0,     0,  -122,  -122,  -122,  -122,
    -122,  -122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -122,  -122,  -122,  -122,  -122,  -117,  -117,  -117,
       0,  -117,  -117,     0,     0,     0,     0,  -117,  -117,  -117,
    -117,  -117,  -117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -117,  -117,  -117,  -117,  -117,   -80,   -80,
     -80,     0,   -80,   -80,     0,     0,     0,     0,   -80,   -80,
     -80,   -80,   -80,   -80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -80,   -80,   -80,   -80,   -80,    78,
      79,    80,     0,    81,    82,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,   -70,
     -79,   -79,   -79,     0,   -79,   -79,     0,     0,     0,     0,
     -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -79,   -79,   -79,   -79,
     -79,  -110,  -110,  -110,     0,  -110,  -110,     0,     0,     0,
       0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,  -110,  -107,    79,    80,     0,  -107,  -107,     0,     0,
       0,     0,  -107,  -107,  -107,  -107,  -107,  -107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,  -107,  -111,  -111,  -111,     0,  -111,  -111,     0,
       0,     0,     0,  -111,  -111,  -111,  -111,  -111,  -111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -111,
    -111,  -111,  -111,  -111,  -108,  -108,    80,     0,  -108,  -108,
       0,     0,     0,     0,  -108,  -108,  -108,  -108,  -108,  -108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,  -108,  -112,  -112,  -112,     0,  -112,
    -112,     0,     0,     0,     0,  -112,  -112,  -112,  -112,  -112,
    -112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -112,  -112,  -112,  -112,  -112,  -109,  -109,  -109,     0,
    -109,  -109,     0,     0,     0,     0,  -109,  -109,  -109,  -109,
    -109,  -109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,  -109,   -95,   -95,   -95,
       0,   -95,   -95,     0,     0,     0,     0,   -95,   -95,   -95,
     -95,   -95,   -95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -95,   -95,   -95,   -95,   -95,    78,    79,
      80,     0,   -83,    82,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,   -83,   -96,
     -96,   -96,     0,   -96,   -96,     0,     0,     0,     0,   -96,
     -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -96,   -96,   -96,   -96,   -96,
      78,    79,    80,     0,   -84,   -84,     0,     0,     0,     0,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
     -84,   -97,   -97,   -97,     0,   -97,   -97,     0,     0,     0,
       0,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -97,   -97,   -97,
     -97,   -97,    78,    79,    80,     0,   -85,   -85,     0,     0,
       0,     0,   -85,   -85,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,   -85,   -98,   -98,   -98,     0,   -98,   -98,     0,
       0,     0,     0,   -98,   -98,   -98,   -98,   -98,   -98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,   -98,    78,    79,    80,     0,   -86,   -86,
       0,     0,     0,     0,   -86,   -86,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,   -86,   -99,   -99,   -99,     0,   -99,
     -99,     0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,
     -99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -99,   -99,   -99,   -99,   -99,    78,    79,    80,     0,
     -87,   -87,     0,     0,     0,     0,   -87,   -87,   -87,   -87,
     -87,   -87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,   -87,  -100,  -100,  -100,
       0,  -100,  -100,     0,     0,     0,     0,  -100,  -100,  -100,
    -100,  -100,  -100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -100,  -100,  -100,  -100,  -100,    78,    79,
      80,     0,   -88,   -88,     0,     0,     0,     0,   -88,   -88,
     -88,   -88,   -88,   -88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,    92,   -88,  -101,
    -101,  -101,     0,  -101,  -101,     0,     0,     0,     0,  -101,
    -101,  -101,  -101,  -101,  -101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -101,  -101,  -101,  -101,  -101,
      78,    79,    80,     0,   -89,   -89,     0,     0,     0,     0,
     -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
     -89,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -102,  -102,  -102,
    -102,  -102,    78,    79,    80,     0,   -90,   -90,     0,     0,
       0,     0,   -90,   -90,   -90,   -90,   -90,   -90,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,   -90,  -103,  -103,  -103,     0,  -103,  -103,     0,
       0,     0,     0,  -103,  -103,  -103,  -103,  -103,  -103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -103,
    -103,  -103,  -103,  -103,   -91,   -91,   -91,     0,   -91,   -91,
       0,     0,     0,     0,   -91,   -91,   -91,   -91,   -91,   -91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -91,   -91,    91,    92,   -91,  -104,  -104,  -104,     0,  -104,
    -104,     0,     0,     0,     0,  -104,  -104,  -104,  -104,  -104,
    -104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -104,  -104,  -104,  -104,  -104,   -92,   -92,   -92,     0,
     -92,   -92,     0,     0,     0,     0,   -92,   -92,   -92,   -92,
     -92,   -92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -92,   -92,    91,    92,   -92,  -105,  -105,  -105,
       0,  -105,  -105,     0,     0,     0,     0,  -105,  -105,  -105,
    -105,  -105,  -105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -105,  -105,  -105,  -105,  -105,   -93,   -93,
     -93,     0,   -93,   -93,     0,     0,     0,     0,   -93,   -93,
     -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -93,   -93,   -93,   -93,   -93,  -106,
    -106,  -106,     0,  -106,  -106,     0,     0,     0,     0,  -106,
    -106,  -106,  -106,  -106,  -106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -106,  -106,  -106,  -106,  -106,
     -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,     0,
     -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -94,   -94,   -94,   -94,
     -94,    78,    79,    80,     0,    81,    82,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,   -82,  -132,  -132,  -132,     0,  -132,  -132,     0,     0,
       0,     0,  -132,  -132,  -132,  -132,  -132,  -132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -132,  -132,
    -132,  -132,  -132,  -134,  -134,  -134,     0,  -134,  -134,     0,
       0,     0,     0,  -134,  -134,  -134,  -134,  -134,  -134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -134,
    -134,  -134,  -134,  -134,  -133,  -133,  -133,     0,  -133,  -133,
       0,     0,     0,     0,  -133,  -133,  -133,  -133,  -133,  -133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -133,  -133,  -133,  -133,  -133,  -130,  -130,  -130,     0,  -130,
    -130,     0,     0,     0,     0,  -130,  -130,  -130,  -130,  -130,
    -130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -130,  -130,  -130,  -130,  -130,    78,    79,    80,     0,
      81,    82,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,   436,    78,    79,    80,
       0,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,   466
};

static const yytype_int16 yycheck[] =
{
       0,   263,   263,   536,     6,     0,     0,   287,     0,   434,
      10,    11,    12,    20,     1,    15,    16,    17,    18,     1,
       1,    21,     6,   556,     6,     6,    39,    21,     1,    21,
       3,     4,     0,     6,    47,     0,    47,     1,    49,   464,
      47,    48,     6,    49,    50,    47,     1,   327,     3,     4,
      50,     6,    47,    21,    54,    48,    47,     1,   320,   320,
       1,    48,    62,    47,    64,     6,     7,     8,     9,    10,
      11,   604,    13,    14,    15,     1,    49,     1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    20,    49,   357,   357,    38,    39,    40,
      41,     6,    43,    44,    48,     1,     1,    48,   108,     6,
      51,     1,     1,     1,     1,    47,    20,    49,    47,     0,
      47,    48,    48,    48,    48,     1,    47,     3,     4,    47,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      21,    49,     1,    47,    49,    50,   171,    20,   173,    47,
      47,    49,    48,    48,     6,   155,   156,    20,    48,    48,
      48,    48,    38,    39,    40,    41,    48,    43,    44,   169,
     170,   171,    48,   173,    47,    51,    52,   169,   170,     5,
       6,     5,     6,    48,     5,     6,     0,     6,   213,    48,
     215,   185,   217,   193,    47,   195,     6,    49,    50,    49,
      50,   193,   202,   195,    49,     3,     4,    21,     6,    47,
     210,    49,   212,   213,   214,   215,   216,   217,   210,    20,
     212,    47,   214,    47,   216,   531,   220,   219,    49,    50,
      49,    50,   232,   233,   234,   235,   117,    47,     5,     6,
     232,   233,   234,   235,    49,   551,    47,   247,   248,   249,
     250,   251,   252,     6,     7,     8,     9,    10,    11,    49,
      13,    14,    15,   569,    47,    20,    49,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    49,    50,    49,    47,   286,    49,   169,   170,
      43,    44,    47,   174,    47,    48,    49,    47,    47,    49,
      49,    47,     6,    49,   304,   305,   306,   307,   308,   309,
      49,    50,   193,    49,   195,    49,    50,    49,    50,    49,
      50,    49,    50,    49,    50,    47,   326,     0,    52,   210,
       1,   212,     1,   214,    49,   216,     0,    49,    49,    47,
     340,   341,   342,   343,   344,   345,    49,    48,    21,    51,
      49,   232,   233,   234,   235,   169,   170,    21,    49,    49,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,    49,    48,    47,     1,   193,
     380,   195,    49,    48,    47,     6,     7,     8,     9,    10,
      11,    48,    13,    14,    15,    47,   210,    47,   212,    48,
     214,    48,   216,     1,    20,     3,     4,   432,     6,     7,
       8,     9,    10,    11,    48,    13,    14,    15,   232,   233,
     234,   235,    43,    44,    49,    47,    20,    48,   428,    47,
     430,     0,   432,    48,    47,    47,    20,   462,    49,   439,
      38,    39,    40,    41,    48,    43,    44,    49,    49,    47,
      48,    47,    21,    51,    52,    52,    49,    49,   458,    49,
     460,     1,   462,    49,    49,     1,    49,    49,   468,    49,
       6,     7,     8,     9,    10,    11,    47,    13,    14,    15,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,    52,   169,   170,    49,    49,
      49,    49,    49,    49,    49,   169,   170,    43,    44,    47,
      47,    21,    48,    49,    49,    49,    49,    49,    49,    49,
     193,    49,   195,    49,   220,   120,    -1,    -1,    -1,   193,
      -1,   195,    -1,    -1,    -1,   535,   536,   210,    -1,   212,
      -1,   214,    -1,   216,    -1,    -1,   210,    -1,   212,    -1,
     214,    -1,   216,    -1,    -1,   555,   556,    -1,    -1,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,    -1,   232,   233,
     234,   235,     1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,   616,    -1,   618,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,    -1,   603,   604,    -1,    -1,   632,    -1,   634,
      -1,    -1,    -1,    -1,    43,    44,   616,    -1,   618,    48,
      49,    -1,    -1,    -1,   193,    -1,   195,    -1,    -1,    -1,
     630,   631,   632,    -1,   634,    -1,    -1,    -1,   630,   631,
      -1,   210,    -1,   212,    -1,   214,    -1,   216,   673,    -1,
     675,    -1,   677,    -1,    -1,    -1,    -1,   682,    -1,   684,
     660,   686,   662,   232,   233,   234,   235,    -1,   660,    -1,
     662,    -1,    -1,   673,    -1,   675,    -1,   677,    -1,   679,
      -1,   681,   682,   683,   684,   685,   686,   679,    -1,   681,
      -1,   683,    -1,   685,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,   708,   709,
     710,    -1,    -1,    -1,     1,   707,   708,   709,   710,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
       1,    -1,    -1,   614,   615,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,   630,
     631,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,   647,    38,   649,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,   660,
      51,   662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   670,
      -1,   672,    -1,   674,    -1,   676,    -1,    -1,   679,    -1,
     681,    -1,   683,    -1,   685,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,   630,   631,    -1,    -1,
      -1,    -1,   703,   704,   705,   706,   707,   708,   709,   710,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,   660,    -1,   662,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    48,    49,    50,    -1,   679,    -1,   681,    -1,   683,
       1,   685,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   707,   708,   709,   710,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    47,    48,     1,    -1,
      51,    52,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,    -1,    -1,    -1,    -1,    -1,   630,   631,    42,
      43,    44,    -1,    -1,    -1,    48,   630,   631,    -1,    18,
      -1,    -1,    21,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    51,   660,    -1,   662,
      -1,    -1,    -1,    42,    43,    -1,   660,    -1,   662,    48,
      -1,    50,    -1,    -1,    -1,    54,   679,    -1,   681,    -1,
     683,    -1,   685,    62,    -1,   679,    -1,   681,    -1,   683,
      -1,   685,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   707,   708,   709,   710,    -1,    -1,
      -1,    -1,     1,   707,   708,   709,   710,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,   107,   108,
      -1,   630,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,   124,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
       1,   660,    51,   662,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,   156,    -1,    -1,
     679,    -1,   681,    -1,   683,    -1,   685,    -1,    -1,    -1,
      -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    -1,    -1,   185,    48,   707,   708,
     709,   710,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,   202,    13,    14,    15,    -1,    -1,   208,
      -1,    -1,    -1,    -1,   213,    -1,   215,    -1,   217,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    -1,    -1,    -1,    -1,   286,    -1,    -1,
      -1,    43,    44,    -1,    -1,   294,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,   308,
     309,     1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,   326,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   340,   341,   342,   343,   344,   345,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    49,
      -1,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,    -1,    -1,    -1,    -1,
     379,   380,    -1,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      38,    39,    40,    41,    -1,    43,    44,   426,    -1,   428,
      48,   430,    -1,    51,    52,   434,    -1,    -1,    -1,   438,
     439,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    51,    -1,    -1,   456,    -1,   458,
      -1,   460,    -1,    -1,    -1,   464,     1,    -1,   467,   468,
      18,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    54,    -1,    43,    44,
      -1,     1,    47,    48,    62,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   535,   536,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    43,    44,    -1,   555,   556,    48,     1,
     108,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,   603,   604,    48,    -1,   156,    51,
      52,     6,     7,     8,     9,    10,    11,   616,    13,    14,
      15,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    -1,   632,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    42,    43,    44,
       1,    -1,    -1,    48,   202,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,   213,    -1,   215,    -1,   217,
      -1,    42,    43,    44,   673,    -1,   675,    48,   677,    -1,
      -1,    -1,    -1,   682,    -1,   684,    -1,   686,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    47,    48,    -1,   247,
     248,   249,   250,   251,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,     1,    -1,     3,     4,   286,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,   326,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,   340,   341,   342,   343,   344,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,    -1,     1,    -1,
       3,     4,   380,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
     428,    -1,   430,    38,    -1,    40,    41,    -1,    43,    44,
      -1,   439,    47,    48,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,    -1,   460,    -1,    -1,    -1,    18,    -1,    -1,    -1,
     468,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,    -1,    50,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    43,    44,
      62,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,   535,   536,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,   108,   555,   556,    38,
      -1,    40,    41,    -1,    43,    44,    -1,    -1,    47,    48,
      -1,    -1,    51,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,     1,    51,
      52,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,   156,   603,   604,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,   616,   171,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,   632,    48,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
     202,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,   215,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   673,    -1,   675,    -1,   677,
      -1,    -1,    -1,    -1,   682,    -1,   684,    -1,   686,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
       1,    -1,     3,     4,   286,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   304,   305,   306,   307,   308,   309,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,   326,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,   340,   341,
     342,   343,   344,   345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     1,    -1,     3,     4,   380,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,   428,    -1,   430,    38,
      39,    40,    41,    -1,    43,    44,    -1,   439,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,   460,    -1,
      -1,    -1,    18,    -1,    -1,    -1,   468,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,    -1,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    42,    43,    44,    62,    -1,     1,    48,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,   535,   536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,   108,   555,   556,    48,    -1,    -1,    51,    52,
      43,    44,    -1,    -1,    -1,    48,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
     156,   603,   604,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,   616,   171,    51,    52,    38,    39,
      40,    41,     1,    43,    44,    -1,    -1,    -1,    48,    -1,
     632,    51,    52,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    22,    -1,    -1,   202,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,   213,    -1,   215,
      -1,   217,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,   673,    -1,   675,    -1,   677,    -1,    -1,    -1,    -1,
     682,    -1,   684,    -1,   686,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,   249,   250,   251,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,     1,    -1,     3,     4,
     286,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,   305,
     306,   307,   308,   309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
     326,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,   340,   341,   342,   343,   344,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,    -1,
       1,    -1,     3,     4,   380,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,   428,    -1,   430,    38,    39,    40,    41,    -1,
      43,    44,    -1,   439,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   458,    -1,   460,    -1,    -1,    -1,    18,    -1,
      -1,    -1,   468,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,    -1,
      50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    42,
      43,    44,    62,    -1,     1,    48,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,   108,   555,
     556,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,   156,   603,   604,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
     616,   171,    51,    -1,    -1,    38,    39,    40,    41,     1,
      43,    44,    -1,    -1,     6,    48,   632,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    -1,   202,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,   213,    -1,   215,    -1,   217,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,   673,    -1,   675,
      -1,   677,    -1,    -1,    -1,    -1,   682,    -1,   684,    -1,
     686,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,
     250,   251,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,    -1,    -1,     0,     1,   286,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,   304,   305,   306,   307,   308,   309,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    38,    39,    40,    41,   326,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    -1,
     340,   341,   342,   343,   344,   345,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     1,    -1,     3,     4,
     380,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,   428,    -1,
     430,    38,    39,    40,    41,    -1,    43,    44,    -1,   439,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,
     460,    -1,    -1,    -1,    18,    -1,    -1,    -1,   468,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    43,    44,    62,    -1,
       1,    48,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,   536,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,   108,   555,   556,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,   156,   603,   604,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,   616,   171,    51,    52,
      38,    39,    40,    41,     1,    43,    44,    -1,    -1,    -1,
      48,    -1,   632,    51,    52,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    -1,   202,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,   673,    -1,   675,    -1,   677,    -1,    -1,
      -1,    -1,   682,    -1,   684,    -1,   686,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,     1,    -1,
       3,     4,   286,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,   326,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,   340,   341,   342,   343,
     344,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,     0,     1,    -1,     3,     4,   380,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,   428,    -1,   430,    38,    39,    40,
      41,    -1,    43,    44,    -1,   439,    -1,    48,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   458,    -1,   460,    -1,    -1,    -1,
      18,    -1,    -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,    -1,    50,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   535,   536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
     108,   555,   556,    48,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,   156,   603,
     604,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,   616,   171,    51,    -1,    -1,    38,    39,    40,
      41,     1,    43,    44,    -1,    -1,     6,    48,   632,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,   202,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,   213,    -1,   215,    -1,   217,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,   673,
      -1,   675,    -1,   677,    -1,    -1,    -1,    -1,   682,    -1,
     684,    -1,   686,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,   250,   251,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,     1,    -1,     3,     4,   286,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,   326,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,   340,   341,   342,   343,   344,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,    -1,     1,    -1,
       3,     4,   380,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
     428,    -1,   430,    38,    39,    40,    41,    -1,    43,    44,
      -1,   439,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,    -1,   460,    -1,    -1,    -1,    18,    -1,    -1,    -1,
     468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,    -1,    50,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,   536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,   108,   555,   556,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,   156,   603,   604,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,   616,   171,
      51,    52,    -1,    38,    39,    40,    41,     1,    43,    44,
      -1,    -1,    -1,    48,   632,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
     202,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,   213,    -1,   215,    -1,   217,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,   673,    -1,   675,    -1,   677,
      -1,    -1,    -1,    -1,   682,    -1,   684,    -1,   686,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      -1,    -1,     0,     1,   286,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,   304,   305,   306,   307,   308,   309,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,   326,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    -1,    -1,   340,   341,
     342,   343,   344,   345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,     0,     1,    -1,     3,     4,   380,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,   428,    -1,   430,    38,
      39,    40,    41,    -1,    43,    44,    -1,   439,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,   460,    -1,
      -1,    -1,    18,    -1,    -1,    -1,   468,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,    -1,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   535,   536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,   108,   555,   556,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
     156,   603,   604,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,   616,   171,    51,    52,    -1,    38,
      39,    40,    41,     1,    43,    44,    -1,    -1,    -1,    48,
     632,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,   202,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,   213,    -1,   215,
      -1,   217,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,   673,    -1,   675,    -1,   677,    -1,    -1,    -1,    -1,
     682,    -1,   684,    -1,   686,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,   249,   250,   251,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,    -1,    -1,     0,     1,
     286,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,   304,   305,
     306,   307,   308,   309,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
     326,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,   340,   341,   342,   343,   344,   345,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,    -1,
       1,    -1,     3,     4,   380,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,   428,    -1,   430,    38,    39,    40,    41,    -1,
      43,    44,    -1,   439,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   458,    -1,   460,    -1,    -1,    -1,    18,    -1,
      -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,    -1,
      50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,   108,   555,
     556,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,   156,   603,   604,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
     616,   171,    51,    52,    38,    39,    40,    41,     1,    43,
      44,    -1,    -1,    -1,    48,    -1,   632,    51,    52,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      -1,    -1,   202,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,   213,    -1,   215,    -1,   217,    -1,    -1,
      43,    44,    45,    46,    -1,    48,    49,   673,    -1,   675,
      -1,   677,    -1,    -1,    -1,    -1,   682,    -1,   684,    -1,
     686,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,
     250,   251,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,     1,    -1,     3,     4,   286,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304,   305,   306,   307,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,   326,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
     340,   341,   342,   343,   344,   345,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,     0,     1,    -1,     3,     4,
     380,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,   428,    -1,
     430,    38,    39,    40,    41,    -1,    43,    44,    -1,   439,
      -1,    48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,
     460,    -1,    -1,    -1,    18,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,    -1,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,   536,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,   108,   555,   556,    48,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,   156,   603,   604,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,   616,   171,    51,    -1,
      -1,    38,    39,    40,    41,     1,    43,    44,    -1,    -1,
      -1,    48,   632,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    -1,   202,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,   673,    -1,   675,    -1,   677,    -1,    -1,
      -1,    -1,   682,    -1,   684,    -1,   686,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    -1,    -1,
       0,     1,   286,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,   326,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    -1,    -1,   340,   341,   342,   343,
     344,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,    -1,     1,    -1,     3,     4,   380,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,   428,    -1,   430,    38,    39,    40,
      41,    -1,    43,    44,    -1,   439,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   458,    -1,   460,    -1,    -1,     0,
       1,    -1,     3,     4,   468,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   535,   536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,   555,   556,    48,    -1,     1,    51,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,   603,
     604,    -1,    48,    -1,    -1,    51,    52,    -1,    38,    39,
      40,    41,   616,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    -1,    -1,     1,    -1,    -1,   632,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    38,    39,    40,    41,    -1,    43,    44,   673,
      -1,   675,    48,   677,    -1,    51,    -1,    -1,   682,    -1,
     684,    -1,   686,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
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
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
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
      -1,    -1,     1,    48,    -1,    -1,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    38,    -1,    40,    41,    -1,    43,
      44,    -1,    -1,     1,    48,    -1,    -1,    51,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      38,    -1,    40,    41,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    -1,    48,    49,    50,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,     1,    48,
      49,    -1,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,     1,    -1,    47,    48,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
       1,    -1,    -1,    48,    -1,     6,     7,     8,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,     1,    -1,    -1,    48,
      -1,     6,     7,     8,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,     1,    -1,    -1,    48,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,     1,    -1,
      -1,    48,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,     1,    -1,    -1,    48,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
       1,    -1,    -1,    48,    -1,     6,     7,     8,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,     1,    -1,    -1,    48,
      -1,     6,     7,     8,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,     1,    -1,    -1,    48,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,     1,    -1,
      -1,    48,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,     1,    -1,    -1,    48,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
       1,    -1,    -1,    48,    -1,     6,     7,     8,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,     1,    -1,    -1,    48,
      -1,     6,     7,     8,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,     1,    -1,    -1,    48,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,     1,    -1,
      -1,    48,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,     1,    -1,    -1,    48,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
       1,    -1,    -1,    48,    -1,     6,     7,     8,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,     1,    -1,    -1,    48,
      -1,     6,     7,     8,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,     1,    -1,    -1,    48,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,     1,    -1,
      -1,    48,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,     1,    -1,    -1,    48,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
       1,    -1,    -1,    48,    -1,     6,     7,     8,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,     1,    -1,    -1,    48,
      -1,     6,     7,     8,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,     1,    -1,    -1,    48,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,     1,    -1,
      -1,    48,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
       1,    13,    14,    15,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    43,    44,     1,    -1,    -1,    48,    -1,     6,
       7,     8,     9,    10,    11,     1,    13,    14,    15,    -1,
       6,     7,     8,     9,    10,    11,     1,    13,    14,    15,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,    44,
       1,    -1,    -1,    48,    -1,     6,     7,     8,     9,    10,
      11,     1,    13,    14,    15,    -1,     6,     7,     8,     9,
      10,    11,     1,    13,    14,    15,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    43,    44,     1,    -1,    -1,    48,
      -1,     6,     7,     8,     9,    10,    11,     1,    13,    14,
      15,    -1,     6,     7,     8,     9,    10,    11,     1,    13,
      14,    15,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      43,    44,     1,    -1,    -1,    48,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,     1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    -1,    43,    44,    17,    18,
      19,    48,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    17,    18,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    17,    18,    19,
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
      -1,    -1,    -1,    43,    44,    45,    46,    47
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
      48,     1,     7,     8,    48,    75,    91,     1,    75,     1,
      75,     1,    48,     1,    48,     1,    75,     1,    75,     1,
      75,     1,    75,    64,     0,     1,    56,    47,    17,    18,
      19,    21,    22,    27,    28,    29,    30,    31,    32,    43,
      44,    45,    46,    47,     1,    77,    86,    91,    47,    91,
      47,     1,    91,    47,     1,    42,    75,    48,    48,     1,
      75,     1,    74,    75,    49,    49,     1,    39,    57,    65,
      66,    67,    68,    71,    92,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,    20,    48,    20,    47,    20,
      47,    48,    49,    88,    49,    49,    49,    42,    75,    49,
      49,    47,    49,    47,    39,    68,    52,    67,    91,    75,
      75,    89,    90,     1,     1,    59,    47,    49,    47,     1,
       1,    49,    49,    39,    68,    39,    68,    74,     1,    74,
      68,    49,    50,     1,    60,    61,    62,    91,    92,    68,
      39,    68,    39,    47,    49,    47,    49,    47,    75,    49,
      50,    91,    68,    68,    74,    68,    74,    68,     1,    74,
      63,    62,    49,    49,    49,    49,    68,    68,    68,    68,
       6,     6,     7,     8,     9,    10,    11,    13,    14,    15,
      43,    44,    48,    76,    78,    79,    80,    81,    82,    83,
      84,    85,    87,    91,     6,     6,     6,    17,    18,    19,
      21,    22,    27,    28,    29,    30,    31,    32,    43,    44,
      45,    46,     7,     8,    38,    40,    48,    51,    63,    69,
      70,    72,    73,    75,    91,    47,     1,    47,     6,     7,
       8,     9,    10,    11,    13,    14,    15,    43,    44,    48,
      76,    78,    79,    80,    81,    82,    83,    84,    85,    87,
      91,     1,     7,     8,    38,    40,    48,    51,    63,    69,
      70,    72,    73,    75,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    43,    44,    48,    75,    76,    78,    79,
      80,    81,    82,    83,    84,    85,    87,    91,    20,    47,
      17,    18,    19,    21,    22,    27,    28,    29,    30,    31,
      32,    43,    44,    45,    46,     3,     4,     6,    75,    48,
      48,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,    75,     1,    77,    86,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    48,     1,    48,     1,
      48,     1,    48,     1,    64,    47,    47,    91,    48,    48,
       1,    75,     1,    75,     1,    75,     1,    75,     1,    75,
      75,     1,    77,    86,    47,     1,    48,     1,    48,     1,
      48,     1,    48,     1,    64,    47,    47,    48,    48,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,    75,
      17,    18,    19,    21,    22,    27,    28,    29,    30,    31,
      32,    43,    44,    45,    46,     1,    77,    86,     1,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     5,
       5,    91,    42,    75,    49,    20,    48,    47,     1,    47,
       1,    42,    75,     1,    75,     1,    74,    49,    65,    20,
      47,    91,    42,    75,    49,    20,    48,    47,     1,    47,
       1,    42,    75,     1,    75,     1,    74,    49,    65,    91,
      42,    75,    49,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,     1,    75,     1,    75,     1,    75,     1,
      75,     1,    75,    20,    48,    88,    49,    49,    75,    89,
      49,    49,    49,    49,    49,    49,    47,    49,    47,    52,
       1,    88,    49,    49,    75,    89,    49,    49,    49,    49,
      49,    49,    47,    49,    47,    52,    88,    49,    49,    75,
      89,    49,    49,    47,    47,     1,     1,    39,    68,    39,
      68,    74,     1,    74,    49,    49,    47,    47,     1,     1,
      39,    68,    39,    68,    74,     1,    74,    49,    49,    68,
      39,    68,    39,    47,    49,    47,    49,    47,    68,    39,
      68,    39,    47,    49,    47,    49,    47,    68,    68,    74,
      68,    74,    68,     1,    74,    68,    68,    74,    68,    74,
      68,     1,    74,    49,    49,    49,    49,    49,    49,    49,
      49,    68,    68,    68,    68,    68,    68,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    59,    58,    60,    60,    61,
      61,    61,    62,    62,    62,    64,    63,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    77,    76,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    83,    84,    86,
      85,    88,    87,    87,    87,    89,    89,    90,    90,    91,
      92,    92,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     0,     7,     0,     1,     3,
       1,     1,     2,     1,     1,     0,     4,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     4,
       5,     5,     5,     4,     5,     3,     3,     1,     1,     2,
       5,     7,     5,     7,     6,     6,     2,     2,     3,     9,
       9,     9,     9,     7,     7,     4,     2,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     0,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     0,
       5,     0,     5,     4,     4,     0,     1,     3,     1,     1,
       1,     1,     2,     2
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
#line 119 "./src/bison.y"
           {
    free(((*yyvaluep).string));
}
#line 5251 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 119 "./src/bison.y"
           {
    free(((*yyvaluep).string));
}
#line 5259 "bison.tab.c"
        break;

    case YYSYMBOL_LIST_TOKEN: /* LIST_TOKEN  */
#line 119 "./src/bison.y"
           {
    free(((*yyvaluep).string));
}
#line 5267 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5275 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5283 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5291 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5299 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5307 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5315 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5323 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5331 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5339 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5347 "bison.tab.c"
        break;

    case YYSYMBOL_59_1: /* @1  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5355 "bison.tab.c"
        break;

    case YYSYMBOL_optListParams: /* optListParams  */
#line 115 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5363 "bison.tab.c"
        break;

    case YYSYMBOL_listParams: /* listParams  */
#line 115 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5371 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5379 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5387 "bison.tab.c"
        break;

    case YYSYMBOL_optListCodeBlock: /* optListCodeBlock  */
#line 115 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5395 "bison.tab.c"
        break;

    case YYSYMBOL_listCodeBlock: /* listCodeBlock  */
#line 115 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5403 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5411 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5419 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5427 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5435 "bison.tab.c"
        break;

    case YYSYMBOL_elseError: /* elseError  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5443 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5451 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5459 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5467 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5475 "bison.tab.c"
        break;

    case YYSYMBOL_assignArith: /* assignArith  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5483 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5491 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5499 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5507 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5515 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5523 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5531 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5539 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5547 "bison.tab.c"
        break;

    case YYSYMBOL_ioCommand: /* ioCommand  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5555 "bison.tab.c"
        break;

    case YYSYMBOL_optListExpression: /* optListExpression  */
#line 115 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5563 "bison.tab.c"
        break;

    case YYSYMBOL_listExpression: /* listExpression  */
#line 115 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 5571 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5579 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 111 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 5587 "bison.tab.c"
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
#line 145 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected error || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 5885 "bison.tab.c"
    break;

  case 4: /* startProgram: %empty  */
#line 149 "./src/bison.y"
             {
        SHOW_SYNTAX_ERROR("empty translation unit\n");
    }
#line 5893 "bison.tab.c"
    break;

  case 5: /* declarationList: declarationList declaration  */
#line 155 "./src/bison.y"
                                {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 5901 "bison.tab.c"
    break;

  case 6: /* declarationList: declaration  */
#line 158 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 5909 "bison.tab.c"
    break;

  case 7: /* declaration: variableDeclare  */
#line 164 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5917 "bison.tab.c"
    break;

  case 8: /* declaration: functionDeclare  */
#line 167 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5925 "bison.tab.c"
    break;

  case 9: /* declaration: statement  */
#line 172 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("an statement is not permitted at this top level || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5935 "bison.tab.c"
    break;

  case 10: /* variableDeclare: type id ';'  */
#line 180 "./src/bison.y"
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
            (yyval.astnode) = create_astnode_context(AST_VAR_DECLARE, "variable declare", (yylsp[-2]));
            insert_kid((yyvsp[-2].astnode), (yyval.astnode));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
        }
    }
#line 5956 "bison.tab.c"
    break;

  case 11: /* variableDeclare: type ';'  */
#line 198 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("useless type name in empty declaration || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5966 "bison.tab.c"
    break;

  case 12: /* variableDeclare: type id ASSIGN_TOKEN error  */
#line 204 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 5977 "bison.tab.c"
    break;

  case 13: /* variableDeclare: id id ASSIGN_TOKEN error  */
#line 211 "./src/bison.y"
                               {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 5988 "bison.tab.c"
    break;

  case 14: /* variableDeclare: id id ';'  */
#line 218 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5999 "bison.tab.c"
    break;

  case 15: /* @1: %empty  */
#line 227 "./src/bison.y"
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
#line 6027 "bison.tab.c"
    break;

  case 16: /* functionDeclare: type id '(' @1 optListParams ')' compoundStatement  */
#line 249 "./src/bison.y"
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
    }
#line 6054 "bison.tab.c"
    break;

  case 17: /* optListParams: %empty  */
#line 274 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 6062 "bison.tab.c"
    break;

  case 19: /* listParams: listParams ',' param  */
#line 281 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 6071 "bison.tab.c"
    break;

  case 20: /* listParams: param  */
#line 285 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 6080 "bison.tab.c"
    break;

  case 21: /* listParams: error  */
#line 291 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected params || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.list) = NULL;
    }
#line 6089 "bison.tab.c"
    break;

  case 22: /* param: type id  */
#line 298 "./src/bison.y"
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
            (yyval.astnode) = create_astnode_context(AST_PARAM, "param", (yyloc));
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
        }
    }
#line 6109 "bison.tab.c"
    break;

  case 23: /* param: type  */
#line 315 "./src/bison.y"
           {
        SHOW_SYNTAX_ERROR("after '%s' expected identifier || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6119 "bison.tab.c"
    break;

  case 24: /* param: id  */
#line 321 "./src/bison.y"
         {
        SHOW_SYNTAX_ERROR("expected type to '%s' || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6129 "bison.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 329 "./src/bison.y"
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
#line 6149 "bison.tab.c"
    break;

  case 26: /* compoundStatement: '{' $@2 optListCodeBlock '}'  */
#line 343 "./src/bison.y"
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
#line 6172 "bison.tab.c"
    break;

  case 27: /* optListCodeBlock: %empty  */
#line 364 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 6180 "bison.tab.c"
    break;

  case 29: /* listCodeBlock: listCodeBlock codeBlock  */
#line 371 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 6189 "bison.tab.c"
    break;

  case 30: /* listCodeBlock: codeBlock  */
#line 375 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 6198 "bison.tab.c"
    break;

  case 31: /* codeBlock: statement  */
#line 382 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6207 "bison.tab.c"
    break;

  case 32: /* codeBlock: variableDeclare  */
#line 386 "./src/bison.y"
                      {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6216 "bison.tab.c"
    break;

  case 34: /* statement: flowExpression  */
#line 394 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6225 "bison.tab.c"
    break;

  case 35: /* statement: compoundStatement  */
#line 398 "./src/bison.y"
                        {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6234 "bison.tab.c"
    break;

  case 36: /* statement: expression ';'  */
#line 402 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "", (yyloc));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 6243 "bison.tab.c"
    break;

  case 37: /* statement: error ';'  */
#line 408 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6252 "bison.tab.c"
    break;

  case 38: /* statement: '(' error ')'  */
#line 413 "./src/bison.y"
                    {
        SHOW_SYNTAX_ERROR("expected expression before ')' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6261 "bison.tab.c"
    break;

  case 39: /* statement: WRITE_TOKEN '(' error ')'  */
#line 418 "./src/bison.y"
                                {
       SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
       delete_astnode((yyvsp[-3].astnode));
       (yyval.astnode) = NULL;
    }
#line 6271 "bison.tab.c"
    break;

  case 40: /* statement: WRITE_TOKEN '(' error ')' ';'  */
#line 424 "./src/bison.y"
                                    {
       SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
       delete_astnode((yyvsp[-4].astnode));
       (yyval.astnode) = NULL;
    }
#line 6281 "bison.tab.c"
    break;

  case 41: /* statement: WRITE_TOKEN '(' expression ')' error  */
#line 429 "./src/bison.y"
                                           {
       SHOW_SYNTAX_ERROR("expected ';' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
       delete_astnode((yyvsp[-4].astnode));
       delete_astnode((yyvsp[-2].astnode));
       (yyval.astnode) = NULL;
    }
#line 6292 "bison.tab.c"
    break;

  case 42: /* statement: WRITE_TOKEN '(' STRING_TOKEN ')' error  */
#line 436 "./src/bison.y"
                                             {
       SHOW_SYNTAX_ERROR("expected ';' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
       delete_astnode((yyvsp[-4].astnode));
       delete_astnode((yyvsp[-2].astnode));
       (yyval.astnode) = NULL;
    }
#line 6303 "bison.tab.c"
    break;

  case 43: /* statement: READ_TOKEN '(' error ')'  */
#line 444 "./src/bison.y"
                               {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        (yyval.astnode) = NULL;
    }
#line 6313 "bison.tab.c"
    break;

  case 44: /* statement: READ_TOKEN '(' error ')' ';'  */
#line 449 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        (yyval.astnode) = NULL;
    }
#line 6323 "bison.tab.c"
    break;

  case 45: /* statement: READ_TOKEN error ';'  */
#line 454 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected '(' token after 'read' || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6333 "bison.tab.c"
    break;

  case 46: /* statement: WRITE_TOKEN error ';'  */
#line 459 "./src/bison.y"
                            {
        SHOW_SYNTAX_ERROR("expected '(' token after 'write' || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6343 "bison.tab.c"
    break;

  case 47: /* flowExpression: condExpression  */
#line 467 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6351 "bison.tab.c"
    break;

  case 48: /* flowExpression: interationExpression  */
#line 470 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6359 "bison.tab.c"
    break;

  case 49: /* flowExpression: returnExpression ';'  */
#line 473 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 6367 "bison.tab.c"
    break;

  case 50: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 479 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6377 "bison.tab.c"
    break;

  case 51: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 484 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6388 "bison.tab.c"
    break;

  case 52: /* condExpression: IF_TOKEN '(' error ')' statement  */
#line 492 "./src/bison.y"
                                                      {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6398 "bison.tab.c"
    break;

  case 53: /* condExpression: IF_TOKEN '(' error ')' statement ELSE_TOKEN statement  */
#line 498 "./src/bison.y"
                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6409 "bison.tab.c"
    break;

  case 54: /* condExpression: IF_TOKEN '(' expression ')' ELSE_TOKEN statement  */
#line 505 "./src/bison.y"
                                                       {
        SHOW_SYNTAX_ERROR("expected expression before 'else' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6420 "bison.tab.c"
    break;

  case 55: /* condExpression: IF_TOKEN '(' error ')' ELSE_TOKEN statement  */
#line 512 "./src/bison.y"
                                                  {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6430 "bison.tab.c"
    break;

  case 56: /* condExpression: IF_TOKEN error  */
#line 518 "./src/bison.y"
                     {
        SHOW_SYNTAX_ERROR("expected '(' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6439 "bison.tab.c"
    break;

  case 57: /* elseError: ELSE_TOKEN statement  */
#line 527 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6449 "bison.tab.c"
    break;

  case 58: /* elseError: error ELSE_TOKEN statement  */
#line 533 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6459 "bison.tab.c"
    break;

  case 59: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 541 "./src/bison.y"
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
#line 6474 "bison.tab.c"
    break;

  case 60: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ';' optExpression ')' statement  */
#line 553 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6486 "bison.tab.c"
    break;

  case 61: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ';' optExpression ')' statement  */
#line 561 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6498 "bison.tab.c"
    break;

  case 62: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' error ')' statement  */
#line 569 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6510 "bison.tab.c"
    break;

  case 63: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ')' statement  */
#line 577 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6521 "bison.tab.c"
    break;

  case 64: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ')' statement  */
#line 584 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 6532 "bison.tab.c"
    break;

  case 65: /* interationExpression: FOR_TOKEN '(' error ')'  */
#line 591 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6541 "bison.tab.c"
    break;

  case 66: /* interationExpression: FOR_TOKEN error  */
#line 596 "./src/bison.y"
                      {
        SHOW_SYNTAX_ERROR("expected '(' token after 'for' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6550 "bison.tab.c"
    break;

  case 67: /* returnExpression: RETURN_TOKEN expression  */
#line 603 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return expression", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6559 "bison.tab.c"
    break;

  case 68: /* returnExpression: RETURN_TOKEN error  */
#line 609 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'return' with no value, in function returning non-void || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.astnode) = NULL;
    }
#line 6568 "bison.tab.c"
    break;

  case 69: /* optExpression: %empty  */
#line 616 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 6576 "bison.tab.c"
    break;

  case 70: /* optExpression: expression  */
#line 619 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 6584 "bison.tab.c"
    break;

  case 71: /* expression: assignArith  */
#line 625 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "expression assign", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6593 "bison.tab.c"
    break;

  case 72: /* expression: binArith  */
#line 629 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "expression bin", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6602 "bison.tab.c"
    break;

  case 73: /* expression: listArith  */
#line 633 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "expression list", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6611 "bison.tab.c"
    break;

  case 74: /* expression: unaArith  */
#line 637 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "expression unarith", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6620 "bison.tab.c"
    break;

  case 75: /* expression: constant  */
#line 641 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "expression constant", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6629 "bison.tab.c"
    break;

  case 76: /* expression: funcCall  */
#line 645 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "ex funccall", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6638 "bison.tab.c"
    break;

  case 77: /* expression: ioCommand  */
#line 649 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "ex comandio", (yyloc));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6647 "bison.tab.c"
    break;

  case 78: /* expression: id  */
#line 653 "./src/bison.y"
         {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        } else {
            (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "id exp", (yyloc));
            insert_kid((yyvsp[0].astnode), (yyval.astnode));
        }
    }
#line 6662 "bison.tab.c"
    break;

  case 79: /* expression: '(' expression ')'  */
#line 663 "./src/bison.y"
                         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "(exp)", (yyloc));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 6671 "bison.tab.c"
    break;

  case 80: /* expression: id error  */
#line 669 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 6681 "bison.tab.c"
    break;

  case 81: /* $@3: %empty  */
#line 677 "./src/bison.y"
       {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        }
    }
#line 6693 "bison.tab.c"
    break;

  case 82: /* assignArith: id $@3 ASSIGN_TOKEN expression  */
#line 683 "./src/bison.y"
                              {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign", (yyloc));
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6703 "bison.tab.c"
    break;

  case 83: /* binArith: expression OR_TOKEN expression  */
#line 691 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6713 "bison.tab.c"
    break;

  case 84: /* binArith: expression AND_TOKEN expression  */
#line 696 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6723 "bison.tab.c"
    break;

  case 85: /* binArith: expression EQUAL_TOKEN expression  */
#line 701 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6733 "bison.tab.c"
    break;

  case 86: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 706 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6743 "bison.tab.c"
    break;

  case 87: /* binArith: expression LESS_TOKEN expression  */
#line 711 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6753 "bison.tab.c"
    break;

  case 88: /* binArith: expression LE_EQ_TOKEN expression  */
#line 716 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6763 "bison.tab.c"
    break;

  case 89: /* binArith: expression GREAT_TOKEN expression  */
#line 721 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6773 "bison.tab.c"
    break;

  case 90: /* binArith: expression GR_EQ_TOKEN expression  */
#line 726 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6783 "bison.tab.c"
    break;

  case 91: /* binArith: expression '+' expression  */
#line 731 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6793 "bison.tab.c"
    break;

  case 92: /* binArith: expression '-' expression  */
#line 736 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6803 "bison.tab.c"
    break;

  case 93: /* binArith: expression '*' expression  */
#line 741 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6813 "bison.tab.c"
    break;

  case 94: /* binArith: expression '/' expression  */
#line 746 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6823 "bison.tab.c"
    break;

  case 95: /* binArith: expression OR_TOKEN error  */
#line 752 "./src/bison.y"
                                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6833 "bison.tab.c"
    break;

  case 96: /* binArith: expression AND_TOKEN error  */
#line 757 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6843 "bison.tab.c"
    break;

  case 97: /* binArith: expression EQUAL_TOKEN error  */
#line 762 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6853 "bison.tab.c"
    break;

  case 98: /* binArith: expression DIFF_EQ_TOKEN error  */
#line 767 "./src/bison.y"
                                     {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6863 "bison.tab.c"
    break;

  case 99: /* binArith: expression LESS_TOKEN error  */
#line 772 "./src/bison.y"
                                  {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6873 "bison.tab.c"
    break;

  case 100: /* binArith: expression LE_EQ_TOKEN error  */
#line 777 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6883 "bison.tab.c"
    break;

  case 101: /* binArith: expression GREAT_TOKEN error  */
#line 782 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6893 "bison.tab.c"
    break;

  case 102: /* binArith: expression GR_EQ_TOKEN error  */
#line 787 "./src/bison.y"
                                   {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6903 "bison.tab.c"
    break;

  case 103: /* binArith: expression '+' error  */
#line 792 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6913 "bison.tab.c"
    break;

  case 104: /* binArith: expression '-' error  */
#line 797 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6923 "bison.tab.c"
    break;

  case 105: /* binArith: expression '*' error  */
#line 802 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6933 "bison.tab.c"
    break;

  case 106: /* binArith: expression '/' error  */
#line 807 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6943 "bison.tab.c"
    break;

  case 107: /* listArith: expression MAP_TOKEN expression  */
#line 815 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6953 "bison.tab.c"
    break;

  case 108: /* listArith: expression FILTER_TOKEN expression  */
#line 820 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6963 "bison.tab.c"
    break;

  case 109: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 825 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}", (yyloc));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 6973 "bison.tab.c"
    break;

  case 110: /* listArith: expression MAP_TOKEN error  */
#line 831 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6983 "bison.tab.c"
    break;

  case 111: /* listArith: expression FILTER_TOKEN error  */
#line 836 "./src/bison.y"
                                    {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 6993 "bison.tab.c"
    break;

  case 112: /* listArith: expression CONSTRUCTOR_LIST_TOKEN error  */
#line 841 "./src/bison.y"
                                              {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 7003 "bison.tab.c"
    break;

  case 113: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 849 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}", (yyloc));
        (yyval.astnode)->context->operation = "!";
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7013 "bison.tab.c"
    break;

  case 114: /* unaArith: QUESTION_TOKEN expression  */
#line 854 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}", (yyloc));
        (yyval.astnode)->context->operation = "?";
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7023 "bison.tab.c"
    break;

  case 115: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 859 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}", (yyloc));
        (yyval.astnode)->context->operation = "%";
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7033 "bison.tab.c"
    break;

  case 116: /* unaArith: '+' expression  */
#line 864 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}", (yyloc));
        (yyval.astnode)->context->operation = "+";
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7043 "bison.tab.c"
    break;

  case 117: /* unaArith: '-' expression  */
#line 869 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}", (yyloc));
        (yyval.astnode)->context->operation = "-";
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7053 "bison.tab.c"
    break;

  case 118: /* unaArith: EXCLAMATION_TOKEN error  */
#line 875 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 7062 "bison.tab.c"
    break;

  case 119: /* unaArith: QUESTION_TOKEN error  */
#line 879 "./src/bison.y"
                           {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 7071 "bison.tab.c"
    break;

  case 120: /* unaArith: PERCENTAGE_TOKEN error  */
#line 883 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 7080 "bison.tab.c"
    break;

  case 121: /* unaArith: '+' error  */
#line 887 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 7089 "bison.tab.c"
    break;

  case 122: /* unaArith: '-' error  */
#line 891 "./src/bison.y"
                             {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 7098 "bison.tab.c"
    break;

  case 123: /* constant: constantInteger  */
#line 898 "./src/bison.y"
                    {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant int", (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_INT;
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7108 "bison.tab.c"
    break;

  case 124: /* constant: constantReal  */
#line 903 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant real", (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_FLOAT;
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7118 "bison.tab.c"
    break;

  case 125: /* constant: constantNIL  */
#line 908 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant nil", (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_LIST;
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 7128 "bison.tab.c"
    break;

  case 126: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 916 "./src/bison.y"
                           {
        (yyvsp[0].astnode)->context->dtype = DTYPE_INT;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 7137 "bison.tab.c"
    break;

  case 127: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 923 "./src/bison.y"
                        {
        (yyvsp[0].astnode)->context->dtype = DTYPE_FLOAT;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 7146 "bison.tab.c"
    break;

  case 128: /* constantNIL: NIL_TOKEN  */
#line 930 "./src/bison.y"
              {
        (yyvsp[0].astnode)->context->dtype = DTYPE_LIST;
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 7155 "bison.tab.c"
    break;

  case 129: /* $@4: %empty  */
#line 937 "./src/bison.y"
       {
       Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        } 
    }
#line 7167 "bison.tab.c"
    break;

  case 130: /* funcCall: id $@4 '(' optListExpression ')'  */
#line 943 "./src/bison.y"
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
#line 7186 "bison.tab.c"
    break;

  case 131: /* $@5: %empty  */
#line 960 "./src/bison.y"
                      {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        }
    }
#line 7198 "bison.tab.c"
    break;

  case 132: /* ioCommand: READ_TOKEN '(' id $@5 ')'  */
#line 966 "./src/bison.y"
          {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "read call", (yyloc));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
    }
#line 7208 "bison.tab.c"
    break;

  case 133: /* ioCommand: WRITE_TOKEN '(' expression ')'  */
#line 971 "./src/bison.y"
                                     {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "write call", (yyloc));
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 7218 "bison.tab.c"
    break;

  case 134: /* ioCommand: WRITE_TOKEN '(' STRING_TOKEN ')'  */
#line 976 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_BUILT_IN, "write call", (yyloc));
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 7228 "bison.tab.c"
    break;

  case 135: /* optListExpression: %empty  */
#line 984 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 7236 "bison.tab.c"
    break;

  case 137: /* listExpression: listExpression ',' expression  */
#line 991 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 7245 "bison.tab.c"
    break;

  case 138: /* listExpression: expression  */
#line 995 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 7254 "bison.tab.c"
    break;

  case 139: /* id: ID_TOKEN  */
#line 1002 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 7262 "bison.tab.c"
    break;

  case 140: /* type: INT_TOKEN  */
#line 1008 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT, (yyvsp[0].string), (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_INT;
        free((yyvsp[0].string));
    }
#line 7272 "bison.tab.c"
    break;

  case 141: /* type: FLOAT_TOKEN  */
#line 1013 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT, (yyvsp[0].string), (yyloc));
        (yyval.astnode)->context->dtype = DTYPE_FLOAT;
        free((yyvsp[0].string));
    }
#line 7282 "bison.tab.c"
    break;

  case 142: /* type: INT_TOKEN LIST_TOKEN  */
#line 1018 "./src/bison.y"
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
#line 7298 "bison.tab.c"
    break;

  case 143: /* type: FLOAT_TOKEN LIST_TOKEN  */
#line 1029 "./src/bison.y"
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
#line 7314 "bison.tab.c"
    break;


#line 7318 "bison.tab.c"

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

#line 1042 "./src/bison.y"


void yyerror(const char *error_msg){
    // if (error_msg) {
    //     printf(RED"Line: %d || Column: %d || "RESET, num_line, num_col);
    //     printf(RED"Error: %s || Error count: %d \n"RESET, error_msg, error);
    // }

    if(!error_msg)
        error++;
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
        printf("##################### %s #####################\n", "Abstract Syntax Tree");
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

    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_list(list_context, delete_list_treenode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
