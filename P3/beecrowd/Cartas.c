#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserir (No **inicio, No **fim, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if (*inicio == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }
}

int remover (No **inicio, No **fim) {
    if (*inicio == NULL) return -1;
    No *temp = *inicio;
    int v = temp->valor;
    *inicio = temp->prox;
    if (*inicio == NULL)
        *fim = NULL;
    free(temp);
    return v;
}

int main () {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        No *inicio = NULL, *fim = NULL;
        for (int i = 1; i <= n; i++) {
            inserir(&inicio, &fim, i);
        }
        printf("Discarded cards:");
        while (inicio != fim) {
            int descartada = remover(&inicio, &fim);
            printf(" %d", descartada);
            if (inicio != fim) printf(",");
            int mover = remover(&inicio, &fim);
            inserir(&inicio, &fim, mover);
        }
        printf("\nRemaining card: %d\n", inicio->valor);
        while (inicio != NULL)
            remover(&inicio, &fim);
    }
    return 0;
}
