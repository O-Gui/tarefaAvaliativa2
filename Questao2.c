#include <stdio.h>
#include <string.h>

struct Jogador {
    char nome[31];
    char posicao;
    int forca;
};

double calcularForca(struct Jogador time[11]) {
    double forca_total = 0.0;
    
    for (int i = 0; i < 11; i++) {
        if (time[i].posicao == 'G') {
            forca_total += 8.0 * time[i].forca;
        } else if (time[i].posicao == 'L') {
            forca_total += 10.0 * time[i].forca;
        } else if (time[i].posicao == 'Z') {
            forca_total += 5.0 * time[i].forca;
        } else if (time[i].posicao == 'V') {
            forca_total += 8.0 * time[i].forca;
        } else if (time[i].posicao == 'M') {
            forca_total += 11.0 * time[i].forca;
        } else if (time[i].posicao == 'A') {
            forca_total += 12.0 * time[i].forca;
        }
    }
    
    return forca_total / 100.0;
}

int main() {
    struct Jogador time1[11];
    struct Jogador time2[11];
    char nome_time1[31];
    char nome_time2[31];

    fgets(nome_time1, sizeof(nome_time1), stdin);
    nome_time1[strcspn(nome_time1, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        char linha[64];
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%30[^;];%c;%d\n", time1[i].nome, &time1[i].posicao, &time1[i].forca);
    }

    fgets(nome_time2, sizeof(nome_time2), stdin);
    nome_time2[strcspn(nome_time2, "\n")] = '\0';

    for (int i = 0; i < 11; i++) {
        char linha[64];
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%30[^;];%c;%d\n", time2[i].nome, &time2[i].posicao, &time2[i].forca);
    }

    double forca_time1 = calcularForca(time1);
    double forca_time2 = calcularForca(time2);
    
    printf("%s: %.2lf de forca\n", nome_time1, forca_time1);
    printf("%s: %.2lf de forca\n", nome_time2, forca_time2);

    if (forca_time1 > forca_time2) {
        printf("%s eh mais forte\n", nome_time1);
    } else if (forca_time2 > forca_time1) {
        printf("%s eh mais forte\n", nome_time2);
    }

    return 0;
}