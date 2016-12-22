/* PRACTICA 2 */

%{
  #include <stdio.h>
  
  #include "tablasimbolos.h"
  #include "tablacuadruplas.h"
  #include "exp_a_b.h"

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
  #define DIVREA 12 //Division normal, siempre reales
  #define MODENT 13
  #define MODREA 14
  #define DIV 15 //Division entera, siempre enteros
  #define INT2REA 16
  #define ASIGNA 17
  
  extern int yylex();
  extern FILE *yyin;

  void yyerror (char const *);
  
  quad_table qt;
  symbol_table st;

%}

%union{
  int paraEnteros;
  char *paraCadenas;
  exp_a_b *paraExp;
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
%type <paraExp> exp_a_b

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
  | lista_id BI_DOSPUNTOS tipo_base BI_PUNTO_COMA lista_d_var { set_type_st(st, $3); } /* Cambiamos d_tipo por tipo_base */
  | %empty
;

lista_id:
    BI_ID BI_COMA lista_id 
          {            
            if (!exists_name_symbol_st(st, $1){
              symbol *s = new_symbol_st($1);
              insert_symbol_st(st, s);
            }
            else
            {
              printf("Error en lista_id - BI_ID BI_COMA lista_id\n");
              printf("El nombre ya está ocupado por otro identificador.\n");              
            }
          }
  | BI_ID {
            if (!exists_name_symbol_st(st, $1){
              symbol *s = new_symbol_st($1);
              insert_symbol_st(st, s);
            }
            else
            {
              printf("Error en lista_id - BI_ID\n");
              printf("El nombre ya está ocupado por otro identificador\n");
            }           
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
                              char *name = "temp";

                              $$    = new_exp_a();          // Pedimos una estructura exp_a_b para manejar aritmeticos                                                            
                              $$->s = new_symbol_st(name);  // Pedimos un simbolo temporal
                              insert_symbol_st(st, $$->s);  // Insertamos el simbolo temporal en la tabla de simbolos

                              //SUMA ENTERO ENTERO
                              if($1->s->type == TIPOENTERO && $3->s->type == TIPOENTERO){
                                quad *q = create_new_quad_qt(SUMAENT, $1->s->id, $3->s->id, $$->s->id);
                                gen(qt, q);
                                $$->s->type = TIPOENTERO;
                              }

                              //SUMA ENTERO REAL
                              else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL){
                                quad *q1 = create_new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
                                quad *q2 = create_new_quad_qt(SUMAREA, $$->s->id, $3->s->id, $$->s->id);
                                gen(qt, q1);
                                gen(qt, q2);
                                $$->s->type = TIPOREAL; 
                              }

                              //SUMA REAL ENTERO
                              else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO){
                                quad *q1 = create_new_quad_qt(INT2REA, $3->s->id, NONE, $$->s->id);
                                quad *q2 = create_new_quad_qt(SUMAREA, $$->s->id, $1->s->id, $$->s->id);
                                gen(qt, q1);
                                gen(qt, q2);
                                $$->s->type = TIPOREAL; 
                              }

                              //SUMA REAL REAL
                              else if($1->s->type == TIPOREAL && $3->s->type == TIPOREAL){
                                quad *q = create_new_quad_qt(SUMAREA, $1->s->id, $3->s->id, $$->s->id);
                                gen(qt, q);
                                $$->s->type = TIPOREAL; 
                              }

                              //Hay algun booleano
                              else if($1->s->type == TIPOBOOLEANO || $3->s->type == TIPOBOOLEANO){
                                printf("Error: No se pueden sumar booleanos\n");
                              }
                                  
                            }
  | exp_a_b BI_RESTA exp_a_b {
                                printf("Expresion resta\n");
                                $$ = newTemp(tabla);

                                //RESTA ENTERO ENTERO
                                if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, RESTAENT, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOENTERO;
                                }

                                //RESTA ENTERO REAL
                                else if($1->tipo == TIPOENTERO && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, INT2REA, $1->sid, 0, $$->sid);
                                  gen(tablaQuads, RESTAREA, $$->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //RESTA REAL ENTERO
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, INT2REA, $3->sid, 0, $$->sid);
                                  gen(tablaQuads, RESTAREA, $$->sid, $1->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //RESTA REAL REAL
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, RESTAREA, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //Hay algun booleano
                                else if($1->tipo == TIPOBOOLEANO || $3->tipo == TIPOBOOLEANO){
                                  printf("Error: No se pueden restar booleanos\n");
                                }
                              }
  | exp_a_b BI_MULT exp_a_b {
                                printf("Expresion Multiplicacion\n");
                                $$ = newTemp(tabla);

                                //MULTIPLICACION ENTERO ENTERO
                                if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, MULTENT, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOENTERO;
                                }

                                //MULTIPLICACION ENTERO REAL
                                else if($1->tipo == TIPOENTERO && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, INT2REA, $1->sid, 0, $$->sid);
                                  gen(tablaQuads, MULTREA, $$->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //MULTIPLICACION REAL ENTERO
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, INT2REA, $3->sid, 0, $$->sid);
                                  gen(tablaQuads, MULTREA, $$->sid, $1->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //MULTIPLICACION REAL REAL
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, MULTREA, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //Hay algun booleano
                                else if($1->tipo == TIPOBOOLEANO || $3->tipo == TIPOBOOLEANO){
                                  printf("Error: No se pueden multiplicar booleanos\n");
                                }
                              }
  | exp_a_b BI_DIVISION exp_a_b 
                                {
                                printf("Expresion Division\n");
                                $$ = newTemp(tabla);
                                Simbolo *aux = newTemp(tabla); 

                                //DIVISION ENTERO ENTERO
                                if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, INT2REA, $1->sid, 0, $$->sid);
                                  gen(tablaQuads, INT2REA, $3->sid, 0, aux->sid);
                                  gen(tablaQuads, DIVREA, $$->sid, aux->sid, $$->sid);
                                  $$->tipo = TIPOREAL;
                                }

                                //DIVISION ENTERO REAL
                                else if($1->tipo == TIPOENTERO && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, INT2REA, $1->sid, 0, $$->sid);
                                  gen(tablaQuads, DIVREA, $$->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //DIVISION REAL ENTERO
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, INT2REA, $3->sid, 0, $$->sid);
                                  gen(tablaQuads, DIVREA, $$->sid, $1->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //DIVISION REAL REAL
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, DIVREA, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //Hay algun booleano
                                else if($1->tipo == TIPOBOOLEANO || $3->tipo == TIPOBOOLEANO){
                                  printf("Error: No se pueden dividir booleanos\n");
                                }
                              }
  | exp_a_b BI_MOD exp_a_b {
                                printf("Expresion Modulo\n");
                                $$ = newTemp(tabla);

                                //MODULO ENTERO ENTERO
                                if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, MODENT, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOENTERO;
                                }

                                //MODULO ENTERO REAL
                                else if($1->tipo == TIPOENTERO && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, INT2REA, $1->sid, 0, $$->sid);
                                  gen(tablaQuads, MODREA, $$->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //MODULO REAL ENTERO
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, INT2REA, $3->sid, 0, $$->sid);
                                  gen(tablaQuads, MODREA, $$->sid, $1->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //MODULO REAL REAL
                                else if($1->tipo == TIPOREAL && $3->tipo == TIPOREAL){
                                  gen(tablaQuads, MODREA, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOREAL; 
                                }

                                //Hay algun booleano
                                else if($1->tipo == TIPOBOOLEANO || $3->tipo == TIPOBOOLEANO){
                                  printf("Error: No se puede sacar el modulo de booleanos\n");
                                }
                              }
  | exp_a_b BI_DIV exp_a_b {
                                printf("Expresion Division Entera\n");
                                $$ = newTemp(tabla);

                                //COCIENTE ENTERO ENTERO: devuelve solo la parte entera
                                if($1->tipo == TIPOENTERO && $3->tipo == TIPOENTERO){
                                  gen(tablaQuads, DIV, $1->sid, $3->sid, $$->sid);
                                  $$->tipo = TIPOENTERO;
                                }

                                //Hay algun real
                                else if($1->tipo == TIPOREAL || $3->tipo == TIPOREAL){
                                  printf("Error: No se pueden usar reales en una division entera\n");
                                }

                                //Hay algun booleano
                                else if($1->tipo == TIPOBOOLEANO || $3->tipo == TIPOBOOLEANO){
                                  printf("Error: No se puede sacar el cociente de booleanos\n");
                                }
                              }
  | BI_PARENTESIS_AP exp_a_b BI_PARENTESIS_CI { printf("Parentesis\n"); }
  | operando { printf("Operando\n"); }
  | BI_LITERAL_ENTERO 
                      {
                        $$ = newTemp(tabla);
                        $$->tipo = TIPOENTERO;
                      }
  | BI_LITERAL_REAL 
                    {
                      $$ = newTemp(tabla);
                      $$->tipo = TIPOREAL;
                    } 
  | BI_RESTA exp_a_b %prec BI_MENOS_UNARIO { printf("Menos Unario\n"); }
  | exp_a_b BI_Y exp_a_b 
                      {

                      }
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

int main (int argc,char **argv)
{
    if (argc>1){

        FILE * file = fopen("new file ", "r" );
        if(!file){
            printf("El archivo no existe\n");
            return -1;
        }
        yyin = file;

    }else{  

        yyin = stdin;

    }

    tabla = nuevaTabla();
    tablaQuads = nuevaTablaQuad();
    
    do{
        yyparse();
    }while (!feof(yyin));

    mostrarTablaSimbolos(tabla);
    mostrarTablaQuad(tablaQuads);
    return 0;
}

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}