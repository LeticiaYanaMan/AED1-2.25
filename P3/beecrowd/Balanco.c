#include <stdio.h>
#include <string.h>

typedef struct {
    char itens[1000];
    int topo;
} Pilha;

void ini(Pilha *p) {
    p->topo = -1;
}

int cheia(Pilha *p) {
    return p->topo == -1;
}

int push(Pilha *p, char c) {
    if (p->topo == 1000 - 1)
        return 0;
    p->itens[++p->topo] = c;
    return 1;
}

int pop(Pilha *p) {
    if (cheia(p))
        return 0;
    p->topo--;
    return 1;
}

int main() {
    char linha[1000];
    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        Pilha p;
        ini(&p);
        int correto = 1;
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '(') {
                push(&p, '(');
            } else if (linha[i] == ')') {
                if (!pop(&p)) {
                    correto = 0;
                    break;
                }
            }
        }
        if (!correto || !cheia(&p))
            printf("incorrect\n");
        else
            printf("correct\n");
    }
    return 0;
}
