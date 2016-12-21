/*
	@descripcion Implementa las funciones para la estructura de datos 'lista'
	@autor Benites Fernández, Edson
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/**
 * @return: una lista vacía 
 */
list new_list()
{
	list l = (list)malloc(sizeof(list));
	l->first = NULL;
	l->last  = NULL;
	l->size  = 0; 	
}

/**
 * Libera la memoria ocupada por una lista
 */
void free_list(list l)
{
	if(is_empty_list(l))
	{
		printf("Lista vacía, la borramos\n");
		free(l);	
	}
	else
	{
		/*node* curr = l->first;
		while(curr->next != NULL)
		{
			node *curr
			free_node_list(curr);
		}
		free_node_list(curr);*/
		printf("No se implementó la liberación de memoria hacia atrás\n\n");
		free(l);
	}
	
}

/** 
 * @return: un nuevo nodo 
 */
node* new_node_list()
{
	node* n = (node*)malloc(sizeof(node*));	
	return n;
}

/**
 * Inserta un nodo en la lista 
 */
void insert_node_list(list l, node* n)
{
	if(is_empty_list(l))
	{
		l->first = n;
		l->last  = n;
		l->size  = 1;	
	}
	else
	{
		node* aux = l->last;
		aux->next = n;
		l->last   = n;
		l->size  += 1;
	}	 
}

/**
 * @return: 1 si la lista está vacía y 0 en caso contrario 
 */
int is_empty_list(list l)
{
	if(l->size == 0)
		return TRUE;
	else
		return FALSE;
}

/**
 * Imprime el contenido de una lista por pantalla 
 */
void to_string_list(list l)
{
	if(!is_empty_list(l))
	{
		node *curr = l->first;
		printf("\n\n IMPRIMIENDO LISTA ... \n\n");
		//printf("Tamaño de la lista: %d\n", l->size);
		//printf("Primero de la lista: %d\n", l->first->val);
		//printf("Último de la lista: %d\n\n", l->last->val);
		printf("INDEX\n");
		while(curr->next != NULL)
		{
			printf("%d\n",curr->index);
			curr = curr->next;
		}
		printf("%d\n", curr->index);
	}
	else
	{
		printf("\n\n LISTA VACIA ... \n\n");
	}
}
