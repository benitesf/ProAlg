/* PRACTICA 2 */
/*
    @autor Benites Fernández, Edson
    @autor Catalan Vitas, Daniel
*/

%{
  #include <stdio.h>  
  #include <stdlib.h>
  #include <string.h>
  #include "tablasimbolos.h"
  #include "tablacuadruplas.h"
  #include "exp_a_b.h"
  
  extern int yylex();
  extern FILE *yyin;
  extern yylineno;

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
  int paraBooleanos;
  int paraOprel;
  char *paraCadenas;
  exp_a_b *paraExp;
  int paraM;
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
%token <paraBooleanos> BI_LITERAL_BOOLEANO
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
%type <paraOprel> oprel
%type <paraM> M

%start algoritmo


%% /* Grammar rules and actions follow.  */


algoritmo:
  BI_ALGORITMO BI_ID cabecera_alg bloque_alg BI_FALGORITMO { 
    #ifdef _DEBUG
    printf("ALGORITMO\n"); 
    #endif
  }
;

cabecera_alg:
  decl_globales decl_a_f decl_ent_sal BI_COMENTARIO { 
    #ifdef _DEBUG
    printf("CABECERA\n"); 
    #endif
  }
    
;

bloque_alg:
  bloque BI_COMENTARIO { 
    #ifdef _DEBUG
    printf("BLOQUE ALGORITMO\n"); 
    #endif
  };
    
;

decl_globales:
    declaracion_tipo decl_globales { 
      #ifdef _DEBUG
      printf("DECLARACION DE TIPO\n"); 
      #endif
    }
  | declaracion_cte decl_globales { 
      #ifdef _DEBUG
      printf("DECLARACION DE CTE\n"); 
      #endif
    }
  | %empty {}
;

decl_a_f:
    accion_d decl_a_f { 
      #ifdef _DEBUG
      printf("DECLARACION DE ACCION/ES\n"); 
      #endif
    }
  | funcion_d decl_a_f {
      #ifdef _DEBUG 
      printf("DECLARACION DE FUNCION/ES\n"); 
      #endif
    }
  | %empty {}
;

bloque:
  declaraciones instrucciones { 
    #ifdef _DEBUG
    printf("BLOQUE DE INSTRUCCIONES\n"); 
    #endif
  }
;

declaraciones:
    declaracion_tipo declaraciones {
      #ifdef _DEBUG
      printf("DECLARACION DE TIPOS\n");
      #endif
    }
  | declaracion_cte declaraciones {
      #ifdef _DEBUG
      printf("DECLARACION DE CTE\n");
      #endif
    }
  | declaracion_var declaraciones {
      #ifdef _DEBUG
      printf("DECLARACION DE VAR\n");
      #endif
    }
  | %empty
;

declaracion_tipo:
  BI_TIPO lista_d_tipo BI_FTIPO {
    #ifdef _DEBUG
    printf("DECLARACION DE TIPOS.\n"); 
    #endif
  }
;

declaracion_cte:
  BI_CONST lista_de_cte BI_FCONST {
    #ifdef _DEBUG
    printf("DECLARACION DE CONSTANTES\n"); 
    #endif
  }
;

declaracion_var:
  BI_VAR lista_d_var BI_FVAR BI_PUNTO_COMA {     
    #ifdef _DEBUG
    printf("DECLARACION DE VARIABLES\n");
    #endif
  }
;

lista_d_tipo:
    BI_ID BI_IGUAL d_tipo BI_PUNTO_COMA lista_d_tipo { 
      #ifdef _DEBUG
      printf("LISTA DE TIPO\n"); 
      #endif
    }
  | %empty {}
;

d_tipo:
    BI_TUPLA lista_campos BI_FTUPLA {}
  | BI_TABLA BI_CORCHETE_AP expresion_t BI_SUBRANGO expresion_t BI_CORCHETE_CI BI_DE d_tipo {}
  | BI_ID {}
  | expresion_t BI_SUBRANGO expresion_t {}
  | BI_REF d_tipo {}
  | tipo_base { 
      #ifdef _DEBUG
      printf("TIPO : %d\n", $1); 
      #endif
    }
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
      #ifdef _DEBUG
      printf("LITERAL ENTERO\n");
      #endif

      $$ = TIPOENTERO; 
      if(get_flag_st(st) == NONE)
      {
        set_type_st(st, TIPOENTERO);
        set_flag_st(st, OFF);
      }

    }
  | BI_LITERAL_BOOLEANO{
    #ifdef _DEBUG
    printf("LITERAL BOOLEANO\n");
    #endif

    $$ = TIPOBOOLEANO; 
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOBOOLEANO);
      set_flag_st(st, OFF);
    }

  }
  | BI_LITERAL_CARACTER{ 
    #ifdef _DEBUG
    printf("LITERAL CARACTER\n");
    #endif

    $$ = TIPOCARACTER; 
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOCARACTER);
      set_flag_st(st, OFF);
    }

  }
  | BI_LITERAL_REAL{ 
    #ifdef _DEBUG
    printf("LITERAL REAL\n");
    #endif

    $$ = TIPOREAL;
    if(get_flag_st(st) == NONE)
    {
      set_type_st(st, TIPOREAL);
      set_flag_st(st, OFF);
    }

  }
  | BI_LITERAL_CADENA{ 
    #ifdef _DEBUG
    printf("LITERAL CADENA\n");
    #endif

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
    lista_id BI_DOSPUNTOS tipo_id BI_PUNTO_COMA lista_d_var {}
  | lista_id BI_DOSPUNTOS tipo_base BI_PUNTO_COMA lista_d_var { /* Cambiamos d_tipo por tipo_base */
      #ifdef _DEBUG
      printf("LISTA DE VARIABLES\n");
      #endif

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
    #ifdef _DEBUG
    printf("ASIGNACION DE TIPOS POR TIPO ID\n");
    #endif
    
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
      #ifdef _DEBUG
      printf("LISTA DE IDENTIFICADORES\n");
      #endif  

      if(!exists_name_symbol_st(st, $1)){
        symbol *s = new_symbol_st($1);
        insert_symbol_st(st, s);
        set_flag_st(st, NONE);
      }
      else
      {
        #ifdef _DEBUG
        printf("EL IDENTIFICADOR YA EXISTE EN LA TABLA DE SIMBOLOS\n");
        #endif
      }
    }
  | BI_ID 
    {
      #ifdef _DEBUG
      printf("IDENTIFICADOR\n");
      #endif

      if(!exists_name_symbol_st(st, $1)){
        symbol *s = new_symbol_st($1);
        insert_symbol_st(st, s);
        set_flag_st(st, NONE);
      }
      else
      {
        #ifdef _DEBUG
        printf("EL IDENTIFICADOR YA EXISTE EN LA TABLA DE SIMBOLOS\n");
        #endif
      }           
    }
;

decl_ent_sal:
    decl_ent { 
      #ifdef _DEBUG
      printf("DECLARACION DE ELEMENTOS DE ENTRADA\n");
      #endif
    }
  | decl_ent decl_sal { 
      #ifdef _DEBUG
      printf("DECLARACION DE ELEMENTOS DE ENTRADA Y SALIDA\n");
      #endif
    }
  | decl_sal { 
      #ifdef _DEBUG
      printf("DECLARACION DE ELEMENTOS DE SALIDA\n");
      #endif
    }
;

decl_ent:
  BI_ENT lista_d_var {}
;

decl_sal:
  BI_SAL lista_d_var {}
;

expresion:
    exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA BOOLEANA\n");
      #endif

      $$ = $1;
    }
  | funcion_ll {}
;

exp_a_b:
    exp_a_b BI_SUMA exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA SUMA\n");
      #endif

      $$    = new_exp_a();          // Pedimos una estructura exp_a_b para manejar aritmeticos                                                            
      $$->s = new_symbol_st(TEMP);  // Pedimos un simbolo temporal
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
        yyerror("NO SE PUEDEN SUMAR BOOLEANOS");
      }
          
    }
  | exp_a_b BI_RESTA exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA RESTA\n");
      #endif

      $$    = new_exp_a();          // Pedimos una estructura exp_a_b para manejar aritmeticos                                                            
      $$->s = new_symbol_st(TEMP);  // Pedimos un simbolo temporal
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
        yyerror("NO SE PUEDEN RESTAR BOOLEANOS");
      }
    }
  | exp_a_b BI_MULT exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA MULTIPLICACION\n");
      #endif

      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);
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
        yyerror("NO SE PUEDEN MULTIPLICAR BOOLEANOS");
      }
    }
  | exp_a_b BI_DIVISION exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA DIVISION\n");
      #endif

      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);
      insert_symbol_st(st, $$->s);

      symbol *aux = new_symbol_st(TEMP);
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
        yyerror("NO SE PUEDEN DIVIDIR BOOLEANOS");
      }
    }
  | exp_a_b BI_MOD exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA MODULO\n");
      #endif

      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);
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
        yyerror("NO SE PUEDE SACAR LE MODULO DE BOOLEANOS");
      }
    }
  | exp_a_b BI_DIV exp_a_b {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA DIVISION ENTERA\n");
      #endif

      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);
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
        yyerror("NO SE PUEDE SACAR EL COCIENTE DE BOOLEANOS");
      }
    }
  | BI_PARENTESIS_AP exp_a_b BI_PARENTESIS_CI{
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA BOOLEANA PARENTESIS\n");
      #endif

      if(is_arithmetic($2))
      {
        $$ = $2;
      }
      else if(is_boolean($2))
      {
        $$ = $2;
      }
      else
      {
        yyerror("TIPO NO COMPATIBLE CON LA OPERACION (EXP)");        
      }
    }
  | operando_a_b
  | BI_LITERAL_ENTERO {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA LITERAL ENTERO\n");
      #endif

      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);                            
      $$->s->type = TIPOENTERO;
      insert_symbol_st(st, $$->s);                      
    }
  | BI_LITERAL_REAL {
      #ifdef _DEBUG
      printf("EXPRESION ARITMETICA LITERAL REAL\n");
      #endif

      $$    = new_exp_a();
      $$->s = new_symbol_st(TEMP);                        
      $$->s->type = TIPOREAL;
      insert_symbol_st(st, $$->s);                      
    } 
  | BI_RESTA exp_a_b %prec BI_MENOS_UNARIO {      
      if(is_arithmetic($2))
      {
        #ifdef _DEBUG
        printf("EXPRESION ARITMETICA MENOS UNARIO\n");
        #endif

        $$    = new_exp_a();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = $2->s->type;
        insert_symbol_st(st, $$->s);
        
        quad *q = new_quad_qt(MENOSOP, $2->s->id, NONE, $$->s->id); 
        gen(qt, q);       
      }
      else if(is_boolean($2))
      {
        yyerror("MENOS UNARIO NO COMPATIBLE CON EL TIPO DEL OPERANDO");        
      }
      
    }
  | exp_a_b BI_Y M exp_a_b{      
      if(is_boolean($1) && is_boolean($4))
      {        
        #ifdef _DEBUG
        printf("EXPRESION BOOLEANA Y\n");
        #endif

        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;        
        insert_symbol_st(st, $$->s);

        backpatch($1->true, $3);
        $$->false = merge($1->false, $4->false);
        $$->true  = $4->true;      
      }
      else
      {
        yyerror("TIPOS NOS COMPATIBLES CON LA OPERACION Y");
      }
    }
  | exp_a_b BI_O M exp_a_b {      
      if(is_boolean($1) && is_boolean($4))
      {
        #ifdef _DEBUG
        printf("EXPRESION BOOLEANA O\n");
        #endif

        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;
        insert_symbol_st(st, $$->s);

        backpatch($1->false, $3);
        $$->true = merge($1->true, $4->true);
        $$->false = $4->false;
      }
      else
      {
        yyerror("TIPOS NOS COMPATIBLES CON LA OPERACION O");
      }
      

    }
  | BI_NO exp_a_b {
      if(is_boolean($2))
      {
        #ifdef _DEBUG
        printf("EXPRESION BOOLEANA NEGACION\n");
        #endif

        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;
        insert_symbol_st(st, $$->s);

        $$->true  = $2->false;
        $$->false = $2->true;
      }
      else
      {
        yyerror("TIPOS NOS COMPATIBLES CON LA OPERACION NEGACION");
      }
    }
  | BI_LITERAL_BOOLEANO {
      #ifdef _DEBUG
      printf("EXPRESION BOOLEANA LITERAL BOOLEANO\n");
      #endif

      $$    = new_exp_b();
      $$->s = new_symbol_st(TEMP);
      $$->s->type = TIPOBOOLEANO;
      $$->s->value.bool = $1;
      insert_symbol_st(st, $$->s);

      quad *q1 = new_quad_qt(GOTO, $$->s->id, CTE_TRUE, NOGOTO);
      quad *q2 = new_quad_qt(GOTO, $$->s->id, CTE_FALSE, NOGOTO);

      gen(qt, q1);
      gen(qt, q2);

      $$->true  = makelist(q1);
      $$->false = makelist(q2);

    }  
  | expresion oprel expresion {
    if($2 == IGUAL || $2 == DISTINTO)
    {
      if(is_boolean($1) && is_boolean($3))
      {        
        #ifdef _DEBUG
        printf("EXPRESION BOOLEANA OPREL\n");
        #endif

        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;
        insert_symbol_st(st, $$->s);
        
        quad *q1 = new_quad_qt($2, $1->s->id, $3->s->id, NOGOTO);
        quad *q2 = new_quad_qt(GOTO, $$->s->id, CTE_FALSE, NOGOTO);

        gen(qt, q1);
        gen(qt, q2);

        $$->true  = makelist(q1);
        $$->false = makelist(q2);
      }
      else if(is_arithmetic($1) && is_arithmetic($3))
      {
        #ifdef _DEBUG
        printf("EXPRESION ARITMETICA OPREL\n");
        #endif 
        
        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;
        insert_symbol_st(st, $$->s);
        
        quad *q1 = new_quad_qt($2, $1->s->id, $3->s->id, NOGOTO);
        quad *q2 = new_quad_qt(GOTO, $$->s->id, CTE_FALSE, NOGOTO);

        gen(qt, q1);
        gen(qt, q2);

        $$->true  = makelist(q1);
        $$->false = makelist(q2);        
      }
      else
      {
        yyerror("TIPOS NOS COMPATIBLES CON OPREL");
      }
    }
    else
    {
      if(is_arithmetic($1) && is_arithmetic($3))
      {
        #ifdef _DEBUG
        printf("EXPRESION ARITMETICA OPREL\n");
        #endif 
        
        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;
        insert_symbol_st(st, $$->s);
        
        quad *q1 = new_quad_qt($2, $1->s->id, $3->s->id, NOGOTO);
        quad *q2 = new_quad_qt(GOTO, $$->s->id, CTE_FALSE, NOGOTO);

        gen(qt, q1);
        gen(qt, q2);

        $$->true  = makelist(q1);
        $$->false = makelist(q2);        
      }
      else
      {
        yyerror("TIPOS NOS COMPATIBLES CON OPREL");
      }
    }     
      
    }
  | operando_a_b oprel operando_a_b{
      if(is_arithmetic($1) && is_arithmetic($3))
      {
        #ifdef _DEBUG
        printf("OPERANDO ARITMETICO OPREL OPERANDO ARITMETICO\n");
        #endif 
        
        $$ = new_exp_b();
        $$->s = new_symbol_st(TEMP);
        $$->s->type = TIPOBOOLEANO;
        insert_symbol_st(st, $$->s);
        
        quad *q1 = new_quad_qt($2, $1->s->id, $3->s->id, NOGOTO);
        quad *q2 = new_quad_qt(GOTO, $$->s->id, CTE_FALSE, NOGOTO);

        gen(qt, q1);
        gen(qt, q2);

        $$->true  = makelist(q1);
        $$->false = makelist(q2);        
      }
      else
      {
        yyerror("TIPOS NOS COMPATIBLES CON LA OPERACION IGUAL BOOLEANA");
      }
  }
;

oprel:
    BI_MAYOR {$$ = MAYOR;}
  | BI_MENOR {$$ = MENOR;}
  | BI_MAYOR_IGUAL {$$ = MAYOR_IGUAL;}
  | BI_MENOR_IGUAL {$$ = MENOR_IGUAL;}
  | BI_DISTINTO {$$ = DISTINTO;}
  | BI_IGUAL {$$ = IGUAL;}
;

operando_a_b:
    BI_ID{
      #ifdef _DEBUG
      printf("OPERANDO_A_B\n");
      #endif

      if(exists_name_symbol_st(st, $1))
      { 
        #ifdef _DEBUG
        printf("EL ID EXISTE EN LA TABLA DE SIMBOLOS\n");
        #endif                   

        symbol *s = get_symbol_st(st, $1); 

        if(s->type == TIPOREAL || s->type == TIPOENTERO)
        {
          $$    = new_exp_a();
          $$->s = s;       
        }
        else if(s->type == TIPOBOOLEANO){
          $$    = new_exp_b();
          $$->s = s;

          quad *q1 = new_quad_qt(GOTO, $$->s->id, CTE_TRUE, NOGOTO);
          quad *q2 = new_quad_qt(GOTO, $$->s->id, CTE_FALSE, NOGOTO);

          gen(qt, q1);
          gen(qt, q2);          

          $$->true  = makelist(q1);
          $$->false = makelist(q2);                   
        }        
      }
      else
      {
        #ifdef _DEBUG
        printf("EL ID NO EXISTE EN LA TABLA DE SIMBOLOS\n");
        #endif
        yyerror("ID NO EXISTE EN LA TABLA DE SIMBOLOS");
      }      
    }
  | operando BI_PUNTO operando  {}
  | operando BI_CORCHETE_AP expresion BI_CORCHETE_CI {}
  | operando BI_REF {} 
;

operando:
    BI_ID {      
      #ifdef _DEBUG
      printf("OPERANDO\n");
      #endif

      if(exists_name_symbol_st(st, $1))
      {    
        #ifdef _DEBUG
        printf("EL ID EXISTE EN LA TABLA DE SIMBOLOS\n");
        #endif

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
        #ifdef _DEBUG
        printf("EL ID NO EXISTE EN LA TABLA DE SIMBOLOS\n");
        #endif
        yyerror("ID NO EXISTE EN LA TABLA DE SIMBOLOS");
      }
    }
  | operando BI_PUNTO operando  {}
  | operando BI_CORCHETE_AP expresion BI_CORCHETE_CI {}
  | operando BI_REF {}
;

M:
  %empty {$$ = next_quad_qt(qt);}

instrucciones:
    instruccion BI_PUNTO_COMA instrucciones
  | instruccion BI_PUNTO_COMA
;

instruccion:
    BI_CONTINUAR {}
  | asignacion 
  | alternativa {

  }
  | iteracion {}
  | accion_ll {}
;

asignacion:
    operando BI_ASIGNACION expresion {
      
      if(is_arithmetic($1) && is_arithmetic($3))
      {
        #ifdef _DEBUG
        printf("ASIGNACION ARITMETICA\n");
        #endif

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
      }
      else if(is_boolean($1) && is_boolean($3))
      {
        #ifdef _DEBUG
        printf("ASIGNACION BOOLEANA\n");
        #endif

        backpatch($3->true, next_quad_qt(qt));
        backpatch($3->false, next_quad_qt(qt)+1);

        quad *q1 = new_quad_qt(ASIGNA, CTE_TRUE, NONE, $1->s->id);
        quad *q2 = new_quad_qt(ASIGNA, CTE_FALSE, NONE, $1->s->id);

        gen(qt, q1);
        gen(qt, q2);
      }          
      else 
      {  
        yyerror("ERROR. LOS TIPOS SON INCOMPATIBLES PARA LA ASIGNACION");            
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
    if(argc>1)
    {
      FILE * file = fopen(argv[1], "r" );
      if(!file)
      {
        printf("El archivo no existe\n");
        return -1;
      }
      yyin = file;

    }
    else
    {  
      yyin = stdin;
    }

    st = new_st();
    qt = new_qt();
    
    int ret;

    do{
       ret = yyparse();
    }while (!feof(yyin));

    if(ret == 0)
    {
      printf("\nCOMPILACION EXITOSA\n");
      to_string_st(st);
      to_string_qt(qt);
    }
    else
      printf("\nOCURRIÓ UN ERROR EN LA COMPILACION\n");   

    free_st(st);
    free_qt(qt);

    return 0;
}

/* Called by yyparse on error.  */
void yyerror (char const *s)
{
  fprintf (stderr, "Error en el parser (linea %d): %s\n", yylineno, s);
  exit(-1);
}