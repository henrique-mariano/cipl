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

    extern int error, num_line, num_col;
    
    extern int yyparse();
    extern int yylex();
    extern int yylex_destroy();
    extern void yyerror(const char *error_msg);

    extern FILE *yyin;

    /* No raiz da arvore sintatica abstrata */
    AstNode *root;

    /* Lista para ajudar na criacao da arvore */
    List *node_aux;

    /* Tabela de simbolos */
    SymbolTable *symbol_table;


#line 98 "bison.tab.c"

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
  YYSYMBOL_INT_LIST_TOKEN = 5,             /* INT_LIST_TOKEN  */
  YYSYMBOL_FLOAT_LIST_TOKEN = 6,           /* FLOAT_LIST_TOKEN  */
  YYSYMBOL_ID_TOKEN = 7,                   /* ID_TOKEN  */
  YYSYMBOL_READ_TOKEN = 8,                 /* READ_TOKEN  */
  YYSYMBOL_WRITE_TOKEN = 9,                /* WRITE_TOKEN  */
  YYSYMBOL_NIL_TOKEN = 10,                 /* NIL_TOKEN  */
  YYSYMBOL_CONSTANT_REAL_TOKEN = 11,       /* CONSTANT_REAL_TOKEN  */
  YYSYMBOL_CONSTANT_INTEGER_TOKEN = 12,    /* CONSTANT_INTEGER_TOKEN  */
  YYSYMBOL_MUL_DIV_TOKEN = 13,             /* MUL_DIV_TOKEN  */
  YYSYMBOL_EXCLAMATION_TOKEN = 14,         /* EXCLAMATION_TOKEN  */
  YYSYMBOL_QUESTION_TOKEN = 15,            /* QUESTION_TOKEN  */
  YYSYMBOL_PERCENTAGE_TOKEN = 16,          /* PERCENTAGE_TOKEN  */
  YYSYMBOL_MAP_TOKEN = 17,                 /* MAP_TOKEN  */
  YYSYMBOL_FILTER_TOKEN = 18,              /* FILTER_TOKEN  */
  YYSYMBOL_CONSTRUCTOR_LIST_TOKEN = 19,    /* CONSTRUCTOR_LIST_TOKEN  */
  YYSYMBOL_ADD_MIN_TOKEN = 20,             /* ADD_MIN_TOKEN  */
  YYSYMBOL_ASSIGN_TOKEN = 21,              /* ASSIGN_TOKEN  */
  YYSYMBOL_OR_TOKEN = 22,                  /* OR_TOKEN  */
  YYSYMBOL_AND_TOKEN = 23,                 /* AND_TOKEN  */
  YYSYMBOL_EQ_EXC_TOKEN = 24,              /* EQ_EXC_TOKEN  */
  YYSYMBOL_LE_GR_TOKEN = 25,               /* LE_GR_TOKEN  */
  YYSYMBOL_IF_TOKEN = 26,                  /* IF_TOKEN  */
  YYSYMBOL_ELSE_TOKEN = 27,                /* ELSE_TOKEN  */
  YYSYMBOL_FOR_TOKEN = 28,                 /* FOR_TOKEN  */
  YYSYMBOL_RETURN_TOKEN = 29,              /* RETURN_TOKEN  */
  YYSYMBOL_STRING_TOKEN = 30,              /* STRING_TOKEN  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_startProgram = 38,              /* startProgram  */
  YYSYMBOL_declaration = 39,               /* declaration  */
  YYSYMBOL_variableDeclare = 40,           /* variableDeclare  */
  YYSYMBOL_functionDeclare = 41,           /* functionDeclare  */
  YYSYMBOL_optListParams = 42,             /* optListParams  */
  YYSYMBOL_listParams = 43,                /* listParams  */
  YYSYMBOL_param = 44,                     /* param  */
  YYSYMBOL_compoundStatement = 45,         /* compoundStatement  */
  YYSYMBOL_optListCodeBlock = 46,          /* optListCodeBlock  */
  YYSYMBOL_listCodeBlock = 47,             /* listCodeBlock  */
  YYSYMBOL_codeBlock = 48,                 /* codeBlock  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_flowExpression = 50,            /* flowExpression  */
  YYSYMBOL_condExpression = 51,            /* condExpression  */
  YYSYMBOL_interationExpression = 52,      /* interationExpression  */
  YYSYMBOL_returnExpression = 53,          /* returnExpression  */
  YYSYMBOL_optExpression = 54,             /* optExpression  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_binArith = 56,                  /* binArith  */
  YYSYMBOL_listArith = 57,                 /* listArith  */
  YYSYMBOL_unaArith = 58,                  /* unaArith  */
  YYSYMBOL_constant = 59,                  /* constant  */
  YYSYMBOL_constantInteger = 60,           /* constantInteger  */
  YYSYMBOL_constantReal = 61,              /* constantReal  */
  YYSYMBOL_constantNIL = 62,               /* constantNIL  */
  YYSYMBOL_constantString = 63,            /* constantString  */
  YYSYMBOL_funcCall = 64,                  /* funcCall  */
  YYSYMBOL_optListExpression = 65,         /* optListExpression  */
  YYSYMBOL_listExpression = 66,            /* listExpression  */
  YYSYMBOL_id = 67,                        /* id  */
  YYSYMBOL_type = 68                       /* type  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   4155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  271

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      32,    33,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    92,    98,   101,   107,   115,   137,   140,
     144,   148,   155,   164,   183,   186,   190,   194,   201,   205,
     212,   216,   220,   227,   230,   233,   239,   244,   253,   266,
     273,   276,   282,   287,   291,   295,   299,   303,   307,   311,
     318,   323,   328,   333,   338,   343,   351,   356,   361,   369,
     373,   377,   381,   388,   392,   396,   400,   407,   413,   419,
     425,   431,   445,   451,   460,   463,   467,   471,   478,   484,
     487,   490,   493
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
  "INT_LIST_TOKEN", "FLOAT_LIST_TOKEN", "ID_TOKEN", "READ_TOKEN",
  "WRITE_TOKEN", "NIL_TOKEN", "CONSTANT_REAL_TOKEN",
  "CONSTANT_INTEGER_TOKEN", "MUL_DIV_TOKEN", "EXCLAMATION_TOKEN",
  "QUESTION_TOKEN", "PERCENTAGE_TOKEN", "MAP_TOKEN", "FILTER_TOKEN",
  "CONSTRUCTOR_LIST_TOKEN", "ADD_MIN_TOKEN", "ASSIGN_TOKEN", "OR_TOKEN",
  "AND_TOKEN", "EQ_EXC_TOKEN", "LE_GR_TOKEN", "IF_TOKEN", "ELSE_TOKEN",
  "FOR_TOKEN", "RETURN_TOKEN", "STRING_TOKEN", "';'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "startProgram", "declaration",
  "variableDeclare", "functionDeclare", "optListParams", "listParams",
  "param", "compoundStatement", "optListCodeBlock", "listCodeBlock",
  "codeBlock", "statement", "flowExpression", "condExpression",
  "interationExpression", "returnExpression", "optExpression",
  "expression", "binArith", "listArith", "unaArith", "constant",
  "constantInteger", "constantReal", "constantNIL", "constantString",
  "funcCall", "optListExpression", "listExpression", "id", "type", YY_NULLPTR
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
     285,    59,    40,    41,    44,   123,   125
};
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     146,     4,    36,    48,    64,    42,   126,   133,   215,    69,
    -196,   233,   -23,     8,   248,     0,   -18,    16,    24,    71,
     -16,   146,    41,  1973,   258,    47,    50,    57,  3614,  3629,
    3644,   555,   555,   555,   555,    65,    73,   555,  3659,   684,
    2007,  2041,    70,  2075,  2109,  2143,  2177,  2211,  2245,    76,
    3674,  3689,  3704,  3719,  3734,  3749,  3764,  3779,  3794,  3809,
    1556,   102,   272,   272,  3824,  3839,  3854,  3869,   684,    53,
    3884,  2969,   290,  2279,  2313,   555,   555,   555,   555,   555,
     555,   555,   555,   555,  2347,   555,   425,    80,    82,  2986,
      85,  3003,    86,  3899,  3914,  3929,  3944,  3959,  3974,  3989,
    4004,  4019,  4034,  4049,   953,    87,    54,  4064,  4079,    84,
      53,  4094,   813,  1599,    90,  1058,   377,   272,  2381,    95,
     377,  2415,    68,  3598,  1973,  2935,   103,   121,  3020,  3037,
    3054,   684,   684,   684,   684,  3071,   684,  3088,  3105,  3122,
    3139,  3156,  3173,  3190,  3207,  3224,  2952,   123,  4109,   684,
     684,   684,   684,   684,   684,   684,   684,   684,     3,   129,
     130,  1082,  1187,  1211,   813,   813,   813,   813,  1316,   684,
    1340,  1445,  1469,  2503,  2521,  2539,  2557,  2575,  2593,   929,
    2449,   813,   813,   813,   813,   813,   813,   813,   813,   813,
     132,   134,  1973,  1633,  1667,  1701,  1735,   137,  4124,    98,
     272,   272,  3241,  3258,  3275,  3292,  3309,   684,   425,  3326,
    3343,  3360,  3377,  3394,  3411,  3428,  3445,  3462,   272,   272,
    2611,  2629,  2647,  2665,  3479,   813,   425,  2683,  2701,  2719,
    2737,  2755,  2773,  2791,  2809,  2827,   684,    53,   135,  1769,
    1803,  2483,   149,   150,  3496,  3513,   151,   162,   169,  2845,
    2863,   170,  3530,   174,  1837,  3547,  3564,  3581,  2881,  2899,
    2917,    84,    53,  1871,   176,    84,   272,  1905,   175,    84,
    1939
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   160,    12,  -196,  -196,  -196,   190,   -19,  -122,
    -196,   183,  -102,   -80,   -75,   -68,   -65,   -31,   191,   332,
     461,   590,   719,   848,   977,  1106,  1235,  1364,  -195,  -196,
      -9,    51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    40,     8,    16,    17,    18,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    88,    89,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   105,   106,
      60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    24,   199,     1,     2,     3,     4,   113,   -68,   -68,
      22,   -69,     7,   246,   118,    20,   -68,     7,   121,    23,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   194,
     146,   251,    90,    -8,   195,   -68,   -68,   -68,    92,    14,
      15,   196,    10,   -70,   197,     1,     2,     3,     4,    -9,
      21,     9,    87,   146,   146,   -71,     9,   -11,   -11,   146,
     123,    26,    27,    28,    29,    30,    19,    31,    32,    33,
     238,   -72,    19,    34,   -12,   -12,    12,   179,   122,   114,
     -10,   -10,    62,    38,   -30,    39,   119,   -65,   112,    63,
     193,   123,    26,    27,    28,    29,    30,    68,    31,    32,
      33,   -68,   -68,   179,    34,    69,    72,    74,   146,   147,
     190,   180,   191,    37,    38,   107,    39,   110,   108,   192,
     111,   117,   146,   146,   146,   146,    -3,   146,   120,    -3,
      -3,    -3,    -3,    -4,   241,   200,    -4,    -4,    -4,    -4,
     146,   146,   146,   146,   146,   146,   146,   146,   146,     1,
       2,     3,     4,   201,   -68,   179,   179,   179,   179,   263,
     146,   218,   219,   267,   236,    11,   237,   270,   239,   242,
     243,   254,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   194,   255,   256,   257,   194,   195,   247,   248,   194,
     195,   146,   146,   196,   195,   258,   197,   196,   146,   179,
     197,   196,   259,   260,   197,   262,   253,   266,   269,   146,
     146,    25,     0,     0,    50,    -5,   179,   179,    -5,    -5,
      -5,    -5,    64,    65,    66,    67,    73,   146,    70,     0,
      71,   264,     0,    -2,    50,   268,    -2,    -2,    -2,    -2,
       0,     0,   193,     0,     0,     0,   193,     0,    -6,     0,
     193,    -6,    -6,    -6,    -6,     0,     0,   146,    -7,    91,
     148,    -7,    -7,    -7,    -7,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,   104,     0,   125,
     126,   127,   128,   129,   130,     0,   131,   132,   133,     0,
     -13,     0,   134,   -13,   -13,   -13,   -13,     0,     0,     0,
     198,   148,   135,   115,   136,   -30,     0,    50,     0,     0,
       0,    50,     0,     0,     0,    50,     0,     0,     0,     0,
       0,     0,   202,   203,   204,   205,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     0,     0,    50,   123,    26,    27,    28,    29,    30,
       0,    31,    32,    33,   137,   137,     0,    34,   245,   104,
     137,     0,     0,    35,     0,    36,    37,    38,     0,    39,
       0,     0,   124,     0,     0,     0,   250,   104,   170,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   148,     0,
       0,     0,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,     0,     0,   170,   167,     0,     0,     0,   137,
       0,     0,   198,   148,     0,   168,   198,   169,   -64,     0,
     198,     0,     0,   137,   137,   137,   137,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   137,   137,   137,   137,   137,   137,   137,   137,
       0,     0,     0,     0,     0,     0,   170,   170,   170,   170,
     138,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   170,   170,   170,   170,   170,   170,
     170,   170,     0,   138,   138,     0,     0,     0,     0,   138,
       0,     0,   137,   137,     0,     0,     0,     0,     0,   137,
     170,     0,     0,     0,     0,     0,     0,   171,     0,     0,
     137,   137,     0,     0,     0,     0,     0,   170,   170,     0,
       0,     0,   123,    26,    27,    28,    29,    30,   137,    31,
      32,    33,     0,   171,     0,    34,     0,     0,   138,     0,
       0,     0,     0,     0,     0,    38,     0,    39,     0,     0,
       0,     0,   138,   138,   138,   138,     0,   138,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   138,   138,   138,   138,   138,   138,   138,   138,     0,
       0,     0,     0,     0,     0,   171,   171,   171,   171,   139,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   171,   171,   171,   171,   171,   171,   171,
     171,     0,   139,   139,     0,     0,     0,     0,   139,     0,
       0,   138,   138,     0,     0,     0,     0,     0,   138,   171,
       0,     0,     0,     0,     0,     0,   172,     0,     0,   138,
     138,     0,     0,     0,     0,     0,   171,   171,     0,     0,
       0,   125,   126,   127,   128,   129,   130,   138,   131,   132,
     133,     0,   172,     0,   134,     0,     0,   139,     0,     0,
       0,     0,     0,     0,   135,     0,   136,     0,     0,     0,
       0,   139,   139,   139,   139,     0,   139,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     139,   139,   139,   139,   139,   139,   139,   139,     0,     0,
       0,     0,     0,     0,   172,   172,   172,   172,   140,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   172,   172,   172,   172,   172,   172,   172,   172,
       0,   140,   140,     0,     0,     0,     0,   140,     0,     0,
     139,   139,     0,     0,     0,     0,     0,   139,   172,     0,
       0,     0,     0,     0,     0,   173,     0,     0,   139,   139,
       0,     0,     0,     0,     0,   172,   172,     0,     0,     0,
     158,   159,   160,   161,   162,   163,   139,   164,   165,   166,
       0,   173,     0,   167,     0,     0,   140,     0,     0,     0,
       0,     0,     0,   168,     0,   169,     0,     0,     0,     0,
     140,   140,   140,   140,     0,   140,   139,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   140,
     140,   140,   140,   140,   140,   140,   140,     0,     0,     0,
       0,     0,     0,   173,   173,   173,   173,   141,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   173,   173,   173,   173,   173,   173,   173,   173,     0,
     141,   141,     0,     0,     0,     0,   141,     0,     0,   140,
     140,     0,     0,     0,     0,     0,   140,   173,     0,     0,
       0,     0,     0,     0,   174,     0,     0,   140,   140,     0,
       0,     0,   -38,     0,   173,   173,   -38,   -38,   -38,   -38,
     225,   -38,   -38,   -38,   -38,   140,     0,     0,     0,     0,
     174,   226,   -38,   -38,     0,   141,   181,     0,     0,     0,
     182,   183,   184,   185,     0,   186,   187,   188,   189,   141,
     141,   141,   141,     0,   141,   140,   -67,   -67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   141,   141,
     141,   141,   141,   141,   141,   141,     0,     0,     0,     0,
       0,     0,   174,   174,   174,   174,   142,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     174,   174,   174,   174,   174,   174,   174,   174,     0,   142,
     142,     0,     0,     0,     0,   142,     0,     0,   141,   141,
       0,     0,     0,     0,     0,   141,   174,     0,     0,     0,
       0,     0,     0,   175,     0,     0,   141,   141,     0,     0,
       0,   181,     0,   174,   174,   182,   183,   184,   185,     0,
     186,   187,   188,   189,   141,     0,     0,     0,     0,   175,
       0,   -66,   -66,     0,   142,   -59,     0,     0,     0,   -59,
     -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,   142,   142,
     142,   142,     0,   142,   141,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   142,   142,   142,
     142,   142,   142,   142,   142,     0,     0,     0,     0,     0,
       0,   175,   175,   175,   175,   143,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   175,   175,
     175,   175,   175,   175,   175,   175,   175,     0,   143,   143,
       0,     0,     0,     0,   143,     0,     0,   142,   142,     0,
       0,     0,     0,     0,   142,   175,     0,     0,     0,     0,
       0,     0,   176,     0,     0,   142,   142,     0,     0,     0,
     -58,     0,   175,   175,   -58,   -58,   -58,   -58,     0,   -58,
     -58,   -58,   -58,   142,     0,     0,     0,     0,   176,     0,
     -58,   -58,     0,   143,   -57,     0,     0,     0,   -57,   -57,
     -57,   -57,     0,   -57,   -57,   -57,   -57,   143,   143,   143,
     143,     0,   143,   142,   -57,   -57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   143,   143,   143,   143,
     143,   143,   143,   143,     0,     0,     0,     0,     0,     0,
     176,   176,   176,   176,   144,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   176,   176,
     176,   176,   176,   176,   176,   176,     0,   144,   144,     0,
       0,     0,     0,   144,     0,     0,   143,   143,     0,     0,
       0,     0,     0,   143,   176,     0,     0,     0,     0,     0,
       0,   177,     0,     0,   143,   143,     0,     0,     0,   -60,
       0,   176,   176,   -60,   -60,   -60,   -60,     0,   -60,   -60,
     -60,   -60,   143,     0,     0,     0,     0,   177,     0,   -60,
     -60,     0,   144,   -33,     0,     0,     0,   -33,   -33,   -33,
     -33,     0,   -33,   -33,   -33,   -33,   144,   144,   144,   144,
       0,   144,   143,   -33,   -33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   144,   144,   144,   144,   144,
     144,   144,   144,     0,     0,     0,     0,     0,     0,   177,
     177,   177,   177,   145,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   177,   177,   177,
     177,   177,   177,   177,   177,     0,   145,   145,     0,     0,
       0,     0,   145,     0,     0,   144,   144,     0,     0,     0,
       0,     0,   144,   177,     0,     0,     0,     0,     0,     0,
     178,     0,     0,   144,   144,     0,     0,     0,   -34,     0,
     177,   177,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,
     -34,   144,     0,     0,     0,     0,   178,     0,   -34,   -34,
       0,   145,   -35,     0,     0,     0,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -35,   -35,   145,   145,   145,   145,     0,
     145,   144,   -35,   -35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   145,   145,   145,   145,   145,   145,
     145,   145,     0,     0,     0,     0,     0,     0,   178,   178,
     178,   178,     0,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   178,   178,   178,   178,   178,
     178,   178,   178,   178,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   145,     0,     0,     0,   -38,
       0,   145,   178,   -38,   -38,   -38,   -38,    85,   -38,   -38,
     -38,   -38,   145,   145,     0,     0,     0,   -38,    86,   178,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,   -26,
       0,     0,     0,     0,     0,   -26,   116,   -26,   -26,   -26,
     145,   -26,     0,     0,   -26,   -26,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,
       0,     0,     0,   -21,     0,     0,     0,     0,     0,   -21,
     -21,   -21,   -21,   -21,     0,   -21,     0,     0,   -21,   -21,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,     0,     0,     0,   -20,     0,     0,
       0,     0,     0,   -20,   -20,   -20,   -20,   -20,     0,   -20,
       0,     0,   -20,   -20,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,     0,     0,
       0,   -23,     0,     0,     0,     0,     0,   -23,   -23,   -23,
     -23,   -23,     0,   -23,     0,     0,   -23,   -23,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,   -24,     0,     0,     0,   -24,     0,     0,     0,     0,
       0,   -24,   -24,   -24,   -24,   -24,     0,   -24,     0,     0,
     -24,   -24,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,     0,     0,     0,   -25,
       0,     0,     0,     0,     0,   -25,   -25,   -25,   -25,   -25,
       0,   -25,     0,     0,   -25,   -25,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,
       0,     0,     0,   -22,     0,     0,     0,     0,     0,   -22,
     -22,   -22,   -22,   -22,     0,   -22,     0,     0,   -22,   -22,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
       0,   -13,   -13,   -13,     0,     0,     0,   -13,     0,     0,
       0,     0,     0,   -13,   -13,   -13,   -13,   -13,     0,   -13,
       0,     0,   -13,   -13,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,     0,     0,
       0,   -26,     0,     0,     0,     0,     0,   -26,   265,   -26,
     -26,   -26,     0,   -26,     0,     0,   -26,   -26,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,
     -27,   -27,     0,     0,     0,   -27,     0,     0,     0,     0,
       0,   -27,   -27,   -27,   -27,   -27,     0,   -27,     0,     0,
     -27,   -27,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,     0,     0,     0,   -28,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,   -28,
       0,   -28,     0,     0,   -28,   -28,     1,     2,     3,     4,
     123,    26,    27,    28,    29,    30,     0,    31,    32,    33,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    35,
       0,    36,    37,    38,     0,    39,     0,     0,   124,   -14,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
       0,   -19,   -19,   -19,     0,     0,     0,   -19,     0,     0,
       0,     0,     0,   -19,     0,   -19,   -19,   -19,     0,   -19,
       0,     0,   -19,   -19,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,     0,     0,
       0,   -21,     0,     0,     0,     0,     0,   -21,     0,   -21,
     -21,   -21,     0,   -21,     0,     0,   -21,   -21,     1,     2,
       3,     4,   123,    26,    27,    28,    29,    30,     0,    31,
      32,    33,     0,     0,     0,    34,     0,     0,     0,     0,
       0,    35,     0,    36,    37,    38,     0,    39,     0,     0,
     124,   -15,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,     0,   -17,   -17,   -17,     0,     0,     0,   -17,
       0,     0,     0,     0,     0,   -17,     0,   -17,   -17,   -17,
       0,   -17,     0,     0,   -17,   -17,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,
       0,     0,     0,   -18,     0,     0,     0,     0,     0,   -18,
       0,   -18,   -18,   -18,     0,   -18,     0,     0,   -18,   -18,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,     0,     0,     0,   -20,     0,     0,
       0,     0,     0,   -20,     0,   -20,   -20,   -20,     0,   -20,
       0,     0,   -20,   -20,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,     0,     0,
       0,   -23,     0,     0,     0,     0,     0,   -23,     0,   -23,
     -23,   -23,     0,   -23,     0,     0,   -23,   -23,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,   -24,     0,     0,     0,   -24,     0,     0,     0,     0,
       0,   -24,     0,   -24,   -24,   -24,     0,   -24,     0,     0,
     -24,   -24,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,     0,   -16,   -16,   -16,     0,     0,     0,   -16,
       0,     0,     0,     0,     0,   -16,     0,   -16,   -16,   -16,
       0,   -16,     0,     0,   -16,   -16,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,
       0,     0,     0,   -25,     0,     0,     0,     0,     0,   -25,
       0,   -25,   -25,   -25,     0,   -25,     0,     0,   -25,   -25,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
       0,   -22,   -22,   -22,     0,     0,     0,   -22,     0,     0,
       0,     0,     0,   -22,     0,   -22,   -22,   -22,     0,   -22,
       0,     0,   -22,   -22,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,     0,     0,
       0,   -27,     0,     0,     0,     0,     0,   -27,     0,   -27,
     -27,   -27,     0,   -27,     0,     0,   -27,   -27,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,   -28,     0,     0,     0,   -28,     0,     0,     0,     0,
       0,   -28,     0,   -28,   -28,   -28,     0,   -28,     0,     0,
     -28,   -28,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,     0,    -6,    -6,    -6,     0,     0,     0,    -6,
       0,     0,     0,     0,     0,    -6,     0,    -6,    -6,    -6,
       0,    -6,     0,     0,    -6,    -6,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,     0,   -13,   -13,   -13,
       0,     0,     0,   -13,     0,     0,     0,     0,     0,   -13,
       0,   -13,   -13,   -13,     0,   -13,   -36,     0,   -13,   -13,
     -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,     0,
       0,     0,     0,     0,   -53,     0,   -36,   -36,   -53,   -53,
     -53,   -53,     0,   -53,   -53,   -53,   -53,     0,     0,     0,
       0,     0,   -54,     0,   -53,   -53,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -54,   -54,     0,     0,     0,     0,     0,
     -55,     0,   -54,   -54,   -55,   -55,   -55,   -55,     0,   -55,
     -55,   -55,   -55,     0,     0,     0,     0,     0,   -56,     0,
     -55,   -55,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,
     -56,     0,     0,     0,     0,     0,   -37,     0,   -56,   -56,
     -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,   -37,     0,
       0,     0,     0,     0,   -49,     0,   -37,   -37,   -49,   -49,
     -49,   -49,     0,   -49,   -49,   -49,   -49,     0,     0,     0,
       0,     0,   -50,     0,   -49,   -49,   -50,   -50,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,     0,     0,     0,     0,
     -51,     0,   -50,   -50,   -51,   -51,   -51,   -51,     0,   -51,
     -51,   -51,   -51,     0,     0,     0,     0,     0,   181,     0,
     -51,   -51,   -52,   -52,   -52,   -52,     0,   -52,   -52,   -52,
     -52,     0,     0,     0,     0,     0,   -45,     0,   -52,   -52,
     -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,     0,
       0,     0,     0,     0,   181,     0,   -45,   -45,   -46,   183,
     184,   185,     0,   -46,   -46,   -46,   -46,     0,     0,     0,
       0,     0,   181,     0,   -46,   -46,   -47,   -47,   184,   185,
       0,   -47,   -47,   -47,   -47,     0,     0,     0,     0,     0,
     181,     0,   -47,   -47,   -48,   -48,   -48,   185,     0,   -48,
     -48,   -48,   -48,     0,     0,     0,     0,     0,   181,     0,
     -48,   -48,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,
     -44,     0,     0,     0,     0,     0,   181,     0,   -44,   -44,
     182,   183,   184,   185,     0,   -40,   187,   188,   189,     0,
       0,     0,     0,     0,   181,     0,   -40,   -40,   182,   183,
     184,   185,     0,   -41,   -41,   188,   189,     0,     0,     0,
       0,     0,   181,     0,   -41,   -41,   182,   183,   184,   185,
       0,   -42,   -42,   -42,   189,     0,     0,     0,     0,     0,
     181,     0,   -42,   -42,   182,   183,   184,   185,     0,   -43,
     -43,   -43,   -43,     0,     0,     0,     0,     0,   -39,     0,
     -43,   -43,   -39,   -39,   -39,   -39,     0,   -39,   -39,   -39,
     -39,     0,     0,     0,     0,     0,   181,     0,   -39,   -39,
     182,   183,   184,   185,     0,   186,   187,   188,   189,     0,
       0,     0,     0,     0,   -62,     0,   -32,   -32,   -62,   -62,
     -62,   -62,     0,   -62,   -62,   -62,   -62,     0,     0,     0,
       0,     0,   -63,     0,   -62,   -62,   -63,   -63,   -63,   -63,
       0,   -63,   -63,   -63,   -63,     0,     0,     0,     0,     0,
     -61,     0,   -63,   -63,   -61,   -61,   -61,   -61,     0,   -61,
     -61,   -61,   -61,     0,     0,     0,     0,     0,   -68,     0,
     -61,   -61,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,     0,     0,     0,     0,   -38,     0,   -68,   -68,   -38,
     -38,   -38,   -38,   207,   -38,   -38,   -38,   -38,     0,     0,
       0,     0,   149,     0,   208,   -38,   150,   151,   152,   153,
       0,   154,   155,   156,   157,     0,     0,     0,     0,   149,
       0,     0,    93,   150,   151,   152,   153,     0,   154,   155,
     156,   157,     0,     0,     0,     0,   149,     0,     0,   -31,
     150,   151,   152,   153,     0,   154,   155,   156,   157,     0,
       0,     0,     0,   -59,     0,     0,   109,   -59,   -59,   -59,
     -59,     0,   -59,   -59,   -59,   -59,     0,     0,     0,     0,
     -58,     0,     0,   -59,   -58,   -58,   -58,   -58,     0,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,   -57,     0,     0,
     -58,   -57,   -57,   -57,   -57,     0,   -57,   -57,   -57,   -57,
       0,     0,     0,     0,   -60,     0,     0,   -57,   -60,   -60,
     -60,   -60,     0,   -60,   -60,   -60,   -60,     0,     0,     0,
       0,   -33,     0,     0,   -60,   -33,   -33,   -33,   -33,     0,
     -33,   -33,   -33,   -33,     0,     0,     0,     0,   -34,     0,
       0,   -33,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,
     -34,     0,     0,     0,     0,   -35,     0,     0,   -34,   -35,
     -35,   -35,   -35,     0,   -35,   -35,   -35,   -35,     0,     0,
       0,     0,   -36,     0,     0,   -35,   -36,   -36,   -36,   -36,
       0,   -36,   -36,   -36,   -36,     0,     0,     0,     0,   -53,
       0,     0,   -36,   -53,   -53,   -53,   -53,     0,   -53,   -53,
     -53,   -53,     0,     0,     0,     0,   -54,     0,     0,   -53,
     -54,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,     0,
       0,     0,     0,   -55,     0,     0,   -54,   -55,   -55,   -55,
     -55,     0,   -55,   -55,   -55,   -55,     0,     0,     0,     0,
     -56,     0,     0,   -55,   -56,   -56,   -56,   -56,     0,   -56,
     -56,   -56,   -56,     0,     0,     0,     0,   -37,     0,     0,
     -56,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,   -37,
       0,     0,     0,     0,   -49,     0,     0,   -37,   -49,   -49,
     -49,   -49,     0,   -49,   -49,   -49,   -49,     0,     0,     0,
       0,   -50,     0,     0,   -49,   -50,   -50,   -50,   -50,     0,
     -50,   -50,   -50,   -50,     0,     0,     0,     0,   -51,     0,
       0,   -50,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,
     -51,     0,     0,     0,     0,   149,     0,     0,   -51,   -52,
     -52,   -52,   -52,     0,   -52,   -52,   -52,   -52,     0,     0,
       0,     0,   149,     0,     0,   -52,   150,   151,   152,   153,
       0,   154,   155,   156,   157,     0,     0,     0,     0,   -45,
       0,     0,   244,   -45,   -45,   -45,   -45,     0,   -45,   -45,
     -45,   -45,     0,     0,     0,     0,   149,     0,     0,   -45,
     -46,   151,   152,   153,     0,   -46,   -46,   -46,   -46,     0,
       0,     0,     0,   149,     0,     0,   -46,   -47,   -47,   152,
     153,     0,   -47,   -47,   -47,   -47,     0,     0,     0,     0,
     149,     0,     0,   -47,   -48,   -48,   -48,   153,     0,   -48,
     -48,   -48,   -48,     0,     0,     0,     0,   149,     0,     0,
     -48,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
       0,     0,     0,     0,   149,     0,     0,   -44,   150,   151,
     152,   153,     0,   -40,   155,   156,   157,     0,     0,     0,
       0,   149,     0,     0,   -40,   150,   151,   152,   153,     0,
     -41,   -41,   156,   157,     0,     0,     0,     0,   149,     0,
       0,   -41,   150,   151,   152,   153,     0,   -42,   -42,   -42,
     157,     0,     0,     0,     0,   149,     0,     0,   -42,   150,
     151,   152,   153,     0,   -43,   -43,   -43,   -43,     0,     0,
       0,     0,   149,     0,     0,   -43,   150,   151,   152,   153,
       0,   154,   155,   156,   157,     0,     0,     0,     0,   -39,
       0,     0,   249,   -39,   -39,   -39,   -39,     0,   -39,   -39,
     -39,   -39,     0,     0,     0,     0,   149,     0,     0,   -39,
     150,   151,   152,   153,     0,   154,   155,   156,   157,     0,
       0,     0,     0,   149,     0,     0,   -32,   150,   151,   152,
     153,     0,   154,   155,   156,   157,     0,     0,     0,     0,
     -62,     0,     0,   261,   -62,   -62,   -62,   -62,     0,   -62,
     -62,   -62,   -62,     0,     0,     0,     0,   -63,     0,     0,
     -62,   -63,   -63,   -63,   -63,     0,   -63,   -63,   -63,   -63,
       0,     0,     0,     0,   -61,     0,     0,   -63,   -61,   -61,
     -61,   -61,     0,   -61,   -61,   -61,   -61,     0,     0,     0,
       0,   -68,     0,     0,   -61,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,     0,     0,     0,   -59,     0,   -68,
     -68,   -59,   -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,
       0,     0,   -58,     0,     0,   -59,   -58,   -58,   -58,   -58,
       0,   -58,   -58,   -58,   -58,     0,     0,   -57,     0,     0,
     -58,   -57,   -57,   -57,   -57,     0,   -57,   -57,   -57,   -57,
       0,     0,   -60,     0,     0,   -57,   -60,   -60,   -60,   -60,
       0,   -60,   -60,   -60,   -60,     0,     0,    75,     0,     0,
     -60,    76,    77,    78,    79,     0,    80,    81,    82,    83,
       0,     0,   -33,     0,     0,    84,   -33,   -33,   -33,   -33,
       0,   -33,   -33,   -33,   -33,     0,     0,   -34,     0,     0,
     -33,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,   -34,
       0,     0,   -35,     0,     0,   -34,   -35,   -35,   -35,   -35,
       0,   -35,   -35,   -35,   -35,     0,     0,   -36,     0,     0,
     -35,   -36,   -36,   -36,   -36,     0,   -36,   -36,   -36,   -36,
       0,     0,   -53,     0,     0,   -36,   -53,   -53,   -53,   -53,
       0,   -53,   -53,   -53,   -53,     0,     0,   -54,     0,     0,
     -53,   -54,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,
       0,     0,   -55,     0,     0,   -54,   -55,   -55,   -55,   -55,
       0,   -55,   -55,   -55,   -55,     0,     0,   -56,     0,     0,
     -55,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,
       0,     0,   -37,     0,     0,   -56,   -37,   -37,   -37,   -37,
       0,   -37,   -37,   -37,   -37,     0,     0,   -49,     0,     0,
     -37,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,
       0,     0,   -50,     0,     0,   -49,   -50,   -50,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,     0,   -51,     0,     0,
     -50,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,
       0,     0,    75,     0,     0,   -51,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   -52,   -52,     0,     0,    75,     0,     0,
     -52,    76,    77,    78,    79,     0,    80,    81,    82,    83,
       0,     0,   -39,     0,     0,   -29,   -39,   -39,   -39,   -39,
       0,   -39,   -39,   -39,   -39,     0,     0,   -45,     0,     0,
     -39,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,
       0,     0,    75,     0,     0,   -45,   -46,    77,    78,    79,
       0,   -46,   -46,   -46,   -46,     0,     0,    75,     0,     0,
     -46,   -47,   -47,    78,    79,     0,   -47,   -47,   -47,   -47,
       0,     0,    75,     0,     0,   -47,   -48,   -48,   -48,    79,
       0,   -48,   -48,   -48,   -48,     0,     0,    75,     0,     0,
     -48,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
       0,     0,    75,     0,     0,   -44,    76,    77,    78,    79,
       0,   -40,    81,    82,    83,     0,     0,    75,     0,     0,
     -40,    76,    77,    78,    79,     0,   -41,   -41,    82,    83,
       0,     0,    75,     0,     0,   -41,    76,    77,    78,    79,
       0,   -42,   -42,   -42,    83,     0,     0,    75,     0,     0,
     -42,    76,    77,    78,    79,     0,   -43,   -43,   -43,   -43,
       0,     0,    75,     0,     0,   -43,    76,    77,    78,    79,
       0,    80,    81,    82,    83,     0,     0,   -62,     0,     0,
     -32,   -62,   -62,   -62,   -62,     0,   -62,   -62,   -62,   -62,
       0,     0,   -63,     0,     0,   -62,   -63,   -63,   -63,   -63,
       0,   -63,   -63,   -63,   -63,     0,     0,   -61,     0,     0,
     -63,   -61,   -61,   -61,   -61,     0,   -61,   -61,   -61,   -61,
       0,     0,    75,     0,     0,   -61,    76,    77,    78,    79,
       0,    80,    81,    82,    83,     0,     0,    75,     0,     0,
     -31,    76,    77,    78,    79,     0,    80,    81,    82,    83,
       0,     0,     0,     0,     0,   240
};

static const yytype_int16 yycheck[] =
{
       9,    20,   124,     3,     4,     5,     6,   109,    31,    32,
      19,     7,     0,   208,   116,    33,    13,     5,   120,    35,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   109,
      39,   226,    63,    33,   109,    32,    33,    34,    69,    31,
      32,   109,     0,     7,   109,     3,     4,     5,     6,    33,
      34,     0,    61,    62,    63,     7,     5,    33,    34,    68,
       7,     8,     9,    10,    11,    12,    15,    14,    15,    16,
     192,     7,    21,    20,    33,    34,     7,    86,     7,   110,
      33,    34,    32,    30,    31,    32,   117,    33,    34,    32,
     109,     7,     8,     9,    10,    11,    12,    32,    14,    15,
      16,    33,    34,   112,    20,    32,    36,    31,   117,     7,
      26,    31,    28,    29,    30,    33,    32,    31,    33,    35,
      33,    31,   131,   132,   133,   134,     0,   136,    33,     3,
       4,     5,     6,     0,    36,    32,     3,     4,     5,     6,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     3,
       4,     5,     6,    32,    31,   164,   165,   166,   167,   261,
     169,    32,    32,   265,    32,     5,    32,   269,    31,   200,
     201,    36,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   261,    33,    33,    33,   265,   261,   218,   219,   269,
     265,   200,   201,   261,   269,    33,   261,   265,   207,   208,
     265,   269,    33,    33,   269,    31,   237,    31,    33,   218,
     219,    21,    -1,    -1,    23,     0,   225,   226,     3,     4,
       5,     6,    31,    32,    33,    34,    43,   236,    37,    -1,
      39,   262,    -1,     0,    43,   266,     3,     4,     5,     6,
      -1,    -1,   261,    -1,    -1,    -1,   265,    -1,     0,    -1,
     269,     3,     4,     5,     6,    -1,    -1,   266,     0,    68,
      69,     3,     4,     5,     6,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    -1,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
       0,    -1,    20,     3,     4,     5,     6,    -1,    -1,    -1,
     109,   110,    30,   112,    32,    33,    -1,   116,    -1,    -1,
      -1,   120,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,    -1,   192,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    62,    63,    -1,    20,   207,   208,
      68,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    -1,    -1,    -1,   225,   226,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,   112,    20,    -1,    -1,    -1,   117,
      -1,    -1,   261,   262,    -1,    30,   265,    32,    33,    -1,
     269,    -1,    -1,   131,   132,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,   155,   156,   157,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,
      39,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,    -1,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,   200,   201,    -1,    -1,    -1,    -1,    -1,   207,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
     218,   219,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,     7,     8,     9,    10,    11,    12,   236,    14,
      15,    16,    -1,   112,    -1,    20,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,   131,   132,   133,   134,    -1,   136,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    39,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,   182,   183,   184,   185,   186,   187,   188,
     189,    -1,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,
      -1,   200,   201,    -1,    -1,    -1,    -1,    -1,   207,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,   218,
     219,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,     7,     8,     9,    10,    11,    12,   236,    14,    15,
      16,    -1,   112,    -1,    20,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,
      -1,   131,   132,   133,   134,    -1,   136,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    39,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,   184,   185,   186,   187,   188,   189,
      -1,    62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,
     200,   201,    -1,    -1,    -1,    -1,    -1,   207,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,   218,   219,
      -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,   236,    14,    15,    16,
      -1,   112,    -1,    20,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
     131,   132,   133,   134,    -1,   136,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,    -1,    -1,   164,   165,   166,   167,    39,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,   184,   185,   186,   187,   188,   189,    -1,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,   200,
     201,    -1,    -1,    -1,    -1,    -1,   207,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,   218,   219,    -1,
      -1,    -1,    13,    -1,   225,   226,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   236,    -1,    -1,    -1,    -1,
     112,    32,    33,    34,    -1,   117,    13,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,   131,
     132,   133,   134,    -1,   136,   266,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   165,   166,   167,    39,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,    -1,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,   200,   201,
      -1,    -1,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,   218,   219,    -1,    -1,
      -1,    13,    -1,   225,   226,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,   236,    -1,    -1,    -1,    -1,   112,
      -1,    33,    34,    -1,   117,    13,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,   131,   132,
     133,   134,    -1,   136,   266,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,
      -1,   164,   165,   166,   167,    39,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,   184,   185,   186,   187,   188,   189,    -1,    62,    63,
      -1,    -1,    -1,    -1,    68,    -1,    -1,   200,   201,    -1,
      -1,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,   218,   219,    -1,    -1,    -1,
      13,    -1,   225,   226,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,   236,    -1,    -1,    -1,    -1,   112,    -1,
      33,    34,    -1,   117,    13,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,   131,   132,   133,
     134,    -1,   136,   266,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   165,   166,   167,    39,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
     184,   185,   186,   187,   188,   189,    -1,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,   200,   201,    -1,    -1,
      -1,    -1,    -1,   207,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,   218,   219,    -1,    -1,    -1,    13,
      -1,   225,   226,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,   236,    -1,    -1,    -1,    -1,   112,    -1,    33,
      34,    -1,   117,    13,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,   131,   132,   133,   134,
      -1,   136,   266,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,
     165,   166,   167,    39,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,   184,
     185,   186,   187,   188,   189,    -1,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,   200,   201,    -1,    -1,    -1,
      -1,    -1,   207,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,   218,   219,    -1,    -1,    -1,    13,    -1,
     225,   226,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,   236,    -1,    -1,    -1,    -1,   112,    -1,    33,    34,
      -1,   117,    13,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,   131,   132,   133,   134,    -1,
     136,   266,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,   184,   185,
     186,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,    -1,    -1,    -1,    13,
      -1,   207,   208,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   218,   219,    -1,    -1,    -1,    31,    32,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
     266,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    32,    13,    -1,    35,    36,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    33,    34,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    33,    34,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    33,    34,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      33,    34,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    13,    -1,    33,    34,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    33,    34,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    33,    34,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    33,    34,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      33,    34,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    13,    -1,    33,    34,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    33,    34,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    33,    34,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    33,    34,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      33,    34,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    13,    -1,    33,    34,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    33,    34,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    33,    34,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    33,    34,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      33,    34,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    13,    -1,    33,    34,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    33,    34,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    33,    34,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    33,    34,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      33,    34,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    32,    33,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    32,    33,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    33,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    33,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    33,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    33,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    33,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    33,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,
      18,    19,    20,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    33,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    13,    -1,    31,
      32,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      -1,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    38,    39,    40,    41,    68,
       0,    39,     7,    67,    31,    32,    42,    43,    44,    68,
      33,    34,    67,    35,    45,    44,     8,     9,    10,    11,
      12,    14,    15,    16,    20,    26,    28,    29,    30,    32,
      40,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      67,    68,    32,    32,    55,    55,    55,    55,    32,    32,
      55,    55,    36,    48,    31,    13,    17,    18,    19,    20,
      22,    23,    24,    25,    31,    21,    32,    67,    54,    55,
      54,    55,    54,    33,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    65,    66,    33,    33,    33,
      31,    33,    34,    49,    54,    55,    27,    31,    49,    54,
      33,    49,     7,     7,    35,     7,     8,     9,    10,    11,
      12,    14,    15,    16,    20,    30,    32,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    67,     7,    55,    13,
      17,    18,    19,    20,    22,    23,    24,    25,     7,     8,
       9,    10,    11,    12,    14,    15,    16,    20,    30,    32,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    67,
      31,    13,    17,    18,    19,    20,    22,    23,    24,    25,
      26,    28,    35,    45,    50,    51,    52,    53,    55,    46,
      32,    32,    55,    55,    55,    55,    55,    21,    32,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    32,    32,
      55,    55,    55,    55,    55,    21,    32,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    32,    32,    46,    31,
      31,    36,    54,    54,    33,    55,    65,    54,    54,    33,
      55,    65,    55,    54,    36,    33,    33,    33,    33,    33,
      33,    33,    31,    49,    54,    27,    31,    49,    54,    33,
      49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    41,    42,    42,
      43,    43,    44,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    49,    50,    50,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    59,    60,    61,    62,
      63,    64,    64,    64,    65,    65,    66,    66,    67,    68,
      68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     6,     0,     1,
       3,     1,     2,     3,     0,     1,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     5,     7,     9,     2,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     0,     1,     3,     1,     1,     1,
       1,     1,     1
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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_INT_TOKEN: /* INT_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2063 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2071 "bison.tab.c"
        break;

    case YYSYMBOL_INT_LIST_TOKEN: /* INT_LIST_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2079 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_LIST_TOKEN: /* FLOAT_LIST_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2087 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2095 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2103 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2111 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2119 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2127 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2135 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2143 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2151 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2159 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2167 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2175 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2183 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2191 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2199 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2207 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2215 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2223 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2231 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2239 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2247 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2255 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2263 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2271 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2279 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2287 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2295 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2303 "bison.tab.c"
        break;

    case YYSYMBOL_constantString: /* constantString  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2311 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2319 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2327 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 82 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2335 "bison.tab.c"
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* startProgram: startProgram declaration  */
#line 89 "./src/bison.y"
                             {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 2608 "bison.tab.c"
    break;

  case 3: /* startProgram: declaration  */
#line 92 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 2616 "bison.tab.c"
    break;

  case 4: /* declaration: variableDeclare  */
#line 98 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 2624 "bison.tab.c"
    break;

  case 5: /* declaration: functionDeclare  */
#line 101 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 2632 "bison.tab.c"
    break;

  case 6: /* variableDeclare: type id ';'  */
#line 107 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_VAR_DECLARE, "variable declare");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 2642 "bison.tab.c"
    break;

  case 7: /* functionDeclare: type id '(' optListParams ')' compoundStatement  */
#line 115 "./src/bison.y"
                                                    {
        /* Lidar com contextos */
        (yyval.astnode) = create_astnode_context(AST_FUNC_DECLARE, "func declare");
        insert_kid((yyvsp[-5].astnode), (yyval.astnode));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
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
#line 2666 "bison.tab.c"
    break;

  case 8: /* optListParams: %empty  */
#line 137 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 2674 "bison.tab.c"
    break;

  case 10: /* listParams: listParams ',' param  */
#line 144 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 2683 "bison.tab.c"
    break;

  case 11: /* listParams: param  */
#line 148 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 2692 "bison.tab.c"
    break;

  case 12: /* param: type id  */
#line 155 "./src/bison.y"
            {
        (yyval.astnode) = create_astnode_context(AST_PARAM, "param");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2702 "bison.tab.c"
    break;

  case 13: /* compoundStatement: '{' optListCodeBlock '}'  */
#line 164 "./src/bison.y"
                             {
        // printf("CompoundStatement\n");
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
    }
#line 2723 "bison.tab.c"
    break;

  case 14: /* optListCodeBlock: %empty  */
#line 183 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 2731 "bison.tab.c"
    break;

  case 16: /* listCodeBlock: listCodeBlock codeBlock  */
#line 190 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 2740 "bison.tab.c"
    break;

  case 17: /* listCodeBlock: codeBlock  */
#line 194 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 2749 "bison.tab.c"
    break;

  case 18: /* codeBlock: statement  */
#line 201 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2758 "bison.tab.c"
    break;

  case 19: /* codeBlock: variableDeclare  */
#line 205 "./src/bison.y"
                      {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2767 "bison.tab.c"
    break;

  case 20: /* statement: flowExpression  */
#line 212 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2776 "bison.tab.c"
    break;

  case 21: /* statement: compoundStatement  */
#line 216 "./src/bison.y"
                        {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2785 "bison.tab.c"
    break;

  case 22: /* statement: expression ';'  */
#line 220 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 2794 "bison.tab.c"
    break;

  case 23: /* flowExpression: condExpression  */
#line 227 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 2802 "bison.tab.c"
    break;

  case 24: /* flowExpression: interationExpression  */
#line 230 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 2810 "bison.tab.c"
    break;

  case 25: /* flowExpression: returnExpression ';'  */
#line 233 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 2818 "bison.tab.c"
    break;

  case 26: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 239 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2828 "bison.tab.c"
    break;

  case 27: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 244 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2839 "bison.tab.c"
    break;

  case 28: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 253 "./src/bison.y"
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
#line 2854 "bison.tab.c"
    break;

  case 29: /* returnExpression: RETURN_TOKEN expression  */
#line 266 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return expression");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2863 "bison.tab.c"
    break;

  case 30: /* optExpression: %empty  */
#line 273 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 2871 "bison.tab.c"
    break;

  case 31: /* optExpression: expression  */
#line 276 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 2879 "bison.tab.c"
    break;

  case 32: /* expression: id ASSIGN_TOKEN expression  */
#line 282 "./src/bison.y"
                               {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2889 "bison.tab.c"
    break;

  case 33: /* expression: binArith  */
#line 287 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2898 "bison.tab.c"
    break;

  case 34: /* expression: listArith  */
#line 291 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2907 "bison.tab.c"
    break;

  case 35: /* expression: unaArith  */
#line 295 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2916 "bison.tab.c"
    break;

  case 36: /* expression: constant  */
#line 299 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2925 "bison.tab.c"
    break;

  case 37: /* expression: funcCall  */
#line 303 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2934 "bison.tab.c"
    break;

  case 38: /* expression: id  */
#line 307 "./src/bison.y"
         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2943 "bison.tab.c"
    break;

  case 39: /* expression: '(' expression ')'  */
#line 311 "./src/bison.y"
                         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 2952 "bison.tab.c"
    break;

  case 40: /* binArith: expression OR_TOKEN expression  */
#line 318 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria or");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2962 "bison.tab.c"
    break;

  case 41: /* binArith: expression AND_TOKEN expression  */
#line 323 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria and");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2972 "bison.tab.c"
    break;

  case 42: /* binArith: expression EQ_EXC_TOKEN expression  */
#line 328 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria ==!");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2982 "bison.tab.c"
    break;

  case 43: /* binArith: expression LE_GR_TOKEN expression  */
#line 333 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria <>");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 2992 "bison.tab.c"
    break;

  case 44: /* binArith: expression ADD_MIN_TOKEN expression  */
#line 338 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria +-");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3002 "bison.tab.c"
    break;

  case 45: /* binArith: expression MUL_DIV_TOKEN expression  */
#line 343 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "aritmetica binaria */");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3012 "bison.tab.c"
    break;

  case 46: /* listArith: expression MAP_TOKEN expression  */
#line 351 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "aritmetica binaria de lista map");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3022 "bison.tab.c"
    break;

  case 47: /* listArith: expression FILTER_TOKEN expression  */
#line 356 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "aritmetica binaria de lista filter");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3032 "bison.tab.c"
    break;

  case 48: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 361 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "aritmetica binaria de lista constructor");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3042 "bison.tab.c"
    break;

  case 49: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 369 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria !");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3051 "bison.tab.c"
    break;

  case 50: /* unaArith: QUESTION_TOKEN expression  */
#line 373 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria ?");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3060 "bison.tab.c"
    break;

  case 51: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 377 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria %");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3069 "bison.tab.c"
    break;

  case 52: /* unaArith: ADD_MIN_TOKEN expression  */
#line 381 "./src/bison.y"
                               {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "aritmetica unaria +-");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3078 "bison.tab.c"
    break;

  case 53: /* constant: constantInteger  */
#line 388 "./src/bison.y"
                    {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant int");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3087 "bison.tab.c"
    break;

  case 54: /* constant: constantReal  */
#line 392 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant real");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3096 "bison.tab.c"
    break;

  case 55: /* constant: constantNIL  */
#line 396 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant nil");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3105 "bison.tab.c"
    break;

  case 56: /* constant: constantString  */
#line 400 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant string");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3114 "bison.tab.c"
    break;

  case 57: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 407 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3122 "bison.tab.c"
    break;

  case 58: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 413 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3130 "bison.tab.c"
    break;

  case 59: /* constantNIL: NIL_TOKEN  */
#line 419 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3138 "bison.tab.c"
    break;

  case 60: /* constantString: STRING_TOKEN  */
#line 425 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3146 "bison.tab.c"
    break;

  case 61: /* funcCall: id '(' optListExpression ')'  */
#line 431 "./src/bison.y"
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
#line 3165 "bison.tab.c"
    break;

  case 62: /* funcCall: READ_TOKEN '(' optExpression ')'  */
#line 445 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        if((yyvsp[-1].astnode))
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3176 "bison.tab.c"
    break;

  case 63: /* funcCall: WRITE_TOKEN '(' optExpression ')'  */
#line 451 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        if((yyvsp[-1].astnode))
            insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3187 "bison.tab.c"
    break;

  case 64: /* optListExpression: %empty  */
#line 460 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3195 "bison.tab.c"
    break;

  case 66: /* listExpression: listExpression ',' expression  */
#line 467 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 3204 "bison.tab.c"
    break;

  case 67: /* listExpression: expression  */
#line 471 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3213 "bison.tab.c"
    break;

  case 68: /* id: ID_TOKEN  */
#line 478 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3221 "bison.tab.c"
    break;

  case 69: /* type: INT_TOKEN  */
#line 484 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3229 "bison.tab.c"
    break;

  case 70: /* type: FLOAT_TOKEN  */
#line 487 "./src/bison.y"
                  {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3237 "bison.tab.c"
    break;

  case 71: /* type: INT_LIST_TOKEN  */
#line 490 "./src/bison.y"
                     {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3245 "bison.tab.c"
    break;

  case 72: /* type: FLOAT_LIST_TOKEN  */
#line 493 "./src/bison.y"
                       {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3253 "bison.tab.c"
    break;


#line 3257 "bison.tab.c"

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
          = {yyssp, yytoken};
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

#line 498 "./src/bison.y"


void yyerror(const char *error_msg){
    error++;
    printf("Line: %d || Column: %d || ", num_line, num_col);
    printf("Error: %s || Error count: %d \n", error_msg, error);
}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Error: It is necessary to inform the file path\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp){
        printf("Error: Unable to open file\n");
        return 0;
    }

    yyin = fp;
    root = create_astnode_context(AST_ROOT, "root");
    node_aux = create_list();
    yyparse();
    print_tree(root, 0);
    // print_list(node_aux);
    printf("Tamanho lista: %d\n", node_aux->size);
    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
