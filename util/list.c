/*
	@descripcion Implementa las funciones para la estructura de datos 'lista'
	@autor Benites Fernández, Edson
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * @return: una lista vacía 
 */
list new_list()
{
	list l   = malloc(sizeof(list));
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
		node *curr = l->first;		
		free_nodes_list(curr);		
		free(l);							
	}
}

/**
 * Libera la memoria ocupada por los nodos recursivamente
 */
void free_nodes_list(node *n)
{
	if(n->next == NULL)
	{
		free(n);
	}
	else
	{
		free_nodes_list(n->next);
		free(n);		
	}		
}

/** 
 * @return: un nuevo nodo 
 */
node* new_node_list()
{
	node *n = malloc(sizeof(node));	
	return n;
}

/**
 * Inserta un nodo en la lista 
 */
void insert_node_list(list l, node *n)
{
	if(is_empty_list(l))
	{
		l->first = n;
		l->last  = n;
		l->size  = 1;	
	}
	else
	{
		node *aux = l->last;
		aux->next = n;
		l->last   = n;
		l->size  += 1;
	}	 
}

///////// Podemos usar la lista como una pila

/* Insertamos un nuevo nodo en la lista*/
void push(list l, int i)
{
	node *n = new_node_list();
	n->index = i;

	if(is_empty_list(l))
	{		
		l->first = n;
		l->last  = n;
		l->size  = 1;
	}
	else
	{
		n = l->first;
		l->first = n;
		l->size += 1;
	}
}

/* Retorna el primer elemento de la lista */
int pop(list l)
{
	if(!is_empty_list(l))
	{
		node *n = l->first;
		l->first = n->next;
		l->size -= 1;
		return n->index;
	}
	else
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}
}

/**
 * @return: 1 si la lista está vacía y 0 en caso contrario 
 */
int is_empty_list(list l)
{
	if(l->size == 0 || l->first == NULL || l->last == NULL)
		return TRUE;
	else
		return FALSE;
}

/**
 * @return: 1 si la lista no es null
 */
 int is_null_list(list l)
 {
 	return l==NULL? TRUE:FALSE;
 }

/**
 * Imprime el contenido de una lista por pantalla 
 */
void to_string_list(list l)
{	
	if(!is_null_list(l))
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
			printf("%d\n\n", curr->index);
		}
		else
		{
			printf("\n\n LISTA VACIA ... \n\n");
		}	
	}
	else
	{
		printf("\n\n ERROR. LA LISTA ES NULA ... \n\n");
	}
	
}
