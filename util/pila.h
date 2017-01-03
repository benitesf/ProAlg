/*
	@descripcion Se define la estructura de datos 'pila' para enteros
	@autor Benites Fernández, Edson
*/

#ifndef __PILA_H
#define __PILA_H

#include "../util.h"

/* Se define la estructura de node */
typedef struct node
{
	int index;
	struct node* next;
} node;

/* Se define la estructura de list */
struct pila
{
	node *first, *last;
	int size;
};

typedef struct pila* pila;

///////////////////////////////////////////////

/**
 * @return: una pila vacía 
 */
pila new_pila();

/**
 * Libera la memoria ocupada por la pila
 */
void free_pila(pila p);

/**
 * Libera la memoria ocupada por los nodos
 */
void free_nodes_pila(node *n);

/** 
 * @return: un nuevo nodo 
 */
node* new_node_list();

/**
 * Inserta un nodo en la lista 
 */
void insert_node_list(list l, node* n);

/**
 * @return: 1 si la lista está vacía y 0 en caso contrario 
 */
int is_empty_list(list l);

/**
 * Imprime el contenido de una lista por pantalla 
 */
void to_string_list(list l);
#endif 