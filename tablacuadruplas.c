#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablacuadruplas.h"


/**
 * @return: tabla de cuadruplas vacía
 */
quad_table new_qt()
{
	quad_table qt = malloc(sizeof(quad_table));

	if(qt == NULL)
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}

	qt->first = NULL;
	qt->last  = NULL;
	qt->size  = 0;

	return qt;
}


/**
 * Inserta una cuadrupla en la tabla de cuadruplas
 * @param qt: tabla de cuadruplas
 * @param q:  cuadrupla a insertar
 */
void gen(quad_table qt, quad *q)
{
	if(is_empty_qt(qt))
	{
		qt->first = q;
		qt->last  = q;
		qt->size += 1;
	}
	else
	{
		qt->last->next = q;		
		qt->last       = q;
		qt->size      += 1;
	}
	#ifdef _DEBUG
		printf("_______ QUAD INSERTADO _______\n");
		to_string_qt(qt);
	#endif
}


/**
 * @return: devuelve una cuadrupla
 */
quad* new_quad_qt(int operator, int operand1, int operand2, int result)
{
	quad *q = malloc(sizeof(quad));

	if(q == NULL)
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}

	q->operator = operator;
	q->operand1 = operand1;
	q->operand2 = operand2;
	q->result   = result;
	q->next     = NULL;

	return q;
}


/**
 * @return: devuelve el índice de la siguiente cuadrupla
 */
int next_quad_qt(quad_table qt)
{
	return qt->size+1;
}

/**
 * @return: devuelve una lista con id de quad
 */
list makelist(int quad)
{
	list l  = malloc(sizeof(list));
	node *n = malloc(sizeof(node));

	n->index = quad;
	n->next  = NULL;

	l->first = n;
	l->last  = n;
	l->size  = 1;

	return l;		
}


/**
 * @param l1: primera lista
 * @param l2: segunda lista
 * @return: devuelve una lista que contiene los elementos de l1 y l2
 */
list merge(list l1, list l2)
{
	/* Reutilizamos l1, pero únicamente en el caso de que ya no volvamos a usar l1. 
	   En el caso de que aún necesitaramos usarlo, creamos una nuvea lista y realizamos
	   el merge de l1 y l2 */
	//list l = malloc(sizeof(list));

	l1->last->next = l2->first;
	l1->last       = l2->last;
	//l->first       = l1->first;
	//l->last        = l1->last;
	return l1;
}


/**
 * Completa las quadruplas de la lista para que salten a la cuadrupla especificada
 * @param l: lista
 * @param quad: id de quad 
 */
void backpatch(list l, int quad)
{
	
}


/**
 * Comprueba si la tabla de cuadruplas esta vacía
 */
int is_empty_qt(quad_table qt)
{
	if(qt->first == NULL || qt->last == NULL || qt->size == 0)
		return TRUE;
	else
		return FALSE;
}

/**
 * Libera la tabla de cuadruplas
 * @param qt: tabla de cuadruplas
 */
void free_qt(quad_table qt)
{
	if(is_empty_qt(qt))
	{
		free(qt);
	}
	else
	{
		free_quads_qt(qt->first);
		free(qt);
	}
}

/**
 * Libera la memoria ocupada por las cuadruplas
 * @param q: primera cuadrupla
 */
void free_quads_qt(quad *q)
{
	if(q->next == NULL)
	{
		free(q);
	}
	else
	{
		free_quads_qt(q->next);
		free(q);
	}
}

/**
 * Imprime el contenido de la tabla de cuadruplas por pantalla 
 */
void to_string_qt(quad_table qt)
{
	if(!is_empty_qt(qt))
	{
		quad *curr = qt->first;
		printf("\n\n IMPRIMIENDO TABLA DE CUADRUPLAS ... \n\n");
		printf("Tamaño: %d\n\n", qt->size);
		//printf("Primero: %d\n", st->first->val);
		//printf("Último: %d\n\n", st->last->val);
		printf("OPERATOR\tOPERAND1\tOPERAND2\tRESULT\n\n");

		while(curr->next != NULL)
		{
			printf("\t%d\t%d\t%d\t%d\n",curr->operator, curr->operand1, curr->operand2, curr->result);
			curr = curr->next;
		}
		printf("\t%d\t%d\t%d\t%d\n\n",curr->operator, curr->operand1, curr->operand2, curr->result);
	}
	else
	{
		printf("\n\n TABLA DE CUADRUPLAS VACIA ... \n\n");
	}
}



