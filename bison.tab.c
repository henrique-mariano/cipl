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

    #define SEMANTIC_ERROR(__STR_ERR_SEM__, ...) \
            printf(RED"Semantic error: "RESET __STR_ERR_SEM__, ##__VA_ARGS__);
    #define SHOW_SYNTAX_ERROR(__STR_ERR_SYN__, ...) \
            printf(RED"Syntax error: "RESET __STR_ERR_SYN__, ##__VA_ARGS__);

    #define SHOW_SHOW_SYNTAX_ERROR(__STR_ERR__, ...) { \
        yyerror(NULL); \
        SHOW_SYNTAX_ERROR(__STR_ERR__, ##__VA_ARGS__); \
    }

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

#line 127 "bison.tab.c"

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
  YYSYMBOL_76_3 = 76,                      /* $@3  */
  YYSYMBOL_binArith = 77,                  /* binArith  */
  YYSYMBOL_listArith = 78,                 /* listArith  */
  YYSYMBOL_unaArith = 79,                  /* unaArith  */
  YYSYMBOL_constant = 80,                  /* constant  */
  YYSYMBOL_constantInteger = 81,           /* constantInteger  */
  YYSYMBOL_constantReal = 82,              /* constantReal  */
  YYSYMBOL_constantNIL = 83,               /* constantNIL  */
  YYSYMBOL_constantString = 84,            /* constantString  */
  YYSYMBOL_funcCall = 85,                  /* funcCall  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_87_5 = 87,                      /* $@5  */
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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   12622

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  570

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
       0,   155,   155,   159,   163,   169,   172,   178,   181,   186,
     194,   212,   218,   225,   232,   241,   241,   288,   291,   295,
     299,   305,   312,   329,   335,   343,   343,   378,   381,   385,
     389,   396,   400,   404,   408,   412,   416,   422,   429,   432,
     435,   441,   446,   454,   460,   467,   474,   480,   489,   495,
     503,   515,   523,   531,   539,   546,   553,   558,   565,   571,
     578,   581,   587,   587,   598,   602,   606,   610,   614,   618,
     628,   634,   639,   646,   651,   656,   661,   666,   671,   676,
     681,   686,   691,   696,   701,   709,   714,   719,   727,   731,
     735,   739,   743,   750,   754,   758,   762,   769,   775,   781,
     787,   793,   793,   813,   813,   824,   841,   844,   848,   852,
     859,   865,   868,   871,   879
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
  "expression", "$@3", "binArith", "listArith", "unaArith", "constant",
  "constantInteger", "constantReal", "constantNIL", "constantString",
  "funcCall", "$@4", "$@5", "optListExpression", "listExpression", "id",
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

#define YYPACT_NINF (-258)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     765,     4,   102,   104,  2472,   -18,    53, 11211, 11242, 11273,
    6788,  6788,  6788,     5,     7,   541, 11304,  6788,  6788,   699,
     745,    26,  5465,  5511,  5527,  5573,  5589,  5635,  5651,  5697,
    5713,    64, 11335, 11366, 11397, 11428, 11459, 11490, 11521, 11552,
   11583, 11614,  2783,    -1,  5759,    39,   110,    41,  1746, 11645,
    3094, 11676, 11707,  5775,  3957,  5821,  2183,    68, 11738, 11769,
   11800,    69,  9627,   829,  -258,    83,  5837,  5883,  6788,  6788,
    6788,  6788,  6788,  6788,  6788,  6788,  6788,  6788,  6788,  6788,
    6788,  6788,  6788,  5899, 11831,   144,   105,    80,  5945,   118,
     120,  6879,   127,   -36,   158,  9660,   -22,   186, 11862, 11893,
   11924,   -15,  1510,   892,   188,  1178,  1321,  1491,  1634,   111,
   11955, 11986, 12017, 12048, 12079, 12110, 12141, 12172, 12203, 12234,
   12265, 12296, 12327, 12358, 12389,  6788,  1746,   223,  5961,   240,
    6007,    34,   193, 12420,  6831,    51,   349,  1435,  6023,  2402,
    1510,  1802,  6069,  1945,    93, 12451,   194,  6085,  6131,    38,
   12482,  6913,  1821,  2114,  1821,  2256,    75,   133,   197,  2424,
   12513,   -16,   196,   147,   153,   173,    82,  6147,  1821,  6193,
    1821,  2057,  1821,  2057,  1821,  1020,   195,   117,   177,  6209,
    6255,   213,  6271,   214,  6317,   216,   217,  6333,   179,  1821,
    1821,  1821,  1821,  6379,  6395,  6441,  6457,  3405,  6622,   219,
     220,  9693,  9726,  9759,  6841,  6841,  6841,  9792,  6841,  6841,
    6701,  9825,  9858,  9891,  9924,  9957,  9990, 10023, 10056, 10089,
    6655,    99,   139,   221,  6554,   239,   241,  6947,  6981,  7015,
    6831,  6831,  6831,  7049,  6831,  6831,  6712,  7083,  7117,  7151,
    7185,  7219,  7253,  7287,  7321,  7355,  6588,  6841,  6841,  6841,
    6841,  6841,  6841,  6841,  6841,  6841,  6841,  6841,  6841,  6841,
    6841,  6841,    15,    48,   745,  2567,  2735,  2878,  3046,   222,
   12544,  2783,  6831,  6831,  6831,  6831,  6831,  6831,  6831,  6831,
    6831,  6831,  6831,  6831,  6831,  6831,  6831,  3189,   224,  3357,
     243,    49,    66,   745,  3500,  3669,  3811,  3980,   245, 12575,
    3715,   246,   248,  1225,  8307,  8340,  6851,  6851,  6851,  8373,
    6851,  6851,  6723,  8406,  8439,  8472,  8505,  8538,  8571,  8604,
    8637,  8670,  8703,  4026,   287,  4122,    79,    98,   189, 10122,
      41,  1746, 10155, 10188, 10221, 10254, 10287,   244, 10320, 10353,
     279,   252,    41,  1746,  7389,  7423,  7457,  7491,  7525,   254,
   10386,  7559,   281,   256, 10419, 10452, 10485, 10518, 10551, 10584,
   10617, 10650, 10683, 10716, 10749, 10782, 10815, 10848, 10881,  4174,
    6767,  4226,  2713,   829,  4241,  4293,   113,  7593,  7627,  7661,
    7695,  7729,  7763,  7797,  7831,  7865,  7899,  7933,  7967,  8001,
    8035,  8069,  4309,  4355,  6778,  4371,  3024,   829,  4417,  4433,
      41,  1746,  8736,  8769,  8802,  8835,  8868,   260, 10914,  6851,
    6851,  6851,  6851,  6851,  6851,  6851,  6851,  6851,  6851,  6851,
    6851,  6851,  6851,  6851,  8901,   285,   267,  4479,    92,   106,
     120,   268, 10947, 10980,  6841,  1746,   120,   269,  8103,  8137,
    6831,  1746,   270, 11013,   146,   273,   271,   320,  4494,   275,
   11046,   164,   278,   274,   120,   284,  8934,  8967,  9000,  9033,
    9066,  9099,  9132,  9165,  9198,  9231,  9264,  9297,  9330,  9363,
    9396,  9429,  9462,  6851,  1746,   288, 11079, 11112,   289,   290,
    8171,  8205,   292,  1044,  4105,  1435,  4546,  3335,  4561,  4613,
    6503,  6518,  1435,  4629,  3646,  4675,   295,  9495,  9528,   296,
   11145, 11178,  8239,  8273,  1510,  4690,  1510,  4742,   167,   168,
     280,  2132,  4758,  2132,  4804,   171,   172,   299,  9561,  9594,
    4819,  1510,  4871,  1510,  2057,  1510,  2057,  1510,  1561,  4887,
    2132,  4933,  2132,  2057,  2132,  2057,  2132,  1872,  4948,  5000,
     298,  5015,   300,  5067,   312,   316,  5083,  5129,   317,  5145,
     318,  5191,   322,   324,  1510,  1510,  1510,  1510,  2132,  2132,
    2132,  2132,  5206,  5258,  5273,  5325,  5341,  5387,  5403,  5449
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -258,  -258,  -258,   306,    21,  -258,  -258,  -258,  -258,   145,
       9,  -257,  -230,  -258,   264,   162,   291,   428,  -258,   436,
     488,   203,     0,  -218,  1179,  1490,  1801,  2112,  2423,  2734,
    3045,  3356,  3667,  -217,  -242,  -106,  -258,   866,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    21,    22,    23,   103,    25,   149,   162,   163,   164,
     265,    63,   104,   105,   106,   107,   266,   267,   108,   268,
     269,    97,   270,    85,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    86,   132,    92,    93,    50,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    43,   340,   341,    -3,   222,    53,   373,    55,    26,
      49,    51,    52,  -107,   134,    58,   369,    59,    60,    62,
     146,    24,    32,    43,   140,   137,    64,   138,   352,   353,
      47,    26,   287,   -21,   -21,   -15,   397,   -15,   -15,   161,
     -15,   326,   327,    24,   328,  -113,    88,   223,    91,   371,
     393,    44,   290,    54,    95,    56,    98,   197,     5,     6,
       7,     8,     9,   370,    10,    11,    12,   395,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   -15,   428,  -111,  -113,   -17,   328,   291,
     152,   292,    15,    16,    17,    18,   372,   394,  -113,    19,
     127,    48,   293,   429,  -112,   425,   426,    45,  -111,    46,
    -112,    67,  -114,   324,   396,   -59,  -114,   221,    99,  -110,
     326,   327,   171,   328,   172,   145,    91,   128,  -111,  -111,
      44,   -23,   -23,   447,   151,   299,   299,   313,   129,    98,
     325,  -113,  -113,   446,   294,   294,  -110,  -112,  -112,  -111,
     166,  -112,    32,   126,    32,  -114,  -114,  -114,   289,  -110,
     448,    26,    27,    26,   125,   130,   131,   453,    32,  -103,
      32,   329,    32,   329,    32,   329,   133,    26,   166,    26,
     173,    26,   174,    26,    27,   187,  -110,  -110,   475,    32,
      32,    32,    32,   485,   479,   486,   -18,   177,    26,    26,
      26,    26,   -20,   -20,   332,   333,   334,   135,   335,   336,
     338,   492,   496,   493,   524,   526,   525,   527,   533,   535,
     534,   536,   -24,   -24,   147,   431,   -22,   -22,   -19,   -19,
     344,   345,   346,   139,   347,   348,   350,   437,  -110,  -110,
     142,   148,   150,   160,   175,   176,    20,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   189,   190,   141,   191,   192,   330,   331,   374,
    -110,   287,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   342,   427,   343,
     392,    28,   398,   432,   400,   455,   401,   153,   155,   434,
     435,   440,   159,   438,   441,   473,   402,   403,   404,   456,
     405,   406,   408,    28,   167,   474,   169,   476,   480,   483,
     487,   489,   188,   488,   490,   494,   495,   528,    66,   478,
     179,    91,   180,   497,   182,   482,   184,   500,   501,   502,
     156,   503,   158,    91,   518,   519,   537,   554,     0,   555,
     290,   193,   194,   195,   196,   197,     5,     6,     7,     8,
       9,   556,    10,    11,    12,   557,   558,   559,   499,   143,
     443,   560,    98,   561,   181,     0,   183,     0,   186,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   154,   292,
      15,    16,    17,    18,   450,     0,    98,    19,     0,     0,
     293,    91,     0,     0,     0,     0,     0,     0,     0,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,     0,     0,   295,   295,    29,     0,
       0,     0,     0,     0,   477,    91,    30,     0,     0,     0,
     481,    91,     0,    28,     0,    28,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,    30,    28,
       0,    28,     0,    28,     0,    28,     0,     0,     0,     0,
       0,     0,     0,   498,    91,     0,     0,     0,     0,     0,
      28,    28,    28,    28,     0,   313,     0,    98,    31,     0,
     299,   299,   313,     0,    98,     0,     0,     0,     0,   294,
     294,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,   299,     0,   299,     0,     0,     0,     0,     0,     0,
     294,     0,   294,     0,   329,     0,   329,     0,   329,     0,
     299,     0,   299,   329,   299,   329,   299,   329,     0,   294,
       0,   294,    57,   294,     0,   294,     0,   197,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     0,   299,   299,
     299,   299,     0,   296,   296,     0,     0,   294,   294,   294,
     294,   297,   297,     0,     0,   445,     0,     0,     0,     0,
      29,     0,    29,    16,    17,    18,     0,     0,    30,    19,
      30,     0,     0,     0,     0,     0,    29,     0,    29,   452,
      29,     0,    29,     0,    30,     0,    30,     0,    30,     0,
      30,     0,     0,     0,     0,     0,     0,    29,    29,    29,
      29,     0,     0,   298,   298,    30,    30,    30,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,    31,     0,     0,   505,   507,     0,     0,     0,
       0,     0,   512,   514,     0,     0,    31,     0,    31,     0,
      31,     0,    31,     0,     0,     0,   520,     0,   522,     0,
       0,     0,     0,   529,     0,   531,     0,    31,    31,    31,
      31,     0,     0,   538,     0,   539,     0,   541,   508,   543,
     510,     0,   546,     0,   547,   515,   549,   517,   551,     0,
      61,     0,     0,     0,     0,   198,   199,   200,   201,   202,
     203,     0,   204,   205,   206,     0,   562,   563,   564,   565,
     566,   567,   568,   569,     0,     0,     0,   540,     0,   542,
       0,   545,     0,     0,     0,     0,   548,     0,   550,     0,
     553,   207,   208,   209,     0,     0,   -25,   210,   -25,   -25,
       0,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,
     -25,     0,     0,     0,     0,    -4,     1,     0,     2,     3,
       0,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,   295,   295,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
       0,     0,     0,   -25,     0,     0,   -25,   -25,     0,     0,
       0,     0,   295,    13,   295,    14,    15,    16,    17,    18,
       0,     0,     0,    19,     0,     0,    20,     0,     0,     0,
       0,   295,     0,   295,     0,   295,     0,   295,     0,     0,
     101,     0,     2,     3,     0,     4,     5,     6,     7,     8,
       9,     0,    10,    11,    12,     0,     0,     0,     0,   295,
     295,   295,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,   262,   102,   263,
      15,    16,    17,    18,     0,     0,     0,    19,     0,     0,
     264,   -27,     0,     0,     0,   220,     0,     0,    42,     0,
       0,     0,     0,   -32,     0,   -32,   -32,     0,   -32,   -32,
     -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,    87,    89,
       0,     0,     0,    90,   246,     0,     0,     0,   296,   296,
     220,     0,     0,     0,     0,     0,   297,   297,     0,   271,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,   296,
     -32,   296,     0,   -32,   -32,     0,     0,   297,     0,   297,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
     296,     0,   296,     0,   296,     0,   297,     0,   297,     0,
     297,   271,   297,     0,     0,   144,     0,     0,   298,   298,
       0,     0,     0,     0,     0,     0,   296,   296,   296,   296,
       0,     0,   246,     0,   297,   297,   297,   297,     0,   298,
     246,   298,     0,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,   298,     0,
     298,   185,   298,     0,   298,     0,   198,   199,   200,   201,
     202,   203,   178,   204,   205,   206,     0,   220,     0,   220,
       0,   220,     0,   165,     0,   288,   298,   298,   298,   298,
     197,     5,     6,     7,     8,     9,     0,    10,    11,    12,
       0,     0,   207,   208,   209,     0,     0,     0,   210,   -60,
     220,   220,   220,     0,   220,   220,   220,     0,     0,     0,
       0,     0,   262,   504,   263,    15,    16,    17,    18,     0,
       0,     0,    19,     0,     0,   264,   246,   246,   246,     0,
     246,   246,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   376,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   323,   323,   323,     0,   323,   323,   220,   101,
       0,     2,     3,     0,     4,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,     0,   430,   246,   211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   436,   246,
       0,     0,     0,     0,     0,     0,   262,   102,   263,    15,
      16,    17,    18,     0,     0,     0,    19,   237,     0,   264,
     -28,     0,     0,   211,     0,     0,   220,     0,     0,   271,
       0,     0,   -99,   -99,   -99,     0,   -99,   -99,     0,     0,
       0,     0,   -99,   -99,   -99,   -99,   -99,   -99,     0,     0,
     220,     0,     0,   271,     0,     0,   454,   246,   -99,   -99,
     -99,   -99,   -99,     0,   -99,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   246,     0,     0,     0,   237,   246,   246,     0,     0,
       0,     0,     0,   237,     0,     0,   314,     0,     0,     0,
       0,     0,   -30,     0,   -30,   -30,     0,   -30,   -30,   -30,
     -30,   -30,   -30,     0,   -30,   -30,   -30,     0,     0,   323,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,   323,   211,     0,   211,     0,     0,     0,   323,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,
       0,     0,   -30,   -30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   211,   211,     0,   211,   211,   211,
     220,     0,   220,     0,   220,     0,     0,     0,     0,   220,
       0,   220,     0,   220,     0,     0,     0,     0,     0,   237,
     237,   237,     0,   237,   237,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   300,   301,   302,   303,   304,   305,     0,   306,   307,
     308,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,   310,   311,
       0,     0,   -60,   312,   -60,   314,   314,   314,     0,   314,
     314,   211,   -31,     0,   -31,   -31,     0,   -31,   -31,   -31,
     -31,   -31,   -31,     0,   -31,   -31,   -31,     0,     0,   212,
     237,   288,     0,     0,     0,     0,   197,     5,     6,     7,
       8,     9,   237,    10,    11,    12,     0,     0,     0,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,     0,     0,   238,   -31,
       0,     0,   -31,   -31,   212,     0,     0,     0,   262,   211,
     263,    15,    16,    17,    18,     0,     0,     0,    19,     0,
       0,   264,   544,     0,     0,     0,     0,   198,   199,   200,
     201,   202,   203,   211,   204,   205,   206,     0,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   207,   208,   209,     0,     0,     0,   210,
     -60,     0,     0,   211,   237,     0,   238,     0,     0,   237,
     237,     0,     0,     0,   238,     0,     0,   315,     0,     0,
       0,     0,     0,     0,     0,   -33,     0,   -33,   -33,     0,
     -33,   -33,   -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,
       0,     0,   314,   237,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   212,   314,   212,     0,     0,     0,     0,
       0,   314,   -33,   -33,   -33,   -33,   -33,   -33,   -33,     0,
       0,     0,   -33,     0,     0,   -33,   -33,     0,     0,     0,
       0,     0,     0,     0,   212,   212,   212,     0,   212,   212,
     212,     0,     0,   211,     0,   211,     0,   211,     0,     0,
       0,     0,   211,     0,   211,     0,   211,     0,     0,     0,
     238,   238,   238,     0,   238,   238,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   224,   225,   226,   227,   228,   229,     0,   230,
     231,   232,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     235,     0,     0,     0,   236,  -106,   315,   315,   315,     0,
     315,   315,   212,   -48,     0,   -48,   -48,     0,   -48,   -48,
     -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,     0,     0,
     213,   238,    65,     0,     0,     0,     0,   197,     5,     6,
       7,     8,     9,   238,    10,    11,    12,     0,     0,     0,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,   239,
     -48,     0,     0,   -48,   -48,   213,     0,     0,     0,    13,
     212,    14,    15,    16,    17,    18,     0,     0,     0,    19,
       0,     0,    20,   552,     0,     0,     0,     0,   198,   199,
     200,   201,   202,   203,   212,   204,   205,   206,     0,     0,
       0,   238,     0,     0,     0,     0,     0,     0,     0,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   207,   208,   209,     0,     0,     0,
     210,   -60,     0,     0,   212,   238,     0,   239,     0,     0,
     238,   238,     0,     0,     0,   239,     0,     0,   316,     0,
       0,     0,     0,     0,     0,     0,   -29,     0,   -29,   -29,
       0,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,
     -29,     0,     0,   315,   238,     0,     0,     0,     0,     0,
       0,     0,   213,     0,   213,   315,   213,     0,     0,     0,
       0,     0,   315,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
       0,     0,     0,   -29,     0,     0,   -29,   -29,     0,     0,
       0,     0,     0,     0,     0,   213,   213,   213,     0,   213,
     213,   213,     0,     0,   212,     0,   212,     0,   212,     0,
       0,     0,     0,   212,     0,   212,     0,   212,     0,     0,
       0,   239,   239,   239,     0,   239,   239,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   198,   199,   200,   201,   202,   203,     0,
     204,   205,   206,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,     0,   210,   -60,   316,   316,   316,
       0,   316,   316,   213,   -43,   -43,     0,   -43,   -43,     0,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,
       0,   214,   239,   290,     0,     0,     0,     0,   197,     5,
       6,     7,     8,     9,   239,    10,    11,    12,     0,     0,
       0,     0,   -43,   168,   -43,   -43,   -43,   -43,   -43,     0,
     240,     0,   -43,     0,     0,   -43,   214,     0,     0,     0,
     291,   213,   292,    15,    16,    17,    18,     0,     0,     0,
      19,     0,     0,   293,    96,     0,     0,     0,     0,   197,
       5,     6,     7,     8,     9,   213,    10,    11,    12,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,    16,    17,    18,     0,     0,
     -60,    19,     0,     0,     0,   213,   239,     0,   240,     0,
       0,   239,   239,     0,     0,     0,   240,     0,     0,   317,
       0,     0,     0,     0,     0,     0,   -41,   -41,     0,   -41,
     -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,
     -41,   -41,     0,     0,   316,   239,     0,     0,     0,     0,
       0,     0,     0,   214,     0,   214,   316,   214,     0,     0,
       0,     0,     0,   316,   -41,   170,   -41,   -41,   -41,   -41,
     -41,     0,     0,     0,   -41,     0,     0,   -41,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   214,   214,     0,
     214,   214,   214,     0,     0,   213,     0,   213,     0,   213,
       0,     0,     0,     0,   213,     0,   213,     0,   213,     0,
       0,     0,   240,   240,   240,     0,   240,   240,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,     0,
       0,     0,     0,   157,     0,     0,     0,     0,   197,     5,
       6,     7,     8,     9,     0,    10,    11,    12,   317,   317,
     317,     0,   317,   317,   214,   -49,     0,   -49,   -49,     0,
     -49,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,
       0,     0,   215,   240,    16,    17,    18,     0,     0,   -60,
      19,     0,     0,     0,     0,   240,     0,     0,     0,     0,
       0,     0,   -49,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,   241,   -49,  -110,     0,   -49,   -49,   215,  -110,     0,
       0,     0,   214,     0,     0,     0,     0,     0,     0,  -110,
    -110,  -110,  -110,  -110,  -110,     0,     0,     0,     0,  -110,
    -110,  -110,  -110,  -110,  -110,     0,   214,     0,     0,     0,
       0,     0,     0,   240,     0,  -110,  -110,  -110,  -110,  -110,
    -110,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   240,     0,   241,
       0,     0,   240,   240,     0,     0,     0,   241,     0,     0,
     318,     0,     0,     0,     0,     0,     0,     0,   -35,     0,
     -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
     -35,   -35,   -35,     0,     0,   317,   240,     0,     0,     0,
       0,     0,     0,     0,   215,     0,   215,   317,   215,     0,
       0,     0,     0,     0,   317,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,     0,   -35,     0,     0,   -35,   -35,
       0,     0,     0,     0,     0,     0,     0,   215,   215,   215,
       0,   215,   215,   215,     0,     0,   214,     0,   214,     0,
     214,     0,     0,     0,     0,   214,     0,   214,     0,   214,
       0,     0,     0,   241,   241,   241,     0,   241,   241,   215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
       0,     0,     0,     0,   444,     0,     0,     0,     0,   197,
       5,     6,     7,     8,     9,     0,    10,    11,    12,   318,
     318,   318,     0,   318,   318,   215,   -34,     0,   -34,   -34,
       0,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,
     -34,     0,     0,   216,   241,    16,    17,    18,     0,     0,
     -60,    19,     0,     0,     0,     0,   241,     0,     0,     0,
       0,     0,     0,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
       0,     0,   242,   -34,    84,     0,   -34,   -34,   216,   221,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
     -69,   -69,   -69,   -62,   -69,   -69,     0,     0,     0,     0,
     -69,   -69,   -69,   -69,   -69,   -69,     0,   215,     0,     0,
       0,     0,     0,     0,   241,     0,   -69,   -69,   -69,   -69,
     -69,  -101,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,   241,     0,
     242,     0,     0,   241,   241,     0,     0,     0,   242,     0,
       0,   319,     0,     0,     0,     0,     0,     0,     0,   -38,
       0,   -38,   -38,     0,   -38,   -38,   -38,   -38,   -38,   -38,
       0,   -38,   -38,   -38,     0,     0,   318,   241,     0,     0,
       0,     0,     0,     0,     0,   216,     0,   216,   318,   216,
       0,     0,     0,     0,     0,   318,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,
     -38,     0,     0,     0,     0,     0,     0,     0,   216,   216,
     216,     0,   216,   216,   216,     0,     0,   215,     0,   215,
       0,   215,     0,     0,     0,     0,   215,     0,   215,     0,
     215,     0,     0,     0,   242,   242,   242,     0,   242,   242,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,     0,     0,     0,     0,   451,     0,     0,     0,     0,
     197,     5,     6,     7,     8,     9,     0,    10,    11,    12,
     319,   319,   319,     0,   319,   319,   216,   -39,     0,   -39,
     -39,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,   -39,
     -39,   -39,     0,     0,   217,   242,    16,    17,    18,     0,
       0,   -60,    19,     0,     0,     0,     0,   242,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,   243,   -39,    84,     0,   -39,   -39,   217,
       0,     0,     0,     0,   216,     0,     0,     0,     0,     0,
       0,   -69,   -69,   -69,   -62,   -69,   -69,     0,     0,     0,
       0,   -69,   -69,   -69,   -69,   -69,   -69,     0,   216,     0,
       0,     0,     0,     0,     0,   242,     0,   -69,   -69,   -69,
     -69,   -69,  -101,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   242,
       0,   243,     0,     0,   242,   242,     0,     0,     0,   243,
       0,     0,   320,     0,     0,     0,     0,     0,     0,     0,
     -37,     0,   -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -37,   -37,     0,     0,   319,   242,     0,
       0,     0,     0,     0,     0,     0,   217,     0,   217,   319,
     217,     0,     0,     0,     0,     0,   319,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,   -37,     0,     0,
     -37,   -37,     0,     0,     0,     0,     0,     0,     0,   217,
     217,   217,     0,   217,   217,   217,     0,     0,   216,     0,
     216,     0,   216,     0,     0,     0,     0,   216,     0,   216,
       0,   216,     0,     0,     0,   243,   243,   243,     0,   243,
     243,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,     0,     0,     0,     0,   509,     0,     0,     0,
       0,   197,     5,     6,     7,     8,     9,     0,    10,    11,
      12,   320,   320,   320,     0,   320,   320,   217,   -11,     0,
     -11,   -11,     0,   -11,   -11,   -11,   -11,   -11,   -11,     0,
     -11,   -11,   -11,     0,     0,   218,   243,    16,    17,    18,
       0,     0,   -60,    19,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,     0,     0,   244,   -11,  -110,     0,   -11,   -11,
     218,     0,     0,     0,     0,   217,     0,     0,     0,     0,
       0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,
       0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,   217,
       0,     0,     0,     0,     0,     0,   243,     0,  -110,  -110,
    -110,  -110,  -110,  -110,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     243,     0,   244,     0,     0,   243,   243,     0,     0,     0,
     244,     0,     0,   321,     0,     0,     0,     0,     0,     0,
     -35,   -35,     0,   -35,   -35,     0,   -35,   -35,   -35,   -35,
     -35,   -35,     0,   -35,   -35,   -35,     0,     0,   320,   243,
       0,     0,     0,     0,     0,     0,     0,   218,     0,   218,
     320,   218,     0,     0,     0,     0,     0,   320,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,     0,   -35,     0,
       0,   -35,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   218,   218,     0,   218,   218,   218,     0,     0,   217,
       0,   217,     0,   217,     0,     0,     0,     0,   217,     0,
     217,     0,   217,     0,     0,     0,   244,   244,   244,     0,
     244,   244,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,     0,     0,     0,     0,   516,     0,     0,
       0,     0,   197,     5,     6,     7,     8,     9,     0,    10,
      11,    12,   321,   321,   321,     0,   321,   321,   218,   -34,
     -34,     0,   -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,   -34,   -34,   -34,     0,   219,   244,    16,    17,
      18,     0,     0,   -60,    19,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   245,  -110,   -34,     0,     0,
     -34,   219,     0,     0,     0,     0,   218,     0,     0,     0,
       0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,
       0,     0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,
     218,     0,     0,     0,     0,     0,     0,   244,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   244,     0,   245,     0,     0,   244,   244,     0,     0,
       0,   245,     0,     0,   322,     0,     0,     0,     0,     0,
       0,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,   -38,     0,     0,   321,
     244,     0,     0,     0,     0,     0,     0,     0,   219,     0,
     219,   321,   219,     0,     0,     0,     0,     0,   321,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,   -38,
       0,     0,   -38,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   219,   219,     0,   219,   219,   219,     0,     0,
     218,     0,   218,     0,   218,     0,     0,     0,     0,   218,
       0,   218,     0,   218,     0,     0,     0,   245,   245,   245,
       0,   245,   245,   219,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,     0,     0,     0,     0,    94,     0,
       0,     0,     0,   198,   199,   200,   201,   202,   203,     0,
     204,   205,   206,   322,   322,   322,     0,   322,   322,   219,
     -39,   -39,     0,   -39,   -39,     0,   -39,   -39,   -39,   -39,
     -39,   -39,     0,   -39,   -39,   -39,     0,     0,   245,   207,
     208,   209,     0,     0,     0,   210,     0,     0,     0,     0,
     245,     0,     0,     0,     0,     0,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,     0,     0,   424,   -39,     0,
       0,   -39,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,   -69,   -69,   -69,   -62,   -69,   -69,     0,
       0,     0,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,
       0,   219,     0,     0,     0,     0,     0,     0,   245,   -69,
     -69,   -69,   -69,   -69,  -101,   -69,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   245,     0,     0,     0,   288,   245,   245,     0,
       0,   197,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,     0,   -10,     0,   -10,   -10,     0,   -10,   -10,
     -10,   -10,   -10,   -10,     0,   -10,   -10,   -10,     0,     0,
     322,   245,     0,   262,   506,   263,    15,    16,    17,    18,
       0,     0,   322,    19,     0,     0,   264,     0,     0,   322,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,     0,     0,     0,
     -10,     0,     0,   -10,   -10,   -47,     0,   -47,   -47,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,
       0,   219,     0,   219,     0,   219,     0,     0,     0,     0,
     219,     0,   219,     0,   219,     0,     0,     0,     0,     0,
       0,     0,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,
       0,     0,   -47,     0,     0,   -47,   -47,   -57,     0,   -57,
     -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,     0,   -57,
     -57,   -57,   -40,     0,   -40,   -40,     0,   -40,   -40,   -40,
     -40,   -40,   -40,     0,   -40,   -40,   -40,     0,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,     0,   -57,     0,     0,   -57,   -57,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,   -40,
       0,     0,   -40,   -40,   -36,     0,   -36,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -37,
     -37,     0,   -37,   -37,     0,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -37,   -37,     0,     0,     0,     0,     0,
       0,   -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,
       0,   -36,     0,     0,   -36,   -36,     0,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,     0,   -47,   -47,   -37,   -47,   -47,
     -37,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,
     -47,   -57,   -57,     0,   -57,   -57,     0,   -57,   -57,   -57,
     -57,   -57,   -57,     0,   -57,   -57,   -57,     0,     0,     0,
       0,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
       0,     0,     0,   -47,     0,     0,   -47,     0,     0,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,     0,   -40,   -40,   -57,
     -40,   -40,   -57,   -40,   -40,   -40,   -40,   -40,   -40,     0,
     -40,   -40,   -40,   -36,   -36,     0,   -36,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,     0,
       0,     0,     0,     0,     0,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,     0,     0,     0,   -40,     0,     0,   -40,     0,
       0,   -36,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,
     -12,   -36,   -12,   -12,   -36,   -12,   -12,   -12,   -12,   -12,
     -12,     0,   -12,   -12,   -12,   -14,     0,   -14,   -14,     0,
     -14,   -14,   -14,   -14,   -14,   -14,     0,   -14,   -14,   -14,
       0,     0,     0,     0,     0,     0,     0,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,     0,     0,     0,   -12,     0,     0,
     -12,   -12,   -14,   -14,   -14,   -14,   -14,   -14,   -14,     0,
       0,     0,   -14,     0,     0,   -14,   -14,   -56,     0,   -56,
     -56,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,
     -56,   -56,   -26,     0,   -26,   -26,     0,   -26,   -26,   -26,
     -26,   -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,
       0,     0,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,     0,     0,     0,   -56,     0,     0,   -56,   -56,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,     0,     0,     0,   -26,
       0,     0,   -26,   -26,   -13,     0,   -13,   -13,     0,   -13,
     -13,   -13,   -13,   -13,   -13,     0,   -13,   -13,   -13,   -56,
     -56,     0,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,
     -56,     0,   -56,   -56,   -56,     0,     0,     0,     0,     0,
       0,   -13,   -13,   -13,   -13,   -13,   -13,   -13,     0,     0,
       0,   -13,     0,     0,   -13,   -13,     0,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,     0,   -26,   -26,   -56,   -26,   -26,
     -56,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   -43,     0,   -43,   -43,     0,   -43,   -43,   -43,   -43,
     -43,   -43,     0,   -43,   -43,   -43,     0,     0,     0,     0,
       0,     0,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
       0,     0,     0,   -26,     0,     0,   -26,     0,   -43,   521,
     -43,   -43,   -43,   -43,   -43,     0,     0,     0,   -43,     0,
       0,   -43,   -43,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,   -41,   -41,   -41,     0,   -41,   -41,   -41,   -43,   -43,
       0,   -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,   -43,
       0,   -43,   -43,   -43,     0,     0,     0,     0,     0,     0,
     -41,   523,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,
     -41,     0,     0,   -41,   -41,     0,   -43,   530,   -43,   -43,
     -43,   -43,   -43,     0,   -41,   -41,   -43,   -41,   -41,   -43,
     -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,   -41,   -41,
     -46,     0,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,     0,   -46,   -46,   -46,     0,     0,     0,     0,     0,
       0,     0,   -41,   532,   -41,   -41,   -41,   -41,   -41,     0,
       0,     0,   -41,     0,     0,   -41,     0,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,     0,   -46,     0,     0,
     -46,   -46,   -45,     0,   -45,   -45,     0,   -45,   -45,   -45,
     -45,   -45,   -45,     0,   -45,   -45,   -45,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,   -46,     0,     0,     0,     0,     0,     0,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,     0,     0,     0,   -45,
       0,     0,   -45,   -45,     0,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,     0,   -45,   -45,   -46,   -45,   -45,   -46,   -45,
     -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -44,
       0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,     0,     0,     0,     0,     0,     0,
       0,   -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,     0,     0,   -45,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,     0,   -44,     0,     0,   -44,
     -44,   -42,     0,   -42,   -42,     0,   -42,   -42,   -42,   -42,
     -42,   -42,     0,   -42,   -42,   -42,   -54,     0,   -54,   -54,
       0,   -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,
     -54,     0,     0,     0,     0,     0,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,     0,     0,     0,   -42,     0,
       0,   -42,   -42,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,   -54,     0,     0,   -54,   -54,   -55,     0,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,     0,
     -55,   -55,   -55,   -44,   -44,     0,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,     0,
       0,     0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,   -55,     0,     0,   -55,   -55,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -42,
     -42,   -44,   -42,   -42,   -44,   -42,   -42,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   -42,   -54,   -54,     0,   -54,   -54,
       0,   -54,   -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,
     -54,     0,     0,     0,     0,     0,     0,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,     0,     0,     0,   -42,     0,     0,
     -42,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
       0,   -55,   -55,   -54,   -55,   -55,   -54,   -55,   -55,   -55,
     -55,   -55,   -55,     0,   -55,   -55,   -55,   -51,     0,   -51,
     -51,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,
     -51,   -51,     0,     0,     0,     0,     0,     0,     0,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,
       0,     0,   -55,     0,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,     0,   -51,     0,     0,   -51,   -51,   -52,
       0,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   -52,   -53,     0,   -53,   -53,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,     0,
       0,     0,     0,     0,     0,     0,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,
     -52,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,     0,
       0,   -53,     0,     0,   -53,   -53,   -50,     0,   -50,   -50,
       0,   -50,   -50,   -50,   -50,   -50,   -50,     0,   -50,   -50,
     -50,   -51,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,
     -51,   -51,   -51,     0,   -51,   -51,   -51,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
       0,     0,     0,   -50,     0,     0,   -50,   -50,     0,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,     0,   -52,   -52,   -51,
     -52,   -52,   -51,   -52,   -52,   -52,   -52,   -52,   -52,     0,
     -52,   -52,   -52,   -53,   -53,     0,   -53,   -53,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,     0,
       0,     0,     0,     0,     0,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,   -52,     0,     0,   -52,     0,
       0,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -50,
     -50,   -53,   -50,   -50,   -53,   -50,   -50,   -50,   -50,   -50,
     -50,     0,   -50,   -50,   -50,    -2,    65,     0,     2,     3,
       0,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,     0,     0,     0,     0,     0,     0,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,   -50,     0,     0,
     -50,     0,     0,    13,     0,    14,    15,    16,    17,    18,
       0,    -6,    -6,    19,    -6,    -6,    20,    -6,    -6,    -6,
      -6,    -6,    -6,     0,    -6,    -6,    -6,    -7,    -7,     0,
      -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,    -7,     0,
      -7,    -7,    -7,     0,     0,     0,     0,     0,     0,    -6,
       0,    -6,    -6,    -6,    -6,    -6,     0,     0,     0,    -6,
       0,     0,    -6,     0,     0,    -7,     0,    -7,    -7,    -7,
      -7,    -7,     0,    -8,    -8,    -7,    -8,    -8,    -7,    -8,
      -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,    -8,   -35,
     -35,     0,   -35,   -35,     0,   -35,   -35,   -35,   -35,   -35,
     -35,     0,   -35,   -35,   -35,     0,     0,     0,     0,     0,
       0,    -8,     0,    -8,    -8,    -8,    -8,    -8,     0,     0,
       0,    -8,     0,     0,    -8,     0,     0,   -35,     0,   -35,
     -35,   -35,   -35,   -35,     0,    -9,    -9,   -35,    -9,    -9,
     -35,    -9,    -9,    -9,    -9,    -9,    -9,     0,    -9,    -9,
      -9,   -34,   -34,     0,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,   -34,   -34,   -34,     0,     0,     0,
       0,     0,     0,    -9,     0,    -9,    -9,    -9,    -9,    -9,
       0,     0,     0,    -9,     0,     0,    -9,     0,     0,   -34,
       0,   -34,   -34,   -34,   -34,   -34,     0,   -38,   -38,   -34,
     -38,   -38,   -34,   -38,   -38,   -38,   -38,   -38,   -38,     0,
     -38,   -38,   -38,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,     0,
       0,     0,     0,     0,     0,   -38,     0,   -38,   -38,   -38,
     -38,   -38,     0,     0,     0,   -38,     0,     0,   -38,     0,
       0,   -39,     0,   -39,   -39,   -39,   -39,   -39,     0,   -37,
     -37,   -39,   -37,   -37,   -39,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -37,   -37,   -47,   -47,     0,   -47,   -47,
       0,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,
     -47,     0,     0,     0,     0,     0,     0,   -37,     0,   -37,
     -37,   -37,   -37,   -37,     0,     0,     0,   -37,     0,     0,
     -37,     0,     0,   -47,     0,   -47,   -47,   -47,   -47,   -47,
       0,   -57,   -57,   -47,   -57,   -57,   -47,   -57,   -57,   -57,
     -57,   -57,   -57,     0,   -57,   -57,   -57,    -5,    -5,     0,
      -5,    -5,     0,    -5,    -5,    -5,    -5,    -5,    -5,     0,
      -5,    -5,    -5,     0,     0,     0,     0,     0,     0,   -57,
       0,   -57,   -57,   -57,   -57,   -57,     0,     0,     0,   -57,
       0,     0,   -57,     0,     0,    -5,     0,    -5,    -5,    -5,
      -5,    -5,     0,   -40,   -40,    -5,   -40,   -40,    -5,   -40,
     -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -36,
     -36,     0,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,
     -36,     0,   -36,   -36,   -36,     0,     0,     0,     0,     0,
       0,   -40,     0,   -40,   -40,   -40,   -40,   -40,     0,     0,
       0,   -40,     0,     0,   -40,     0,     0,   -36,     0,   -36,
     -36,   -36,   -36,   -36,     0,   -11,   -11,   -36,   -11,   -11,
     -36,   -11,   -11,   -11,   -11,   -11,   -11,     0,   -11,   -11,
     -11,   -14,   -14,     0,   -14,   -14,     0,   -14,   -14,   -14,
     -14,   -14,   -14,     0,   -14,   -14,   -14,     0,     0,     0,
       0,     0,     0,   -11,     0,   -11,   -11,   -11,   -11,   -11,
       0,     0,     0,   -11,     0,     0,   -11,     0,     0,   -14,
       0,   -14,   -14,   -14,   -14,   -14,     0,   -10,   -10,   -14,
     -10,   -10,   -14,   -10,   -10,   -10,   -10,   -10,   -10,     0,
     -10,   -10,   -10,   -56,   -56,     0,   -56,   -56,     0,   -56,
     -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,     0,
       0,     0,     0,     0,     0,   -10,     0,   -10,   -10,   -10,
     -10,   -10,     0,     0,     0,   -10,     0,     0,   -10,     0,
       0,   -56,     0,   -56,   -56,   -56,   -56,   -56,     0,   -26,
     -26,   -56,   -26,   -26,   -56,   -26,   -26,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,   -13,   -13,     0,   -13,   -13,
       0,   -13,   -13,   -13,   -13,   -13,   -13,     0,   -13,   -13,
     -13,     0,     0,     0,     0,     0,     0,   -26,     0,   -26,
     -26,   -26,   -26,   -26,     0,     0,     0,   -26,     0,     0,
     -26,     0,     0,   -13,     0,   -13,   -13,   -13,   -13,   -13,
       0,   -12,   -12,   -13,   -12,   -12,   -13,   -12,   -12,   -12,
     -12,   -12,   -12,     0,   -12,   -12,   -12,   -46,   -46,     0,
     -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -46,   -46,   -46,     0,     0,     0,     0,     0,     0,   -12,
       0,   -12,   -12,   -12,   -12,   -12,     0,     0,     0,   -12,
       0,     0,   -12,     0,     0,   -46,     0,   -46,   -46,   -46,
     -46,   -46,     0,   -45,   -45,   -46,   -45,   -45,   -46,   -45,
     -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -44,
     -44,     0,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,     0,   -44,   -44,   -44,     0,     0,     0,     0,     0,
       0,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,     0,     0,   -45,     0,     0,   -44,     0,   -44,
     -44,   -44,   -44,   -44,     0,   -42,   -42,   -44,   -42,   -42,
     -44,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,
     -42,   -54,   -54,     0,   -54,   -54,     0,   -54,   -54,   -54,
     -54,   -54,   -54,     0,   -54,   -54,   -54,     0,     0,     0,
       0,     0,     0,   -42,     0,   -42,   -42,   -42,   -42,   -42,
       0,     0,     0,   -42,     0,     0,   -42,     0,     0,   -54,
       0,   -54,   -54,   -54,   -54,   -54,     0,   -55,   -55,   -54,
     -55,   -55,   -54,   -55,   -55,   -55,   -55,   -55,   -55,     0,
     -55,   -55,   -55,   -16,   -16,     0,   -16,   -16,     0,   -16,
     -16,   -16,   -16,   -16,   -16,     0,   -16,   -16,   -16,     0,
       0,     0,     0,     0,     0,   -55,     0,   -55,   -55,   -55,
     -55,   -55,     0,     0,     0,   -55,     0,     0,   -55,     0,
       0,   -16,     0,   -16,   -16,   -16,   -16,   -16,     0,   -51,
     -51,   -16,   -51,   -51,   -16,   -51,   -51,   -51,   -51,   -51,
     -51,     0,   -51,   -51,   -51,   -52,   -52,     0,   -52,   -52,
       0,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,
     -52,     0,     0,     0,     0,     0,     0,   -51,     0,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,   -51,     0,     0,
     -51,     0,     0,   -52,     0,   -52,   -52,   -52,   -52,   -52,
       0,   -53,   -53,   -52,   -53,   -53,   -52,   -53,   -53,   -53,
     -53,   -53,   -53,     0,   -53,   -53,   -53,   -50,   -50,     0,
     -50,   -50,     0,   -50,   -50,   -50,   -50,   -50,   -50,     0,
     -50,   -50,   -50,     0,     0,     0,     0,     0,     0,   -53,
       0,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,   -53,
       0,     0,   -53,     0,     0,   -50,     0,   -50,   -50,   -50,
     -50,   -50,     0,     0,   290,   -50,     0,     0,   -50,   197,
       5,     6,     7,     8,     9,     0,    10,    11,    12,   290,
       0,     0,     0,     0,   197,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,     0,     0,     0,
       0,   291,   511,   292,    15,    16,    17,    18,     0,     0,
       0,    19,     0,     0,   293,  -110,   291,   513,   292,    15,
      16,    17,    18,     0,     0,     0,    19,     0,     0,   293,
       0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,
       0,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,   351,
       0,     0,     0,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,     0,  -110,  -110,  -110,   -69,   -69,   -69,   -62,   -69,
     -69,     0,     0,     0,     0,   -69,   -69,   -69,   -69,   -69,
     -69,     0,     0,  -110,     0,     0,     0,     0,     0,     0,
       0,   -69,   -69,   -69,   -69,     0,  -101,   -69,   -69,  -110,
    -110,  -110,  -110,  -110,  -110,     0,     0,     0,     0,  -110,
    -110,  -110,  -110,  -110,  -110,     0,   339,     0,     0,     0,
       0,     0,     0,     0,     0,  -110,  -110,  -110,  -110,     0,
    -110,  -110,   -69,   -69,   -69,   -62,   -69,   -69,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -69,   -69,
     -69,   -69,   337,  -101,   -69,     0,     0,   198,   199,   200,
     201,   202,   203,   349,   204,   205,   206,     0,   198,   199,
     200,   201,   202,   203,   407,   204,   205,   206,     0,   198,
     199,   200,   201,   202,   203,     0,   204,   205,   206,     0,
       0,     0,     0,   207,   208,   209,     0,     0,     0,   210,
       0,     0,     0,     0,   207,   208,   209,     0,     0,     0,
     210,     0,     0,     0,     0,   207,   208,   209,   442,     0,
       0,   210,     0,   198,   199,   200,   201,   202,   203,   449,
     204,   205,   206,     0,   198,   199,   200,   201,   202,   203,
       0,   204,   205,   206,   197,     5,     6,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,     0,   210,     0,     0,     0,     0,
     207,   208,   209,     0,     0,     0,   210,     0,     0,     0,
      16,    17,    18,     0,     0,     0,    19,   224,   225,   226,
     227,   228,   229,     0,   230,   231,   232,   198,   199,   200,
     201,   202,   203,     0,   204,   205,   206,   300,   301,   302,
     303,   304,   305,     0,   306,   307,   308,     0,     0,     0,
       0,     0,     0,   233,   234,   235,     0,     0,     0,   236,
       0,     0,     0,   207,   208,   209,     0,     0,     0,   210,
       0,     0,     0,   309,   310,   311,   272,   273,   274,   312,
     275,   276,     0,     0,     0,     0,   277,   278,   279,   280,
     281,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,   284,   285,   286,     0,     0,  -109,  -109,
     272,   273,   274,     0,   275,   276,     0,     0,     0,     0,
     277,   278,   279,   280,   281,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,   285,   286,
       0,     0,  -108,  -108,   -99,   -99,   -99,     0,   -99,   -99,
       0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,   -99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -99,   -99,   -99,   -99,     0,     0,   -99,   -99,   -98,   -98,
     -98,     0,   -98,   -98,     0,     0,     0,     0,   -98,   -98,
     -98,   -98,   -98,   -98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -98,   -98,   -98,   -98,     0,     0,
     -98,   -98,   -97,   -97,   -97,     0,   -97,   -97,     0,     0,
       0,     0,   -97,   -97,   -97,   -97,   -97,   -97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -97,   -97,
     -97,   -97,     0,     0,   -97,   -97,  -100,  -100,  -100,     0,
    -100,  -100,     0,     0,     0,     0,  -100,  -100,  -100,  -100,
    -100,  -100,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -100,  -100,  -100,  -100,     0,     0,  -100,  -100,
     -64,   -64,   -64,     0,   -64,   -64,     0,     0,     0,     0,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -64,   -64,   -64,   -64,
       0,     0,   -64,   -64,   -65,   -65,   -65,     0,   -65,   -65,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -65,   -65,   -65,   -65,     0,     0,   -65,   -65,   -66,   -66,
     -66,     0,   -66,   -66,     0,     0,     0,     0,   -66,   -66,
     -66,   -66,   -66,   -66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -66,   -66,   -66,   -66,     0,     0,
     -66,   -66,   -67,   -67,   -67,     0,   -67,   -67,     0,     0,
       0,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -67,   -67,
     -67,   -67,     0,     0,   -67,   -67,   -93,   -93,   -93,     0,
     -93,   -93,     0,     0,     0,     0,   -93,   -93,   -93,   -93,
     -93,   -93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -93,   -93,   -93,   -93,     0,     0,   -93,   -93,
     -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,     0,
     -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -94,   -94,   -94,   -94,
       0,     0,   -94,   -94,   -95,   -95,   -95,     0,   -95,   -95,
       0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -95,   -95,   -95,   -95,     0,     0,   -95,   -95,   -96,   -96,
     -96,     0,   -96,   -96,     0,     0,     0,     0,   -96,   -96,
     -96,   -96,   -96,   -96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -96,   -96,   -96,   -96,     0,     0,
     -96,   -96,   -68,   -68,   -68,     0,   -68,   -68,     0,     0,
       0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -68,   -68,
     -68,   -68,     0,     0,   -68,   -68,   -88,   -88,   -88,     0,
     -88,   -88,     0,     0,     0,     0,   -88,   -88,   -88,   -88,
     -88,   -88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -88,   -88,   -88,   -88,     0,     0,   -88,   -88,
     -89,   -89,   -89,     0,   -89,   -89,     0,     0,     0,     0,
     -89,   -89,   -89,   -89,   -89,   -89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -89,   -89,   -89,   -89,
       0,     0,   -89,   -89,   -90,   -90,   -90,     0,   -90,   -90,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -90,   -90,   -90,   -90,     0,     0,   -90,   -90,   -91,   -91,
     -91,     0,   -91,   -91,     0,     0,     0,     0,   -91,   -91,
     -91,   -91,   -91,   -91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -91,   -91,   -91,   -91,     0,     0,
     -91,   -91,   -92,   -92,   -92,     0,   -92,   -92,     0,     0,
       0,     0,   -92,   -92,   -92,   -92,   -92,   -92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -92,   -92,
     -92,   -92,     0,     0,   -92,   -92,   -71,   -71,   -71,     0,
     -71,   -71,     0,     0,     0,     0,   -71,   -71,   -71,   -71,
     -71,   -71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -71,   -71,   -71,   -71,     0,     0,   -71,   -71,
     -85,   273,   274,     0,   -85,   -85,     0,     0,     0,     0,
     -85,   -85,   -85,   -85,   -85,   -85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,   285,   286,
       0,     0,   -85,   -85,   -86,   -86,   274,     0,   -86,   -86,
       0,     0,     0,     0,   -86,   -86,   -86,   -86,   -86,   -86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     283,   284,   285,   286,     0,     0,   -86,   -86,   -87,   -87,
     -87,     0,   -87,   -87,     0,     0,     0,     0,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,   284,   285,   286,     0,     0,
     -87,   -87,   272,   273,   274,     0,   -73,   276,     0,     0,
       0,     0,   277,   278,   279,   280,   281,   282,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,   284,
     285,   286,     0,     0,   -73,   -73,   272,   273,   274,     0,
     -74,   -74,     0,     0,     0,     0,   277,   278,   279,   280,
     281,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,   284,   285,   286,     0,     0,   -74,   -74,
     272,   273,   274,     0,   -75,   -75,     0,     0,     0,     0,
     -75,   -75,   279,   280,   281,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,   285,   286,
       0,     0,   -75,   -75,   272,   273,   274,     0,   -76,   -76,
       0,     0,     0,     0,   -76,   -76,   279,   280,   281,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     283,   284,   285,   286,     0,     0,   -76,   -76,   272,   273,
     274,     0,   -77,   -77,     0,     0,     0,     0,   -77,   -77,
     -77,   -77,   -77,   -77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,   284,   285,   286,     0,     0,
     -77,   -77,   272,   273,   274,     0,   -78,   -78,     0,     0,
       0,     0,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,   284,
     285,   286,     0,     0,   -78,   -78,   272,   273,   274,     0,
     -79,   -79,     0,     0,     0,     0,   -79,   -79,   -79,   -79,
     -79,   -79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,   284,   285,   286,     0,     0,   -79,   -79,
     272,   273,   274,     0,   -80,   -80,     0,     0,     0,     0,
     -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,   285,   286,
       0,     0,   -80,   -80,   -81,   -81,   -81,     0,   -81,   -81,
       0,     0,     0,     0,   -81,   -81,   -81,   -81,   -81,   -81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -81,   -81,   285,   286,     0,     0,   -81,   -81,   -82,   -82,
     -82,     0,   -82,   -82,     0,     0,     0,     0,   -82,   -82,
     -82,   -82,   -82,   -82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -82,   -82,   285,   286,     0,     0,
     -82,   -82,   -83,   -83,   -83,     0,   -83,   -83,     0,     0,
       0,     0,   -83,   -83,   -83,   -83,   -83,   -83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -83,   -83,
     -83,   -83,     0,     0,   -83,   -83,   -84,   -84,   -84,     0,
     -84,   -84,     0,     0,     0,     0,   -84,   -84,   -84,   -84,
     -84,   -84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -84,   -84,   -84,   -84,     0,     0,   -84,   -84,
     -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,     0,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,
       0,     0,   -72,   -72,   -70,   -70,   -70,     0,   -70,   -70,
       0,     0,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -70,   -70,   -70,   -70,     0,     0,   -70,   -70,  -105,  -105,
    -105,     0,  -105,  -105,     0,     0,     0,     0,  -105,  -105,
    -105,  -105,  -105,  -105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -105,  -105,  -105,  -105,     0,     0,
    -105,  -105,   272,   273,   274,     0,   275,   276,     0,     0,
       0,     0,   277,   278,   279,   280,   281,   282,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,   284,
     285,   286,     0,     0,   -63,   -63,  -104,  -104,  -104,     0,
    -104,  -104,     0,     0,     0,     0,  -104,  -104,  -104,  -104,
    -104,  -104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -104,  -104,  -104,  -104,     0,     0,  -104,  -104,
    -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,     0,
    -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -102,  -102,  -102,  -102,
       0,     0,  -102,  -102,   -98,   -98,   -98,     0,   -98,   -98,
       0,     0,     0,     0,   -98,   -98,   -98,   -98,   -98,   -98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -98,   -98,   -98,   -98,   -98,     0,   -98,   -97,   -97,   -97,
       0,   -97,   -97,     0,     0,     0,     0,   -97,   -97,   -97,
     -97,   -97,   -97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -97,   -97,   -97,   -97,   -97,     0,   -97,
    -100,  -100,  -100,     0,  -100,  -100,     0,     0,     0,     0,
    -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -100,  -100,  -100,  -100,
    -100,     0,  -100,   409,   410,   411,     0,   412,   413,     0,
       0,     0,     0,   414,   415,   416,   417,   418,   419,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   420,
     421,   422,   423,   -61,     0,   -61,   -64,   -64,   -64,     0,
     -64,   -64,     0,     0,     0,     0,   -64,   -64,   -64,   -64,
     -64,   -64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -64,   -64,   -64,   -64,   -64,     0,   -64,   -65,
     -65,   -65,     0,   -65,   -65,     0,     0,     0,     0,   -65,
     -65,   -65,   -65,   -65,   -65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,
       0,   -65,   -66,   -66,   -66,     0,   -66,   -66,     0,     0,
       0,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -66,   -66,
     -66,   -66,   -66,     0,   -66,   -67,   -67,   -67,     0,   -67,
     -67,     0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,
     -67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,     0,   -67,   -93,   -93,
     -93,     0,   -93,   -93,     0,     0,     0,     0,   -93,   -93,
     -93,   -93,   -93,   -93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -93,   -93,   -93,   -93,   -93,     0,
     -93,   -94,   -94,   -94,     0,   -94,   -94,     0,     0,     0,
       0,   -94,   -94,   -94,   -94,   -94,   -94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -94,   -94,   -94,
     -94,   -94,     0,   -94,   -95,   -95,   -95,     0,   -95,   -95,
       0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,   -95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -95,   -95,   -95,   -95,   -95,     0,   -95,   -96,   -96,   -96,
       0,   -96,   -96,     0,     0,     0,     0,   -96,   -96,   -96,
     -96,   -96,   -96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,   -96,     0,   -96,
     -68,   -68,   -68,     0,   -68,   -68,     0,     0,     0,     0,
     -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,     0,   -68,   -88,   -88,   -88,     0,   -88,   -88,     0,
       0,     0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -88,
     -88,   -88,   -88,   -88,     0,   -88,   -89,   -89,   -89,     0,
     -89,   -89,     0,     0,     0,     0,   -89,   -89,   -89,   -89,
     -89,   -89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -89,   -89,   -89,   -89,   -89,     0,   -89,   -90,
     -90,   -90,     0,   -90,   -90,     0,     0,     0,     0,   -90,
     -90,   -90,   -90,   -90,   -90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,
       0,   -90,   -91,   -91,   -91,     0,   -91,   -91,     0,     0,
       0,     0,   -91,   -91,   -91,   -91,   -91,   -91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -91,   -91,
     -91,   -91,   -91,     0,   -91,   -92,   -92,   -92,     0,   -92,
     -92,     0,     0,     0,     0,   -92,   -92,   -92,   -92,   -92,
     -92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -92,   -92,   -92,   -92,   -92,     0,   -92,   -71,   -71,
     -71,     0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,     0,
     -71,   -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,
       0,   -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -72,   -72,   -72,
     -72,   -72,     0,   -72,   -70,   -70,   -70,     0,   -70,   -70,
       0,     0,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -70,   -70,   -70,   -70,   -70,     0,   -70,   -85,   410,   411,
       0,   -85,   -85,     0,     0,     0,     0,   -85,   -85,   -85,
     -85,   -85,   -85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   420,   421,   422,   423,   -85,     0,   -85,
     -86,   -86,   411,     0,   -86,   -86,     0,     0,     0,     0,
     -86,   -86,   -86,   -86,   -86,   -86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   420,   421,   422,   423,
     -86,     0,   -86,   -87,   -87,   -87,     0,   -87,   -87,     0,
       0,     0,     0,   -87,   -87,   -87,   -87,   -87,   -87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   420,
     421,   422,   423,   -87,     0,   -87,   409,   410,   411,     0,
     -73,   413,     0,     0,     0,     0,   414,   415,   416,   417,
     418,   419,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   420,   421,   422,   423,   -73,     0,   -73,   409,
     410,   411,     0,   -74,   -74,     0,     0,     0,     0,   414,
     415,   416,   417,   418,   419,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   420,   421,   422,   423,   -74,
       0,   -74,   409,   410,   411,     0,   -75,   -75,     0,     0,
       0,     0,   -75,   -75,   416,   417,   418,   419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   420,   421,
     422,   423,   -75,     0,   -75,   409,   410,   411,     0,   -76,
     -76,     0,     0,     0,     0,   -76,   -76,   416,   417,   418,
     419,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   420,   421,   422,   423,   -76,     0,   -76,   409,   410,
     411,     0,   -77,   -77,     0,     0,     0,     0,   -77,   -77,
     -77,   -77,   -77,   -77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   420,   421,   422,   423,   -77,     0,
     -77,   409,   410,   411,     0,   -78,   -78,     0,     0,     0,
       0,   -78,   -78,   -78,   -78,   -78,   -78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   420,   421,   422,
     423,   -78,     0,   -78,   409,   410,   411,     0,   -79,   -79,
       0,     0,     0,     0,   -79,   -79,   -79,   -79,   -79,   -79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     420,   421,   422,   423,   -79,     0,   -79,   409,   410,   411,
       0,   -80,   -80,     0,     0,     0,     0,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   420,   421,   422,   423,   -80,     0,   -80,
     -81,   -81,   -81,     0,   -81,   -81,     0,     0,     0,     0,
     -81,   -81,   -81,   -81,   -81,   -81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -81,   -81,   422,   423,
     -81,     0,   -81,   -82,   -82,   -82,     0,   -82,   -82,     0,
       0,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -82,
     -82,   422,   423,   -82,     0,   -82,   -83,   -83,   -83,     0,
     -83,   -83,     0,     0,     0,     0,   -83,   -83,   -83,   -83,
     -83,   -83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -83,   -83,   -83,   -83,   -83,     0,   -83,   -84,
     -84,   -84,     0,   -84,   -84,     0,     0,     0,     0,   -84,
     -84,   -84,   -84,   -84,   -84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -84,   -84,   -84,   -84,   -84,
       0,   -84,  -105,  -105,  -105,     0,  -105,  -105,     0,     0,
       0,     0,  -105,  -105,  -105,  -105,  -105,  -105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -105,  -105,
    -105,  -105,  -105,     0,  -105,   409,   410,   411,     0,   412,
     413,     0,     0,     0,     0,   414,   415,   416,   417,   418,
     419,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   420,   421,   422,   423,   -63,     0,   -63,  -104,  -104,
    -104,     0,  -104,  -104,     0,     0,     0,     0,  -104,  -104,
    -104,  -104,  -104,  -104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -104,  -104,  -104,  -104,  -104,     0,
    -104,  -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -102,  -102,  -102,
    -102,  -102,     0,  -102,   247,   248,   249,     0,   250,   251,
       0,     0,     0,     0,   252,   253,   254,   255,   256,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,   259,   260,   261,     0,     0,   100,   247,   248,   249,
       0,   250,   251,     0,     0,     0,     0,   252,   253,   254,
     255,   256,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,   260,   261,     0,     0,   136,
     -99,   -99,   -99,     0,   -99,   -99,     0,     0,     0,     0,
     -99,   -99,   -99,   -99,   -99,   -99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -99,   -99,   -99,   -99,
       0,     0,   -99,   -98,   -98,   -98,     0,   -98,   -98,     0,
       0,     0,     0,   -98,   -98,   -98,   -98,   -98,   -98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,     0,     0,   -98,   -97,   -97,   -97,     0,
     -97,   -97,     0,     0,     0,     0,   -97,   -97,   -97,   -97,
     -97,   -97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -97,   -97,   -97,   -97,     0,     0,   -97,  -100,
    -100,  -100,     0,  -100,  -100,     0,     0,     0,     0,  -100,
    -100,  -100,  -100,  -100,  -100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -100,  -100,  -100,  -100,     0,
       0,  -100,   -64,   -64,   -64,     0,   -64,   -64,     0,     0,
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
     -67,     0,     0,   -67,   -93,   -93,   -93,     0,   -93,   -93,
       0,     0,     0,     0,   -93,   -93,   -93,   -93,   -93,   -93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -93,   -93,   -93,   -93,     0,     0,   -93,   -94,   -94,   -94,
       0,   -94,   -94,     0,     0,     0,     0,   -94,   -94,   -94,
     -94,   -94,   -94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -94,   -94,   -94,   -94,     0,     0,   -94,
     -95,   -95,   -95,     0,   -95,   -95,     0,     0,     0,     0,
     -95,   -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -95,   -95,   -95,   -95,
       0,     0,   -95,   -96,   -96,   -96,     0,   -96,   -96,     0,
       0,     0,     0,   -96,   -96,   -96,   -96,   -96,   -96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -96,
     -96,   -96,   -96,     0,     0,   -96,   -68,   -68,   -68,     0,
     -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -68,   -68,   -68,   -68,     0,     0,   -68,   247,
     248,   249,     0,   250,   251,     0,     0,     0,     0,   252,
     253,   254,   255,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,   261,     0,
       0,   -61,   -88,   -88,   -88,     0,   -88,   -88,     0,     0,
       0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -88,   -88,
     -88,   -88,     0,     0,   -88,   -89,   -89,   -89,     0,   -89,
     -89,     0,     0,     0,     0,   -89,   -89,   -89,   -89,   -89,
     -89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -89,   -89,   -89,   -89,     0,     0,   -89,   -90,   -90,
     -90,     0,   -90,   -90,     0,     0,     0,     0,   -90,   -90,
     -90,   -90,   -90,   -90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,     0,     0,
     -90,   -91,   -91,   -91,     0,   -91,   -91,     0,     0,     0,
       0,   -91,   -91,   -91,   -91,   -91,   -91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -91,   -91,   -91,
     -91,     0,     0,   -91,   -92,   -92,   -92,     0,   -92,   -92,
       0,     0,     0,     0,   -92,   -92,   -92,   -92,   -92,   -92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -92,   -92,   -92,   -92,     0,     0,   -92,   247,   248,   249,
       0,   250,   251,     0,     0,     0,     0,   252,   253,   254,
     255,   256,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,   260,   261,     0,     0,   433,
     -71,   -71,   -71,     0,   -71,   -71,     0,     0,     0,     0,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -71,   -71,   -71,   -71,
       0,     0,   -71,   247,   248,   249,     0,   250,   251,     0,
       0,     0,     0,   252,   253,   254,   255,   256,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     259,   260,   261,     0,     0,   439,   -85,   248,   249,     0,
     -85,   -85,     0,     0,     0,     0,   -85,   -85,   -85,   -85,
     -85,   -85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,   259,   260,   261,     0,     0,   -85,   -86,
     -86,   249,     0,   -86,   -86,     0,     0,     0,     0,   -86,
     -86,   -86,   -86,   -86,   -86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,   261,     0,
       0,   -86,   -87,   -87,   -87,     0,   -87,   -87,     0,     0,
       0,     0,   -87,   -87,   -87,   -87,   -87,   -87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,   259,
     260,   261,     0,     0,   -87,   247,   248,   249,     0,   -73,
     251,     0,     0,     0,     0,   252,   253,   254,   255,   256,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,   261,     0,     0,   -73,   247,   248,
     249,     0,   -74,   -74,     0,     0,     0,     0,   252,   253,
     254,   255,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,   260,   261,     0,     0,
     -74,   247,   248,   249,     0,   -75,   -75,     0,     0,     0,
       0,   -75,   -75,   254,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   259,   260,
     261,     0,     0,   -75,   247,   248,   249,     0,   -76,   -76,
       0,     0,     0,     0,   -76,   -76,   254,   255,   256,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,   259,   260,   261,     0,     0,   -76,   247,   248,   249,
       0,   -77,   -77,     0,     0,     0,     0,   -77,   -77,   -77,
     -77,   -77,   -77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,   260,   261,     0,     0,   -77,
     247,   248,   249,     0,   -78,   -78,     0,     0,     0,     0,
     -78,   -78,   -78,   -78,   -78,   -78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,   261,
       0,     0,   -78,   247,   248,   249,     0,   -79,   -79,     0,
       0,     0,     0,   -79,   -79,   -79,   -79,   -79,   -79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     259,   260,   261,     0,     0,   -79,   247,   248,   249,     0,
     -80,   -80,     0,     0,     0,     0,   -80,   -80,   -80,   -80,
     -80,   -80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,   259,   260,   261,     0,     0,   -80,   -81,
     -81,   -81,     0,   -81,   -81,     0,     0,     0,     0,   -81,
     -81,   -81,   -81,   -81,   -81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -81,   -81,   260,   261,     0,
       0,   -81,   -82,   -82,   -82,     0,   -82,   -82,     0,     0,
       0,     0,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -82,   -82,
     260,   261,     0,     0,   -82,   -83,   -83,   -83,     0,   -83,
     -83,     0,     0,     0,     0,   -83,   -83,   -83,   -83,   -83,
     -83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -83,   -83,   -83,   -83,     0,     0,   -83,   -84,   -84,
     -84,     0,   -84,   -84,     0,     0,     0,     0,   -84,   -84,
     -84,   -84,   -84,   -84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -84,   -84,   -84,   -84,     0,     0,
     -84,   247,   248,   249,     0,   250,   251,     0,     0,     0,
       0,   252,   253,   254,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   259,   260,
     261,     0,     0,   457,   -72,   -72,   -72,     0,   -72,   -72,
       0,     0,     0,     0,   -72,   -72,   -72,   -72,   -72,   -72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -72,   -72,   -72,   -72,     0,     0,   -72,   -70,   -70,   -70,
       0,   -70,   -70,     0,     0,     0,     0,   -70,   -70,   -70,
     -70,   -70,   -70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -70,   -70,   -70,   -70,     0,     0,   -70,
     247,   248,   249,     0,   250,   251,     0,     0,     0,     0,
     252,   253,   254,   255,   256,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,   261,
       0,     0,   484,   247,   248,   249,     0,   250,   251,     0,
       0,     0,     0,   252,   253,   254,   255,   256,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     259,   260,   261,     0,     0,   491,  -105,  -105,  -105,     0,
    -105,  -105,     0,     0,     0,     0,  -105,  -105,  -105,  -105,
    -105,  -105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -105,  -105,  -105,  -105,     0,     0,  -105,   247,
     248,   249,     0,   250,   251,     0,     0,     0,     0,   252,
     253,   254,   255,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,   261,     0,
       0,   -63,  -104,  -104,  -104,     0,  -104,  -104,     0,     0,
       0,     0,  -104,  -104,  -104,  -104,  -104,  -104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -104,  -104,
    -104,  -104,     0,     0,  -104,  -102,  -102,  -102,     0,  -102,
    -102,     0,     0,     0,     0,  -102,  -102,  -102,  -102,  -102,
    -102,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -102,  -102,  -102,  -102,     0,     0,  -102,   -99,   -99,
     -99,     0,   -99,   -99,     0,     0,     0,     0,   -99,   -99,
     -99,   -99,   -99,   -99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -99,   -99,   -99,   -99,   -99,   -98,
     -98,   -98,     0,   -98,   -98,     0,     0,     0,     0,   -98,
     -98,   -98,   -98,   -98,   -98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -98,   -98,   -98,   -98,   -98,
     -97,   -97,   -97,     0,   -97,   -97,     0,     0,     0,     0,
     -97,   -97,   -97,   -97,   -97,   -97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -97,   -97,   -97,   -97,
     -97,  -100,  -100,  -100,     0,  -100,  -100,     0,     0,     0,
       0,  -100,  -100,  -100,  -100,  -100,  -100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -100,  -100,  -100,
    -100,  -100,    68,    69,    70,     0,    71,    72,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,   -64,   -64,   -64,     0,   -64,   -64,     0,
       0,     0,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -64,
     -64,   -64,   -64,   -64,   -65,   -65,   -65,     0,   -65,   -65,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -65,   -65,   -65,   -65,   -65,   -66,   -66,   -66,     0,   -66,
     -66,     0,     0,     0,     0,   -66,   -66,   -66,   -66,   -66,
     -66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -67,   -67,   -67,     0,
     -67,   -67,     0,     0,     0,     0,   -67,   -67,   -67,   -67,
     -67,   -67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -67,   -67,   -67,   -67,   -67,   -93,   -93,   -93,
       0,   -93,   -93,     0,     0,     0,     0,   -93,   -93,   -93,
     -93,   -93,   -93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -93,   -93,   -93,   -93,   -93,   -94,   -94,
     -94,     0,   -94,   -94,     0,     0,     0,     0,   -94,   -94,
     -94,   -94,   -94,   -94,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -94,   -94,   -94,   -94,   -94,   -95,
     -95,   -95,     0,   -95,   -95,     0,     0,     0,     0,   -95,
     -95,   -95,   -95,   -95,   -95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -95,   -95,   -95,   -95,   -95,
     -96,   -96,   -96,     0,   -96,   -96,     0,     0,     0,     0,
     -96,   -96,   -96,   -96,   -96,   -96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -96,   -96,   -96,   -96,
     -96,   -68,   -68,   -68,     0,   -68,   -68,     0,     0,     0,
       0,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -68,   -68,   -68,
     -68,   -68,   -88,   -88,   -88,     0,   -88,   -88,     0,     0,
       0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -88,   -88,
     -88,   -88,   -88,   -89,   -89,   -89,     0,   -89,   -89,     0,
       0,     0,     0,   -89,   -89,   -89,   -89,   -89,   -89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -89,
     -89,   -89,   -89,   -89,   -90,   -90,   -90,     0,   -90,   -90,
       0,     0,     0,     0,   -90,   -90,   -90,   -90,   -90,   -90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -90,   -90,   -90,   -90,   -90,    68,    69,    70,     0,    71,
      72,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,   -58,   -91,   -91,   -91,     0,
     -91,   -91,     0,     0,     0,     0,   -91,   -91,   -91,   -91,
     -91,   -91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -91,   -91,   -91,   -91,   -91,   -92,   -92,   -92,
       0,   -92,   -92,     0,     0,     0,     0,   -92,   -92,   -92,
     -92,   -92,   -92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -92,   -92,   -92,   -92,   -92,   -71,   -71,
     -71,     0,   -71,   -71,     0,     0,     0,     0,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -71,   -71,   -71,   -71,   -71,    68,
      69,    70,     0,    71,    72,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,   -61,
     -72,   -72,   -72,     0,   -72,   -72,     0,     0,     0,     0,
     -72,   -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -72,   -72,   -72,   -72,
     -72,   -70,   -70,   -70,     0,   -70,   -70,     0,     0,     0,
       0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -70,   -70,   -70,
     -70,   -70,   -85,    69,    70,     0,   -85,   -85,     0,     0,
       0,     0,   -85,   -85,   -85,   -85,   -85,   -85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,   -85,   -86,   -86,    70,     0,   -86,   -86,     0,
       0,     0,     0,   -86,   -86,   -86,   -86,   -86,   -86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,   -86,   -87,   -87,   -87,     0,   -87,   -87,
       0,     0,     0,     0,   -87,   -87,   -87,   -87,   -87,   -87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,   -87,    68,    69,    70,     0,   -73,
      72,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    80,    81,    82,   -73,    68,    69,    70,     0,
     -74,   -74,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,   -74,    68,    69,    70,
       0,   -75,   -75,     0,     0,     0,     0,   -75,   -75,    75,
      76,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,   -75,    68,    69,
      70,     0,   -76,   -76,     0,     0,     0,     0,   -76,   -76,
      75,    76,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,   -76,    68,
      69,    70,     0,   -77,   -77,     0,     0,     0,     0,   -77,
     -77,   -77,   -77,   -77,   -77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,   -77,
      68,    69,    70,     0,   -78,   -78,     0,     0,     0,     0,
     -78,   -78,   -78,   -78,   -78,   -78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
     -78,    68,    69,    70,     0,   -79,   -79,     0,     0,     0,
       0,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,   -79,    68,    69,    70,     0,   -80,   -80,     0,     0,
       0,     0,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,   -80,   -81,   -81,   -81,     0,   -81,   -81,     0,
       0,     0,     0,   -81,   -81,   -81,   -81,   -81,   -81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -81,
     -81,    81,    82,   -81,   -82,   -82,   -82,     0,   -82,   -82,
       0,     0,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -82,   -82,    81,    82,   -82,   -83,   -83,   -83,     0,   -83,
     -83,     0,     0,     0,     0,   -83,   -83,   -83,   -83,   -83,
     -83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -83,   -83,   -83,   -83,   -83,   -84,   -84,   -84,     0,
     -84,   -84,     0,     0,     0,     0,   -84,   -84,   -84,   -84,
     -84,   -84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -84,   -84,   -84,   -84,   -84,  -105,  -105,  -105,
       0,  -105,  -105,     0,     0,     0,     0,  -105,  -105,  -105,
    -105,  -105,  -105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -105,  -105,  -105,  -105,  -105,    68,    69,
      70,     0,    71,    72,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,   -63,  -104,
    -104,  -104,     0,  -104,  -104,     0,     0,     0,     0,  -104,
    -104,  -104,  -104,  -104,  -104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -104,  -104,  -104,  -104,  -104,
    -102,  -102,  -102,     0,  -102,  -102,     0,     0,     0,     0,
    -102,  -102,  -102,  -102,  -102,  -102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -102,  -102,  -102,  -102,
    -102,    68,    69,    70,     0,    71,    72,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,   375,    68,    69,    70,     0,    71,    72,     0,     0,
       0,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,   399
};

static const yytype_int16 yycheck[] =
{
       0,     0,   220,   220,     0,     6,     1,   264,     1,     0,
      10,    11,    12,    49,    50,    15,     1,    17,    18,    19,
     126,     0,    22,    22,    39,    47,     0,    49,   246,   246,
      48,    22,    47,    49,    50,     1,   293,     3,     4,     1,
       6,     3,     4,    22,     6,     6,    47,     6,    48,     1,
       1,    47,     1,    48,    54,    48,    56,     6,     7,     8,
       9,    10,    11,    48,    13,    14,    15,     1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    49,     5,     6,    47,    49,     6,    38,
      39,    40,    41,    42,    43,    44,    48,    48,     6,    48,
      20,    48,    51,     5,     6,   323,   323,     5,     6,     5,
       6,    47,     6,    20,    48,    47,     6,     6,    49,    20,
       3,     4,    47,     6,    49,   125,   126,    47,    49,    50,
      47,    49,    50,    20,   134,   135,   136,   137,    20,   139,
      47,    49,    50,   373,   135,   136,    47,    49,    50,    47,
     149,    47,   152,    48,   154,    49,    50,    47,    47,    20,
      47,   152,     0,   154,    20,    47,    48,   397,   168,    49,
     170,   171,   172,   173,   174,   175,    49,   168,   177,   170,
      47,   172,    49,   174,    22,   176,    47,    48,   430,   189,
     190,   191,   192,    47,   436,    49,    49,    50,   189,   190,
     191,   192,    49,    50,   204,   205,   206,    49,   208,   209,
     210,    47,   454,    49,    47,    47,    49,    49,    47,    47,
      49,    49,    49,    50,     1,   331,    49,    50,    49,    50,
     230,   231,   232,    47,   234,   235,   236,   343,    49,    50,
      52,     1,    49,    49,    47,    49,    51,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,    49,    49,   102,    49,    49,    48,    48,    47,
      49,    47,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,    48,     1,    48,
      47,     0,    47,    49,    48,   401,    48,   135,   136,    20,
      48,    20,   140,    49,    48,    20,   306,   307,   308,    49,
     310,   311,   312,    22,   152,    48,   154,    49,    49,    49,
      47,     1,   177,    52,    49,    47,    52,    47,    22,   435,
     168,   331,   170,    49,   172,   441,   174,    49,    49,    49,
     137,    49,   139,   343,    49,    49,    47,    49,    -1,    49,
       1,   189,   190,   191,   192,     6,     7,     8,     9,    10,
      11,    49,    13,    14,    15,    49,    49,    49,   474,   105,
     370,    49,   372,    49,   171,    -1,   173,    -1,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,   394,    -1,   396,    48,    -1,    -1,
      51,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,    -1,    -1,   135,   136,     0,    -1,
      -1,    -1,    -1,    -1,   434,   435,     0,    -1,    -1,    -1,
     440,   441,    -1,   152,    -1,   154,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,   168,
      -1,   170,    -1,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   473,   474,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,   485,    -1,   487,     0,    -1,
     490,   491,   492,    -1,   494,    -1,    -1,    -1,    -1,   490,
     491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,   511,    -1,   513,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,   513,    -1,   524,    -1,   526,    -1,   528,    -1,
     530,    -1,   532,   533,   534,   535,   536,   537,    -1,   530,
      -1,   532,     1,   534,    -1,   536,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,   558,   559,
     560,   561,    -1,   135,   136,    -1,    -1,   558,   559,   560,
     561,   135,   136,    -1,    -1,   372,    -1,    -1,    -1,    -1,
     152,    -1,   154,    42,    43,    44,    -1,    -1,   152,    48,
     154,    -1,    -1,    -1,    -1,    -1,   168,    -1,   170,   396,
     172,    -1,   174,    -1,   168,    -1,   170,    -1,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,    -1,   135,   136,   189,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,   154,    -1,    -1,   483,   484,    -1,    -1,    -1,
      -1,    -1,   490,   491,    -1,    -1,   168,    -1,   170,    -1,
     172,    -1,   174,    -1,    -1,    -1,   504,    -1,   506,    -1,
      -1,    -1,    -1,   511,    -1,   513,    -1,   189,   190,   191,
     192,    -1,    -1,   521,    -1,   523,    -1,   525,   485,   527,
     487,    -1,   530,    -1,   532,   492,   534,   494,   536,    -1,
       1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,   554,   555,   556,   557,
     558,   559,   560,   561,    -1,    -1,    -1,   524,    -1,   526,
      -1,   528,    -1,    -1,    -1,    -1,   533,    -1,   535,    -1,
     537,    42,    43,    44,    -1,    -1,     1,    48,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   490,   491,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,   511,    38,   513,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    -1,
      -1,   530,    -1,   532,    -1,   534,    -1,   536,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,   558,
     559,   560,   561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    42,    43,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,   490,   491,
      54,    -1,    -1,    -1,    -1,    -1,   490,   491,    -1,    63,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,   511,
      48,   513,    -1,    51,    52,    -1,    -1,   511,    -1,   513,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   530,    -1,
     532,    -1,   534,    -1,   536,    -1,   530,    -1,   532,    -1,
     534,   105,   536,    -1,    -1,   109,    -1,    -1,   490,   491,
      -1,    -1,    -1,    -1,    -1,    -1,   558,   559,   560,   561,
      -1,    -1,   126,    -1,   558,   559,   560,   561,    -1,   511,
     134,   513,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,   530,    -1,
     532,     1,   534,    -1,   536,    -1,     6,     7,     8,     9,
      10,    11,   166,    13,    14,    15,    -1,   171,    -1,   173,
      -1,   175,    -1,   177,    -1,     1,   558,   559,   560,   561,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,    49,
     204,   205,   206,    -1,   208,   209,   210,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,   230,   231,   232,    -1,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   306,   307,   308,    -1,   310,   311,   312,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,   330,   331,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,   343,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    48,    -1,    51,
      52,    -1,    -1,    54,    -1,    -1,   370,    -1,    -1,   373,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
     394,    -1,    -1,   397,    -1,    -1,   400,   401,    43,    44,
      45,    46,    47,    -1,    49,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,    -1,    -1,    -1,   126,   440,   441,    -1,    -1,
      -1,    -1,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,   473,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   485,   173,    -1,   175,    -1,    -1,    -1,   492,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,    -1,   208,   209,   210,
     524,    -1,   526,    -1,   528,    -1,    -1,    -1,    -1,   533,
      -1,   535,    -1,   537,    -1,    -1,    -1,    -1,    -1,   230,
     231,   232,    -1,   234,   235,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    49,   306,   307,   308,    -1,   310,
     311,   312,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    19,
     331,     1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,   343,    13,    14,    15,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    48,    48,
      -1,    -1,    51,    52,    54,    -1,    -1,    -1,    38,   370,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,     1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,   394,    13,    14,    15,    -1,    -1,    -1,
     401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,    42,    43,    44,    -1,    -1,    -1,    48,
      49,    -1,    -1,   434,   435,    -1,   126,    -1,    -1,   440,
     441,    -1,    -1,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,   473,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,   173,   485,   175,    -1,    -1,    -1,    -1,
      -1,   492,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,    -1,   208,   209,
     210,    -1,    -1,   524,    -1,   526,    -1,   528,    -1,    -1,
      -1,    -1,   533,    -1,   535,    -1,   537,    -1,    -1,    -1,
     230,   231,   232,    -1,   234,   235,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    48,    49,   306,   307,   308,    -1,
     310,   311,   312,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      19,   331,     1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,   343,    13,    14,    15,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    48,
      48,    -1,    -1,    51,    52,    54,    -1,    -1,    -1,    38,
     370,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,     1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,   394,    13,    14,    15,    -1,    -1,
      -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    -1,    -1,   434,   435,    -1,   126,    -1,    -1,
     440,   441,    -1,    -1,    -1,   134,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,   473,   474,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   171,    -1,   173,   485,   175,    -1,    -1,    -1,
      -1,    -1,   492,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,   205,   206,    -1,   208,
     209,   210,    -1,    -1,   524,    -1,   526,    -1,   528,    -1,
      -1,    -1,    -1,   533,    -1,   535,    -1,   537,    -1,    -1,
      -1,   230,   231,   232,    -1,   234,   235,   236,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    48,    49,   306,   307,   308,
      -1,   310,   311,   312,     0,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    19,   331,     1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,   343,    13,    14,    15,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      48,    -1,    48,    -1,    -1,    51,    54,    -1,    -1,    -1,
      38,   370,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,     1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,   394,    13,    14,    15,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    -1,   434,   435,    -1,   126,    -1,
      -1,   440,   441,    -1,    -1,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,   473,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,    -1,   173,   485,   175,    -1,    -1,
      -1,    -1,    -1,   492,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,    -1,
     208,   209,   210,    -1,    -1,   524,    -1,   526,    -1,   528,
      -1,    -1,    -1,    -1,   533,    -1,   535,    -1,   537,    -1,
      -1,    -1,   230,   231,   232,    -1,   234,   235,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,   306,   307,
     308,    -1,   310,   311,   312,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    19,   331,    42,    43,    44,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    48,    48,     1,    -1,    51,    52,    54,     6,    -1,
      -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,   394,    -1,    -1,    -1,
      -1,    -1,    -1,   401,    -1,    43,    44,    45,    46,    47,
      48,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   434,   435,    -1,   126,
      -1,    -1,   440,   441,    -1,    -1,    -1,   134,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,   473,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   171,    -1,   173,   485,   175,    -1,
      -1,    -1,    -1,    -1,   492,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,   524,    -1,   526,    -1,
     528,    -1,    -1,    -1,    -1,   533,    -1,   535,    -1,   537,
      -1,    -1,    -1,   230,   231,   232,    -1,   234,   235,   236,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,   306,
     307,   308,    -1,   310,   311,   312,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    19,   331,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    48,    48,     1,    -1,    51,    52,    54,     6,
      -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,   394,    -1,    -1,
      -1,    -1,    -1,    -1,   401,    -1,    43,    44,    45,    46,
      47,    48,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,    -1,
     126,    -1,    -1,   440,   441,    -1,    -1,    -1,   134,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,   473,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,    -1,   173,   485,   175,
      -1,    -1,    -1,    -1,    -1,   492,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,    -1,   208,   209,   210,    -1,    -1,   524,    -1,   526,
      -1,   528,    -1,    -1,    -1,    -1,   533,    -1,   535,    -1,
     537,    -1,    -1,    -1,   230,   231,   232,    -1,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
     306,   307,   308,    -1,   310,   311,   312,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    19,   331,    42,    43,    44,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,   343,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    48,    48,     1,    -1,    51,    52,    54,
      -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,   394,    -1,
      -1,    -1,    -1,    -1,    -1,   401,    -1,    43,    44,    45,
      46,    47,    48,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,   435,
      -1,   126,    -1,    -1,   440,   441,    -1,    -1,    -1,   134,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,   473,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,   173,   485,
     175,    -1,    -1,    -1,    -1,    -1,   492,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     205,   206,    -1,   208,   209,   210,    -1,    -1,   524,    -1,
     526,    -1,   528,    -1,    -1,    -1,    -1,   533,    -1,   535,
      -1,   537,    -1,    -1,    -1,   230,   231,   232,    -1,   234,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,   306,   307,   308,    -1,   310,   311,   312,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    19,   331,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,   343,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    48,    48,     1,    -1,    51,    52,
      54,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,   394,
      -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    43,    44,
      45,    46,    47,    48,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
     435,    -1,   126,    -1,    -1,   440,   441,    -1,    -1,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,   473,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,   173,
     485,   175,    -1,    -1,    -1,    -1,    -1,   492,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,    -1,   208,   209,   210,    -1,    -1,   524,
      -1,   526,    -1,   528,    -1,    -1,    -1,    -1,   533,    -1,
     535,    -1,   537,    -1,    -1,    -1,   230,   231,   232,    -1,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,   306,   307,   308,    -1,   310,   311,   312,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    19,   331,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,   343,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    48,     1,    48,    -1,    -1,
      51,    54,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
     394,    -1,    -1,    -1,    -1,    -1,    -1,   401,    43,    44,
      45,    46,    47,    48,    49,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,    -1,   126,    -1,    -1,   440,   441,    -1,    -1,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,   473,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   171,    -1,
     173,   485,   175,    -1,    -1,    -1,    -1,    -1,   492,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,   206,    -1,   208,   209,   210,    -1,    -1,
     524,    -1,   526,    -1,   528,    -1,    -1,    -1,    -1,   533,
      -1,   535,    -1,   537,    -1,    -1,    -1,   230,   231,   232,
      -1,   234,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,   306,   307,   308,    -1,   310,   311,   312,
       0,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,   331,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,     1,    48,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,   394,    -1,    -1,    -1,    -1,    -1,    -1,   401,    43,
      44,    45,    46,    47,    48,    49,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   434,   435,    -1,    -1,    -1,     1,   440,   441,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
     473,   474,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,   485,    48,    -1,    -1,    51,    -1,    -1,   492,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,   524,    -1,   526,    -1,   528,    -1,    -1,    -1,    -1,
     533,    -1,   535,    -1,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     1,    -1,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,     1,    -1,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,     0,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,     0,     1,    48,     3,     4,    51,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    51,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,     1,    -1,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    14,    15,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     1,    -1,     3,
       4,    -1,     6,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,     1,
      -1,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,    38,
      39,    40,    41,    42,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,     0,     1,    48,     3,     4,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     0,
       1,    -1,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,     0,     1,    48,     3,     4,
      51,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,     0,     1,    -1,     3,     4,    -1,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,     0,     1,    48,
       3,     4,    51,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,     0,     1,    -1,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    -1,     0,
       1,    48,     3,     4,    51,     6,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,     0,     1,    -1,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      51,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      -1,     0,     1,    48,     3,     4,    51,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     0,     1,    -1,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    51,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,     1,    48,    -1,    -1,    51,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,     1,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    51,     1,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    -1,    48,    49,    50,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    -1,    48,    49,    50,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    -1,
      48,    49,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,     1,    48,    49,    -1,    -1,     6,     7,     8,
       9,    10,    11,     1,    13,    14,    15,    -1,     6,     7,
       8,     9,    10,    11,     1,    13,    14,    15,    -1,     6,
       7,     8,     9,    10,    11,    -1,    13,    14,    15,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    42,    43,    44,     1,    -1,
      -1,    48,    -1,     6,     7,     8,     9,    10,    11,     1,
      13,    14,    15,    -1,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    48,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,     6,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    42,    43,    44,    17,    18,    19,    48,
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
      45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    38,    40,    41,    42,    43,    44,    48,
      51,    54,    55,    56,    57,    58,    63,    68,    69,    70,
      72,    73,    75,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    90,    91,    47,     5,     5,    48,    48,    75,
      90,    75,    75,     1,    48,     1,    48,     1,    75,    75,
      75,     1,    75,    64,     0,     1,    56,    47,    17,    18,
      19,    21,    22,    27,    28,    29,    30,    31,    32,    43,
      44,    45,    46,    47,     1,    76,    86,    90,    47,    90,
      90,    75,    88,    89,     1,    75,     1,    74,    75,    49,
      49,     1,    39,    57,    65,    66,    67,    68,    71,    91,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    20,    48,    20,    47,    20,
      47,    48,    87,    49,    50,    49,    49,    47,    49,    47,
      39,    68,    52,    67,    90,    75,    88,     1,     1,    59,
      49,    75,    39,    68,    39,    68,    74,     1,    74,    68,
      49,     1,    60,    61,    62,    90,    91,    68,    39,    68,
      39,    47,    49,    47,    49,    47,    49,    50,    90,    68,
      68,    74,    68,    74,    68,     1,    74,    63,    62,    49,
      49,    49,    49,    68,    68,    68,    68,     6,     6,     7,
       8,     9,    10,    11,    13,    14,    15,    42,    43,    44,
      48,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      90,     6,     6,     6,     6,     7,     8,     9,    10,    11,
      13,    14,    15,    42,    43,    44,    48,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    90,    17,    18,    19,
      21,    22,    27,    28,    29,    30,    31,    32,    43,    44,
      45,    46,    38,    40,    51,    63,    69,    70,    72,    73,
      75,    90,    17,    18,    19,    21,    22,    27,    28,    29,
      30,    31,    32,    43,    44,    45,    46,    47,     1,    47,
       1,    38,    40,    51,    63,    69,    70,    72,    73,    75,
       6,     7,     8,     9,    10,    11,    13,    14,    15,    42,
      43,    44,    48,    75,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    90,    20,    47,     3,     4,     6,    75,
      48,    48,    75,    75,    75,    75,    75,     1,    75,     1,
      76,    86,    48,    48,    75,    75,    75,    75,    75,     1,
      75,     1,    76,    86,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,     1,
      48,     1,    48,    64,    47,    47,    90,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    47,     1,    48,     1,    48,    64,    47,    47,
      48,    48,    75,    75,    75,    75,    75,     1,    75,    17,
      18,    19,    21,    22,    27,    28,    29,    30,    31,    32,
      43,    44,    45,    46,     1,    76,    86,     1,     5,     5,
      90,    88,    49,    49,    20,    48,    90,    88,    49,    49,
      20,    48,     1,    75,     1,    74,    65,    20,    47,     1,
      75,     1,    74,    65,    90,    88,    49,    49,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    20,    48,    87,    49,    75,    88,    87,
      49,    75,    88,    49,    49,    47,    49,    47,    52,     1,
      49,    49,    47,    49,    47,    52,    87,    49,    75,    88,
      49,    49,    49,    49,    39,    68,    39,    68,    74,     1,
      74,    39,    68,    39,    68,    74,     1,    74,    49,    49,
      68,    39,    68,    39,    47,    49,    47,    49,    47,    68,
      39,    68,    39,    47,    49,    47,    49,    47,    68,    68,
      74,    68,    74,    68,     1,    74,    68,    68,    74,    68,
      74,    68,     1,    74,    49,    49,    49,    49,    49,    49,
      49,    49,    68,    68,    68,    68,    68,    68,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    56,
      57,    57,    57,    57,    57,    59,    58,    60,    60,    61,
      61,    61,    62,    62,    62,    64,    63,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    76,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    81,    82,    83,
      84,    86,    85,    87,    85,    85,    88,    88,    89,    89,
      90,    91,    91,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       3,     2,     4,     4,     3,     0,     7,     0,     1,     3,
       1,     1,     2,     1,     1,     0,     4,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     5,     7,     5,     7,     6,     6,     2,     2,     3,
       9,     9,     9,     9,     7,     7,     4,     2,     2,     2,
       0,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
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
    case YYSYMBOL_INT_TOKEN: /* INT_TOKEN  */
#line 133 "./src/bison.y"
           {
    free(((*yyvaluep).string));
}
#line 3989 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 133 "./src/bison.y"
           {
    free(((*yyvaluep).string));
}
#line 3997 "bison.tab.c"
        break;

    case YYSYMBOL_LIST_TOKEN: /* LIST_TOKEN  */
#line 133 "./src/bison.y"
           {
    free(((*yyvaluep).string));
}
#line 4005 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4013 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4021 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4029 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4037 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4045 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4053 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4061 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4069 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4077 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4085 "bison.tab.c"
        break;

    case YYSYMBOL_59_1: /* @1  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4093 "bison.tab.c"
        break;

    case YYSYMBOL_optListParams: /* optListParams  */
#line 129 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 4101 "bison.tab.c"
        break;

    case YYSYMBOL_listParams: /* listParams  */
#line 129 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 4109 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4117 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4125 "bison.tab.c"
        break;

    case YYSYMBOL_optListCodeBlock: /* optListCodeBlock  */
#line 129 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 4133 "bison.tab.c"
        break;

    case YYSYMBOL_listCodeBlock: /* listCodeBlock  */
#line 129 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 4141 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4149 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4157 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4165 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4173 "bison.tab.c"
        break;

    case YYSYMBOL_elseError: /* elseError  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4181 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4189 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4197 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4205 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4213 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4221 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4229 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4237 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4245 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4253 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4261 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4269 "bison.tab.c"
        break;

    case YYSYMBOL_constantString: /* constantString  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4277 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4285 "bison.tab.c"
        break;

    case YYSYMBOL_optListExpression: /* optListExpression  */
#line 129 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 4293 "bison.tab.c"
        break;

    case YYSYMBOL_listExpression: /* listExpression  */
#line 129 "./src/bison.y"
           {
    delete_list(((*yyvaluep).list), delete_list_astnode);
}
#line 4301 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4309 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 125 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 4317 "bison.tab.c"
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
#line 159 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected error || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 4615 "bison.tab.c"
    break;

  case 4: /* startProgram: %empty  */
#line 163 "./src/bison.y"
             {
        SHOW_SYNTAX_ERROR("empty translation unit\n");
    }
#line 4623 "bison.tab.c"
    break;

  case 5: /* declarationList: declarationList declaration  */
#line 169 "./src/bison.y"
                                {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 4631 "bison.tab.c"
    break;

  case 6: /* declarationList: declaration  */
#line 172 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 4639 "bison.tab.c"
    break;

  case 7: /* declaration: variableDeclare  */
#line 178 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4647 "bison.tab.c"
    break;

  case 8: /* declaration: functionDeclare  */
#line 181 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4655 "bison.tab.c"
    break;

  case 9: /* declaration: statement  */
#line 186 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("an statement is not permitted at this top level || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 4665 "bison.tab.c"
    break;

  case 10: /* variableDeclare: type id ';'  */
#line 194 "./src/bison.y"
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
#line 4686 "bison.tab.c"
    break;

  case 11: /* variableDeclare: type ';'  */
#line 212 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("useless type name in empty declaration || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 4696 "bison.tab.c"
    break;

  case 12: /* variableDeclare: type id ASSIGN_TOKEN error  */
#line 218 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("expected ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 4707 "bison.tab.c"
    break;

  case 13: /* variableDeclare: id id ASSIGN_TOKEN error  */
#line 225 "./src/bison.y"
                               {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[-2].astnode));
        (yyval.astnode) = NULL;
    }
#line 4718 "bison.tab.c"
    break;

  case 14: /* variableDeclare: id id ';'  */
#line 232 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("unexpected type || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 4729 "bison.tab.c"
    break;

  case 15: /* @1: %empty  */
#line 241 "./src/bison.y"
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
#line 4757 "bison.tab.c"
    break;

  case 16: /* functionDeclare: type id '(' @1 optListParams ')' compoundStatement  */
#line 263 "./src/bison.y"
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
#line 4784 "bison.tab.c"
    break;

  case 17: /* optListParams: %empty  */
#line 288 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 4792 "bison.tab.c"
    break;

  case 19: /* listParams: listParams ',' param  */
#line 295 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 4801 "bison.tab.c"
    break;

  case 20: /* listParams: param  */
#line 299 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 4810 "bison.tab.c"
    break;

  case 21: /* listParams: error  */
#line 305 "./src/bison.y"
            {
        SHOW_SYNTAX_ERROR("unexpected params || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.list) = NULL;
    }
#line 4819 "bison.tab.c"
    break;

  case 22: /* param: type id  */
#line 312 "./src/bison.y"
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
#line 4839 "bison.tab.c"
    break;

  case 23: /* param: type  */
#line 329 "./src/bison.y"
           {
        SHOW_SYNTAX_ERROR("after '%s' expected identifier || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 4849 "bison.tab.c"
    break;

  case 24: /* param: id  */
#line 335 "./src/bison.y"
         {
        SHOW_SYNTAX_ERROR("expected type to '%s' || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 4859 "bison.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 343 "./src/bison.y"
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
#line 4879 "bison.tab.c"
    break;

  case 26: /* compoundStatement: '{' $@2 optListCodeBlock '}'  */
#line 357 "./src/bison.y"
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
#line 4902 "bison.tab.c"
    break;

  case 27: /* optListCodeBlock: %empty  */
#line 378 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 4910 "bison.tab.c"
    break;

  case 29: /* listCodeBlock: listCodeBlock codeBlock  */
#line 385 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 4919 "bison.tab.c"
    break;

  case 30: /* listCodeBlock: codeBlock  */
#line 389 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 4928 "bison.tab.c"
    break;

  case 31: /* codeBlock: statement  */
#line 396 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 4937 "bison.tab.c"
    break;

  case 32: /* codeBlock: variableDeclare  */
#line 400 "./src/bison.y"
                      {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 4946 "bison.tab.c"
    break;

  case 34: /* statement: flowExpression  */
#line 408 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 4955 "bison.tab.c"
    break;

  case 35: /* statement: compoundStatement  */
#line 412 "./src/bison.y"
                        {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 4964 "bison.tab.c"
    break;

  case 36: /* statement: expression ';'  */
#line 416 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 4973 "bison.tab.c"
    break;

  case 37: /* statement: error ';'  */
#line 422 "./src/bison.y"
                {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 4982 "bison.tab.c"
    break;

  case 38: /* flowExpression: condExpression  */
#line 429 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4990 "bison.tab.c"
    break;

  case 39: /* flowExpression: interationExpression  */
#line 432 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4998 "bison.tab.c"
    break;

  case 40: /* flowExpression: returnExpression ';'  */
#line 435 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 5006 "bison.tab.c"
    break;

  case 41: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 441 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5016 "bison.tab.c"
    break;

  case 42: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 446 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5027 "bison.tab.c"
    break;

  case 43: /* condExpression: IF_TOKEN '(' error ')' statement  */
#line 454 "./src/bison.y"
                                                      {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5037 "bison.tab.c"
    break;

  case 44: /* condExpression: IF_TOKEN '(' error ')' statement ELSE_TOKEN statement  */
#line 460 "./src/bison.y"
                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5048 "bison.tab.c"
    break;

  case 45: /* condExpression: IF_TOKEN '(' expression ')' ELSE_TOKEN statement  */
#line 467 "./src/bison.y"
                                                       {
        SHOW_SYNTAX_ERROR("expected expression before 'else' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-3].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5059 "bison.tab.c"
    break;

  case 46: /* condExpression: IF_TOKEN '(' error ')' ELSE_TOKEN statement  */
#line 474 "./src/bison.y"
                                                  {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5069 "bison.tab.c"
    break;

  case 47: /* condExpression: IF_TOKEN error  */
#line 480 "./src/bison.y"
                     {
        SHOW_SYNTAX_ERROR("expected '(' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 5078 "bison.tab.c"
    break;

  case 48: /* elseError: ELSE_TOKEN statement  */
#line 489 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5088 "bison.tab.c"
    break;

  case 49: /* elseError: error ELSE_TOKEN statement  */
#line 495 "./src/bison.y"
                                 {
        SHOW_SYNTAX_ERROR("'else' without a previous 'if' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5098 "bison.tab.c"
    break;

  case 50: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 503 "./src/bison.y"
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
#line 5113 "bison.tab.c"
    break;

  case 51: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ';' optExpression ')' statement  */
#line 515 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5125 "bison.tab.c"
    break;

  case 52: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ';' optExpression ')' statement  */
#line 523 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5137 "bison.tab.c"
    break;

  case 53: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' error ')' statement  */
#line 531 "./src/bison.y"
                                                                            {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-6].astnode));
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5149 "bison.tab.c"
    break;

  case 54: /* interationExpression: FOR_TOKEN '(' error ';' optExpression ')' statement  */
#line 539 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        delete_astnode((yyvsp[-2].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5160 "bison.tab.c"
    break;

  case 55: /* interationExpression: FOR_TOKEN '(' optExpression ';' error ')' statement  */
#line 546 "./src/bison.y"
                                                          {
        SHOW_SYNTAX_ERROR("expected expression before ';' token || line: %d, column: %d\n", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        delete_astnode((yyvsp[-4].astnode));
        delete_astnode((yyvsp[0].astnode));
        (yyval.astnode) = NULL;
    }
#line 5171 "bison.tab.c"
    break;

  case 56: /* interationExpression: FOR_TOKEN '(' error ')'  */
#line 553 "./src/bison.y"
                              {
        SHOW_SYNTAX_ERROR("expected expression before ')' token || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 5180 "bison.tab.c"
    break;

  case 57: /* interationExpression: FOR_TOKEN error  */
#line 558 "./src/bison.y"
                      {
        SHOW_SYNTAX_ERROR("expected '(' token after 'for' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 5189 "bison.tab.c"
    break;

  case 58: /* returnExpression: RETURN_TOKEN expression  */
#line 565 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return expression");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5198 "bison.tab.c"
    break;

  case 59: /* returnExpression: RETURN_TOKEN error  */
#line 571 "./src/bison.y"
                         {
        SHOW_SYNTAX_ERROR("'return' with no value, in function returning non-void || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.astnode) = NULL;
    }
#line 5207 "bison.tab.c"
    break;

  case 60: /* optExpression: %empty  */
#line 578 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 5215 "bison.tab.c"
    break;

  case 61: /* optExpression: expression  */
#line 581 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5223 "bison.tab.c"
    break;

  case 62: /* $@3: %empty  */
#line 587 "./src/bison.y"
       {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        }
    }
#line 5235 "bison.tab.c"
    break;

  case 63: /* expression: id $@3 ASSIGN_TOKEN expression  */
#line 593 "./src/bison.y"
                              {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5245 "bison.tab.c"
    break;

  case 64: /* expression: binArith  */
#line 598 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5254 "bison.tab.c"
    break;

  case 65: /* expression: listArith  */
#line 602 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5263 "bison.tab.c"
    break;

  case 66: /* expression: unaArith  */
#line 606 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5272 "bison.tab.c"
    break;

  case 67: /* expression: constant  */
#line 610 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5281 "bison.tab.c"
    break;

  case 68: /* expression: funcCall  */
#line 614 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5290 "bison.tab.c"
    break;

  case 69: /* expression: id  */
#line 618 "./src/bison.y"
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
#line 5305 "bison.tab.c"
    break;

  case 70: /* expression: '(' expression ')'  */
#line 628 "./src/bison.y"
                         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 5314 "bison.tab.c"
    break;

  case 71: /* expression: id error  */
#line 634 "./src/bison.y"
               {
        SHOW_SYNTAX_ERROR("expected expression before ';' || line: %d, column: %d\n", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        delete_astnode((yyvsp[-1].astnode));
        (yyval.astnode) = NULL;
    }
#line 5324 "bison.tab.c"
    break;

  case 72: /* expression: '(' error ')'  */
#line 639 "./src/bison.y"
                    {
        SHOW_SYNTAX_ERROR("expected expression before ')' || line: %d, column: %d\n", (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.astnode) = NULL;
    }
#line 5333 "bison.tab.c"
    break;

  case 73: /* binArith: expression OR_TOKEN expression  */
#line 646 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5343 "bison.tab.c"
    break;

  case 74: /* binArith: expression AND_TOKEN expression  */
#line 651 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5353 "bison.tab.c"
    break;

  case 75: /* binArith: expression EQUAL_TOKEN expression  */
#line 656 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5363 "bison.tab.c"
    break;

  case 76: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 661 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5373 "bison.tab.c"
    break;

  case 77: /* binArith: expression LESS_TOKEN expression  */
#line 666 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5383 "bison.tab.c"
    break;

  case 78: /* binArith: expression LE_EQ_TOKEN expression  */
#line 671 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5393 "bison.tab.c"
    break;

  case 79: /* binArith: expression GREAT_TOKEN expression  */
#line 676 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5403 "bison.tab.c"
    break;

  case 80: /* binArith: expression GR_EQ_TOKEN expression  */
#line 681 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5413 "bison.tab.c"
    break;

  case 81: /* binArith: expression '+' expression  */
#line 686 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5423 "bison.tab.c"
    break;

  case 82: /* binArith: expression '-' expression  */
#line 691 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5433 "bison.tab.c"
    break;

  case 83: /* binArith: expression '*' expression  */
#line 696 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5443 "bison.tab.c"
    break;

  case 84: /* binArith: expression '/' expression  */
#line 701 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5453 "bison.tab.c"
    break;

  case 85: /* listArith: expression MAP_TOKEN expression  */
#line 709 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5463 "bison.tab.c"
    break;

  case 86: /* listArith: expression FILTER_TOKEN expression  */
#line 714 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5473 "bison.tab.c"
    break;

  case 87: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 719 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5483 "bison.tab.c"
    break;

  case 88: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 727 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5492 "bison.tab.c"
    break;

  case 89: /* unaArith: QUESTION_TOKEN expression  */
#line 731 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5501 "bison.tab.c"
    break;

  case 90: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 735 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5510 "bison.tab.c"
    break;

  case 91: /* unaArith: '+' expression  */
#line 739 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5519 "bison.tab.c"
    break;

  case 92: /* unaArith: '-' expression  */
#line 743 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5528 "bison.tab.c"
    break;

  case 93: /* constant: constantInteger  */
#line 750 "./src/bison.y"
                    {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant int");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5537 "bison.tab.c"
    break;

  case 94: /* constant: constantReal  */
#line 754 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant real");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5546 "bison.tab.c"
    break;

  case 95: /* constant: constantNIL  */
#line 758 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant nil");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5555 "bison.tab.c"
    break;

  case 96: /* constant: constantString  */
#line 762 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant string");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 5564 "bison.tab.c"
    break;

  case 97: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 769 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5572 "bison.tab.c"
    break;

  case 98: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 775 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5580 "bison.tab.c"
    break;

  case 99: /* constantNIL: NIL_TOKEN  */
#line 781 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5588 "bison.tab.c"
    break;

  case 100: /* constantString: STRING_TOKEN  */
#line 787 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5596 "bison.tab.c"
    break;

  case 101: /* $@4: %empty  */
#line 793 "./src/bison.y"
       {
       Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        } 
    }
#line 5608 "bison.tab.c"
    break;

  case 102: /* funcCall: id $@4 '(' optListExpression ')'  */
#line 799 "./src/bison.y"
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
#line 5627 "bison.tab.c"
    break;

  case 103: /* $@5: %empty  */
#line 813 "./src/bison.y"
                        {
        Symbol *has_sym = lookup_symbol((yyvsp[0].astnode)->context->name, current_context);
        if(has_sym == NULL){
            SEMANTIC_ERROR("identifier '%s' undeclared || line: %d, column: %d\n", (yyvsp[0].astnode)->context->name, (yylsp[0]).first_line, (yylsp[0]).first_column);
            semantic_error = 1;
        }
    }
#line 5639 "bison.tab.c"
    break;

  case 104: /* funcCall: READ_TOKEN '(' id $@5 ')'  */
#line 819 "./src/bison.y"
          {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
    }
#line 5649 "bison.tab.c"
    break;

  case 105: /* funcCall: WRITE_TOKEN '(' optListExpression ')'  */
#line 824 "./src/bison.y"
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
#line 5668 "bison.tab.c"
    break;

  case 106: /* optListExpression: %empty  */
#line 841 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 5676 "bison.tab.c"
    break;

  case 108: /* listExpression: listExpression ',' expression  */
#line 848 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 5685 "bison.tab.c"
    break;

  case 109: /* listExpression: expression  */
#line 852 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 5694 "bison.tab.c"
    break;

  case 110: /* id: ID_TOKEN  */
#line 859 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 5702 "bison.tab.c"
    break;

  case 111: /* type: INT_TOKEN  */
#line 865 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT, (yyvsp[0].string));
    }
#line 5710 "bison.tab.c"
    break;

  case 112: /* type: FLOAT_TOKEN  */
#line 868 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT, (yyvsp[0].string));
    }
#line 5718 "bison.tab.c"
    break;

  case 113: /* type: INT_TOKEN LIST_TOKEN  */
#line 871 "./src/bison.y"
                           {
        char *str = (char *) calloc((strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 10), sizeof(char));
        strcat(str, (yyvsp[-1].string));
        strcat(str, " ");
        strcat(str, (yyvsp[0].string));
        (yyval.astnode) = create_astnode_context(AST_TYPE_INT_LIST, str);
        free(str);
    }
#line 5731 "bison.tab.c"
    break;

  case 114: /* type: FLOAT_TOKEN LIST_TOKEN  */
#line 879 "./src/bison.y"
                             {
        char *str = (char *) calloc((strlen((yyvsp[-1].string)) + strlen((yyvsp[0].string)) + 10), sizeof(char));
        strcat(str, (yyvsp[-1].string));
        strcat(str, " ");
        strcat(str, (yyvsp[0].string));
        (yyval.astnode) = create_astnode_context(AST_TYPE_FLOAT_LIST, str);
        free(str);
    }
#line 5744 "bison.tab.c"
    break;


#line 5748 "bison.tab.c"

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

#line 889 "./src/bison.y"


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
            SEMANTIC_ERROR("undefined reference to function main\n");
    } else
        SEMANTIC_ERROR("undefined reference to function main\n");

    if(root->kids->size > 0) {
        // printf("##################### %s #####################\n", "Abstract Syntax Tree");
        // print_tree(root, 0);
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
