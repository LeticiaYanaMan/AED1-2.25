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
  printf("quantidade: \n");
  scanf("%d", &venda[i].qtd);
  printf("mes da compra (1-12): \n");
  scanf("%d", &venda[i].mes);
  printf("nome do cliente: \n");
  scanf("%s", &venda[i].nome);
}

// pesquisa

int op;
printf("escolha uma das opções: \n");
printf("1 -- total de vendas num dado mes \n");
printf("2 -- total de vendas de um determinado produto num dado mes para um determinado cliente \n");
printf("3 -- total de vendas de cada produto \n");
printf("4 -- total vendido para cada cliente \n");
printf("5 -- fim");
scanf("%d", &op);
if (op == 1) {

}
if (op == 2) {

}
if (op == 3) {

}
if (op == 4) {

}
if (op == 5) {

}








