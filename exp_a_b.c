#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exp_a_b.h"

/**
 *
 * @return: devuelve una estructura exp_a_b
 */
exp_a_b* new_exp_a_b()
{
	exp_a_b *ex = malloc(sizeof(exp_a_b));

	if(ex == NULL)
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}

	return ex;	
}

/**
 *
 * @return: devuelve una estructura exp_a_b para manejar aritméticos
 */
exp_a_b* new_exp_a()
{
	exp_a_b *ex = malloc(sizeof(exp_a_b));

	if(ex == NULL)
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}

	ex->ar    = TRUE;
	ex->bol   = FALSE;
	ex->true  = NULL;
	ex->false = NULL;

	return ex;
}

/**
 *
 * @return: devuelve una estructura exp_a_b para manejar booleanos
 */
exp_a_b* new_exp_b()
{
	exp_a_b *ex = malloc(sizeof(exp_a_b));

	if(ex == NULL)
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}

	ex->ar    = FALSE;
	ex->bol   = TRUE;
	ex->true  = NULL;
	ex->false = NULL;

	return ex;	
}

/**
 *
 * Convierte a aritmetico
 */
int set_arithmetic(exp_a_b *ex)
{
	ex->ar    = TRUE;
	ex->bol   = FALSE;
}

/**
 *
 * Convierte a booleano
 */
int set_boolean(exp_a_b *ex)
{
	ex->ar    = FALSE;
	ex->bol   = TRUE;
}

/**
 *
 * @return: TRUE si es una estructura para expresiones aritméticas
 */
int is_arithmetic(exp_a_b *e)
{
	return e->ar == TRUE? TRUE: FALSE;
}

/**
 *
 * @return: TRUE si es una estructura para expresiones booleanas
 */
int is_boolean(exp_a_b *e)
{
	return e->bol == TRUE? TRUE: FALSE;
}