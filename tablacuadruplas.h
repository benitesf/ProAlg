#ifndef CB_TABLACUADRUPLAS_H
#define CB_TABLACUADRUPLAS_H
#define ROWS 100
#define COLS 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TablaQuad{

	int **quads;
	int nextQuad;

} TablaQuad;

TablaQuad *nuevaTablaQuad(void);
void gen(TablaQuad *tabla, int oper, int var1, int var2, int result);

#endif
