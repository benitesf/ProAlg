/*
	@descripcion Se define en esta cabecera la estructura de datos pila
	@auto Benites Fernández, Edson
*/

#ifndef __LIST_H
#define __LIST_H

#include "../util.h"
	
/* Se define la estructura de node */
typedef struct node
{
	int index;
	struct node* next;
} node;

/* Se define la estructura de list */
struct list
{
	node *first, *last;
	int size;
};

typedef struct list* list;

///////////////////////////////////////////////

/**
 * @return: una lista vacía 
 */
list new_list();

/**
 * Libera la memoria ocupada por una lista
 */
void free_list(list l);

/**
 * Libera la memoria ocupada por los nodos
 */
void free_nodes_list(node *n);

/** 
 * @return: un nuevo nodo 
 */
node* new_node_list();

/**
 * Inserta un nodo en la lista 
 */
void insert_node_list(list l, node* n);

///////// Podemos usar la lista como una pila

/* Insertamos un nuevo nodo en la lista*/
void push(list l, int i);

/* Retorna el index del primer elemento de la lista */
int pop(list l);


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