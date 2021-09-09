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


#line 94 "bison.tab.c"

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
  YYSYMBOL_funcCall = 63,                  /* funcCall  */
  YYSYMBOL_id = 64,                        /* id  */
  YYSYMBOL_type = 65                       /* type  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   2685

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

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
       0,    73,    73,    76,    82,    83,    87,    96,   111,   114,
     126,   127,   131,   144,   153,   156,   165,   166,   170,   176,
     184,   188,   193,   200,   201,   202,   206,   207,   211,   215,
     219,   220,   224,   225,   226,   227,   228,   229,   230,   234,
     235,   236,   237,   238,   239,   240,   244,   245,   246,   250,
     251,   252,   253,   257,   258,   259,   263,   270,   277,   283,
     287,   291,   294,   300,   305,   309,   313
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_TOKEN",
  "FLOAT_TOKEN", "INT_LIST_TOKEN", "FLOAT_LIST_TOKEN", "ID_TOKEN",
  "READ_TOKEN", "WRITE_TOKEN", "NIL_TOKEN", "CONSTANT_REAL_TOKEN",
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
  "constantInteger", "constantReal", "constantNIL", "funcCall", "id",
  "type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
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

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    27,    33,    84,   134,    48,    72,   106,   231,   137,
    -116,   244,   -27,    -5,    53,    56,   297,    13,   -26,    11,
      94,   148,   -21,    18,   118,  1083,   313,   149,  2204,  2219,
    2234,   509,   509,   509,   509,     0,     6,   509,   583,  1117,
    1151,    31,  1185,  1219,  1253,  1287,  1321,  1355,    16,  2249,
    2264,  2279,  2294,  2309,  2324,  2339,  2354,  2369,  2140,   168,
    2384,  2399,  2414,  2429,   583,   451,  2444,   358,   320,  1389,
    1423,   509,   509,   509,   509,   509,   509,   509,   509,   509,
     509,  1457,   152,    25,   661,    40,  2459,  2474,  2489,  2504,
    2519,  2534,  2549,  2564,  2579,  2594,  2609,  2624,    66,   410,
     451,  2639,    54,    82,   542,   152,  1491,    70,   542,  1525,
     185,   194,   218,  2156,  2172,  2188,  1083,   255,   638,  1613,
     724,  1647,  1664,   583,   583,   583,   583,   583,  1681,  1698,
    1715,  1732,  1749,  1766,  1783,  1800,  1630,    89,    93,   140,
     583,   583,   583,   583,   583,   583,   583,   583,   583,   583,
    1817,  1559,    17,   133,  1083,   197,   777,   811,   845,   142,
    2654,   143,  1834,  1851,  1868,  1885,  1902,   152,  1919,  1936,
    1953,  1970,  1987,  2004,  2021,  2038,  2055,  2072,   583,   451,
     161,   879,   913,  1593,  2089,   166,  2106,   179,   947,  2123,
     410,   451,   981,   183,   410,   152,  1015,   187,   410,  1049
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   225,     8,  -116,  -116,  -116,   199,   -20,  -115,
    -116,   196,   -93,   -96,   -90,   -69,   -68,   -72,   116,   207,
     217,   308,   365,   440,   497,   572,   629,    -9,    20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    39,     8,    18,    19,    20,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    85,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,   161,    26,   156,   -60,   -60,   102,    22,     7,   157,
      98,   106,    24,     7,    25,   109,     1,     2,     3,     4,
       9,     1,     2,     3,     4,     9,   -61,   -61,   103,   136,
     158,   159,    64,   107,   -63,   -63,   -63,    21,    65,   180,
     -64,   -64,   -64,    21,    -9,    23,    -8,    70,    10,   178,
      83,     1,     2,     3,     4,   136,   151,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,    68,   -26,   -26,
     -26,   100,    -3,   136,   -26,    -3,    -3,    -3,    -3,   155,
     -26,   104,   -26,   -26,   -62,   -62,   -26,    16,    17,   -26,
     -26,   -65,   -65,   -65,   156,   185,   136,   192,   156,   101,
     157,   196,   156,   108,   157,   199,    -4,   187,   157,    -4,
      -4,    -4,    -4,   105,   136,   136,   136,   136,   136,   193,
     -60,   158,   159,   197,   -61,   158,   159,   -11,   -11,   158,
     159,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   -66,   -66,   -66,    12,    13,    14,    60,    61,    62,
      63,   -12,   -12,    66,    67,   110,   111,   112,   136,   117,
     118,   119,   120,   121,   122,   179,   123,   124,   125,   136,
     155,   -62,   126,   181,   155,   137,   138,   139,   155,   183,
      84,    86,   -10,   -10,   127,   -30,   136,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,   188,   150,   189,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     191,   -21,   -21,   -21,   195,   160,    86,   -21,   -60,   -60,
     198,   150,    27,   -21,   -21,   -21,   -21,   -61,   -61,   -21,
      11,    -5,   -21,   -21,    -5,    -5,    -5,    -5,    69,   162,
     163,   164,   165,   166,    -2,   128,     0,    -2,    -2,    -2,
      -2,   -62,   -62,     0,     0,   129,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,     0,   -60,     0,
       0,   128,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   129,     0,   150,     0,     0,     0,   -60,   -60,   128,
       0,     0,     0,     0,   186,    86,     0,    -6,     0,   129,
      -6,    -6,    -6,    -6,     0,     0,   160,    86,     0,     0,
     160,   150,   128,    -7,   160,     0,    -7,    -7,    -7,    -7,
     -13,     0,   129,   -13,   -13,   -13,   -13,     0,     0,     0,
     128,   128,   128,   128,   128,     0,     0,     0,     0,     0,
     129,   129,   129,   129,   129,     0,   130,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,     0,     0,     0,
       0,   140,   130,     0,   128,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   129,   128,     0,     0,     0,     0,
     130,    87,     0,     0,     0,   129,     0,     0,     0,     0,
       0,     0,   128,   131,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,     0,     0,     0,   113,   114,   115,
      28,    29,    30,     0,    31,    32,    33,     0,     0,   131,
      34,   130,   130,   130,   130,   130,   152,     0,   153,    37,
       0,     0,    38,     0,     0,   154,     0,   131,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   113,   114,
     115,    28,    29,    30,     0,    31,    32,    33,     0,     0,
     131,    34,     0,     0,     0,   130,     0,     0,   132,     0,
       0,     0,   -30,    38,     0,     0,   130,     0,   131,   131,
     131,   131,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   132,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,     0,   113,   114,   115,    28,
      29,    30,   132,    31,    32,    33,     0,     0,     0,    34,
       0,     0,   131,     0,     0,   133,     0,     0,     0,     0,
       0,    38,     0,   131,     0,   132,     0,     0,     0,   113,
     114,   115,    28,    29,    30,     0,    31,    32,    33,     0,
     131,   133,    34,   132,   132,   132,   132,   132,    35,     0,
      36,    37,     0,     0,    38,     0,     0,   116,     0,   133,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     117,   118,   119,   120,   121,   122,     0,   123,   124,   125,
       0,     0,   133,   126,     0,     0,     0,   132,     0,     0,
     134,     0,     0,     0,     0,   127,     0,     0,   132,     0,
     133,   133,   133,   133,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   134,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,     0,     0,     0,
       0,   -61,     0,     0,   134,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   133,     0,     0,   135,     0,     0,
     -61,   -61,     0,     0,   140,   133,     0,   134,   141,   142,
     143,   144,   145,   146,   147,   148,   149,     0,     0,     0,
       0,     0,   133,   135,    99,   134,   134,   134,   134,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,   -58,     0,   134,
       0,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     134,     0,   135,   135,   135,   135,   135,   -58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,     0,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,     0,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,     0,     0,   135,   -20,     0,     0,
       0,     0,     0,   -20,   -20,   -20,   -20,   135,     0,   -20,
       0,     0,   -20,   -20,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   135,   -23,   -23,   -23,     0,     0,
       0,   -23,     0,     0,     0,     0,     0,   -23,   -23,   -23,
     -23,     0,     0,   -23,     0,     0,   -23,   -23,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,   -24,     0,     0,     0,   -24,     0,     0,     0,     0,
       0,   -24,   -24,   -24,   -24,     0,     0,   -24,     0,     0,
     -24,   -24,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,     0,     0,     0,   -25,
       0,     0,     0,     0,     0,   -25,   -25,   -25,   -25,     0,
       0,   -25,     0,     0,   -25,   -25,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,
       0,     0,     0,   -22,     0,     0,     0,     0,     0,   -22,
     -22,   -22,   -22,     0,     0,   -22,     0,     0,   -22,   -22,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
       0,   -13,   -13,   -13,     0,     0,     0,   -13,     0,     0,
       0,     0,     0,   -13,   -13,   -13,   -13,     0,     0,   -13,
       0,     0,   -13,   -13,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,     0,     0,
       0,   -26,     0,     0,     0,     0,     0,   -26,   194,   -26,
     -26,     0,     0,   -26,     0,     0,   -26,   -26,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,
     -27,   -27,     0,     0,     0,   -27,     0,     0,     0,     0,
       0,   -27,   -27,   -27,   -27,     0,     0,   -27,     0,     0,
     -27,   -27,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,     0,     0,     0,   -28,
       0,     0,     0,     0,     0,   -28,   -28,   -28,   -28,     0,
       0,   -28,     0,     0,   -28,   -28,     1,     2,     3,     4,
     113,   114,   115,    28,    29,    30,     0,    31,    32,    33,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    35,
       0,    36,    37,     0,     0,    38,     0,     0,   116,   -14,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
       0,   -19,   -19,   -19,     0,     0,     0,   -19,     0,     0,
       0,     0,     0,   -19,     0,   -19,   -19,     0,     0,   -19,
       0,     0,   -19,   -19,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,     0,     0,
       0,   -21,     0,     0,     0,     0,     0,   -21,     0,   -21,
     -21,     0,     0,   -21,     0,     0,   -21,   -21,     1,     2,
       3,     4,   113,   114,   115,    28,    29,    30,     0,    31,
      32,    33,     0,     0,     0,    34,     0,     0,     0,     0,
       0,    35,     0,    36,    37,     0,     0,    38,     0,     0,
     116,   -15,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,     0,   -17,   -17,   -17,     0,     0,     0,   -17,
       0,     0,     0,     0,     0,   -17,     0,   -17,   -17,     0,
       0,   -17,     0,     0,   -17,   -17,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,
       0,     0,     0,   -18,     0,     0,     0,     0,     0,   -18,
       0,   -18,   -18,     0,     0,   -18,     0,     0,   -18,   -18,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,     0,     0,     0,   -20,     0,     0,
       0,     0,     0,   -20,     0,   -20,   -20,     0,     0,   -20,
       0,     0,   -20,   -20,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,     0,     0,
       0,   -23,     0,     0,     0,     0,     0,   -23,     0,   -23,
     -23,     0,     0,   -23,     0,     0,   -23,   -23,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,   -24,     0,     0,     0,   -24,     0,     0,     0,     0,
       0,   -24,     0,   -24,   -24,     0,     0,   -24,     0,     0,
     -24,   -24,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,     0,   -16,   -16,   -16,     0,     0,     0,   -16,
       0,     0,     0,     0,     0,   -16,     0,   -16,   -16,     0,
       0,   -16,     0,     0,   -16,   -16,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,
       0,     0,     0,   -25,     0,     0,     0,     0,     0,   -25,
       0,   -25,   -25,     0,     0,   -25,     0,     0,   -25,   -25,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
       0,   -22,   -22,   -22,     0,     0,     0,   -22,     0,     0,
       0,     0,     0,   -22,     0,   -22,   -22,     0,     0,   -22,
       0,     0,   -22,   -22,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,     0,     0,
       0,   -27,     0,     0,     0,     0,     0,   -27,     0,   -27,
     -27,     0,     0,   -27,     0,     0,   -27,   -27,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,   -28,     0,     0,     0,   -28,     0,     0,     0,     0,
       0,   -28,     0,   -28,   -28,     0,     0,   -28,     0,     0,
     -28,   -28,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,     0,    -6,    -6,    -6,     0,     0,     0,    -6,
       0,     0,     0,     0,     0,    -6,     0,    -6,    -6,     0,
       0,    -6,     0,     0,    -6,    -6,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,     0,   -13,   -13,   -13,
       0,     0,     0,   -13,     0,     0,     0,     0,     0,   -13,
       0,   -13,   -13,     0,     0,   -13,   -62,     0,   -13,   -13,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,     0,
       0,     0,     0,   -37,     0,   -62,   -62,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,     0,
     -57,     0,   167,   -37,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,     0,     0,   -56,     0,     0,
     -57,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
       0,     0,     0,     0,   -32,     0,     0,   -56,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,     0,     0,
       0,   -33,     0,     0,   -32,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,     0,     0,     0,   -34,     0,
       0,   -33,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,     0,     0,   -35,     0,     0,   -34,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,     0,
       0,     0,   -53,     0,     0,   -35,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,     0,   -54,
       0,     0,   -53,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,     0,     0,     0,     0,   -55,     0,     0,   -54,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,
       0,     0,     0,   -36,     0,     0,   -55,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,     0,
     140,     0,     0,   -36,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,   -49,     0,     0,
     -31,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,     0,   -50,     0,     0,   -49,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,     0,     0,     0,
       0,   -51,     0,     0,   -50,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,     0,   140,     0,
       0,   -51,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,     0,     0,     0,     0,   140,     0,     0,   -52,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,   -45,     0,     0,   184,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,     0,     0,   140,
       0,     0,   -45,   -46,   142,   143,   144,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,     0,   140,     0,     0,   -46,
     -47,   -47,   143,   144,   -47,   -47,   -47,   -47,   -47,     0,
       0,     0,     0,   140,     0,     0,   -47,   -48,   -48,   -48,
     144,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,     0,
     140,     0,     0,   -48,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,     0,     0,   140,     0,     0,
     -44,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,   140,     0,     0,   -39,   141,   142,
     143,   144,   -40,   -40,   147,   148,   149,     0,     0,     0,
       0,   140,     0,     0,   -40,   141,   142,   143,   144,   -41,
     -41,   -41,   148,   149,     0,     0,     0,     0,   140,     0,
       0,   -41,   141,   142,   143,   144,   -42,   -42,   -42,   -42,
     149,     0,     0,     0,     0,   140,     0,     0,   -42,   141,
     142,   143,   144,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,     0,   -38,     0,     0,   -43,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,     0,     0,     0,     0,   140,
       0,     0,   -38,   141,   142,   143,   144,   145,   146,   147,
     148,   149,     0,     0,     0,     0,   -59,     0,     0,   190,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,     0,
       0,     0,     0,   -37,     0,     0,   -59,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,   -60,
       0,   -37,    82,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,     0,     0,     0,   -61,     0,   -60,   -60,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,     0,     0,
       0,   -62,     0,   -61,   -61,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,     0,     0,     0,   -58,     0,   -62,
     -62,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
       0,     0,   -57,     0,     0,   -58,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,     0,     0,   -56,     0,     0,
     -57,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
       0,     0,    71,     0,     0,   -56,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,   -32,     0,     0,
      81,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
       0,     0,   -33,     0,     0,   -32,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,     0,     0,   -34,     0,     0,
     -33,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
       0,     0,   -35,     0,     0,   -34,   -35,   -35,   -35,   -35,
     -35,   -35,   -35,   -35,   -35,     0,     0,   -53,     0,     0,
     -35,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
       0,     0,   -54,     0,     0,   -53,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,   -55,     0,     0,
     -54,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,   -36,     0,     0,   -55,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -36,     0,     0,   -49,     0,     0,
     -36,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,   -50,     0,     0,   -49,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,     0,     0,   -51,     0,     0,
     -50,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
       0,     0,    71,     0,     0,   -51,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,     0,     0,    71,     0,     0,
     -52,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,    71,     0,     0,   -29,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,   -38,     0,     0,
     -31,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
       0,     0,   -45,     0,     0,   -38,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,     0,     0,    71,     0,     0,
     -45,   -46,    73,    74,    75,   -46,   -46,   -46,   -46,   -46,
       0,     0,    71,     0,     0,   -46,   -47,   -47,    74,    75,
     -47,   -47,   -47,   -47,   -47,     0,     0,    71,     0,     0,
     -47,   -48,   -48,   -48,    75,   -48,   -48,   -48,   -48,   -48,
       0,     0,    71,     0,     0,   -48,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,    71,     0,     0,
     -44,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,    71,     0,     0,   -39,    72,    73,    74,    75,
     -40,   -40,    78,    79,    80,     0,     0,    71,     0,     0,
     -40,    72,    73,    74,    75,   -41,   -41,   -41,    79,    80,
       0,     0,    71,     0,     0,   -41,    72,    73,    74,    75,
     -42,   -42,   -42,   -42,    80,     0,     0,    71,     0,     0,
     -42,    72,    73,    74,    75,   -43,   -43,   -43,   -43,   -43,
       0,     0,   -59,     0,     0,   -43,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,     0,     0,    71,     0,     0,
     -59,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,   182
};

static const yytype_int16 yycheck[] =
{
       9,   116,    22,    99,    31,    32,    99,    33,     0,    99,
      82,   104,    21,     5,    35,   108,     3,     4,     5,     6,
       0,     3,     4,     5,     6,     5,    31,    32,   100,    38,
      99,    99,    32,   105,     7,     8,     9,    17,    32,   154,
       7,     8,     9,    23,    33,    34,    33,    31,     0,    32,
      59,     3,     4,     5,     6,    64,    31,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    36,    14,    15,
      16,    31,     0,    82,    20,     3,     4,     5,     6,    99,
      26,    27,    28,    29,    31,    32,    32,    31,    32,    35,
      36,     7,     8,     9,   190,   167,   105,   190,   194,    33,
     190,   194,   198,    33,   194,   198,     0,   179,   198,     3,
       4,     5,     6,    31,   123,   124,   125,   126,   127,   191,
      31,   190,   190,   195,    31,   194,   194,    33,    34,   198,
     198,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     7,     8,     9,     7,     8,     9,    31,    32,    33,
      34,    33,    34,    37,    38,     7,     8,     9,   167,     7,
       8,     9,    10,    11,    12,    32,    14,    15,    16,   178,
     190,    31,    20,    31,   194,     7,     8,     9,   198,    36,
      64,    65,    33,    34,    32,    33,   195,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    36,    82,    33,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      31,    14,    15,    16,    31,    99,   100,    20,    33,    34,
      33,   105,    23,    26,    27,    28,    29,    33,    34,    32,
       5,     0,    35,    36,     3,     4,     5,     6,    42,   123,
     124,   125,   126,   127,     0,    38,    -1,     3,     4,     5,
       6,    33,    34,    -1,    -1,    38,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    13,    -1,
      -1,    64,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    64,    -1,   167,    -1,    -1,    -1,    32,    33,    82,
      -1,    -1,    -1,    -1,   178,   179,    -1,     0,    -1,    82,
       3,     4,     5,     6,    -1,    -1,   190,   191,    -1,    -1,
     194,   195,   105,     0,   198,    -1,     3,     4,     5,     6,
       0,    -1,   105,     3,     4,     5,     6,    -1,    -1,    -1,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,    -1,    38,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    13,    64,    -1,   167,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   167,   178,    -1,    -1,    -1,    -1,
      82,    33,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   105,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    -1,    -1,    64,
      20,   123,   124,   125,   126,   127,    26,    -1,    28,    29,
      -1,    -1,    32,    -1,    -1,    35,    -1,    82,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
     105,    20,    -1,    -1,    -1,   167,    -1,    -1,    38,    -1,
      -1,    -1,    31,    32,    -1,    -1,   178,    -1,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    64,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,     7,     8,     9,    10,
      11,    12,    82,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,   167,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    32,    -1,   178,    -1,   105,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
     195,    64,    20,   123,   124,   125,   126,   127,    26,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    35,    -1,    82,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,   105,    20,    -1,    -1,    -1,   167,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    32,    -1,    -1,   178,    -1,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,    64,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    82,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   167,    -1,    -1,    38,    -1,    -1,
      32,    33,    -1,    -1,    13,   178,    -1,   105,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,   195,    64,    33,   123,   124,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    13,    -1,   167,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     178,    -1,   123,   124,   125,   126,   127,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,   167,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,   178,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   195,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    35,    36,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    35,    36,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    35,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    35,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    13,    -1,    35,    36,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    32,    33,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    32,    33,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    33,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    33,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    33,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    33,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      33,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    33,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    33,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    33,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    13,    -1,    -1,    33,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    33,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    13,
      -1,    31,    32,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    13,    -1,    31,    32,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    13,    -1,    31,    32,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    13,    -1,    31,
      32,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    13,    -1,    -1,    31,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,
      31,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    38,    39,    40,    41,    65,
       0,    39,     7,     8,     9,    64,    31,    32,    42,    43,
      44,    65,    33,    34,    64,    35,    45,    44,    10,    11,
      12,    14,    15,    16,    20,    26,    28,    29,    32,    40,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      55,    55,    55,    55,    32,    32,    55,    55,    36,    48,
      31,    13,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    31,    32,    64,    55,    54,    55,    33,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    54,    33,
      31,    33,    49,    54,    27,    31,    49,    54,    33,    49,
       7,     8,     9,     7,     8,     9,    35,     7,     8,     9,
      10,    11,    12,    14,    15,    16,    20,    32,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     7,     8,     9,
      13,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      55,    31,    26,    28,    35,    45,    50,    51,    52,    53,
      55,    46,    55,    55,    55,    55,    55,    32,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    32,    32,
      46,    31,    31,    36,    33,    54,    55,    54,    36,    33,
      33,    31,    49,    54,    27,    31,    49,    54,    33,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    41,    42,    42,
      43,    43,    44,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    49,    50,    50,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    60,    61,    62,    63,
      64,    64,    64,    65,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     6,     0,     1,
       3,     1,     2,     3,     0,     1,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     5,     7,     9,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1
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

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
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
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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
  YY_USE (yykind);
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
#line 73 "./src/bison.y"
                             {
        insert_kid(yyvsp[0], root);
    }
#line 2046 "bison.tab.c"
    break;

  case 3: /* startProgram: declaration  */
#line 76 "./src/bison.y"
                  {
        insert_kid(yyvsp[0], root);
    }
#line 2054 "bison.tab.c"
    break;

  case 6: /* variableDeclare: type id ';'  */
#line 87 "./src/bison.y"
                {
        printf("variable delcare\n");
        yyval = create_astnode_context(AST_VAR_DECLARE, "variable declare");
        insert_kid(yyvsp[-2], yyval);
        insert_kid(yyvsp[-1], yyval);
    }
#line 2065 "bison.tab.c"
    break;

  case 7: /* functionDeclare: type id '(' optListParams ')' compoundStatement  */
#line 96 "./src/bison.y"
                                                    {
        /* Lidar com contextos */
        yyval = create_astnode_context(AST_FUNC_DECLARE, "func declare");
        // printf("FUNC DECLARE\n");
        insert_kid(yyvsp[-5], yyval);
        insert_kid(yyvsp[-4], yyval);

        if(yyvsp[-2]) /* Se existir parametros insira */
            insert_kid(yyvsp[-2], yyval);
        insert_kid(yyvsp[0], yyval);
        // delete_context_ast(node_aux);
    }
#line 2082 "bison.tab.c"
    break;

  case 8: /* optListParams: %empty  */
#line 111 "./src/bison.y"
           {
        yyval = NULL;
    }
#line 2090 "bison.tab.c"
    break;

  case 9: /* optListParams: listParams  */
#line 114 "./src/bison.y"
                 {
        // printf("Lista de params\n");
        yyval = create_astnode_context(AST_PARAM, "listParam");
        /* Retira os elementos da lista auxiliar 
        e depois adiciona como filhos ao no listParam */
        do{
            insert_kid(pop_element_list(node_aux), yyval);
        } while(node_aux->size >= 1);
    }
#line 2104 "bison.tab.c"
    break;

  case 12: /* param: type id  */
#line 131 "./src/bison.y"
            {
        yyval = create_astnode_context(AST_PARAM, "param");
        insert_kid(yyvsp[-1], yyval);
        insert_kid(yyvsp[0], yyval);

        /* Adiciona os parametros na lista auxiliar */

        insert_list_element(node_aux, yyval);
    }
#line 2118 "bison.tab.c"
    break;

  case 13: /* compoundStatement: '{' optListCodeBlock '}'  */
#line 144 "./src/bison.y"
                             {
        // printf("CompoundStatement\n");
        yyval = create_astnode_context(AST_STATE_FLOW, "compound statement");
        if(yyvsp[-1])
            insert_kid(yyvsp[-1], yyval);
    }
#line 2129 "bison.tab.c"
    break;

  case 14: /* optListCodeBlock: %empty  */
#line 153 "./src/bison.y"
           {
        yyval = NULL;
    }
#line 2137 "bison.tab.c"
    break;

  case 15: /* optListCodeBlock: listCodeBlock  */
#line 156 "./src/bison.y"
                   {
        yyval = create_astnode_context(AST_STATE_FLOW, "listCodeBlock");
        do{
            insert_kid(pop_element_list(node_aux), yyval);
        } while(node_aux->size >= 1);
    }
#line 2148 "bison.tab.c"
    break;

  case 18: /* codeBlock: statement  */
#line 170 "./src/bison.y"
              {
        // printf("code block\n");
        yyval = create_astnode_context(AST_STATE_FLOW, "code block");
        insert_kid(yyvsp[0], yyval);
        insert_list_element(node_aux, yyval);
    }
#line 2159 "bison.tab.c"
    break;

  case 19: /* codeBlock: variableDeclare  */
#line 176 "./src/bison.y"
                      {
        yyval = create_astnode_context(AST_STATE_FLOW, "code block");
        insert_kid(yyvsp[0], yyval);
        insert_list_element(node_aux, yyval);
    }
#line 2169 "bison.tab.c"
    break;

  case 20: /* statement: flowExpression  */
#line 184 "./src/bison.y"
                   {
        yyval = create_astnode_context(AST_STATE_FLOW, "statement");
        // insert_list_element(node_aux, $$);
    }
#line 2178 "bison.tab.c"
    break;

  case 21: /* statement: compoundStatement  */
#line 188 "./src/bison.y"
                        {
        yyval = create_astnode_context(AST_STATE_FLOW, "statement");
        insert_kid(yyvsp[0], yyval);
        // insert_list_element(node_aux, $$);
    }
#line 2188 "bison.tab.c"
    break;

  case 22: /* statement: expression ';'  */
#line 193 "./src/bison.y"
                     {
        yyval = create_astnode_context(AST_STATE_EXPRESSION, "statement");
        // insert_list_element(node_aux, $$);
    }
#line 2197 "bison.tab.c"
    break;

  case 56: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 263 "./src/bison.y"
                           {
        // printf("CONSTANT_INTEGER_TOKEN\n");
        // insert_kid($1, root);
    }
#line 2206 "bison.tab.c"
    break;

  case 57: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 270 "./src/bison.y"
                        {
        // printf("CONSTANT_REAL_TOKEN\n");
        // insert_kid($1, root);
    }
#line 2215 "bison.tab.c"
    break;

  case 58: /* constantNIL: NIL_TOKEN  */
#line 277 "./src/bison.y"
              {
        ;
    }
#line 2223 "bison.tab.c"
    break;

  case 60: /* id: ID_TOKEN  */
#line 287 "./src/bison.y"
             {
        // printf("ID_TOKEN\n");
        // insert_kid($1, root);
    }
#line 2232 "bison.tab.c"
    break;

  case 61: /* id: READ_TOKEN  */
#line 291 "./src/bison.y"
                 {
        ;
    }
#line 2240 "bison.tab.c"
    break;

  case 62: /* id: WRITE_TOKEN  */
#line 294 "./src/bison.y"
                  {
        ;
    }
#line 2248 "bison.tab.c"
    break;

  case 63: /* type: INT_TOKEN  */
#line 300 "./src/bison.y"
              {
        // printf("INT_TOKEN\n");
        // printf("contexto: %s\n", $$->context->name);
        // insert_kid($1, root);
    }
#line 2258 "bison.tab.c"
    break;

  case 64: /* type: FLOAT_TOKEN  */
#line 305 "./src/bison.y"
                  {
        // printf("FLOAT_TOKEN\n");
        // insert_kid($1, root);
    }
#line 2267 "bison.tab.c"
    break;

  case 65: /* type: INT_LIST_TOKEN  */
#line 309 "./src/bison.y"
                     {
        // printf("INT_LIST_TOKEN\n");
        // insert_kid($1, root);
    }
#line 2276 "bison.tab.c"
    break;

  case 66: /* type: FLOAT_LIST_TOKEN  */
#line 313 "./src/bison.y"
                       {
        // printf("INT_LIST_TOKEN\n");
        // insert_kid($1, root);
    }
#line 2285 "bison.tab.c"
    break;


#line 2289 "bison.tab.c"

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

#line 319 "./src/bison.y"


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