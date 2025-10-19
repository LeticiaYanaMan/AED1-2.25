#include <string.h>

typedef struct {
    char *data;
    int topo;
    int max;
} Pilha;

void init_pilha(Pilha *pilha, int i, int N) {
    pilha[i].data = (char *)malloc(N * sizeof(char));
    pilha[i].topo = -1;
    pilha[i].max = N;
}

void add_pilha(Pilha *pilha, int i, char par) {
    if (pilha[i].topo == pilha[i].max - 1) {
      pilha[i].max += 2;
      pilha[i].data = (char *)realloc(pilha[i].data, pilha[i].max * sizeof(char));
    }
    pilha[i].data[++pilha[i].topo] = par;
}


int main() {
    char exp[1001];
    int N, len;
    int cont_exp = 0;
    int cont_pilha = 0;
    Pilha *pilha;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        fgets(exp, sizeof(exp), stdin);
        len = strlen(exp);
        for (int j = 0; j < len; j++) {
            if (exp[i] == "(") {
                cont_exp += 1;
            }
        }
        init_pilha(pilha, i, cont_exp);
        for (int l = 0; l < cont_exp; l++) {
          add_pilha(pilha, l, ")");
          cont_pilha += 1;
        }
        if (cont_pilha == cont_exp) {
          printf("correct\n");
        }
        else {
          printf("incorrect\n");
        }
    }
    return 0;
}
