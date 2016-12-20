/* PRACTICA 2 */

%{
  #include <stdio.h>
  #include "tablasimbolos.h"
	#include "tablacuadruplas.h"
  #define TRUE 1
  #define FALSE 0
  #define TIPOENTERO 1
  #define TIPOBOOLEANO 2
  #define TIPOCARACTER 3
  #define TIPOREAL 4
  #define TIPOCADENA 5
	#define SUMAENT 6
	#define SUMAREA 7
	#define RESTAENT 8
	#define RESTAREA 9
	#define MULTENT 10
	#define MULTREA 11
	#define DIVENT 12
	#define DIVREA 13
	#define INT2REA 14
	#define ASIGNA 15
	
  //int yylex (void);
  void yyerror (char const *);
%}

%union{
	int paraEnteros;
	char* paraCadenas;
	Simbolo * paraPTS;
}

%token BI_IGUAL
%left  BI_MAYOR
%left  BI_MENOR
%left  BI_MAYOR_IGUAL
%left  BI_MENOR_IGUAL
%left  BI_DISTINTO
%token BI_ASIGNACION
%token BI_COMA
%token BI_PUNTO
%token BI_PUNTO_COMA
%token BI_SUBRANGO
%token BI_DOSPUNTOS
%token BI_CORCHETE_AP
%token BI_CORCHETE_CI
%token BI_PARENTESIS_AP
%token BI_PARENTESIS_CI
%token BI_LLAVE_AP
%token BI_LLAVE_CI

%left  BI_SUMA BI_RESTA
%left  BI_MULT BI_DIVISION BI_MOD BI_DIV
%left  BI_Y BI_O
%right BI_MENOS_UNARIO

%token BI_ALGORITMO
%token BI_FALGORITMO
%token BI_ACCION
%token BI_FACCION
%token BI_FUNCION
%token BI_FFUNCION
%token BI_TIPO
%token BI_FTIPO
%token BI_CONST
%token BI_FCONST
%token BI_VAR
%token BI_FVAR
%token BI_TUPLA
%token BI_FTUPLA
%token BI_MIENTRAS
%token BI_FMIENTRAS
%token BI_HACER
%token BI_PARA
%token BI_FPARA
%token BI_HASTA
%token BI_TABLA
%token BI_CONTINUAR
%token BI_DE
%token BI_REF
%token BI_ENT
%token BI_SAL
%token BI_ES
%token BI_DEV
%right BI_NO
%token BI_SI
%token BI_FSI
%token BI_ENTONCES
%token BI_ENTERO
%token BI_REAL
%token BI_BOOLEANO
%token BI_CARACTER
%token BI_CADENA

%token BI_COMENTARIO
%token BI_LITERAL_BOOLEANO
%token BI_LITERAL_CARACTER
%token BI_LITERAL_CADENA
%token <paraCadenas> BI_ID
%token BI_LITERAL_ENTERO
%token BI_LITERAL_REAL

%type <paraEnteros> tipo_base
%type <paraPTS> exp_a_b

%start algoritmo


%% /* Grammar rules and actions follow.  */


algoritmo:
  BI_ALGORITMO BI_ID cabecera_alg bloque_alg BI_FALGORITMO { printf("Algoritmo: %s\n", $2); }
;

cabecera_alg:
  decl_globales decl_a_f decl_ent_sal BI_COMENTARIO { printf("Cabecera.\n"); }
;

bloque_alg:
  bloque BI_COMENTARIO { printf("Bloque Algoritmo.\n"); };
;

decl_globales:
    declaracion_tipo decl_globales { printf("Declaraciones Globales.\n"); }
  | declaracion_cte decl_globales { printf("Declaraciones Globales.\n"); }
  | %empty {}
;

decl_a_f:
    accion_d decl_a_f { printf("Declaracion de acciones.\n"); }
  | funcion_d decl_a_f { printf("Declaracion de funciones.\n"); }
  | %empty {}
;

bloque:
  declaraciones instrucciones { printf("Bloque.\n"); };
;

declaraciones:
    declaracion_tipo declaraciones {}
  | declaracion_cte declaraciones {}
  | declaracion_var declaraciones {}
  | %empty {}
;

declaracion_tipo:
  BI_TIPO lista_d_tipo BI_FTIPO { printf("Declaracion de tipos.\n"); }
;

declaracion_cte:
  BI_CONST lista_de_cte BI_FCONST { printf("Declaracion de constantes.\n"); }
;

declaracion_var:
  BI_VAR lista_d_var BI_FVAR { printf("Declaracion de variables.\n");}
;

lista_d_tipo:
    BI_ID BI_IGUAL d_tipo BI_PUNTO_COMA lista_d_tipo { printf("Lista de tipo.\n"); }
  | %empty {}
;

d_tipo:
    BI_TUPLA lista_campos BI_FTUPLA {}
  | BI_TABLA BI_CORCHETE_AP expresion_t BI_SUBRANGO expresion_t BI_CORCHETE_CI BI_DE d_tipo {}
  | BI_ID {}
  | expresion_t BI_SUBRANGO expresion_t {}
  | BI_REF d_tipo {}
  | tipo_base { printf("Tipo : %d\n", $1); }
;

expresion_t:
    expresion {}
  | BI_LITERAL_CARACTER {}
;

lista_campos:
    BI_ID BI_DOSPUNTOS d_tipo BI_PUNTO_COMA lista_campos {}
  | %empty {}
;

tipo_base:
    BI_LITERAL_ENTERO { $$ = TIPOENTERO; }
  | BI_LITERAL_BOOLEANO { $$ = TIPOBOOLEANO; }
  | BI_LITERAL_CARACTER { $$ = TIPOCARACTER; }
  | BI_LITERAL_REAL { $$ = TIPOREAL; }
  | BI_LITERAL_CADENA { $$ = TIPOCADENA; }
;

lista_de_cte:
    BI_ID BI_IGUAL tipo_base BI_PUNTO_COMA lista_de_cte {}
  | %empty {}
;

lista_d_var:
    lista_id BI_DOSPUNTOS BI_ID BI_PUNTO_COMA lista_d_var {}
  | lista_id BI_DOSPUNTOS d_tipo BI_PUNTO_COMA lista_d_var { modificarTiposTS($3, &tabla); }
  | %empty
;

lista_id:
    BI_ID BI_COMA lista_id 
          {
            int existe = existeSimbolo($1, &tabla);
					  if (existe == FALSE){
					    insertarSimbolo($1, &tabla);
						}
          }
  | BI_ID { 
            printf("Lista de id.\n");
	    	    insertarSimbolo($1, &tabla); 
          }
;

decl_ent_sal:
    decl_ent { printf("Declaracion de elementos de entrada\n"); }
  | decl_ent decl_sal { printf("Declaracion de elementos de entrada/salida\n"); }
  | decl_sal { printf("Declaracion de elementos de salida\n"); }
;

decl_ent:
  BI_ENT lista_d_var {}
;

decl_sal:
  BI_SAL lista_d_var {}
;

expresion:
    exp_a_b { printf("Expresion aritmetica o booleana\n"); }
  | funcion_ll { printf("Funcion"); }
;

exp_a_b:
    exp_a_b BI_SUMA exp_a_b {
															printf("Expresion suma\n");
															$$ = newTemp(&tabla);

															//SUMA ENTERO ENTERO
															if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
																gen(&tablaQuads, SUMAENT, $1->sid, $3->sid, $$->sid);
																$$->tipo = TIPOENTERO;
															}

															//SUMA ENTERO REAL
															if($1->tipo == TIPOENTERO && $3->tipo == TIPOREAL){
																gen(&tablaQuads, INT2REA, $1->sid, 0, $$->sid);
																gen(&tablaQuads, SUMAREA, $$->sid, $3->sid, $$->sid);
																$$->tipo = TIPOREAL; 
															}

															//SUMA REAL ENTERO
															if($1->tipo == TIPOREAL && $3->tipo == TIPOENTERO){
																gen(&tablaQuads, INT2REA, $3->sid, 0, $$->sid);
																gen(&tablaQuads, SUMAREA, $$->sid, $1->sid, $$->sid);
																$$->tipo = TIPOREAL; 
															}

															//SUMA REAL REAL
															if($1->tipo == TIPOREAL && $3->tipo == TIPOREAL){
																gen(&tablaQuads, SUMAREA, $1->sid, $3->sid, $$->sid);
																$$->tipo = TIPOREAL; 
															}
																	
														}
  | exp_a_b BI_RESTA exp_a_b {
																printf("Expresion resta\n");
																$$ = newTemp(&tabla);

																//RESTA ENTERO ENTERO
																if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
																	gen(&tablaQuads, RESTAENT, $1->sid, $3->sid, $$->sid);
																	$$->tipo = TIPOENTERO;
																}

																//RESTA ENTERO REAL
																if($1->tipo == TIPOENTERO && $3->tipo == TIPOREAL){
																	gen(&tablaQuads, INT2REA, $1->sid, 0, $$->sid);
																	gen(&tablaQuads, RESTAREA, $$->sid, $3->sid, $$->sid);
																	$$->tipo = TIPOREAL; 
																}

																//RESTA REAL ENTERO
																if($1->tipo == TIPOREAL && $3->tipo == TIPOENTERO){
																	gen(&tablaQuads, INT2REA, $3->sid, 0, $$->sid);
																	gen(&tablaQuads, RESTAREA, $$->sid, $1->sid, $$->sid);
																	$$->tipo = TIPOREAL; 
																}

																//RESTA REAL REAL
																if($1->tipo == TIPOREAL && $3->tipo == TIPOREAL){
																	gen(&tablaQuads, RESTAREA, $1->sid, $3->sid, $$->sid);
																	$$->tipo = TIPOREAL; 
																}
															}
  | exp_a_b BI_MULT exp_a_b {}
  | exp_a_b BI_DIVISION exp_a_b {}
  | exp_a_b BI_MOD exp_a_b {}
  | exp_a_b BI_DIV exp_a_b {}
  | BI_PARENTESIS_AP exp_a_b BI_PARENTESIS_CI {}
  | operando {}
  | BI_LITERAL_ENTERO {}
  | BI_LITERAL_REAL {} 
  | BI_RESTA exp_a_b %prec BI_MENOS_UNARIO{}
  | exp_a_b BI_Y exp_a_b {}
  | exp_a_b BI_O exp_a_b {}
  | BI_NO exp_a_b {}
  | BI_LITERAL_BOOLEANO {}
  | expresion BI_IGUAL expresion {}
  | expresion oprel expresion {}
;

oprel:
    BI_MAYOR {}
  | BI_MENOR {}
  | BI_MAYOR_IGUAL {}
  | BI_MENOR_IGUAL {}
  | BI_DISTINTO {}
;

operando:
    BI_ID {}
  | operando BI_PUNTO operando  {}
  | operando BI_CORCHETE_AP expresion BI_CORCHETE_CI {}
  | operando BI_REF {}
;

instrucciones:
    instruccion BI_PUNTO_COMA instrucciones {}
  | instruccion {}
;

instruccion:
    BI_CONTINUAR {}
  | asignacion  {}
  | alternativa {}
  | iteracion {}
  | accion_ll {}
;

asignacion:
    operando BI_ASIGNACION expresion {}
;

alternativa:
    BI_SI expresion BI_ENTONCES instrucciones lista_opciones BI_FSI {}
;

lista_opciones:
    BI_CORCHETE_AP BI_CORCHETE_CI expresion BI_ENTONCES instrucciones lista_opciones {}
  | %empty {}
;

iteracion:
    it_cota_fija  {}
  | it_cota_exp {}
;

it_cota_exp:
  BI_MIENTRAS expresion BI_HACER instrucciones BI_FMIENTRAS {}
;

it_cota_fija:
  BI_PARA BI_ID BI_ASIGNACION expresion BI_HASTA expresion BI_HACER instrucciones BI_FPARA {}
;

accion_d:
  BI_ACCION a_cabecera bloque BI_FACCION {}
;

funcion_d:
  BI_FUNCION f_cabecera bloque BI_DEV expresion BI_FFUNCION {}
;

a_cabecera:
  BI_ID BI_PARENTESIS_AP d_par_form BI_PARENTESIS_CI BI_PUNTO_COMA {}
;

f_cabecera:
  BI_ID BI_PARENTESIS_AP lista_d_var BI_PARENTESIS_CI BI_DEV d_tipo BI_PUNTO_COMA {}
;

d_par_form:
    d_p_form BI_PUNTO_COMA d_par_form {}
  | %empty {}
;

d_p_form:
    BI_ENT lista_id BI_DOSPUNTOS d_tipo {}
  | BI_SAL lista_id BI_DOSPUNTOS d_tipo {}
  | BI_ES lista_id BI_DOSPUNTOS d_tipo {}
;

accion_ll:
  BI_ID BI_PARENTESIS_AP l_ll BI_PARENTESIS_CI {}
;

funcion_ll:
  BI_ID BI_PARENTESIS_AP l_ll BI_PARENTESIS_CI {}
;

l_ll:
    expresion BI_COMA l_ll  {}
  | expresion {}
;

%%



#include <ctype.h>

/*int yylex (void)
{

}*/

int main (void)
{
	Tabla tabla = nuevaTabla();
	TablaQuad tablaQuad = nuevaTablaQuad();

  //return yyparse ();
	return 0;
}

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

