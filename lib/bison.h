/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIB_BISON_H_INCLUDED
# define YY_YY_LIB_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_TOKEN = 258,               /* INT_TOKEN  */
    FLOAT_TOKEN = 259,             /* FLOAT_TOKEN  */
    INT_LIST_TOKEN = 260,          /* INT_LIST_TOKEN  */
    FLOAT_LIST_TOKEN = 261,        /* FLOAT_LIST_TOKEN  */
    ID_TOKEN = 262,                /* ID_TOKEN  */
    READ_TOKEN = 263,              /* READ_TOKEN  */
    WRITE_TOKEN = 264,             /* WRITE_TOKEN  */
    NIL_TOKEN = 265,               /* NIL_TOKEN  */
    CONSTANT_REAL_TOKEN = 266,     /* CONSTANT_REAL_TOKEN  */
    CONSTANT_INTEGER_TOKEN = 267,  /* CONSTANT_INTEGER_TOKEN  */
    MUL_DIV_TOKEN = 268,           /* MUL_DIV_TOKEN  */
    EXCLAMATION_TOKEN = 269,       /* EXCLAMATION_TOKEN  */
    QUESTION_TOKEN = 270,          /* QUESTION_TOKEN  */
    PERCENTAGE_TOKEN = 271,        /* PERCENTAGE_TOKEN  */
    MAP_TOKEN = 272,               /* MAP_TOKEN  */
    FILTER_TOKEN = 273,            /* FILTER_TOKEN  */
    CONSTRUCTOR_LIST_TOKEN = 274,  /* CONSTRUCTOR_LIST_TOKEN  */
    ADD_MIN_TOKEN = 275,           /* ADD_MIN_TOKEN  */
    ASSIGN_TOKEN = 276,            /* ASSIGN_TOKEN  */
    OR_TOKEN = 277,                /* OR_TOKEN  */
    AND_TOKEN = 278,               /* AND_TOKEN  */
    EQ_EXC_TOKEN = 279,            /* EQ_EXC_TOKEN  */
    LE_GR_TOKEN = 280,             /* LE_GR_TOKEN  */
    ADD_UNARY_TOKEN = 281,         /* ADD_UNARY_TOKEN  */
    MIN_UNARY_TOKEN = 282,         /* MIN_UNARY_TOKEN  */
    EQUAL_TOKEN = 283,             /* EQUAL_TOKEN  */
    DIFF_EQ_TOKEN = 284,           /* DIFF_EQ_TOKEN  */
    LESS_TOKEN = 285,              /* LESS_TOKEN  */
    LE_EQ_TOKEN = 286,             /* LE_EQ_TOKEN  */
    GREAT_TOKEN = 287,             /* GREAT_TOKEN  */
    GR_EQ_TOKEN = 288,             /* GR_EQ_TOKEN  */
    ADD_TOKEN = 289,               /* ADD_TOKEN  */
    MIN_TOKEN = 290,               /* MIN_TOKEN  */
    MUL_TOKEN = 291,               /* MUL_TOKEN  */
    DIV_TOKEN = 292,               /* DIV_TOKEN  */
    UNI_OP = 293,                  /* UNI_OP  */
    IF_TOKEN = 294,                /* IF_TOKEN  */
    ELSE_TOKEN = 295,              /* ELSE_TOKEN  */
    FOR_TOKEN = 296,               /* FOR_TOKEN  */
    RETURN_TOKEN = 297,            /* RETURN_TOKEN  */
    STRING_TOKEN = 298             /* STRING_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "./src/bison.y"

    struct AstNode *astnode;
    struct Symbol *symbol;
    struct List *list;

#line 113 "lib/bison.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_LIB_BISON_H_INCLUDED  */
