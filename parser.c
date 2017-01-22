/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include "global.h"
	using namespace std;

	//lista zmiennych którym później będzie przydzielony typ podczas deklaracji | lista argumentów funkcji write, ride
	vector<int> argsVector;

	void yyerror(char const* s);

	//zakres tablicy ma start i stop
	arrayRange array_range;

	//zmienna pomocnicza dla array do przekazania typu po deklaracji
	int helpVarArray;

	//początek offsetu parametrów fun/proc 8 dla proc 12 dla fun
	int funcProcParmOffset=8;

	//lista na parametry funkcji
	list<pair<int, arrayRange> > parameters;

	//LISTA DO OBLICZANIA INCSP
	list<int> funParams;

#line 91 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    BEGINN = 259,
    END = 260,
    VAR = 261,
    INTEGER = 262,
    REAL = 263,
    ARRAY = 264,
    OF = 265,
    FUN = 266,
    PROC = 267,
    IF = 268,
    THEN = 269,
    ELSE = 270,
    DO = 271,
    WHILE = 272,
    RELOP = 273,
    MULOP = 274,
    SIGN = 275,
    ASSIGN = 276,
    OR = 277,
    NOT = 278,
    ID = 279,
    NUM = 280,
    NONE = 281,
    DONE = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,    32,     2,    31,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    30,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    65,    57,    73,    74,    78,    87,    99,
     124,   128,   129,   142,   143,   147,   148,   152,   166,   177,
     182,   165,   190,   202,   189,   209,   220,   224,   251,   277,
     281,   282,   285,   286,   290,   294,   295,   297,   305,   296,
     316,   325,   315,   337,   345,   384,   405,   503,   507,   514,
     518,   543,   544,   555,   561,   569,   570,   579,   600,   672,
     673,   677,   701
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BEGINN", "END", "VAR",
  "INTEGER", "REAL", "ARRAY", "OF", "FUN", "PROC", "IF", "THEN", "ELSE",
  "DO", "WHILE", "RELOP", "MULOP", "SIGN", "ASSIGN", "OR", "NOT", "ID",
  "NUM", "NONE", "DONE", "'('", "')'", "';'", "'.'", "','", "':'", "'['",
  "']'", "$accept", "program", "$@1", "$@2", "start_identifiers",
  "identifier_list", "declarations", "type", "standard_type",
  "subprogram_declarations", "subprogram_declaration", "subprogram_head",
  "$@3", "$@4", "$@5", "$@6", "$@7", "arguments", "parameter_list",
  "compound_statement", "optional_statement", "statement_list",
  "statement", "$@8", "$@9", "@10", "$@11", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", "eof", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    40,    41,
      59,    46,    44,    58,    91,    93
};
# endif

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,    -7,    25,     3,   -94,    14,   -94,     0,    17,    30,
     -94,   -94,    68,    60,    58,   -94,    40,    62,    63,    81,
      59,   -94,    64,    55,   -94,   -94,     2,    65,   -94,    61,
     -94,   -94,   -94,    57,    67,   -94,    66,    66,    21,   -94,
     -10,   -94,    87,    69,   -94,    72,   -94,   -94,   -94,    70,
     -94,    60,   -94,   -94,    28,    28,   -14,   -94,    21,   -94,
     -94,    37,    79,   -94,    21,    21,    21,   -94,     2,    21,
      74,    71,    44,    49,    75,    76,    79,   -94,    21,    78,
      89,    21,    28,    28,    28,    88,    11,   -94,   -13,   -94,
      46,   -94,   -94,    80,    55,   -94,    60,    73,   -94,    29,
     -94,     2,    46,    79,    79,   -94,   -94,   -94,    21,   -94,
      84,   -94,    50,   -94,   -94,   -94,     2,   -94,    77,    55,
      83,    90,   -94,   100,   -94,   -94,     2,    73,   -94,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     5,     0,     0,     0,
      10,     6,    16,     0,     2,     7,     0,     0,     0,     0,
       0,    10,     0,     0,    18,    22,    31,     0,    15,     0,
       8,    13,    14,     0,     0,    11,    26,    26,     0,    40,
      45,    36,     0,    30,    32,     0,    35,     3,    17,     0,
       9,     0,    19,    23,     0,     0,    43,    59,     0,    57,
      37,    49,    51,    55,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     0,    33,
      34,    62,     4,     0,     0,    25,     0,     0,    24,     0,
      60,     0,    50,    53,    54,    56,    41,    46,     0,    44,
       0,    27,     0,    20,    58,    38,     0,    48,     0,     0,
       0,     0,    42,     0,    28,    21,     0,     0,    39,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -48,    93,   -89,   -93,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,    82,   -94,     4,
     -94,   -94,   -66,   -94,   -94,   -94,   -94,   -26,   -94,    38,
     -37,   -53,   -46,   -45,   -94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    19,    70,     7,    16,    12,    34,    35,    14,
      20,    21,    36,    74,   120,    37,    75,    52,    73,    41,
      42,    43,    44,    80,   121,    64,   116,    59,    46,    86,
      87,    61,    62,    63,    92
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    60,    89,    72,   113,   111,    26,    82,    76,    83,
      77,   -43,     1,    88,    78,    38,    90,     3,    65,    39,
      66,    79,   109,    27,    66,     4,    40,    85,   102,     8,
     124,     5,     9,    48,   129,   115,   103,   104,     6,   105,
     107,    54,    45,   108,    55,    56,    57,    10,   112,    58,
     122,    55,    56,    57,    11,    81,    58,    82,   114,    83,
     128,   108,    31,    32,    33,    26,    82,    13,    83,    17,
      18,   117,    22,    23,    13,    45,    22,    94,    95,    96,
      31,    32,    22,   119,    15,    26,    24,    25,    30,    28,
      45,    49,    67,    69,    51,    71,    47,    50,    84,    68,
      45,    91,    93,   101,   106,   126,    98,   100,    97,   118,
     127,   110,   123,   125,    29,     0,    99,     0,     0,    53
};

static const yytype_int8 yycheck[] =
{
      26,    38,    68,    51,    97,    94,     4,    20,    54,    22,
      55,    21,     3,    66,    28,    13,    69,    24,    28,    17,
      34,    58,    35,    19,    34,     0,    24,    64,    81,    29,
     119,    28,    32,    29,   127,   101,    82,    83,    24,    84,
      29,    20,    68,    32,    23,    24,    25,    30,    96,    28,
     116,    23,    24,    25,    24,    18,    28,    20,    29,    22,
     126,    32,     7,     8,     9,     4,    20,     6,    22,    11,
      12,   108,    32,    33,     6,   101,    32,    33,    29,    30,
       7,     8,    32,    33,    24,     4,    24,    24,    24,    30,
     116,    34,     5,    21,    28,    25,    31,    30,    19,    30,
     126,    27,    31,    14,    16,    15,    30,    29,    33,    25,
      10,    31,    35,    30,    21,    -1,    78,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    37,    24,     0,    28,    24,    40,    29,    32,
      30,    24,    42,     6,    45,    24,    41,    11,    12,    38,
      46,    47,    32,    33,    24,    24,     4,    55,    30,    42,
      24,     7,     8,     9,    43,    44,    48,    51,    13,    17,
      24,    55,    56,    57,    58,    63,    64,    31,    55,    34,
      30,    28,    53,    53,    20,    23,    24,    25,    28,    63,
      66,    67,    68,    69,    61,    28,    34,     5,    30,    21,
      39,    25,    41,    54,    49,    52,    68,    69,    28,    66,
      59,    18,    20,    22,    19,    66,    65,    66,    67,    58,
      67,    27,    70,    31,    33,    29,    30,    33,    30,    65,
      29,    14,    67,    68,    68,    69,    16,    29,    32,    35,
      31,    43,    41,    44,    29,    58,    62,    66,    25,    33,
      50,    60,    58,    35,    43,    30,    15,    10,    58,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    38,    39,    37,    40,    40,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    46,    48,    49,
      50,    47,    51,    52,    47,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    59,    60,    58,
      61,    62,    58,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    13,     1,     3,     1,     3,     6,
       0,     1,     9,     1,     1,     3,     0,     3,     0,     0,
       0,     9,     0,     0,     6,     3,     0,     3,     5,     3,
       1,     0,     1,     3,     3,     1,     1,     0,     0,     8,
       0,     0,     6,     1,     4,     1,     4,     1,     3,     1,
       3,     1,     2,     3,     3,     1,     3,     1,     4,     1,
       3,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 60 "parser.y" /* yacc.c:1646  */
    {
				writeToOutput("\nlab0:");
			}
#line 1335 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "parser.y" /* yacc.c:1646  */
    {
				writeToOutput("\n\texit\n");
				writeAllToFile();
			}
#line 1344 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "parser.y" /* yacc.c:1646  */
    {
				int ii = (yyvsp[0]);
				if(ii == -1) //-1 bo parser,WRZUĆ DO argsVector ID ustawił jak już było w ST
				{
					YYERROR;
				}
				argsVector.push_back(ii);
			}
#line 1357 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "parser.y" /* yacc.c:1646  */
    {
				int ii = (yyvsp[0]);
				if(ii == -1)
				{
					YYERROR;
				}
				argsVector.push_back(ii);
			}
#line 1370 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 100 "parser.y" /* yacc.c:1646  */
    {
			//ustawiamy typ i obliczamy offset(adres)
			for(int i = 0; i<argsVector.size(); i++)
			{
				if((yyvsp[-1]) == INTEGER || (yyvsp[-1]) == REAL)
				{
					SymbolTable[argsVector[i]].token = VAR;
					SymbolTable[argsVector[i]].type = (yyvsp[-1]);
					SymbolTable[argsVector[i]].address = generateNewVariablePosition(SymbolTable[argsVector[i]].name);
				}
				else if((yyvsp[-1]) == ARRAY) // dla tablic zapisz również dodatkowe dane
				{
					SymbolTable[argsVector[i]].type = helpVarArray;
					SymbolTable[argsVector[i]].token = (yyvsp[-1]);
					SymbolTable[argsVector[i]].array = array_range;		// struktura zawierająca indeks początkowy i końcowy array
					SymbolTable[argsVector[i]].address = generateNewVariablePosition(SymbolTable[argsVector[i]].name);
				}
				else
				{
					yyerror("Nieznany typ.");YYERROR;
				}
			}
			argsVector.clear(); // wyczyść listę indeksów napotkanych ID
		}
#line 1399 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 130 "parser.y" /* yacc.c:1646  */
    {
				(yyval) = ARRAY;
				helpVarArray = (yyvsp[0]);
				array_range.start = (yyvsp[-6]);
				array_range.argType = (yyvsp[0]);
				array_range.stop = (yyvsp[-3]);
				array_range.startVal = atoi(SymbolTable[(yyvsp[-6])].name.c_str());
				array_range.stopVal = atoi(SymbolTable[(yyvsp[-3])].name.c_str());
			}
#line 1413 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "parser.y" /* yacc.c:1646  */
    {
				//koniec proc/func
				writeToOutput("\n\tleave");
				writeToOutputByToken(_RETURN,-1,true,-1,true,-1,true);
				printSymTable();
				clearLocalVariables();
				isGlobal = true;			//bo już po funkcji..
				funcProcParmOffset = 8; 	//resetuje
			}
#line 1427 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "parser.y" /* yacc.c:1646  */
    {	//WYPISZ LABEL FUNKCJI OFFSET NA 12, ZMIANA NA LOCAL
				int ii = (yyvsp[0]);
				if((yyvsp[0]) == -1){
					YYERROR;
				}
				SymbolTable[ii].token = FUN;
				isGlobal = false;
				writeToOutputByToken(FUN, ii ,true ,-1 ,true ,-1 ,true);//wypisuje label funkcji
				funcProcParmOffset = 12; //wartość zwracana pod +8 pod +12 parms
			}
#line 1442 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 177 "parser.y" /* yacc.c:1646  */
    {	//PRZYPISZ PARAMETRY DO ST.PARMS Z PARAMETERS
				SymbolTable[(yyvsp[-2])].parameters=parameters; //info o argumentach
				parameters.clear();
			}
#line 1451 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 182 "parser.y" /* yacc.c:1646  */
    {	//ZRÓB MIEJSCE NA WARTOŚĆ ZWRACANĄ
				SymbolTable[(yyvsp[-5])].type = (yyvsp[0]);//return type
				int returnVarible = insert(SymbolTable[(yyvsp[-5])].name.c_str() ,VAR ,(yyvsp[0])); 	//zmienna na wartosc zwracana
				SymbolTable[returnVarible].isReference = true;				  			// referencja
				SymbolTable[returnVarible].address = 8;									// wartość zwracana pod offsetem +8
			}
#line 1462 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 190 "parser.y" /* yacc.c:1646  */
    { 	//OFFSET NA 8 ZMIANA NA LOCAL
				int ii = (yyvsp[0]);
				if(ii == -1)
				{
					YYERROR;
				}
				SymbolTable[ii].token=PROC;
				isGlobal=false;
				writeToOutputByToken(PROC ,ii ,true ,-1 ,true ,-1 ,true);	// wygeneruj początek procedury
				funcProcParmOffset = 8;				 				// pierwszy (jeśli wystąpi) parametr będzie pod offsetem +8
			}
#line 1478 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 202 "parser.y" /* yacc.c:1646  */
    {	//PRZYPISZ PARAMETRY DO ST.PARMS Z PARAMETERS
				SymbolTable[(yyvsp[-2])].parameters = parameters;
				parameters.clear();
			}
#line 1487 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 210 "parser.y" /* yacc.c:1646  */
    { //USTAW OFFSETY DLA PARAMETRÓW +4...
				//lista parametrów w funkcji nadaj im kolejne offsety
				//iteruj po każdym parametrze
				for(list<int>::iterator it = funParams.begin(); it != funParams.end(); it++)
				{
					SymbolTable[*it].address = funcProcParmOffset;
					funcProcParmOffset += 4;
				}
				funParams.clear(); // wyczyść listę przechowujacą parametry
			}
#line 1502 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 225 "parser.y" /* yacc.c:1646  */
    {	//WRZUCA Z argsVector DO PARAMETERS(ABY PRZEKAZAĆ DO ST DO TEGO ID) I FUNpARMS(DO LICZENIA OFFSETÓW)
				int refType = (yyvsp[0]);
				//przelatuje przez każdy argument funkcji
				//ustawia referencje
				//ustawia typ
				//wrzuca do funParams (dzieki temu później będą policzone offsety)
				//wrzuca do parameters
				for(int i = 0; i<argsVector.size(); i++){
					// oznacz jako referencję, ustaw typ oraz adres
					SymbolTable[argsVector[i]].isReference=true;
					if(refType == ARRAY)
					{
						/*printf("\nccc--- %d --- %d\n", SymbolTable[argsVector[i]].type, refType );*/
						SymbolTable[argsVector[i]].token = ARRAY;
						SymbolTable[argsVector[i]].type = helpVarArray;
						SymbolTable[argsVector[i]].array = array_range;
					}
					else
					{
						SymbolTable[argsVector[i]].type = refType;
					}
					parameters.push_back(make_pair(refType, array_range));	// dodaj do listy argumentów
					funParams.push_front(argsVector[i]);					// lista po której będą nadawane adresy
				}
				argsVector.clear();
			}
#line 1533 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 252 "parser.y" /* yacc.c:1646  */
    {
				//to co wyżej
				int refType = (yyvsp[0]);
				for(int i = 0;i<argsVector.size();i++)
				{
					// oznacz jako referencję, ustaw typ oraz adres
					SymbolTable[argsVector[i]].isReference = true;
					if(refType == ARRAY)
					{
						SymbolTable[argsVector[i]].token = ARRAY;
						SymbolTable[argsVector[i]].type = helpVarArray;
						SymbolTable[argsVector[i]].array = array_range;
					}
					else
					{
						 SymbolTable[argsVector[i]].type = refType;
					}
					parameters.push_back(make_pair(refType, array_range));	// dodaj do listy argumentów
					funParams.push_front(argsVector[i]);			// lista po której będą nadawane adresy
				}
				argsVector.clear();
			}
#line 1560 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 291 "parser.y" /* yacc.c:1646  */
    {
				writeToOutputByToken(ASSIGN,(yyvsp[-2]),true,-1, true,(yyvsp[0]),true);
			}
#line 1568 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 297 "parser.y" /* yacc.c:1646  */
    {	//ZRÓB LABEL $2 SPRAWDŹ CZY expression == 0 JAK NIE SKACZ
				int firstLabel = createLabel();//tworzymy label dla jumpa
				int newNumInST = insertNumIfNE("0",INTEGER);
				//jump dla niespełnionego warunku (expression=0), czy $2(expression) jest równe newNumInST czyli(0)
				writeToOutputByToken(_EQ, firstLabel, true, (yyvsp[0]), true, newNumInST, true);
				(yyvsp[0]) = firstLabel;
			}
#line 1580 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 305 "parser.y" /* yacc.c:1646  */
    {	//RÓB LABEL2 $5 RÓB JUMPA DO $5, RÓB LABEL $2
				int secondLabel = createLabel();
				(yyvsp[0]) = secondLabel;
				writeToOutputByToken(_JUMP, secondLabel, true, -1, true, -1, true);
				writeToOutputByToken(_LABEL, (yyvsp[-3]), true, -1, true, -1, true);
			}
#line 1591 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 312 "parser.y" /* yacc.c:1646  */
    {	//RÓB LABEL $5
				writeToOutputByToken(_LABEL, (yyvsp[-3]), true, -1, true, -1, true);
			}
#line 1599 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 316 "parser.y" /* yacc.c:1646  */
    {	//RÓB START $1 I STOP SS->$2 LABEL, WYPISZ STARTLABEL
				int stopLabel = createLabel();
				int startLabel = createLabel();
				(yyvsp[0]) = startLabel;
				//Wstawia nowy token pod $2, kolejne poniżej będą przesunięte $2 --> $3
				(yyval) = stopLabel;
				writeToOutputByToken(_LABEL, startLabel, true, -1, true, -1, true);
			}
#line 1612 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 325 "parser.y" /* yacc.c:1646  */
    {	//JAK WARUNEK NIE SPEŁNIONY UCIEKAJ DO STOP
				int v = insertNumIfNE("0",INTEGER);
				writeToOutputByToken(_EQ, (yyvsp[-2]), true, (yyvsp[-1]), true, v, true);
			}
#line 1621 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 330 "parser.y" /* yacc.c:1646  */
    {	//RÓB JUMP DO START I LABEL STOPU
				writeToOutputByToken(_JUMP, (yyvsp[-5]), true, -1, true, -1, true);
				writeToOutputByToken(_LABEL, (yyvsp[-4]), true, -1, true, -1, true);
			}
#line 1630 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 338 "parser.y" /* yacc.c:1646  */
    {	//ZWRÓĆ ID
				int z = (yyvsp[0]);
				if(z == -1) {
					yyerror("Niezadeklarowana zmienna!"); YYERROR;
				}
				(yyval) = z;
			}
#line 1642 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 346 "parser.y" /* yacc.c:1646  */
    {	//JAK SIMPLE_EXP REAL TO ZMIEŃ NA INT, ODEJMIJ OD INDEKSU INDEX STARTOWY(WYPISZ MINUS) MNOŻENIE INDEKSU RAZY TYP OCZLICZENIE ADRESU ELEMENTU W NOWEJ ZMIENNEJ, ZMIANA NA REF
				//jak real zmien na int
				int index = (yyvsp[-1]);
				if(SymbolTable[index].type==REAL)
				{
					int convertedVal = createAdditionalVariable(INTEGER);
					writeToOutputByToken(_REALTOINT, convertedVal, true, index, true, -1, true);
					index=convertedVal;
				}
				// wyciagnij indeks array w tablicy symboli i jej poczatkowy indeks
				int arrayId = (yyvsp[-3]);
				int startIndex = SymbolTable[arrayId].array.start;
				int realIndex = createAdditionalVariable(INTEGER); 								//zmienna na index startowy rzeczywisty
				writeToOutputByToken(_MINUS, realIndex, true, index, true, startIndex, true);	// odejmij od indeksu indeks poczatkowy
				//dodaj numy jak nie ma
				int arrayElementSize=0;
				if(SymbolTable[arrayId].type==INTEGER)
				{
					arrayElementSize = insertNumIfNE("4",INTEGER);

				}
				else if(SymbolTable[arrayId].type==REAL)
				{
					arrayElementSize = insertNumIfNE("8",INTEGER);
				}
				//element * pozycja
				writeToOutputByToken(_MUL, realIndex, true, realIndex, true, arrayElementSize, true);
				int varWithAddresOfArrayElement = createAdditionalVariable(INTEGER);
				//adres początku tablicy + adres elementu w tablicy i mamy w efekcie adres z wartością w tablicy
				writeToOutputByToken(_PLUS, varWithAddresOfArrayElement, true, arrayId, false, realIndex, true);
				//ustaw, że jest to adres referentychny bo nie wskazuje na wartość lecz na wskaźnik pod którym jest wartość adresu, ustawienei typu na int/real
				SymbolTable[varWithAddresOfArrayElement].isReference=true;
				SymbolTable[varWithAddresOfArrayElement].type=SymbolTable[arrayId].type;
				(yyval)=varWithAddresOfArrayElement;
			}
#line 1682 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 385 "parser.y" /* yacc.c:1646  */
    {	// wywołanie func/proc np aaa;WYWOŁANIE BEZ PARAMETRÓW GENERUJ CALL #SSS
				int procF = (yyvsp[0]);
				if(procF==-1){
					yyerror("Użycie niezadeklarowanej nazwy.");
					YYERROR;
				}
				if(SymbolTable[procF].token == FUN || SymbolTable[procF].token==PROC){
					if(SymbolTable[procF].parameters.size()>0){
						yyerror("Zła liczba parametrów.");
						YYERROR;
						}
					writeToOutput(string("\n\tcall.i #").c_str());
					writeToOutput(SymbolTable[procF].name.c_str());
				}
				else
				{
					yyerror("Program oczekiwał nazwy funkcji a otrzymał coś innego.");
					YYERROR;
				}
			}
#line 1707 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 406 "parser.y" /* yacc.c:1646  */
    {	//JAK READ WRITE WYPISZ ..
				//OBLICZ incspCount, FOR {KONWERTUJ TYPY I WRZUĆ NUMY DO PRZEKAZANIA JAKO PARMETRY FUNKCJI GENERUJ PUSHA}
				//USUŃ Z argsVector, ZRÓB ZMIENNĄ NA RETURN I JĄ ZWRÓĆ JAK FUNKCJA GENERUJ CALL I INCSP
				int index = (yyvsp[-3]);
				int w = lookup("write");
				int r = lookup("read");
				if(index==w || index==r)
				{
					//dla każdego elementu z argsVector
					for(int i=0;i<argsVector.size();i++)
					{
						if((yyvsp[-3])==r)  writeToOutputByToken(_READ, argsVector[i],true, -1, true, -1, true );
						if((yyvsp[-3])==w)  writeToOutputByToken(_WRITE,argsVector[i],true, -1, true, -1, true );
					}
				}
				else
			{
				string idName = SymbolTable[(yyvsp[-3])].name;
				int index = lookupForFunction(idName.c_str());
				if(index==-1)
				{
					yyerror("Niezadeklarowana nazwa.");
					YYERROR;
				}
				if(SymbolTable[index].token == FUN || SymbolTable[index].token == PROC)
				{
				//podano za mało parametrów
					if(argsVector.size()<SymbolTable[index].parameters.size())
					{
						yyerror("Nieprawidłowa liczba parametrów.");
						YYERROR;
					}
					// zmienna na rozmiar wrzuconych na stos referencji
					int incspCount = 0;
					//iterator po argumentach
					list<pair<int,arrayRange> >::iterator it=SymbolTable[index].parameters.begin();
					int startPoint = argsVector.size() - SymbolTable[index].parameters.size();
					// przejdź po argumentach
					for(int i=startPoint;i<argsVector.size();i++)
					{
						int id = argsVector[i];
						// typ argumentu procedury/funkcji
						int argumentType = (*it).first;
						if(argumentType==ARRAY)
						{
							argumentType = (*it).second.argType;
						}
						// jeśli przekazujemy NUM to stwórz nowy obiekt w tablicy
						if(SymbolTable[argsVector[i]].token==NUM)
						{
							// zmienna tymczasowa tworz od razu o takim typie, jakiego wymaga funkcja
							int numVar = createAdditionalVariable(argumentType);
							writeToOutputByToken(ASSIGN,numVar,true, -1, true, argsVector[i], true);
							id = numVar;
						}
						// typ przekazywany
						int passedType = SymbolTable[id].type;
						// typ argumentu funkcji i typ wartosci przekazywanej są różne (INT i REAL) - konwersja
						if(argumentType!=passedType){
						int tempVar = createAdditionalVariable(argumentType);
						writeToOutputByToken(ASSIGN, tempVar, true, -1, true, id, true);
						id = tempVar;
						}
						writeToOutputByToken(_PUSH,id,false,-1, true, -1, true);
						incspCount+=4; // zwieksz adres parametrów
						it++;
						}
						// usun z wektora argumenty
						int size = argsVector.size();
						for(int i = startPoint;i<size;i++)
						argsVector.pop_back();
						if(SymbolTable[index].token==FUN){
						// zmienna na wartość zwracaną
						int id = createAdditionalVariable(SymbolTable[index].type);
						writeToOutputByToken(_PUSH,id,false,-1, true, -1, true);
						incspCount+=4;	// zwiększ rozmiar
						(yyval) = id;
						}
						// generuj call
						writeToOutputByToken(_CALL, index,true,-1,true,-1,true);
						stringstream helper;
						helper << incspCount;
						//generuj incsp
						int incspNum = insertNumIfNE(helper.str().c_str(),INTEGER);
						writeToOutputByToken(_INCSP,incspNum,true,-1,true,-1,true);
						}
						else
						{
						yyerror("Brak takiej funkcji/procedury.");
						YYERROR;
						}
						}
						argsVector.clear();
						}
#line 1806 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 504 "parser.y" /* yacc.c:1646  */
    {
				argsVector.push_back((yyvsp[0]));
			}
#line 1814 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 508 "parser.y" /* yacc.c:1646  */
    {
				argsVector.push_back((yyvsp[0]));
			}
#line 1822 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 515 "parser.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[0]);
			}
#line 1830 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 519 "parser.y" /* yacc.c:1646  */
    {	//GENERUJE LABELE I SKACZE W ZALEŻNOŚCI CZY SPEŁNIONY WARUNEK ZWRACA RESULTVAR
			int newLabelPass = createLabel();
			int relopType = (yyvsp[-1]);
			//skok jeżeli warunek spełniony
			writeToOutputByToken(relopType, newLabelPass, true, (yyvsp[-2]), true, (yyvsp[0]), true);
			//wynik operacji RELOP czyli 0 lub 1
			int resultVar = createAdditionalVariable(INTEGER);
			int badVal = insertNumIfNE("0",INTEGER);
			//ustawia resultVar na 0 (warunek nie spełniony, nie przeskoczyliśmy)
			writeToOutputByToken(ASSIGN, resultVar, true, -1, true, badVal, true);
			//label ostatni za którym idzie dalsza część programu ten po obu (0 i 1)
			int newLabelFinish = createLabel();
			writeToOutputByToken(_JUMP, newLabelFinish, true, -1, true, -1, true);
			//jeżeli warunek spełniony
			writeToOutputByToken(_LABEL, newLabelPass, true, -1, true, -1, true);
			int goodVal = insertNumIfNE("1",INTEGER);
			writeToOutputByToken(ASSIGN, resultVar, true, -1, true, goodVal, true);//ustawia resultVar na 1 (warunek spełniony)
			//Label za całym wyrażeniem
			writeToOutputByToken(_LABEL, newLabelFinish, true, -1, true, -1, true);
			(yyval) = resultVar;
		}
#line 1856 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 545 "parser.y" /* yacc.c:1646  */
    {	//DLA PLUSA ZWRÓĆ TERM DLA MINUSA ODEJMIJ OD ZERA I ZWRÓĆ
			if((yyvsp[-1])==_PLUS) (yyval)=(yyvsp[0]);
			else{
				//operacja jak mamy liczbę ujemną
				(yyval)=createAdditionalVariable(SymbolTable[(yyvsp[0])].type);
				int tempVar = insertNumIfNE("0",SymbolTable[(yyvsp[0])].type);
				//SUB //odejmie od 0 naszą wartość z term
				writeToOutputByToken((yyvsp[-1]), (yyval), true, tempVar, true, (yyvsp[0]), true);
				}
			}
#line 1871 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 556 "parser.y" /* yacc.c:1646  */
    {	//GENERUJE OPERACJE + LUB - ZWRACA WYNIK
				int resultType=generateResultType((yyvsp[-2]), (yyvsp[0]));
				(yyval)=createAdditionalVariable(resultType);
				writeToOutputByToken((yyvsp[-1]), (yyval), true, (yyvsp[-2]), true, (yyvsp[0]), true);
			}
#line 1881 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 562 "parser.y" /* yacc.c:1646  */
    {	//GENERUJE OR ZWRACA WYNIK
				int tempVar = createAdditionalVariable(INTEGER);
				writeToOutputByToken(OR, tempVar, true, (yyvsp[-2]), true, (yyvsp[0]), true);
				(yyval) = tempVar;}
#line 1890 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 571 "parser.y" /* yacc.c:1646  */
    {	//ZWRACA WYNIK I ROBI OPERACJE DLA * MOD AND DIV
				int resultType=generateResultType((yyvsp[-2]), (yyvsp[0])); // oczekiwany typ wyniku
				(yyval)=createAdditionalVariable(resultType);//zwraca id w TS
				writeToOutputByToken((yyvsp[-1]), (yyval), true, (yyvsp[-2]), true, (yyvsp[0]), true);
			}
#line 1900 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 580 "parser.y" /* yacc.c:1646  */
    {	//PROC NIE MOŻE BO NIE ZWRACA WYNIKU, WIĘC WYWOŁANIE FUNKCJI BEZ PARM  LUB ZMIENNA
				//JAK FUN GENERUJ PUSH CALL I INCSP JAK ZMIENNA ZWRÓĆ VARIABLE JAK FUN ADRES ZWROTNY
					int funCalled = (yyvsp[0]);
					if(SymbolTable[funCalled].token==FUN){
						if(SymbolTable[funCalled].parameters.size()>0){
							yyerror("Wywołanie funkcji przyjmującej parametry bez parametrów");
							YYERROR;
						}
						funCalled = createAdditionalVariable(SymbolTable[funCalled].type);//nowa zmienna na wartość którą zwróci funkcja
						writeToOutput(string("\n\tpush.i #").c_str());writeIntToOutput(SymbolTable[funCalled].address);
						writeToOutput(string("\n\tcall.i #").c_str());writeToOutput(SymbolTable[(yyvsp[0])].name.c_str());
						//funkcja bez parametrów więc incsp = 4
						writeToOutput(string("\n\tincsp.i #4").c_str());
					}
					else if(SymbolTable[funCalled].token==PROC){
						yyerror("Nie można pobrać wyniku bo procedura go nie zwraca");
						YYERROR;
					}
					(yyval) = funCalled;
				}
#line 1925 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 601 "parser.y" /* yacc.c:1646  */
    { 	//OBLICZ incspCount, FOR {KONWERTUJ TYPY I WRZUĆ NUMY DO PRZEKAZANIA JAKO PARMETRY FUNKCJI GENERUJ PUSHA}
					//USUŃ Z argsVector, ZRÓB ZMIENNĄ NA RETURN I JĄ ZWRÓĆ JAK FUNKCJA
					//GENERUJ CALL I INCSP
				string name = SymbolTable[(yyvsp[-3])].name;
				int index = lookupForFunction(name.c_str());
				if(index==-1){
				yyerror("Niezadeklarowana nazwa.");
					YYERROR;
				}
				if(SymbolTable[index].token == FUN){
					if(argsVector.size()<SymbolTable[index].parameters.size()){
						yyerror("Nieprawidłowa liczba parametrów.");
						YYERROR;
					}
					// zmienna na rozmiar wrzuconych na stos referencji
					int incspCount = 0;
					//iterator po argumentach
					list<pair<int,arrayRange> >::iterator it=SymbolTable[index].parameters.begin();
					int startPoint = argsVector.size() - SymbolTable[index].parameters.size();
					// przejdź po argumentach
					for(int i=startPoint;i<argsVector.size();i++){
						int id = argsVector[i];
						// typ argumentu procedury/funkcji
						int argumentType = (*it).first;
						if(argumentType==ARRAY) argumentType = (*it).second.argType;
						// jeśli przekazujemy NUM to stwórz nowy obiekt w tablicy
							if(SymbolTable[argsVector[i]].token==NUM) {
							// zmienna tymczasowa tworz od razu o takim typie, jakiego wymaga funkcja
								int numVar = createAdditionalVariable(argumentType);
								writeToOutputByToken(ASSIGN,numVar,true, -1, true, argsVector[i], true);
								id = numVar;
							}
							// typ przekazywany
							int passedType = SymbolTable[id].type;
							// typ argumentu funkcji i typ wartosci przekazywanej są różne (INT i REAL) - konwersja
							if(argumentType!=passedType){
								int tempVar = createAdditionalVariable(argumentType);
								writeToOutputByToken(ASSIGN, tempVar, true, -1, true, id, true);
								id = tempVar;
							}
							writeToOutputByToken(_PUSH,id,false,-1, true, -1, true);
							incspCount+=4; // zwieksz adres parametrów
							it++;
							}
							// usun z wektora argumenty
							int size = argsVector.size();
							for(int i = startPoint;i<size;i++)
							argsVector.pop_back();
							// zmienna na wartość zwracaną
							int id = createAdditionalVariable(SymbolTable[index].type);
							writeToOutputByToken(_PUSH,id,false,-1, true, -1, true);
							incspCount+=4;	// zwiększ rozmiar
							(yyval) = id;
							// generuj call
							writeToOutputByToken(_CALL, index,true,-1,true,-1,true);
							stringstream helper;
							helper << incspCount;
							// generuj incsp
							int incspNum = insertNumIfNE(helper.str().c_str(),INTEGER);
							writeToOutputByToken(_INCSP,incspNum,true,-1,true,-1,true);
							}
							else if(SymbolTable[index].token==PROC){
								yyerror("Procedury nie zwracają wartości, nie można wykonać operacji!");
								YYERROR;
							}
							else
							{
								yyerror("Nie znaleziono takiej funkcji/procedury.");
								YYERROR;
							}
						}
#line 2001 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 674 "parser.y" /* yacc.c:1646  */
    {
				(yyval) = (yyvsp[-1]);
			}
#line 2009 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 678 "parser.y" /* yacc.c:1646  */
    {	//RÓB LABELE JAK 0 TO SKACZ JAK NIE TO TEŻ SKACZ ...
			int labelFactorEqualZero = createLabel();
			int zeroId = insertNumIfNE("0",INTEGER);
			//jeq jeżeli factor == 0 skacz do miejsca w którym ustawimy wartość na 1
			writeToOutputByToken(_EQ,labelFactorEqualZero, true, (yyvsp[0]), true,  zeroId, true);
			//jeżeli factor był inny niż 0 to zapisz 0 to zmiennej jak boło to samo to nie wykona bo przeskoczył
			int varWithNotResult = createAdditionalVariable(INTEGER);
			writeToOutputByToken(ASSIGN,varWithNotResult, true, -1, true, zeroId, true);
			//jump na koniec
			int labelFinishNOT = createLabel();
			writeToOutputByToken(_JUMP, labelFinishNOT, true, -1, true, -1, true);
			//miejsce w którym wpisujemy 1 (bo factor był 0)
			writeToOutputByToken(_LABEL, labelFactorEqualZero, true, -1, true, -1, true);
			int num1 = insertNumIfNE("1",INTEGER);
			//jeżeli factor był 0 to zapisz 1
			writeToOutputByToken(ASSIGN,varWithNotResult, true, -1, true, num1, true);
			//label kończący NOT'a
			writeToOutputByToken(_LABEL, labelFinishNOT, true, -1, true, -1, true);
			(yyval)=varWithNotResult;
			}
#line 2034 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 702 "parser.y" /* yacc.c:1646  */
    {
				return 0;
			}
#line 2042 "parser.c" /* yacc.c:1646  */
    break;


#line 2046 "parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 708 "parser.y" /* yacc.c:1906  */



void yyerror(char const *s)
{
	printf("Błąd w linii %d: %s \n",lineno, s);
}
