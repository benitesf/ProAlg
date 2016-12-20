/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 17 "parser.y" /* yacc.c:1909  */

	int paraEnteros;
	char* paraCadenas; 

#line 133 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
