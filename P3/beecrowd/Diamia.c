#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No* prox;
} No;

void push(No **topo, char valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

void pop(No** topo) {
    No* aux = *topo;
    *topo = aux->prox;
    free(aux);
}

void free_pilha(No **topo) {
    while (*topo != NULL) {
        No *aux = *topo;
        *topo = (*topo)->prox;
        free(aux);
    }
}

int main() {
    int n;
    char mina[1000];
    scanf("%d", &n);
    while (n-- != 0) {
        scanf("%s", mina);
        No* pilha = NULL;
        int d=0, i;
        int tam = strlen(mina);
        for (i=0; i<tam; i++) {
            if (mina[i] == '<') {
                push(&pilha, '<');
            }
            if (mina[i] == '>') {
                if (pilha != NULL) {
                    pop(&pilha);
                    d++;
                }
            }
        }
        printf("%d\n", d);
        free_pilha (&pilha);
    }
    return 0;
}
