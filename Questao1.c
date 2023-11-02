#include <stdio.h>

int main() {
    int sequencia[10];

   for (int i = 0; i < 10; i++) {
        scanf("%d", &sequencia[i]);
    }

    int tamanho_atual = 10;

    for (int i = 0; i < 10; i++) {
        printf("%d", sequencia[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    printf("\n");

    while (tamanho_atual > 1) {
        int sequencia2[9];

        for (int i = 0; i < tamanho_atual - 1; i++) {
            sequencia2[i] = sequencia[i] + sequencia[i + 1];
        }

        tamanho_atual--;
        for (int i = 0; i < tamanho_atual; i++) {
            sequencia[i] = sequencia2[i];
        }
        for (int i = 0; i < tamanho_atual; i++) {
            printf("%d", sequencia[i]);
            if (i < tamanho_atual - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}