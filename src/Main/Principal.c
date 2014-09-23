#include<stdio.h>
#include <stdlib.h>
#include"../Math/CalculoMedia.h"
#include"../Math/Calculadora.h"
#include"../Math/Equacoes.h"
#include"../Math/Fatorial.h"
#include"../Math/ImcUtils.h"
#include"../Math/Tabuada.h"
#include"../Math/Fibonacci.h"
#include"../Desafios/Desafio1.h"
#include"../Desafios/Desafio2.h"
#include"../Biblioteca/exemplo.h"

// scanf tem pelo menos dois parametros
// primeiro parametro: o tipo de variavel da leitura
// %d - inteiro 
// %f - float
// %lf - double 
// %c - char
// %s - string
// Segundo parametro - o enderecos das variaveis de leitura comecando atraves do &

int main() {

	// TODO - Fazer concatenação de nome e sobrenome usando vetor;
	// TODO - Criar função para retorar o tamanho do array;
	// TODO - Criar matriz e exibir na tela
	// TODO - Criar funçõa que recebe uma matriz, letra, quantidadeLinhas, quantidadeColunas
		// imprimir o M =

	int i, j, m[3][3];

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	for (i = 0; i < 3; i++) {
		if (i == 0) {
			printf("┌\n");
		}

		if (i == 2) {
			printf("└\n");
		}

		for (j = 0; j < 3; j++) {

			printf("|%2d ", m[i][j]);

			if (j == 2 && i == 0) {
				printf("┐\n");
			}

			if (j == 2 && i == 2) {
				printf("┘\n");
			}

			if (i == 2) {
				printf("└\n");
			}
		}

		printf("|\n");
	}

	/*


	 int v1[3] = {1,2,3};
	 int v2[3] = {2,2,1};
	 int v3[3];

	 // SOMA
	 v3[0] = v1[0] + v2[0];
	 v3[1] = v1[1] + v2[1];
	 v3[2] = v1[2] + v2[2];

	 int i;

	 printf("Soma: \n");
	 for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {

	 v3[i] = v1[i] + v2[i];
	 printf("%d ", v3[i]);
	 }

	 printf("\n");


	 // SUBTRAÇÃO
	 printf("Subtração: \n");
	 for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {
	 v3[i] = v1[i] - v2[i];
	 printf("%d ", v3[i]);
	 }

	 printf("\n");


	 // Multiplicação
	 printf("Multiplicação: \n");
	 for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {
	 v3[i] = v1[i] * v2[i];
	 printf("%d ", v3[i]);
	 }

	 printf("\n");

	 int produtoVetorial = 0;
	 //  n-1 Somatorio i = 0 v1[i] X  v2[i]

	 // Produto interno
	 for (i = 0; i < (sizeof(v3) / sizeof(v3[0])); i++) {
	 v3[i] = v1[i] * v2[i];
	 produtoVetorial += v3[i];
	 }

	 printf("Produto vetorial: %d ", produtoVetorial);


	 // Array String
	 char nome[51], sobrenome[51];

	 gets(nome);
	 puts(nome);


	 // sizeOf

	 char literal[100];
	 printf("\n");
	 printf("Tamanho vetor: %d", sizeof(literal)); */

	return 0;
}
