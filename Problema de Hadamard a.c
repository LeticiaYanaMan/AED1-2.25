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
  }

  // ler o segundo vetor 
  for (int i = 0; i < 101; i++) {
    scanf("%d", &V[i]);
  }

  // calcular, armazenar e exibir o valor do produto
  for (int i = 0; i < 101; i++) {
    res[i] = U[i] * V[i];
    printf("U[%d] = %d", i, res[i]);
  }
  return 0;
}
