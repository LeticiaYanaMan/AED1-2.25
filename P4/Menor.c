#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
  int chave;
  struct No* esq;
  struct No* dir;
} No;

int main() {
  No* raiz == NULL;
  char c[50];
int valor;
  while (scanf("%d", c) != EOF) {
    if (strcmp(c, "ADD")==0)  {
      scanf("%d", &valor);
      raiz = INSERT(raiz, valor);
    }
    if (strcmp(c, "PRINT")==0) {
      PRINT(raiz);
    if (strcmp(c, "MENORES")==0) {
      scanf("%d", &valor);
      Menores(raiz, valor);}
