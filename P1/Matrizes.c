#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas = 3, colunas = 4;

    // ponteiro para ponteiro → cada ponteiro será uma linha
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // preencher matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i * 10 + j; // só um exemplo
        }
    }

    // imprimir matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // liberar memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); // libera cada linha
    }
    free(matriz); // libera o vetor de ponteiros

    return 0;
}
