/**
Suponha que os números inteiros 1, 2, 3, 4 são colocados, nesta ordem, numa pilha inicialmente vazia. Depois de cada operação de empilhar, você pode retirar
zero ou mais elementos da pilha. Cada número retirado da pilha é impresso numa folha de papel. Por exemplo, a sequência de operações E, E, D, E, D, D, E, D, onde E
signica ”empilhar o próximo número da sequência” e D signica ”desempilhar”, produza impressão da sequência 2, 3, 1, 4. Quais das 24 permutações de 1, 2, 3, 4 podem ser
obtidas desta maneira?
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int topo;
  int capacidade;
} Pilha 

void init(Pilha *pilha, int capacidade) {
  pilha->data = (int *)malloc(capacidade * sizeof(int));
  pilha->topo = -1;
  pilha->capacidade = capacidade;
}

void push(Pilha *pilha, int valor) {
  if (pilha-> topo == pilh->capacidade -1) {
    aumentar_capacidade(pilha);
  }
  pilha->data[++pilha->topo} = valor;
}

int peek(Pilha *pilha) {
  if (vazia(pilha)) {
    printf("Erro: Pilha vazia. \n");
    exit(1);           
  }
  return pilha->data[pilha->topo];
}

int main() {
  Pilha pilha;
  init(&pulha, 4);
  push(&pilha, 1);
  push(&pilha, 2);
  push(&pilha, 3);
  push(&pilha, 4);








