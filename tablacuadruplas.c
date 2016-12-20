#include "tablacuadruplas.h"

/* Devuelve una nueva tabla */
TablaQuad *nuevaTablaQuad(void){

	TablaQuad *tabla;
	tabla->quads = malloc(ROWS*sizeof(int*));
	
	int i;
	for(i=0; i<ROWS; i++){
		tabla->quads[i] = malloc(COLS*sizeof(int));
	}

	tabla->nextQuad = 0;
	return tabla;

}

/* */
void gen(TablaQuad *tabla, int oper, int var1, int var2, int result){
	if (tabla->nextQuad < ROWS){
		tabla->quads[tabla->nextQuad][0] = oper;
		tabla->quads[tabla->nextQuad][1] = var1;
		tabla->quads[tabla->nextQuad][2] = var2;
		tabla->quads[tabla->nextQuad][3] = result;
		tabla->nextQuad++;
	}
	else{
		printf("Error: Llena.\n");
	}
}


