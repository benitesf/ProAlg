#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#include "../tablacuadruplas.h"
#include "../tablasimbolos.h"

int main(void)
{	
#ifdef LIST	
	list l;
	node *n1, *n2, *n3;

	l = new_list();
	n1 = new_node_list();
	n2 = new_node_list();
	n3 = new_node_list();

	n1->index  = 1;
	n1->next   = NULL;

	n2->index  = 2;
	n2->next   = NULL;

	n3->index  = 3;
	n3->next   = NULL;	
	
	insert_node_list(l, n1);
	insert_node_list(l, n2);
	insert_node_list(l, n3);

	to_string_list(l);
	
	free_list(l);
#endif

#ifdef QUAD
	quad_table qt;
	quad *q1, *q2, *q3;

	qt = new_qt();
	q1 = new_quad_qt(1,2,3,4);
	q2 = new_quad_qt(5,6,7,8);
	q3 = new_quad_qt(9,10,11,12);

	gen(qt, q1);
	gen(qt, q2);
	gen(qt, q3);

	to_string_qt(qt);

	free_qt(qt);
#endif	

#ifdef SYMBOL
	symbol_table st;
	symbol *s1, *s2, *s3;

	st = new_st();
	s1 = new_symbol_st("Primer Simbolo");
	s2 = new_symbol_st("Segundo Simbolo");
	s3 = new_symbol_st("Tercer Simbolo");	

	insert_symbol_st(st, s1);
	insert_symbol_st(st, s2);
	insert_symbol_st(st, s3);

	to_string_st(st);

	free_st(st);
#endif	
	
	return 0;
}