#include<stdio.h>
#include<math.h>

int getFatorial(int numero) {
	int y = 1;
	int fatorial = 1;

	printf("Fatorial numerico \n");
	printf("Fatorial:");
	while (y <= numero) {
		printf("%dX%d %d \n", fatorial, y, fatorial * y);
		fatorial = fatorial * y;
		y++;
	}

	printf("%d", fatorial);

	return fatorial;
}

int getSerie(int QuantidadeSeries) {
	int i, soma =0;

	for (i =0; i < QuantidadeSeries; i++) {
		printf("Fatorial: %d/(%d + 1)", getFatorial(i), i);
		soma += getFatorial(i) / (i + 1);
	}

	return soma;

}

