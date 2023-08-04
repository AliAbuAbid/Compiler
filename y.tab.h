/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    COMMENT = 258,                 /* COMMENT  */
    WHILE = 259,                   /* WHILE  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    FOR = 262,                     /* FOR  */
    DO = 263,                      /* DO  */
    VAR = 264,                     /* VAR  */
    ARGS = 265,                    /* ARGS  */
    RETURN = 266,                  /* RETURN  */
    BOOL = 267,                    /* BOOL  */
    STRING = 268,                  /* STRING  */
    CHARPTR = 269,                 /* CHARPTR  */
    CHAR = 270,                    /* CHAR  */
    INT = 271,                     /* INT  */
    INTPTR = 272,                  /* INTPTR  */
    PROCEDUR = 273,                /* PROCEDUR  */
    AND = 274,                     /* AND  */
    ADDRESS = 275,                 /* ADDRESS  */
    EQ = 276,                      /* EQ  */
    ASSINGMENT = 277,              /* ASSINGMENT  */
    OR = 278,                      /* OR  */
    LENGTH = 279,                  /* LENGTH  */
    GT = 280,                      /* GT  */
    GTE = 281,                     /* GTE  */
    LTE = 282,                     /* LTE  */
    LT = 283,                      /* LT  */
    NOTEQ = 284,                   /* NOTEQ  */
    NOT = 285,                     /* NOT  */
    DIVISION = 286,                /* DIVISION  */
    PLUS = 287,                    /* PLUS  */
    MINUS = 288,                   /* MINUS  */
    STAR = 289,                    /* STAR  */
    VARIABLE = 290,                /* VARIABLE  */
    STR_VAL = 291,                 /* STR_VAL  */
    REAL_VAL = 292,                /* REAL_VAL  */
    CHAR_VAL = 293,                /* CHAR_VAL  */
    NULLL = 294,                   /* NULLL  */
    MAIN = 295,                    /* MAIN  */
    ID = 296,                      /* ID  */
    SEMICOLON = 297,               /* SEMICOLON  */
    COMMA = 298,                   /* COMMA  */
    LPAREN = 299,                  /* LPAREN  */
    RPAREN = 300,                  /* RPAREN  */
    LBRACKET = 301,                /* LBRACKET  */
    RBRACKET = 302,                /* RBRACKET  */
    LBRACE = 303,                  /* LBRACE  */
    RBRACE = 304,                  /* RBRACE  */
    DEC_VAL = 305,                 /* DEC_VAL  */
    HEX_VAL = 306,                 /* HEX_VAL  */
    BTRUE = 307,                   /* BTRUE  */
    BFALSE = 308,                  /* BFALSE  */
    REAL = 309,                    /* REAL  */
    REALPTR = 310,                 /* REALPTR  */
    FUNCTION = 311,                /* FUNCTION  */
    COLON = 312,                   /* COLON  */
    DEREFRENCE = 313,              /* DEREFRENCE  */
    ARG_ARROW = 314,               /* ARG_ARROW  */
    QUOTE = 315,                   /* QUOTE  */
    DOUBLE_QUOTES = 316,           /* DOUBLE_QUOTES  */
    BEGIN_COMMENT = 317,           /* BEGIN_COMMENT  */
    END_COMMENT = 318,             /* END_COMMENT  */
    VOID = 319                     /* VOID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define COMMENT 258
#define WHILE 259
#define IF 260
#define ELSE 261
#define FOR 262
#define DO 263
#define VAR 264
#define ARGS 265
#define RETURN 266
#define BOOL 267
#define STRING 268
#define CHARPTR 269
#define CHAR 270
#define INT 271
#define INTPTR 272
#define PROCEDUR 273
#define AND 274
#define ADDRESS 275
#define EQ 276
#define ASSINGMENT 277
#define OR 278
#define LENGTH 279
#define GT 280
#define GTE 281
#define LTE 282
#define LT 283
#define NOTEQ 284
#define NOT 285
#define DIVISION 286
#define PLUS 287
#define MINUS 288
#define STAR 289
#define VARIABLE 290
#define STR_VAL 291
#define REAL_VAL 292
#define CHAR_VAL 293
#define NULLL 294
#define MAIN 295
#define ID 296
#define SEMICOLON 297
#define COMMA 298
#define LPAREN 299
#define RPAREN 300
#define LBRACKET 301
#define RBRACKET 302
#define LBRACE 303
#define RBRACE 304
#define DEC_VAL 305
#define HEX_VAL 306
#define BTRUE 307
#define BFALSE 308
#define REAL 309
#define REALPTR 310
#define FUNCTION 311
#define COLON 312
#define DEREFRENCE 313
#define ARG_ARROW 314
#define QUOTE 315
#define DOUBLE_QUOTES 316
#define BEGIN_COMMENT 317
#define END_COMMENT 318
#define VOID 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "part1.y"

    struct node *node;
    char *string;

#line 200 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
