#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca <> NULL - udalo sie wczytac
 * Zwraca == NULL - podczas wczytywania wystapil blad
 */
Matrix * readFromFile(char * fname) {
	int r,c;
	int ir, ic;
	FILE * fin =  fopen(fname,"r");
	Matrix * mat = NULL;

	if (fin != NULL) {
		fscanf(fin,"%d %d",&r,&c);
		mat = createMatrix(r,c);
		if (mat != NULL) {
			for (ir = 0; ir < r; ir++) 
				for (ic = 0; ic < c; ic++)
					fscanf(fin, "%lf",&(mat->data[ir][ic]));
		} else {
			fprintf(stderr,"Wystąpił problem podczas tworzenia macierzy o rozmiarach %d x %d dla danych z pliku: %s\n", r, c, fname);
		}
		fclose(fin);
	} else {
		fprintf(stderr,"Nie mogę otworzyć pliku o nazwie: %s\n", fname);
	}
	return mat;
}

void printToScreen(Matrix *mat) {
	int i,j;
	printf("[ \n");
	for (i = 0; i<mat->r; i++) {
		printf("  ");
		for (j = 0; j < mat->c; j++) {
			printf("%f ", mat->data[i][j]);
		}
		printf("; \n");
	}
	printf("]\n");
}

Matrix * createMatrix(int r, int c) {
		int i;
		Matrix * mat = (Matrix*) malloc(sizeof(Matrix));
		if (mat != NULL) {
			mat->r = r;
			mat->c = c;
			mat->data = (double**) malloc(sizeof(double*) * r);
			for (i=0; i < r; i++) {
					mat->data[i] = (double*) malloc(sizeof(double) * c);
			}
		}

		return mat;
}

void freeMatrix(Matrix * mat) {
  int i;
	for (i=0;i < mat->r; i++)
		free(mat->data[i]);
	free(mat->data);
	free(mat);
}

Matrix * findElem(Matrix *mat, int r, int c){
	float max = mat->data[0][0];
	int row;
	for(int i = 0; i < r; i++){
		if(mat->data[i][0] > max){
			max = mat->data[i][0];
			row = i+1;
		}
	}
	//zamiana wierszy 
	float temp[c];
	for(int i = 0; i < c; i++){
		temp[i] = mat->data[0][i];//spisanie danych do tempa
	}
	mat->data[0] = mat->data[row];
	for(int i = 0; i < c; i++){
		mat->data[row][i] = temp[i];
	}
	
	printf("najwieksza wartosc w kolumnie to: %lf\n", max);
	printf("jest to w wierszu %d\n", row);
	return mat;
}

