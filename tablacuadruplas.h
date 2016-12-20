/*
	@descripcion En esta cabecera se define la estructura la tabla de cuadruplas.
	Definimos una cuadrupla con una estructura compuesta de la siguiente manera
	<operator, operand1, operand2, result> donde:
		-operator: es un operador
		-operand1: es el primer operador
		-operand2: es el segundo operador
		-result:   es el resultado de la operación
		-next:     es un puntero a la siguiente cuadrupla
	
	@autor Benites Fernández, Edson	        
*/

#ifndef CB_TABLACUADRUPLAS_H
#define CB_TABLACUADRUPLAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util/list.c"

/* Se define la estructura la cuadrupla */
typedef struct quad{
	int operator;
	int operand1;
	int operand2;
	int result;
	struct quad *next;
}quad;

/* Se define la estructura la tabla de cuadruplas */
struct quad_table{
	quad *first;
	quad *last;
	int size;
};

/* Se define el tipo quad_table como un puntero a la estructura quad_table */
typedef struct quad_table* quad_table;

/////////////////////////////////////////

/**
 * @return: tabla de cuadruplas vacía
 */
quad_table new_qt();


/**
 * Inserta una cuadrupla en la tabla de cuadruplas
 * @param qt: tabla de cuadruplas
 * @param q:  cuadrupla a insertar
 */
void gen(quad_table qt, quad *q);


/**
 * @return: devuelve una cuadrupla
 */
quad* create_new_quad(int operator, int operand1, int operand2, int result);


/**
 * @return: devuelve el índice de la siguiente cuadrupla
 */
int next_quad(quad_table qt);

/**
 * @return: devuelve una lista con id de quad 
 */
list makelist(int quad);


/**
 * @param l1: primera lista
 * @param l2: segunda lista
 * @return: devuelve una lista que contiene los elementos de l1 y l2
 */
list merge(list l1, list l2);


/**
 * Completa las quadruplas de la lista para que salten a la cuadrupla especificada
 * @param l: lista
 * @param quad: id de quad 
 */
void backpatch(list l, int quad);


/**
 * Comprueba si la tabla de cuadruplas esta vacía
 */
int is_empty_qt(quad_table qt);


/**
 * Imprime el contenido de la tabla de cuadruplas por pantalla 
 */
void to_string_qt(quad_table qt);


#endif
