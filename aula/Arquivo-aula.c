#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("ERRO\n");
        return 1;
    }
    return 0;
}

// vai funcionar e abrir um file de texto chamado data.txt
-----------------------------------------------------------------------------
#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("ERRO\n");
        return 1;
    }
    fprintf(file, "Nome: %s, Idade: %d\n", "Alice", 25);
    return 0;
}

// vai funcionar e, no arquivo aberto, escrever exatamente "Nome: Alice, Idade: 25" e pula uma linha

-------------------------------------------------------------------------
// EXERCICIO 1 - SLIDE 47 DA AULA 3-4
#include <stdio.h>

int main() {
    FILE *file = fopen("log.txt", "a");
    if (file == NULL) {
        printf("ERRO\n");
        return 1;
    }
    fprintf(file, "Execução concluída com sucesso");
    fclose(file);
    return 0;
}

// EXERCICIO 2 - SLIDE 47 DA AULA 3-4








