/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "part1.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "lex.yy.c"

typedef enum {false,true} bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;


	typedef struct Varaiables
	{	int isArg;
		char *name;
		char *value;
		char *type;
		char * length;
	}Varaiable;

    typedef struct Function 
	{
        char * name;
		struct Varaiables * arguments;
        char *returnType; 
		int argNum;
		bool findreturn;
    } Function;

		typedef struct SCOPE
	{	
		char *name;
		Varaiable * var;
		int VarCount;
		int Fcount;
		Function ** func;
		struct SCOPE * nextScope;
		struct SCOPE * preScope;
	}SCOPE;
	//part 1
	int yylex();
	int yyerror(char *e);
	
	//part 2
	static int scope=0;
	SCOPE* mkScope(char *);
	SCOPE* finScope(SCOPE * scopes);
	SCOPE* globalScope=NULL;
	void addFunc(char * name,Varaiable * arguments,node *returnType,int argNum,SCOPE*);
	void addVar(Varaiable * arguments,int,int,SCOPE * MYscope);
	void syntaxAnalyzer(node *tree,SCOPE * scope);
	void pushScopes(SCOPE* from,char*);
	char* getExpType(node *,SCOPE*);
	char* findFuncInScopes(node * tree,SCOPE * MYscope);
	char* findVar(node * tree,SCOPE * MYscope);
	node* mkNode(char* token, node *left, node *right);
	Varaiable* mkArguments(node *,int *);
	Varaiable* callFuncArguments(SCOPE *,node *tree,int * count);
	/////////////////////////////
	void printTree(node *tree);
	void printtree(node *tree, int level, int linebreak);
	char* concat(char* s1, char* s2);
	void print_tree (node *tree, int tab);
	void printTabs(int n);
	void printTabsOnce(int n);
	void pausex();
	void unpause();
	void printNewline();
	int streq(char* s1, char* s2);
	int isType(char* t);
	int isOperator(char* t);
	int openParenthesis = 0;
	int pauselevel = 0;
	int hadOperator = 0;
	int currentTab = 0;
	////////////////////
	void generate_three_address_code(node* tree);
	

#line 154 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 340 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMENT = 3,                    /* COMMENT  */
  YYSYMBOL_WHILE = 4,                      /* WHILE  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_DO = 8,                         /* DO  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_ARGS = 10,                      /* ARGS  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_CHARPTR = 14,                   /* CHARPTR  */
  YYSYMBOL_CHAR = 15,                      /* CHAR  */
  YYSYMBOL_INT = 16,                       /* INT  */
  YYSYMBOL_INTPTR = 17,                    /* INTPTR  */
  YYSYMBOL_PROCEDUR = 18,                  /* PROCEDUR  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_ADDRESS = 20,                   /* ADDRESS  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_ASSINGMENT = 22,                /* ASSINGMENT  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_LENGTH = 24,                    /* LENGTH  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_GTE = 26,                       /* GTE  */
  YYSYMBOL_LTE = 27,                       /* LTE  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_NOTEQ = 29,                     /* NOTEQ  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_DIVISION = 31,                  /* DIVISION  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_STAR = 34,                      /* STAR  */
  YYSYMBOL_VARIABLE = 35,                  /* VARIABLE  */
  YYSYMBOL_STR_VAL = 36,                   /* STR_VAL  */
  YYSYMBOL_REAL_VAL = 37,                  /* REAL_VAL  */
  YYSYMBOL_CHAR_VAL = 38,                  /* CHAR_VAL  */
  YYSYMBOL_NULLL = 39,                     /* NULLL  */
  YYSYMBOL_MAIN = 40,                      /* MAIN  */
  YYSYMBOL_ID = 41,                        /* ID  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_LPAREN = 44,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 45,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 46,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 47,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 48,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 49,                    /* RBRACE  */
  YYSYMBOL_DEC_VAL = 50,                   /* DEC_VAL  */
  YYSYMBOL_HEX_VAL = 51,                   /* HEX_VAL  */
  YYSYMBOL_BTRUE = 52,                     /* BTRUE  */
  YYSYMBOL_BFALSE = 53,                    /* BFALSE  */
  YYSYMBOL_REAL = 54,                      /* REAL  */
  YYSYMBOL_REALPTR = 55,                   /* REALPTR  */
  YYSYMBOL_FUNCTION = 56,                  /* FUNCTION  */
  YYSYMBOL_COLON = 57,                     /* COLON  */
  YYSYMBOL_DEREFRENCE = 58,                /* DEREFRENCE  */
  YYSYMBOL_ARG_ARROW = 59,                 /* ARG_ARROW  */
  YYSYMBOL_QUOTE = 60,                     /* QUOTE  */
  YYSYMBOL_DOUBLE_QUOTES = 61,             /* DOUBLE_QUOTES  */
  YYSYMBOL_BEGIN_COMMENT = 62,             /* BEGIN_COMMENT  */
  YYSYMBOL_END_COMMENT = 63,               /* END_COMMENT  */
  YYSYMBOL_VOID = 64,                      /* VOID  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_project = 66,                   /* project  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_main = 68,                      /* main  */
  YYSYMBOL_procedures = 69,                /* procedures  */
  YYSYMBOL_procedure = 70,                 /* procedure  */
  YYSYMBOL_para_pro = 71,                  /* para_pro  */
  YYSYMBOL_para_list = 72,                 /* para_list  */
  YYSYMBOL_pro_body = 73,                  /* pro_body  */
  YYSYMBOL_declares = 74,                  /* declares  */
  YYSYMBOL_declear = 75,                   /* declear  */
  YYSYMBOL_var_id = 76,                    /* var_id  */
  YYSYMBOL_type_id = 77,                   /* type_id  */
  YYSYMBOL_type_pro = 78,                  /* type_pro  */
  YYSYMBOL_stmnts = 79,                    /* stmnts  */
  YYSYMBOL_stmnt_block = 80,               /* stmnt_block  */
  YYSYMBOL_new_block = 81,                 /* new_block  */
  YYSYMBOL_stmnt = 82,                     /* stmnt  */
  YYSYMBOL_for_declars = 83,               /* for_declars  */
  YYSYMBOL_assmnt_stmnt = 84,              /* assmnt_stmnt  */
  YYSYMBOL_lhs = 85,                       /* lhs  */
  YYSYMBOL_expr = 86,                      /* expr  */
  YYSYMBOL_address_expr = 87,              /* address_expr  */
  YYSYMBOL_derefrence_expr = 88,           /* derefrence_expr  */
  YYSYMBOL_expr_list = 89,                 /* expr_list  */
  YYSYMBOL_paren_expr = 90,                /* paren_expr  */
  YYSYMBOL_call_func = 91                  /* call_func  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   587

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   122,   125,   130,   131,   134,   140,   146,
     147,   151,   152,   154,   160,   160,   162,   167,   168,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   192,   192,   194,
     194,   194,   194,   196,   203,   209,   217,   223,   231,   232,
     233,   234,   236,   237,   238,   243,   248,   252,   253,   254,
     256,   258,   259,   260,   261,   262,   263,   264,   265,   267,
     268,   269,   270,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   288,   290,   291,   293,   294,   295,
     297,   305,   306,   307,   310,   311,   312,   314,   315
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "COMMENT", "WHILE",
  "IF", "ELSE", "FOR", "DO", "VAR", "ARGS", "RETURN", "BOOL", "STRING",
  "CHARPTR", "CHAR", "INT", "INTPTR", "PROCEDUR", "AND", "ADDRESS", "EQ",
  "ASSINGMENT", "OR", "LENGTH", "GT", "GTE", "LTE", "LT", "NOTEQ", "NOT",
  "DIVISION", "PLUS", "MINUS", "STAR", "VARIABLE", "STR_VAL", "REAL_VAL",
  "CHAR_VAL", "NULLL", "MAIN", "ID", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "DEC_VAL",
  "HEX_VAL", "BTRUE", "BFALSE", "REAL", "REALPTR", "FUNCTION", "COLON",
  "DEREFRENCE", "ARG_ARROW", "QUOTE", "DOUBLE_QUOTES", "BEGIN_COMMENT",
  "END_COMMENT", "VOID", "$accept", "project", "program", "main",
  "procedures", "procedure", "para_pro", "para_list", "pro_body",
  "declares", "declear", "var_id", "type_id", "type_pro", "stmnts",
  "stmnt_block", "new_block", "stmnt", "for_declars", "assmnt_stmnt",
  "lhs", "expr", "address_expr", "derefrence_expr", "expr_list",
  "paren_expr", "call_func", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-154)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -154,    18,  -154,     2,  -154,   -19,     8,  -154,  -154,     0,
      15,    40,    28,    41,    28,   -20,    43,    10,    34,    45,
      44,    35,    28,    30,    53,    55,    54,    56,  -154,    71,
      -4,    44,    91,    73,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,    76,  -154,  -154,    79,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,     5,    77,  -154,    78,
      80,    86,   121,  -154,    83,    88,  -154,    44,  -154,   233,
    -154,  -154,    90,    99,   104,   105,   258,   -12,   109,   258,
    -154,  -154,  -154,  -154,    -3,   258,  -154,  -154,  -154,  -154,
      -7,  -154,  -154,   110,   132,   499,   134,   136,  -154,    91,
     258,   258,    22,    33,   517,  -154,  -154,   113,   114,   137,
    -154,   258,   258,  -154,   396,     5,   116,   258,  -154,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,  -154,   118,   417,   438,    44,   119,   122,   144,
    -154,  -154,   258,  -154,   258,    37,  -154,   480,   123,   294,
    -154,   121,   258,   459,   553,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,  -154,   -17,   -17,  -154,  -154,   133,   133,
     125,   258,   258,   258,   311,   328,  -154,   258,   258,  -154,
     145,   183,   345,  -154,  -154,  -154,  -154,  -154,  -154,   167,
      91,   362,   535,   553,  -154,  -154,   379,  -154,  -154,  -154,
     133,  -154,  -154,    -5,   131,  -154,   135,  -154,   133,  -154
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     0,     1,     0,     0,     3,     5,     0,
       0,     0,    10,     0,    10,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    12,     0,
       0,     0,     0,     0,     6,    28,    29,    35,    30,    31,
      34,    32,    36,    33,     0,    17,    19,    26,    25,    21,
      22,    24,    23,    27,    11,     6,    15,     0,     6,     0,
       0,     0,    38,     4,     0,     0,     8,     0,    14,    13,
       7,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    79,    78,    86,    85,     0,     6,    77,    82,    81,
       0,    51,    37,     0,     0,     0,    74,    75,    76,     0,
       0,     0,    54,    85,     0,    74,    75,    87,     0,     0,
      73,    96,     0,    98,     0,    15,    91,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,     0,     0,    57,     0,     0,
      58,    59,     0,    50,     0,     0,    83,    95,     0,     0,
      60,    38,     0,     0,    55,    67,    61,    68,    64,    63,
      65,    66,    62,    72,    69,    70,    71,    16,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,    96,    97,
      84,     0,     0,    92,    42,    41,    40,    46,    39,    44,
       0,     0,     0,    53,    84,    89,     0,    94,    43,    93,
       0,    52,    56,     0,     0,    45,     0,    90,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,  -154,     7,    -2,   164,   157,    23,    69,
     -56,   -27,   -94,  -154,    42,  -153,  -154,   -66,  -154,   -11,
      93,   -55,   -69,   -67,    19,  -154,  -154
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,    56,   185,    16,    17,    57,    62,
     186,    26,    54,    44,    69,   187,    91,   188,   138,    93,
      94,    95,   105,   106,   148,   113,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      96,     8,    97,    92,    45,   133,    68,     3,    35,    36,
      37,    38,    39,    40,   128,    77,   189,   131,     4,   -57,
       5,   104,     9,     5,   110,   128,   129,   130,   131,   107,
     114,   136,   108,   140,   116,   141,   137,   117,    15,    20,
      72,   111,    77,   112,    12,   134,   135,   205,    10,    11,
      41,    42,    22,    90,     8,   209,   147,   149,     6,    13,
      43,    61,   153,   137,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   111,    60,   142,
      90,    64,   176,   177,    14,    25,    18,   174,    21,   175,
      24,    23,    27,   115,    29,    68,   201,   182,    31,    96,
      96,    97,    97,    46,    47,    48,    49,    50,    51,   170,
      30,    32,    96,     8,    97,    92,   191,   192,   193,    34,
      33,    55,   196,   147,    58,    59,    63,    11,    65,    66,
      67,    96,    70,    97,   140,    71,   141,    73,    74,    96,
      75,    97,    67,   100,    76,    52,    53,    99,   101,   102,
     109,     5,   118,    77,   119,   145,   -58,    78,   -59,   144,
     167,   146,   152,    79,   172,   171,   173,   -56,   179,    80,
      81,    82,    83,   200,    84,   184,   207,    85,    19,    28,
     208,    86,   190,    87,   151,    88,    89,    73,    74,    61,
      75,    90,   206,   181,    76,   139,     0,   197,     0,     0,
       0,     0,     0,    77,     0,     0,     0,    78,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,    80,
      81,    82,    83,     0,    84,     0,     0,    85,     0,     0,
       0,    86,   198,    87,     0,    88,    89,    73,    74,     0,
      75,    90,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,    78,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,    80,
      81,    82,    83,     0,    84,     0,     0,    85,    77,     0,
       0,    86,    78,    87,     0,    88,    89,     0,    79,     0,
       0,    90,     0,     0,    80,    81,    82,    83,     0,   103,
       0,     0,    85,     0,     0,     0,     0,     0,    87,     0,
      88,    89,     0,   120,     0,   121,    90,   122,     0,   123,
     124,   125,   126,   127,     0,   128,   129,   130,   131,     0,
     120,     0,   121,     0,   122,     0,   123,   124,   125,   126,
     127,   180,   128,   129,   130,   131,     0,   120,     0,   121,
       0,   122,     0,   123,   124,   125,   126,   127,   194,   128,
     129,   130,   131,     0,   120,     0,   121,     0,   122,     0,
     123,   124,   125,   126,   127,   195,   128,   129,   130,   131,
       0,   120,     0,   121,     0,   122,     0,   123,   124,   125,
     126,   127,   199,   128,   129,   130,   131,     0,   120,     0,
     121,     0,   122,     0,   123,   124,   125,   126,   127,   202,
     128,   129,   130,   131,     0,   120,     0,   121,     0,   122,
       0,   123,   124,   125,   126,   127,   204,   128,   129,   130,
     131,     0,     0,     0,     0,     0,   120,     0,   121,     0,
     122,   150,   123,   124,   125,   126,   127,     0,   128,   129,
     130,   131,     0,     0,     0,     0,     0,   120,     0,   121,
       0,   122,   168,   123,   124,   125,   126,   127,     0,   128,
     129,   130,   131,     0,     0,     0,     0,     0,   120,     0,
     121,     0,   122,   169,   123,   124,   125,   126,   127,     0,
     128,   129,   130,   131,     0,     0,     0,     0,     0,   120,
       0,   121,     0,   122,   183,   123,   124,   125,   126,   127,
       0,   128,   129,   130,   131,     0,     0,     0,   120,     0,
     121,     0,   122,   178,   123,   124,   125,   126,   127,     0,
     128,   129,   130,   131,     0,     0,   120,     0,   121,     0,
     122,   132,   123,   124,   125,   126,   127,     0,   128,   129,
     130,   131,     0,     0,   120,     0,   121,     0,   122,   143,
     123,   124,   125,   126,   127,     0,   128,   129,   130,   131,
       0,     0,   120,     0,   121,     0,   122,   203,   123,   124,
     125,   126,   127,     0,   128,   129,   130,   131
};

static const yytype_int16 yycheck[] =
{
      69,     3,    69,    69,    31,    99,    62,     0,    12,    13,
      14,    15,    16,    17,    31,    20,   169,    34,     0,    22,
      18,    76,    41,    18,    79,    31,    32,    33,    34,    41,
      85,     9,    44,   102,    41,   102,    41,    44,    10,    59,
      67,    44,    20,    46,    44,   100,   101,   200,    40,    41,
      54,    55,    42,    58,    56,   208,   111,   112,    56,    44,
      64,    56,   117,    41,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    44,    55,    46,
      58,    58,    45,    46,    44,    41,    45,   142,    45,   144,
      45,    57,    57,    86,    64,   151,   190,   152,    43,   168,
     169,   168,   169,    12,    13,    14,    15,    16,    17,   136,
      57,    57,   181,   115,   181,   181,   171,   172,   173,    48,
      64,    48,   177,   178,    48,    46,    49,    41,    50,    49,
       9,   200,    49,   200,   203,    47,   203,     4,     5,   208,
       7,   208,     9,    44,    11,    54,    55,    57,    44,    44,
      41,    18,    42,    20,    22,    41,    22,    24,    22,    46,
      42,    24,    46,    30,    42,    46,    22,    22,    45,    36,
      37,    38,    39,     6,    41,    42,    45,    44,    14,    22,
      45,    48,    57,    50,   115,    52,    53,     4,     5,    56,
       7,    58,   203,   151,    11,   102,    -1,   178,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    -1,    52,    53,     4,     5,    -1,
       7,    58,    -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    44,    20,    -1,
      -1,    48,    24,    50,    -1,    52,    53,    -1,    30,    -1,
      -1,    58,    -1,    -1,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      52,    53,    -1,    19,    -1,    21,    58,    23,    -1,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    34,    -1,
      19,    -1,    21,    -1,    23,    -1,    25,    26,    27,    28,
      29,    47,    31,    32,    33,    34,    -1,    19,    -1,    21,
      -1,    23,    -1,    25,    26,    27,    28,    29,    47,    31,
      32,    33,    34,    -1,    19,    -1,    21,    -1,    23,    -1,
      25,    26,    27,    28,    29,    47,    31,    32,    33,    34,
      -1,    19,    -1,    21,    -1,    23,    -1,    25,    26,    27,
      28,    29,    47,    31,    32,    33,    34,    -1,    19,    -1,
      21,    -1,    23,    -1,    25,    26,    27,    28,    29,    47,
      31,    32,    33,    34,    -1,    19,    -1,    21,    -1,    23,
      -1,    25,    26,    27,    28,    29,    47,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,
      23,    45,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      -1,    23,    45,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    -1,    23,    45,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    -1,    23,    45,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    34,    -1,    -1,    -1,    19,    -1,
      21,    -1,    23,    43,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    34,    -1,    -1,    19,    -1,    21,    -1,
      23,    42,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    34,    -1,    -1,    19,    -1,    21,    -1,    23,    42,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    34,
      -1,    -1,    19,    -1,    21,    -1,    23,    42,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,    67,    69,     0,    18,    56,    68,    70,    41,
      40,    41,    44,    44,    44,    10,    71,    72,    45,    71,
      59,    45,    42,    57,    45,    41,    76,    57,    72,    64,
      57,    43,    57,    64,    48,    12,    13,    14,    15,    16,
      17,    54,    55,    64,    78,    76,    12,    13,    14,    15,
      16,    17,    54,    55,    77,    48,    69,    73,    48,    46,
      73,    56,    74,    49,    73,    50,    49,     9,    75,    79,
      49,    47,    76,     4,     5,     7,    11,    20,    24,    30,
      36,    37,    38,    39,    41,    44,    48,    50,    52,    53,
      58,    81,    82,    84,    85,    86,    87,    88,    91,    57,
      44,    44,    44,    41,    86,    87,    88,    41,    44,    41,
      86,    44,    46,    90,    86,    69,    41,    44,    42,    22,
      19,    21,    23,    25,    26,    27,    28,    29,    31,    32,
      33,    34,    42,    77,    86,    86,     9,    41,    83,    85,
      87,    88,    46,    42,    46,    41,    24,    86,    89,    86,
      45,    74,    46,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    42,    45,    45,
      76,    46,    42,    22,    86,    86,    45,    46,    43,    45,
      47,    79,    86,    45,    42,    70,    75,    80,    82,    80,
      57,    86,    86,    86,    47,    47,    86,    89,    49,    47,
       6,    77,    47,    42,    47,    80,    84,    45,    45,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    74,    74,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    84,    85,    85,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      87,    88,    88,    88,    89,    89,    89,    90,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     9,     2,     0,    10,    10,     1,
       0,     5,     3,     3,     2,     0,     5,     3,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     1,     1,     5,     5,     7,     5,     9,     2,     2,
       3,     1,     4,     3,     0,     3,     4,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     1,     2,     4,     5,
       7,     2,     4,     5,     3,     1,     0,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* project: program  */
#line 120 "part1.y"
                 { syntaxAnalyzer((yyvsp[0].node),globalScope),generate_three_address_code((yyvsp[0].node)); }
#line 1622 "y.tab.c"
    break;

  case 3: /* program: procedures main  */
#line 122 "part1.y"
                        {(yyval.node)=mkNode("CODE",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1628 "y.tab.c"
    break;

  case 4: /* main: FUNCTION MAIN LPAREN RPAREN COLON VOID LBRACE pro_body RBRACE  */
#line 126 "part1.y"
{
	(yyval.node)=mkNode("main",mkNode("\n\t\tARGS None\n\t\tRET VOID\n\t\t",NULL,(yyvsp[-1].node)),NULL);
}
#line 1636 "y.tab.c"
    break;

  case 5: /* procedures: procedures procedure  */
#line 130 "part1.y"
                                 {(yyval.node)=mkNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1642 "y.tab.c"
    break;

  case 6: /* procedures: %empty  */
#line 131 "part1.y"
          {(yyval.node)=NULL;}
#line 1648 "y.tab.c"
    break;

  case 7: /* procedure: FUNCTION ID LPAREN para_pro RPAREN COLON type_pro LBRACE pro_body RBRACE  */
#line 135 "part1.y"
{ 
		(yyval.node)=mkNode("FUNC",mkNode((yyvsp[-8].string),mkNode(" ",NULL,NULL),mkNode("\n\t\t(ARGS\n\t\t\t(",(yyvsp[-6].node),mkNode(")\n\t\t(Return",(yyvsp[-3].node),NULL))),mkNode(")",(yyvsp[-1].node),NULL));

}
#line 1657 "y.tab.c"
    break;

  case 8: /* procedure: PROCEDUR ID LPAREN para_pro RPAREN COLON VOID LBRACE pro_body RBRACE  */
#line 141 "part1.y"
{
	(yyval.node)=mkNode("FUNC  ",mkNode((yyvsp[-8].string),mkNode("",NULL,NULL),NULL),mkNode("\n\t\t(ARGS\n",(yyvsp[-6].node),(yyvsp[-1].node)));
}
#line 1665 "y.tab.c"
    break;

  case 9: /* para_pro: para_list  */
#line 146 "part1.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 1671 "y.tab.c"
    break;

  case 10: /* para_pro: %empty  */
#line 147 "part1.y"
  {(yyval.node)=NULL;}
#line 1677 "y.tab.c"
    break;

  case 11: /* para_list: ARGS ARG_ARROW var_id COLON type_id  */
#line 151 "part1.y"
                                               {(yyval.node)=mkNode("(",(yyvsp[0].node),mkNode("",(yyvsp[-2].node),mkNode(")",NULL,NULL)));}
#line 1683 "y.tab.c"
    break;

  case 12: /* para_list: para_list SEMICOLON para_list  */
#line 152 "part1.y"
                                         {(yyval.node)=mkNode("",(yyvsp[-2].node),mkNode("",(yyvsp[0].node),NULL));}
#line 1689 "y.tab.c"
    break;

  case 13: /* pro_body: procedures declares stmnts  */
#line 155 "part1.y"
{
	(yyval.node)=mkNode("\n\t\t(BODY\n\t\t", mkNode(" ",(yyvsp[-2].node),NULL),mkNode(" ",(yyvsp[-1].node),mkNode(" ",(yyvsp[0].node),mkNode(" ",NULL,NULL))));
}
#line 1697 "y.tab.c"
    break;

  case 14: /* declares: declares declear  */
#line 160 "part1.y"
                            {(yyval.node)=mkNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1703 "y.tab.c"
    break;

  case 15: /* declares: %empty  */
#line 160 "part1.y"
                                                     {(yyval.node)=NULL;}
#line 1709 "y.tab.c"
    break;

  case 16: /* declear: VAR var_id COLON type_id SEMICOLON  */
#line 163 "part1.y"
{
	(yyval.node)=mkNode("var", (yyvsp[-1].node),(yyvsp[-3].node));
}
#line 1717 "y.tab.c"
    break;

  case 17: /* var_id: ID COMMA var_id  */
#line 167 "part1.y"
                        {(yyval.node)=mkNode((yyvsp[-2].string), mkNode(" ", (yyvsp[0].node), NULL),NULL);}
#line 1723 "y.tab.c"
    break;

  case 18: /* var_id: ID  */
#line 168 "part1.y"
             {(yyval.node)=mkNode((yyvsp[0].string), NULL, NULL);}
#line 1729 "y.tab.c"
    break;

  case 19: /* type_id: BOOL  */
#line 171 "part1.y"
              {(yyval.node)=mkNode("bool", NULL, NULL);}
#line 1735 "y.tab.c"
    break;

  case 20: /* type_id: STRING LBRACKET DEC_VAL RBRACKET  */
#line 172 "part1.y"
                                           {(yyval.node)=mkNode("string", mkNode("[",mkNode("$3",NULL,NULL),NULL), NULL);}
#line 1741 "y.tab.c"
    break;

  case 21: /* type_id: CHAR  */
#line 173 "part1.y"
               {(yyval.node)=mkNode("char", NULL, NULL);}
#line 1747 "y.tab.c"
    break;

  case 22: /* type_id: INT  */
#line 174 "part1.y"
              {(yyval.node)=mkNode("int", NULL, NULL);}
#line 1753 "y.tab.c"
    break;

  case 23: /* type_id: REAL  */
#line 175 "part1.y"
               {(yyval.node)=mkNode("real", NULL, NULL);}
#line 1759 "y.tab.c"
    break;

  case 24: /* type_id: INTPTR  */
#line 176 "part1.y"
                 {(yyval.node)=mkNode("int*", NULL, NULL);}
#line 1765 "y.tab.c"
    break;

  case 25: /* type_id: CHARPTR  */
#line 177 "part1.y"
                  {(yyval.node)=mkNode("char*", NULL, NULL);}
#line 1771 "y.tab.c"
    break;

  case 26: /* type_id: STRING  */
#line 178 "part1.y"
                 {(yyval.node)=mkNode("string",NULL,NULL);}
#line 1777 "y.tab.c"
    break;

  case 27: /* type_id: REALPTR  */
#line 179 "part1.y"
                  {(yyval.node)=mkNode("real*", NULL, NULL);}
#line 1783 "y.tab.c"
    break;

  case 28: /* type_pro: BOOL  */
#line 182 "part1.y"
               {(yyval.node)=mkNode("bool", NULL, NULL);}
#line 1789 "y.tab.c"
    break;

  case 29: /* type_pro: STRING  */
#line 183 "part1.y"
                 {(yyval.node)=mkNode("string", NULL, NULL);}
#line 1795 "y.tab.c"
    break;

  case 30: /* type_pro: CHAR  */
#line 184 "part1.y"
               {(yyval.node)=mkNode("char", NULL, NULL);}
#line 1801 "y.tab.c"
    break;

  case 31: /* type_pro: INT  */
#line 185 "part1.y"
              {(yyval.node)=mkNode("int", NULL, NULL);}
#line 1807 "y.tab.c"
    break;

  case 32: /* type_pro: REAL  */
#line 186 "part1.y"
               {(yyval.node)=mkNode("real", NULL, NULL);}
#line 1813 "y.tab.c"
    break;

  case 33: /* type_pro: VOID  */
#line 187 "part1.y"
               {(yyval.node)=mkNode("void", NULL, NULL);}
#line 1819 "y.tab.c"
    break;

  case 34: /* type_pro: INTPTR  */
#line 188 "part1.y"
                 {(yyval.node)=mkNode("int*", NULL, NULL);}
#line 1825 "y.tab.c"
    break;

  case 35: /* type_pro: CHARPTR  */
#line 189 "part1.y"
                  {(yyval.node)=mkNode("char*", NULL, NULL);}
#line 1831 "y.tab.c"
    break;

  case 36: /* type_pro: REALPTR  */
#line 190 "part1.y"
                  {(yyval.node)=mkNode("real*", NULL, NULL);}
#line 1837 "y.tab.c"
    break;

  case 37: /* stmnts: stmnts stmnt  */
#line 192 "part1.y"
                     {(yyval.node)=mkNode("",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1843 "y.tab.c"
    break;

  case 38: /* stmnts: %empty  */
#line 192 "part1.y"
                                              {(yyval.node)=NULL;}
#line 1849 "y.tab.c"
    break;

  case 39: /* stmnt_block: stmnt  */
#line 194 "part1.y"
                   {(yyval.node)=(yyvsp[0].node);}
#line 1855 "y.tab.c"
    break;

  case 40: /* stmnt_block: declear  */
#line 194 "part1.y"
                                    {(yyval.node)=(yyvsp[0].node);}
#line 1861 "y.tab.c"
    break;

  case 41: /* stmnt_block: procedure  */
#line 194 "part1.y"
                                                       {(yyval.node)=(yyvsp[0].node);}
#line 1867 "y.tab.c"
    break;

  case 42: /* stmnt_block: SEMICOLON  */
#line 194 "part1.y"
                                                                            {(yyval.node)=mkNode("",NULL,NULL);}
#line 1873 "y.tab.c"
    break;

  case 43: /* new_block: LBRACE procedures declares stmnts RBRACE  */
#line 197 "part1.y"
{
	(yyval.node)=mkNode("{",(yyvsp[-3].node),mkNode("", (yyvsp[-1].node),mkNode("", (yyvsp[-1].node),("}",NULL,NULL))));
}
#line 1881 "y.tab.c"
    break;

  case 44: /* stmnt: IF LPAREN expr RPAREN stmnt_block  */
#line 204 "part1.y"
{
	(yyval.node)=mkNode("if",
	mkNode("(", (yyvsp[-2].node), 
	mkNode(")",NULL,NULL)),(yyvsp[0].node));
}
#line 1891 "y.tab.c"
    break;

  case 45: /* stmnt: IF LPAREN expr RPAREN stmnt_block ELSE stmnt_block  */
#line 210 "part1.y"
{
	(yyval.node)=mkNode("if-else",
	mkNode("", (yyvsp[-4].node), 
	mkNode("",NULL,NULL)),
	mkNode("",(yyvsp[-2].node),
	mkNode("",(yyvsp[0].node),NULL)));
}
#line 1903 "y.tab.c"
    break;

  case 46: /* stmnt: WHILE LPAREN expr RPAREN stmnt_block  */
#line 218 "part1.y"
{
	(yyval.node)=mkNode("while",
	mkNode("(", (yyvsp[-2].node), 
	mkNode(")",NULL,NULL)),(yyvsp[0].node));
}
#line 1913 "y.tab.c"
    break;

  case 47: /* stmnt: FOR LPAREN for_declars SEMICOLON expr SEMICOLON assmnt_stmnt RPAREN stmnt_block  */
#line 224 "part1.y"
{
		(yyval.node)= mkNode("for",
			mkNode("(",
			mkNode("",(yyvsp[-6].node),(yyvsp[-4].node)),
			mkNode("",(yyvsp[-2].node),
			mkNode(")",NULL,NULL))),(yyvsp[0].node));		
}
#line 1925 "y.tab.c"
    break;

  case 48: /* stmnt: assmnt_stmnt SEMICOLON  */
#line 231 "part1.y"
                         {(yyval.node)=mkNode("",(yyvsp[-1].node),NULL);}
#line 1931 "y.tab.c"
    break;

  case 49: /* stmnt: expr SEMICOLON  */
#line 232 "part1.y"
                  {(yyval.node)=(yyvsp[-1].node);}
#line 1937 "y.tab.c"
    break;

  case 50: /* stmnt: RETURN expr SEMICOLON  */
#line 233 "part1.y"
                        {(yyval.node)=mkNode("return",(yyvsp[-1].node),NULL);}
#line 1943 "y.tab.c"
    break;

  case 51: /* stmnt: new_block  */
#line 234 "part1.y"
            {(yyval.node)=(yyvsp[0].node);}
#line 1949 "y.tab.c"
    break;

  case 52: /* for_declars: VAR var_id COLON type_id  */
#line 236 "part1.y"
                                     {(yyval.node)=mkNode("var",(yyvsp[0].node),(yyvsp[-2].node));}
#line 1955 "y.tab.c"
    break;

  case 53: /* for_declars: lhs ASSINGMENT expr  */
#line 237 "part1.y"
                                              {(yyval.node)=mkNode("=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1961 "y.tab.c"
    break;

  case 54: /* for_declars: %empty  */
#line 238 "part1.y"
                          {(yyval.node)=NULL;}
#line 1967 "y.tab.c"
    break;

  case 55: /* assmnt_stmnt: lhs ASSINGMENT expr  */
#line 244 "part1.y"
{
	(yyval.node)=mkNode("=",(yyvsp[-2].node),(yyvsp[0].node));
}
#line 1975 "y.tab.c"
    break;

  case 56: /* lhs: ID LBRACKET expr RBRACKET  */
#line 249 "part1.y"
{
	(yyval.node)=mkNode((yyvsp[-3].string), mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)), NULL);
}
#line 1983 "y.tab.c"
    break;

  case 57: /* lhs: ID  */
#line 252 "part1.y"
     {(yyval.node)=mkNode((yyvsp[0].string),NULL,NULL);}
#line 1989 "y.tab.c"
    break;

  case 58: /* lhs: address_expr  */
#line 253 "part1.y"
               {(yyval.node)=(yyvsp[0].node);}
#line 1995 "y.tab.c"
    break;

  case 59: /* lhs: derefrence_expr  */
#line 254 "part1.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2001 "y.tab.c"
    break;

  case 60: /* expr: LPAREN expr RPAREN  */
#line 256 "part1.y"
                          {(yyval.node)=mkNode("(",(yyvsp[-1].node),mkNode(")",NULL,NULL));}
#line 2007 "y.tab.c"
    break;

  case 61: /* expr: expr EQ expr  */
#line 258 "part1.y"
                 {(yyval.node)=mkNode("==",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2013 "y.tab.c"
    break;

  case 62: /* expr: expr NOTEQ expr  */
#line 259 "part1.y"
                          {(yyval.node)=mkNode("!=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2019 "y.tab.c"
    break;

  case 63: /* expr: expr GTE expr  */
#line 260 "part1.y"
                        {(yyval.node)=mkNode(">=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2025 "y.tab.c"
    break;

  case 64: /* expr: expr GT expr  */
#line 261 "part1.y"
                       {(yyval.node)=mkNode(">",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2031 "y.tab.c"
    break;

  case 65: /* expr: expr LTE expr  */
#line 262 "part1.y"
                        {(yyval.node)=mkNode("<=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2037 "y.tab.c"
    break;

  case 66: /* expr: expr LT expr  */
#line 263 "part1.y"
                       {(yyval.node)=mkNode("<",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2043 "y.tab.c"
    break;

  case 67: /* expr: expr AND expr  */
#line 264 "part1.y"
                        {(yyval.node)=mkNode("&&",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2049 "y.tab.c"
    break;

  case 68: /* expr: expr OR expr  */
#line 265 "part1.y"
                       {(yyval.node)=mkNode("||",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2055 "y.tab.c"
    break;

  case 69: /* expr: expr PLUS expr  */
#line 267 "part1.y"
                         {(yyval.node)=mkNode("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2061 "y.tab.c"
    break;

  case 70: /* expr: expr MINUS expr  */
#line 268 "part1.y"
                          {(yyval.node)=mkNode("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2067 "y.tab.c"
    break;

  case 71: /* expr: expr STAR expr  */
#line 269 "part1.y"
                         {(yyval.node)=mkNode("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2073 "y.tab.c"
    break;

  case 72: /* expr: expr DIVISION expr  */
#line 270 "part1.y"
                             {(yyval.node)=mkNode("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2079 "y.tab.c"
    break;

  case 73: /* expr: NOT expr  */
#line 272 "part1.y"
                   {(yyval.node)=mkNode("!",(yyvsp[0].node),NULL);}
#line 2085 "y.tab.c"
    break;

  case 74: /* expr: address_expr  */
#line 273 "part1.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2091 "y.tab.c"
    break;

  case 75: /* expr: derefrence_expr  */
#line 274 "part1.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2097 "y.tab.c"
    break;

  case 76: /* expr: call_func  */
#line 275 "part1.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2103 "y.tab.c"
    break;

  case 77: /* expr: DEC_VAL  */
#line 276 "part1.y"
                  {(yyval.node)=mkNode((yyvsp[0].string),mkNode("INT",NULL,NULL),NULL);}
#line 2109 "y.tab.c"
    break;

  case 78: /* expr: CHAR_VAL  */
#line 277 "part1.y"
                   {(yyval.node)=mkNode((yyvsp[0].string),mkNode("CHAR", NULL, NULL),NULL);}
#line 2115 "y.tab.c"
    break;

  case 79: /* expr: REAL_VAL  */
#line 278 "part1.y"
                   {(yyval.node)=mkNode((yyvsp[0].string),mkNode("REAL", NULL, NULL),NULL);}
#line 2121 "y.tab.c"
    break;

  case 80: /* expr: STR_VAL  */
#line 279 "part1.y"
                  {(yyval.node)=mkNode((yyvsp[0].string),mkNode("STRING", NULL, NULL),NULL);}
#line 2127 "y.tab.c"
    break;

  case 81: /* expr: BFALSE  */
#line 280 "part1.y"
                 {(yyval.node)=mkNode((yyvsp[0].string),mkNode("BOOL", NULL, NULL),NULL);}
#line 2133 "y.tab.c"
    break;

  case 82: /* expr: BTRUE  */
#line 281 "part1.y"
                {(yyval.node)=mkNode((yyvsp[0].string),mkNode("BOOL", NULL, NULL),NULL);}
#line 2139 "y.tab.c"
    break;

  case 83: /* expr: LENGTH ID LENGTH  */
#line 283 "part1.y"
        {
		(yyval.node)=mkNode("|",
		mkNode((yyvsp[-1].string),NULL,NULL),
		mkNode("|",NULL,NULL));
	}
#line 2149 "y.tab.c"
    break;

  case 84: /* expr: ID LBRACKET expr RBRACKET  */
#line 289 "part1.y"
        {(yyval.node)=mkNode("var",mkNode((yyvsp[-3].string),mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)),NULL),NULL);}
#line 2155 "y.tab.c"
    break;

  case 85: /* expr: ID  */
#line 290 "part1.y"
             {(yyval.node)=mkNode(" var",mkNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2161 "y.tab.c"
    break;

  case 86: /* expr: NULLL  */
#line 291 "part1.y"
                {(yyval.node)=mkNode("null",NULL,NULL);}
#line 2167 "y.tab.c"
    break;

  case 87: /* address_expr: ADDRESS ID  */
#line 293 "part1.y"
                         {(yyval.node)=mkNode("&",mkNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2173 "y.tab.c"
    break;

  case 88: /* address_expr: ADDRESS LPAREN ID RPAREN  */
#line 294 "part1.y"
                                   {(yyval.node)=mkNode("&",mkNode("(",mkNode((yyvsp[-1].string),NULL,NULL),NULL),mkNode(")",NULL,NULL));}
#line 2179 "y.tab.c"
    break;

  case 89: /* address_expr: ADDRESS ID LBRACKET expr RBRACKET  */
#line 296 "part1.y"
        {(yyval.node)=mkNode("&", mkNode((yyvsp[-3].string),mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)),NULL),NULL);}
#line 2185 "y.tab.c"
    break;

  case 90: /* address_expr: ADDRESS LPAREN ID LBRACKET expr RBRACKET RPAREN  */
#line 298 "part1.y"
        {
		(yyval.node)=mkNode("&",
		mkNode("(", 
		mkNode((yyvsp[-4].string),mkNode("[",(yyvsp[-2].node),mkNode("]",NULL,NULL)),NULL)
		,mkNode(")",NULL,NULL)),NULL);
	}
#line 2196 "y.tab.c"
    break;

  case 91: /* derefrence_expr: DEREFRENCE ID  */
#line 305 "part1.y"
                                       {(yyval.node)=mkNode("^",mkNode((yyvsp[0].string),NULL,NULL),NULL);}
#line 2202 "y.tab.c"
    break;

  case 92: /* derefrence_expr: DEREFRENCE LPAREN expr RPAREN  */
#line 306 "part1.y"
                                        {(yyval.node)=mkNode("^",mkNode("(",(yyvsp[-1].node),NULL),mkNode(")",NULL,NULL));}
#line 2208 "y.tab.c"
    break;

  case 93: /* derefrence_expr: DEREFRENCE ID LBRACKET expr RBRACKET  */
#line 308 "part1.y"
        {(yyval.node)=mkNode((yyvsp[-4].string), mkNode((yyvsp[-3].string),mkNode("[",(yyvsp[-1].node),mkNode("]",NULL,NULL)),NULL), NULL);}
#line 2214 "y.tab.c"
    break;

  case 94: /* expr_list: expr COMMA expr_list  */
#line 310 "part1.y"
                                {(yyval.node)=mkNode("",(yyvsp[-2].node),mkNode(",",(yyvsp[0].node),NULL));}
#line 2220 "y.tab.c"
    break;

  case 95: /* expr_list: expr  */
#line 311 "part1.y"
               {(yyval.node)=mkNode("",(yyvsp[0].node),NULL);}
#line 2226 "y.tab.c"
    break;

  case 96: /* expr_list: %empty  */
#line 312 "part1.y"
          {(yyval.node)=NULL;}
#line 2232 "y.tab.c"
    break;

  case 97: /* paren_expr: LPAREN expr_list RPAREN  */
#line 314 "part1.y"
                                   {(yyval.node)=(yyvsp[-1].node);}
#line 2238 "y.tab.c"
    break;

  case 98: /* call_func: ID paren_expr  */
#line 315 "part1.y"
                         {(yyval.node)=mkNode("Call func",mkNode((yyvsp[-1].string),NULL,NULL),mkNode("ARGS",(yyvsp[0].node),NULL));}
#line 2244 "y.tab.c"
    break;


#line 2248 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 316 "part1.y"




int main()
{
	int res = yyparse();
	if(res==0)
		printf("\nThe Syntax and Semantics Are Valid\n");
		//printtree(tree,0,0); 
	return res;	
}


///////////////////////////////////////////////////////////////////////////


void addVar(Varaiable * arguments,int countvars,int isArg,SCOPE * MYscope){
	if(countvars==0)
	return;
	Varaiable* tmp;
	SCOPE * scopes=MYscope;

	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("There is the same var %s in one declare",arguments[i].name);
		SCOPE * t=scopes->preScope;
		while(t->preScope!=NULL && t->preScope->Fcount==0)
			t=t->preScope;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->Fcount-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(scopes->var==NULL)
	{ 
		scopes->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		tmp=scopes->var;
		scopes->var=(Varaiable*) malloc(sizeof(Varaiable)*(scopes->VarCount+countvars));
		for(int i=0;i<scopes->VarCount;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(tmp[i].name,arguments[j].name)==0 )
				{
					printf("There can't be the same var %s in same scope",tmp[i].name);
					SCOPE * t=scopes->preScope;
					while(t->preScope!=NULL && t->preScope->Fcount==0)
						t=t->preScope;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->Fcount-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			scopes->var[i]=tmp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{

		scopes->var[scopes->VarCount].name=arguments[j].name;
		scopes->var[scopes->VarCount].value=NULL;
		scopes->var[scopes->VarCount].isArg=isArg;
		scopes->var[scopes->VarCount].length=arguments[j].length;
		scopes->var[(scopes->VarCount)++].type=arguments[j].type;
	}

}


char * getExpType(node * tree,SCOPE* MYscope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
	
		if(strcmp(tree->left->token,"BOOL")==0)
			msg= "bool";
		if(strcmp(tree->token,"!")==0)
		if(strcmp(getExpType(tree->left,MYscope),"bool")==0)
			msg="bool";
		else{
			printf("ERROR, you can use operator ! only on bool type");
			exit(1);
		}
		if(strcmp(tree->token,"|")==0)
		if(strcmp(getExpType(tree->left,MYscope),"string")==0)
		msg="int";
		else{
			printf("ERROR, you can use operator | only on string type in the function %s",globalScope->func[globalScope->Fcount-1]->name);
			exit(1);
		}
		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->right,MYscope),"string")!=0)
			msg="bool";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			msg="bool";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{

			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->right,MYscope),"bool")==0)
			msg="bool";
			else{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
			

		}
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->left,MYscope),"int")==0)
			msg="int";
			else
			msg="real";
			}

			if(strcmp(getExpType(tree->right,MYscope),"int")==0&&(strcmp(getExpType(tree->left,MYscope),"char*")==0||strcmp(getExpType(tree->right,MYscope),"int*")==0||strcmp(getExpType(tree->right,MYscope),"real*")==0)){
				msg=getExpType(tree->left,MYscope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}

		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(getExpType(tree->left,MYscope),"int")==0||strcmp(getExpType(tree->left,MYscope),"real")==0)&&(strcmp(getExpType(tree->right,MYscope),"int")==0||strcmp(getExpType(tree->right,MYscope),"real")==0))
			{
			if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))==0&&strcmp(getExpType(tree->left,MYscope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			else
			{
				printf("ERROR, you can't use operator %s between %s and %s in the function %s\n\n",tree->token,getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),globalScope->func[globalScope->Fcount-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=getExpType(tree->left->left,MYscope);
			else{
				msg=getExpType(tree->left,MYscope);
				
				}
			if(strcmp(msg,"char")==0)
			msg="char*";
			else
			if(strcmp(msg,"int")==0)
			msg="int*";
			else
			if(strcmp(msg,"real")==0)
			msg="real*";
			else
			{
				printf("ERROR, you can't use %s on %s \n",tree->token,msg);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=getExpType(tree->left->left,MYscope);
			else
				msg=getExpType(tree->left,MYscope);
			
			if(strcmp(msg,"char*")==0)
			msg="char";
			else
			if(strcmp(msg,"int*")==0)
			msg="int";
			else
			if(strcmp(msg,"real*")==0)
			msg="real";
			else
			{
				printf("ERROR, you can't use %s on %s \n",tree->token,msg);
				exit(1);
			}

		}
		if(strcmp(tree->token,"(")==0)
			msg=getExpType(tree->left,MYscope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findFuncInScopes(tree,MYscope);
		
	}
	if(strcmp(msg,"")==0)
		msg=findVar(tree,MYscope);

	
	

	return msg;
}

SCOPE* mkScope(char* name)
{	
	SCOPE *newScope = (SCOPE*)malloc(sizeof(SCOPE));
	newScope->name=name;
	newScope->var=NULL;
	newScope->VarCount=0;
	newScope->func=NULL;
	newScope->Fcount=0;
	newScope->nextScope=NULL;
	newScope->preScope=NULL;
	return newScope;
}


void addFunc(char * name,Varaiable * arguments,node *returnType,int argNum,SCOPE * MYscope){
	Function** tmp;
	SCOPE * scopes = MYscope;
	for(int i=0;i<argNum;i++)
		for(int j=0;j<argNum;j++)
	if(i!=j && strcmp(arguments[j].name,arguments[i].name)==0 )
	{
		printf("ERROR, there are identicles arguments %s in func %s\n",arguments[i].name,name);
		exit(1);
	}
	if(scopes->func==NULL)
	{ 
		scopes->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		tmp=scopes->func;
		scopes->func=(Function**) malloc(sizeof(Function*)*(scopes->Fcount+1));
		for(int i=0;i<scopes->Fcount;i++)
		{
				if(strcmp(tmp[i]->name,name)==0 )
				{
					printf("ERROR, there's already function %s in same scope \n",tmp[i]->name);
					exit(1);
				}
				scopes->func[i]=tmp[i];
		}
	}
		scopes->func[scopes->Fcount]=(Function*) malloc(sizeof(Function));
		scopes->func[scopes->Fcount]->name=name;
		scopes->func[scopes->Fcount]->arguments=arguments;
		if(returnType==NULL)
		scopes->func[scopes->Fcount]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type function %s can't be string\n",name);
				exit(1);
			}
		scopes->func[scopes->Fcount]->returnType=returnType->token;
		}
		scopes->func[scopes->Fcount]->argNum=argNum;
		scopes->func[scopes->Fcount]->findreturn=false;
		++(scopes->Fcount); 

}


/* allocation for node*/
node* mkNode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

int yyerror(char *e)
{
	int yydebug=1;
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "Does not accept '%s'\n",yytext);
	
	return 0;
}

SCOPE* finScope(SCOPE * scopes)
{
	SCOPE * MYscope=scopes;
	if(MYscope!=NULL)
	while(MYscope->nextScope!=NULL)
		MYscope=MYscope->nextScope;
	return MYscope;
}


void syntaxAnalyzer(node *tree,SCOPE * MYscope){
	int flagGalit=0;
	if(strcmp(tree->token, "=") == 0 )
	{
		if(!(strcmp(getExpType(tree->right,MYscope),"NULL")==0&& (strcmp(getExpType(tree->left,MYscope),"real*")==0||strcmp(getExpType(tree->left,MYscope),"int*")==0||strcmp(getExpType(tree->left,MYscope),"char*")==0)))
		if(strcmp(getExpType(tree->left,MYscope),getExpType(tree->right,MYscope))!=0 && (strcmp(getExpType(tree->left,MYscope),"int")!=0) && strcmp(getExpType(tree->right,MYscope),"real")!=0 &&(strcmp(getExpType(tree->left,MYscope),"real")!=0) && strcmp(getExpType(tree->right,MYscope),"int")!=0)
		{
			printf("ERORR, you can't do = between %s and %s in scope %s in the function %s\n",getExpType(tree->left,MYscope),getExpType(tree->right,MYscope),MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int VarCount=0;
		Varaiable * var=mkArguments(tree,&VarCount);
		addVar(var,VarCount,0,MYscope);
		
		
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"bool")!=0)
		{
			printf("ERROR, the condition in if statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"bool")!=0)
		{
			printf("ERROR, the condition in while statement has to be boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
		
		
		
	}
			else if(strcmp(tree->token, "for") == 0)
	{

	 if(strcmp(getExpType(tree->left->left->right,MYscope),"bool")!=0)
		{
			printf("ERROR, the condition in for statement has to be boolean\n");
			exit(1);
		}

		syntaxAnalyzer(tree->left->left->left,MYscope);

		syntaxAnalyzer(tree->left->right->left,MYscope);

		if(strcmp(tree->right->token,"{")!=0)
		{

			pushScopes(MYscope,tree->token);

			if (tree->left) 
				syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
			if (tree->right)
				syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        	scope--;
			return;
		}

		
		
	}
	else if(strcmp(tree->token, "FUNC") == 0)
	{
        int count=0;
		Varaiable * arg=mkArguments(tree->left->right->left,&count);
		addFunc(tree->left->token,arg,tree->left->right->right->left,count,MYscope);
		pushScopes(MYscope,tree->token);
		addVar(arg,count,1,finScope(MYscope));
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));

	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
		if(MYscope->func[MYscope->Fcount-1]->findreturn==false)
		{
			//printf("ERORR, there is no Return in func %s\n",tree->left->token); 
			//exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{
		
        int count=0;
		Varaiable * arg=mkArguments(tree->right->left,&count);
		addFunc(tree->left->token,arg,NULL,count,MYscope);
		pushScopes(MYscope,tree->token);
		addVar(arg,count,1,finScope(MYscope));
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
		scope--;	
		return;
    }


	else if(strcmp(tree->token, "Call func") == 0)
	{
		findFuncInScopes(tree,MYscope);
		//printf("(%s \n",tree->token);
		
		
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{
		pushScopes(NULL,tree->token);
	if (tree->left) 
		syntaxAnalyzer(tree->left,globalScope);
	
	if (tree->right)
		syntaxAnalyzer(tree->right,globalScope);
		scope--;
		return;
	}

    else if(strcmp(tree->token, "main") == 0)
	{
		addFunc(tree->token,NULL,NULL,0,MYscope);
		pushScopes(MYscope,tree->token);

	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        scope--;
		return;
               
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(getExpType(tree->left->left,MYscope),"bool")!=0)
		{
			printf("ERORR, if condition must be of type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			pushScopes(MYscope,tree->token);
			syntaxAnalyzer(tree->right->left,finScope( MYscope->nextScope));
			scope--;
			pushScopes(MYscope,tree->token);
			syntaxAnalyzer(tree->right->right->left,finScope( MYscope->nextScope));
        	scope--;
			return;
		}
	}

	else if(strcmp(tree->token, "return") == 0)
	{
		SCOPE * tmp= MYscope;
		int flag=true;
		while(strcmp(tmp->name,"FUNC")!=0&&strcmp(tmp->name,"PROC")!=0&&strcmp(tmp->name,"CODE")!=0)
		{
			tmp=tmp->preScope;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType))
			{
			printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
			printf("%s ,%s %s\n",getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType,tmp->preScope->func[tmp->preScope->Fcount-1]->name);
			exit(1);
			}
		}
		else
		{
			if (strcmp(tmp->preScope->func[tmp->preScope->Fcount-1]->returnType, "void")==0) 
				flagGalit=1;
			if(tmp->preScope->func[tmp->preScope->Fcount-1]->returnType!=NULL && flagGalit==0)
			{
				if(0==strcmp(getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType))
				{
					tmp->preScope->func[tmp->preScope->Fcount-1]->findreturn=true;
				}
				else // Galit's Change
				{
					printf("ERORR,the return type doesn't match the type of function %s \n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
					printf("%s ,%s %s\n",getExpType(tree->left,MYscope),tmp->preScope->func[tmp->preScope->Fcount-1]->returnType,tmp->preScope->func[tmp->preScope->Fcount-1]->name);
					exit(1);
				}
			}
			else
			{
				printf("ERORR, there can't be return in function '%s', because it's void type\n",tmp->preScope->func[tmp->preScope->Fcount-1]->name);
				exit(1);
			}  
		}  
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    pushScopes(MYscope,tree->token);
	if (tree->left) 
		syntaxAnalyzer(tree->left,finScope( MYscope->nextScope));
	
	if (tree->right)
		syntaxAnalyzer(tree->right,finScope( MYscope->nextScope));
        scope--;
		return;			
	}
	else if(strcmp(tree->token, " var") == 0 )
	{
		findVar(tree->left,MYscope);
	}
	if (tree->left) 
		syntaxAnalyzer(tree->left,MYscope);
	
	if (tree->right)
		syntaxAnalyzer(tree->right,MYscope);
}


void pushScopes(SCOPE* from,char* name)
{
	SCOPE * point;
	if(globalScope==NULL)
		globalScope=mkScope(name);
	else{
	point=globalScope;
	while(point->nextScope!=NULL)
		point=point->nextScope;
	point->nextScope=mkScope(name);
	point->nextScope->preScope=from;
	}
}

char* findFuncInScopes(node * tree,SCOPE * MYscope)
{
	SCOPE* tmp=MYscope;
	Varaiable* arguments;
	bool find = false, flag = true;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->Fcount;i++)
		if(strcmp(tree->left->token,tmp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			arguments=callFuncArguments(MYscope,tree->right->left,&count);
			if(count==tmp->func[i]->argNum)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(arguments[j].type,tmp->func[i]->arguments[t].type)!=0)
						flag=false;
				}
				if(flag==true)
					return tmp->func[i]->returnType;
			}
		}
		tmp=tmp->preScope;
	}
	printf("ERROR,func %s not find call in scope %s in the function %s\n",tree->left->token,MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
	if(find==true)
		printf("There is a function with the same name that accepts different arguments\n");
		exit(1);
}

char *findVar(node * tree,SCOPE * MYscope)
{
	SCOPE* tmp = MYscope;
	if(strcmp(tree->token," var")==0)
		tree=tree->left;
	while(tmp!=NULL)
	{
		for(int i=0;i<tmp->VarCount;i++)
		if(strcmp(tree->token,tmp->var[i].name)==0)
		{
			
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(tmp->var[i].type,"string")==0 )
					if(strcmp(getExpType(tree->left->left,MYscope),"int")==0)
					{
							return "char";
					}
					else
					{
						printf("ERORR, index in string can be only int (<string>[<int>])in scope %s in the function %s\n",MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
						exit(1);
					}
				else
				{
					printf("ERORR,you can use index only on string type (<string>[<int>]) or any poiner type in scope %s in the function %s\n",MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
					exit(1);
				}

			}
			else
			return tmp->var[i].type;

		}
		tmp=tmp->preScope;
	}
	printf("ERORR, var %s wasn't found in scope %s in the function %s\n ",tree->token,MYscope->name,globalScope->func[globalScope->Fcount-1]->name);
	exit(1);	
}

Varaiable * mkArguments(node *tree,int *count){
	Varaiable  *arr=NULL,arr2[50];
	char* type,*length;
	if(tree!=NULL)
	{
		node * temp1=tree,*tmp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			tmp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
			{
				type=tmp->left->token;
				if(tmp->left->left!=NULL)
					length=tmp->left->left->left->token;
				node * tmptree;
				tmptree=tmp->right->left;
				do{
				arr2[*count].name=tmptree->token;
				arr2[*count].type=type;
				arr2[*count].length=length;
				(*count)++;
				if(tmptree->left==NULL)
					tmptree=NULL;
				else
					tmptree=tmptree->left->left;
				}while(tmptree!=NULL);
			}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(tmp->token, "var")!=0);
		tmp=temp1;
		if(strcmp(tmp->token, "(")==0||strcmp(tmp->token, "var")==0)
		{
			type=tmp->left->token;
			node * tmptree;
			if(strcmp(tmp->token, "var")==0)
			tmptree=tmp->right;
			else
			tmptree=tmp->right->left;
			if(tmp->left->left!=NULL)
			length=tmp->left->left->left->token;
			do{
			arr2[*count].name=tmptree->token;
			arr2[*count].type=type;
			arr2[*count].length=length;
			(*count)++;
			if(tmptree->left==NULL)
				tmptree=NULL;
			else
				tmptree=tmptree->left->left;
			}while(tmptree!=NULL);
		}
		arr=(Varaiable*)malloc(sizeof(Varaiable)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=arr2[i].name;
			arr[i].type=arr2[i].type;
		}
	}
	return arr;
}


Varaiable* callFuncArguments(SCOPE * MYscope,node *tree,int * count)
{
	Varaiable  *arr=NULL,arr2[50];
	char* type,*length;
	while(tree!=NULL)
	{
		arr2[(*count)++].type=getExpType(tree->left,MYscope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;

	}
	arr=(Varaiable*)malloc(sizeof(Varaiable)*(*count));
	for(int i = 0; i<*count; i++)
		arr[i].type=arr2[i].type;
	return arr;
}

void printtree(node* tree, int level, int linebreak) {
	char* t = tree->token;
	char* argss=(char*)malloc(sizeof(tree->left));
	struct node* left = tree->left;
	struct node* right = tree->right;

	char* r;

	char* l;
	
	if (left) {
		l = tree->left->token;
		
	}


	if (right)
	 r = tree->right->token;
	 
	


	int lvl = level;

	int closeParen = 0;

	int newline = 0;

	int tabs = 0;

	int leftBreak = 0;

	int rightBreak = 0;

	int pauseLeft = 0;

	int pauseRight = 0;

	int printTabsLeft = 0;

	int unpaus = 1;



	if (streq(t, "") ||

		streq(t, "\n") ||

		streq(t, " ") ||

		streq(t, "}")) {

		if (streq(t, "\n")) {

			printNewline();

			printTabsOnce(level);

		}

		unpaus = 0;

	} else {

		if (streq(t, ")") && openParenthesis == 0);

		else {

			if (currentTab == 0)

				printTabs(level);

		}

		lvl++;

		if (streq(t, "(")) {

			if (streq(r, ")") && streq(l, "")) {

				printNewline();

				printTabs(level);

				printf("(");

				openParenthesis++;

			}

			pauseLeft = 1;

			pauseRight = 1;

			lvl--;

		} else if (streq(t, ")")) {

			if (openParenthesis > 0) {

				printf("%s", t);

				printNewline();

				newline = 1;

				openParenthesis--;

			}

		} else if (streq(t, "FUNC") || streq(t, "CODE ")) {
            
			printf("(%s", t);

			printNewline();

			closeParen = 1;

			newline = 1;

			leftBreak = 1;

			tabs = 1;

			unpause();

		} else if (streq(t, "Call-func")) {

			if (hadOperator) {

				printNewline();

				printTabsOnce(level);

			}

			printf("(%s", t);

			printNewline();

			closeParen = 1;

			newline = 1;

			leftBreak = 1;

			tabs = 1;

			unpause();

			hadOperator = 1;

		} else if (streq(t, "args")) {

			printf("(ARGS");

			newline = 1;

			closeParen = 1;

			if (left) {

				tabs = 1;

				printNewline();

				pauseRight = 1;

				pauseLeft = 1;

				printTabs(level+1);

			} else {

				printf(" NONE");

			}

		} else if (streq(t, "type ")) {

			printf("(TYPE ");

			closeParen = 1;

			newline = 1;

			pauseLeft = 1;

		} else if (streq(t, "body ")) {

			printf("\n\t\t(BODY");

			printNewline();

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "return")) {

			printf("\t(RET ");

			closeParen = 1;

			pauseLeft = 1;

			newline = 1;

			if (left && isOperator(l)) tabs = 1;

		} else if (streq(t, "var") || streq(t, "string")) {
            
			printf("(DECLARE ");

			closeParen = 1;

			newline = 1;

			pauseLeft = 1;

			pauseRight = 1;

		} else if (streq(t, "if")){

			printf("(IF ");

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "if-else")){

			printf("(IF-ELSE ");

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "while")){
            

			printf("(WHILE ");

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "do")){

			printf("(DO");

			printNewline();

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "for")){

			printf("(FOR");

			printNewline();

			closeParen = 1;

			tabs = 1;

			newline = 1;

		} else if (streq(t, "{")) {

			printf("(BLOCK");

			printNewline();

			closeParen = 1;

			newline = 1;

			tabs = 1;

		} else if (isType(t)) {

			printf("%s", t);

			unpaus = 0;

		} else if (streq(t, "=")) {

			printf("(=");

			pauseLeft = 1;

			pauseRight = 1;

			closeParen = 1;

			newline = 1;

			hadOperator = 0;

		} else if (isOperator(t)) {

			printNewline();

			unpause();

			hadOperator = 1;

			printTabs(level);

			printf("(%s", t);

			if (streq(t, "!")) tabs = 1;

			closeParen = 1;

			pauseLeft = 1;

			newline = 1;

			if (right) {

				if (streq(r, "Call func")) {

					leftBreak = 1;

					printNewline();

					currentTab = 0;

					printTabsLeft = 1;

				} else {

					rightBreak = 1;

				}

				tabs = 1;

			}

			if (left && right) {

				rightBreak = 1;

				newline = 1;

			}

		} else if (streq(t, "]\n")) {

			printf("%s", t);

			printTabsOnce(level);

		} else if (streq(t, "TRUE ") || streq(t, "FALSE ")) {

			printf("%s", t);

			printNewline();

		} else {

			printf(" %s", t);

			unpaus = 0;

			if (linebreak) printNewline();

			--lvl;

		}

	}

	if (left) {

		if (printTabsLeft) { printTabsOnce(lvl); }

		if (pauseLeft) pausex();

		printtree(left, lvl, leftBreak);

	}

	if (right) {

		if (pauseRight) pausex();

		printtree(right, lvl, rightBreak);

	}

	if (currentTab == 0 && (tabs || (hadOperator && streq(t, "=")))) {

		if (streq(t, "args ") && !hadOperator);

		else {

			printTabsOnce(level);

			if (streq(t,"=")) hadOperator = 0;

		}

	}

	if (closeParen) { printf(")"); }

	if (newline) { printNewline(); }

	if (unpaus) { unpause(); }

}


char* concat(char* s1, char* s2) {

	int len1 = strlen(s1);

	int len2 = strlen(s2);

	int len = len1 + len2;

	char* newstr = (char*)malloc(sizeof(char)*len + 1);

	int j = 0;

	for (int i = 0; i < len1; ++i) {

		newstr[j++] = s1[i];

	}

	for (int i = 0; i < len2; ++i) {

		newstr[j++] = s2[i];

	}
	

	newstr[j] = '\0';

	return newstr;

}



void printNewline() {

	printf("\n");

	currentTab = 0;

}



void printTabs(int n)

{

	if (pauselevel)

		return;

	for(int i = 0; i < n; ++i) {

		currentTab++;

		printf("\t");

	}

}



void printTabsOnce(int n) {

	int temp = pauselevel;

	unpause();

	printTabs(n);

	pauselevel = temp;

}



void pausex() {

	pauselevel = 1;

}



void unpause() {

	pauselevel = 0;

}



int streq(char* s1, char* s2) {

	return strcmp(s1, s2) == 0;

}



int isType(char* t) {

	return  streq(t, "BOOL ") ||

			streq(t, "INT ") ||

			streq(t, "CHAR ") ||

			streq(t, "REAL ") ||

			streq(t, "VOID ") ||

			streq(t, "INT* ") ||

			streq(t, "CHAR* ") ||

			streq(t, "REAL* ");

}



int isOperator(char* t) {

	return streq(t, ">") ||

		   streq(t, "<") ||

		   streq(t, ">=") ||

		   streq(t, "<=") ||

		   streq(t, "==") ||

		   streq(t, "!=") ||

		   streq(t, "!") ||

		   streq(t, "||") ||

		   streq(t, "&&") ||

		   streq(t, "*") ||

		   streq(t, "/") ||

		   streq(t, "+") ||

		   streq(t, "-");

}


void printTree(node* tree) {


	printtree(tree,0,0);

}


//////////////////////////////////////////////////////
int l=1,t=0;


char* called;
char* operator;
int x=0;
void generate_three_address_code(node* tree){
	  if (tree == NULL){
	    return;
	  }
 	else if (strcmp(tree->token, "FUNC") == 0 || strcmp(tree->token,"main")==0)
    {	
		if(strcmp(tree->token,"main")==0)
			printf("main:");
        else {
			printf("%s:", tree->left->token);
		}
		printf("\n\tBeginFunc\n");
    }
	else if(strcmp(tree->token,"=")==0){
		if(strcmp(tree->right->token,"Call func")==0){
			if(strcmp(tree->right->right->left->left->token," var")==0){
				printf("\tt%d = %s\n",t,tree->right->right->left->left->left->token);
			}
			else{
	 			printf("\tt%d = %s\n",t,tree->right->right->left->left->token);
			}
			called=tree->left->token;

			printf("\tPushParams t%d\n",t);
			t++;
			
		}
		else{
				if(strcmp(tree->right->token,"+")==0||strcmp(tree->right->token,"-")==0||strcmp(tree->right->token,"*")==0||strcmp(tree->right->token,"/")==0){
					if(strcmp(tree->right->left->token," var")==0 && strcmp(tree->right->right->token," var")==0){

						printf("\tt%d = %s %s %s\n",t,tree->right->left->left->token,tree->right->token,tree->right->right->left->token);
					}
					else if(strcmp(tree->right->left->token," var")==0 && !strcmp(tree->right->right->token," var")==0){
						printf("\tt%d = %s %s %s\n",t,tree->right->left->left->token,tree->right->token,tree->right->right->token);
					}
					else if(!strcmp(tree->right->left->token," var")==0 && strcmp(tree->right->right->token," var")==0){
						printf("\tt%d = %s %s %s\n",t,tree->right->left->left->left->token,tree->right->token,tree->right->right->left->token);
						
					}
					else{
						printf("\tt%d = %s %s %s\n",t,tree->right->left->token,tree->right->token,tree->right->right->token);
						
					}
			}
			else if(strcmp(tree->right->token," var")==0){
				printf("\tt%d = %s\n",t,tree->right->left->token);
			}
	 		else{
				 printf("\tt%d = %s\n",t,tree->right->token);
			}
			printf("\t%s = t%d\n",tree->left->token,t);
			t++;

		}
		
	}
	else if(strcmp(tree->token,"if")==0){
		if(strcmp(tree->left->left->token,"==")==0||strcmp(tree->left->left->token,"!=")==0||strcmp(tree->left->left->token,">=")==0||strcmp(tree->left->left->token,"<=")==0||strcmp(tree->left->left->token,">")==0 ||strcmp(tree->left->left->token,"<")==0){

			if(strcmp(tree->left->left->token,"==")==0 ||strcmp(tree->left->left->token,"!=")==0||strcmp(tree->left->left->token,">=")==0||strcmp(tree->left->left->token,"<=")==0||strcmp(tree->left->left->token,">")==0||strcmp(tree->left->left->token,"<")==0){
				x=l;
				if(strcmp(tree->left->left->right->token," var")==0){
					printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->left->token,l);
				}
				else{
					printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->token,l);
				}
			}
		}
		printf("\tgoto L%d\n",l+1);
		printf("L%d:   ",l);
		l++;
	}
	else if(strcmp(tree->token,"else\t")==0){
			printf("\tgoto L%d\n",l+1);
			printf("L%d:   ",l);
			l++;
	}
	else if(strcmp(tree->token,"return")==0){
		if(strcmp(tree->left->token,"+")==0||strcmp(tree->left->token,"-")==0||strcmp(tree->left->token,"*")==0||strcmp(tree->left->token,"/")==0){
			printf("L%d:     t%d = %s %s %s\n",l,t,tree->left->left->left->token,tree->left->token,tree->left->right->left->token);
		}
		printf("\tReturn t%d\n\tEndFunc\n\n\n",t);
		l++;
		t++;
	}

	else if(strcmp(tree->token,"while")==0){
		printf("L%d:    ",l);
		l++;
		if(strcmp(tree->left->left->token,"==")==0 ||strcmp(tree->left->left->token,"!=")==0||strcmp(tree->left->left->token,">=")==0||strcmp(tree->left->left->token,"<=")==0||strcmp(tree->left->left->token,">")==0||strcmp(tree->left->left->token,"<")==0){
			x=l;
			if(strcmp(tree->left->left->right->token," var")==0){
				printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->left->token,l);
			}
			else{ 
				printf("\tif %s %s %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->token,tree->left->left->right->token,l);
			}
		}
		
		
		printf("\tgoto L%d\n",l+1);
		printf("L%d:   ",l);
		l++;
		
	}
	else if(strcmp(tree->token,"for")==0){
		printf("L%d:    ",l);
		l++;
			printf("\tif %s < %s Goto L%d\n",tree->left->left->left->left->token,tree->left->left->right->token,l);
		printf("\tgoto L%d\n",l+1);
		printf("L%d:   ",l);
		l++;
	}
	else if(strcmp(tree->token,"Call func")==0){
		printf("\n\tt%d = LCall %s\n",t,tree->left->token);
		t++;
		printf("\tPopParams %d\n",t+1);
		printf("\t%s = t%d\n",called,t-1);

	}
	


        generate_three_address_code(tree->left);
        generate_three_address_code(tree->right);

}
