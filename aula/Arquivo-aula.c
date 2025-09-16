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
