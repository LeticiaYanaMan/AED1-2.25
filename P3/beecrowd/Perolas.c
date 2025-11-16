#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No {
    char nome[101];
    int contador;
    struct No* prox;
} No;

No* INIT_ALUNO(char* nome) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->contador = 0;
    novo->prox = NULL;
    return novo;
}

No* SEARCH(No** cabeca, char* nome) {
    No* atual = *cabeca;
    No* anterior = NULL;
    
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        anterior = atual;
        atual = atual->prox;
    }
    
    No* novo = INIT_ALUNO(nome);
    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        anterior->prox = novo;
    }
    return novo;
}

void END(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int COMPARE(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    int P, A, R;
    
    while (1) {
        scanf("%d %d %d", &P, &A, &R);
        
        if (P == 0 && A == 0 && R == 0) {
            break;
        }
        
        char perolas[P][1001];
        for (int i = 0; i < P; i++) {
            scanf(" %[^\n]", perolas[i]);
        }
        
        No* lista = NULL;
        
        for (int i = 0; i < A; i++) {
            char nomeAluno[101];
            scanf(" %[^\n]", nomeAluno);
            
            No* atual = SEARCH(&lista, nomeAluno);
            
            for (int j = 0; j < R; j++) {
                char resposta[1001];
                scanf(" %[^\n]", resposta);
                
                for (int k = 0; k < P; k++) {
                    if (strcmp(resposta, perolas[k]) == 0) {
                        atual->contador++;
                        break;
                    }
                }
            }
        }
        
        int maxPerolas = 0;
        No* atual = lista;
        while (atual != NULL) {
            if (atual->contador > maxPerolas) {
                maxPerolas = atual->contador;
            }
            atual = atual->prox;
        }
        
        char* vencedores[A];
        int num = 0;
        
        atual = lista;
        while (atual != NULL) {
            if (atual->contador == maxPerolas) {
                vencedores[num] = atual->nome;
                num++;
            }
            atual = atual->prox;
        }
        
        qsort(vencedores, num, sizeof(char*), COMPARE);
        
        for (int i = 0; i < num; i++) {
            if (i > 0) {
                printf(", ");
            }
            printf("%s", vencedores[i]);
        }
        printf("\n");
        
        END(lista);
    }
    
    return 0;
}
