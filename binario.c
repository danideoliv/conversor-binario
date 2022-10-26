#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	char bin[100]; // Variável onde será armazenado o número binário
	int casas = 1; // Casas decimais da conversão (1, 2, 4, 8, …)
	int cont_total = 1; // Total da soma das casas
	int cont_zero = 0; // Total da soma das casas onde tem o algarismo 0
	int num_dec; // Resultado da subtração de cont_total e cont_zero

	printf("Digite um número em binário: ");

	scanf("%s", &bin); // Entrada do número binário 

	for (int i = (strlen(bin) - 1); i > 0; i--) {
	// Basicamente, esta repetição está invertida e nela está o total de elementos no vetor bin com excessão do último.	
		casas *= 2; // Como o valor inicial é 1, a multiplicação não dará 0
		cont_total += casas; // A contagem é feita com a atribuição de multiplicação por 2 na variável casas
		
		if (bin[i-1] == '0') {
		// Caso a casa decimal atual seja 0, também é feita uma contagem	
			cont_zero += casas;

		}
	}
	
	if (bin[strlen(bin) - 1] == '0') {
	// Caso a última casa seja 0, cont_zero adiciona 1	
   		cont_zero += 1;
	}

	num_dec = cont_total - cont_zero; // Subtrai as casas que têm 1 pela as que têm 0 e assim teremos o número

	printf("Número em decimal: %d\n", num_dec);	

  return 0;

}
