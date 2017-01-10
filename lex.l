/* scanner para la practica 1 */
/*
    @autor Benites Fernández, Edson
    @autor Catalan Vitas, Daniel
*/
  
/* DECLARACIONES 
 * En la parte de las declaraciones se declaran:
 * 	- Constantes Manifiestas  %{ %}
 *	- Las definiciones y expresiones regulares	
 */


%{
#include "parser.tab.h"
#include "tablasimbolos.h"
#include "tablacuadruplas.h"
#include "exp_a_b.h"
%}

%option yylineno

LETRA             [a-zA-Z]
CIFRA    	      [0-9]
LR_EXP            (e|E)
LR_COM_SIM        "'"
LR_LLAVE_CI2      "/}"
LR_COM_BAR        "/'"

LR_SUMA           "+"
LR_RESTA          "-"
LR_MULT           "*"
LR_DIVISION       "/"
LR_IGUAL          "="
LR_MAYOR          ">"
LR_MENOR          "<"
LR_MAYOR_IGUAL    ">="
LR_MENOR_IGUAL    "<="
LR_DISTINTO       "<>"
LR_ASIGNACION     ":="
LR_PUNTO_COMA     ";"
LR_COMA           ","
LR_PUNTO          "."
LR_SUBRANGO       ".."
LR_DOSPUNTOS      ":"
LR_ENTONCES       "->"
LR_PARENTESIS_AP  "("
LR_PARENTESIS_CI  ")"
LR_CORCHETE_AP    "["
LR_CORCHETE_CI    "]"
LR_LLAVE_AP       "{"
LR_LLAVE_CI       "}"

PR_ACCION         (a|A)(c|C)(c|C)(i|I)(o|O)(n|N)
PR_FACCION        (f|F)(a|A)(c|C)(c|C)(i|I)(o|O)(n|N)
PR_ALGORITMO      (a|A)(l|L)(g|G)(o|O)(r|R)(i|I)(t|T)(m|M)(o|O)
PR_FALGORITMO     (f|F)(a|A)(l|L)(g|G)(o|O)(r|R)(i|I)(t|T)(m|M)(o|O)
PR_BOOLEANO       (b|B)(o|O)(o|O)(l|L)(e|E)(a|A)(n|N)(o|O)
PR_CADENA         (c|C)(a|A)(d|D)(e|E)(n|N)(a|A)
PR_CARACTER       (c|C)(a|A)(r|R)(a|A)(c|C)(t|T)(e|E)(r|R)
PR_CONST          (c|C)(o|O)(n|N)(s|S)(t|T)
PR_FCONST         (f|F)(c|C)(o|O)(n|N)(s|S)(t|T)
PR_CONTINUAR      (c|C)(o|O)(n|N)(t|T)(i|I)(n|N)(u|U)(a|A)(r|R)
PR_DEV            (d|D)(e|E)(v|V)
PR_DIV            (d|D)(i|I)(v|V)
PR_ENT            (e|E)(n|N)(t|T)
PR_ENTERO         (e|E)(n|N)(t|T)(e|E)(r|R)(o|O)
PR_ES             (e|E){LR_DIVISION}(s|S)
PR_FUNCION	  (f|F)(u|U)(n|N)(c|C)(i|i)(o|O)(n|N)
PR_FFUNCION       (f|F)(f|F)(u|U)(n|N)(c|C)(i|i)(o|O)(n|N)
PR_MIENTRAS	  (m|M)(i|I)(e|E)(n|N)(t|T)(r|R)(a|A)(s|S)
PR_FMIENTRAS	  (f|F)(m|M)(i|I)(e|E)(n|N)(t|T)(r|R)(a|A)(s|S)
PR_PARA           (p|P)(a|A)(r|R)(a|A)
PR_FPARA	  (f|F)(p|P)(a|A)(r|R)(a|A)
PR_SI             (s|S)(i|I)
PR_FSI		  (f|F)(s|S)(i|I)		
PR_TIPO		  (t|T)(i|I)(p|P)(o|O)
PR_FTIPO	  (f|F)(t|T)(i|I)(p|P)(o|O)
PR_TUPLA	  (t|T)(u|U)(p|P)(l|L)(a|A)
PR_FTUPLA	  (f|F)(t|T)(u|U)(p|P)(l|L)(a|A)
PR_VAR            (v|V)(a|A)(r|R)
PR_FVAR		  (f|F)(v|V)(a|A)(r|R)
PR_HACER	  (h|H)(a|A)(c|C)(e|E)(r|R)
PR_HASTA	  (h|H)(a|A)(s|S)(t|T)(a|A)	
PR_MOD		  (m|M)(o|O)(d|D)
PR_NO		  (n|N)(o|O)
PR_O		  (o|O)
PR_REAL		  (r|R)(e|E)(a|A)(l|L)
PR_REF		  (r|R)(e|E)(f|F)
PR_SAL		  (s|S)(a|A)(l|L)
PR_TABLA	  (t|T)(a|A)(b|B)(l|L)(a|A)
PR_Y		  (y|Y)

COMENTARIO        {LR_LLAVE_AP}([^\}]|{LR_LLAVE_CI2})*{LR_LLAVE_CI}
VERDADERO         ([vV][eE][rR][dD][aA][dD][eE][rR][oO])
FALSO             ([fF][aA][lL][sS][oO])
LITERAL_CARACTER  \".\"
LITERAL_CADENA    {LR_COM_SIM}([^\']|{LR_COM_BAR})*{LR_COM_SIM}
ID       	  {LETRA}({LETRA}|{CIFRA})*
LITERAL_ENTERO 	  ({LR_SUMA}|{LR_RESTA})?{CIFRA}+({LR_EXP}{CIFRA}+)?
LITERAL_REAL      ({LR_SUMA}|{LR_RESTA})?{CIFRA}+({LR_PUNTO}{CIFRA}+)?({LR_EXP}{CIFRA}+)?
     
%%

{LR_SUMA}             {printf( "Caracter especial +\n"); return(BI_SUMA);}
{LR_RESTA}            {printf( "Caracter especial -\n"); return(BI_RESTA);}
{LR_MULT}             {printf( "Caracter especial *\n"); return(BI_MULT);}
{LR_DIVISION}         {printf( "Caracter especial /\n"); return(BI_DIVISION);}
{LR_IGUAL}            {printf( "Caracter especial =\n"); return(BI_IGUAL);}
{LR_MAYOR}            {printf( "Caracter especial >\n"); return(BI_MAYOR);}
{LR_MENOR}            {printf( "Caracter especial <\n"); return(BI_MENOR);}
{LR_MAYOR_IGUAL}      {printf( "Caracter especial >=\n"); return(BI_MAYOR_IGUAL);}
{LR_MENOR_IGUAL}      {printf( "Caracter especial <=\n"); return(BI_MENOR_IGUAL);}
{LR_DISTINTO}         {printf( "Caracter especial <>\n"); return(BI_DISTINTO);}
{LR_ASIGNACION}       {printf( "Caracter especial :=\n"); return(BI_ASIGNACION);}
{LR_PUNTO_COMA}       {printf( "Caracter especial ;\n"); return(BI_PUNTO_COMA);}
{LR_COMA}             {printf( "Caracter especial ,\n"); return(BI_COMA);}
{LR_PUNTO}            {printf( "Caracter especial .\n"); return(BI_PUNTO);}
{LR_SUBRANGO}         {printf( "Caracter especial ..\n"); return(BI_SUBRANGO);}
{LR_DOSPUNTOS}        {printf( "Caracter especial :\n"); return(BI_DOSPUNTOS);}
{LR_ENTONCES}         {printf( "Caracter especial ->\n"); return(BI_ENTONCES);}
{LR_PARENTESIS_AP}    {printf( "Caracter especial (\n"); return(BI_PARENTESIS_AP);}
{LR_PARENTESIS_CI}    {printf( "Caracter especial )\n"); return(BI_PARENTESIS_CI);}
{LR_CORCHETE_AP}      {printf( "Caracter especial [\n"); return(BI_CORCHETE_AP);}
{LR_CORCHETE_CI}      {printf( "Caracter especial ]\n"); return(BI_CORCHETE_CI);}
{LR_LLAVE_AP}         {printf( "Caracter especial {\n"); return(BI_LLAVE_AP);}
{LR_LLAVE_CI}         {printf( "Caracter especial }\n"); return(BI_LLAVE_CI);}

{PR_ACCION}           {printf( "Palabra reservada accion\n"); return(BI_ACCION);}
{PR_FACCION}          {printf( "Palabra reservada faccion\n"); return(BI_FACCION);}
{PR_ALGORITMO}        {printf( "Palabra reservada algoritmo\n"); return(BI_ALGORITMO);}
{PR_FALGORITMO}       {printf( "Palabra reservada falgoritmo\n"); return(BI_FALGORITMO);}
{PR_BOOLEANO}         {printf( "Palabra reservada booleano\n"); return(BI_LITERAL_BOOLEANO);}
{PR_CADENA}           {printf( "Palabra reservada cadena\n"); return(BI_LITERAL_CADENA);}
{PR_CARACTER}         {printf( "Palabra reservada caracter\n"); return(BI_LITERAL_CARACTER);}
{PR_ENTERO}           {printf( "Palabra reservada entero\n"); return(BI_LITERAL_ENTERO);}
{PR_REAL}	          {printf( "Palabra reservada real\n"); return(BI_LITERAL_REAL);} 
{PR_CONST}            {printf( "Palabra reservada const\n"); return(BI_CONST);}
{PR_FCONST}           {printf( "Palabra reservada fconst\n"); return(BI_FCONST);}
{PR_CONTINUAR}        {printf( "Palabra reservada continuar\n"); return(BI_CONTINUAR);}
{PR_DEV}              {printf( "Palabra reservada dev\n"); return(BI_DEV);}
{PR_DIV}              {printf( "Palabra reservada div\n"); return(BI_DIV);}
{PR_ENT}              {printf( "Palabra reservada ent\n"); return(BI_ENT);}
{PR_ES}               {printf( "Palabra reservada es\n"); return(BI_ES);}
{PR_FUNCION}	      {printf( "Palabra reservada funcion\n"); return(BI_FUNCION);}
{PR_FFUNCION}         {printf( "Palabra reservada ffuncion\n"); return(BI_FFUNCION);}
{PR_MIENTRAS}         {printf( "Palabra reservada mientras\n"); return(BI_MIENTRAS);}
{PR_FMIENTRAS}	      {printf( "Palabra reservada fmientras\n"); return(BI_FMIENTRAS);}
{PR_PARA}             {printf( "Palabra reservada para\n"); return(BI_PARA);}
{PR_FPARA}	          {printf( "Palabra reservada fpara\n"); return(BI_FPARA);}
{PR_SI}               {printf( "Palabra reservada si\n"); return(BI_SI);}
{PR_FSI}	          {printf( "Palabra reservada fsi\n"); return(BI_FSI);}	
{PR_TIPO}	          {printf( "Palabra reservada tipo\n"); return(BI_TIPO);}
{PR_FTIPO}	          {printf( "Palabra reservada ftipo\n"); return(BI_FTIPO);}
{PR_TUPLA}	          {printf( "Palabra reservada tupla\n"); return(BI_TUPLA);}
{PR_FTUPLA}	          {printf( "Palabra reservada ftupla\n"); return(BI_FTUPLA);}
{PR_VAR}              {printf( "Palabra reservada var\n"); return(BI_VAR);}
{PR_FVAR}	          {printf( "Palabra reservada fvar\n"); return(BI_FVAR);}
{PR_HACER}	          {printf( "Palabra reservada hacer\n"); return(BI_HACER);}
{PR_HASTA}	          {printf( "Palabra reservada hasta\n"); return(BI_HASTA);}
{PR_MOD}	          {printf( "Palabra reservada mod\n"); return(BI_MOD);}  
{PR_NO}		          {printf( "Palabra reservada no\n"); return(BI_NO);}   
{PR_O}	              {printf( "Palabra reservada O\n"); return(BI_O);}    
{PR_REF}	          {printf( "Palabra reservada ref\n"); return(BI_REF);}  
{PR_SAL}	          {printf( "Palabra reservada sal\n"); return(BI_SAL);}  
{PR_TABLA}	          {printf( "Palabra reservada tabla\n"); return(BI_TABLA);}  
{PR_Y}	              {printf( "Palabra reservada Y\n"); return(BI_Y);}  

{COMENTARIO}          {printf( "Un comentario: %s\n", yytext ); return(BI_COMENTARIO);}  
{VERDADERO}           {yylval.paraBooleanos = 1; return(BI_LITERAL_BOOLEANO);}
{FALSO}               {yylval.paraBooleanos = 0; return(BI_LITERAL_BOOLEANO);}
{LITERAL_CARACTER}    {printf( "Un literal caracter: %s\n", yytext ); return(BI_LITERAL_CARACTER);}
{LITERAL_CADENA}      {printf( "Un literal cadena: %s\n", yytext ); return(BI_LITERAL_CADENA);}
{ID}        	      {	
                        yylval.paraCadenas = malloc(strlen(yytext));
            			strncpy(yylval.paraCadenas, yytext, strlen(yytext));            			
            			printf("Un identificador: %s\n", yytext);
                        return(BI_ID);
		      }
{LITERAL_ENTERO}      {printf( "Un literal entero: %s (%d)\n", yytext, atoi( yytext )); return(BI_LITERAL_ENTERO);}
{LITERAL_REAL}        {printf( "Un literal real: %s (%g)\n", yytext, atof( yytext )); return(BI_LITERAL_REAL);}     
\t {}                 /* eat up whitespace */   
\n {}        
%%
