#include <stdio.h>
#include <stdlib.h>
#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	int i, j;

	double suma;

	if(mat->r != mat->c){

		fprintf(stderr, "nieprawidlowy rozmiar macierzy!\n");

		return 2;

	}

	for (i = (x->r)-1; i >= 0; i--) { //-1, bo indeksy!

		suma = 0;

		for(j=(x->r)-1; j>i; j--){ //od ostat. wiersza, do wiersza w ktorym jestesmy

			suma = suma - x->data[j][0]*mat->data[i][j];

		}

		if(mat->data[i][i] != 0){ //zrobilismy przestawianie, czyli macierz musi byc nieosobliwa

								  //no i jestesmy na 'stopniu' macierzy schodkowej

			x->data[i][0] = (b->data[i][0] + suma) / mat->data[i][i];//x dla danego wiersza staje sie suma 

			              	       		  							 //wyrazu wolnego i suma dotychcz. podzielona

																	// przez wspolczynnik przy x

		}else{

			fprintf(stderr, "macierz jest osobliwa, dzielenie przez zero!!!\n");

			return 1;

		}

		

	}

	return 0;

}


