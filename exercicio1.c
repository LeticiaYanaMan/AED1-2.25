Exercício:
Crie um programa em C que defina uma struct chamada Produto, contendo:

char nome[50]
float preco
int quantidade

O programa deve:
1. Declarar um vetor de 5 produtos.
2. Ler os dados de cada produto utilizando ponteiros para struct.
3. Imprimir todos os produtos cadastrados.
4. Mostrar o nome do produto com o maior valor total em estoque (preço × quantidade).
---------------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main() {
  char nome[50];


