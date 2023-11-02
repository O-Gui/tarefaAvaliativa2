#include <stdio.h>

void lerMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void somarMatrizes(int matrizA[4][4], int matrizB[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void subtrairMatrizes(int matrizA[4][4], int matrizB[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

void multiplicarMatrizes(int matrizA[4][4], int matrizB[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

int main() {
    int matrizA[4][4], matrizB[4][4], resultado[4][4];
    char operacao[10];

    lerMatriz(matrizA);
    lerMatriz(matrizB);

    scanf("%s", operacao);

    if (strcmp(operacao, "soma") == 0) {
        somarMatrizes(matrizA, matrizB, resultado);
    } else if (strcmp(operacao, "sub") == 0) {
        subtrairMatrizes(matrizA, matrizB, resultado);
    } else if (strcmp(operacao, "mult") == 0) {
        multiplicarMatrizes(matrizA, matrizB, resultado);
    }

    imprimirMatriz(resultado);

    return 0;
}