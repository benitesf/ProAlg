#include "list.h"
#include "list.c"

int main(void)
{	
	list l;
	node *n1, *n2, *n3;

	l = new_list();
	n1 = new_node_list();
	n2 = new_node_list();
	n3 = new_node_list();

	n1->val  = 1;
	n1->next = NULL;

	n2->val  = 2;
	n2->next = NULL;

	n3->val  = 3;
	n3->next = NULL;	
	
	insert_node_list(l, n1);
	insert_node_list(l, n2);
	insert_node_list(l, n3);

	to_string_list(l);

	free_node_list(n1);
	free_node_list(n2);
	free_node_list(n3);
	free_list(l);
	return 0;
}