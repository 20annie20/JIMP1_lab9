#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include "mat_io.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	
for (int i=0; i < mat->r - 1; i++)
		{
			if (mat->c != mat->r)
			return 2;

			double m;
			
			findElem (mat, mat->c, mat->r, i);
			if (mat->data[i][i] == 0)
					return 1;
			for (int j=i+1; j< mat->r; j++) 
				{					
					m = mat->data[j][i]/mat->data[i][i];
					b->data[j][0] -= m*(b->data[i][0]);
					
					for (int k=0; k < mat->r; k++)
						mat->data[j][k] -= m*(mat->data[i][k]);
				}
				
		}

		return 0;
}

