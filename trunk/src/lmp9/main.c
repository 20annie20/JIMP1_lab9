#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

void errorHandle(int *p){
	if(p == NULL)
		printf("Test - nie odczytano danych\n");
}

int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) 
		return -1;
	if (b == NULL) 
		return -2;
	printToScreen(A);
	printToScreen(b);

	if(A->c != b->c){
		errorHandle(NULL);
	}
	
	A = findElem(A, A->r, A->c, 0);
	printToScreen(A);
	res = eliminate(A,b);
	x = createMatrix(b->r, 1);
	if (x != NULL) {

		
		res = backsubst(x,A,b);

		printToScreen(x);
	  	freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
