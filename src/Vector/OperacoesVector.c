#include<stdio.h>
#include<Math.h>


void operationsWithVectors() {

	int v1[3] = {1,2,3};
	int v2[3] = {1,2,3};
	int v3[3];

	// SOMA
	v3[0] = v1[0] + v2[0];
	v3[1] = v1[1] + v2[1];
	v3[2] = v1[2] + v2[2];

	int i;

	for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {
		printf("Soma: \n");
		v3[i] = v1[i] + v2[i];
		printf("%d ", v3[i]);
	}

	printf("\n");


	// SUBTRA‚ÌO
	for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {
		printf("Subtra‹o: \n");
		v3[i] = v1[i] - v2[i];
		printf("%d ", v3[i]);
	}

	printf("\n");


	// Multiplica‹o
	for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {
			printf("Multiplica‹o: \n");
			v3[i] = v1[i] * v2[i];
			printf("%d ", v3[i]);
		}

	printf("\n");
}
