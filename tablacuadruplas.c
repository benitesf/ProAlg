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
	quad *aux = qt->last;
	aux->next = q;	
	qt->last = q;
}


/**
 * @return: devuelve una cuadrupla
 */
quad* create_new_quad(int operator, int operand1, int operand2, int result)
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

	return q;
}


/**
 * @return: devuelve el índice de la siguiente cuadrupla
 */
int next_quad(quad_table qt)
{
	return qt->size+1;
}

/**
 * @return: devuelve una lista con id de quad 
 */
list makelist(int quad)
{

}


/**
 * @param l1: primera lista
 * @param l2: segunda lista
 * @return: devuelve una lista que contiene los elementos de l1 y l2
 */
list merge(list l1, list l2)
{

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

}


/**
 * Imprime el contenido de la tabla de cuadruplas por pantalla 
 */
void to_string_qt(quad_table qt)
{

}



