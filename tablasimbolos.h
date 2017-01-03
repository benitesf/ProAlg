/*
	@descripcion En esta cabecera se define la estructura la tabla de simbolos.
	Definimos un símbolo con una estructura compuesta de la siguiente manera
	<id , name, type, value(union), next> donde:
		-id:    es el identificador de un único símbolo.
		-name:  es el nombre del símbolo. 
		-type:  es el tipo del símbolo.
		-value: es un union, que puede tener distintos valores (de momento 1)
		-next:  es un puntero a la siguiente simbolo.
	
	@autor Benites Fernández, Edson	        
*/

#ifndef CB_TABLASIMBOLOS_H
#define CB_TABLASIMBOLOS_H

#include "util.h"
#include "util/list.h"
/* Define el valor que se le asigna a un símbolo cuando no tiene tipo*/
//#define NONE -1

/* Define valores booleanos*/
//#define TRUE  1
//#define FALSE 0

/* Se define la estructura symbol */
typedef struct symbol{
	int  id;
	char *name;				     
	int  type;						     
	union{
		int   inte;
		int   bool;
		float floa;
		char  chara;
		char *string;		
	}value;
	struct symbol *next;  
}symbol;

/* Se define el tipo símbolo como un puntero a node */
//typedef struct node* symbol;

/* Se define la estructura symbol_table */
struct symbol_table{
	symbol *first, *last;
	//list pila;
	int size;
	int flag;
};

/* Se define el tipo symbol_table como un puntero a symbol_table*/
typedef struct symbol_table* symbol_table;

////////////////////////////////////

/** 
 * @return Devuelve una tabla de símbolos
 */
symbol_table new_st();


/** 
 * @return Devuelve un simbolo con nombre pasado como parámetro, y de tipo NONE
 */
symbol* new_symbol_st(char *name);

/** 
 * Inserta un símbolo en la tabla de simbolos
 * @param st: la tabla de símbolos
 * @param name: nombre del símbolo 
 */
void insert_symbol_st(symbol_table st, symbol *s);

/**
 * @param st: tabla de símbolos
 * @param name: nombre único del símbolo
 * @return: devuelve TRUE si existe símbolo con el nombre pasado como párametro 
 * y FALSE en caso contrario 
 */
int exists_name_symbol_st(symbol_table st, char *name);

/**
 * @param st: tabla de símbolos
 * @param name: nombre único del símbolo
 * @return: símbolo con nombre pasado por parámetro
 */
symbol* get_symbol_st(symbol_table st, char *name);

/**
 * @param st: tabla de símbolos
 * @param id: identificador de símbolo
 * @return: devuelve un símbolo con id pasado como parámetro,
 * en caso de que no exista, devuelve NULL
 */
//symbol get_symbol_st(symbol_table st, int id);


/**
 * Actualiza los tipos de los últimos símbolos introducidos, ya que no disponen de uno. 
 * @param st: tabla de símbolos
 * @param type: tipo del símbolo
 */
void set_type_st(symbol_table st, int type);


/** 
* Crea un símbolo temporal, lo inserta y,
* finalmente lo devuelve.
* @param st: tabla de símbolos
* @return symbol: un símbolo
*/
//symbol new_temp_st(symbol_table st);


/**
* @param st: tabla de símbolos
* @return: Devuelve TRUE si la tabla de símbolos está vacía, y FALSE en caso contrario 
*/
int is_empty_st(symbol_table st);

/**
* @param st: tabla de símbolos
* @param flag: activa o desactiva el flag de la tabla de simbolos
*/
void set_flag_st(symbol_table st, int flag);

/**
* @param st: tabla de símbolos
* @return: devuelve el flag de la tabla de simbolos
*/
int get_flag_st(symbol_table st);

/**
 * Libera la tabla de símbolos
 * @param st: tabla de símbolos
 */
void free_st(symbol_table st);

/**
 * Libera la memoria ocupada por los simbolos
 * @param s: primer simbolo
 */
void free_symbols_st(symbol *s);

/**
 * Deja la pila vacía
 * @param st
 */
//void free_pila_st(list p);

/** 
 * Imprime el contenido de una tabla de símbolos por pantalla 
 * @param st: tabla de símbolos
 */
void to_string_st(symbol_table st);

#endif
