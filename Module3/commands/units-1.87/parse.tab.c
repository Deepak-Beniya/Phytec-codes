/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse unitsparse
#define yylex   unitslex
#define yyerror unitserror
#define yylval  unitslval
#define yychar  unitschar
#define yydebug unitsdebug
#define yynerrs unitsnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     REAL = 258,
     UNIT = 259,
     RFUNC = 260,
     UFUNC = 261,
     EXPONENT = 262,
     MULTIPLY = 263,
     MULTSTAR = 264,
     DIVIDE = 265,
     NUMDIV = 266,
     SQRT = 267,
     CUBEROOT = 268,
     MULTMINUS = 269,
     EOL = 270,
     FUNCINV = 271,
     SCANERROR = 272,
     MINUS = 273,
     ADD = 274,
     UNARY = 275
   };
#endif
/* Tokens.  */
#define REAL 258
#define UNIT 259
#define RFUNC 260
#define UFUNC 261
#define EXPONENT 262
#define MULTIPLY 263
#define MULTSTAR 264
#define DIVIDE 265
#define NUMDIV 266
#define SQRT 267
#define CUBEROOT 268
#define MULTMINUS 269
#define EOL 270
#define FUNCINV 271
#define SCANERROR 272
#define MINUS 273
#define ADD 274
#define UNARY 275




/* Copy the first part of user declarations.  */
#line 23 "parse.y"


#define YYPARSE_PARAM comm
#define YYLEX_PARAM comm

#define COMM ((struct commtype *)comm)

#include "units.h"


static int err;  /* value used by parser to store return values */

#define CHECK if (err) { COMM->errorcode=err; YYABORT; }


#define MEMSIZE 100
struct unittype *memtable[MEMSIZE];
int nextunit=0;
int maxunit=0;

struct commtype {
   int location;
   char *data;
   struct unittype *result;
   int errorcode;
   char *paramname;
   struct unittype *paramvalue;
};

struct function { 
   char *name; 
   double (*func)(double); 
   int type;
}; 

#define DIMENSIONLESS 0
#define ANGLEIN 1
#define ANGLEOUT 2

struct unittype *
getnewunit()
{
  if (nextunit>=MEMSIZE) 
    return 0;
  memtable[nextunit] = (struct unittype *) 
    mymalloc(sizeof(struct unittype),"(getnewunit)");
  if (!memtable[nextunit])
    return 0;
  initializeunit(memtable[nextunit]);
  return memtable[nextunit++];
}
 

struct unittype *
makenumunit(double num,int *myerr)
{
  struct unittype *ret;
  ret=getnewunit();
  if (!ret){
    *myerr = E_PARSEMEM;
    return 0;  
  }
  ret->factor = num;
  *myerr = 0;
  return ret;
}


double 
logb2(double x)
{
  return log(x)/log(2.0);
}


int
funcunit(struct unittype *theunit, struct function *fun)
{
  struct unittype angleunit;

  if (fun->type==ANGLEIN){
    err=unit2num(theunit);
    if (err==E_NOTANUMBER){
      initializeunit(&angleunit);
      angleunit.denominator[0] = dupstr("radian");
      angleunit.denominator[1] = 0;
      err = multunit(theunit, &angleunit);
      freeunit(&angleunit);
      if (!err)
	err = unit2num(theunit);
    }
    if (err)
      return err;
  } else if (fun->type==ANGLEOUT || fun->type == DIMENSIONLESS) {
    if (err=unit2num(theunit))
      return err;
    
  } else 
     return E_BADFUNCTYPE;
  errno = 0;
  theunit->factor = (*(fun->func))(theunit->factor);
  if (errno)
    return E_FUNC;
  if (fun->type==ANGLEOUT) {
    theunit->numerator[0] = dupstr("radian");
    theunit->numerator[1] = 0;
  }
  return 0;
}




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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 139 "parse.y"
{
  double number;
  int integer;
  struct unittype *utype;
  struct function *dfunc;
  struct func *ufunc;
}
/* Line 187 of yacc.c.  */
#line 265 "parse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 278 "parse.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNRULES -- Number of states.  */
#define YYNSTATES  55

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      21,    22,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    17,    20,
      23,    27,    31,    35,    39,    43,    45,    49,    53,    55,
      57,    61,    65,    68,    70,    73,    76,    79,    82,    86,
      91,    96
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      24,     0,    -1,    15,    -1,    25,    15,    -1,     1,    -1,
      26,    -1,    10,    29,    -1,    29,    -1,    14,    29,    -1,
      18,    29,    -1,    26,    19,    26,    -1,    26,    18,    26,
      -1,    26,    10,    26,    -1,    26,     8,    26,    -1,    26,
       9,    26,    -1,     3,    -1,    27,    11,    27,    -1,    21,
      26,    22,    -1,    27,    -1,     4,    -1,    29,     7,    29,
      -1,    29,    14,    29,    -1,    29,    29,    -1,    28,    -1,
      12,    28,    -1,    13,    28,    -1,     5,    28,    -1,     6,
      28,    -1,    16,     6,    28,    -1,    29,     7,    14,    29,
      -1,    29,     7,    18,    29,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   181,   181,   182,   183,   186,   187,   190,   191,   192,
     193,   194,   196,   197,   198,   201,   202,   205,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     225,   228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "REAL", "UNIT", "RFUNC", "UFUNC",
  "EXPONENT", "MULTIPLY", "MULTSTAR", "DIVIDE", "NUMDIV", "SQRT",
  "CUBEROOT", "MULTMINUS", "EOL", "FUNCINV", "SCANERROR", "MINUS", "ADD",
  "UNARY", "'('", "')'", "$accept", "input", "unitexpr", "expr", "numexpr",
  "pexpr", "list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    24,    24,    24,    25,    25,    26,    26,    26,
      26,    26,    26,    26,    26,    27,    27,    28,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     2,     2,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     2,     1,     2,     2,     2,     2,     3,     4,
       4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,    15,    19,     0,     0,     0,     0,     0,     0,
       2,     0,    31,     0,     0,     0,     0,     5,    18,    23,
       7,    26,    27,     6,    24,    25,     8,     0,     9,     0,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    28,    17,    13,    14,    12,    11,    10,    16,     0,
       0,    20,    21,    29,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -19
static const yytype_int16 yypact[] =
{
      41,   -19,   -19,   -19,   -18,   -18,   136,   -18,   -18,   136,
     -19,    12,   -19,   136,    60,     8,     4,     2,    11,   -19,
      79,   -19,   -19,    79,   -19,   -19,    79,   -18,    79,   137,
     -19,   -19,    60,    60,    60,    60,    60,    20,    98,   136,
     117,   -19,   -19,   -19,    22,    22,     7,     7,   -19,   136,
     136,    24,   117,    24,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,   -19,    -7,     3,    -3,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    21,    22,    14,    24,    25,    23,    29,    30,    26,
      32,    33,    34,    28,    20,    32,    33,    34,    27,    31,
      35,    36,    37,     2,    41,    43,    44,    45,    46,    47,
      32,    38,    20,    20,    20,    20,    20,     0,    51,    52,
      48,     0,     1,     0,     2,     3,     4,     5,     0,    53,
      54,     6,     0,     7,     8,     9,    10,    11,    12,    13,
       0,     0,    14,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     7,     8,     9,     0,    11,    12,    13,     0,
       0,    14,     2,     3,     4,     5,    38,     0,     0,     0,
       0,     7,     8,    39,     0,    11,    12,     0,     0,     0,
      14,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       7,     8,    49,     0,    11,    12,    50,     0,     0,    14,
       2,     3,     4,     5,    38,     0,     0,     0,     0,     7,
       8,     0,     0,    11,    12,     0,     0,     0,    14,     2,
       3,     4,     5,     0,     0,    32,    33,    34,     7,     8,
       0,     0,    11,    12,     0,    35,    36,    14,     0,    42
};

static const yytype_int8 yycheck[] =
{
       0,     4,     5,    21,     7,     8,     6,    14,     0,     9,
       8,     9,    10,    13,    14,     8,     9,    10,     6,    15,
      18,    19,    11,     3,    27,    32,    33,    34,    35,    36,
       8,     7,    32,    33,    34,    35,    36,    -1,    38,    39,
      37,    -1,     1,    -1,     3,     4,     5,     6,    -1,    49,
      50,    10,    -1,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      -1,    21,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      21,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    18,    -1,    -1,    21,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    16,    17,    -1,    -1,    -1,    21,     3,
       4,     5,     6,    -1,    -1,     8,     9,    10,    12,    13,
      -1,    -1,    16,    17,    -1,    18,    19,    21,    -1,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    10,    12,    13,    14,
      15,    16,    17,    18,    21,    24,    25,    26,    27,    28,
      29,    28,    28,    29,    28,    28,    29,     6,    29,    26,
       0,    15,     8,     9,    10,    18,    19,    11,     7,    14,
      29,    28,    22,    26,    26,    26,    26,    26,    27,    14,
      18,    29,    29,    29,    29
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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






/*----------.
| yyparse.  |
`----------*/

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 181 "parse.y"
    { COMM->result = makenumunit(1,&err); CHECK; YYACCEPT; ;}
    break;

  case 3:
#line 182 "parse.y"
    { COMM->result = (yyvsp[(1) - (2)].utype); YYACCEPT; ;}
    break;

  case 4:
#line 183 "parse.y"
    { YYABORT; ;}
    break;

  case 5:
#line 186 "parse.y"
    {(yyval.utype) = (yyvsp[(1) - (1)].utype);;}
    break;

  case 6:
#line 187 "parse.y"
    { invertunit((yyvsp[(2) - (2)].utype)); (yyval.utype)=(yyvsp[(2) - (2)].utype);;}
    break;

  case 7:
#line 190 "parse.y"
    { (yyval.utype) = (yyvsp[(1) - (1)].utype); ;}
    break;

  case 8:
#line 191 "parse.y"
    { (yyval.utype) = (yyvsp[(2) - (2)].utype); (yyval.utype)->factor *= -1; ;}
    break;

  case 9:
#line 192 "parse.y"
    { (yyval.utype) = (yyvsp[(2) - (2)].utype); (yyval.utype)->factor *= -1; ;}
    break;

  case 10:
#line 193 "parse.y"
    { err = addunit((yyvsp[(1) - (3)].utype),(yyvsp[(3) - (3)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 11:
#line 194 "parse.y"
    { (yyvsp[(3) - (3)].utype)->factor *= -1; err = addunit((yyvsp[(1) - (3)].utype),(yyvsp[(3) - (3)].utype)); 
                                         CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 12:
#line 196 "parse.y"
    { err = divunit((yyvsp[(1) - (3)].utype), (yyvsp[(3) - (3)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 13:
#line 197 "parse.y"
    { err = multunit((yyvsp[(1) - (3)].utype),(yyvsp[(3) - (3)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 14:
#line 198 "parse.y"
    { err = multunit((yyvsp[(1) - (3)].utype),(yyvsp[(3) - (3)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 15:
#line 201 "parse.y"
    { (yyval.number) = (yyvsp[(1) - (1)].number);         ;}
    break;

  case 16:
#line 202 "parse.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) / (yyvsp[(3) - (3)].number);    ;}
    break;

  case 17:
#line 205 "parse.y"
    { (yyval.utype) = (yyvsp[(2) - (3)].utype);  ;}
    break;

  case 18:
#line 211 "parse.y"
    { (yyval.utype) = makenumunit((yyvsp[(1) - (1)].number),&err); CHECK;;}
    break;

  case 19:
#line 212 "parse.y"
    { (yyval.utype) = (yyvsp[(1) - (1)].utype); ;}
    break;

  case 20:
#line 213 "parse.y"
    { err = unitpower((yyvsp[(1) - (3)].utype),(yyvsp[(3) - (3)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 21:
#line 214 "parse.y"
    { err = multunit((yyvsp[(1) - (3)].utype),(yyvsp[(3) - (3)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (3)].utype);;}
    break;

  case 22:
#line 215 "parse.y"
    { err = multunit((yyvsp[(1) - (2)].utype),(yyvsp[(2) - (2)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (2)].utype);;}
    break;

  case 23:
#line 216 "parse.y"
    { (yyval.utype)=(yyvsp[(1) - (1)].utype); ;}
    break;

  case 24:
#line 217 "parse.y"
    { err = rootunit((yyvsp[(2) - (2)].utype),2); CHECK; (yyval.utype)=(yyvsp[(2) - (2)].utype);;}
    break;

  case 25:
#line 218 "parse.y"
    { err = rootunit((yyvsp[(2) - (2)].utype),3); CHECK; (yyval.utype)=(yyvsp[(2) - (2)].utype);;}
    break;

  case 26:
#line 219 "parse.y"
    { err = funcunit((yyvsp[(2) - (2)].utype),(yyvsp[(1) - (2)].dfunc)); CHECK; (yyval.utype)=(yyvsp[(2) - (2)].utype);;}
    break;

  case 27:
#line 220 "parse.y"
    { err = evalfunc((yyvsp[(2) - (2)].utype),(yyvsp[(1) - (2)].ufunc),0); CHECK; (yyval.utype)=(yyvsp[(2) - (2)].utype);;}
    break;

  case 28:
#line 221 "parse.y"
    { err = evalfunc((yyvsp[(3) - (3)].utype),(yyvsp[(2) - (3)].ufunc),1); CHECK; (yyval.utype)=(yyvsp[(3) - (3)].utype);;}
    break;

  case 29:
#line 223 "parse.y"
    { (yyvsp[(4) - (4)].utype)->factor *= -1;
				   err = unitpower((yyvsp[(1) - (4)].utype),(yyvsp[(4) - (4)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (4)].utype);;}
    break;

  case 30:
#line 226 "parse.y"
    { (yyvsp[(4) - (4)].utype)->factor *= -1;
				   err = unitpower((yyvsp[(1) - (4)].utype),(yyvsp[(4) - (4)].utype)); CHECK; (yyval.utype)=(yyvsp[(1) - (4)].utype);;}
    break;

  case 31:
#line 228 "parse.y"
    { err = E_PARSEMEM; CHECK; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1683 "parse.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 234 "parse.y"


#ifndef strchr
#  ifdef NO_STRCHR
#    define strchr(a,b) index((a),(b))
#  else
     char *strchr();
#  endif
#endif /* !strchr */

double strtod();


struct function 
  realfunctions[] = { "sin", sin,    ANGLEIN,
                      "cos", cos,    ANGLEIN,
                      "tan", tan,    ANGLEIN,
                      "ln", log,     DIMENSIONLESS,
                      "log", log10,  DIMENSIONLESS,
                      "log2", logb2, DIMENSIONLESS,
                      "exp", exp,    DIMENSIONLESS,
                      "acos", acos,  ANGLEOUT,
                      "atan", atan,  ANGLEOUT,
                      "asin", asin,  ANGLEOUT,
                      0, 0, 0};

struct {
  char op;
  int value;
} optable[] = { '*', MULTIPLY,
            	'/', DIVIDE, 
            	'|', NUMDIV, 
            	'+', ADD, 
            	'(', '(', 
            	')', ')', 
            	'^', EXPONENT, 
                '~', FUNCINV,
            	0, 0 };

struct {
  char *name;
  int value;
} strtable[] = { "sqrt", SQRT, 
                 "cuberoot", CUBEROOT, 
                 "per" , DIVIDE, 
                 0, 0 };

yylex(YYSTYPE *lvalp, struct commtype *comm)
{
  int length, count;
  struct unittype *output;
  char *inptr;

  char *nonunitchars = "+-*/|\t\n^ ()";
  
  if (comm->location==-1) return 0;
  inptr = comm->data + comm->location;   /* Point to start of data */

  /* Skip white space */
  while( *inptr && strchr(WHITE,*inptr)) inptr++, comm->location++;

  if (*inptr==0) {
    comm->location = -1;
    return EOL;  /* Return failure if string has ended */
  }  

  /* Check for **, an exponent operator.  */

  if (0==strncmp("**",inptr,2)){
    comm->location += 2;
    return EXPONENT;
  }

  /* Check for '-' and '*' which get special handling */
 
  if (*inptr=='-'){
    comm->location++;
    if (minusminus)
      return MINUS;
    return MULTMINUS;
  }      


  if (*inptr=='*'){
    comm->location++;
    if (oldstar)
      return MULTIPLY;
    return MULTSTAR;
  }      


  /* Look for single character ops */

  for(count=0; optable[count].op; count++){
    if (*inptr==optable[count].op) {
       comm->location++;
       return optable[count].value;
    }
  }

  /* Look for numbers */

  if (strchr(".0123456789",*inptr)){  /* prevent "nan" from being recognized */
    char *endloc;
    lvalp->number = strtod(inptr, &endloc);
    if (inptr != endloc) { 
      comm->location += (endloc-inptr);
      return REAL;
    }
  }

  /* Look for a word (function name or unit name) */

  length = strcspn(inptr,nonunitchars);   

  if (!length){  /* This shouldn't happen */
     return 0;
  }

  /* Look for string operators */

  for(count=0;strtable[count].name;count++){
     if (length==strlen(strtable[count].name) && 
	 0==strncmp(strtable[count].name,inptr,length)){
       comm->location += length;
       return strtable[count].value;
     }
  }
  
  /* Look for real function names */

  for(count=0;realfunctions[count].name;count++){
     if (length==strlen(realfunctions[count].name) && 
	 0==strncmp(realfunctions[count].name,inptr,length)){
       lvalp->dfunc = realfunctions+count;
       comm->location += length;
       return RFUNC;
     }
  }

  /* Look for function parameter */

  if (function_parameter && length==strlen(function_parameter) && 
      0==strncmp(function_parameter, inptr, length)){
      output = getnewunit();
      if (!output)
	return SCANERROR;
      unitcopy(output, parameter_value);
      lvalp->utype = output;
      comm->location += length;
      return UNIT;
  } 

  /* Look for user defined function */

  lvalp->ufunc = fnlookup(inptr,length);
  if (lvalp->ufunc){
    comm->location += length;
    return UFUNC;
  }

  /* Didn't find a special string, so treat it as unit name */

  comm->location+=length;
  if (strchr("23456789",inptr[length-1])) {  /* do exponent handling like m3 */
     count = inptr[length-1] - '0';
     length--;
  } else count=1;

  output = getnewunit();
  if (!output)
    return SCANERROR;
  output->numerator[count]=0;
  for(;count;count--){
    output->numerator[count-1] = mymalloc(length+1,"(yylex)");
    strncpy(output->numerator[count-1], inptr, length);
    output->numerator[count-1][length]=0;
  }
  lvalp->utype=output;
  return UNIT;
}


yyerror(char *s){}

void
freelist(int startunit)
{
  if (nextunit>maxunit) 
    maxunit = nextunit;
  while(nextunit>startunit){
    freeunit(memtable[--nextunit]);
    free(memtable[nextunit]);
  }
}


int
parseunit(struct unittype *output, char *input,char **errstr,int *errloc)
{
  struct commtype comm;
  int startunit;

  startunit = nextunit;
  initializeunit(output);
  comm.location = 0;
  comm.data = input;
  comm.errorcode = E_PARSE;    /* Assume parse error */
  if (yyparse(&comm)){
    if (comm.location==-1) 
      comm.location = strlen(input);
    if (errstr){
      if (smarterror && comm.errorcode==E_FUNC)
	*errstr = strerror(errno);
      else
        *errstr=errormsg[comm.errorcode];
    }
    if (errloc)
      *errloc = comm.location;
    freelist(startunit);
    return comm.errorcode;
  } else {
    if (errstr)
      *errstr = 0;
    multunit(output,comm.result);
    freeunit(comm.result);
    freelist(startunit);
    return 0;
  }
}



