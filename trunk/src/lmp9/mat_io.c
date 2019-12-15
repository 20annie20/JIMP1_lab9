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

Matrix *findElem (Matrix *mat, int r, int c, int rnum)
{
	double t = mat->data[0][rnum];
	int k = -1;
	for (int i = 0; i < r; i++)
		{
			for (int j=0; j < c; j++)
			{
				if (mat->data[i][j] > t)
					k = i;
			} 
		}
		if (k > -1)
		{
			double *tmp = malloc (sizeof (double)*c);
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					tmp[j] = mat->data[k][j];
					mat->data[k][j] = mat->data [rnum][j];
					mat->data[rnum][j] = tmp[j];
				}
			}
		}
		return mat;
}