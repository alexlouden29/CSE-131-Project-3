
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine



/* Line 189 of yacc.c  */
#line 90 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Float = 261,
     T_Uint = 262,
     T_Bvec2 = 263,
     T_Bvec3 = 264,
     T_Bvec4 = 265,
     T_Ivec2 = 266,
     T_Ivec3 = 267,
     T_Ivec4 = 268,
     T_Uvec2 = 269,
     T_Uvec3 = 270,
     T_Uvec4 = 271,
     T_Vec2 = 272,
     T_Vec3 = 273,
     T_Vec4 = 274,
     T_Mat2 = 275,
     T_Mat3 = 276,
     T_Mat4 = 277,
     T_While = 278,
     T_For = 279,
     T_If = 280,
     T_Else = 281,
     T_Return = 282,
     T_Break = 283,
     T_Continue = 284,
     T_Do = 285,
     T_Switch = 286,
     T_Case = 287,
     T_Default = 288,
     T_In = 289,
     T_Out = 290,
     T_Const = 291,
     T_Uniform = 292,
     T_LeftParen = 293,
     T_RightParen = 294,
     T_LeftBracket = 295,
     T_RightBracket = 296,
     T_LeftBrace = 297,
     T_RightBrace = 298,
     T_Dot = 299,
     T_Comma = 300,
     T_Colon = 301,
     T_Semicolon = 302,
     T_Question = 303,
     T_LessEqual = 304,
     T_GreaterEqual = 305,
     T_EQ = 306,
     T_NE = 307,
     T_And = 308,
     T_Or = 309,
     T_Plus = 310,
     T_Star = 311,
     T_MulAssign = 312,
     T_DivAssign = 313,
     T_AddAssign = 314,
     T_SubAssign = 315,
     T_Equal = 316,
     T_LeftAngle = 317,
     T_RightAngle = 318,
     T_Dash = 319,
     T_Slash = 320,
     T_Inc = 321,
     T_Dec = 322,
     T_Identifier = 323,
     T_IntConstant = 324,
     T_FloatConstant = 325,
     T_BoolConstant = 326,
     T_FieldSelection = 327,
     LOWEST = 328,
     LOWER_THAN_ELSE = 329
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Float 261
#define T_Uint 262
#define T_Bvec2 263
#define T_Bvec3 264
#define T_Bvec4 265
#define T_Ivec2 266
#define T_Ivec3 267
#define T_Ivec4 268
#define T_Uvec2 269
#define T_Uvec3 270
#define T_Uvec4 271
#define T_Vec2 272
#define T_Vec3 273
#define T_Vec4 274
#define T_Mat2 275
#define T_Mat3 276
#define T_Mat4 277
#define T_While 278
#define T_For 279
#define T_If 280
#define T_Else 281
#define T_Return 282
#define T_Break 283
#define T_Continue 284
#define T_Do 285
#define T_Switch 286
#define T_Case 287
#define T_Default 288
#define T_In 289
#define T_Out 290
#define T_Const 291
#define T_Uniform 292
#define T_LeftParen 293
#define T_RightParen 294
#define T_LeftBracket 295
#define T_RightBracket 296
#define T_LeftBrace 297
#define T_RightBrace 298
#define T_Dot 299
#define T_Comma 300
#define T_Colon 301
#define T_Semicolon 302
#define T_Question 303
#define T_LessEqual 304
#define T_GreaterEqual 305
#define T_EQ 306
#define T_NE 307
#define T_And 308
#define T_Or 309
#define T_Plus 310
#define T_Star 311
#define T_MulAssign 312
#define T_DivAssign 313
#define T_AddAssign 314
#define T_SubAssign 315
#define T_Equal 316
#define T_LeftAngle 317
#define T_RightAngle 318
#define T_Dash 319
#define T_Slash 320
#define T_Inc 321
#define T_Dec 322
#define T_Identifier 323
#define T_IntConstant 324
#define T_FloatConstant 325
#define T_BoolConstant 326
#define T_FieldSelection 327
#define LOWEST 328
#define LOWER_THAN_ELSE 329




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 41 "parser.y"

    int integerConstant;
    bool boolConstant;
    double floatConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    FnDecl *funcDecl;
    List<Decl*> *declList;
    Type *typeDecl;
    TypeQualifier *typeQualifier;
    Expr *expression;
    VarDecl *varDecl;
    List<VarDecl *> *varDeclList;
    List<Stmt*> *stmtList;
    Stmt       *stmt;
    Operator *ops;
    Identifier *funcId;
    List<Expr*> *argList;



/* Line 214 of yacc.c  */
#line 296 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 321 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    18,    21,
      26,    32,    34,    38,    41,    45,    50,    56,    62,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    93,    95,    97,    99,   102,   106,   108,   111,   113,
     115,   117,   120,   123,   125,   127,   129,   131,   133,   135,
     143,   149,   157,   162,   166,   169,   172,   175,   179,   185,
     195,   197,   199,   201,   203,   207,   210,   213,   217,   220,
     224,   226,   230,   232,   234,   239,   241,   244,   247,   251,
     253,   256,   259,   262,   265,   267,   271,   275,   277,   281,
     285,   287,   291,   295,   299,   303,   305,   309,   313,   315,
     319,   321,   325,   327,   333,   337,   339,   341,   343,   345
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    77,    78,    -1,    78,    -1,
      79,    -1,    80,    86,    -1,    80,    47,    -1,    82,    47,
      -1,    85,    68,    38,    39,    -1,    85,    68,    38,    81,
      39,    -1,    82,    -1,    81,    45,    82,    -1,    85,    68,
      -1,    84,    85,    68,    -1,    85,    68,    61,    83,    -1,
      84,    85,    68,    61,    83,    -1,    85,    68,    40,    69,
      41,    -1,    84,    85,    68,    40,    69,    41,    -1,   110,
      -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,     5,
      -1,     3,    -1,     6,    -1,     4,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    42,
      43,    -1,    42,    87,    43,    -1,    88,    -1,    87,    88,
      -1,    86,    -1,    89,    -1,    47,    -1,    82,    47,    -1,
     110,    47,    -1,    90,    -1,    91,    -1,    92,    -1,    93,
      -1,    94,    -1,    95,    -1,    25,    38,   110,    39,    88,
      26,    88,    -1,    25,    38,   110,    39,    88,    -1,    31,
      38,   110,    39,    42,    87,    43,    -1,    32,   110,    46,
      88,    -1,    33,    46,    88,    -1,    28,    47,    -1,    29,
      47,    -1,    27,    47,    -1,    27,   110,    47,    -1,    23,
      38,   110,    39,    88,    -1,    24,    38,   110,    47,   110,
      47,   110,    39,    88,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    38,   110,    39,    -1,    99,    39,    -1,
      98,    39,    -1,   101,    38,     3,    -1,   101,    38,    -1,
     101,    38,   100,    -1,   110,    -1,   100,    45,   110,    -1,
      68,    -1,    96,    -1,   102,    40,   110,    41,    -1,    97,
      -1,   102,    66,    -1,   102,    67,    -1,   102,    44,    72,
      -1,   102,    -1,    66,   103,    -1,    67,   103,    -1,    55,
     103,    -1,    64,   103,    -1,   103,    -1,   104,    56,   103,
      -1,   104,    65,   103,    -1,   104,    -1,   105,    55,   104,
      -1,   105,    64,   104,    -1,   105,    -1,   106,    62,   105,
      -1,   106,    63,   105,    -1,   106,    50,   105,    -1,   106,
      49,   105,    -1,   106,    -1,   107,    51,   106,    -1,   107,
      52,   106,    -1,   107,    -1,   108,    53,   107,    -1,   108,
      -1,   109,    54,   108,    -1,   109,    -1,   109,    48,   109,
      46,   109,    -1,   103,   111,   110,    -1,    61,    -1,    59,
      -1,    60,    -1,    57,    -1,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   151,   152,   163,   164,   175,   176,   179,
     185,   192,   193,   196,   201,   206,   212,   217,   222,   230,
     233,   234,   235,   236,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   251,   252,   255,   256,   259,   260,
     263,   264,   268,   269,   270,   271,   272,   273,   274,   277,
     281,   287,   292,   293,   296,   297,   298,   299,   302,   305,
     311,   314,   315,   316,   317,   320,   321,   324,   325,   328,
     331,   332,   335,   338,   339,   340,   343,   348,   353,   360,
     361,   366,   371,   376,   383,   384,   389,   396,   397,   402,
     409,   410,   415,   420,   425,   432,   433,   438,   445,   446,
     453,   454,   461,   462,   466,   472,   473,   474,   475,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Float",
  "T_Uint", "T_Bvec2", "T_Bvec3", "T_Bvec4", "T_Ivec2", "T_Ivec3",
  "T_Ivec4", "T_Uvec2", "T_Uvec3", "T_Uvec4", "T_Vec2", "T_Vec3", "T_Vec4",
  "T_Mat2", "T_Mat3", "T_Mat4", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_Continue", "T_Do", "T_Switch", "T_Case",
  "T_Default", "T_In", "T_Out", "T_Const", "T_Uniform", "T_LeftParen",
  "T_RightParen", "T_LeftBracket", "T_RightBracket", "T_LeftBrace",
  "T_RightBrace", "T_Dot", "T_Comma", "T_Colon", "T_Semicolon",
  "T_Question", "T_LessEqual", "T_GreaterEqual", "T_EQ", "T_NE", "T_And",
  "T_Or", "T_Plus", "T_Star", "T_MulAssign", "T_DivAssign", "T_AddAssign",
  "T_SubAssign", "T_Equal", "T_LeftAngle", "T_RightAngle", "T_Dash",
  "T_Slash", "T_Inc", "T_Dec", "T_Identifier", "T_IntConstant",
  "T_FloatConstant", "T_BoolConstant", "T_FieldSelection", "LOWEST",
  "LOWER_THAN_ELSE", "$accept", "Program", "DeclList", "Decl",
  "Declaration", "FuncDecl", "ParameterList", "SingleDecl", "Initializer",
  "TypeQualify", "TypeDecl", "CompoundStatement", "StatementList",
  "Statement", "SingleStatement", "SelectionStmt", "SwitchStmt",
  "CaseStmt", "JumpStmt", "WhileStmt", "ForStmt", "PrimaryExpr",
  "FunctionCallExpr", "FunctionCallHeaderNoParameters",
  "FunctionCallHeaderWithParameters", "ArgumentList", "FunctionIdentifier",
  "PostfixExpr", "UnaryExpr", "MultiExpr", "AdditionExpr", "RelationExpr",
  "EqualityExpr", "LogicAndExpr", "LogicOrExpr", "Expression", "AssignOp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    83,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    92,    92,    93,    93,    93,    93,    94,    95,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    99,
     100,   100,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   103,   103,   104,   104,   104,   105,   105,   105,
     106,   106,   106,   106,   106,   107,   107,   107,   108,   108,
     109,   109,   110,   110,   110,   111,   111,   111,   111,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     2,     2,     4,
       5,     1,     3,     2,     3,     4,     5,     5,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     7,
       5,     7,     4,     3,     2,     2,     2,     3,     5,     9,
       1,     1,     1,     1,     3,     2,     2,     3,     2,     3,
       1,     3,     1,     1,     4,     1,     2,     2,     3,     1,
       2,     2,     2,     2,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     5,     3,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    27,    24,    26,    28,    29,    30,    31,    32,
      33,    20,    21,    22,    23,     0,     2,     4,     5,     0,
       0,     0,     0,     1,     3,     0,     7,     6,     8,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    40,     0,     0,     0,     0,    60,    61,    62,
      63,     0,     0,    38,     0,    36,    39,    43,    44,    45,
      46,    47,    48,    73,    75,     0,     0,     0,    79,    84,
      87,    90,    95,    98,   100,   102,     0,    14,     0,     0,
       0,     0,     0,     0,    56,     0,    54,    55,     0,     0,
       0,     0,    82,    83,    80,    81,    41,    13,    35,    37,
      66,    65,    68,     0,     0,    76,    77,   108,   109,   106,
     107,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     9,
       0,    11,     0,    15,    19,     0,     0,     0,    57,     0,
       0,    53,    64,    67,    69,    70,     0,    78,   104,    85,
      86,    84,    88,    89,    94,    93,    91,    92,    96,    97,
      99,     0,   101,     0,    16,    10,     0,    17,     0,     0,
       0,     0,    52,     0,    74,     0,    18,    12,    58,     0,
      50,     0,    71,   103,     0,     0,     0,     0,    49,    51,
       0,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,   130,    51,   133,    21,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   144,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   112
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
     107,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,    12,   107,  -119,  -119,    21,
      -5,   355,   -12,  -119,  -119,   150,  -119,  -119,  -119,    13,
     -30,    76,    79,    92,   -34,    46,    85,    97,    93,    91,
      93,  -119,  -119,    93,    93,    93,    93,   101,  -119,  -119,
    -119,   100,    82,  -119,   205,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   110,   113,   127,   -26,    62,
     -45,    -2,     2,    -6,   123,   -39,   133,   -37,    55,   120,
      93,    93,    93,    93,  -119,   143,  -119,  -119,    93,   145,
     315,   155,  -119,  -119,  -119,  -119,  -119,   -18,  -119,  -119,
    -119,  -119,    16,    93,   124,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,  -119,   126,    93,  -119,
      70,  -119,   161,  -119,  -119,   164,   157,   167,  -119,   168,
     315,  -119,  -119,  -119,   170,  -119,   171,  -119,  -119,  -119,
    -119,  -119,   -45,   -45,    -2,    -2,    -2,    -2,     2,     2,
      -6,   -29,   123,   172,  -119,  -119,   107,  -119,   315,    93,
     315,   189,  -119,    93,  -119,    93,  -119,  -119,  -119,   188,
     218,   315,  -119,   191,    93,   315,   260,   207,  -119,  -119,
     315,  -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   233,  -119,  -119,  -119,     0,   122,  -119,
      23,   232,    72,   -52,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,   -17,   -49,
      81,    24,   131,   130,  -118,   -33,  -119
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      20,    85,    99,   127,    40,    89,   161,    91,    78,   124,
      79,   113,    23,    84,   103,   125,    20,   175,   104,   143,
     114,    43,    79,    22,   128,   125,    92,    93,    94,    95,
      44,    80,    45,    46,    47,    48,    49,    50,   141,    22,
     105,   106,    28,    80,    29,   121,   122,   134,   135,   136,
     137,   117,   118,   115,    40,   139,    30,   183,     1,     2,
       3,     4,   116,    25,   119,   120,   152,   153,    26,   145,
     146,    43,     5,     6,     7,     8,     9,    10,   131,   148,
      44,    77,    45,    46,    47,    48,    49,    50,   172,    11,
      12,    13,    14,    86,   129,   134,   149,   150,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   165,
       1,     2,     3,     4,    81,   166,   178,    82,   180,   107,
     108,   109,   110,   111,     5,     6,     7,     8,     9,    10,
      83,    40,    87,   188,    99,    88,   179,    90,   191,   -72,
     182,    11,    12,    13,    14,   158,   159,    96,    43,   100,
      97,   187,   101,     1,     2,     3,     4,    44,   151,    45,
      46,    47,    48,    49,    50,   102,   177,     5,     6,     7,
       8,     9,    10,    31,    32,    33,   123,    34,    35,    36,
     126,    37,    38,    39,    11,    12,    13,    14,    40,   132,
     138,   140,    25,    41,   142,   163,   147,    42,   154,   155,
     156,   157,   167,   168,   169,    43,   170,   171,     1,     2,
       3,     4,   174,   176,    44,   173,    45,    46,    47,    48,
      49,    50,     5,     6,     7,     8,     9,    10,    31,    32,
      33,   181,    34,    35,    36,   184,    37,    38,    39,    11,
      12,    13,    14,    40,   185,   125,   190,    25,    98,    24,
     164,    27,    42,   186,   160,   162,     0,     0,     0,     0,
      43,     0,     0,     1,     2,     3,     4,     0,     0,    44,
       0,    45,    46,    47,    48,    49,    50,     5,     6,     7,
       8,     9,    10,    31,    32,    33,     0,    34,    35,    36,
       0,    37,    38,    39,    11,    12,    13,    14,    40,     0,
       0,     0,    25,   189,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,     0,    43,     0,     0,     1,     2,
       3,     4,     0,     0,    44,     0,    45,    46,    47,    48,
      49,    50,     5,     6,     7,     8,     9,    10,    31,    32,
      33,     0,    34,    35,    36,     0,    37,    38,    39,    11,
      12,    13,    14,    40,     0,     0,     0,    25,     1,     2,
       3,     4,    42,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     5,     6,     7,     8,     9,    10,     0,    44,
       0,    45,    46,    47,    48,    49,    50
};

static const yytype_int16 yycheck[] =
{
       0,    34,    54,    40,    38,    38,   124,    40,    38,    48,
      40,    56,     0,    47,    40,    54,    16,    46,    44,     3,
      65,    55,    40,     0,    61,    54,    43,    44,    45,    46,
      64,    61,    66,    67,    68,    69,    70,    71,    90,    16,
      66,    67,    47,    61,    21,    51,    52,    80,    81,    82,
      83,    49,    50,    55,    38,    88,    68,   175,     3,     4,
       5,     6,    64,    42,    62,    63,   115,   116,    47,   102,
     103,    55,    17,    18,    19,    20,    21,    22,    78,   112,
      64,    68,    66,    67,    68,    69,    70,    71,   140,    34,
      35,    36,    37,    47,    39,   128,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    39,
       3,     4,     5,     6,    38,    45,   168,    38,   170,    57,
      58,    59,    60,    61,    17,    18,    19,    20,    21,    22,
      38,    38,    47,   185,   186,    38,   169,    46,   190,    38,
     173,    34,    35,    36,    37,   121,   122,    47,    55,    39,
      68,   184,    39,     3,     4,     5,     6,    64,   175,    66,
      67,    68,    69,    70,    71,    38,   166,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    53,    27,    28,    29,
      47,    31,    32,    33,    34,    35,    36,    37,    38,    69,
      47,    46,    42,    43,    39,    69,    72,    47,   117,   118,
     119,   120,    41,    39,    47,    55,    39,    39,     3,     4,
       5,     6,    41,    41,    64,    45,    66,    67,    68,    69,
      70,    71,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    42,    27,    28,    29,    47,    31,    32,    33,    34,
      35,    36,    37,    38,    26,    54,    39,    42,    43,    16,
     128,    19,    47,   181,   123,   125,    -1,    -1,    -1,    -1,
      55,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    64,
      -1,    66,    67,    68,    69,    70,    71,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,    64,    -1,    66,    67,    68,    69,
      70,    71,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    42,     3,     4,
       5,     6,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    17,    18,    19,    20,    21,    22,    -1,    64,
      -1,    66,    67,    68,    69,    70,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    17,    18,    19,    20,    21,
      22,    34,    35,    36,    37,    76,    77,    78,    79,    80,
      82,    84,    85,     0,    78,    42,    47,    86,    47,    85,
      68,    23,    24,    25,    27,    28,    29,    31,    32,    33,
      38,    43,    47,    55,    64,    66,    67,    68,    69,    70,
      71,    82,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    68,    38,    40,
      61,    38,    38,    38,    47,   110,    47,    47,    38,   110,
      46,   110,   103,   103,   103,   103,    47,    68,    43,    88,
      39,    39,    38,    40,    44,    66,    67,    57,    58,    59,
      60,    61,   111,    56,    65,    55,    64,    49,    50,    62,
      63,    51,    52,    53,    48,    54,    47,    40,    61,    39,
      81,    82,    69,    83,   110,   110,   110,   110,    47,   110,
      46,    88,    39,     3,   100,   110,   110,    72,   110,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     107,   109,   108,    69,    83,    39,    45,    41,    39,    47,
      39,    39,    88,    45,    41,    46,    41,    82,    88,   110,
      88,    42,   110,   109,    47,    26,    87,   110,    88,    43,
      39,    88
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
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
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { 
                                      (yylsp[(1) - (1)]); 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program((yyvsp[(1) - (1)].declList));
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) {
                                          if ( IsDebugOn("dumpAST") ) {
                                            program->Print(0);
                                          }
                                          program->Check();
                                      }
                                    }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyvsp[(1) - (2)].funcDecl)->SetFunctionBody((yyvsp[(2) - (2)].stmt)); (yyval.decl) = (yyvsp[(1) - (2)].funcDecl); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (2)].funcDecl); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (2)].varDecl); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {
                            Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(2) - (4)].identifier)); 
                            List<VarDecl *> *formals = new List<VarDecl *>;
                            (yyval.funcDecl) = new FnDecl(id, (yyvsp[(1) - (4)].typeDecl), formals);
                         }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {
                            Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(2) - (5)].identifier)); 
                            (yyval.funcDecl) = new FnDecl(id, (yyvsp[(1) - (5)].typeDecl), (yyvsp[(4) - (5)].varDeclList));
                         }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    { ((yyval.varDeclList) = new List<VarDecl *>)->Append((yyvsp[(1) - (1)].varDecl));  }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    { ((yyval.varDeclList) = (yyvsp[(1) - (3)].varDeclList))->Append((yyvsp[(3) - (3)].varDecl)); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {
                            Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(2) - (2)].identifier)); 
                            (yyval.varDecl) = new VarDecl(id, (yyvsp[(1) - (2)].typeDecl));
                         }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {
                            Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(3) - (3)].identifier)); 
                            (yyval.varDecl) = new VarDecl(id, (yyvsp[(2) - (3)].typeDecl), (yyvsp[(1) - (3)].typeQualifier));
                         }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {
                            // incomplete: drop the initializer here
                            Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(2) - (4)].identifier)); 
                            (yyval.varDecl) = new VarDecl(id, (yyvsp[(1) - (4)].typeDecl), (yyvsp[(4) - (4)].expression));
                         }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {
                            Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(3) - (5)].identifier)); 
                            (yyval.varDecl) = new VarDecl(id, (yyvsp[(2) - (5)].typeDecl), (yyvsp[(1) - (5)].typeQualifier), (yyvsp[(5) - (5)].expression));
                         }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { 
                            Identifier *id = new Identifier((yylsp[(2) - (5)]), (const char *)(yyvsp[(2) - (5)].identifier));
                            (yyval.varDecl) = new VarDecl(id, new ArrayType((yylsp[(1) - (5)]), (yyvsp[(1) - (5)].typeDecl), (yyvsp[(4) - (5)].integerConstant)));
                         }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    { 
                            Identifier *id = new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier));
                            (yyval.varDecl) = new VarDecl(id, new ArrayType((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].typeDecl), (yyvsp[(5) - (6)].integerConstant)), (yyvsp[(1) - (6)].typeQualifier));
                         }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {(yyval.typeQualifier) = TypeQualifier::inTypeQualifier;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {(yyval.typeQualifier) = TypeQualifier::outTypeQualifier;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {(yyval.typeQualifier) = TypeQualifier::constTypeQualifier;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {(yyval.typeQualifier) = TypeQualifier::uniformTypeQualifier;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval.typeDecl) = Type::intType;    }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    { (yyval.typeDecl) = Type::voidType;   }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    { (yyval.typeDecl) = Type::floatType;  }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.typeDecl) = Type::boolType;   }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.typeDecl) = Type::vec2Type;   }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.typeDecl) = Type::vec3Type;   }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { (yyval.typeDecl) = Type::vec4Type;   }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    { (yyval.typeDecl) = Type::mat2Type;   }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { (yyval.typeDecl) = Type::mat3Type;   }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    { (yyval.typeDecl) = Type::mat4Type;   }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    { (yyval.stmt) = new StmtBlock(new List<VarDecl*>, new List<Stmt *>); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    { (yyval.stmt) = new StmtBlock(new List<VarDecl*>, (yyvsp[(2) - (3)].stmtList)); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt)); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    { ((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt)); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { (yyval.stmt) = new EmptyExpr();  }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {
                                       (yyval.stmt) = new DeclStmt((yyvsp[(1) - (2)].varDecl));
                                     }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (2)].expression); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    {
                                        (yyval.stmt) = new IfStmt((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
                                     }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    {
                                        (yyval.stmt) = new IfStmt((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].stmt), NULL);
                                     }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
                                        (yyval.stmt) = new SwitchStmt((yyvsp[(3) - (7)].expression), (yyvsp[(6) - (7)].stmtList), NULL);
                                     }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    { (yyval.stmt) = new Case((yyvsp[(2) - (4)].expression), (yyvsp[(4) - (4)].stmt)); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { (yyval.stmt) = new Default((yyvsp[(3) - (3)].stmt)); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    { (yyval.stmt) = new BreakStmt(yylloc); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    { (yyval.stmt) = new ContinueStmt(yylloc); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { (yyval.stmt) = new ReturnStmt(yylloc); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { (yyval.stmt) = new ReturnStmt(yyloc, (yyvsp[(2) - (3)].expression)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    { (yyval.stmt) = new WhileStmt((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].stmt)); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {
                                    (yyval.stmt) = new ForStmt((yyvsp[(3) - (9)].expression), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].stmt));
                                 }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    { Identifier *id = new Identifier(yylloc, (const char*)(yyvsp[(1) - (1)].identifier));
                                       (yyval.expression) = new VarExpr(yyloc, id);
                                     }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    { (yyval.expression) = new IntConstant(yylloc, (yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    { (yyval.expression) = new FloatConstant(yylloc, (yyvsp[(1) - (1)].floatConstant)); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    { (yyval.expression) = new BoolConstant(yylloc, (yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression);}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (2)].expression); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (2)].expression); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { (yyval.expression) = new Call((yylsp[(1) - (3)]), NULL, (yyvsp[(1) - (3)].funcId), new List<Expr*>); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { (yyval.expression) = new Call((yylsp[(1) - (2)]), NULL, (yyvsp[(1) - (2)].funcId), new List<Expr*>); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    { (yyval.expression) = new Call((yylsp[(1) - (3)]), NULL, (yyvsp[(1) - (3)].funcId), (yyvsp[(3) - (3)].argList));}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    { ((yyval.argList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expression));}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 332 "parser.y"
    { ((yyval.argList) = (yyvsp[(1) - (3)].argList))->Append((yyvsp[(3) - (3)].expression));}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    { (yyval.funcId) = new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    { (yyval.expression) = new ArrayAccess((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression)); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    {
                                       }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    {
                                          Operator *op = new Operator(yylloc, (const char *)(yyvsp[(2) - (2)].identifier));
                                          (yyval.expression) = new PostfixExpr((yyvsp[(1) - (2)].expression), op);
                                       }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    {
                                          Operator *op = new Operator(yylloc, (const char *)(yyvsp[(2) - (2)].identifier));
                                          (yyval.expression) = new PostfixExpr((yyvsp[(1) - (2)].expression), op);
                                       }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 354 "parser.y"
    {
                                          Identifier *id = new Identifier(yylloc, (const char *)(yyvsp[(3) - (3)].identifier));
                                          (yyval.expression) = new FieldAccess((yyvsp[(1) - (3)].expression), id);
                                       }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 362 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(1) - (2)].identifier));
                             (yyval.expression) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expression));
                           }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(1) - (2)].identifier));
                             (yyval.expression) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expression));
                           }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 372 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(1) - (2)].identifier));
                             (yyval.expression) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expression));
                           }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 377 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(1) - (2)].identifier));
                             (yyval.expression) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expression));
                           }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 383 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new ArithmeticExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 390 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new ArithmeticExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 398 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new ArithmeticExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 403 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new ArithmeticExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 411 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new RelationalExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new RelationalExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new RelationalExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 426 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new RelationalExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 432 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 434 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new EqualityExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 439 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new EqualityExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 447 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new LogicalExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 453 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 455 "parser.y"
    {
                             Operator *op = new Operator(yylloc, (yyvsp[(2) - (3)].identifier));
                             (yyval.expression) = new LogicalExpr((yyvsp[(1) - (3)].expression), op, (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 461 "parser.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 463 "parser.y"
    {
                             (yyval.expression) = new ConditionalExpr((yyvsp[(1) - (5)].expression), (yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].expression));
                           }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 467 "parser.y"
    {
                             (yyval.expression) = new AssignExpr((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].ops), (yyvsp[(3) - (3)].expression));
                           }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 472 "parser.y"
    { (yyval.ops) = new Operator(yylloc, (yyvsp[(1) - (1)].identifier));   }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 473 "parser.y"
    { (yyval.ops) = new Operator(yylloc, "+=");  }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 474 "parser.y"
    { (yyval.ops) = new Operator(yylloc, "-=");  }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 475 "parser.y"
    { (yyval.ops) = new Operator(yylloc, "*=");  }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 476 "parser.y"
    { (yyval.ops) = new Operator(yylloc, "/=");  }
    break;



/* Line 1455 of yacc.c  */
#line 2651 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 479 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}

