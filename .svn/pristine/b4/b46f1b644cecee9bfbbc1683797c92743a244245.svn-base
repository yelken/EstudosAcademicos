#include <stdio.h>
#include <math.h>

int getDelta(int a, int b, int c) {
	int delta;
	delta = pow(b, 2) - 4*(a*c);
	return delta;
}

int *getRaizesEquacoes(int a, int b, int c) {
			
	// Alocar duas posições de memória para o array
	int *raizes = malloc(2 * sizeof(int));
	
	raizes[0] = (-b + sqrt(getDelta(a,b,c))) / 2*a;
	raizes[1] = (-b - sqrt(getDelta(a,b,c))) / 2*a;
	
	printf("A raiz 1: %d\n", raizes[0]);
	printf("A raiz 2: %d\n", raizes[1]);
	
	return raizes;
}