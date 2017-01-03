/* PRACTICA 2 */

%{
  #include <stdio.h>  
  #include <stdlib.h>
  #include <string.h>
  #include "tablasimbolos.h"
  #include "tablacuadruplas.h"
  #include "exp_a_b.h"
  #include "util/list.h"
  
  extern int yylex();
  extern FILE *yyin;

  void yyerror (char const *);
  
  quad_table qt;
  symbol_table st;

%}

%code requires
{
  #include "tablasimbolos.h"
  #include "tablacuadruplas.h"
  #include "exp_a_b.h"
}

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
%type <paraExp> operando_a_b
%type <paraExp> operando
%type <paraExp> expresion

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
    declaracion_tipo declaraciones { printf("DECLARACION DE TIPOS\n");}
  | declaracion_cte declaraciones {printf("DECLARACION DE CTE\n");}
  | declaracion_var declaraciones {printf("DECLARACION DE VAR\n");}
  | %empty
;

declaracion_tipo:
  BI_TIPO lista_d_tipo BI_FTIPO { printf("Declaracion de tipos.\n"); }
;

declaracion_cte:
  BI_CONST lista_de_cte BI_FCONST { printf("Declaracion de constantes.\n"); }
;

declaracion_var:
  BI_VAR lista_d_var BI_FVAR BI_PUNTO_COMA {     
    printf("Declaracion de variables.\n");
  }
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
    BI_LITERAL_ENTERO{

      $$ = TIPOENTERO; 
      if(get_flag_st(st) == NONE)
      {
        set_type_st(st, TIPOENTERO);
        set_flag_st(st, OFF);
      }

    }
  | BI_LITERAL_BOOLEANO{

    $$ = TIPOBOOLEANO; 
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOBOOLEANO);
      set_flag_st(st, OFF);
    }

  }
  | BI_LITERAL_CARACTER{ 
    
    $$ = TIPOCARACTER; 
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOCARACTER);
      set_flag_st(st, OFF);
    }

  }
  | BI_LITERAL_REAL{ 

    $$ = TIPOREAL;
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOREAL);
      set_flag_st(st, OFF);
    }

  }
  | BI_LITERAL_CADENA{ 

    $$ = TIPOCADENA;   
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOCADENA);
      set_flag_st(st, OFF);
    }

  }
;

lista_de_cte:
    BI_ID BI_IGUAL tipo_base BI_PUNTO_COMA lista_de_cte {}
  | %empty {}
;

lista_d_var:
    lista_id BI_DOSPUNTOS tipo_id BI_PUNTO_COMA lista_d_var {
      /*
      if(exists_name_symbol_st(st,$3))
      {
        symbol *s = get_symbol_st(st, $3);

        if(get_flag_st(st) == NONE)
        {
          set_type_st(st, s->type);
          set_flag_st(st, OFF);
        }          
      }
      else
      {
        printf("Error en lista_d_var: no existe el tipo pasado como identificador en la tabla de simbolos\n");
      }*/
      
    }
  | lista_id BI_DOSPUNTOS tipo_base BI_PUNTO_COMA lista_d_var { /* Cambiamos d_tipo por tipo_base */
      if(get_flag_st(st) == NONE)
      {
        set_type_st(st, $3);
        set_flag_st(st, OFF);
      }      
    } 
  | %empty
;

tipo_id:
  BI_ID{
    printf("_______ MODIFICAMOS TIPOS -1 POR TIPO_ID ______________\n");
      if(exists_name_symbol_st(st,$1))
      {
        symbol *s = get_symbol_st(st, $1);

        if(get_flag_st(st) == NONE)
        {
          set_type_st(st, s->type);
          set_flag_st(st, OFF);
        }          
      }
      else
      {
        printf("Error en lista_d_var: no existe el tipo pasado como identificador en la tabla de simbolos\n");
      }
  }

lista_id:
    BI_ID BI_COMA lista_id 
          {            
            if(!exists_name_symbol_st(st, $1)){
              symbol *s = new_symbol_st($1);
              insert_symbol_st(st, s);
              set_flag_st(st, NONE);
            }
            else
            {
              printf("El nombre ya está ocupado por otro identificador.\n");              
            }
          }
  | BI_ID {
            if(!exists_name_symbol_st(st, $1)){
              symbol *s = new_symbol_st($1);
              insert_symbol_st(st, s);
              set_flag_st(st, NONE);
            }
            else
            {
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
    exp_a_b 
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
        quad *q = new_quad_qt(SUMAENT, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOENTERO;
      }

      //SUMA ENTERO REAL
      else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL){
        quad *q1 = new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(SUMAREA, $$->s->id, $3->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //SUMA REAL ENTERO
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO){
        quad *q1 = new_quad_qt(INT2REA, $3->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(SUMAREA, $$->s->id, $1->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //SUMA REAL REAL
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOREAL){
        quad *q = new_quad_qt(SUMAREA, $1->s->id, $3->s->id, $$->s->id);
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
      char *name = "temp";

      $$    = new_exp_a();          // Pedimos una estructura exp_a_b para manejar aritmeticos                                                            
      $$->s = new_symbol_st(name);  // Pedimos un simbolo temporal
      insert_symbol_st(st, $$->s);  // Insertamos el simbolo temporal en la tabla de simbolos

      //RESTA ENTERO ENTERO
      if($1->s->type == TIPOENTERO && $3->s->type == TIPOENTERO){
        quad *q = new_quad_qt(RESTAENT, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOENTERO;
      }

      //RESTA ENTERO REAL
      else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL){
        quad *q1 = new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(RESTAREA, $$->s->id, $3->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //RESTA REAL ENTERO
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO){
        quad *q1 = new_quad_qt(INT2REA, $3->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(RESTAREA, $$->s->id, $1->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //RESTA REAL REAL
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOREAL){
        quad *q = new_quad_qt(RESTAREA, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOREAL; 
      }

      //Hay algun booleano
      else if($1->s->type == TIPOBOOLEANO || $3->s->type == TIPOBOOLEANO){
        printf("Error: No se pueden restar booleanos\n");
      }
    }
  | exp_a_b BI_MULT exp_a_b {
      printf("Expresion Multiplicacion\n");
      char *name = "temp";

      $$    = new_exp_a();
      $$->s = new_symbol_st(name);
      insert_symbol_st(st, $$->s);

      //MULTIPLICACION ENTERO ENTERO
      if($1->s->type == TIPOENTERO && $3->s->type == TIPOENTERO){
        quad *q = new_quad_qt(MULTENT, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOENTERO;
      }

      //MULTIPLICACION ENTERO REAL
      else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL){
        quad *q1 = new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(MULTREA, $$->s->id, $3->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //MULTIPLICACION REAL ENTERO
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO){
        quad *q1 = new_quad_qt(INT2REA, $3->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(MULTREA, $$->s->id, $1->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //MULTIPLICACION REAL REAL
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOREAL){
        quad *q = new_quad_qt(MULTREA, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOREAL; 
      }

      //Hay algun booleano
      else if($1->s->type == TIPOBOOLEANO || $3->s->type == TIPOBOOLEANO){
        printf("Error: No se pueden multiplicar booleanos\n");
      }
    }
  | exp_a_b BI_DIVISION exp_a_b {
      printf("Expresion Division\n");
      char *name = "temp";

      $$    = new_exp_a();
      $$->s = new_symbol_st(name);
      insert_symbol_st(st, $$->s);

      symbol *aux = new_symbol_st(name);
      insert_symbol_st(st, aux); 

      //DIVISION ENTERO ENTERO
      if($1->s->type == TIPOENTERO && $3->s->type == TIPOENTERO){
        quad *q1 = new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(INT2REA, $3->s->id, NONE, aux->id);
        quad *q3 = new_quad_qt(DIVREA, $$->s->id, aux->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        gen(qt, q3);
        $$->s->type = TIPOREAL;
      }

      //DIVISION ENTERO REAL
      else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL){
        quad *q1 = new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(DIVREA, $$->s->id, $3->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //DIVISION REAL ENTERO
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO){
        quad *q1 = new_quad_qt(INT2REA, $3->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(DIVREA, $$->s->id, $1->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //DIVISION REAL REAL
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOREAL){
        quad *q = new_quad_qt(DIVREA, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOREAL; 
      }

      //Hay algun booleano
      else if($1->s->type == TIPOBOOLEANO || $3->s->type == TIPOBOOLEANO){
        printf("Error: No se pueden dividir booleanos\n");
      }
    }
  | exp_a_b BI_MOD exp_a_b {
      printf("Expresion Modulo\n");
      char *name = "temp";

      $$    = new_exp_a();
      $$->s = new_symbol_st(name);
      insert_symbol_st(st, $$->s);

      //MODULO ENTERO ENTERO
      if($1->s->type == TIPOENTERO && $3->s->type == TIPOENTERO){
        quad *q = new_quad_qt(MODENT, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOENTERO;
      }

      //MODULO ENTERO REAL
      else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL){
        quad *q1 = new_quad_qt(INT2REA, $1->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(MODREA, $$->s->id, $3->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //MODULO REAL ENTERO
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO){
        quad *q1 = new_quad_qt(INT2REA, $3->s->id, NONE, $$->s->id);
        quad *q2 = new_quad_qt(MODREA, $$->s->id, $1->s->id, $$->s->id);
        gen(qt, q1);
        gen(qt, q2);
        $$->s->type = TIPOREAL; 
      }

      //MODULO REAL REAL
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOREAL){
        quad *q = new_quad_qt(MODREA, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOREAL; 
      }

      //Hay algun booleano
      else if($1->s->type == TIPOBOOLEANO || $3->s->type == TIPOBOOLEANO){
        printf("Error: No se puede sacar el modulo de booleanos\n");
      }
    }
  | exp_a_b BI_DIV exp_a_b {
      printf("Expresion Division Entera\n");
      char *name = "temp";

      $$    = new_exp_a();
      $$->s = new_symbol_st(name);
      insert_symbol_st(st, $$->s);

      //COCIENTE ENTERO ENTERO: devuelve solo la parte entera
      if($1->s->type == TIPOENTERO && $3->s->type == TIPOENTERO){
        quad *q = new_quad_qt(DIV, $1->s->id, $3->s->id, $$->s->id);
        gen(qt, q);
        $$->s->type = TIPOENTERO;
      }

      //Hay algun real
      else if($1->s->type == TIPOREAL || $3->s->type == TIPOREAL){
        printf("Error: No se pueden usar reales en una division entera\n");
      }

      //Hay algun booleano
      else if($1->s->type == TIPOBOOLEANO || $3->s->type == TIPOBOOLEANO){
        printf("Error: No se puede sacar el cociente de booleanos\n");
      }
    }
  | BI_PARENTESIS_AP exp_a_b BI_PARENTESIS_CI{}
  | operando_a_b
  | BI_LITERAL_ENTERO {
      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);                        
      $$->s->type = TIPOENTERO;
      insert_symbol_st(st, $$->s);                      
    }
  | BI_LITERAL_REAL {
      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);                        
      $$->s->type = TIPOREAL;
      insert_symbol_st(st, $$->s);                      
    } 
  | BI_RESTA exp_a_b %prec BI_MENOS_UNARIO {      
      if(is_arithmetic($2))
      {
        printf("Menos unario\n");
        $$    = new_exp_a();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = $2->s->type;
        insert_symbol_st(st, $$->s);
        
        quad *q = new_quad_qt(MENOSOP, $2->s->id, NONE, $$->s->id); 
        gen(qt, q);       
      }
      else if(is_boolean($2))
      {
        fprintf(stderr, "MENOS UNARIO NO COMPATIBLE CON EL TIPO DEL OPERANDO\n");
        exit(-1);        
      }
      
    }
  | exp_a_b BI_Y exp_a_b{      
      if(is_boolean($1) && is_boolean($3))
      {        
        printf("OPERACION CONJUNCION\n");
        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;        
        insert_symbol_st(st, $$->s);

        // HACER MAKELIST
      }
      else
      {
        fprintf(stderr, "ERROR. TIPOS NOS COMPATIBLES CON LA OPERACION DE CONJUNCION\n");
        exit(-1);    
      }
    }
  | exp_a_b BI_O exp_a_b {}
  | BI_NO exp_a_b {}
  | BI_LITERAL_BOOLEANO {
      printf("LITERAL BOOLEANO\n");
      $$    = new_exp_b();
      $$->s = new_symbol_st(TEMP);
      $$->s->type = TIPOBOOLEANO;
      insert_symbol_st(st, $$->s);
    }
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

operando_a_b:
    BI_ID{
      printf("OPERANDO_A_B\n");
      if(exists_name_symbol_st(st, $1))
      {                    
        symbol *s = get_symbol_st(st, $1); 

        if(s->type == TIPOREAL || s->type == TIPOENTERO)
        {
          $$    = new_exp_a();
          $$->s = s;       
        }
        else if(s->type == TIPOBOOLEANO){
          $$    = new_exp_b();
          $$->s = s;
        }        
      }
      else
      {
        printf("El operando no existe en la tabla de simbolos\n");
      }      
    }
  | operando BI_PUNTO operando  {}
  | operando BI_CORCHETE_AP expresion BI_CORCHETE_CI {}
  | operando BI_REF {} 
;

operando:
    BI_ID {      
      printf("OPERANDO\n");
      if(exists_name_symbol_st(st, $1))
      {                
        symbol *s = get_symbol_st(st, $1);
        
        if(s->type == TIPOREAL || s->type == TIPOENTERO)
        {
          $$    = new_exp_a();
          $$->s = s;
        }
        else if(s->type == TIPOBOOLEANO){
          $$    = new_exp_b();
          $$->s = s;
        }
      }
      else
      {
        printf("El operando no existe en la tabla de simbolos\n");
      }
    }
  | operando BI_PUNTO operando  {}
  | operando BI_CORCHETE_AP expresion BI_CORCHETE_CI {}
  | operando BI_REF {}
;

instrucciones:
    instruccion BI_PUNTO_COMA instrucciones
  | instruccion BI_PUNTO_COMA
;

instruccion:
    BI_CONTINUAR {}
  | asignacion 
  | alternativa {}
  | iteracion {}
  | accion_ll {}
;

asignacion:
    operando BI_ASIGNACION expresion {
      printf("ASIGNACION\n");
      if($1->s->type == $3->s->type)
      {        
        quad *q = new_quad_qt(ASIGNA, $3->s->id, NONE, $1->s->id);
        gen(qt, q);          
      } 
      else if($1->s->type == TIPOENTERO && $3->s->type == TIPOREAL)
      {
        printf("CONVERTIMOS TIPOREAL A TIPOENTERO\n");
        quad *q = new_quad_qt(REA2INT, $3->s->id, NONE, $1->s->id);
        gen(qt, q);

      }
      else if($1->s->type == TIPOREAL && $3->s->type == TIPOENTERO)
      {
        printf("CONVERTIMOS TIPOENTERO A TIPOREAL\n");
        quad *q = new_quad_qt(INT2REA, $3->s->id, NONE, $1->s->id);
        gen(qt, q);
      }
      else 
      {
        fprintf(stderr, "ERROR, LOS TIPOS SON INCOMPATIBLES\n");
        exit(-1);
      }      
    }
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

        FILE * file = fopen(argv[1], "r" );
        if(!file){
            printf("El archivo no existe\n");
            return -1;
        }
        yyin = file;

    }else{  

        yyin = stdin;

    }

    st = new_st();
    qt = new_qt();
    
    do{
        yyparse();
    }while (!feof(yyin));

    to_string_st(st);
    to_string_qt(qt);

    free_st(st);
    free_qt(qt);

    /*st = new_st();
    qt = new_qt();  

    switch(yyparse())
    {
      case 0:
        printf("\nCompilación exitosa\n");
      break;
      case 1:
        printf("\nError en la compilación\n");
      break;
    }

    to_string_st(st);
    to_string_qt(qt);
    
    free_st(st);
    free_qt(qt);*/

    return 0;
}

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
  fprintf (stderr, "Error en el parser: %s\n", s);
  //printf("error de parseo(linea %d): %s\n", line_number, s);
}