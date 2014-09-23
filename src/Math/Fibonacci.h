#include<stdio.h>
#include<math.h>

int fibRecursivo(int numero) {
	if (numero == 0) {
		return 0;
	} else if (numero == 1) {
		return 1;
	}

	return fibRecursivo(numero - 1) + fibRecursivo(numero - 2);
}

void fib(int numero) {
	int a, b, i;

	for (a=0, b=1, i=0; i<numero; b+=a, a=b-a, i++) {				
		printf(" %d ", a);
	}
}

