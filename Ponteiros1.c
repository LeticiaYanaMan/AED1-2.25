#include <stdio.h>

// struct com as informaçoes do produto
struct venda {
  char ptd[1001];
  int qtd;
  int mes;
  char nome[1001];
}

int main() {
// primeiro, precisa cadastrar "n" produtos
int n;
printf("Quantos produtos deseja cadastrar?\n");
scanf("%d", &n);

for (int i = 0, i < n, i++) {
  printf("nome do produto: \n");
  scanf("%s", &venda[i].ptd);
