/**
Suponha que os números inteiros 1, 2, 3, 4 são colocados, nesta ordem, numa pilha inicialmente vazia. Depois de cada operação de empilhar, você pode retirar
zero ou mais elementos da pilha. Cada número retirado da pilha é impresso numa folha de papel. Por exemplo, a sequência de operações E, E, D, E, D, D, E, D, onde E
signica ”empilhar o próximo número da sequência” e D signica ”desempilhar”, produza impressão da sequência 2, 3, 1, 4. Quais das 24 permutações de 1, 2, 3, 4 podem ser
obtidas desta maneira?
**/ python

def achar_permut(lst):
    res = set()

    def gera(ent, pil, sai):
        if not ent and not pil:
            res.add(tuple(sai))
            return

        if ent:
            x = ent[0]
            gera(ent[1:], pil + [x], sai)

        if pil:
            t = pil[-1]
            gera(ent, pil[:-1], sai + [t])

    gera(list(lst), [], [])
    return sorted([list(p) for p in res])

if __name__ == "__main__":
    nums = [1, 2, 3, 4]
    perms = achar_permut(nums)

    for p in perms:
        print(p)
    
    print(f"Total de permutações: {len(perms)}")

/**
Escreva uma função que inverta a ordem das letras de cada palavra de
uma sentença, preservando a ordem das palavras. Suponha que as palavras da sentença
são separadas por espaços. A aplicação da operação à sentença AMU MEGASNEM
ATERCES, por exemplo, deve produzir UMA MENSAGEM SECRETA.
**/ C

---------------------- CASSEMIRO
#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    int i=0, a=0, tam=0, tampala=0, aux=0;
    fgets(str, sizeof(str), stdin);
    tam = strlen(str) - 2;
    while (str[k] != '\0') {
        for (i = aux; str[i] != ' '; i++) {
            tampala++;
            aux++;
        }
        if (tampala == aux) {
            for (i = tampala; i >= 0; i--) {
                printf("%c", str[i]);
            }
        }
        else {
            for (i = aux; i >= aux - tampala; i--) {
                printf("%c", str[i]);
            }
        }
        a += aux;
        aux = tampala;
        tampala = 0;
    }
    return 0;
}

---------------------------- VIC

#include <stdio.h>
#include <string.h>

void inverter(char str[], int i, int f) {
    while (i < f) {
        char aux = str[i];
        str[i] = str[f];
        str[f] = aux;
        i++;
        f--;
    }
}

int main() {
    char frase[1001];
    fgets(frase, sizeof(frase), stdin);
    
    int len = strlen(frase);
    if (len > 0 && frase[len-1] == '\n') {
        frase[len-1] = '\0';
        len--;
    }

    int inicio = 0;
    for (int i = 0; i <= len; i++) {
        if (frase[i] == ' ' || frase[i] == '\0') {
            inverter(frase, inicio, i-1);
            inicio = i + 1;
        }
    }

    printf("%s\n", frase);
    return 0;
}




