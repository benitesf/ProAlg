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
	//st->pila  = new_list();
	st->size  = 0;
	st->flag  = OFF;
	
	#ifdef _DEBUG
		printf("_______ NUEVA TABLA DE SIMBOLOS CREADA _______\n");
		to_string_st(st);		
	#endif

	return st;
}

/** 
 * @return Devuelve un simbolo con nombre pasado como parámetro, y de tipo NONE
 */
symbol* new_symbol_st(char *name)
{
	symbol *new_symbol = malloc(sizeof(symbol));

	if(new_symbol != NULL)
	{
		new_symbol->name = name;
		new_symbol->type = NONE;

		return new_symbol;
	}
	else
	{
		fprintf(stderr, "failed to allocate memory.\n");
        exit(-1);
	}
}

/** 
 * Inserta un símbolo en la tabla de simbolos
 * @param st: la tabla de símbolos
 * @param name: nombre del símbolo 
 */
void insert_symbol_st(symbol_table st, symbol *s)
{		
	/*#ifdef _DEBUG
		printf("_______ SE VA A INSERTAR UN NUEVO SIMBOLO _______\n");
		to_string_st(st);		
	#endif*/

	s->id = st->size + 1;	

	if(is_empty_st(st))
	{
		st->first = s;
		st->last  = s;
		st->size  = 1;
	}
	else
	{
		st->last->next = s;		
		st->last       = s;
		st->size += 1;
	}
	#ifdef _DEBUG
		printf("_______ SE HA INSERTADO UN NUEVO SIMBOLO _______\n");
		to_string_st(st);		
	#endif
	
}

/**
 * @param st: tabla de símbolos
 * @param id: identificador de símbolo
 * @return: devuelve TRUE si existe símbolo con el nombre pasado como párametro 
 * y FALSE en caso contrario 
 */
int exists_name_symbol_st(symbol_table st, char *name)
{
	if(is_empty_st(st))
	{	
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
 * @param st: tabla de símbolos
 * @param name: nombre único del símbolo
 * @return: símbolo con nombre pasado por parámetro
 */
symbol* get_symbol_st(symbol_table st, char *name)
{
	if(exists_name_symbol_st(st, name))
	{
		symbol *curr = st->first;

		while(curr->next != NULL)
		{
			if(strcmp(curr->name, name) == 0)
				return curr;

			curr = curr->next;
		}

		if(strcmp(curr->name, name) == 0)
			return curr;
	}
	else
	{
		fprintf(stderr, "Error, el símbolo no existe en la tabla de símbolos.\n");
        exit(-1);
	}
}

/**
 * Actualiza los tipos de los últimos símbolos introducidos, ya que no disponen de uno. 
 * @param st: tabla de símbolos
 * @param type: tipo del símbolo
 */
void set_type_st(symbol_table st, int type)
{	
/*#ifdef _DEBUG
	printf("_______ SE VA A MODIFICAR LOS TIPOS -1 _______\n");
	to_string_st(st);
#endif	*/
	if(!is_empty_st(st))
	{
		symbol *aux = st->first;

		while(aux->next != NULL)
		{
			if(aux->type == NONE)
				aux->type = type;

			aux = aux->next;
		}

		if(aux->type == NONE)
			aux->type = type;
	}

#ifdef _DEBUG
	printf("_______ SE HA MODIFICADO LOS TIPOS DE LA ST _______\n");
	to_string_st(st);
#endif	
}

/** 
* Crea un símbolo temporal, lo inserta y,
* finalmente lo devuelve.
* @param st: tabla de símbolos
* @return symbol: un símbolo
*/
/*symbol new_temp_st(symbol_table st)
{
	char *name = "temp";
	insert_symbol_st(st, name);
}*/
  	
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
* @param st: tabla de símbolos
* @param flag: activa o desactiva el flag de la tabla de simbolos
*/
void set_flag_st(symbol_table st, int flag)
{
	st->flag = flag;
}

/**
* @param st: tabla de símbolos
* @return: devuelve el flag de la tabla de simbolos
*/
int get_flag_st(symbol_table st)
{
	return st->flag;
}

/**
 * Libera la tabla de símbolos
 * @param st: tabla de símbolos
 */
void free_st(symbol_table st)
{	
	if(is_empty_st(st))
	{		
		free(st);
	}
	else
	{
		free_symbols_st(st->first);
		free(st);
	}
}

/**
 * Libera la memoria ocupada por los simbolos
 * @param s: primer simbolo
 */
void free_symbols_st(symbol *s)
{
	if(s->next == NULL)
	{
		free(s);
	}
	else
	{
		free_symbols_st(s->next);
		free(s);
	}
}

/**
 * Deja la pila vacía
 * @param st
 */
/*void free_pila_st(list p)
{
	if(!is_empty_list(p))
	{
		free_nodes_list(p->first);
		p->first = NULL;
		p->last  = NULL;
		p->size  = 0;
	}	
}*/

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
		printf("flag: %d\n\n", st->flag);
		//printf("Primero: %d\n", st->first->val);
		//printf("Último: %d\n\n", st->last->val);
		printf("ID\tNAME\tTYPE\tVALUE\n\n");

		while(curr->next != NULL)
		{
			if(curr->type == TIPOENTERO)
			{
				printf("%d\t%s\t%d\t%d\n",curr->id, curr->name, curr->type, curr->value.inte);
			}
			else if(curr->type == TIPOREAL)
			{
				printf("%d\t%s\t%d\t%f\n",curr->id, curr->name, curr->type, curr->value.floa);	
			}
			else if(curr->type == TIPOCADENA)
			{
				printf("%d\t%s\t%d\t%s\n",curr->id, curr->name, curr->type, curr->value.string);
			}
			else if(curr->type == TIPOCARACTER)
			{
				printf("%d\t%s\t%d\t%c\n",curr->id, curr->name, curr->type, curr->value.chara);
			}
			else if(curr->type == TIPOBOOLEANO)
			{
				printf("%d\t%s\t%d\t%d\n",curr->id, curr->name, curr->type, curr->value.bool);
			}
			
			curr = curr->next;
		}
		if(curr->type == TIPOENTERO)
		{
			printf("%d\t%s\t%d\t%d\n",curr->id, curr->name, curr->type, curr->value.inte);
		}
		else if(curr->type == TIPOREAL)
		{
			printf("%d\t%s\t%d\t%f\n",curr->id, curr->name, curr->type, curr->value.floa);	
		}
		else if(curr->type == TIPOCADENA)
		{
			printf("%d\t%s\t%d\t%s\n",curr->id, curr->name, curr->type, curr->value.string);
		}
		else if(curr->type == TIPOCARACTER)
		{
			printf("%d\t%s\t%d\t%c\n",curr->id, curr->name, curr->type, curr->value.chara);
		}
		else if(curr->type == TIPOBOOLEANO)
		{
			printf("%d\t%s\t%d\t%d\n",curr->id, curr->name, curr->type, curr->value.bool);
		}
	}
	else
	{
		printf("\n\n TABLA DE SIMBOLOS VACIA ... \n\n");
	}
}

