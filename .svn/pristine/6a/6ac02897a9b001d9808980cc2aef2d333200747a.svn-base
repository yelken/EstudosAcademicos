#include<stdio.h>
#include<math.h>

float getImc(float massa, float altura) {
	float retorno;
	retorno = massa / pow(altura, 2);
	return retorno;
}

void getSituacaoImc(float imc) {
	if (imc < 16) {
		printf("Magreza grave");
	} else if (imc > 16 && imc < 17) {
		printf("Magreza moderada");
	} else if (imc > 17 && imc < 18.5) {
		printf("Magreza leve");
	} else if (imc > 18.5 && imc < 25) {
		printf("Saudavel");
	} else if (imc > 25 && imc < 30) {
		printf("Sobrepeso");
	} else if (imc > 30 && imc < 35) {
		printf("Obesidadade grau I");
	} else if (imc > 35 && imc < 40) {
		printf("Obesidadade grau II (Severa)");
	} else if (imc >= 40) {
		printf("Obesidadade grau III (Morbida)");
	}
}