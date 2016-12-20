#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tablasimbolos.h"
#include "../tablasimbolos.c"

int main(void)
{
	symbol_table st;

	st = new_st();
	insert_symbol_st(st, "lol");
	insert_symbol_st(st, "loco");
	insert_symbol_st(st, "doco");
	to_string_st(st);
	free_st(st); 	

	return 0;
}