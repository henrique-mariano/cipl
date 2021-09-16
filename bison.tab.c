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

    extern int error, num_line, num_col, symbol_id, scope;
    
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
  YYSYMBOL_ADD_UNARY_TOKEN = 26,           /* ADD_UNARY_TOKEN  */
  YYSYMBOL_MIN_UNARY_TOKEN = 27,           /* MIN_UNARY_TOKEN  */
  YYSYMBOL_EQUAL_TOKEN = 28,               /* EQUAL_TOKEN  */
  YYSYMBOL_DIFF_EQ_TOKEN = 29,             /* DIFF_EQ_TOKEN  */
  YYSYMBOL_LESS_TOKEN = 30,                /* LESS_TOKEN  */
  YYSYMBOL_LE_EQ_TOKEN = 31,               /* LE_EQ_TOKEN  */
  YYSYMBOL_GREAT_TOKEN = 32,               /* GREAT_TOKEN  */
  YYSYMBOL_GR_EQ_TOKEN = 33,               /* GR_EQ_TOKEN  */
  YYSYMBOL_ADD_TOKEN = 34,                 /* ADD_TOKEN  */
  YYSYMBOL_MIN_TOKEN = 35,                 /* MIN_TOKEN  */
  YYSYMBOL_MUL_TOKEN = 36,                 /* MUL_TOKEN  */
  YYSYMBOL_DIV_TOKEN = 37,                 /* DIV_TOKEN  */
  YYSYMBOL_UNI_OP = 38,                    /* UNI_OP  */
  YYSYMBOL_IF_TOKEN = 39,                  /* IF_TOKEN  */
  YYSYMBOL_ELSE_TOKEN = 40,                /* ELSE_TOKEN  */
  YYSYMBOL_FOR_TOKEN = 41,                 /* FOR_TOKEN  */
  YYSYMBOL_RETURN_TOKEN = 42,              /* RETURN_TOKEN  */
  YYSYMBOL_STRING_TOKEN = 43,              /* STRING_TOKEN  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_45_ = 45,                       /* '-'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_startProgram = 55,              /* startProgram  */
  YYSYMBOL_declaration = 56,               /* declaration  */
  YYSYMBOL_variableDeclare = 57,           /* variableDeclare  */
  YYSYMBOL_functionDeclare = 58,           /* functionDeclare  */
  YYSYMBOL_optListParams = 59,             /* optListParams  */
  YYSYMBOL_listParams = 60,                /* listParams  */
  YYSYMBOL_param = 61,                     /* param  */
  YYSYMBOL_compoundStatement = 62,         /* compoundStatement  */
  YYSYMBOL_optListCodeBlock = 63,          /* optListCodeBlock  */
  YYSYMBOL_listCodeBlock = 64,             /* listCodeBlock  */
  YYSYMBOL_codeBlock = 65,                 /* codeBlock  */
  YYSYMBOL_statement = 66,                 /* statement  */
  YYSYMBOL_flowExpression = 67,            /* flowExpression  */
  YYSYMBOL_condExpression = 68,            /* condExpression  */
  YYSYMBOL_interationExpression = 69,      /* interationExpression  */
  YYSYMBOL_returnExpression = 70,          /* returnExpression  */
  YYSYMBOL_optExpression = 71,             /* optExpression  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_binArith = 73,                  /* binArith  */
  YYSYMBOL_listArith = 74,                 /* listArith  */
  YYSYMBOL_unaArith = 75,                  /* unaArith  */
  YYSYMBOL_constant = 76,                  /* constant  */
  YYSYMBOL_constantInteger = 77,           /* constantInteger  */
  YYSYMBOL_constantReal = 78,              /* constantReal  */
  YYSYMBOL_constantNIL = 79,               /* constantNIL  */
  YYSYMBOL_constantString = 80,            /* constantString  */
  YYSYMBOL_funcCall = 81,                  /* funcCall  */
  YYSYMBOL_optListExpression = 82,         /* optListExpression  */
  YYSYMBOL_listExpression = 83,            /* listExpression  */
  YYSYMBOL_id = 84,                        /* id  */
  YYSYMBOL_type = 85                       /* type  */
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
#define YYLAST   6825

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      49,    50,    46,    44,    51,    45,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    96,    96,    99,   105,   108,   114,   141,   182,   185,
     189,   193,   200,   209,   227,   230,   234,   238,   245,   249,
     256,   260,   264,   271,   274,   277,   283,   288,   297,   310,
     317,   320,   326,   331,   335,   339,   343,   347,   351,   355,
     362,   367,   372,   377,   382,   387,   392,   397,   402,   407,
     412,   417,   425,   430,   435,   443,   447,   451,   455,   459,
     466,   470,   474,   478,   485,   491,   497,   503,   509,   523,
     528,   545,   548,   552,   556,   563,   569,   572,   575,   578
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
  "AND_TOKEN", "EQ_EXC_TOKEN", "LE_GR_TOKEN", "ADD_UNARY_TOKEN",
  "MIN_UNARY_TOKEN", "EQUAL_TOKEN", "DIFF_EQ_TOKEN", "LESS_TOKEN",
  "LE_EQ_TOKEN", "GREAT_TOKEN", "GR_EQ_TOKEN", "ADD_TOKEN", "MIN_TOKEN",
  "MUL_TOKEN", "DIV_TOKEN", "UNI_OP", "IF_TOKEN", "ELSE_TOKEN",
  "FOR_TOKEN", "RETURN_TOKEN", "STRING_TOKEN", "'+'", "'-'", "'*'", "'/'",
  "';'", "'('", "')'", "','", "'{'", "'}'", "$accept", "startProgram",
  "declaration", "variableDeclare", "functionDeclare", "optListParams",
  "listParams", "param", "compoundStatement", "optListCodeBlock",
  "listCodeBlock", "codeBlock", "statement", "flowExpression",
  "condExpression", "interationExpression", "returnExpression",
  "optExpression", "expression", "binArith", "listArith", "unaArith",
  "constant", "constantInteger", "constantReal", "constantNIL",
  "constantString", "funcCall", "optListExpression", "listExpression",
  "id", "type", YY_NULLPTR
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
     295,   296,   297,   298,    43,    45,    42,    47,    59,    40,
      41,    44,   123,   125
};
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      33,     2,     9,    35,    37,     8,    15,    43,    73,    49,
    -137,    97,   -25,    23,   128,     1,   -10,    31,    48,    51,
      -2,    33,    56,  2105,   148,    68,    11,    25,  5465,  5497,
    5529,   101,   101,   101,    34,    55,   101,  5561,   101,   101,
     623,  2156,  2171,    13,  2222,  2237,  2288,  2303,  2354,  2369,
      87,  5593,  5625,  5657,  5689,  5721,  5753,  5785,  5817,  5849,
    5881,  5399,   136,   149,    18,  5913,  5945,  5977,   623,   454,
    6009,  6041,  6073,  3903,   168,  2420,  2435,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,  2486,   101,    18,   107,   108,   681,   109,    70,
    3937,   112,  6105,  6137,  6169,  6201,  6233,  6265,  6297,  6329,
    6361,  6393,  6425,  6457,  6489,  6521,  6553,  6585,  6617,  6649,
     114,  6681,  6713,   804,  2633,   454,  6745,   862,   432,   121,
    2679,    80,  2501,   120,  2679,  2552,    76,  5432,  2105,  3835,
     126,   127,  3971,  4005,  4039,   623,   623,   623,  4073,   623,
     623,   623,  4107,  4141,  4175,  4209,  4243,  4277,  4311,  4345,
    4379,  3869,   129,   143,   289,   163,   164,  1043,  1224,  1405,
     804,   804,   804,  1586,   804,   804,   623,  1767,  1948,  2715,
    2750,  2785,  2820,  2855,  2890,  2925,   500,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   623,   623,   623,   623,
     623,   623,  2567,   804,   804,   804,   804,   804,   804,   804,
     804,   804,   804,   804,   804,   804,   804,   804,   173,   176,
    2105,   612,   793,   974,  1155,   179,  6777,  4413,   180,   149,
      18,  4447,  4481,  4515,  4549,  4583,  4617,   623,    18,   149,
      18,  2960,  2995,  3030,  3065,  3100,  4651,   804,    18,  4685,
    4719,  4753,  4787,  4821,  4855,  4889,  4923,  4957,  4991,  5025,
    5059,  5093,  5127,  5161,  3135,  3170,  3205,  3240,  3275,  3310,
    3345,  3380,  3415,  3450,  3485,  3520,  3555,  3590,  3625,   623,
     454,   181,  1336,  1517,  2618,   185,   193,  5195,  5229,   200,
     201,   204,  3660,  3695,   224,  5263,   227,  1698,  5297,  5331,
    5365,  3730,  3765,  3800,  2633,   454,  1879,   228,  2633,    80,
    2030,   229,  2633,  2090
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   221,    17,  -137,  -137,  -137,   257,   -19,  -136,
    -137,   236,   -89,   -72,   -67,   -60,   -31,   -56,   178,   365,
     546,   727,   908,  1089,  1270,  1451,  1632,  1813,   -91,  -137,
      -9,    65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    41,     8,    16,    17,    18,    42,    43,
      44,    45,    46,    47,    48,    49,    50,   101,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    98,    99,
      61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    24,   228,   120,     1,     2,     3,     4,    10,   -76,
      22,     1,     2,     3,     4,    -3,   -77,     7,    -3,    -3,
      -3,    -3,     7,   -75,   -75,   164,   165,   166,   167,   168,
     169,   161,   170,   171,   172,   128,     1,     2,     3,     4,
      20,   132,   -78,    -4,   -79,   135,    -4,    -4,    -4,    -4,
      23,    -8,   222,    95,    96,   186,    12,   223,   136,   161,
      63,   173,   174,   175,   224,     9,    74,   176,   -71,   129,
       9,    14,    15,    -5,    64,   133,    -5,    -5,    -5,    -5,
      19,    -9,    21,    68,   281,   186,    19,   139,   140,   141,
     142,   143,   144,   225,   145,   146,   147,    -2,   -11,   -11,
      -2,    -2,    -2,    -2,    69,   221,   -12,   -12,   137,    26,
      27,    28,    29,    30,   186,    31,    32,    33,   -10,   -10,
     -72,   123,   161,   148,   149,   150,   -75,   -75,    -6,   151,
     -30,    -6,    -6,    -6,    -6,    76,   161,   161,   161,   286,
     161,   161,   161,   162,    37,    38,    39,   289,    -7,   291,
      40,    -7,    -7,    -7,    -7,   202,   163,   294,   121,   122,
     125,   186,   186,   186,   126,   186,   186,   161,   -13,   131,
     134,   -13,   -13,   -13,   -13,   229,   230,   -75,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   -75,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,    65,
      66,    67,   239,   240,    70,   306,    71,    72,    73,   310,
     285,   186,   279,   313,   296,   280,    11,   282,   161,   186,
     290,   186,   222,   284,   297,   298,   222,   223,   186,   186,
     222,   223,    97,   299,   224,   223,   100,   102,   224,   307,
     300,   301,   224,   311,   302,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     161,   119,    97,   225,   303,   305,   309,   225,    25,   312,
      75,   225,     0,     0,     0,   221,     0,     0,     0,   221,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
     161,   127,   226,   102,     0,     0,   -75,   -75,   -75,   227,
     -75,   -75,   -75,     0,     0,     0,     0,   -75,   -75,   -75,
     -75,   -75,   -75,   231,   232,   233,     0,   234,   235,   236,
       0,     0,     0,   -75,   -75,   -75,   -75,     0,   -75,   -75,
     -75,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,     0,   244,   245,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
       0,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,    97,     0,
       0,     0,     0,     0,     0,   288,    97,     0,    97,     0,
       0,     0,     0,     0,     0,   293,    97,     0,     0,   177,
       0,     0,     0,   152,     0,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   102,   177,
       0,   137,    26,    27,    28,    29,    30,     0,    31,    32,
      33,   -26,   130,   -26,   -26,   -26,   -26,   -26,     0,     0,
       0,   -26,   226,   102,   -26,   -26,   226,   227,   177,     0,
     226,     0,     0,     0,     0,     0,   152,    37,    38,    39,
       0,     0,   -30,    40,     0,     0,     0,     0,     0,     0,
     152,   152,   152,     0,   152,   152,   152,   -38,   -38,   -38,
       0,   247,   -38,   -38,     0,     0,     0,     0,   -38,   -38,
     -38,   -38,   -38,   -38,     0,   177,   177,   177,     0,   177,
     177,   152,     0,     0,   -38,   -38,   -38,   -38,     0,   248,
     -38,   -38,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,     0,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,   152,   177,     0,   177,     0,     0,     0,     0,
     178,     0,   177,   177,   153,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,     0,
     139,   140,   141,   142,   143,   144,     0,   145,   146,   147,
     178,     0,     0,     0,   152,     0,     0,     0,     0,     0,
       0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,     0,
       0,   -21,     0,     0,   -21,   -21,   148,   149,   150,   178,
       0,     0,   151,     0,   152,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   153,   153,     0,   153,   153,   153,   203,   204,
     205,     0,     0,   206,   207,     0,     0,     0,     0,   208,
     209,   210,   211,   212,   213,     0,   178,   178,   178,     0,
     178,   178,   153,     0,     0,   214,   215,   216,   217,     0,
       0,   -74,   -74,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,     0,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   178,     0,     0,     0,
       0,     0,     0,   153,   178,     0,   178,     0,     0,     0,
       0,   179,     0,   178,   178,   154,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,
       0,   164,   165,   166,   167,   168,   169,     0,   170,   171,
     172,   179,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,
       0,     0,   -20,     0,     0,   -20,   -20,   173,   174,   175,
     179,     0,     0,   176,     0,   153,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,   154,   154,     0,   154,   154,   154,   203,
     204,   205,     0,     0,   206,   207,     0,     0,     0,     0,
     208,   209,   210,   211,   212,   213,     0,   179,   179,   179,
       0,   179,   179,   154,     0,     0,   214,   215,   216,   217,
       0,     0,   -73,   -73,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,     0,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,     0,     0,     0,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,     0,     0,     0,   154,   179,     0,   179,     0,     0,
       0,     0,   180,     0,   179,   179,   155,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   180,     0,     0,     0,   154,     0,     0,     0,
       0,     0,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,     0,     0,   -23,   -23,     0,     0,
       0,   180,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   155,   155,     0,   155,   155,   155,
     -66,   -66,   -66,     0,     0,   -66,   -66,     0,     0,     0,
       0,   -66,   -66,   -66,   -66,   -66,   -66,     0,   180,   180,
     180,     0,   180,   180,   155,     0,     0,   -66,   -66,   -66,
     -66,     0,     0,   -66,   -66,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
       0,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,     0,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,   155,   180,     0,   180,     0,
       0,     0,     0,   181,     0,   180,   180,   156,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,   -24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,     0,     0,     0,   155,     0,     0,
       0,     0,     0,     0,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,     0,     0,     0,   -24,     0,     0,   -24,   -24,     0,
       0,     0,   181,     0,     0,     0,     0,   155,     0,     0,
     156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,   156,   156,     0,   156,   156,
     156,   -65,   -65,   -65,     0,     0,   -65,   -65,     0,     0,
       0,     0,   -65,   -65,   -65,   -65,   -65,   -65,     0,   181,
     181,   181,     0,   181,   181,   156,     0,     0,   -65,   -65,
     -65,   -65,     0,     0,   -65,   -65,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,     0,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,     0,     0,     0,
     157,     0,     0,     0,     0,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,   156,   181,     0,   181,
       0,     0,     0,     0,   182,     0,   181,   181,   157,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     0,
     -25,   -25,   -25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,     0,     0,   156,     0,
       0,     0,     0,     0,     0,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,     0,     0,     0,   -25,     0,     0,   -25,   -25,
       0,     0,     0,   182,     0,     0,     0,     0,   156,     0,
       0,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   157,   157,     0,   157,
     157,   157,   -64,   -64,   -64,     0,     0,   -64,   -64,     0,
       0,     0,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,
     182,   182,   182,     0,   182,   182,   157,     0,     0,   -64,
     -64,   -64,   -64,     0,     0,   -64,   -64,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,     0,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,     0,     0,     0,     0,     0,   157,   182,     0,
     182,     0,     0,     0,     0,   183,     0,   182,   182,   158,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
       0,   -22,   -22,   -22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,     0,     0,     0,   157,
       0,     0,     0,     0,     0,     0,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,     0,     0,     0,   -22,     0,     0,   -22,
     -22,     0,     0,     0,   183,     0,     0,     0,     0,   157,
       0,     0,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   158,   158,     0,
     158,   158,   158,   -67,   -67,   -67,     0,     0,   -67,   -67,
       0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,   -67,
       0,   183,   183,   183,     0,   183,   183,   158,     0,     0,
     -67,   -67,   -67,   -67,     0,     0,   -67,   -67,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,     0,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,   158,   183,
       0,   183,     0,     0,     0,     0,   184,     0,   183,   183,
     159,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,     0,   -13,   -13,   -13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   184,     0,     0,     0,
     158,     0,     0,     0,     0,     0,     0,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,     0,     0,     0,   -13,     0,     0,
     -13,   -13,     0,     0,     0,   184,     0,     0,     0,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   159,   159,
       0,   159,   159,   159,   -33,   -33,   -33,     0,     0,   -33,
     -33,     0,     0,     0,     0,   -33,   -33,   -33,   -33,   -33,
     -33,     0,   184,   184,   184,     0,   184,   184,   159,     0,
       0,   -33,   -33,   -33,   -33,     0,     0,   -33,   -33,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,     0,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
       0,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,   184,     0,     0,     0,     0,     0,     0,   159,
     184,     0,   184,     0,     0,     0,     0,   185,     0,   184,
     184,   160,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   185,     0,     0,
       0,   159,     0,     0,     0,     0,     0,     0,   -26,   308,
     -26,   -26,   -26,   -26,   -26,     0,     0,     0,   -26,     0,
       0,   -26,   -26,     0,     0,     0,   185,     0,     0,     0,
       0,   159,     0,     0,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   160,
     160,     0,   160,   160,   160,   -34,   -34,   -34,     0,     0,
     -34,   -34,     0,     0,     0,     0,   -34,   -34,   -34,   -34,
     -34,   -34,     0,   185,   185,   185,     0,   185,   185,   160,
       0,     0,   -34,   -34,   -34,   -34,     0,     0,   -34,   -34,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,     0,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,     0,     0,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   185,   -27,   -27,   -27,     0,     0,     0,
     160,   185,     0,   185,     0,     0,     0,     0,     0,     0,
     185,   185,     0,     0,     0,     0,     0,     0,     0,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,     0,     0,     0,   -27,
       0,     0,   -27,   -27,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,     0,   -28,   -28,   -28,     0,     1,     2,
       3,     4,   137,    26,    27,    28,    29,    30,     0,    31,
      32,    33,   160,     0,     0,     0,     0,     0,     0,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,     0,     0,     0,   -28,
       0,     0,   -28,   -28,    34,     0,    35,    36,    37,    38,
      39,     0,     0,     0,    40,     0,     0,   138,   -14,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,     0,
     -19,   -19,   -19,     0,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,     0,     0,
       0,     0,     0,     0,     0,   -19,     0,   -19,   -19,   -19,
     -19,   -19,     0,     0,     0,   -19,     0,     0,   -19,   -19,
     -21,     0,   -21,   -21,   -21,   -21,   -21,     0,     0,     0,
     -21,     0,     0,   -21,   -21,     1,     2,     3,     4,   137,
      26,    27,    28,    29,    30,     0,    31,    32,    33,     0,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
       0,   -17,   -17,   -17,     0,     0,     0,     0,     0,     0,
       0,    34,     0,    35,    36,    37,    38,    39,     0,     0,
       0,    40,     0,     0,   138,   -15,   -17,     0,   -17,   -17,
     -17,   -17,   -17,     0,     0,     0,   -17,     0,     0,   -17,
     -17,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,     0,   -18,   -18,   -18,     0,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,
       0,     0,     0,     0,     0,     0,     0,   -18,     0,   -18,
     -18,   -18,   -18,   -18,     0,     0,     0,   -18,     0,     0,
     -18,   -18,   -20,     0,   -20,   -20,   -20,   -20,   -20,     0,
       0,     0,   -20,     0,     0,   -20,   -20,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,     0,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,   -24,   -24,   -24,     0,     0,     0,     0,
       0,     0,     0,   -23,     0,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,     0,     0,   -23,   -23,   -24,     0,
     -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,     0,
       0,   -24,   -24,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,     0,   -16,   -16,   -16,     0,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,
     -25,   -25,     0,     0,     0,     0,     0,     0,     0,   -16,
       0,   -16,   -16,   -16,   -16,   -16,     0,     0,     0,   -16,
       0,     0,   -16,   -16,   -25,     0,   -25,   -25,   -25,   -25,
     -25,     0,     0,     0,   -25,     0,     0,   -25,   -25,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,
     -22,   -22,   -22,     0,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,     0,     0,
       0,     0,     0,     0,     0,   -22,     0,   -22,   -22,   -22,
     -22,   -22,     0,     0,     0,   -22,     0,     0,   -22,   -22,
     -27,     0,   -27,   -27,   -27,   -27,   -27,     0,     0,     0,
     -27,     0,     0,   -27,   -27,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,     0,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
       0,    -6,    -6,    -6,     0,     0,     0,     0,     0,     0,
       0,   -28,     0,   -28,   -28,   -28,   -28,   -28,     0,     0,
       0,   -28,     0,     0,   -28,   -28,    -6,     0,    -6,    -6,
      -6,    -6,    -6,     0,     0,     0,    -6,     0,     0,    -6,
      -6,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,     0,   -13,   -13,   -13,     0,     0,     0,     0,     0,
     137,    26,    27,    28,    29,    30,     0,    31,    32,    33,
       0,     0,     0,     0,     0,     0,     0,   -13,     0,   -13,
     -13,   -13,   -13,   -13,     0,     0,     0,   -13,     0,     0,
     -13,   -13,   218,     0,   219,    36,    37,    38,    39,     0,
       0,     0,    40,     0,     0,   220,   137,    26,    27,    28,
      29,    30,     0,    31,    32,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      35,    36,    37,    38,    39,     0,     0,     0,    40,     0,
       0,   138,   -35,   -35,   -35,     0,     0,   -35,   -35,     0,
       0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -35,
     -35,   -35,   -35,     0,     0,   -35,   -35,   -36,   -36,   -36,
       0,     0,   -36,   -36,     0,     0,     0,     0,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -36,   -36,   -36,   -36,     0,     0,
     -36,   -36,   -60,   -60,   -60,     0,     0,   -60,   -60,     0,
       0,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -60,
     -60,   -60,   -60,     0,     0,   -60,   -60,   -61,   -61,   -61,
       0,     0,   -61,   -61,     0,     0,     0,     0,   -61,   -61,
     -61,   -61,   -61,   -61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -61,   -61,   -61,   -61,     0,     0,
     -61,   -61,   -62,   -62,   -62,     0,     0,   -62,   -62,     0,
       0,     0,     0,   -62,   -62,   -62,   -62,   -62,   -62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -62,
     -62,   -62,   -62,     0,     0,   -62,   -62,   -63,   -63,   -63,
       0,     0,   -63,   -63,     0,     0,     0,     0,   -63,   -63,
     -63,   -63,   -63,   -63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -63,   -63,   -63,   -63,     0,     0,
     -63,   -63,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,
       0,     0,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,     0,     0,   -37,   -37,   -55,   -55,   -55,
       0,     0,   -55,   -55,     0,     0,     0,     0,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -55,   -55,     0,     0,
     -55,   -55,   -56,   -56,   -56,     0,     0,   -56,   -56,     0,
       0,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -56,
     -56,   -56,   -56,     0,     0,   -56,   -56,   -57,   -57,   -57,
       0,     0,   -57,   -57,     0,     0,     0,     0,   -57,   -57,
     -57,   -57,   -57,   -57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,   -57,     0,     0,
     -57,   -57,   -58,   -58,   -58,     0,     0,   -58,   -58,     0,
       0,     0,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -58,
     -58,   -58,   -58,     0,     0,   -58,   -58,   -59,   -59,   -59,
       0,     0,   -59,   -59,     0,     0,     0,     0,   -59,   -59,
     -59,   -59,   -59,   -59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -59,   -59,   -59,   -59,     0,     0,
     -59,   -59,   -52,   204,   205,     0,     0,   -52,   -52,     0,
       0,     0,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -52,   -52,   -53,   -53,   205,
       0,     0,   -53,   -53,     0,     0,     0,     0,   -53,   -53,
     -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   215,   216,   217,     0,     0,
     -53,   -53,   -54,   -54,   -54,     0,     0,   -54,   -54,     0,
       0,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -54,   -54,   203,   204,   205,
       0,     0,   -40,   207,     0,     0,     0,     0,   208,   209,
     210,   211,   212,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   215,   216,   217,     0,     0,
     -40,   -40,   203,   204,   205,     0,     0,   -41,   -41,     0,
       0,     0,     0,   208,   209,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -41,   -41,   203,   204,   205,
       0,     0,   -42,   -42,     0,     0,     0,     0,   -42,   -42,
     210,   211,   212,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   215,   216,   217,     0,     0,
     -42,   -42,   203,   204,   205,     0,     0,   -43,   -43,     0,
       0,     0,     0,   -43,   -43,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -43,   -43,   203,   204,   205,
       0,     0,   -44,   -44,     0,     0,     0,     0,   -44,   -44,
     -44,   -44,   -44,   -44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   215,   216,   217,     0,     0,
     -44,   -44,   203,   204,   205,     0,     0,   -45,   -45,     0,
       0,     0,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -45,   -45,   203,   204,   205,
       0,     0,   -46,   -46,     0,     0,     0,     0,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   214,   215,   216,   217,     0,     0,
     -46,   -46,   203,   204,   205,     0,     0,   -47,   -47,     0,
       0,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -47,   -47,   -48,   -48,   -48,
       0,     0,   -48,   -48,     0,     0,     0,     0,   -48,   -48,
     -48,   -48,   -48,   -48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -48,   -48,   216,   217,     0,     0,
     -48,   -48,   -49,   -49,   -49,     0,     0,   -49,   -49,     0,
       0,     0,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -49,
     -49,   216,   217,     0,     0,   -49,   -49,   -50,   -50,   -50,
       0,     0,   -50,   -50,     0,     0,     0,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -50,   -50,   -50,   -50,     0,     0,
     -50,   -50,   -51,   -51,   -51,     0,     0,   -51,   -51,     0,
       0,     0,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -51,
     -51,   -51,   -51,     0,     0,   -51,   -51,   -39,   -39,   -39,
       0,     0,   -39,   -39,     0,     0,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   -39,     0,     0,
     -39,   -39,   203,   204,   205,     0,     0,   206,   207,     0,
       0,     0,     0,   208,   209,   210,   211,   212,   213,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
     215,   216,   217,     0,     0,   -32,   -32,   -69,   -69,   -69,
       0,     0,   -69,   -69,     0,     0,     0,     0,   -69,   -69,
     -69,   -69,   -69,   -69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -69,   -69,   -69,   -69,     0,     0,
     -69,   -69,   -70,   -70,   -70,     0,     0,   -70,   -70,     0,
       0,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -70,
     -70,   -70,   -70,     0,     0,   -70,   -70,   -68,   -68,   -68,
       0,     0,   -68,   -68,     0,     0,     0,     0,   -68,   -68,
     -68,   -68,   -68,   -68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -68,   -68,   -68,   -68,     0,     0,
     -68,   -68,   -75,   -75,   -75,     0,   -75,   -75,   -75,     0,
       0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -75,
     -75,   -75,   -75,     0,   -75,   -75,   -38,   -38,   -38,     0,
     237,   -38,   -38,     0,     0,     0,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -38,   -38,   -38,   -38,     0,   238,   -38,
     187,   188,   189,     0,     0,   190,   191,     0,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   200,
     201,     0,     0,   103,   187,   188,   189,     0,     0,   190,
     191,     0,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   199,   200,   201,     0,     0,   124,   -66,   -66,
     -66,     0,     0,   -66,   -66,     0,     0,     0,     0,   -66,
     -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,   -66,     0,
       0,   -66,   -65,   -65,   -65,     0,     0,   -65,   -65,     0,
       0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -65,
     -65,   -65,   -65,     0,     0,   -65,   -64,   -64,   -64,     0,
       0,   -64,   -64,     0,     0,     0,     0,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -64,   -64,   -64,   -64,     0,     0,   -64,
     -67,   -67,   -67,     0,     0,   -67,   -67,     0,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -67,   -67,   -67,
     -67,     0,     0,   -67,   -33,   -33,   -33,     0,     0,   -33,
     -33,     0,     0,     0,     0,   -33,   -33,   -33,   -33,   -33,
     -33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -33,   -33,   -33,   -33,     0,     0,   -33,   -34,   -34,
     -34,     0,     0,   -34,   -34,     0,     0,     0,     0,   -34,
     -34,   -34,   -34,   -34,   -34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -34,   -34,   -34,   -34,     0,
       0,   -34,   -35,   -35,   -35,     0,     0,   -35,   -35,     0,
       0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -35,
     -35,   -35,   -35,     0,     0,   -35,   -36,   -36,   -36,     0,
       0,   -36,   -36,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -36,   -36,   -36,   -36,     0,     0,   -36,
     -60,   -60,   -60,     0,     0,   -60,   -60,     0,     0,     0,
       0,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -60,   -60,   -60,
     -60,     0,     0,   -60,   -61,   -61,   -61,     0,     0,   -61,
     -61,     0,     0,     0,     0,   -61,   -61,   -61,   -61,   -61,
     -61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -61,   -61,   -61,   -61,     0,     0,   -61,   -62,   -62,
     -62,     0,     0,   -62,   -62,     0,     0,     0,     0,   -62,
     -62,   -62,   -62,   -62,   -62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -62,   -62,   -62,   -62,     0,
       0,   -62,   -63,   -63,   -63,     0,     0,   -63,   -63,     0,
       0,     0,     0,   -63,   -63,   -63,   -63,   -63,   -63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -63,
     -63,   -63,   -63,     0,     0,   -63,   -37,   -37,   -37,     0,
       0,   -37,   -37,     0,     0,     0,     0,   -37,   -37,   -37,
     -37,   -37,   -37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -37,   -37,   -37,   -37,     0,     0,   -37,
     187,   188,   189,     0,     0,   190,   191,     0,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   200,
     201,     0,     0,   -31,   -55,   -55,   -55,     0,     0,   -55,
     -55,     0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,
     -55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -55,   -55,   -55,   -55,     0,     0,   -55,   -56,   -56,
     -56,     0,     0,   -56,   -56,     0,     0,     0,     0,   -56,
     -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -56,   -56,   -56,   -56,     0,
       0,   -56,   -57,   -57,   -57,     0,     0,   -57,   -57,     0,
       0,     0,     0,   -57,   -57,   -57,   -57,   -57,   -57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,   -57,     0,     0,   -57,   -58,   -58,   -58,     0,
       0,   -58,   -58,     0,     0,     0,     0,   -58,   -58,   -58,
     -58,   -58,   -58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -58,   -58,   -58,   -58,     0,     0,   -58,
     -59,   -59,   -59,     0,     0,   -59,   -59,     0,     0,     0,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -59,   -59,   -59,
     -59,     0,     0,   -59,   187,   188,   189,     0,     0,   190,
     191,     0,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   199,   200,   201,     0,     0,   287,   187,   188,
     189,     0,     0,   190,   191,     0,     0,     0,     0,   192,
     193,   194,   195,   196,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   199,   200,   201,     0,
       0,   292,   -52,   188,   189,     0,     0,   -52,   -52,     0,
       0,     0,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     199,   200,   201,     0,     0,   -52,   -53,   -53,   189,     0,
       0,   -53,   -53,     0,     0,     0,     0,   -53,   -53,   -53,
     -53,   -53,   -53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,   199,   200,   201,     0,     0,   -53,
     -54,   -54,   -54,     0,     0,   -54,   -54,     0,     0,     0,
       0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   200,
     201,     0,     0,   -54,   187,   188,   189,     0,     0,   -40,
     191,     0,     0,     0,     0,   192,   193,   194,   195,   196,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   199,   200,   201,     0,     0,   -40,   187,   188,
     189,     0,     0,   -41,   -41,     0,     0,     0,     0,   192,
     193,   194,   195,   196,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   199,   200,   201,     0,
       0,   -41,   187,   188,   189,     0,     0,   -42,   -42,     0,
       0,     0,     0,   -42,   -42,   194,   195,   196,   197,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     199,   200,   201,     0,     0,   -42,   187,   188,   189,     0,
       0,   -43,   -43,     0,     0,     0,     0,   -43,   -43,   194,
     195,   196,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,   199,   200,   201,     0,     0,   -43,
     187,   188,   189,     0,     0,   -44,   -44,     0,     0,     0,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   200,
     201,     0,     0,   -44,   187,   188,   189,     0,     0,   -45,
     -45,     0,     0,     0,     0,   -45,   -45,   -45,   -45,   -45,
     -45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,   199,   200,   201,     0,     0,   -45,   187,   188,
     189,     0,     0,   -46,   -46,     0,     0,     0,     0,   -46,
     -46,   -46,   -46,   -46,   -46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   199,   200,   201,     0,
       0,   -46,   187,   188,   189,     0,     0,   -47,   -47,     0,
       0,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     199,   200,   201,     0,     0,   -47,   -48,   -48,   -48,     0,
       0,   -48,   -48,     0,     0,     0,     0,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -48,   -48,   200,   201,     0,     0,   -48,
     -49,   -49,   -49,     0,     0,   -49,   -49,     0,     0,     0,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -49,   -49,   200,
     201,     0,     0,   -49,   -50,   -50,   -50,     0,     0,   -50,
     -50,     0,     0,     0,     0,   -50,   -50,   -50,   -50,   -50,
     -50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -50,   -50,   -50,   -50,     0,     0,   -50,   -51,   -51,
     -51,     0,     0,   -51,   -51,     0,     0,     0,     0,   -51,
     -51,   -51,   -51,   -51,   -51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -51,   -51,   -51,   -51,     0,
       0,   -51,   -39,   -39,   -39,     0,     0,   -39,   -39,     0,
       0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -39,
     -39,   -39,   -39,     0,     0,   -39,   187,   188,   189,     0,
       0,   190,   191,     0,     0,     0,     0,   192,   193,   194,
     195,   196,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   198,   199,   200,   201,     0,     0,   -32,
     187,   188,   189,     0,     0,   190,   191,     0,     0,     0,
       0,   192,   193,   194,   195,   196,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   200,
     201,     0,     0,   304,   -69,   -69,   -69,     0,     0,   -69,
     -69,     0,     0,     0,     0,   -69,   -69,   -69,   -69,   -69,
     -69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -69,   -69,   -69,   -69,     0,     0,   -69,   -70,   -70,
     -70,     0,     0,   -70,   -70,     0,     0,     0,     0,   -70,
     -70,   -70,   -70,   -70,   -70,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -70,   -70,   -70,   -70,     0,
       0,   -70,   -68,   -68,   -68,     0,     0,   -68,   -68,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -68,
     -68,   -68,   -68,     0,     0,   -68,   -38,   -38,   -38,     0,
      93,   -38,   -38,     0,     0,     0,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -38,   -38,   -38,   -38,   -38,    94,   -75,
     -75,   -75,     0,   -75,   -75,   -75,     0,     0,     0,     0,
     -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -75,   -75,   -75,   -75,
     -75,   -75,   -66,   -66,   -66,     0,     0,   -66,   -66,     0,
       0,     0,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -66,
     -66,   -66,   -66,   -66,   -65,   -65,   -65,     0,     0,   -65,
     -65,     0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,
     -65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -65,   -65,   -65,   -65,   -65,   -64,   -64,   -64,     0,
       0,   -64,   -64,     0,     0,     0,     0,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -64,   -64,   -64,   -64,   -64,   -67,   -67,
     -67,     0,     0,   -67,   -67,     0,     0,     0,     0,   -67,
     -67,   -67,   -67,   -67,   -67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -67,   -67,   -67,   -67,   -67,
      77,    78,    79,     0,     0,    80,    81,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,    92,   -33,   -33,   -33,     0,     0,   -33,   -33,     0,
       0,     0,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -33,
     -33,   -33,   -33,   -33,   -34,   -34,   -34,     0,     0,   -34,
     -34,     0,     0,     0,     0,   -34,   -34,   -34,   -34,   -34,
     -34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -34,   -34,   -34,   -34,   -34,   -35,   -35,   -35,     0,
       0,   -35,   -35,     0,     0,     0,     0,   -35,   -35,   -35,
     -35,   -35,   -35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -35,   -35,   -35,   -35,   -35,   -36,   -36,
     -36,     0,     0,   -36,   -36,     0,     0,     0,     0,   -36,
     -36,   -36,   -36,   -36,   -36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,   -36,
     -60,   -60,   -60,     0,     0,   -60,   -60,     0,     0,     0,
       0,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -60,   -60,   -60,
     -60,   -60,   -61,   -61,   -61,     0,     0,   -61,   -61,     0,
       0,     0,     0,   -61,   -61,   -61,   -61,   -61,   -61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -61,
     -61,   -61,   -61,   -61,   -62,   -62,   -62,     0,     0,   -62,
     -62,     0,     0,     0,     0,   -62,   -62,   -62,   -62,   -62,
     -62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -62,   -62,   -62,   -62,   -62,   -63,   -63,   -63,     0,
       0,   -63,   -63,     0,     0,     0,     0,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -63,   -63,   -63,   -63,   -63,   -37,   -37,
     -37,     0,     0,   -37,   -37,     0,     0,     0,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,   -37,
     -55,   -55,   -55,     0,     0,   -55,   -55,     0,     0,     0,
       0,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -55,   -55,   -55,
     -55,   -55,   -56,   -56,   -56,     0,     0,   -56,   -56,     0,
       0,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -56,
     -56,   -56,   -56,   -56,   -57,   -57,   -57,     0,     0,   -57,
     -57,     0,     0,     0,     0,   -57,   -57,   -57,   -57,   -57,
     -57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -57,   -57,   -57,   -57,   -57,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,   -29,   -58,   -58,
     -58,     0,     0,   -58,   -58,     0,     0,     0,     0,   -58,
     -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -58,   -58,   -58,   -58,   -58,
     -59,   -59,   -59,     0,     0,   -59,   -59,     0,     0,     0,
       0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -59,   -59,   -59,
     -59,   -59,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,   -31,   -39,   -39,   -39,     0,     0,   -39,
     -39,     0,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,
     -39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -39,   -39,   -39,   -39,   -39,   -52,    78,    79,     0,
       0,   -52,   -52,     0,     0,     0,     0,   -52,   -52,   -52,
     -52,   -52,   -52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,   -52,   -53,   -53,
      79,     0,     0,   -53,   -53,     0,     0,     0,     0,   -53,
     -53,   -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,   -53,
     -54,   -54,   -54,     0,     0,   -54,   -54,     0,     0,     0,
       0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,   -54,    77,    78,    79,     0,     0,   -40,    81,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,   -40,    77,    78,    79,     0,     0,   -41,
     -41,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,   -41,    77,    78,    79,     0,
       0,   -42,   -42,     0,     0,     0,     0,   -42,   -42,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,   -42,    77,    78,
      79,     0,     0,   -43,   -43,     0,     0,     0,     0,   -43,
     -43,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,   -43,
      77,    78,    79,     0,     0,   -44,   -44,     0,     0,     0,
       0,   -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,   -44,    77,    78,    79,     0,     0,   -45,   -45,     0,
       0,     0,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,   -45,    77,    78,    79,     0,     0,   -46,
     -46,     0,     0,     0,     0,   -46,   -46,   -46,   -46,   -46,
     -46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,   -46,    77,    78,    79,     0,
       0,   -47,   -47,     0,     0,     0,     0,   -47,   -47,   -47,
     -47,   -47,   -47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,   -47,   -48,   -48,
     -48,     0,     0,   -48,   -48,     0,     0,     0,     0,   -48,
     -48,   -48,   -48,   -48,   -48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -48,   -48,    90,    91,   -48,
     -49,   -49,   -49,     0,     0,   -49,   -49,     0,     0,     0,
       0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -49,   -49,    90,
      91,   -49,   -50,   -50,   -50,     0,     0,   -50,   -50,     0,
       0,     0,     0,   -50,   -50,   -50,   -50,   -50,   -50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -50,
     -50,   -50,   -50,   -50,   -51,   -51,   -51,     0,     0,   -51,
     -51,     0,     0,     0,     0,   -51,   -51,   -51,   -51,   -51,
     -51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -51,   -51,   -51,   -51,   -51,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,   -32,   -69,   -69,
     -69,     0,     0,   -69,   -69,     0,     0,     0,     0,   -69,
     -69,   -69,   -69,   -69,   -69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -69,   -69,   -69,   -69,   -69,
     -70,   -70,   -70,     0,     0,   -70,   -70,     0,     0,     0,
       0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -70,   -70,   -70,
     -70,   -70,   -68,   -68,   -68,     0,     0,   -68,   -68,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -68,
     -68,   -68,   -68,   -68,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,   283
};

static const yytype_int16 yycheck[] =
{
       9,    20,   138,    94,     3,     4,     5,     6,     0,     7,
      19,     3,     4,     5,     6,     0,     7,     0,     3,     4,
       5,     6,     5,    48,    49,     7,     8,     9,    10,    11,
      12,    40,    14,    15,    16,   124,     3,     4,     5,     6,
      50,   130,     7,     0,     7,   134,     3,     4,     5,     6,
      52,    50,   124,    62,    63,    64,     7,   124,     7,    68,
      49,    43,    44,    45,   124,     0,    53,    49,    50,   125,
       5,    48,    49,     0,    49,   131,     3,     4,     5,     6,
      15,    50,    51,    49,   220,    94,    21,     7,     8,     9,
      10,    11,    12,   124,    14,    15,    16,     0,    50,    51,
       3,     4,     5,     6,    49,   124,    50,    51,     7,     8,
       9,    10,    11,    12,   123,    14,    15,    16,    50,    51,
      50,    51,   131,    43,    44,    45,    50,    51,     0,    49,
      50,     3,     4,     5,     6,    48,   145,   146,   147,   230,
     149,   150,   151,     7,    43,    44,    45,   238,     0,   240,
      49,     3,     4,     5,     6,    48,     7,   248,    50,    50,
      48,   170,   171,   172,    50,   174,   175,   176,     0,    48,
      50,     3,     4,     5,     6,    49,    49,    48,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    50,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    31,
      32,    33,    49,    49,    36,   304,    38,    39,    40,   308,
     229,   230,    49,   312,   280,    49,     5,    48,   237,   238,
     239,   240,   304,    53,    53,    50,   308,   304,   247,   248,
     312,   308,    64,    50,   304,   312,    68,    69,   308,   305,
      50,    50,   312,   309,    50,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     279,    93,    94,   304,    50,    48,    48,   308,    21,    50,
      44,   312,    -1,    -1,    -1,   304,    -1,    -1,    -1,   308,
      -1,    -1,    -1,   312,    -1,    -1,    -1,    -1,    -1,    -1,
     309,   123,   124,   125,    -1,    -1,    17,    18,    19,   131,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,   145,   146,   147,    -1,   149,   150,   151,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
     172,    -1,   174,   175,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,   280,    94,
      -1,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,   304,   305,    52,    53,   308,   309,   123,    -1,
     312,    -1,    -1,    -1,    -1,    -1,   131,    43,    44,    45,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,    17,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,   170,   171,   172,    -1,   174,
     175,   176,    -1,    -1,    44,    45,    46,    47,    -1,    49,
      50,    51,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,    -1,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,   240,    -1,    -1,    -1,    -1,
      64,    -1,   247,   248,    68,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      94,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    43,    44,    45,   123,
      -1,    -1,    49,    -1,   309,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,   170,   171,   172,    -1,
     174,   175,   176,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    51,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    -1,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,   240,    -1,    -1,    -1,
      -1,    64,    -1,   247,   248,    68,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    94,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    43,    44,    45,
     123,    -1,    -1,    49,    -1,   309,    -1,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,   146,   147,    -1,   149,   150,   151,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,   170,   171,   172,
      -1,   174,   175,   176,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    51,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,    -1,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,   240,    -1,    -1,
      -1,    -1,    64,    -1,   247,   248,    68,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    -1,   279,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,
      -1,   123,    -1,    -1,    -1,    -1,   309,    -1,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,   170,   171,
     172,    -1,   174,   175,   176,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    51,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,   240,    -1,
      -1,    -1,    -1,    64,    -1,   247,   248,    68,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,   279,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      -1,    -1,   123,    -1,    -1,    -1,    -1,   309,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,   150,
     151,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,   170,
     171,   172,    -1,   174,   175,   176,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,   240,
      -1,    -1,    -1,    -1,    64,    -1,   247,   248,    68,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,   279,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   309,    -1,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
     170,   171,   172,    -1,   174,   175,   176,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,    -1,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
     240,    -1,    -1,    -1,    -1,    64,    -1,   247,   248,    68,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,   279,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,   309,
      -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,    -1,
     149,   150,   151,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,   170,   171,   172,    -1,   174,   175,   176,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    51,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,    -1,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,   240,    -1,    -1,    -1,    -1,    64,    -1,   247,   248,
      68,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
     279,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,
     309,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,   170,   171,   172,    -1,   174,   175,   176,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    51,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,    -1,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,   240,    -1,    -1,    -1,    -1,    64,    -1,   247,
     248,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   279,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      -1,   309,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,   170,   171,   172,    -1,   174,   175,   176,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    51,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,    -1,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   230,    14,    15,    16,    -1,    -1,    -1,
     237,   238,    -1,   240,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   279,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,   309,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    39,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      39,    -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    39,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    39,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      16,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    39,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    16,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    39,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      39,    -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    39,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    39,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    52,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    51,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    51,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    49,    50,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    50,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    17,    18,    19,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    17,    18,    19,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    55,    56,    57,    58,    85,
       0,    56,     7,    84,    48,    49,    59,    60,    61,    85,
      50,    51,    84,    52,    62,    61,     8,     9,    10,    11,
      12,    14,    15,    16,    39,    41,    42,    43,    44,    45,
      49,    57,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    84,    85,    49,    49,    72,    72,    72,    49,    49,
      72,    72,    72,    72,    53,    65,    48,    17,    18,    19,
      22,    23,    28,    29,    30,    31,    32,    33,    44,    45,
      46,    47,    48,    21,    49,    84,    84,    72,    82,    83,
      72,    71,    72,    50,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      82,    50,    50,    51,    50,    48,    50,    72,    66,    71,
      40,    48,    66,    71,    50,    66,     7,     7,    52,     7,
       8,     9,    10,    11,    12,    14,    15,    16,    43,    44,
      45,    49,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    84,     7,     7,     7,     8,     9,    10,    11,    12,
      14,    15,    16,    43,    44,    45,    49,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    84,    17,    18,    19,
      22,    23,    28,    29,    30,    31,    32,    33,    44,    45,
      46,    47,    48,    17,    18,    19,    22,    23,    28,    29,
      30,    31,    32,    33,    44,    45,    46,    47,    39,    41,
      52,    62,    67,    68,    69,    70,    72,    72,    63,    49,
      49,    72,    72,    72,    72,    72,    72,    21,    49,    49,
      49,    72,    72,    72,    72,    72,    72,    21,    49,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    49,
      49,    63,    48,    48,    53,    84,    82,    50,    72,    82,
      84,    82,    50,    72,    82,    72,    71,    53,    50,    50,
      50,    50,    50,    50,    50,    48,    66,    71,    40,    48,
      66,    71,    50,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    58,    59,    59,
      60,    60,    61,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    67,    68,    68,    69,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    76,    76,    76,    77,    78,    79,    80,    81,    81,
      81,    82,    82,    83,    83,    84,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     3,     6,     0,     1,
       3,     1,     2,     3,     0,     1,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     5,     7,     9,     2,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     1,     3,     1,     1,     1,     1,     1,     1
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
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2707 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2715 "bison.tab.c"
        break;

    case YYSYMBOL_INT_LIST_TOKEN: /* INT_LIST_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2723 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_LIST_TOKEN: /* FLOAT_LIST_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2731 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2739 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2747 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2755 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2763 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2771 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2779 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2787 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2795 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2803 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2811 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2819 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2827 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2835 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2843 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2851 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2859 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2867 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2875 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2883 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2891 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2899 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2907 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2915 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2923 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2931 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2939 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2947 "bison.tab.c"
        break;

    case YYSYMBOL_constantString: /* constantString  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2955 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2963 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2971 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2979 "bison.tab.c"
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
#line 96 "./src/bison.y"
                             {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 3277 "bison.tab.c"
    break;

  case 3: /* startProgram: declaration  */
#line 99 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 3285 "bison.tab.c"
    break;

  case 4: /* declaration: variableDeclare  */
#line 105 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3293 "bison.tab.c"
    break;

  case 5: /* declaration: functionDeclare  */
#line 108 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3301 "bison.tab.c"
    break;

  case 6: /* variableDeclare: type id ';'  */
#line 114 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_VAR_DECLARE, "variable declare");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
        switch((yyvsp[-2].astnode)->context->type){
            case AST_TYPE_INT:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-1].astnode)->context->name), 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, scope, INT_SYMBOL_CONST, 0));
            break;

            case AST_TYPE_FLOAT:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-1].astnode)->context->name), 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, scope, FLOAT_SYMBOL_CONST, 0));
            break;

            case AST_TYPE_INT_LIST:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-1].astnode)->context->name), 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, scope, INT_LIST_SYMBOL_CONST, 0));
            break;

            case AST_TYPE_FLOAT_LIST:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-1].astnode)->context->name), 0, (yylsp[-1]).first_line, (yylsp[-1]).first_column, scope, FLOAT_LIST_SYMBOL_CONST, 0));
            break;

        }
        symbol_id++;
    }
#line 3330 "bison.tab.c"
    break;

  case 7: /* functionDeclare: type id '(' optListParams ')' compoundStatement  */
#line 141 "./src/bison.y"
                                                    {
        /* Lidar com contextos */
        (yyval.astnode) = create_astnode_context(AST_FUNC_DECLARE, "func declare");
        insert_kid((yyvsp[-5].astnode), (yyval.astnode));
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        switch((yyvsp[-5].astnode)->context->type){
            case AST_TYPE_INT:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-4].astnode)->context->name), 0, (yylsp[-4]).first_line, (yylsp[-4]).first_column, scope, INT_SYMBOL_CONST, 1));
            break;

            case AST_TYPE_FLOAT:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-4].astnode)->context->name), 0, (yylsp[-4]).first_line, (yylsp[-4]).first_column, scope, FLOAT_SYMBOL_CONST, 1));
            break;

            case AST_TYPE_INT_LIST:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-4].astnode)->context->name), 0, (yylsp[-4]).first_line, (yylsp[-4]).first_column, scope, INT_LIST_SYMBOL_CONST, 1));
            break;

            case AST_TYPE_FLOAT_LIST:
            insert_symbol(symbol_table, create_symbol(symbol_id, strdup((yyvsp[-4].astnode)->context->name), 0, (yylsp[-4]).first_line, (yylsp[-4]).first_column, scope, FLOAT_LIST_SYMBOL_CONST, 1));
            break;

        }
        symbol_id++;
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
#line 3373 "bison.tab.c"
    break;

  case 8: /* optListParams: %empty  */
#line 182 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3381 "bison.tab.c"
    break;

  case 10: /* listParams: listParams ',' param  */
#line 189 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 3390 "bison.tab.c"
    break;

  case 11: /* listParams: param  */
#line 193 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3399 "bison.tab.c"
    break;

  case 12: /* param: type id  */
#line 200 "./src/bison.y"
            {
        (yyval.astnode) = create_astnode_context(AST_PARAM, "param");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3409 "bison.tab.c"
    break;

  case 13: /* compoundStatement: '{' optListCodeBlock '}'  */
#line 209 "./src/bison.y"
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
    }
#line 3429 "bison.tab.c"
    break;

  case 14: /* optListCodeBlock: %empty  */
#line 227 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3437 "bison.tab.c"
    break;

  case 16: /* listCodeBlock: listCodeBlock codeBlock  */
#line 234 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 3446 "bison.tab.c"
    break;

  case 17: /* listCodeBlock: codeBlock  */
#line 238 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3455 "bison.tab.c"
    break;

  case 18: /* codeBlock: statement  */
#line 245 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3464 "bison.tab.c"
    break;

  case 19: /* codeBlock: variableDeclare  */
#line 249 "./src/bison.y"
                      {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3473 "bison.tab.c"
    break;

  case 20: /* statement: flowExpression  */
#line 256 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3482 "bison.tab.c"
    break;

  case 21: /* statement: compoundStatement  */
#line 260 "./src/bison.y"
                        {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3491 "bison.tab.c"
    break;

  case 22: /* statement: expression ';'  */
#line 264 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3500 "bison.tab.c"
    break;

  case 23: /* flowExpression: condExpression  */
#line 271 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3508 "bison.tab.c"
    break;

  case 24: /* flowExpression: interationExpression  */
#line 274 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3516 "bison.tab.c"
    break;

  case 25: /* flowExpression: returnExpression ';'  */
#line 277 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 3524 "bison.tab.c"
    break;

  case 26: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 283 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3534 "bison.tab.c"
    break;

  case 27: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 288 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3545 "bison.tab.c"
    break;

  case 28: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 297 "./src/bison.y"
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
#line 3560 "bison.tab.c"
    break;

  case 29: /* returnExpression: RETURN_TOKEN expression  */
#line 310 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return expression");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3569 "bison.tab.c"
    break;

  case 30: /* optExpression: %empty  */
#line 317 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 3577 "bison.tab.c"
    break;

  case 31: /* optExpression: expression  */
#line 320 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3585 "bison.tab.c"
    break;

  case 32: /* expression: id ASSIGN_TOKEN expression  */
#line 326 "./src/bison.y"
                               {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3595 "bison.tab.c"
    break;

  case 33: /* expression: binArith  */
#line 331 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3604 "bison.tab.c"
    break;

  case 34: /* expression: listArith  */
#line 335 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3613 "bison.tab.c"
    break;

  case 35: /* expression: unaArith  */
#line 339 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3622 "bison.tab.c"
    break;

  case 36: /* expression: constant  */
#line 343 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3631 "bison.tab.c"
    break;

  case 37: /* expression: funcCall  */
#line 347 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3640 "bison.tab.c"
    break;

  case 38: /* expression: id  */
#line 351 "./src/bison.y"
         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3649 "bison.tab.c"
    break;

  case 39: /* expression: '(' expression ')'  */
#line 355 "./src/bison.y"
                         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3658 "bison.tab.c"
    break;

  case 40: /* binArith: expression OR_TOKEN expression  */
#line 362 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3668 "bison.tab.c"
    break;

  case 41: /* binArith: expression AND_TOKEN expression  */
#line 367 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3678 "bison.tab.c"
    break;

  case 42: /* binArith: expression EQUAL_TOKEN expression  */
#line 372 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3688 "bison.tab.c"
    break;

  case 43: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 377 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3698 "bison.tab.c"
    break;

  case 44: /* binArith: expression LESS_TOKEN expression  */
#line 382 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3708 "bison.tab.c"
    break;

  case 45: /* binArith: expression LE_EQ_TOKEN expression  */
#line 387 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3718 "bison.tab.c"
    break;

  case 46: /* binArith: expression GREAT_TOKEN expression  */
#line 392 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3728 "bison.tab.c"
    break;

  case 47: /* binArith: expression GR_EQ_TOKEN expression  */
#line 397 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3738 "bison.tab.c"
    break;

  case 48: /* binArith: expression '+' expression  */
#line 402 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3748 "bison.tab.c"
    break;

  case 49: /* binArith: expression '-' expression  */
#line 407 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3758 "bison.tab.c"
    break;

  case 50: /* binArith: expression '*' expression  */
#line 412 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3768 "bison.tab.c"
    break;

  case 51: /* binArith: expression '/' expression  */
#line 417 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3778 "bison.tab.c"
    break;

  case 52: /* listArith: expression MAP_TOKEN expression  */
#line 425 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3788 "bison.tab.c"
    break;

  case 53: /* listArith: expression FILTER_TOKEN expression  */
#line 430 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3798 "bison.tab.c"
    break;

  case 54: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 435 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3808 "bison.tab.c"
    break;

  case 55: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 443 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3817 "bison.tab.c"
    break;

  case 56: /* unaArith: QUESTION_TOKEN expression  */
#line 447 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3826 "bison.tab.c"
    break;

  case 57: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 451 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3835 "bison.tab.c"
    break;

  case 58: /* unaArith: '+' expression  */
#line 455 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3844 "bison.tab.c"
    break;

  case 59: /* unaArith: '-' expression  */
#line 459 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3853 "bison.tab.c"
    break;

  case 60: /* constant: constantInteger  */
#line 466 "./src/bison.y"
                    {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant int");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3862 "bison.tab.c"
    break;

  case 61: /* constant: constantReal  */
#line 470 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant real");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3871 "bison.tab.c"
    break;

  case 62: /* constant: constantNIL  */
#line 474 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant nil");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3880 "bison.tab.c"
    break;

  case 63: /* constant: constantString  */
#line 478 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant string");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3889 "bison.tab.c"
    break;

  case 64: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 485 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3897 "bison.tab.c"
    break;

  case 65: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 491 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3905 "bison.tab.c"
    break;

  case 66: /* constantNIL: NIL_TOKEN  */
#line 497 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3913 "bison.tab.c"
    break;

  case 67: /* constantString: STRING_TOKEN  */
#line 503 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3921 "bison.tab.c"
    break;

  case 68: /* funcCall: id '(' optListExpression ')'  */
#line 509 "./src/bison.y"
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
#line 3940 "bison.tab.c"
    break;

  case 69: /* funcCall: READ_TOKEN '(' id ')'  */
#line 523 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_FUNC_CALL, "func call");
        insert_kid((yyvsp[-3].astnode), (yyval.astnode));
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3950 "bison.tab.c"
    break;

  case 70: /* funcCall: WRITE_TOKEN '(' optListExpression ')'  */
#line 528 "./src/bison.y"
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
#line 3969 "bison.tab.c"
    break;

  case 71: /* optListExpression: %empty  */
#line 545 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3977 "bison.tab.c"
    break;

  case 73: /* listExpression: listExpression ',' expression  */
#line 552 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 3986 "bison.tab.c"
    break;

  case 74: /* listExpression: expression  */
#line 556 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3995 "bison.tab.c"
    break;

  case 75: /* id: ID_TOKEN  */
#line 563 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4003 "bison.tab.c"
    break;

  case 76: /* type: INT_TOKEN  */
#line 569 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4011 "bison.tab.c"
    break;

  case 77: /* type: FLOAT_TOKEN  */
#line 572 "./src/bison.y"
                  {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4019 "bison.tab.c"
    break;

  case 78: /* type: INT_LIST_TOKEN  */
#line 575 "./src/bison.y"
                     {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4027 "bison.tab.c"
    break;

  case 79: /* type: FLOAT_LIST_TOKEN  */
#line 578 "./src/bison.y"
                       {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4035 "bison.tab.c"
    break;


#line 4039 "bison.tab.c"

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

#line 583 "./src/bison.y"


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
    symbol_table = create_symbol_table();

    yyparse();

    if(root->kids->size > 0) {
        printf("##################### %s #####################\n", "Abstract Syntax Tree");
        print_tree(root, 0);
        printf("\n");
    } else {
        printf("Unable to print AST\n");
    }
    if(symbol_table->symbols->size > 0) {
        printf("########################## %s #########################\n", "Symbol Table");
        printf("# %-14s || %11s || %-10s || %4s || %6s #\n", "Type", "Symbol Kind", "ID", "Line", "Column");
        print_list(symbol_table->symbols, print_symbol_list);
        printf("#################################################################\n");
    } else {
        printf("Unable to print Symbol Table\n");
    }

    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_symbol_table(symbol_table, delete_list_symbol_table);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
