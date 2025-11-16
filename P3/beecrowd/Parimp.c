#include <stdio.h>
#include <stdlib.h>

int cmp_par(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);  // crescente
}

int cmp_impar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);  // decrescente
}

int main() {
    int N;
    scanf("%d", &N);

    int *pares = malloc(N * sizeof(int));
    int *impares = malloc(N * sizeof(int));
    int qtd_pares = 0, qtd_impares = 0;

    for(int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        if (x%2 == 0)
            pares[qtd_pares++] = x;
        else
            impares[qtd_impares++] = x;
    }

    // ordena pares crescente
    qsort(pares, qtd_pares, sizeof(int), cmp_par);

    // ordena ímpares decrescente
    qsort(impares, qtd_impares, sizeof(int), cmp_impar);

    // imprime pares
    for (int i = 0; i < qtd_pares; i++)
        printf("%d\n", pares[i]);

    // imprime ímpares
    for (int i = 0; i < qtd_impares; i++)
        printf("%d\n", impares[i]);

    free(pares);
    free(impares);

    return 0;
}
