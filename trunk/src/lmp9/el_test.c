#include <stdio.h>

#include "gauss.h"

int main(int argc, char **argv)
{
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);

    printf ("%d\n", res);

	printToScreen(A);
	printToScreen(b);

}