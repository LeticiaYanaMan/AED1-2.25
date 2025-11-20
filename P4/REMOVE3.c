#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No* esq;
    struct No* dir;
} No;

No* INSERIR(No* nodo, int valor) {
    if (nodo == NULL) {
        No* novo = malloc(sizeof(No));
        novo->chave = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < nodo->chave)
        nodo->esq = INSERIR(nodo->esq, valor);
    else 
        nodo->dir = INSERIR(nodo->dir, valor);
    return nodo;
}


No* REMOVE(No* A, int chave) {
    //caso base - arvore vazia ou elemento não encontrado
    if (A == NULL) 
        return A;
    
    // navegar ate encontrar o elemento
    if (chave < A->chave) A->esq = REMOVE(A->esq, chave);
    else if (chave > A->chave) A->dir = REMOVE(A->dir, chave);

    // encontrou o elemento (2 casos possíveis)
    if (chave == A->chave) {
        // 1. Nó folha ou tem apenas um filho 
        if (A->esq == NULL && A->dir == NULL) { // nó folha
            free(A);
            return NULL;
        }
        else if (A->esq != NULL && A->dir == NULL) { // direita vazia (tem na esquerda)
            No* aux = A->esq;
            free(A);
            return aux;
        }
        else if (A->dir != NULL && A->esq == NULL) { //esquerda vazia (tem na direita)
            No* aux = A->dir;
            free(A);
            return aux;
        }

        // 2. Nó tem dois filhos (precisamos achar o sucessor)
        else if (A->esq != NULL && A->dir != NULL) { 
            No* temp = A->dir;
            while (temp && temp->esq != NULL) {
                temp = temp->esq; //vai descendo a árvore até o menor valor (esquerda) da ramificação direita
            }
            A->chave = temp->chave; // copia a chave do sucessor
            A->dir = REMOVE(A->dir, temp->chave); //remove o sucessor
        }
    }
    return A;
}

void PRINT(No* raiz) {
    if (raiz == NULL) return;
    PRINT(raiz->esq);
    printf("%d ", raiz->chave);
    PRINT(raiz->dir);
}

void END(No* raiz) {
    if (raiz == NULL) return;
    END(raiz->esq);
    END(raiz->dir);
    free(raiz);
}

int main() {
    char c[100];
    int valor;
    No* raiz = NULL;


    while (scanf("%s", c) != EOF) {
        if (strcmp(c, "ADD")==0) {
            scanf("%d", &valor);
            raiz = INSERIR(raiz, valor);
        }
        if (strcmp(c, "REMOVE")==0) {
            scanf("%d", &valor);
            raiz = REMOVE(raiz, valor);
        }
        if (strcmp(c, "PRINT")==0) {
            PRINT(raiz); //imprimir em ordem
            printf("\n");
        }
        if (strcmp(c, "END")==0) {
            END(raiz);
            raiz = NULL;
            break;
        }
    }

    return 0;
}
