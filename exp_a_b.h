/*
	@descripcion En esta cabecera se define la macro para definir la estructura
	exp_a_b		
	
	@autor Benites Fernández, Edson	        
*/

#ifndef CB_EXP_A_B_H
#define CB_EXP_A_B_H

#include "util/list.h"
#include "tablasimbolos.h"	

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
 * @return: devuelve una estructura exp_a_b para manejar aritméticos
 */
exp_a_b* new_exp_a();

/**
 *
 * @return: devuelve una estructura exp_a_b para manejar booleanos
 */
exp_a_b* new_exp_b(); 	

#endif