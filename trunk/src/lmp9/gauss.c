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
for (int i=1; i < mat->r; i++)
		{
			double m;
			
			for (int j=0; j< mat->r -1; j++) 
				{					
					if (mat->data[i][j] == 0)
					continue;
					
					if (mat->data[i-1][i-1] == 0)
					return 1;
					
					findElem (mat, mat->c, mat->r, i);
					
					m = mat->data[j+1][i-1]/mat->data[i-1][i-1];
					b->data[j+1][0] -= m*(b->data[i-1][0]);
					
					for (int k=0; k < mat->c; k++)
						mat->data[j+1][k] -= m*(mat->data[i-1][k]);
				}
				
		}

		return 0;
}

