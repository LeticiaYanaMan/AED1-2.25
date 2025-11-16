#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char item[25];
    struct No *prox;
} No;

void ADD(No **lista, char *palavra) {
    No *novo = malloc(sizeof(No));
    No *atual = *lista;
    No *ant = NULL;
    while (atual != NULL && strcmp(atual->item, palavra) < 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (!novo) exit(1);
    if (atual != NULL && strcmp(atual->item, palavra) == 0)
        return;

    strcpy(novo->item, palavra);
    novo->prox = atual;
    if (ant == NULL)
        *lista = novo;
    else
        ant->prox = novo;
}

void PRINT(No *lista) {
    int primeiro = 1;
    while (lista != NULL) {
        if (!primeiro) printf(" ");
        printf("%s", lista->item);
        primeiro = 0;
        lista = lista->prox;
    }
    printf("\n");
}

void END(No **lista) {
    No *atual = *lista;
    while (atual != NULL) {
        No *tmp = atual;
        atual = atual->prox;
        free(tmp);
    }
    *lista = NULL;
}

int main() {
    int N;
    scanf("%d", &N);
    char *linha = NULL;
    size_t tam = 0;
    while (N--) {
        do {
            if (getline(&linha, &tam, stdin) == -1) exit(0);
        } while (linha[0] == '\n');
        No *lista = NULL;
        char *palavra = strtok(linha, " \n");
        while (palavra != NULL) {
            ADD(&lista, palavra);
            palavra = strtok(NULL, " \n");
        }
        PRINT(lista);
        END(&lista);
    }
    free(linha);
    return 0;
}
