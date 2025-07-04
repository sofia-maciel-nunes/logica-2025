// fiz em dupla com a Julia Dos Santos Mota

#include <stdio.h>
#include <string.h>


int verificaString (char lista[][50], int quantiaElementos, char valor[]) {
    for (int i = 0; i < quantiaElementos; i++) {
        if (strcmp(lista[i], valor) == 0) return 1;
    }
    return 0;
}

int verificar_sudoku(char matriz[9][9][50]) {
    for (int i = 0; i < 9; i++) {
        char vistos[9][50];
        int cont = 0;
        for (int j = 0; j < 9; j++) {
            if (verificaString(vistos, cont, matriz[i][j])) return 0;
            strcpy(vistos[cont++], matriz[i][j]);
        }
    }

    for (int j = 0; j < 9; j++) {
        char vistos[9][50];
        int cont = 0;
        for (int i = 0; i < 9; i++) {
            if (verificaString(vistos, cont, matriz[i][j])) return 0;
            strcpy(vistos[cont++], matriz[i][j]);
        }
    }

    for (int bloco_i = 0; bloco_i < 3; bloco_i++) {
        for (int bloco_j = 0; bloco_j < 3; bloco_j++) {
            char vistos[9][50];
            int cont = 0;
            for (int i = bloco_i * 3; i < bloco_i * 3 + 3; i++) {
                for (int j = bloco_j * 3; j < bloco_j * 3 + 3; j++) {
                    if (verificaString(vistos, cont, matriz[i][j])) return 0;
                    strcpy(vistos[cont++], matriz[i][j]);
                }
            }
        }
    }
    return 1;
}

int main() {
    FILE *arquivo = fopen("input4.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: não foi possível abrir o arquivo.\n");
        return 1;
    }

    char matriz[9][9][50];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(arquivo, "%s", matriz[i][j]);
        }
    }
    fclose(arquivo);

    if (verificar_sudoku(matriz))
        printf("SIM\n");
    else
        printf("NÃO\n");

    return 0;
}
