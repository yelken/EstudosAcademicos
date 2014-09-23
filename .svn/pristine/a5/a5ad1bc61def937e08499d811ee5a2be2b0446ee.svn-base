#include<stdio.h>
#include<math.h>

float valorDolar = 2.23;
float e = 2.71;

//float getImc(float massa, float altura) {
//	float retorno = massa * pow(altura, 2);
//	return retorno;
//}

float calculoConsulta(int idade, float massa, float altura) {
	float valorConsulta = ((e * pow(massa, 1 / idade) * getImc(massa, altura))
			/ (pow(sqrt(getImc(massa, altura)) * sin(massa / altura),
					sqrt(idade)))) * valorDolar;

	return valorConsulta;
}

