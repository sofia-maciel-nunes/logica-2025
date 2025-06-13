#include <stdio.h>
#include <string.h>

#define TAMANHO 9

int eh_valido(int matriz[TAMANHO][TAMANHO]) {
    int i, j, k;
    
    for (i = 0; i < TAMANHO; i++) {
        int freq[10] = {0};
        for (j = 0; j < TAMANHO; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || freq[num]) return 0;
            freq[num] = 1;
        }
    }

    for (j = 0; j < TAMANHO; j++) {
        int freq[10] = {0};
        for (i = 0; i < TAMANHO; i++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || freq[num]) return 0;
            freq[num] = 1;
        }
    }
for (j = 0; j < TAMANHO; j++) {
        int freq[10] = {0};
        for (i = 0; i < TAMANHO; i++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || freq[num]) return 0;
            freq[num] = 1;
        }
    }

    for (int bloco_i = 0; bloco_i < 3; bloco_i++) {
        for (int bloco_j = 0; bloco_j < 3; bloco_j++) {
            int freq[10] = {0};
            for (i = bloco_i * 3; i < bloco_i * 3 + 3; i++) {
                for (j = bloco_j * 3; j < bloco_j * 3 + 3; j++) {
                    int num = matriz[i][j];
                    if (num < 1 || num > 9 || freq[num]) return 0;
                    freq[num] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, instancia = 1;
    scanf("%d", &n);

    while (n--) {
        int matriz[TAMANHO][TAMANHO];

        for (int i = 0; i < TAMANHO; i++)
            for (int j = 0; j < TAMANHO; j++)
                scanf("%d", &matriz[i][j]);

        printf("Instancia %d\n", instancia++);

        if (eh_valido(matriz))
            printf("SIM\n");
        else
            printf("NAO\n");

        printf("\n");
    }

    return 0;
}
