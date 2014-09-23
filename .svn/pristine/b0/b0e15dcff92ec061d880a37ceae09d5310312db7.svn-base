#include<stdio.h>
#include<string.h>

// Tipo complexo
enum boolean {
	true = 1, false = 0
};

enum operacoes {
	soma = 1, produto = 2
};

// Define o tipo para ser usado em qualquer lugar
typedef enum boolean bool;
typedef enum operacoes operacao;

bool isNumeroPalindrome(int numero) {
	int auxiliar, reverso;
	bool retorno = false;
	
	// DÚVIDA REFERENTE AO LENGTH DO INTEGER
	//if (sizeof(numero) < 8) {
	//		printf("Digite um número com 8 digitos, exemplo: 12345678");
	//} else {
	auxiliar = numero;
	reverso = 0;

	while (auxiliar != 0) {
		reverso = reverso * 10 + auxiliar % 10;
		auxiliar = auxiliar / 10;
	}

	if (reverso == numero) {
		retorno = true;
	}
	//}

	return retorno;
}

int operacaoNumeros(int numero, operacao paramOp) {
	int auxiliar, reverso, retorno;

	auxiliar = numero;

	switch (paramOp) {
	case soma:
		retorno = 0;
		break;
	case produto:
		retorno = 1;
		break;
	default:
		break;
	}

	reverso = 0;

	while (auxiliar != 0) {
		reverso = auxiliar % 10;

		if (paramOp == soma) {
			retorno = retorno + reverso;
		} else {
			if (reverso != 0) {
				retorno = retorno * reverso;
			}
		}

		auxiliar = auxiliar / 10;
	}

	return retorno;
}
