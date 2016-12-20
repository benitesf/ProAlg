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
#line 3 "parser.y" /* yacc.c:339  */

  #include <stdio.h>
	#include <string.h>
  #include "tablasimbolos.h"
  #define TIPOENTERO 1
  #define TIPOBOOLEANO 2
  #define TIPOCARACTER 3
  #define TIPOREAL 4
  #define TIPOCADENA 5
	
  int yylex (void);
  void yyerror (char const *);

#line 80 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    BI_IGUAL = 258,
    BI_MAYOR = 259,
    BI_MENOR = 260,
    BI_MAYOR_IGUAL = 261,
    BI_MENOR_IGUAL = 262,
    BI_DISTINTO = 263,
    BI_ASIGNACION = 264,
    BI_COMA = 265,
    BI_PUNTO = 266,
    BI_PUNTO_COMA = 267,
    BI_SUBRANGO = 268,
    BI_DOSPUNTOS = 269,
    BI_CORCHETE_AP = 270,
    BI_CORCHETE_CI = 271,
    BI_PARENTESIS_AP = 272,
    BI_PARENTESIS_CI = 273,
    BI_LLAVE_AP = 274,
    BI_LLAVE_CI = 275,
    BI_SUMA = 276,
    BI_RESTA = 277,
    BI_MULT = 278,
    BI_DIVISION = 279,
    BI_MOD = 280,
    BI_DIV = 281,
    BI_Y = 282,
    BI_O = 283,
    BI_MENOS_UNARIO = 284,
    BI_ALGORITMO = 285,
    BI_FALGORITMO = 286,
    BI_ACCION = 287,
    BI_FACCION = 288,
    BI_FUNCION = 289,
    BI_FFUNCION = 290,
    BI_TIPO = 291,
    BI_FTIPO = 292,
    BI_CONST = 293,
    BI_FCONST = 294,
    BI_VAR = 295,
    BI_FVAR = 296,
    BI_TUPLA = 297,
    BI_FTUPLA = 298,
    BI_MIENTRAS = 299,
    BI_FMIENTRAS = 300,
    BI_HACER = 301,
    BI_PARA = 302,
    BI_FPARA = 303,
    BI_HASTA = 304,
    BI_TABLA = 305,
    BI_CONTINUAR = 306,
    BI_DE = 307,
    BI_REF = 308,
    BI_ENT = 309,
    BI_SAL = 310,
    BI_ES = 311,
    BI_DEV = 312,
    BI_NO = 313,
    BI_SI = 314,
    BI_FSI = 315,
    BI_ENTONCES = 316,
    BI_ENTERO = 317,
    BI_REAL = 318,
    BI_BOOLEANO = 319,
    BI_CARACTER = 320,
    BI_CADENA = 321,
    BI_COMENTARIO = 322,
    BI_LITERAL_BOOLEANO = 323,
    BI_LITERAL_CARACTER = 324,
    BI_LITERAL_CADENA = 325,
    BI_ID = 326,
    BI_LITERAL_ENTERO = 327,
    BI_LITERAL_REAL = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:355  */

	int paraEnteros;
	char* paraCadenas; 

#line 199 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 216 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   105,   109,   113,   114,   115,   119,   120,
     121,   125,   129,   130,   131,   132,   136,   140,   144,   148,
     149,   153,   154,   155,   156,   157,   158,   162,   163,   167,
     168,   172,   173,   174,   175,   176,   180,   181,   185,   186,
     187,   191,   192,   196,   197,   198,   202,   206,   210,   211,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   234,   235,   239,   240,
     241,   242,   243,   247,   248,   249,   250,   254,   255,   259,
     260,   261,   262,   263,   267,   271,   275,   276,   280,   281,
     285,   289,   293,   297,   301,   305,   309,   310,   314,   315,
     316,   320,   324,   328,   329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BI_IGUAL", "BI_MAYOR", "BI_MENOR",
  "BI_MAYOR_IGUAL", "BI_MENOR_IGUAL", "BI_DISTINTO", "BI_ASIGNACION",
  "BI_COMA", "BI_PUNTO", "BI_PUNTO_COMA", "BI_SUBRANGO", "BI_DOSPUNTOS",
  "BI_CORCHETE_AP", "BI_CORCHETE_CI", "BI_PARENTESIS_AP",
  "BI_PARENTESIS_CI", "BI_LLAVE_AP", "BI_LLAVE_CI", "BI_SUMA", "BI_RESTA",
  "BI_MULT", "BI_DIVISION", "BI_MOD", "BI_DIV", "BI_Y", "BI_O",
  "BI_MENOS_UNARIO", "BI_ALGORITMO", "BI_FALGORITMO", "BI_ACCION",
  "BI_FACCION", "BI_FUNCION", "BI_FFUNCION", "BI_TIPO", "BI_FTIPO",
  "BI_CONST", "BI_FCONST", "BI_VAR", "BI_FVAR", "BI_TUPLA", "BI_FTUPLA",
  "BI_MIENTRAS", "BI_FMIENTRAS", "BI_HACER", "BI_PARA", "BI_FPARA",
  "BI_HASTA", "BI_TABLA", "BI_CONTINUAR", "BI_DE", "BI_REF", "BI_ENT",
  "BI_SAL", "BI_ES", "BI_DEV", "BI_NO", "BI_SI", "BI_FSI", "BI_ENTONCES",
  "BI_ENTERO", "BI_REAL", "BI_BOOLEANO", "BI_CARACTER", "BI_CADENA",
  "BI_COMENTARIO", "BI_LITERAL_BOOLEANO", "BI_LITERAL_CARACTER",
  "BI_LITERAL_CADENA", "BI_ID", "BI_LITERAL_ENTERO", "BI_LITERAL_REAL",
  "$accept", "algoritmo", "cabecera_alg", "bloque_alg", "decl_globales",
  "decl_a_f", "bloque", "declaraciones", "declaracion_tipo",
  "declaracion_cte", "declaracion_var", "lista_d_tipo", "d_tipo",
  "expresion_t", "lista_campos", "tipo_base", "lista_de_cte",
  "lista_d_var", "lista_id", "decl_ent_sal", "decl_ent", "decl_sal",
  "expresion", "exp_a_b", "literal_numerico", "oprel", "operando",
  "instrucciones", "instruccion", "asignacion", "alternativa",
  "lista_opciones", "iteracion", "it_cota_exp", "it_cota_fija", "accion_d",
  "funcion_d", "a_cabecera", "f_cabecera", "d_par_form", "d_p_form",
  "accion_ll", "funcion_ll", "l_ll", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -49

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -43,    42,    20,  -115,   -16,     4,    84,    29,    20,
      20,    74,    46,    88,    69,    39,    97,    52,     3,    84,
      84,    84,    61,    64,    87,    29,    29,  -115,  -115,   117,
    -115,   141,  -115,   136,   110,   148,  -115,  -115,    65,    92,
    -115,    65,   154,    37,  -115,   160,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,   157,    84,   162,    84,    39,
      39,   115,   128,  -115,  -115,  -115,    65,    65,   113,   188,
     117,    65,   192,   196,  -115,    14,   205,   227,   249,   193,
    -115,   238,   253,  -115,    -2,  -115,  -115,  -115,  -115,  -115,
     250,    39,  -115,   123,  -115,   248,  -115,  -115,   194,   288,
      11,    65,    65,   217,    65,  -115,     3,    38,   263,    39,
     241,  -115,  -115,  -115,  -115,   238,   245,   287,   285,   257,
     147,  -115,   287,    65,   -16,   147,    65,  -115,  -115,  -115,
    -115,  -115,    65,    65,    65,    65,    65,    65,    65,    65,
      65,     4,  -115,    15,   289,     3,    65,     3,   279,   284,
     238,  -115,    -2,   244,  -115,    39,    39,    39,   286,   291,
    -115,   290,    65,  -115,   117,  -115,  -115,   292,   293,  -115,
    -115,   238,   238,   230,   230,   150,   150,   150,   150,   287,
     287,  -115,    39,    39,   261,    32,   294,    65,  -115,  -115,
     296,   298,   299,   295,    38,   258,   224,   302,   147,  -115,
    -115,  -115,  -115,    65,   300,   259,  -115,   117,   117,   117,
    -115,  -115,   117,  -115,   113,   301,   218,    65,  -115,  -115,
    -115,  -115,   306,  -115,   268,     3,    17,  -115,   117,   273,
       3,  -115,  -115,   294,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     1,    20,    37,    15,    10,     7,
       7,     0,     0,     0,     0,    40,     0,     0,     0,    15,
      15,    15,     0,     0,     0,    10,    10,     5,     6,     0,
      16,     0,    17,    42,     0,     0,     2,     4,     0,     0,
      79,     0,    73,     0,    11,    78,    80,    81,    82,    89,
      88,    83,    12,    13,    14,     0,    15,     0,    15,    40,
      40,     0,    43,    45,     8,     9,     0,     0,    30,     0,
       0,     0,    63,    28,    35,    73,    66,    67,     0,     0,
      26,    27,    48,    58,    57,    49,    32,    33,    31,    34,
       0,     0,    18,     0,    63,    73,    66,    67,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    97,     0,    40,
       0,    46,    47,     3,    44,     0,    48,    59,     0,     0,
       0,    25,    62,     0,    20,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    41,    73,     0,     0,     0,     0,   104,     0,
      84,    73,    74,     0,    77,     0,     0,     0,     0,     0,
      92,     0,     0,    56,     0,    21,    28,     0,     0,    19,
      24,    64,    65,    50,    51,    52,    53,    54,    55,    60,
      61,    36,    40,    40,     0,     0,    87,     0,   101,    75,
       0,     0,     0,     0,    97,     0,     0,     0,     0,   102,
      38,    39,    90,     0,     0,     0,   103,     0,     0,     0,
      94,    96,     0,    93,    30,     0,     0,     0,    85,    98,
      99,   100,     0,    29,     0,     0,     0,    95,     0,     0,
       0,    22,    91,    87,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,   134,   135,    10,    86,    50,    70,
    -115,   198,   -60,  -114,   109,   297,   183,   -52,   -86,  -115,
    -115,   264,   -37,   -22,  -115,  -115,   -18,  -104,  -115,  -115,
    -115,    94,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   131,
    -115,  -115,  -115,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    16,     8,    24,    17,    18,    19,    20,
      21,    12,    78,    79,   119,    80,    14,    34,    35,    61,
      62,    63,    81,    82,    83,   132,    84,    44,    45,    46,
      47,   205,    48,    49,    50,    25,    26,    56,    58,   158,
     159,    51,    85,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    98,   154,     1,   100,   142,   167,   111,   112,   103,
     121,   170,   168,   104,   126,   127,   128,   129,   130,   131,
     126,   127,   128,   129,   130,   131,   -23,   182,     3,   115,
     115,   123,   123,   144,   115,   126,   127,   128,   129,   130,
     131,   184,     4,   186,   116,   117,   102,    38,   103,   122,
      39,   105,   104,     9,    40,    11,     5,   161,     6,     9,
       9,    22,    41,    23,   148,   150,   108,   153,   110,   190,
     191,   192,   147,    10,    42,    13,   206,    29,   230,    10,
      10,   203,    66,    30,   215,   152,   148,    67,    43,   171,
     105,    31,   155,   156,   157,   172,   115,   115,   115,   115,
     115,   115,   115,   115,   197,    52,    53,    54,    32,   185,
      33,   173,   174,   175,   176,   177,   178,   179,   180,    37,
       5,   229,     6,    71,    15,   196,   233,    43,    36,    43,
     200,   201,    55,    94,    66,    57,    95,    96,    97,    67,
      66,    59,    60,    27,    28,    67,    91,   219,   220,   221,
     148,    92,   222,   -48,   -48,   -48,   -48,   -48,   -48,    68,
      64,    65,    93,    99,    66,    68,   216,    69,   231,    67,
      70,   101,   106,    69,   107,    71,    70,   139,   140,   109,
     226,    71,   113,    60,   118,    72,    73,    74,    75,    76,
      77,    72,    73,    74,   143,    76,    77,   126,   127,   128,
     129,   130,   131,   120,   -32,    71,   125,    43,   -33,    86,
      87,    74,    43,    88,    89,    94,   166,   -31,    95,    96,
      97,   126,   127,   128,   129,   130,   131,   126,   127,   128,
     129,   130,   131,   -48,   -48,   -48,   -48,   -48,   -48,   -34,
     145,   126,   127,   128,   129,   130,   131,   126,   127,   128,
     129,   130,   131,   135,   136,   137,   138,   139,   140,   213,
     189,   124,   141,   163,   225,   123,   133,   134,   135,   136,
     137,   138,   139,   140,   133,   134,   135,   136,   137,   138,
     139,   140,   126,   127,   128,   129,   130,   131,   151,   187,
     -48,   -48,   -48,   -48,   -48,   -48,   160,   146,   162,   164,
     165,   183,   188,   194,   193,   198,   202,   210,   195,   204,
     207,   199,   208,   209,   214,   212,   217,   224,   227,   218,
     228,   232,   169,   223,   181,   211,   114,   234,    90
};

static const yytype_uint8 yycheck[] =
{
      18,    38,   106,    30,    41,    91,   120,    59,    60,    11,
      70,   125,   123,    15,     3,     4,     5,     6,     7,     8,
       3,     4,     5,     6,     7,     8,    12,    12,    71,    66,
      67,    17,    17,    93,    71,     3,     4,     5,     6,     7,
       8,   145,     0,   147,    66,    67,     9,    44,    11,    71,
      47,    53,    15,     3,    51,    71,    36,   109,    38,     9,
      10,    32,    59,    34,   101,   102,    56,   104,    58,   155,
     156,   157,    61,     3,    71,    71,   187,     3,    61,     9,
      10,    49,    17,    37,   198,   103,   123,    22,   106,   126,
      53,     3,    54,    55,    56,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   164,    19,    20,    21,    39,   146,
      71,   133,   134,   135,   136,   137,   138,   139,   140,    67,
      36,   225,    38,    58,    40,   162,   230,   145,    31,   147,
     182,   183,    71,    68,    17,    71,    71,    72,    73,    22,
      17,    54,    55,     9,    10,    22,    10,   207,   208,   209,
     187,    41,   212,     3,     4,     5,     6,     7,     8,    42,
      25,    26,    14,    71,    17,    42,   203,    50,   228,    22,
      53,    17,    12,    50,    17,    58,    53,    27,    28,    17,
     217,    58,    67,    55,    71,    68,    69,    70,    71,    72,
      73,    68,    69,    70,    71,    72,    73,     3,     4,     5,
       6,     7,     8,    15,    12,    58,    13,   225,    12,    68,
      69,    70,   230,    72,    73,    68,    69,    12,    71,    72,
      73,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     8,    12,
      46,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    23,    24,    25,    26,    27,    28,    35,
      16,    12,    12,    18,    46,    17,    21,    22,    23,    24,
      25,    26,    27,    28,    21,    22,    23,    24,    25,    26,
      27,    28,     3,     4,     5,     6,     7,     8,    71,    10,
       3,     4,     5,     6,     7,     8,    33,     9,    57,    14,
      43,    12,    18,    12,    18,    13,    45,    12,    18,    15,
      14,    18,    14,    14,    12,    57,    16,    16,    12,    60,
      52,    48,   124,   214,   141,   194,    62,   233,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    75,    71,     0,    36,    38,    76,    78,    82,
      83,    71,    85,    71,    90,    40,    77,    80,    81,    82,
      83,    84,    32,    34,    79,   109,   110,    78,    78,     3,
      37,     3,    39,    71,    91,    92,    31,    67,    44,    47,
      51,    59,    71,   100,   101,   102,   103,   104,   106,   107,
     108,   115,    81,    81,    81,    71,   111,    71,   112,    54,
      55,    93,    94,    95,    79,    79,    17,    22,    42,    50,
      53,    58,    68,    69,    70,    71,    72,    73,    86,    87,
      89,    96,    97,    98,   100,   116,    68,    69,    72,    73,
      89,    10,    41,    14,    68,    71,    72,    73,    96,    71,
      96,    17,     9,    11,    15,    53,    12,    17,    80,    17,
      80,    91,    91,    67,    95,    96,    97,    97,    71,    88,
      15,    86,    97,    17,    12,    13,     3,     4,     5,     6,
       7,     8,    99,    21,    22,    23,    24,    25,    26,    27,
      28,    12,    92,    71,    86,    46,     9,    61,    96,   117,
      96,    71,   100,    96,   101,    54,    55,    56,   113,   114,
      33,    91,    57,    18,    14,    43,    69,    87,   117,    85,
      87,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    90,    12,    12,   101,    96,   101,    10,    18,    16,
      92,    92,    92,    18,    12,    18,    96,    86,    13,    18,
      91,    91,    45,    49,    15,   105,   117,    14,    14,    14,
      12,   113,    57,    35,    12,    87,    96,    16,    60,    86,
      86,    86,    86,    88,    16,    46,    96,    12,    52,   101,
      61,    86,    48,   101,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    77,    78,    78,    78,    79,    79,
      79,    80,    81,    81,    81,    81,    82,    83,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    93,    94,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   100,   100,   101,   101,   102,
     102,   102,   102,   102,   103,   104,   105,   105,   106,   106,
     107,   108,   109,   110,   111,   112,   113,   113,   114,   114,
     114,   115,   116,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     3,     3,     3,     5,
       0,     3,     8,     1,     3,     2,     1,     1,     1,     5,
       0,     1,     1,     1,     1,     1,     5,     0,     5,     5,
       0,     3,     1,     1,     2,     1,     2,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       3,     3,     2,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     6,     6,     0,     1,     1,
       5,     9,     4,     6,     5,     7,     3,     0,     4,     4,
       4,     4,     4,     3,     1
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
#line 101 "parser.y" /* yacc.c:1646  */
    { printf("Algoritmo: %s\n", (yyvsp[-3].paraCadenas)); }
#line 1489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 105 "parser.y" /* yacc.c:1646  */
    { printf("Cabecera.\n"); }
#line 1495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "parser.y" /* yacc.c:1646  */
    { printf("Bloque Algoritmo.\n"); }
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 113 "parser.y" /* yacc.c:1646  */
    { printf("Declaraciones Globales.\n"); }
#line 1507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 114 "parser.y" /* yacc.c:1646  */
    { printf("Declaraciones Globales.\n"); }
#line 1513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 115 "parser.y" /* yacc.c:1646  */
    {}
#line 1519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "parser.y" /* yacc.c:1646  */
    { printf("Declaracion de acciones.\n"); }
#line 1525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "parser.y" /* yacc.c:1646  */
    { printf("Declaracion de funciones.\n"); }
#line 1531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "parser.y" /* yacc.c:1646  */
    {}
#line 1537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "parser.y" /* yacc.c:1646  */
    { printf("Bloque.\n"); }
#line 1543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "parser.y" /* yacc.c:1646  */
    {}
#line 1549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "parser.y" /* yacc.c:1646  */
    {}
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 131 "parser.y" /* yacc.c:1646  */
    {}
#line 1561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "parser.y" /* yacc.c:1646  */
    {}
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "parser.y" /* yacc.c:1646  */
    { printf("Declaracion de tipos.\n"); }
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "parser.y" /* yacc.c:1646  */
    { printf("Declaracion de constantes.\n"); }
#line 1579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 144 "parser.y" /* yacc.c:1646  */
    { printf("Declaracion de variables.\n");}
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 148 "parser.y" /* yacc.c:1646  */
    { printf("Lista de tipo.\n"); }
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 149 "parser.y" /* yacc.c:1646  */
    {}
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "parser.y" /* yacc.c:1646  */
    {}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 154 "parser.y" /* yacc.c:1646  */
    {}
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 155 "parser.y" /* yacc.c:1646  */
    {}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "parser.y" /* yacc.c:1646  */
    {}
#line 1621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "parser.y" /* yacc.c:1646  */
    {}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "parser.y" /* yacc.c:1646  */
    { printf("Tipo : %d\n", (yyvsp[0].paraEnteros)); }
#line 1633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "parser.y" /* yacc.c:1646  */
    {}
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 163 "parser.y" /* yacc.c:1646  */
    {}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "parser.y" /* yacc.c:1646  */
    {}
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 168 "parser.y" /* yacc.c:1646  */
    {}
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.paraEnteros) = TIPOENTERO; }
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.paraEnteros) = TIPOBOOLEANO; }
#line 1669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.paraEnteros) = TIPOCARACTER; }
#line 1675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.paraEnteros) = TIPOREAL; }
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.paraEnteros) = TIPOCADENA; }
#line 1687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 180 "parser.y" /* yacc.c:1646  */
    {}
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "parser.y" /* yacc.c:1646  */
    {}
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "parser.y" /* yacc.c:1646  */
    {}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "parser.y" /* yacc.c:1646  */
    {}
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 191 "parser.y" /* yacc.c:1646  */
    {}
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 192 "parser.y" /* yacc.c:1646  */
    {}
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 196 "parser.y" /* yacc.c:1646  */
    {}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 197 "parser.y" /* yacc.c:1646  */
    {}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 198 "parser.y" /* yacc.c:1646  */
    {}
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 202 "parser.y" /* yacc.c:1646  */
    {}
#line 1747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 206 "parser.y" /* yacc.c:1646  */
    {}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 210 "parser.y" /* yacc.c:1646  */
    {}
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 211 "parser.y" /* yacc.c:1646  */
    {}
#line 1765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 215 "parser.y" /* yacc.c:1646  */
    {}
#line 1771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 216 "parser.y" /* yacc.c:1646  */
    {}
#line 1777 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "parser.y" /* yacc.c:1646  */
    {}
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "parser.y" /* yacc.c:1646  */
    {}
#line 1789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 219 "parser.y" /* yacc.c:1646  */
    {}
#line 1795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 220 "parser.y" /* yacc.c:1646  */
    {}
#line 1801 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 221 "parser.y" /* yacc.c:1646  */
    {}
#line 1807 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 222 "parser.y" /* yacc.c:1646  */
    {}
#line 1813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 223 "parser.y" /* yacc.c:1646  */
    {}
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 224 "parser.y" /* yacc.c:1646  */
    {}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 225 "parser.y" /* yacc.c:1646  */
    {}
#line 1831 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 226 "parser.y" /* yacc.c:1646  */
    {}
#line 1837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 227 "parser.y" /* yacc.c:1646  */
    {}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 228 "parser.y" /* yacc.c:1646  */
    {}
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 229 "parser.y" /* yacc.c:1646  */
    {}
#line 1855 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 230 "parser.y" /* yacc.c:1646  */
    {}
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 234 "parser.y" /* yacc.c:1646  */
    {}
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 235 "parser.y" /* yacc.c:1646  */
    {}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 239 "parser.y" /* yacc.c:1646  */
    {}
#line 1879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 240 "parser.y" /* yacc.c:1646  */
    {}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 241 "parser.y" /* yacc.c:1646  */
    {}
#line 1891 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 242 "parser.y" /* yacc.c:1646  */
    {}
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 243 "parser.y" /* yacc.c:1646  */
    {}
#line 1903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 247 "parser.y" /* yacc.c:1646  */
    {}
#line 1909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 248 "parser.y" /* yacc.c:1646  */
    {}
#line 1915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 249 "parser.y" /* yacc.c:1646  */
    {}
#line 1921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 250 "parser.y" /* yacc.c:1646  */
    {}
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 254 "parser.y" /* yacc.c:1646  */
    {}
#line 1933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 255 "parser.y" /* yacc.c:1646  */
    {}
#line 1939 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 259 "parser.y" /* yacc.c:1646  */
    {}
#line 1945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 260 "parser.y" /* yacc.c:1646  */
    {}
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 261 "parser.y" /* yacc.c:1646  */
    {}
#line 1957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 262 "parser.y" /* yacc.c:1646  */
    {}
#line 1963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 263 "parser.y" /* yacc.c:1646  */
    {}
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 267 "parser.y" /* yacc.c:1646  */
    {}
#line 1975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 271 "parser.y" /* yacc.c:1646  */
    {}
#line 1981 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 275 "parser.y" /* yacc.c:1646  */
    {}
#line 1987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 276 "parser.y" /* yacc.c:1646  */
    {}
#line 1993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 280 "parser.y" /* yacc.c:1646  */
    {}
#line 1999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 281 "parser.y" /* yacc.c:1646  */
    {}
#line 2005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 285 "parser.y" /* yacc.c:1646  */
    {}
#line 2011 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 289 "parser.y" /* yacc.c:1646  */
    {}
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 293 "parser.y" /* yacc.c:1646  */
    {}
#line 2023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "parser.y" /* yacc.c:1646  */
    {}
#line 2029 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 301 "parser.y" /* yacc.c:1646  */
    {}
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 305 "parser.y" /* yacc.c:1646  */
    {}
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 309 "parser.y" /* yacc.c:1646  */
    {}
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 310 "parser.y" /* yacc.c:1646  */
    {}
#line 2053 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 314 "parser.y" /* yacc.c:1646  */
    {}
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 315 "parser.y" /* yacc.c:1646  */
    {}
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 316 "parser.y" /* yacc.c:1646  */
    {}
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 320 "parser.y" /* yacc.c:1646  */
    {}
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 324 "parser.y" /* yacc.c:1646  */
    {}
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 328 "parser.y" /* yacc.c:1646  */
    {}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 329 "parser.y" /* yacc.c:1646  */
    {}
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2099 "parser.tab.c" /* yacc.c:1646  */
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
#line 332 "parser.y" /* yacc.c:1906  */




#include <ctype.h>

int yylex (void)
{
  int c;

  /* Skip white space.  */
  while ((c = getchar ()) == ' ' || c == '\t')
    continue;

  /* Process numbers.  */
  if (c == '.' || isdigit (c))
    {
      ungetc (c, stdin);
      scanf ("%lf", &yylval);
      return NUM;
    }

  /* Return end-of-input.  */
  if (c == EOF)
    return 0;
  /* Return a single char.  */
  return c;
}

int main (void)
{
  return yyparse ();
}



#include <stdio.h>

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}
