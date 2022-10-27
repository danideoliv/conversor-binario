#include <math.h>
#include <stdio.h>
#include <string.h>

int bindec(char *str) {
  int casas = 1, cont_total = 1; // casas -> Casas decimais da conversão (1, 2, 4, 8, …); cont_total -> Total da soma das casas
  int cont_zero = 0; // Total da soma das casas onde tem o algarismo 0
  int num_dec;       // Resultado da subtração de cont_total e cont_zero

  for (int i = (strlen(str) - 1); i > 0; i--) {
    // Basicamente, esta repetição está invertida e nela está o total de elementos no vetor bin com excessão do último.

    casas *= 2; // Como o valor inicial é 1, a multiplicação não dará 0
    cont_total += casas; // A contagem é feita com a atribuição de multiplicação por 2 na variável casas

    if (str[i - 1] == '0') {
      // Caso a casa decimal atual seja 0, também é feita uma contagem
      cont_zero += casas;
    }
  }

  if (str[strlen(str) - 1] == '0') {
    // Caso a última casa seja 0, cont_zero adiciona 1
    cont_zero++;
  }

  num_dec = cont_total - cont_zero; // Subtrai as casas que têm 1 pela as que têm 0 e assim teremos o número
  return num_dec;
	}

void decbin(int num) {
  int dec = num; // dec de "decimal". Basicamente, o parametro passa a ser o valor de uma nova variável 
  int i = 0, bin_num[100]; // Criação da variável i e bin_num (onde ficará o número em binário)

  while (dec >= 1) {
		// Basicamente, enquanto o número for maior ou igual a 1, serão feitos testes com os resultados das divisões inteiras do número por 2
    if (dec % 2 == 0) {
      bin_num[i] = 0; // Casas onde ficarão com 0
    } else if (dec % 2 == 1) {
      bin_num[i] = 1; // Casas onde ficarão com 1
    }

    dec /= 2; // Divisão do número a cada ciclo
		i++; // Contagem de ciclos
	}
	
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", bin_num[j]); // Saída do número binário 
	}
}

int main(void) {
  char bin[100]; // Variável onde a string (número em binário) será armazenada
  int d, dec; // d -> Variável da decisão; dec -> Variável do número decimal que será convertido
	
  printf("Você quer converter binário para decimal ou o contrário? (Digite 1 para a primeira opção e 2 para a segunda): "); scanf("%d", &d); 

  if (d == 1) {
    printf("Digite um número em binário: "); scanf("%s", &bin); // Obtem o número em binário

    printf("Número em decimal: %d\n",
           bindec(bin)); // Saída de dados com o resultado final
  } else if (d == 2) {
    printf("Digite um número em decimal: "); scanf("%d", &dec); // Obtem o número em decimal

    printf("Número em binário: "); decbin(dec); // Saída de dados com o resultado final
  }

  return 0;
}
