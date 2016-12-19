/*
	@descripcion Se define en esta cabecera la estructura de datos pila
	@auto Benites Fernández, Edson
*/

#ifndef __LIST_H
#define __LIST_H

#define TRUE 1
#define FALSE 0
/* Se define la estructura del nodo */
typedef struct node
{
	int val;
	struct node* next;
} node;

/* Se define la estructura de la lista */
struct list
{
	node *first, *last;
	int size;
};

typedef struct list* list;

/* Devuelve una lista vacía */
list new_list();

/* Libera la memoria ocupada por una lista*/
void free_list(list l);

/* Libera la memoria ocupada por un nodo*/
void free_node_list(node* n);

/* Crea y devuelve un nuevo nodo */
node* new_node_list();

/* Inserta un nuevo nodo en la lista */
void insert_node_list(list l, node* n);

/* Devuelve 1 si la lista está vacía y 0 en caso contrario */
int isempty_list(list l);

/* Imprime el contenido de una lista por pantalla */
void to_string_list(list l);

#endif