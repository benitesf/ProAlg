#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablasimbolos.h"


/** 
 * @return Devuelve una tabla de símbolos
 */
symbol_table new_st()
{
	symbol_table st = malloc(sizeof(symbol_table));

	if(st == NULL)
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}		
	
	st->first = NULL;
	st->last  = NULL;
	st->size  = 0;
	
	return st;
}

/** 
 * Inserta un símbolo en la tabla de simbolos
 * @param st: la tabla de símbolos
 * @param name: nombre del símbolo 
 */
void insert_symbol_st(symbol_table st, char *name)
{
	symbol *new_symbol = malloc(sizeof(symbol));

	if(new_symbol != NULL)
	{		
		new_symbol->id   = st->size + 1;
		new_symbol->name = name;
		new_symbol->type = NONE;

		if(is_empty_st(st))
		{
			st->first = new_symbol;
			st->last  = new_symbol;
			st->size  = 1;
		}
		else
		{
			symbol *curr = st->last;
			curr->next   = new_symbol;
			st->last     = new_symbol;
			st->size += 1;
		}
	}
	else
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}
	
}

/**
 * @param st: tabla de símbolos
 * @param id: identificador de símbolo
 * @return: devuelve TRUE si existe símbolo con id pasado como párametro 
 * y FALSE en caso contrario 
 */
int exists_symbol_st(symbol_table st, char *name)
{
	if(is_empty_st(st))
	{
		printf("empty table...\n");
		return FALSE;
	}
	else
	{
		symbol *aux = st->first;

		while(aux->next != NULL)
		{
			if(strcmp(aux->name, name) == 0)
				return TRUE;

			aux = aux->next;
		}

		if(strcmp(aux->name, name) == 0)
			return TRUE;
	}

	return FALSE;
}

/**
 * Actualiza los tipos de los últimos símbolos introducidos, ya que no disponen de uno. 
 * @param st: tabla de símbolos
 * @param type: tipo del símbolo
 */
void set_type_st(symbol_table st, int type)
{
	if(!is_empty_st(st))
	{
		symbol *aux = st->first;

		while(aux->next != NULL)
		{
			if(aux->type == NONE)
				aux->type = type;

			aux = aux->next;
		}

		if(aux->type != NONE)
			aux->type = type;
	}
}

/** 
* Crea un símbolo temporal, lo inserta y,
* finalmente lo devuelve.
* @param st: tabla de símbolos
* @return symbol: un símbolo
*/
symbol new_temp_st(symbol_table st)
{
	char *name = "temp";
	insert_symbol_st(st, name);
}
  	
/**
* @param st: tabla de símbolos
* @return: Devuelve TRUE si la tabla de símbolos está vacía, y FALSE en caso contrario 
*/
int is_empty_st(symbol_table st)
{
	if(st->first == NULL || st->last == NULL || st->size == 0)
		return TRUE;
	else
		return FALSE;
}


/**
 * Libera la tabla de símbolos
 * @param st: tabla de símbolos
 */
void free_st(symbol_table st)
{	
	free(st);
	/*if(is_empty_st(st))
	{
		free(st);
	}
	else if(st->size == 1)
	{
		free(st->first);
		free(st);
	}
	else if(st->size > 1)
	{
		symbol *aux1 = st->first;
		symbol *aux2 = aux1->next;
		int cont = 1;		
		while(aux2->next != NULL)
		{
			free(aux1);			
			symbol *aux1 = aux2;
			aux2         = aux2->next;
		}

		free(aux1);
		free(aux2);		
		free(st);
	}*/
}

/** 
 * Imprime el contenido de una tabla de símbolos por pantalla 
 * @param st: tabla de símbolos
 */
void to_string_st(symbol_table st)
{
	if(!is_empty_st(st))
	{
		symbol *curr = st->first;
		printf("\n\n IMPRIMIENDO TABLA DE SIMBOLOS ... \n\n");
		printf("Tamaño: %d\n\n", st->size);
		//printf("Primero: %d\n", st->first->val);
		//printf("Último: %d\n\n", st->last->val);
		printf("ID\tNAME\tTYPE\n\n");

		while(curr->next != NULL)
		{
			printf("%d\t%s\t%d\n",curr->id, curr->name, curr->type);
			curr = curr->next;
		}
		printf("%d\t%s\t%d\n\n",curr->id, curr->name, curr->type);
	}
	else
	{
		printf("\n\n TABLA DE SIMBOLOS VACIA ... \n\n");
	}
}
