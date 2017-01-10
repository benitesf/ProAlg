/*
	@descripcion En esta cabecera se define la macro para definir la estructura
	exp_a_b		
	
	@autor Benites Fernández, Edson
	@autor Catalan Vitas, Daniel	        
*/

#ifndef CB_EXP_A_B_H
#define CB_EXP_A_B_H

#include "util.h"	
#include "tablasimbolos.h"
#include "tablacuadruplas.h"


/* Estructura exp_a_b, para las expresiones que pueden ser aritméticas o booleanas */
typedef struct exp_a_b
{
	int ar;
	int bol;
	symbol *s;
	list true;
	list false;
}exp_a_b;


/**
 *
 * @return: devuelve una estructura exp_a_b
 */
exp_a_b* new_exp_a_b();

/**
 *
 * @return: devuelve una estructura exp_a_b para manejar aritméticos
 */
exp_a_b* new_exp_a();

/**
 *
 * @return: devuelve una estructura exp_a_b para manejar booleanos
 */
exp_a_b* new_exp_b(); 	

/**
 *
 * Convierte a aritmetico
 */
int set_arithmetic(exp_a_b *ex);

/**
 *
 * Convierte a booleano
 */
int set_boolean(exp_a_b *ex);

/**
 *
 * @return: TRUE si es una estructura para expresiones aritméticas
 */
int is_arithmetic();

/**
 *
 * @return: TRUE si es una estructura para expresiones booleanas
 */
int is_boolean(); 	
#endif