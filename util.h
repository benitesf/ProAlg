/*
	@descripcion En esta cabecera se definen macros para definir la estructura
	exp_a_b, TRUE, FALSE.		
	
	@autor Benites Fernández, Edson
	@autor Catalan Vitas, Daniel	        
*/

#ifndef CB_UTIL_MACROS_H
#define CB_UTIL_MACROS_H

/* Macros booleanas */
#define TRUE 1
#define FALSE 0

/* FLAGS */
#define NONE -1   // simbolos sin tipos
#define NOGOTO -2 // saltos no definidos

/* Macro para desactivar flags */
#define OFF -10	

/* Macros de strings */
#define TEMP "temp"

/*  MACROS DE TIPOS*/
#define TIPOENTERO 1
#define TIPOBOOLEANO 2
#define TIPOCARACTER 3
#define TIPOREAL 4
#define TIPOCADENA 5

/* MACROS DE OPERACIONES ARITMETICAS*/	
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

/* MACROS DE OPERACIONES BOOLEANAS*/	
#define MENOSOP 18
#define MAYOR 25
#define MENOR 26
#define MAYOR_IGUAL 27
#define MENOR_IGUAL 28
#define DISTINTO 29
#define IGUAL 30

/* MACRO DE ASIGNACION */	
#define ASIGNA 19

/* MACRO DE CONVERSION */
#define INT2REA 20
#define REA2INT 21

/* MACRO DE SALTO INCONDICIONAL Y CONDICIONAL */
#define GOTO 22

/* CONSTANTES TRUE Y FALSE */	
#define CTE_TRUE 23
#define CTE_FALSE 24




#endif