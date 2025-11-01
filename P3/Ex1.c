// versao interativa do copiar lista
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

/*
// COPIAR LISTA (RECURSIVA)
No* copiar_listaR(No* lista) {
    No* Novo = NULL;
    if (lista == NULL) 
        return NULL;
    Novo = malloc(sizeof(No));
    Novo->valor = lista->valor;
    Novo->proximo = copiar_listaR(lista->proximo);
    return Novo;
} 
*/

// COPIAR LISTA (INTERATIVA)
No* copiar_listaI(No* lista) {
    No* atual = NULL;
    No* copy = lista;
    while (atual != NULL) {
        copy->valor = atual->valor;
        atual = atual->proximo;
        copy->proximo = atual->proximo;
    }
    return copy;
}

// imprimir (teste)
void PRINT(No** cabeca) {
  No* temp = *cabeca;
  while(temp != NULL) {
    printf ("%d ", temp->valor);
    temp = temp->proximo;
  }
  printf("\n");
}

//adicionar um valor numa lista (teste)
void ADD(No** cabeca, int valor) {
  No* Novo = malloc(sizeof(No));
  Novo->valor = valor;
  Novo->proximo = *cabeca;
  *cabeca = Novo;
}


int main() {
    No* lista = NULL;
    int N;
    char c[50];
    while (scanf("%s", c) != EOF) {
        if (strcmp(c, "ADD")==0) {
            scanf("%d", &N);
            ADD(&lista, N);
        }
        else if (strcmp(c, "PRINT")==0) {
            PRINT(&lista);
        }
        else if (strcmp(c, "COPIAR")==0) {
            No* copia = copiar_listaI(lista);
            PRINT(&copia);
        }
        else if (strcmp(c, "END")==0) {
            free(lista);
        }
        return 0;
    }
}
