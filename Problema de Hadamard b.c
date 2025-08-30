#include <stdio.h>

int main() {

  // os dois produtos
  int U[101];
  int V[101];

  // o resultado
  int res[101];

  // ler o primeiro vetor
  for (int i = 0; i < 101; i++) {
    scanf("%d", &U[i]);
    if (U[i] > 100) {
      printf("INVALIDO\n");
    }
  }

  // ler o segundo vetor 
  for (int i = 0; i < 101; i++) {
    scanf("%d", &V[i]);
    if (V[i] > 100) {
      printf("INVALIDO\n");
      V[i] = 500;
    }
  }

  // calcular, armazenar e exibir o valor do produto
  for (int i = 0; i < 101; i++) {
    res[i] = U[i] * V[i];
    if (V[i] == 500 || U[i] == 500) {
      printf("INVALIDO\n");
    }
    else {
      printf("U[%d] = %d\n", i, res[i]);
    }
  }
  return 0;
}
