#include <stdio.h>
#include <stdlib.h>

int crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int decrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);  
}

int main() {
    int N;
    scanf("%d", &N);

    int *pares = malloc(N * sizeof(int));
    int *impares = malloc(N * sizeof(int));
    int contpares = 0, contimpares = 0;

    for(int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);

        if (x%2 == 0)
            pares[contpares++] = x;
        else
            impares[contimpares++] = x;
    }

    qsort(pares, contpares, sizeof(int), crescente);
    qsort(impares, contimpares, sizeof(int), decrescente);

    for (int i = 0; i < contpares; i++)
        printf("%d\n", pares[i]);
    for (int i = 0; i < contimpares; i++)
        printf("%d\n", impares[i]);

    free(pares);
    free(impares);

    return 0;
}
