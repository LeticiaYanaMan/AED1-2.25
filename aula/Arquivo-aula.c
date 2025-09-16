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
