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
#define YYLAST   6878

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

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
     189,   193,   200,   209,   228,   231,   235,   239,   246,   250,
     257,   261,   265,   272,   275,   278,   284,   289,   298,   311,
     318,   321,   327,   332,   336,   340,   344,   348,   352,   356,
     363,   368,   373,   378,   383,   388,   393,   398,   403,   408,
     413,   418,   426,   431,   436,   444,   448,   452,   456,   460,
     467,   471,   475,   479,   486,   492,   498,   504,   510,   524,
     538,   555,   558,   562,   566,   573,   579,   582,   585,   588
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
      66,     4,    10,    20,    27,     9,    16,    61,   148,    29,
    -137,   167,   -23,   -16,   268,     1,    -4,   -13,    36,    55,
       6,    66,    49,  2164,   275,    51,     7,    11,  5518,  5550,
    5582,   531,   531,   531,    24,    26,   531,  5614,   531,   531,
     674,  2179,  2230,    31,  2245,  2296,  2311,  2362,  2377,  2428,
      40,  5646,  5678,  5710,  5742,  5774,  5806,  5838,  5870,  5902,
    5934,  5452,    72,   100,   100,  5966,  5998,  6030,   674,    33,
    6062,  6094,  6126,   908,   335,  2443,  2494,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,  2509,   531,   100,    47,  2794,    56,    53,    69,
    1088,    80,  6158,  6190,  6222,  6254,  6286,  6318,  6350,  6382,
    6414,  6446,  6478,  6510,  6542,  6574,  6606,  6638,  6670,  6702,
      70,  6734,   854,  6766,    82,    33,  6798,  2829,   479,    81,
    2688,   318,  2560,    83,  2688,  2575,    67,  5485,  2164,   361,
      86,    90,  1268,  1448,  1628,   674,   674,   674,  1808,   674,
     674,   674,  1988,  4194,  4228,  4262,  4296,  4330,  4364,  4398,
    4432,   728,    84,  2724,    97,    98,  2864,  2899,  2934,   854,
     854,   854,  2969,   854,   854,   674,  3004,  3039,  3074,  3109,
    3144,  3179,  3214,  3249,  3284,  2759,   674,   674,   674,   674,
     674,   674,   674,   674,   674,   674,   674,   674,   674,   674,
     674,  2626,   854,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   854,   854,   854,   854,   106,   107,  2164,
     659,   839,  1019,  1199,   109,  6830,  4466,    77,   100,   100,
    4500,  4534,  4568,  4602,  4636,  4670,   674,   100,   100,   100,
    3319,  3354,  3389,  3424,  3459,  4704,   854,   100,  4738,  4772,
    4806,  4840,  4874,  4908,  4942,  4976,  5010,  5044,  5078,  5112,
    5146,  5180,  5214,  3494,  3529,  3564,  3599,  3634,  3669,  3704,
    3739,  3774,  3809,  3844,  3879,  3914,  3949,  3984,   674,    33,
     105,  1379,  1559,  2641,   113,   118,  5248,  5282,   119,   124,
     125,  4019,  4054,   126,  5316,   111,  1739,  5350,  5384,  5418,
    4089,  4124,  4159,    82,    33,  1919,   144,    82,   318,  2098,
     160,    82,  2113
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
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   206,    23,  -137,  -137,  -137,   197,   -19,  -136,
    -137,   177,   -95,   -94,   -72,   -67,   -61,   -57,   226,   413,
     593,   773,   953,  1133,  1313,  1493,  1673,  1853,   -14,  -137,
      -9,     3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,    41,     8,    16,    17,    18,    42,    43,
      44,    45,    46,    47,    48,    49,    50,   101,    96,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    97,    98,
      61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    24,   227,     9,     1,     2,     3,     4,     9,    10,
      22,   -76,     1,     2,     3,     4,    -3,   -77,    19,    -3,
      -3,    -3,    -3,     7,    19,   -75,   -75,   -78,     7,   128,
     221,   161,    14,    15,   -79,   132,    12,    -9,    21,   135,
     137,    26,    27,    28,    29,    30,    20,    31,    32,    33,
      99,    -8,   222,    95,   185,   185,    63,   223,    23,   161,
      64,    -4,   136,   224,    -4,    -4,    -4,    -4,   129,     1,
       2,     3,     4,    68,   133,    69,    37,    38,    39,   162,
     120,   -30,    40,   280,    74,   185,   -11,   -11,    76,   137,
      26,    27,    28,    29,    30,   201,    31,    32,    33,   -12,
     -12,   -10,   -10,   -72,   122,   220,   121,   163,   164,   165,
     166,   167,   168,   185,   169,   170,   171,   -75,   -75,   123,
     126,   217,   161,   218,    36,    37,    38,    39,   125,   131,
     283,    40,   -75,   134,   219,   228,   161,   161,   161,   229,
     161,   161,   161,   172,   173,   174,   238,   239,    -5,   175,
     -71,    -5,    -5,    -5,    -5,   278,   279,   281,   296,   304,
     185,   185,   185,   297,   185,   185,   161,    -2,   298,   299,
      -2,    -2,    -2,    -2,   300,   301,   302,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   308,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   305,   221,
     311,    11,   309,   221,   284,   285,   312,   221,    25,   185,
     185,    75,   295,   288,   289,   290,     0,   161,   185,   185,
     185,   222,     0,   293,     0,   222,   223,   185,   185,   222,
     223,     0,   224,     0,   223,     0,   224,   306,     0,    51,
     224,   310,     0,     0,     0,     0,     0,    65,    66,    67,
       0,     0,    70,     0,    71,    72,    73,     0,    -6,   161,
      51,    -6,    -6,    -6,    -6,    -7,     0,     0,    -7,    -7,
      -7,    -7,     0,     0,   220,     0,     0,     0,   220,     0,
       0,     0,   220,     0,   100,   102,     0,     0,     0,   161,
       0,     0,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,     0,   145,   146,   147,   -13,     0,     0,   -13,   -13,
     -13,   -13,     0,     0,     0,     0,     0,     0,   127,     0,
     225,   102,     0,     0,     0,     0,    51,   226,     0,     0,
      51,   148,   149,   150,    51,     0,     0,   151,   -30,     0,
       0,   230,   231,   232,     0,   233,   234,   235,   -75,   -75,
     -75,     0,   -75,   -75,   -75,     0,     0,     0,     0,   -75,
     -75,   -75,   -75,   -75,   -75,   240,   241,   242,     0,   243,
     244,   245,     0,     0,     0,   -75,   -75,   -75,   -75,     0,
     -75,   -75,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,     0,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,   152,     0,     0,     0,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,     0,     0,     0,   176,   176,     0,     0,
       0,   152,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   102,     0,   176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -26,   130,
     -26,   -26,   -26,   -26,   -26,     0,     0,     0,   -26,   225,
     102,   -26,   -26,   225,   226,   176,     0,   225,   137,    26,
      27,    28,    29,    30,   152,    31,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,   152,
     152,     0,   152,   152,   152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,     0,     0,
      40,     0,   176,   176,   176,     0,   176,   176,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,     0,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
       0,     0,     0,   153,     0,     0,     0,     0,     0,     0,
       0,   176,   176,     0,     0,     0,     0,     0,     0,   152,
     176,   176,   176,     0,     0,     0,   177,   177,     0,   176,
     176,   153,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -21,   -21,   -21,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   177,   145,   146,
     147,   152,     0,     0,     0,     0,     0,     0,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,     0,     0,     0,   -21,     0,
       0,   -21,   -21,     0,     0,   177,     0,   148,   149,   150,
       0,   152,     0,   151,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   153,   153,
     153,     0,   153,   153,   153,   -38,   -38,   -38,     0,   236,
     -38,   -38,     0,     0,     0,     0,   -38,   -38,   -38,   -38,
     -38,   -38,   177,   177,   177,     0,   177,   177,   153,     0,
       0,     0,   -38,   -38,   -38,   -38,     0,   237,   -38,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,     0,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
       0,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,   177,   177,     0,     0,     0,     0,     0,     0,   153,
     177,   177,   177,     0,     0,     0,   178,   178,     0,   177,
     177,   154,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,     0,   -20,   -20,   -20,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   178,   169,   170,
     171,   153,     0,     0,     0,     0,     0,     0,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,     0,     0,     0,   -20,     0,
       0,   -20,   -20,     0,     0,   178,     0,   172,   173,   174,
       0,   153,     0,   175,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   154,
     154,     0,   154,   154,   154,   186,   187,   188,     0,     0,
     189,   190,     0,     0,     0,     0,   191,   192,   193,   194,
     195,   196,   178,   178,   178,     0,   178,   178,   154,     0,
       0,     0,   197,   198,   199,   200,     0,     0,   103,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,     0,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
       0,     0,     0,   155,     0,     0,     0,     0,     0,     0,
       0,   178,   178,     0,     0,     0,     0,     0,     0,   154,
     178,   178,   178,     0,     0,     0,   179,   179,     0,   178,
     178,   155,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,     0,     0,     0,   -23,     0,
       0,   -23,   -23,     0,     0,   179,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   155,   155,
     155,     0,   155,   155,   155,   186,   187,   188,     0,     0,
     189,   190,     0,     0,     0,     0,   191,   192,   193,   194,
     195,   196,   179,   179,   179,     0,   179,   179,   155,     0,
       0,     0,   197,   198,   199,   200,     0,     0,   124,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,     0,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,   179,   179,     0,     0,     0,     0,     0,     0,   155,
     179,   179,   179,     0,     0,     0,   180,   180,     0,   179,
     179,   156,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,   -24,   -24,   -24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,     0,     0,
       0,   155,     0,     0,     0,     0,     0,     0,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,     0,
       0,   -24,   -24,     0,     0,   180,     0,     0,     0,     0,
       0,   155,     0,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   156,   156,
     156,     0,   156,   156,   156,   -66,   -66,   -66,     0,     0,
     -66,   -66,     0,     0,     0,     0,   -66,   -66,   -66,   -66,
     -66,   -66,   180,   180,   180,     0,   180,   180,   156,     0,
       0,     0,   -66,   -66,   -66,   -66,     0,     0,   -66,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,     0,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
       0,     0,     0,   157,     0,     0,     0,     0,     0,     0,
       0,   180,   180,     0,     0,     0,     0,     0,     0,   156,
     180,   180,   180,     0,     0,     0,   181,   181,     0,   180,
     180,   157,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,     0,     0,
       0,   156,     0,     0,     0,     0,     0,     0,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,   -25,     0,
       0,   -25,   -25,     0,     0,   181,     0,     0,     0,     0,
       0,   156,     0,     0,   157,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   157,
     157,     0,   157,   157,   157,   -65,   -65,   -65,     0,     0,
     -65,   -65,     0,     0,     0,     0,   -65,   -65,   -65,   -65,
     -65,   -65,   181,   181,   181,     0,   181,   181,   157,     0,
       0,     0,   -65,   -65,   -65,   -65,     0,     0,   -65,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,     0,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,   181,   181,     0,     0,     0,     0,     0,     0,   157,
     181,   181,   181,     0,     0,     0,   182,   182,     0,   181,
     181,   158,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,     0,   -22,   -22,   -22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   182,     0,     0,
       0,   157,     0,     0,     0,     0,     0,     0,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,     0,     0,     0,   -22,     0,
       0,   -22,   -22,     0,     0,   182,     0,     0,     0,     0,
       0,   157,     0,     0,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   158,
     158,     0,   158,   158,   158,   -64,   -64,   -64,     0,     0,
     -64,   -64,     0,     0,     0,     0,   -64,   -64,   -64,   -64,
     -64,   -64,   182,   182,   182,     0,   182,   182,   158,     0,
       0,     0,   -64,   -64,   -64,   -64,     0,     0,   -64,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,     0,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
       0,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,   182,   182,     0,     0,     0,     0,     0,     0,   158,
     182,   182,   182,     0,     0,     0,   183,   183,     0,   182,
     182,   159,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,     0,   -13,   -13,   -13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,     0,     0,     0,   -13,     0,
       0,   -13,   -13,     0,     0,   183,     0,     0,     0,     0,
       0,   158,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   159,
     159,     0,   159,   159,   159,   -67,   -67,   -67,     0,     0,
     -67,   -67,     0,     0,     0,     0,   -67,   -67,   -67,   -67,
     -67,   -67,   183,   183,   183,     0,   183,   183,   159,     0,
       0,     0,   -67,   -67,   -67,   -67,     0,     0,   -67,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,     0,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
       0,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,   183,   183,     0,     0,     0,     0,     0,     0,   159,
     183,   183,   183,     0,     0,     0,   184,   184,     0,   183,
     183,   160,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,     0,     0,
       0,   159,     0,     0,     0,     0,     0,     0,   -26,   307,
     -26,   -26,   -26,   -26,   -26,     0,     0,     0,   -26,     0,
       0,   -26,   -26,     0,     0,   184,     0,     0,     0,     0,
       0,   159,     0,     0,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   160,
     160,     0,   160,   160,   160,   -33,   -33,   -33,     0,     0,
     -33,   -33,     0,     0,     0,     0,   -33,   -33,   -33,   -33,
     -33,   -33,   184,   184,   184,     0,   184,   184,   160,     0,
       0,     0,   -33,   -33,   -33,   -33,     0,     0,   -33,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,     0,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   184,   184,     0,     0,     0,     0,     0,     0,   160,
     184,   184,   184,     0,     0,     0,     0,     0,     0,   184,
     184,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,   -27,   -27,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,
       0,   160,     0,     0,     0,     0,     0,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,     0,     0,   -27,     0,     0,
     -27,   -27,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,
       0,   160,   -28,     0,     0,   -28,   -28,     1,     2,     3,
       4,   137,    26,    27,    28,    29,    30,     0,    31,    32,
      33,     0,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,     0,   -19,   -19,   -19,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    35,    36,    37,    38,    39,
       0,     0,     0,    40,     0,     0,   138,   -14,   -19,     0,
     -19,   -19,   -19,   -19,   -19,     0,     0,     0,   -19,     0,
       0,   -19,   -19,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,     0,   -21,   -21,   -21,     0,     1,     2,
       3,     4,   137,    26,    27,    28,    29,    30,     0,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,   -21,
       0,   -21,   -21,   -21,   -21,   -21,     0,     0,     0,   -21,
       0,     0,   -21,   -21,    34,     0,    35,    36,    37,    38,
      39,     0,     0,     0,    40,     0,     0,   138,   -15,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,
     -17,   -17,   -17,     0,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,     0,     0,
       0,     0,     0,     0,     0,   -17,     0,   -17,   -17,   -17,
     -17,   -17,     0,     0,     0,   -17,     0,     0,   -17,   -17,
     -18,     0,   -18,   -18,   -18,   -18,   -18,     0,     0,     0,
     -18,     0,     0,   -18,   -18,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,     0,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,   -23,   -23,   -23,     0,     0,     0,     0,     0,     0,
       0,   -20,     0,   -20,   -20,   -20,   -20,   -20,     0,     0,
       0,   -20,     0,     0,   -20,   -20,   -23,     0,   -23,   -23,
     -23,   -23,   -23,     0,     0,     0,   -23,     0,     0,   -23,
     -23,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,     0,   -24,   -24,   -24,     0,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,     0,   -16,   -16,   -16,
       0,     0,     0,     0,     0,     0,     0,   -24,     0,   -24,
     -24,   -24,   -24,   -24,     0,     0,     0,   -24,     0,     0,
     -24,   -24,   -16,     0,   -16,   -16,   -16,   -16,   -16,     0,
       0,     0,   -16,     0,     0,   -16,   -16,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,
     -25,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,     0,   -22,   -22,   -22,     0,     0,     0,     0,
       0,     0,     0,   -25,     0,   -25,   -25,   -25,   -25,   -25,
       0,     0,     0,   -25,     0,     0,   -25,   -25,   -22,     0,
     -22,   -22,   -22,   -22,   -22,     0,     0,     0,   -22,     0,
       0,   -22,   -22,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -27,   -27,   -27,     0,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,   -28,     0,     0,     0,     0,     0,     0,     0,   -27,
       0,   -27,   -27,   -27,   -27,   -27,     0,     0,     0,   -27,
       0,     0,   -27,   -27,   -28,     0,   -28,   -28,   -28,   -28,
     -28,     0,     0,     0,   -28,     0,     0,   -28,   -28,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,     0,
      -6,    -6,    -6,     0,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,     0,   -13,   -13,   -13,     0,     0,
       0,     0,     0,     0,     0,    -6,     0,    -6,    -6,    -6,
      -6,    -6,     0,     0,     0,    -6,     0,     0,    -6,    -6,
     -13,     0,   -13,   -13,   -13,   -13,   -13,     0,     0,     0,
     -13,     0,     0,   -13,   -13,   137,    26,    27,    28,    29,
      30,     0,    31,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,    35,
      36,    37,    38,    39,     0,     0,     0,    40,     0,     0,
     138,   -75,   -75,   -75,     0,   -75,   -75,   -75,     0,     0,
       0,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -75,   -75,
     -75,   -75,     0,   -75,   -75,   -75,   -38,   -38,   -38,     0,
     246,   -38,   -38,     0,     0,     0,     0,   -38,   -38,   -38,
     -38,   -38,   -38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -38,   -38,   -38,   -38,     0,   247,   -38,
     -38,   202,   203,   204,     0,     0,   205,   206,     0,     0,
       0,     0,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -74,   -74,   202,   203,   204,     0,
       0,   205,   206,     0,     0,     0,     0,   207,   208,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,     0,     0,   -73,
     -73,   -66,   -66,   -66,     0,     0,   -66,   -66,     0,     0,
       0,     0,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -66,   -66,
     -66,   -66,     0,     0,   -66,   -66,   -65,   -65,   -65,     0,
       0,   -65,   -65,     0,     0,     0,     0,   -65,   -65,   -65,
     -65,   -65,   -65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -65,   -65,   -65,   -65,     0,     0,   -65,
     -65,   -64,   -64,   -64,     0,     0,   -64,   -64,     0,     0,
       0,     0,   -64,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -64,   -64,
     -64,   -64,     0,     0,   -64,   -64,   -67,   -67,   -67,     0,
       0,   -67,   -67,     0,     0,     0,     0,   -67,   -67,   -67,
     -67,   -67,   -67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -67,   -67,   -67,   -67,     0,     0,   -67,
     -67,   -33,   -33,   -33,     0,     0,   -33,   -33,     0,     0,
       0,     0,   -33,   -33,   -33,   -33,   -33,   -33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -33,   -33,
     -33,   -33,     0,     0,   -33,   -33,   -34,   -34,   -34,     0,
       0,   -34,   -34,     0,     0,     0,     0,   -34,   -34,   -34,
     -34,   -34,   -34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -34,   -34,   -34,   -34,     0,     0,   -34,
     -34,   -35,   -35,   -35,     0,     0,   -35,   -35,     0,     0,
       0,     0,   -35,   -35,   -35,   -35,   -35,   -35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -35,   -35,
     -35,   -35,     0,     0,   -35,   -35,   -36,   -36,   -36,     0,
       0,   -36,   -36,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -36,   -36,   -36,   -36,     0,     0,   -36,
     -36,   -60,   -60,   -60,     0,     0,   -60,   -60,     0,     0,
       0,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -60,   -60,
     -60,   -60,     0,     0,   -60,   -60,   -61,   -61,   -61,     0,
       0,   -61,   -61,     0,     0,     0,     0,   -61,   -61,   -61,
     -61,   -61,   -61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -61,   -61,   -61,   -61,     0,     0,   -61,
     -61,   -62,   -62,   -62,     0,     0,   -62,   -62,     0,     0,
       0,     0,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -62,   -62,
     -62,   -62,     0,     0,   -62,   -62,   -63,   -63,   -63,     0,
       0,   -63,   -63,     0,     0,     0,     0,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -63,   -63,   -63,   -63,     0,     0,   -63,
     -63,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,     0,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -37,   -37,
     -37,   -37,     0,     0,   -37,   -37,   -55,   -55,   -55,     0,
       0,   -55,   -55,     0,     0,     0,     0,   -55,   -55,   -55,
     -55,   -55,   -55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -55,   -55,   -55,   -55,     0,     0,   -55,
     -55,   -56,   -56,   -56,     0,     0,   -56,   -56,     0,     0,
       0,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -56,   -56,
     -56,   -56,     0,     0,   -56,   -56,   -57,   -57,   -57,     0,
       0,   -57,   -57,     0,     0,     0,     0,   -57,   -57,   -57,
     -57,   -57,   -57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -57,   -57,   -57,   -57,     0,     0,   -57,
     -57,   -58,   -58,   -58,     0,     0,   -58,   -58,     0,     0,
       0,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -58,   -58,     0,     0,   -58,   -58,   -59,   -59,   -59,     0,
       0,   -59,   -59,     0,     0,     0,     0,   -59,   -59,   -59,
     -59,   -59,   -59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -59,   -59,   -59,   -59,     0,     0,   -59,
     -59,   -52,   203,   204,     0,     0,   -52,   -52,     0,     0,
       0,     0,   -52,   -52,   -52,   -52,   -52,   -52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -52,   -52,   -53,   -53,   204,     0,
       0,   -53,   -53,     0,     0,     0,     0,   -53,   -53,   -53,
     -53,   -53,   -53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,     0,     0,   -53,
     -53,   -54,   -54,   -54,     0,     0,   -54,   -54,     0,     0,
       0,     0,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -54,   -54,   202,   203,   204,     0,
       0,   -40,   206,     0,     0,     0,     0,   207,   208,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,     0,     0,   -40,
     -40,   202,   203,   204,     0,     0,   -41,   -41,     0,     0,
       0,     0,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -41,   -41,   202,   203,   204,     0,
       0,   -42,   -42,     0,     0,     0,     0,   -42,   -42,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,     0,     0,   -42,
     -42,   202,   203,   204,     0,     0,   -43,   -43,     0,     0,
       0,     0,   -43,   -43,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -43,   -43,   202,   203,   204,     0,
       0,   -44,   -44,     0,     0,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,     0,     0,   -44,
     -44,   202,   203,   204,     0,     0,   -45,   -45,     0,     0,
       0,     0,   -45,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -45,   -45,   202,   203,   204,     0,
       0,   -46,   -46,     0,     0,     0,     0,   -46,   -46,   -46,
     -46,   -46,   -46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,   214,   215,   216,     0,     0,   -46,
     -46,   202,   203,   204,     0,     0,   -47,   -47,     0,     0,
       0,     0,   -47,   -47,   -47,   -47,   -47,   -47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -47,   -47,   -48,   -48,   -48,     0,
       0,   -48,   -48,     0,     0,     0,     0,   -48,   -48,   -48,
     -48,   -48,   -48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -48,   -48,   215,   216,     0,     0,   -48,
     -48,   -49,   -49,   -49,     0,     0,   -49,   -49,     0,     0,
       0,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -49,   -49,
     215,   216,     0,     0,   -49,   -49,   -50,   -50,   -50,     0,
       0,   -50,   -50,     0,     0,     0,     0,   -50,   -50,   -50,
     -50,   -50,   -50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -50,   -50,   -50,   -50,     0,     0,   -50,
     -50,   -51,   -51,   -51,     0,     0,   -51,   -51,     0,     0,
       0,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,   -51,     0,     0,   -51,   -51,   -39,   -39,   -39,     0,
       0,   -39,   -39,     0,     0,     0,     0,   -39,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -39,   -39,   -39,   -39,     0,     0,   -39,
     -39,   202,   203,   204,     0,     0,   205,   206,     0,     0,
       0,     0,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,   214,
     215,   216,     0,     0,   -32,   -32,   -69,   -69,   -69,     0,
       0,   -69,   -69,     0,     0,     0,     0,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -69,   -69,   -69,   -69,     0,     0,   -69,
     -69,   -70,   -70,   -70,     0,     0,   -70,   -70,     0,     0,
       0,     0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -70,   -70,
     -70,   -70,     0,     0,   -70,   -70,   -68,   -68,   -68,     0,
       0,   -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,
     -68,   -68,   -68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -68,   -68,   -68,   -68,     0,     0,   -68,
     -68,   -34,   -34,   -34,     0,     0,   -34,   -34,     0,     0,
       0,     0,   -34,   -34,   -34,   -34,   -34,   -34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -34,   -34,
     -34,   -34,     0,     0,   -34,   -35,   -35,   -35,     0,     0,
     -35,   -35,     0,     0,     0,     0,   -35,   -35,   -35,   -35,
     -35,   -35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -35,   -35,   -35,   -35,     0,     0,   -35,   -36,
     -36,   -36,     0,     0,   -36,   -36,     0,     0,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -36,   -36,   -36,   -36,
       0,     0,   -36,   -60,   -60,   -60,     0,     0,   -60,   -60,
       0,     0,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -60,   -60,   -60,   -60,     0,     0,   -60,   -61,   -61,   -61,
       0,     0,   -61,   -61,     0,     0,     0,     0,   -61,   -61,
     -61,   -61,   -61,   -61,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -61,   -61,   -61,   -61,     0,     0,
     -61,   -62,   -62,   -62,     0,     0,   -62,   -62,     0,     0,
       0,     0,   -62,   -62,   -62,   -62,   -62,   -62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -62,   -62,
     -62,   -62,     0,     0,   -62,   -63,   -63,   -63,     0,     0,
     -63,   -63,     0,     0,     0,     0,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -63,   -63,   -63,   -63,     0,     0,   -63,   -37,
     -37,   -37,     0,     0,   -37,   -37,     0,     0,     0,     0,
     -37,   -37,   -37,   -37,   -37,   -37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -37,   -37,   -37,   -37,
       0,     0,   -37,   186,   187,   188,     0,     0,   189,   190,
       0,     0,     0,     0,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   198,   199,   200,     0,     0,   -31,   -55,   -55,   -55,
       0,     0,   -55,   -55,     0,     0,     0,     0,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -55,   -55,   -55,   -55,     0,     0,
     -55,   -56,   -56,   -56,     0,     0,   -56,   -56,     0,     0,
       0,     0,   -56,   -56,   -56,   -56,   -56,   -56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -56,   -56,
     -56,   -56,     0,     0,   -56,   -57,   -57,   -57,     0,     0,
     -57,   -57,     0,     0,     0,     0,   -57,   -57,   -57,   -57,
     -57,   -57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -57,   -57,   -57,   -57,     0,     0,   -57,   -58,
     -58,   -58,     0,     0,   -58,   -58,     0,     0,     0,     0,
     -58,   -58,   -58,   -58,   -58,   -58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -58,   -58,   -58,   -58,
       0,     0,   -58,   -59,   -59,   -59,     0,     0,   -59,   -59,
       0,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -59,   -59,   -59,   -59,     0,     0,   -59,   186,   187,   188,
       0,     0,   189,   190,     0,     0,     0,     0,   191,   192,
     193,   194,   195,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,   199,   200,     0,     0,
     286,   186,   187,   188,     0,     0,   189,   190,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   198,
     199,   200,     0,     0,   291,   -52,   187,   188,     0,     0,
     -52,   -52,     0,     0,     0,     0,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,   199,   200,     0,     0,   -52,   -53,
     -53,   188,     0,     0,   -53,   -53,     0,     0,     0,     0,
     -53,   -53,   -53,   -53,   -53,   -53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,   199,   200,
       0,     0,   -53,   -54,   -54,   -54,     0,     0,   -54,   -54,
       0,     0,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   198,   199,   200,     0,     0,   -54,   186,   187,   188,
       0,     0,   -40,   190,     0,     0,     0,     0,   191,   192,
     193,   194,   195,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,   199,   200,     0,     0,
     -40,   186,   187,   188,     0,     0,   -41,   -41,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   198,
     199,   200,     0,     0,   -41,   186,   187,   188,     0,     0,
     -42,   -42,     0,     0,     0,     0,   -42,   -42,   193,   194,
     195,   196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,   199,   200,     0,     0,   -42,   186,
     187,   188,     0,     0,   -43,   -43,     0,     0,     0,     0,
     -43,   -43,   193,   194,   195,   196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,   199,   200,
       0,     0,   -43,   186,   187,   188,     0,     0,   -44,   -44,
       0,     0,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   198,   199,   200,     0,     0,   -44,   186,   187,   188,
       0,     0,   -45,   -45,     0,     0,     0,     0,   -45,   -45,
     -45,   -45,   -45,   -45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,   199,   200,     0,     0,
     -45,   186,   187,   188,     0,     0,   -46,   -46,     0,     0,
       0,     0,   -46,   -46,   -46,   -46,   -46,   -46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   198,
     199,   200,     0,     0,   -46,   186,   187,   188,     0,     0,
     -47,   -47,     0,     0,     0,     0,   -47,   -47,   -47,   -47,
     -47,   -47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,   199,   200,     0,     0,   -47,   -48,
     -48,   -48,     0,     0,   -48,   -48,     0,     0,     0,     0,
     -48,   -48,   -48,   -48,   -48,   -48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -48,   -48,   199,   200,
       0,     0,   -48,   -49,   -49,   -49,     0,     0,   -49,   -49,
       0,     0,     0,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -49,   -49,   199,   200,     0,     0,   -49,   -50,   -50,   -50,
       0,     0,   -50,   -50,     0,     0,     0,     0,   -50,   -50,
     -50,   -50,   -50,   -50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -50,   -50,   -50,   -50,     0,     0,
     -50,   -51,   -51,   -51,     0,     0,   -51,   -51,     0,     0,
       0,     0,   -51,   -51,   -51,   -51,   -51,   -51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -51,   -51,
     -51,   -51,     0,     0,   -51,   -39,   -39,   -39,     0,     0,
     -39,   -39,     0,     0,     0,     0,   -39,   -39,   -39,   -39,
     -39,   -39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -39,   -39,   -39,   -39,     0,     0,   -39,   186,
     187,   188,     0,     0,   189,   190,     0,     0,     0,     0,
     191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,   199,   200,
       0,     0,   -32,   186,   187,   188,     0,     0,   189,   190,
       0,     0,     0,     0,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   198,   199,   200,     0,     0,   303,   -69,   -69,   -69,
       0,     0,   -69,   -69,     0,     0,     0,     0,   -69,   -69,
     -69,   -69,   -69,   -69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -69,   -69,   -69,   -69,     0,     0,
     -69,   -70,   -70,   -70,     0,     0,   -70,   -70,     0,     0,
       0,     0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -70,   -70,
     -70,   -70,     0,     0,   -70,   -68,   -68,   -68,     0,     0,
     -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -68,   -68,   -68,   -68,     0,     0,   -68,   -38,
     -38,   -38,     0,    93,   -38,   -38,     0,     0,     0,     0,
     -38,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -38,   -38,   -38,   -38,
     -38,    94,   -75,   -75,   -75,     0,   -75,   -75,   -75,     0,
       0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -75,
     -75,   -75,   -75,   -75,   -75,   -66,   -66,   -66,     0,     0,
     -66,   -66,     0,     0,     0,     0,   -66,   -66,   -66,   -66,
     -66,   -66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -66,   -66,   -66,   -66,   -66,   -65,   -65,   -65,
       0,     0,   -65,   -65,     0,     0,     0,     0,   -65,   -65,
     -65,   -65,   -65,   -65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -65,   -65,   -65,   -65,   -65,   -64,
     -64,   -64,     0,     0,   -64,   -64,     0,     0,     0,     0,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -64,   -64,   -64,   -64,
     -64,   -67,   -67,   -67,     0,     0,   -67,   -67,     0,     0,
       0,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -67,   -67,
     -67,   -67,   -67,    77,    78,    79,     0,     0,    80,    81,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,    92,   -33,   -33,   -33,     0,     0,
     -33,   -33,     0,     0,     0,     0,   -33,   -33,   -33,   -33,
     -33,   -33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -33,   -33,   -33,   -33,   -33,   -34,   -34,   -34,
       0,     0,   -34,   -34,     0,     0,     0,     0,   -34,   -34,
     -34,   -34,   -34,   -34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -34,   -34,   -34,   -34,   -34,   -35,
     -35,   -35,     0,     0,   -35,   -35,     0,     0,     0,     0,
     -35,   -35,   -35,   -35,   -35,   -35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -35,   -35,   -35,   -35,
     -35,   -36,   -36,   -36,     0,     0,   -36,   -36,     0,     0,
       0,     0,   -36,   -36,   -36,   -36,   -36,   -36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -36,   -36,
     -36,   -36,   -36,   -60,   -60,   -60,     0,     0,   -60,   -60,
       0,     0,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -60,   -60,   -60,   -60,   -60,   -61,   -61,   -61,     0,     0,
     -61,   -61,     0,     0,     0,     0,   -61,   -61,   -61,   -61,
     -61,   -61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -61,   -61,   -61,   -61,   -61,   -62,   -62,   -62,
       0,     0,   -62,   -62,     0,     0,     0,     0,   -62,   -62,
     -62,   -62,   -62,   -62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -62,   -62,   -62,   -62,   -62,   -63,
     -63,   -63,     0,     0,   -63,   -63,     0,     0,     0,     0,
     -63,   -63,   -63,   -63,   -63,   -63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -63,   -63,   -63,   -63,
     -63,   -37,   -37,   -37,     0,     0,   -37,   -37,     0,     0,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -37,   -37,
     -37,   -37,   -37,   -55,   -55,   -55,     0,     0,   -55,   -55,
       0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -55,   -55,   -55,   -55,   -55,   -56,   -56,   -56,     0,     0,
     -56,   -56,     0,     0,     0,     0,   -56,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -56,   -56,   -56,   -56,   -56,   -57,   -57,   -57,
       0,     0,   -57,   -57,     0,     0,     0,     0,   -57,   -57,
     -57,   -57,   -57,   -57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -57,   -57,   -57,   -57,   -57,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
     -29,   -58,   -58,   -58,     0,     0,   -58,   -58,     0,     0,
       0,     0,   -58,   -58,   -58,   -58,   -58,   -58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -58,   -58,
     -58,   -58,   -58,   -59,   -59,   -59,     0,     0,   -59,   -59,
       0,     0,     0,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -59,   -59,   -59,   -59,   -59,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,   -31,   -39,   -39,   -39,
       0,     0,   -39,   -39,     0,     0,     0,     0,   -39,   -39,
     -39,   -39,   -39,   -39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -39,   -39,   -39,   -39,   -39,   -52,
      78,    79,     0,     0,   -52,   -52,     0,     0,     0,     0,
     -52,   -52,   -52,   -52,   -52,   -52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
     -52,   -53,   -53,    79,     0,     0,   -53,   -53,     0,     0,
       0,     0,   -53,   -53,   -53,   -53,   -53,   -53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,   -53,   -54,   -54,   -54,     0,     0,   -54,   -54,
       0,     0,     0,     0,   -54,   -54,   -54,   -54,   -54,   -54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,   -54,    77,    78,    79,     0,     0,
     -40,    81,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,   -40,    77,    78,    79,
       0,     0,   -41,   -41,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,   -41,    77,
      78,    79,     0,     0,   -42,   -42,     0,     0,     0,     0,
     -42,   -42,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
     -42,    77,    78,    79,     0,     0,   -43,   -43,     0,     0,
       0,     0,   -43,   -43,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,   -43,    77,    78,    79,     0,     0,   -44,   -44,
       0,     0,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,   -44,    77,    78,    79,     0,     0,
     -45,   -45,     0,     0,     0,     0,   -45,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,   -45,    77,    78,    79,
       0,     0,   -46,   -46,     0,     0,     0,     0,   -46,   -46,
     -46,   -46,   -46,   -46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,   -46,    77,
      78,    79,     0,     0,   -47,   -47,     0,     0,     0,     0,
     -47,   -47,   -47,   -47,   -47,   -47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
     -47,   -48,   -48,   -48,     0,     0,   -48,   -48,     0,     0,
       0,     0,   -48,   -48,   -48,   -48,   -48,   -48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -48,   -48,
      90,    91,   -48,   -49,   -49,   -49,     0,     0,   -49,   -49,
       0,     0,     0,     0,   -49,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -49,   -49,    90,    91,   -49,   -50,   -50,   -50,     0,     0,
     -50,   -50,     0,     0,     0,     0,   -50,   -50,   -50,   -50,
     -50,   -50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -50,   -50,   -50,   -50,   -50,   -51,   -51,   -51,
       0,     0,   -51,   -51,     0,     0,     0,     0,   -51,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -51,   -51,   -51,   -51,   -51,    77,
      78,    79,     0,     0,    80,    81,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
     -32,   -69,   -69,   -69,     0,     0,   -69,   -69,     0,     0,
       0,     0,   -69,   -69,   -69,   -69,   -69,   -69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -69,   -69,
     -69,   -69,   -69,   -70,   -70,   -70,     0,     0,   -70,   -70,
       0,     0,     0,     0,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -70,   -70,   -70,   -70,   -70,   -68,   -68,   -68,     0,     0,
     -68,   -68,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -68,   -68,   -68,   -68,   -68,    77,    78,    79,
       0,     0,    80,    81,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,   282
};

static const yytype_int16 yycheck[] =
{
       9,    20,   138,     0,     3,     4,     5,     6,     5,     0,
      19,     7,     3,     4,     5,     6,     0,     7,    15,     3,
       4,     5,     6,     0,    21,    48,    49,     7,     5,   124,
     124,    40,    48,    49,     7,   130,     7,    50,    51,   134,
       7,     8,     9,    10,    11,    12,    50,    14,    15,    16,
      64,    50,   124,    62,    63,    64,    49,   124,    52,    68,
      49,     0,     7,   124,     3,     4,     5,     6,   125,     3,
       4,     5,     6,    49,   131,    49,    43,    44,    45,     7,
      94,    48,    49,   219,    53,    94,    50,    51,    48,     7,
       8,     9,    10,    11,    12,    48,    14,    15,    16,    50,
      51,    50,    51,    50,    51,   124,    50,     7,     8,     9,
      10,    11,    12,   122,    14,    15,    16,    50,    51,    50,
      50,    39,   131,    41,    42,    43,    44,    45,    48,    48,
      53,    49,    48,    50,    52,    49,   145,   146,   147,    49,
     149,   150,   151,    43,    44,    45,    49,    49,     0,    49,
      50,     3,     4,     5,     6,    49,    49,    48,    53,    48,
     169,   170,   171,    50,   173,   174,   175,     0,    50,    50,
       3,     4,     5,     6,    50,    50,    50,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    48,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   303,   303,
      50,     5,   307,   307,   228,   229,   311,   311,    21,   228,
     229,    44,   279,   237,   238,   239,    -1,   236,   237,   238,
     239,   303,    -1,   247,    -1,   307,   303,   246,   247,   311,
     307,    -1,   303,    -1,   311,    -1,   307,   304,    -1,    23,
     311,   308,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    36,    -1,    38,    39,    40,    -1,     0,   278,
      44,     3,     4,     5,     6,     0,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,   303,    -1,    -1,    -1,   307,    -1,
      -1,    -1,   311,    -1,    68,    69,    -1,    -1,    -1,   308,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,     0,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
     124,   125,    -1,    -1,    -1,    -1,   130,   131,    -1,    -1,
     134,    43,    44,    45,   138,    -1,    -1,    49,    50,    -1,
      -1,   145,   146,   147,    -1,   149,   150,   151,    17,    18,
      19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,   169,   170,   171,    -1,   173,
     174,   175,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      49,    50,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,   303,
     304,    52,    53,   307,   308,   122,    -1,   311,     7,     8,
       9,    10,    11,    12,   131,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      49,    -1,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    11,    12,    94,    14,    15,
      16,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    43,    44,    45,
      -1,   308,    -1,    49,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    49,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,     7,     8,     9,    10,    11,    12,    94,    14,    15,
      16,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    43,    44,    45,
      -1,   308,    -1,    49,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    63,    64,    -1,   246,
     247,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,   169,   170,   171,    -1,   173,   174,   175,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    15,    16,
      -1,   278,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,   308,    49,    -1,    -1,    52,    53,     3,     4,     5,
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
      49,    -1,    -1,    52,    53,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,
      52,    17,    18,    19,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    49,    50,    51,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    51,    17,    18,    19,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,
      51,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    -1,    50,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    -1,
      50,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    -1,    50,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    17,    18,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    17,
      18,    19,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    17,    18,    19,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    17,    18,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    17,    18,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48
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
      46,    47,    48,    21,    49,    84,    72,    82,    83,    82,
      72,    71,    72,    50,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      82,    50,    51,    50,    50,    48,    50,    72,    66,    71,
      40,    48,    66,    71,    50,    66,     7,     7,    52,     7,
       8,     9,    10,    11,    12,    14,    15,    16,    43,    44,
      45,    49,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    84,     7,     7,     8,     9,    10,    11,    12,    14,
      15,    16,    43,    44,    45,    49,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    84,    17,    18,    19,    22,
      23,    28,    29,    30,    31,    32,    33,    44,    45,    46,
      47,    48,    17,    18,    19,    22,    23,    28,    29,    30,
      31,    32,    33,    44,    45,    46,    47,    39,    41,    52,
      62,    67,    68,    69,    70,    72,    72,    63,    49,    49,
      72,    72,    72,    72,    72,    72,    21,    49,    49,    49,
      72,    72,    72,    72,    72,    72,    21,    49,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    49,    49,
      63,    48,    48,    53,    82,    82,    50,    72,    82,    82,
      82,    50,    72,    82,    72,    71,    53,    50,    50,    50,
      50,    50,    50,    50,    48,    66,    71,    40,    48,    66,
      71,    50,    66
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
#line 2717 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_TOKEN: /* FLOAT_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2725 "bison.tab.c"
        break;

    case YYSYMBOL_INT_LIST_TOKEN: /* INT_LIST_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2733 "bison.tab.c"
        break;

    case YYSYMBOL_FLOAT_LIST_TOKEN: /* FLOAT_LIST_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2741 "bison.tab.c"
        break;

    case YYSYMBOL_ID_TOKEN: /* ID_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2749 "bison.tab.c"
        break;

    case YYSYMBOL_READ_TOKEN: /* READ_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2757 "bison.tab.c"
        break;

    case YYSYMBOL_WRITE_TOKEN: /* WRITE_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2765 "bison.tab.c"
        break;

    case YYSYMBOL_NIL_TOKEN: /* NIL_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2773 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_REAL_TOKEN: /* CONSTANT_REAL_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2781 "bison.tab.c"
        break;

    case YYSYMBOL_CONSTANT_INTEGER_TOKEN: /* CONSTANT_INTEGER_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2789 "bison.tab.c"
        break;

    case YYSYMBOL_STRING_TOKEN: /* STRING_TOKEN  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2797 "bison.tab.c"
        break;

    case YYSYMBOL_declaration: /* declaration  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2805 "bison.tab.c"
        break;

    case YYSYMBOL_variableDeclare: /* variableDeclare  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2813 "bison.tab.c"
        break;

    case YYSYMBOL_functionDeclare: /* functionDeclare  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2821 "bison.tab.c"
        break;

    case YYSYMBOL_param: /* param  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2829 "bison.tab.c"
        break;

    case YYSYMBOL_compoundStatement: /* compoundStatement  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2837 "bison.tab.c"
        break;

    case YYSYMBOL_codeBlock: /* codeBlock  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2845 "bison.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2853 "bison.tab.c"
        break;

    case YYSYMBOL_flowExpression: /* flowExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2861 "bison.tab.c"
        break;

    case YYSYMBOL_condExpression: /* condExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2869 "bison.tab.c"
        break;

    case YYSYMBOL_interationExpression: /* interationExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2877 "bison.tab.c"
        break;

    case YYSYMBOL_returnExpression: /* returnExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2885 "bison.tab.c"
        break;

    case YYSYMBOL_optExpression: /* optExpression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2893 "bison.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2901 "bison.tab.c"
        break;

    case YYSYMBOL_binArith: /* binArith  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2909 "bison.tab.c"
        break;

    case YYSYMBOL_listArith: /* listArith  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2917 "bison.tab.c"
        break;

    case YYSYMBOL_unaArith: /* unaArith  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2925 "bison.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2933 "bison.tab.c"
        break;

    case YYSYMBOL_constantInteger: /* constantInteger  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2941 "bison.tab.c"
        break;

    case YYSYMBOL_constantReal: /* constantReal  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2949 "bison.tab.c"
        break;

    case YYSYMBOL_constantNIL: /* constantNIL  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2957 "bison.tab.c"
        break;

    case YYSYMBOL_constantString: /* constantString  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2965 "bison.tab.c"
        break;

    case YYSYMBOL_funcCall: /* funcCall  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2973 "bison.tab.c"
        break;

    case YYSYMBOL_id: /* id  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2981 "bison.tab.c"
        break;

    case YYSYMBOL_type: /* type  */
#line 89 "./src/bison.y"
           {
    delete_astnode(((*yyvaluep).astnode));
}
#line 2989 "bison.tab.c"
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
#line 3287 "bison.tab.c"
    break;

  case 3: /* startProgram: declaration  */
#line 99 "./src/bison.y"
                  {
        insert_kid((yyvsp[0].astnode), root);
    }
#line 3295 "bison.tab.c"
    break;

  case 4: /* declaration: variableDeclare  */
#line 105 "./src/bison.y"
                    {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3303 "bison.tab.c"
    break;

  case 5: /* declaration: functionDeclare  */
#line 108 "./src/bison.y"
                      {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3311 "bison.tab.c"
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
#line 3340 "bison.tab.c"
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
#line 3383 "bison.tab.c"
    break;

  case 8: /* optListParams: %empty  */
#line 182 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3391 "bison.tab.c"
    break;

  case 10: /* listParams: listParams ',' param  */
#line 189 "./src/bison.y"
                         {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 3400 "bison.tab.c"
    break;

  case 11: /* listParams: param  */
#line 193 "./src/bison.y"
            {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3409 "bison.tab.c"
    break;

  case 12: /* param: type id  */
#line 200 "./src/bison.y"
            {
        (yyval.astnode) = create_astnode_context(AST_PARAM, "param");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3419 "bison.tab.c"
    break;

  case 13: /* compoundStatement: '{' optListCodeBlock '}'  */
#line 209 "./src/bison.y"
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
#line 3440 "bison.tab.c"
    break;

  case 14: /* optListCodeBlock: %empty  */
#line 228 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3448 "bison.tab.c"
    break;

  case 16: /* listCodeBlock: listCodeBlock codeBlock  */
#line 235 "./src/bison.y"
                            {
        insert_list_element((yyvsp[-1].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-1].list);
    }
#line 3457 "bison.tab.c"
    break;

  case 17: /* listCodeBlock: codeBlock  */
#line 239 "./src/bison.y"
                {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 3466 "bison.tab.c"
    break;

  case 18: /* codeBlock: statement  */
#line 246 "./src/bison.y"
              {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3475 "bison.tab.c"
    break;

  case 19: /* codeBlock: variableDeclare  */
#line 250 "./src/bison.y"
                      {
        (yyval.astnode) = create_astnode_context(AST_CODE_BLOCK, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3484 "bison.tab.c"
    break;

  case 20: /* statement: flowExpression  */
#line 257 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3493 "bison.tab.c"
    break;

  case 21: /* statement: compoundStatement  */
#line 261 "./src/bison.y"
                        {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3502 "bison.tab.c"
    break;

  case 22: /* statement: expression ';'  */
#line 265 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_STATEMENT, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3511 "bison.tab.c"
    break;

  case 23: /* flowExpression: condExpression  */
#line 272 "./src/bison.y"
                   {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3519 "bison.tab.c"
    break;

  case 24: /* flowExpression: interationExpression  */
#line 275 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3527 "bison.tab.c"
    break;

  case 25: /* flowExpression: returnExpression ';'  */
#line 278 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[-1].astnode);
    }
#line 3535 "bison.tab.c"
    break;

  case 26: /* condExpression: IF_TOKEN '(' expression ')' statement  */
#line 284 "./src/bison.y"
                                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3545 "bison.tab.c"
    break;

  case 27: /* condExpression: IF_TOKEN '(' expression ')' statement ELSE_TOKEN statement  */
#line 289 "./src/bison.y"
                                                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_COND, "cond expression");
        insert_kid((yyvsp[-4].astnode), (yyval.astnode));
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3556 "bison.tab.c"
    break;

  case 28: /* interationExpression: FOR_TOKEN '(' optExpression ';' optExpression ';' optExpression ')' statement  */
#line 298 "./src/bison.y"
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
#line 3571 "bison.tab.c"
    break;

  case 29: /* returnExpression: RETURN_TOKEN expression  */
#line 311 "./src/bison.y"
                            {
        (yyval.astnode) = create_astnode_context(AST_EXPR_RETURN, "return expression");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3580 "bison.tab.c"
    break;

  case 30: /* optExpression: %empty  */
#line 318 "./src/bison.y"
           {
        (yyval.astnode) = NULL;
    }
#line 3588 "bison.tab.c"
    break;

  case 31: /* optExpression: expression  */
#line 321 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3596 "bison.tab.c"
    break;

  case 32: /* expression: id ASSIGN_TOKEN expression  */
#line 327 "./src/bison.y"
                               {
        (yyval.astnode) = create_astnode_context(AST_EXPR_ASSIGN, "assign");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3606 "bison.tab.c"
    break;

  case 33: /* expression: binArith  */
#line 332 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3615 "bison.tab.c"
    break;

  case 34: /* expression: listArith  */
#line 336 "./src/bison.y"
                {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3624 "bison.tab.c"
    break;

  case 35: /* expression: unaArith  */
#line 340 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3633 "bison.tab.c"
    break;

  case 36: /* expression: constant  */
#line 344 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3642 "bison.tab.c"
    break;

  case 37: /* expression: funcCall  */
#line 348 "./src/bison.y"
               {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3651 "bison.tab.c"
    break;

  case 38: /* expression: id  */
#line 352 "./src/bison.y"
         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3660 "bison.tab.c"
    break;

  case 39: /* expression: '(' expression ')'  */
#line 356 "./src/bison.y"
                         {
        (yyval.astnode) = create_astnode_context(AST_EXPRESSION, "");
        insert_kid((yyvsp[-1].astnode), (yyval.astnode));
    }
#line 3669 "bison.tab.c"
    break;

  case 40: /* binArith: expression OR_TOKEN expression  */
#line 363 "./src/bison.y"
                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {or}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3679 "bison.tab.c"
    break;

  case 41: /* binArith: expression AND_TOKEN expression  */
#line 368 "./src/bison.y"
                                      {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {and}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3689 "bison.tab.c"
    break;

  case 42: /* binArith: expression EQUAL_TOKEN expression  */
#line 373 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {==}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3699 "bison.tab.c"
    break;

  case 43: /* binArith: expression DIFF_EQ_TOKEN expression  */
#line 378 "./src/bison.y"
                                          {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {!=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3709 "bison.tab.c"
    break;

  case 44: /* binArith: expression LESS_TOKEN expression  */
#line 383 "./src/bison.y"
                                       {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3719 "bison.tab.c"
    break;

  case 45: /* binArith: expression LE_EQ_TOKEN expression  */
#line 388 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {<=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3729 "bison.tab.c"
    break;

  case 46: /* binArith: expression GREAT_TOKEN expression  */
#line 393 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3739 "bison.tab.c"
    break;

  case 47: /* binArith: expression GR_EQ_TOKEN expression  */
#line 398 "./src/bison.y"
                                        {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {>=}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3749 "bison.tab.c"
    break;

  case 48: /* binArith: expression '+' expression  */
#line 403 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {+}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3759 "bison.tab.c"
    break;

  case 49: /* binArith: expression '-' expression  */
#line 408 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {-}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3769 "bison.tab.c"
    break;

  case 50: /* binArith: expression '*' expression  */
#line 413 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {*}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3779 "bison.tab.c"
    break;

  case 51: /* binArith: expression '/' expression  */
#line 418 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_BIN_ARITH, "operation {/}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3789 "bison.tab.c"
    break;

  case 52: /* listArith: expression MAP_TOKEN expression  */
#line 426 "./src/bison.y"
                                    {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list map}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3799 "bison.tab.c"
    break;

  case 53: /* listArith: expression FILTER_TOKEN expression  */
#line 431 "./src/bison.y"
                                         {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list filter}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3809 "bison.tab.c"
    break;

  case 54: /* listArith: expression CONSTRUCTOR_LIST_TOKEN expression  */
#line 436 "./src/bison.y"
                                                   {
        (yyval.astnode) = create_astnode_context(AST_EXPR_LIST_ARITH, "operation {list constructor}");
        insert_kid((yyvsp[-2].astnode), (yyval.astnode));
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3819 "bison.tab.c"
    break;

  case 55: /* unaArith: EXCLAMATION_TOKEN expression  */
#line 444 "./src/bison.y"
                                 {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {!}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3828 "bison.tab.c"
    break;

  case 56: /* unaArith: QUESTION_TOKEN expression  */
#line 448 "./src/bison.y"
                                {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {?}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3837 "bison.tab.c"
    break;

  case 57: /* unaArith: PERCENTAGE_TOKEN expression  */
#line 452 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {%}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3846 "bison.tab.c"
    break;

  case 58: /* unaArith: '+' expression  */
#line 456 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {+}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3855 "bison.tab.c"
    break;

  case 59: /* unaArith: '-' expression  */
#line 460 "./src/bison.y"
                                  {
        (yyval.astnode) = create_astnode_context(AST_EXPR_UNA_ARITH, "unitary operation {-}");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3864 "bison.tab.c"
    break;

  case 60: /* constant: constantInteger  */
#line 467 "./src/bison.y"
                    {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant int");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3873 "bison.tab.c"
    break;

  case 61: /* constant: constantReal  */
#line 471 "./src/bison.y"
                   {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant real");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3882 "bison.tab.c"
    break;

  case 62: /* constant: constantNIL  */
#line 475 "./src/bison.y"
                  {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant nil");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3891 "bison.tab.c"
    break;

  case 63: /* constant: constantString  */
#line 479 "./src/bison.y"
                     {
        (yyval.astnode) = create_astnode_context(AST_CONSTANT, "constant string");
        insert_kid((yyvsp[0].astnode), (yyval.astnode));
    }
#line 3900 "bison.tab.c"
    break;

  case 64: /* constantInteger: CONSTANT_INTEGER_TOKEN  */
#line 486 "./src/bison.y"
                           {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3908 "bison.tab.c"
    break;

  case 65: /* constantReal: CONSTANT_REAL_TOKEN  */
#line 492 "./src/bison.y"
                        {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3916 "bison.tab.c"
    break;

  case 66: /* constantNIL: NIL_TOKEN  */
#line 498 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3924 "bison.tab.c"
    break;

  case 67: /* constantString: STRING_TOKEN  */
#line 504 "./src/bison.y"
                 {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 3932 "bison.tab.c"
    break;

  case 68: /* funcCall: id '(' optListExpression ')'  */
#line 510 "./src/bison.y"
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
#line 3951 "bison.tab.c"
    break;

  case 69: /* funcCall: READ_TOKEN '(' optListExpression ')'  */
#line 524 "./src/bison.y"
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
#line 3970 "bison.tab.c"
    break;

  case 70: /* funcCall: WRITE_TOKEN '(' optListExpression ')'  */
#line 538 "./src/bison.y"
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
#line 3989 "bison.tab.c"
    break;

  case 71: /* optListExpression: %empty  */
#line 555 "./src/bison.y"
           {
        (yyval.list) = NULL;
    }
#line 3997 "bison.tab.c"
    break;

  case 73: /* listExpression: listExpression ',' expression  */
#line 562 "./src/bison.y"
                                  {
        insert_list_element((yyvsp[-2].list), (yyvsp[0].astnode));
        (yyval.list) = (yyvsp[-2].list);
    }
#line 4006 "bison.tab.c"
    break;

  case 74: /* listExpression: expression  */
#line 566 "./src/bison.y"
                 {
        (yyval.list) = create_list();
        insert_list_element((yyval.list), (yyvsp[0].astnode));
    }
#line 4015 "bison.tab.c"
    break;

  case 75: /* id: ID_TOKEN  */
#line 573 "./src/bison.y"
             {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4023 "bison.tab.c"
    break;

  case 76: /* type: INT_TOKEN  */
#line 579 "./src/bison.y"
              {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4031 "bison.tab.c"
    break;

  case 77: /* type: FLOAT_TOKEN  */
#line 582 "./src/bison.y"
                  {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4039 "bison.tab.c"
    break;

  case 78: /* type: INT_LIST_TOKEN  */
#line 585 "./src/bison.y"
                     {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4047 "bison.tab.c"
    break;

  case 79: /* type: FLOAT_LIST_TOKEN  */
#line 588 "./src/bison.y"
                       {
        (yyval.astnode) = (yyvsp[0].astnode);
    }
#line 4055 "bison.tab.c"
    break;


#line 4059 "bison.tab.c"

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

#line 593 "./src/bison.y"


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
    // printf("Tamanho lista: %d\n", node_aux->size);
    delete_astnode(root);
    delete_list(node_aux, delete_list_astnode);
    delete_symbol_table(symbol_table, delete_list_symbol_table);
    fclose(yyin);
    yylex_destroy();
    
    return 0;
}
