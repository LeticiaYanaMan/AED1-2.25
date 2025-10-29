#include <stdio.h>
#include <stdlib.h>

// definindo fila
typedef struct {
    int *data;
    int start;
    int topo;
    int cap;
} Fila;

// iniciar a fila
void init(Fila *fila, int cap) {
    fila->data = (int *)malloc(cap * sizeof(int));
    fila->start = 0;
    fila->topo = 0;
    fila->cap = cap;
}

// inserir elemento
void inserir(Fila *fila, int valor) {
    if (fila->topo == fila->cap) {
        fila->cap *= 2;
        
    }
    fila->data[fila->topo++] = valor;
    fila->topo = (fila->topo) % (fila->cap); // fazer a volta
}

// remover elemento 
int remover(Fila *fila) {
    if (fila->start == fila->topo) {
        printf("Fila Vazia\n");
        return 0;
    }
    return fila->data[fila->start];
    fila->start = (fila->start +1) % fila->cap;
    fila->cap--;
}

// olhar 
void mostrar(Fila *fila) {
    int i = fila->start;
    for (int j = 0; j < fila->cap; j++) {
        printf("%d\n", fila->data[i]);
        i = (i + 1) % fila->data;
    }
}
