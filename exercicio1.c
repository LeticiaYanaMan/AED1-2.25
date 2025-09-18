// Exercício:
// Crie um programa em C que defina uma struct chamada Produto, contendo:

// char nome[50]
// float preco
// int quantidade

// O programa deve:
// 1. Declarar um vetor de 5 produtos.
// 2. Ler os dados de cada produto utilizando ponteiros para struct.
// 3. Imprimir todos os produtos cadastrados.
// 4. Mostrar o nome do produto com o maior valor total em estoque (preço x quantidade).
///////////////////////////////////

#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[50];
  float preco;
  int quantidade;
} Produto;

int main() {
  Produto p1[6];
  Produto *p; // ponteiro que aponta para struct
  char Str[50];
  double preco;
  int qtd;

  for (int i = 0; i < 6; i++) {
    p = &p1[i]; // p aponta para o primeiro produto 
    scanf("%s", Str);
    strcpy(p->nome, Str);
    scanf("%lf", &preco);
    p->preco = preco;
    scanf("%d", &qtd);
    p->quantidade = qtd;
    for (int j = 0; j < 6; j++) {
      Str[j] = \0;
    }
    printf("%s\n", p->nome);
    printf("%lf\n", p->preco);
    printf("%d\n", p->quantidade);
  }
















