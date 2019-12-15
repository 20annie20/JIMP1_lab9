#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include "mat_io.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
		for (int i=0; i<mat->r; i++)
		{
			for (int j=0; j< mat->c; j++)
				{
					if (mat->data[0][0] == 0)
					return 1;
					if (mat->data[i][j] == 0)
					break;
				double m = mat->data [i+1][j]/mat->data[i][j];
					for (int k=j; k < mat->c; k++)
					{
						b->data[k][0] -= m*b->data[k][0];
						mat->data[i+1][j] -= m*mat->data[i][j];
					}
				}
				findElem (mat, mat->r, mat->c, i);
		}

		
		return 0;
}

