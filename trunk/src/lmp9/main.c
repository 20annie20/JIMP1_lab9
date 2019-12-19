#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {
	if(argc<3) fprintf(stderr, "nie podano dostatecznej liczby argumentow\n");
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL){
		fprintf(stderr, "nie moge wczytac danych poprawnie\n");
		return -1;
	}
	if (b == NULL){
		fprintf(stderr, "nie moge wczytac danych poprawnie\n");
		return -2;
	}

	printToScreen(A);
	printToScreen(b);

	if(A->c != b->r){
		fprintf(stderr, "nieprawidlowe rozmiary macierzy!\n");
		return -3;
	}
	
	//reorganizacja macierzy
	A = findElem(A, A->r, A->c, 0);
	printToScreen(A);
	res = eliminate(A,b);
	if(res != 0 ){
		fprintf(stderr,"brak elementu niezerowego do umieszczenia na diagonali. nie mozemy dzielic przez 0!\n");
		return -4;
	}
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		
		res = backsubst(x,A,b);

		printToScreen(x);
	  	freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		return -5;
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
