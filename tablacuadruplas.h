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
	@autor Catalan Vitas, Daniel	        
*/

#ifndef CB_TABLACUADRUPLAS_H
#define CB_TABLACUADRUPLAS_H

#include "util.h"

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

/* Se define la estrucutra de nodo*/
typedef struct node{
	quad *q;
	struct node *next;
}node;

/* Se define la estructura de lista*/
struct list{
	node *first, *last;
	int size;
};

/* Se define el tipo quad_table como un puntero a la estructura quad_table */
typedef struct quad_table* quad_table;

/* Se define el tipo lista a quad */
typedef struct list* list;

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
quad* new_quad_qt(int operator, int operand1, int operand2, int result);


/**
 * @return: devuelve el índice de la siguiente cuadrupla
 */
int next_quad_qt(quad_table qt);

/**
 * @return: devuelve una lista con 
 */
list makelist(quad *q);


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
void backpatch(list l, int q);


/**
 * Comprueba si la tabla de cuadruplas esta vacía
 */
int is_empty_qt(quad_table qt);

/**
 * Libera la tabla de cuadruplas
 * @param qt: tabla de cuadruplas
 */
void free_qt(quad_table qt);

/**
 * Libera la memoria ocupada por las cuadruplas
 * @param q: primera cuadrupla
 */
void free_quads_qt(quad *q);


/**
 * Imprime el contenido de la tabla de cuadruplas por pantalla 
 */
void to_string_qt(quad_table qt);


//////////////////////////////////////////////////////////////////
/* Funciones para las listas */

/**
 * @return: una lista vacía 
 */
//list new_list();

/**
 * recive una lista y la devuelve vacía
 * @return: una lista vacía 
 */
//list empty_list(list l);

/**
 * Libera la memoria ocupada por una lista
 */
void free_list(list l);

/**
 * Libera la memoria ocupada por los nodos
 */
//void free_nodes_list(node *n);

/** 
 * @return: un nuevo nodo 
 */
//node* new_node_list();

/**
 * Inserta un nodo en la lista 
 */
//void insert_node_list(list l, node* n);

///////// Podemos usar la lista como una pila

/* Insertamos un nuevo nodo en la lista*/
//void push(list l, int i);

/* Retorna el index del primer elemento de la lista */
//int pop(list l);


/**
 * @return: 1 si la lista está vacía y 0 en caso contrario 
 */
int is_empty_list(list l);

/**
 * @return: 1 si la lista no es null
 */
 int is_null_list(list l);

/**
 * Imprime el contenido de una lista por pantalla 
 */
void to_string_list(list l);


#endif
