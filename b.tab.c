
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
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "b.y"

#include<stdio.h>
#include "bib.h"
#include <math.h>
#include "hash_table.c"
#include "quad.c"
//quadruple variable
int deb_else=0;
int deb_if=0;
int qc=0;

int Fin_if=0;
int finInst1=0;
int finInst2=0;
int save_bz=0;
int save_bg=0;
int deb_while=0;
int deb_for=0;
noeud* p;
char savetab [20];
char tmp [20];
char tmp2 [20];
char res [1000];
char* cond_arret;
//table de hashage variable
#define TAILLE_TABLE 100
TableHachage th;
Liste lisElts;
int typeidf,nature;
multi_val2 val2;
float x;

//bison variable
extern int ligne;
extern int col;
int yyparse();
int yylex();
int yyerror(char *s);
extern FILE* yyin;



/* Line 189 of yacc.c  */
#line 116 "b.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     pvar = 258,
     aff = 259,
     pcode = 260,
     pstruct = 261,
     pif = 262,
     pelse = 263,
     pfor = 264,
     pwhile = 265,
     pconst = 266,
     padd = 267,
     psous = 268,
     pmul = 269,
     pint = 270,
     pfloat = 271,
     pdiv = 272,
     psup = 273,
     psupEgal = 274,
     pinf = 275,
     pinfEgal = 276,
     pequal = 277,
     pnotequal = 278,
     ou = 279,
     et = 280,
     negation = 281,
     idf = 282,
     entier = 283,
     reel = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 43 "b.y"

char* operCond;
int num;
char* str;
float flt ;
struct{
int entier;
float reel;
int type;
char* name;
}Col;

struct{
char* cond1;
char* cond2;
char* opera;
}cod;




/* Line 214 of yacc.c  */
#line 203 "b.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 215 "b.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    18,     2,     2,    24,     2,    38,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    25,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    20,     2,    21,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    22,     2,     2,     2,     2,
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
      15,    16,    17,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    17,    22,    27,    34,    41,    44,
      50,    51,    58,    60,    64,    66,    70,    75,    80,    82,
      85,    87,    89,    92,    96,   102,   109,   113,   117,   121,
     125,   129,   131,   133,   135,   139,   144,   146,   148,   150,
     152,   154,   160,   164,   168,   172,   176,   178,   184,   189,
     194,   199,   205,   209,   213,   217,   220,   222,   224,   226,
     228,   230,   232,   237,   242
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    35,    23,     3,    23,    43,    22,
      42,     5,    23,    47,    22,    22,    -1,    43,    15,    46,
      25,    -1,    43,    16,    46,    25,    -1,    43,    11,    46,
       4,    36,    25,    -1,    43,    11,    46,     4,    37,    25,
      -1,    43,    44,    -1,    43,     6,    35,    45,    25,    -1,
      -1,     6,    23,    43,    22,    35,    25,    -1,    35,    -1,
      35,    24,    45,    -1,    35,    -1,    35,    24,    46,    -1,
      35,    20,    36,    21,    -1,    35,    20,    35,    21,    -1,
      48,    -1,    48,    47,    -1,    49,    -1,    52,    -1,    50,
      25,    -1,    35,     4,    51,    -1,    35,    38,    35,     4,
      51,    -1,    35,    20,    35,    21,     4,    51,    -1,    51,
      12,    51,    -1,    51,    13,    51,    -1,    51,    14,    51,
      -1,    51,    17,    51,    -1,    19,    51,    18,    -1,    35,
      -1,    36,    -1,    37,    -1,    35,    38,    35,    -1,    35,
      20,    35,    21,    -1,    59,    -1,    65,    -1,    54,    -1,
      35,    -1,    36,    -1,    55,    18,    23,    47,    22,    -1,
      56,    39,    53,    -1,    57,    39,    36,    -1,    58,    39,
      36,    -1,     9,    19,    35,    -1,    60,    -1,    61,     8,
      23,    47,    22,    -1,    62,    23,    47,    22,    -1,    62,
      23,    47,    22,    -1,     7,    19,    63,    18,    -1,    19,
      51,    64,    51,    18,    -1,    51,    64,    51,    -1,    63,
      32,    63,    -1,    63,    33,    63,    -1,    34,    63,    -1,
      26,    -1,    27,    -1,    30,    -1,    28,    -1,    29,    -1,
      31,    -1,    66,    23,    47,    22,    -1,    67,    19,    63,
      18,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    79,    82,    83,    84,    85,    86,    87,
      88,    91,    93,    94,    96,    96,    96,    96,    99,    99,
     100,   100,   102,   103,   133,   164,   200,   274,   337,   388,
     449,   450,   460,   467,   471,   474,   480,   480,   480,   482,
     482,   483,   490,   505,   513,   523,   541,   551,   564,   572,
     580,   588,   620,   652,   653,   654,   657,   658,   659,   660,
     661,   662,   666,   674,   679
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "pvar", "aff", "pcode", "pstruct", "pif",
  "pelse", "pfor", "pwhile", "pconst", "padd", "psous", "pmul", "pint",
  "pfloat", "pdiv", "')'", "'('", "'['", "']'", "'}'", "'{'", "','", "';'",
  "psup", "psupEgal", "pinf", "pinfEgal", "pequal", "pnotequal", "ou",
  "et", "negation", "idf", "entier", "reel", "'.'", "':'", "$accept", "S",
  "$@1", "PARTIEDEC", "STRUCTURE", "LISTSTRUCT", "LISTEVARIABLE",
  "PARTIEINST", "x", "inst", "instaff", "expr", "INSTIWF", "cond_arret",
  "INSTFOR", "Dinstfor", "Cinstfor", "Binstfor", "Ainstfor", "INSTIF",
  "Bif", "Bifelse", "Aif", "cond", "c", "INSTW", "Binstw", "Ainstw", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    41,    40,
      91,    93,   125,   123,    44,    59,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,    46,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    43,    43,    43,    43,
      43,    44,    45,    45,    46,    46,    46,    46,    47,    47,
      48,    48,    49,    50,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    53,
      53,    54,    55,    56,    57,    58,    59,    59,    60,    61,
      62,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    64,    65,    66,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    12,     4,     4,     6,     6,     2,     5,
       0,     6,     1,     3,     1,     3,     4,     4,     1,     2,
       1,     1,     2,     3,     5,     6,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     4,     1,     1,     1,     1,
       1,     5,     3,     3,     3,     3,     1,     5,     4,     4,
       4,     5,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    10,     0,     0,     0,
       0,     0,     2,     8,    10,     0,    14,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     4,     5,     0,
       0,     0,     9,     0,     0,    15,     0,     0,     0,     0,
      13,    17,    16,     6,     7,     0,     0,    64,     0,     0,
      18,    20,     0,    21,    38,     0,     0,     0,     0,    36,
      46,     0,     0,    37,     0,     0,    11,     0,     0,     0,
       0,     0,     0,    19,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,     0,     0,
      45,     0,    23,     0,     0,     3,     0,    39,    40,    42,
      43,    44,     0,     0,     0,     0,     0,    55,     0,     0,
       0,     0,     0,     0,    56,    57,    59,    60,    58,    61,
       0,    50,     0,     0,     0,     0,     0,     0,     0,    48,
      62,    63,    30,     0,     0,    34,    26,    27,    28,    29,
      52,    53,    54,     0,    24,    41,    47,     0,    35,    25,
      51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    20,     7,    13,    23,    17,    49,    50,    51,
      52,    88,    53,    99,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    89,   120,    63,    64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -78
static const yytype_int16 yypact[] =
{
     -24,     1,    15,    26,   -78,    10,   -78,    75,   -19,    13,
      13,    13,   -78,   -78,   -78,    23,    -7,    48,    40,    59,
      62,    77,    63,    64,     4,    13,    67,   -78,   -78,    73,
      78,    23,   -78,    93,    99,   -78,    96,   100,    -1,   101,
     -78,   -78,   -78,   -78,   -78,    79,   104,   -78,    -2,   102,
      -1,   -78,   103,   -78,   -78,   109,    90,    91,    92,   -78,
     -78,   124,   110,   -78,   111,   116,   -78,    -9,   106,   -16,
     107,   108,   114,   -78,   -78,   115,    72,   112,   113,   117,
      -1,    -1,    -9,   -16,    -9,    -8,   -78,   -78,    49,     5,
     -78,   -16,   105,   118,   133,   -78,    -1,   -78,   -78,   -78,
     -78,   -78,    -1,   122,   123,    17,    42,   -78,   119,   120,
     -16,   -16,   -16,   -16,   -78,   -78,   -78,   -78,   -78,   -78,
     -16,   -78,    -9,    -9,    88,   142,   -16,   125,   128,   143,
     -78,   -78,   -78,   -16,   131,   -78,    68,    68,   -78,   -78,
     105,   126,   -78,   -16,   105,   -78,   -78,    98,   -78,   105,
     -78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -78,   -78,   -78,   139,   -78,   127,    84,   -49,   -78,   -78,
     -78,   -69,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -77,    50,   -78,   -78,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      92,    73,    69,    91,    14,   105,    45,   107,    46,    47,
      83,     1,   108,    24,   106,     4,    15,    25,    70,    85,
      86,    87,   124,   121,     3,    84,    85,    86,    87,     5,
     109,   103,   104,     6,    48,   131,    71,   122,   123,    33,
      34,   136,   137,   138,   139,   141,   142,   127,    16,   122,
     123,   140,    26,   128,   110,   111,   112,   144,    22,   113,
     132,   110,   111,   112,   147,    27,   113,    29,   114,   115,
     116,   117,   118,   119,   149,   114,   115,   116,   117,   118,
     119,     8,   112,     8,    28,   113,     9,    31,     9,    32,
      10,    11,    10,    11,    18,    19,    38,    12,    67,    30,
     110,   111,   112,    36,    37,   113,   132,    97,    98,    35,
     110,   111,   112,    39,    41,   113,   150,   110,   111,   112,
      42,    43,   113,    68,    72,    44,    66,    75,    74,    76,
      77,    78,    79,    80,    81,    82,    95,   126,    96,   125,
     102,    90,    93,    94,   129,   130,   143,   145,   100,   101,
     146,   -49,   148,    21,   134,   135,   133,     0,    40,   123
};

static const yytype_int16 yycheck[] =
{
      69,    50,     4,    19,    23,    82,     7,    84,     9,    10,
      19,    35,    20,    20,    83,     0,    35,    24,    20,    35,
      36,    37,    91,    18,    23,    34,    35,    36,    37,     3,
      38,    80,    81,    23,    35,    18,    38,    32,    33,    35,
      36,   110,   111,   112,   113,   122,   123,    96,    35,    32,
      33,   120,     4,   102,    12,    13,    14,   126,    35,    17,
      18,    12,    13,    14,   133,    25,    17,     5,    26,    27,
      28,    29,    30,    31,   143,    26,    27,    28,    29,    30,
      31,     6,    14,     6,    25,    17,    11,    24,    11,    25,
      15,    16,    15,    16,    10,    11,    23,    22,    19,    22,
      12,    13,    14,    36,    37,    17,    18,    35,    36,    25,
      12,    13,    14,    35,    21,    17,    18,    12,    13,    14,
      21,    25,    17,    19,    22,    25,    25,    18,    25,    39,
      39,    39,     8,    23,    23,    19,    22,     4,    23,    21,
      23,    35,    35,    35,    22,    22,     4,    22,    36,    36,
      22,     8,    21,    14,    35,    35,   106,    -1,    31,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    41,    23,     0,     3,    23,    43,     6,    11,
      15,    16,    22,    44,    23,    35,    35,    46,    46,    46,
      42,    43,    35,    45,    20,    24,     4,    25,    25,     5,
      22,    24,    25,    35,    36,    46,    36,    37,    23,    35,
      45,    21,    21,    25,    25,     7,     9,    10,    35,    47,
      48,    49,    50,    52,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    65,    66,    67,    25,    19,    19,     4,
      20,    38,    22,    47,    25,    18,    39,    39,    39,     8,
      23,    23,    19,    19,    34,    35,    36,    37,    51,    63,
      35,    19,    51,    35,    35,    22,    23,    35,    36,    53,
      36,    36,    23,    47,    47,    63,    51,    63,    20,    38,
      12,    13,    14,    17,    26,    27,    28,    29,    30,    31,
      64,    18,    32,    33,    51,    21,     4,    47,    47,    22,
      22,    18,    18,    64,    35,    35,    51,    51,    51,    51,
      51,    63,    63,     4,    51,    22,    22,    51,    21,    51,
      18
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 79 "b.y"
    {th = init_table(TAILLE_TABLE);transformer_tsToth(lisElts,th);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 79 "b.y"
    { printf ("programme syntaxiquement juste"); YYACCEPT ;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 82 "b.y"
    {remplire(&lisElts,0,0,0);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 83 "b.y"
    {remplire(&lisElts,0,1,0);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 84 "b.y"
    {remplire(&lisElts,1,0,(yyvsp[(5) - (6)].num));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 85 "b.y"
    {remplire(&lisElts,1,1,(yyvsp[(5) - (6)].flt));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 86 "b.y"
    {remplire(&lisElts,0,2,0);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 87 "b.y"
    {remplire(&lisElts,0,2,0);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 91 "b.y"
    {inserer((yyvsp[(5) - (6)].str));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 93 "b.y"
    {inserer((yyvsp[(1) - (1)].str));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 94 "b.y"
    {inserer((yyvsp[(1) - (3)].str));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 96 "b.y"
    {inserer((yyvsp[(1) - (1)].str));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 96 "b.y"
    {inserer((yyvsp[(1) - (3)].str));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 96 "b.y"
    {sprintf(savetab,"%s[%d]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].num)); inserer(savetab);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 96 "b.y"
    {sprintf(savetab,"%s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str)); inserer(savetab);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 103 "b.y"
    {
        //printf("%d=%d",recherche_type(&lisElts,$1),$3.type);
        remplire_cont_idf(&lisElts,(yyvsp[(1) - (3)].str),val2);non_dec(&lisElts,(yyvsp[(1) - (3)].str)); 
         //printf("%s-%d %s-%d\n",$1,recherche_type(&lisElts,$1),$3.name,$3.type);
        if(recherche_type(&lisElts,(yyvsp[(1) - (3)].str))!=(yyvsp[(3) - (3)].Col).type){
        printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
        }
        

        if((yyvsp[(3) - (3)].Col).name==NULL){
                if((yyvsp[(3) - (3)].Col).type==0){
                        
                        sprintf(tmp,"%d",(yyvsp[(3) - (3)].Col).entier);
                        quadr("=",tmp,"vide",(yyvsp[(1) - (3)].str));
                }
                else if((yyvsp[(3) - (3)].Col).type==1){
                         
                        sprintf(tmp,"%.02f",(yyvsp[(3) - (3)].Col).reel);
                        quadr("=",tmp,"vide",(yyvsp[(1) - (3)].str));    
                        }
                        else{
                                 
                                quadr("=",(yyvsp[(3) - (3)].Col).name,"vide",(yyvsp[(1) - (3)].str));        
                        }

                }else{
                       
          
                    quadr("=",(yyvsp[(3) - (3)].Col).name,"vide",(yyvsp[(1) - (3)].str));  
                }
        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 133 "b.y"
    {

                non_dec(&lisElts,(yyvsp[(3) - (5)].str)); 
                non_dec(&lisElts,(yyvsp[(1) - (5)].str));
                sprintf(tmp2,"%s.%s", (yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str));
                 if(recherche_type(&lisElts,(yyvsp[(3) - (5)].str))!=(yyvsp[(5) - (5)].Col).type){
                        printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
                        }
                        

                        if((yyvsp[(5) - (5)].Col).name==NULL){
                                if((yyvsp[(5) - (5)].Col).type==0){
                                        
                                        sprintf(tmp,"%d",(yyvsp[(5) - (5)].Col).entier);
                                        quadr("=",tmp,"vide",tmp2);
                                }
                                else if((yyvsp[(5) - (5)].Col).type==1){
                                        
                                        sprintf(tmp,"%.02f",(yyvsp[(5) - (5)].Col).reel);
                                        quadr("=",tmp,"vide",tmp2);    
                                        }
                                        else{
                                                
                                                quadr("=",(yyvsp[(5) - (5)].Col).name,"vide",tmp2);        
                                        }

                                }else{
                                
                        
                                quadr("=",(yyvsp[(5) - (5)].Col).name,"vide",tmp2);  
                                }
        ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 164 "b.y"
    {
               
                
                non_dec(&lisElts,(yyvsp[(3) - (6)].str)); 
                non_dec_tab(&lisElts,(yyvsp[(1) - (6)].str));
                 sprintf(tmp2,"%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str));
                 if(recherche_type(&lisElts,(yyvsp[(3) - (6)].str))!=(yyvsp[(6) - (6)].Col).type){
                        printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
                        }
                        

                        if((yyvsp[(6) - (6)].Col).name==NULL){
                                if((yyvsp[(6) - (6)].Col).type==0){
                                        
                                        sprintf(tmp,"%d",(yyvsp[(6) - (6)].Col).entier);
                                        quadr("=",tmp,"vide",tmp2);
                                }
                                else if((yyvsp[(6) - (6)].Col).type==1){
                                        
                                        sprintf(tmp,"%.02f",(yyvsp[(6) - (6)].Col).reel);
                                        quadr("=",tmp,"vide",tmp2);    
                                        }
                                        else{
                                                
                                                quadr("=",(yyvsp[(6) - (6)].Col).name,"vide",tmp2);        
                                        }

                                }else{
                                
                        
                                quadr("=",(yyvsp[(6) - (6)].Col).name,"vide",tmp2);  
                                }
        ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 200 "b.y"
    {     
       
        sprintf(res,"T%d", qc);
        if((yyvsp[(1) - (3)].Col).name==NULL && (yyvsp[(3) - (3)].Col).name==NULL){
               
                if((yyvsp[(1) - (3)].Col).type==0 && (yyvsp[(3) - (3)].Col).type==0){
                        (yyval.Col).type = 0;
                        sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col));
                        sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col));
                        quadr("+",tmp,tmp2,res);
                }else if ((yyvsp[(1) - (3)].Col).type==1 && (yyvsp[(3) - (3)].Col).type==1){
                      
                        (yyval.Col).type = 1;
                        sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col));
                        sprintf(tmp2,"%.02f", (yyvsp[(3) - (3)].Col));
                        quadr("+",tmp,tmp2,res); 
                }else if((yyvsp[(1) - (3)].Col).type==0 && (yyvsp[(3) - (3)].Col).type==1){
                        (yyval.Col).type = 1; 
                                
                        sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col).entier);
                        sprintf(tmp2,"%.02f", (yyvsp[(3) - (3)].Col).reel);
                        quadr("+",tmp,tmp2,res);
                }else if((yyvsp[(1) - (3)].Col).type==1 && (yyvsp[(3) - (3)].Col).type==0){
                        (yyval.Col).type = 1; 
                        
                        sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col).reel);
                        sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col).entier);
                        quadr("+",tmp,tmp2,res);
                }
             
                 
        }else   if((yyvsp[(1) - (3)].Col).name==NULL){
                        
                        
                        if((yyvsp[(1) - (3)].Col).type==0){
                        sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col));
                        quadr("+",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                        }else{
                        sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                        quadr("+",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                        }
                        if(((yyvsp[(1) - (3)].Col).type==1 || (yyvsp[(3) - (3)].Col).type==1)){
                                 (yyval.Col).type=1;
                        }else{
                                 (yyval.Col).type=0;
                        }
                     
                }else if((yyvsp[(3) - (3)].Col).name==NULL){
                       
                        
                        if((yyvsp[(3) - (3)].Col).type==0){
                        sprintf(tmp,"%d",(yyvsp[(3) - (3)].Col));
                        quadr("+",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                        }else{
                        sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                        quadr("+",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                        }  
                        if(((yyvsp[(1) - (3)].Col).type==1 || (yyvsp[(3) - (3)].Col).type==1)){
                                 (yyval.Col).type=1;
                        }else{
                                 (yyval.Col).type=0;
                        }
                        (yyval.Col).name = (char*) malloc(20);
                       
                }else{
                        
                        quadr("+",(yyvsp[(1) - (3)].Col).name,(yyvsp[(3) - (3)].Col).name,res); 
                }
                (yyval.Col).name = (char*) malloc(20);
                strcpy((yyval.Col).name,res);
             

       // strcpy($$.name, tmp);
        ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 274 "b.y"
    {
     
                sprintf(res,"T%d", qc);
                if((yyvsp[(1) - (3)].Col).name==NULL && (yyvsp[(3) - (3)].Col).name==NULL){
                
                        if((yyvsp[(1) - (3)].Col).type==0 && (yyvsp[(3) - (3)].Col).type==0){
                                (yyval.Col).type = 0; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col).entier);
                                sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col).entier);
                                quadr("-",tmp,tmp2,res);
                        }else if((yyvsp[(1) - (3)].Col).type==1 && (yyvsp[(3) - (3)].Col).type==1){
                                (yyval.Col).type = 1; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col).reel);
                                sprintf(tmp2,"%.02f", (yyvsp[(3) - (3)].Col).reel);
                                quadr("-",tmp,tmp2,res); 
                        }else if((yyvsp[(1) - (3)].Col).type==0 && (yyvsp[(3) - (3)].Col).type==1){
                                (yyval.Col).type = 1; 
                                 
                                sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col).entier);
                                sprintf(tmp2,"%.02f", (yyvsp[(3) - (3)].Col).reel);
                                quadr("-",tmp,tmp2,res);
                        }else if((yyvsp[(1) - (3)].Col).type==1 && (yyvsp[(3) - (3)].Col).type==0){
                                (yyval.Col).type = 1; 
                               
                                sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col).reel);
                                sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col).entier);
                                quadr("-",tmp,tmp2,res);
                        }
                                
                
                }else   if((yyvsp[(1) - (3)].Col).name==NULL){
                        
                                if((yyvsp[(1) - (3)].Col).type==0){
                                sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col));
                                quadr("-",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                                }else{
                                sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                                quadr("-",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                                }
                                (yyval.Col).name = (char*) malloc(20);
                                strcpy((yyval.Col).name,res);
                        }else if((yyvsp[(3) - (3)].Col).name==NULL){
                                
                        
                                if((yyvsp[(3) - (3)].Col).type==0){
                                sprintf(tmp,"%d",(yyvsp[(3) - (3)].Col));
                                quadr("-",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                                quadr("-",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                                }  
                                (yyval.Col).name = (char*) malloc(20);
                                strcpy((yyval.Col).name,res);
                        }else{
                        
                                quadr("-",(yyvsp[(1) - (3)].Col).name,(yyvsp[(3) - (3)].Col).name,res); 
                        }
                        (yyval.Col).name = (char*) malloc(20);
                        strcpy((yyval.Col).name,res); 

                ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 337 "b.y"
    {
                if((yyvsp[(1) - (3)].Col).type!=(yyvsp[(3) - (3)].Col).type){
                printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
                }
                sprintf(res,"T%d", qc);
                if((yyvsp[(1) - (3)].Col).name==NULL && (yyvsp[(3) - (3)].Col).name==NULL){
                        
                        if((yyvsp[(1) - (3)].Col).type==0 && (yyvsp[(1) - (3)].Col).type==0){
                                (yyval.Col).type = 0; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col).entier);
                                sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col).entier);
                                quadr("*",tmp,tmp2,res);
                        }else{
                                (yyval.Col).type = 1; // initialiser le type de la nouvelle expression à entier
                                
                                sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col).reel);
                                sprintf(tmp2,"%.02f", (yyvsp[(3) - (3)].Col).reel);
                                quadr("*",tmp,tmp2,res); 
                        }
                        
                
                }else   if((yyvsp[(1) - (3)].Col).name==NULL){
                                
                                if((yyvsp[(1) - (3)].Col).type==0){
                                sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col));
                                quadr("*",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                                }else{
                                sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                                quadr("*",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                                }
                        
                        }else if((yyvsp[(3) - (3)].Col).name==NULL){
                                
                                
                                if((yyvsp[(3) - (3)].Col).type==0){
                                sprintf(tmp,"%d",(yyvsp[(3) - (3)].Col));
                                quadr("*",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                                quadr("*",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                                }  
                                
                        }else{
                                
                                quadr("*",(yyvsp[(1) - (3)].Col).name,(yyvsp[(3) - (3)].Col).name,res);   
                        }
                        (yyval.Col).name = (char*) malloc(20);
                        strcpy((yyval.Col).name,res);

                ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 388 "b.y"
    {
        //printf("%d div %d",$1.type,$3.entier);

        /*if($1.type!=$3.type){
           printf("Erreur semantique: Incompatibilite Type  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);     
        }*/
        sprintf(res,"T%d", qc);
        if((yyvsp[(3) - (3)].Col).entier!=0 || (yyvsp[(3) - (3)].Col).reel!=0){
                (yyval.Col).type = 1;
                if((yyvsp[(1) - (3)].Col).name==NULL && (yyvsp[(3) - (3)].Col).name==NULL){
                
                                         
                                if((yyvsp[(1) - (3)].Col).type==0 && (yyvsp[(1) - (3)].Col).type==0){
                                        if((yyvsp[(1) - (3)].Col).entier%(yyvsp[(3) - (3)].Col).entier==0){
                                                (yyval.Col).type = 0; // initialiser le type de la nouvelle expression à entier
                                        }
                                        sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col).entier);
                                        sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col).entier);
                                        quadr("/",tmp,tmp2,res);  
                                }else{
                                        int a = round((yyvsp[(1) - (3)].Col).reel * 100);    
                                        int b = round((yyvsp[(3) - (3)].Col).reel* 100);    
                                        if (a % b == 0) {
                                          (yyval.Col).type = 0;
                                        }

                                      
                                        sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col).reel);
                                        sprintf(tmp2,"%.02f", (yyvsp[(3) - (3)].Col).reel);
                                        //printf("%s",tmp);
                                        quadr("/",tmp,tmp2,res); 
                                }  
                                   
                }else   if((yyvsp[(1) - (3)].Col).name==NULL){
                                 
                                if((yyvsp[(1) - (3)].Col).type==0){
                                
                                sprintf(tmp,"%d", (yyvsp[(1) - (3)].Col));
                                quadr("/",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                                }else{
                                sprintf(tmp,"%.02f", (yyvsp[(1) - (3)].Col));
                                quadr("/",tmp,(yyvsp[(3) - (3)].Col).name,res); 
                                }
                                
                        }else if((yyvsp[(3) - (3)].Col).name==NULL){     
                                 
                                if((yyvsp[(3) - (3)].Col).type==0){
                                sprintf(tmp,"%d",(yyvsp[(3) - (3)].Col));
                                quadr("/",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                                }else{
                                sprintf(tmp,"%.02f", (yyvsp[(3) - (3)].Col));
                                quadr("/",(yyvsp[(1) - (3)].Col).name,tmp,res); 
                                }  
                                 
                        }else{
                             quadr("/",(yyvsp[(1) - (3)].Col).name,(yyvsp[(3) - (3)].Col).name,res);     
                        }
                (yyval.Col).name = (char*) malloc(20);
                strcpy((yyval.Col).name,res);
        }else{printf("Erreur semantique: Division par zero  a la ligne [%d] et a la colonne [%d]\n\n",ligne,col);exit(-1);} 
        ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 449 "b.y"
    {(yyval.Col) = (yyvsp[(2) - (3)].Col);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 450 "b.y"
    {
                (yyval.Col).name = strdup((yyvsp[(1) - (1)].str)); 
                if(recherche_type(&lisElts,(yyvsp[(1) - (1)].str))==1){
                     (yyval.Col).type = 1;    
                }else  if(recherche_type(&lisElts,(yyvsp[(1) - (1)].str))==0){
                       (yyval.Col).type = 0;         
                }else{
                        (yyval.Col).type = 2;
                }
        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 460 "b.y"
    {
                (yyval.Col).type = 0; // initialiser le type de la nouvelle expression à entier
                (yyval.Col).entier=(yyvsp[(1) - (1)].num);
          
           
        ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 467 "b.y"
    {
                (yyval.Col).type = 1; // initialiser le type de la nouvelle expression à réel
                  (yyval.Col).reel=(yyvsp[(1) - (1)].flt);
                  
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 471 "b.y"
    {
                sprintf(tmp,"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
                (yyval.Col).name=tmp;
        ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 474 "b.y"
    {
                sprintf(tmp,"%s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));
                (yyval.Col).name=tmp;    
        ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 482 "b.y"
    {(yyval.Col).name=(yyvsp[(1) - (1)].str);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 482 "b.y"
    {(yyval.Col).entier=(yyvsp[(1) - (1)].num);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 484 "b.y"
    {       sprintf(tmp,"%d", deb_for);
                quadr("BR",tmp,"vide","vide"); 
                sprintf(tmp2,"%d", qc);
                ajour_quad(save_bg,2,tmp2);
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 490 "b.y"
    {
        save_bg=qc;
        sprintf(tmp,"T%d", qc);
        if((yyvsp[(3) - (3)].Col).name==NULL){
                sprintf(tmp2,"%d", (yyvsp[(3) - (3)].Col).entier);
                quadr("BG","",(yyvsp[(1) - (3)].Col).name,tmp2);
        }else{
               
                quadr("BG","",(yyvsp[(1) - (3)].Col).name,(yyvsp[(3) - (3)].Col).name);
        }
    
        

;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 505 "b.y"
    {
        deb_for=qc;
        sprintf(res,"T%d", qc);
        sprintf(tmp,"%d", (yyvsp[(3) - (3)].num));
        quadr("+",tmp,(yyvsp[(1) - (3)].Col).name,res);
        strcpy((yyval.Col).name,res);
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 513 "b.y"
    {
     if((yyvsp[(1) - (3)].Col).type!=0){
        printf("Error Symantique:%s pas compatible la ligne [%d] et a la colonne [%d]\n",(yyvsp[(1) - (3)].Col).name,ligne,col);exit(-1);
     }else{
        sprintf(tmp,"%d",(yyvsp[(3) - (3)].num)); 
        quadr("=",tmp,"vide",(yyvsp[(1) - (3)].Col).name);
        strcpy((yyval.Col).name,(yyvsp[(1) - (3)].Col).name);
     } 
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 523 "b.y"
    {
        //printf("ddd%s",$3);
        //printf("dd%lu",th);
        p=lookup((yyvsp[(3) - (3)].str),th);
     
        if(p==NULL){
                printf("Error Symantique:%s non declareea la ligne [%d] et a la colonne [%d]\n",(yyvsp[(3) - (3)].str),ligne,col);exit(-1);
        }else{

                (yyval.Col).type=p->type;
                (yyval.Col).name=(yyvsp[(3) - (3)].str);
                //printf($$.name);
               
        }
        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 541 "b.y"
    {
        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);
        

        sprintf(tmp2,"%d",qc);
        finInst2=qc; 
        ajour_quad(deb_if,2,tmp2);
        
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 552 "b.y"
    {

        sprintf(tmp,"%d",qc); 
        ajour_quad(finInst1,2,tmp);

        sprintf(tmp2,"%d",qc);
        /*finInst2=qc; 
        ajour_quad(deb_if,2,tmp2);*/
        //quadr("FIN", "vide","vide","vide"); 

        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 565 "b.y"
    {     
        finInst1=qc; 
 
        sprintf(tmp,"%d",qc); // transformer entier vers string
        ajour_quad(deb_if,2,tmp);
        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 573 "b.y"
    {     
        finInst1=qc; 
        quadr("BR", "","vide","vide"); 
        sprintf(tmp,"%d",qc); 
        ajour_quad(deb_if,2,tmp);
        ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 580 "b.y"
    {
        
         deb_if=qc; 
        
         printf("D%s\n",(yyvsp[(3) - (4)].cod).cond2);
         quadr((yyvsp[(3) - (4)].cod).opera,"",(yyvsp[(3) - (4)].cod).cond1,(yyvsp[(3) - (4)].cod).cond2); 
        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 588 "b.y"
    {
         /*deb_if=qc; 
         quadr($2,"","temp_cond","vide"); */
         (yyval.cod).opera=(yyvsp[(3) - (5)].operCond);
        if((yyvsp[(2) - (5)].Col).name==""){
                if((yyvsp[(2) - (5)].Col).type==0){
                
                        sprintf(res,"%d", (yyvsp[(2) - (5)].Col).entier);  
                }else if((yyvsp[(2) - (5)].Col).type==1){
                        sprintf(res,"%.02f", (yyvsp[(2) - (5)].Col).reel);
                }
        }else{           
                (yyval.cod).cond1=(yyvsp[(2) - (5)].Col).name;
        }
        if((yyvsp[(4) - (5)].Col).name==""){
                if((yyvsp[(4) - (5)].Col).type==0){
                        sprintf((yyval.cod).cond2,"%d", (yyvsp[(4) - (5)].Col).entier);
                        
                }else if ((yyvsp[(4) - (5)].Col).type==1){
                        sprintf((yyval.cod).cond2,"%.02f", (yyvsp[(4) - (5)].Col).reel);
                        
                }else{
                        strcpy((yyval.cod).cond2,(yyvsp[(4) - (5)].Col).name);
                }
        }else{  
                
                (yyval.cod).cond2=(yyvsp[(4) - (5)].Col).name;
        } 
        printf("d");
         (yyval.cod).opera=(yyvsp[(3) - (5)].operCond);
         
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 620 "b.y"
    {
         /*deb_if=qc; 
         quadr($2,"","temp_cond","vide"); */
         (yyval.cod).opera=(yyvsp[(2) - (3)].operCond);
        if((yyvsp[(1) - (3)].Col).name==""){
                if((yyvsp[(1) - (3)].Col).type==0){
                
                        sprintf(res,"%d", (yyvsp[(1) - (3)].Col).entier);  
                }else if((yyvsp[(1) - (3)].Col).type==1){
                        sprintf(res,"%.02f", (yyvsp[(1) - (3)].Col).reel);
                }
        }else{           
                (yyval.cod).cond1=(yyvsp[(1) - (3)].Col).name;
        }
        if((yyvsp[(3) - (3)].Col).name==""){
                if((yyvsp[(3) - (3)].Col).type==0){
                        sprintf((yyval.cod).cond2,"%d", (yyvsp[(3) - (3)].Col).entier);
                        
                }else if ((yyvsp[(3) - (3)].Col).type==1){
                        sprintf((yyval.cod).cond2,"%.02f", (yyvsp[(3) - (3)].Col).reel);
                        
                }else{
                        strcpy((yyval.cod).cond2,(yyvsp[(3) - (3)].Col).name);
                }
        }else{  
                
                (yyval.cod).cond2=(yyvsp[(3) - (3)].Col).name;
        } 
        printf("d");
         (yyval.cod).opera=(yyvsp[(2) - (3)].operCond);
         
        ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 657 "b.y"
    { (yyval.operCond) = strdup("BLE"); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 658 "b.y"
    { (yyval.operCond) = strdup("BL"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 659 "b.y"
    { (yyval.operCond) = strdup("BNE"); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 660 "b.y"
    { (yyval.operCond) = strdup("BGE"); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 661 "b.y"
    { (yyval.operCond) = strdup("BG"); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 662 "b.y"
    { (yyval.operCond) = strdup("BE"); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 666 "b.y"
    {
       
        sprintf(tmp,"%d",deb_while);
        quadr("BR",tmp,"vide","vide");//qc sincrement dans le quadr
        sprintf(tmp2,"%d",qc);
        ajour_quad(save_bz,2,tmp2);
        //quadr("FIN","vide","vide","vide");
        ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 674 "b.y"
    {
           save_bz=qc;   
           quadr((yyvsp[(3) - (4)].cod).opera,"",(yyvsp[(3) - (4)].cod).cond1,(yyvsp[(3) - (4)].cod).cond2); 
        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 679 "b.y"
    {
        deb_while=qc;
     
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2406 "b.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
#line 683 "b.y"

int yyerror(char* msg)
{printf("%s ligne %d et colonne %d",msg,ligne,col);
return 0;
}
int main()  {  

yyparse();
//afficheidf(); 
//liste
affiche(lisElts); 
 
//afficher_table(th);
//Quadruple
affich_quad();
//qc=optimize_quads(quadruplets,qc);

 
//printf("\n-----optimiser------");
//affich_quad();
generateAssemblyCode(quadruplets,qc,"code.asm");
//yyin = fopen("test.txt", "r");
//fclose (yyin);
return 0;  
} 

