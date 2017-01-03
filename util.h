/*
	@descripcion En esta cabecera se definen macros para definir la estructura
	exp_a_b, TRUE, FALSE.		
	
	@autor Benites Fernández, Edson	        
*/

#ifndef CB_UTIL_MACROS_H
#define CB_UTIL_MACROS_H

/* Macros booleanas */
#define TRUE 1
#define FALSE 0

/* Macro para definir un simbolo sin tipo */
#define NONE -1

/* Flag para asignacion */
#define ASIG_INT -11
#define ASIG_FLO -12
#define ASIG_CHA -13
#define ASIG_CAD -14
#define ASIG_BOO -15

/* Macros de strings */
#define TEMP "temp"

/*  MACROS */
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
#define REA2INT 17
#define MENOSOP 18
#define ASIGNA 19

/* Macro para desactivar flags */
#define OFF -10	

#endif