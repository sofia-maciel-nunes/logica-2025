// feito em dupla com Julia Dos Santos Mota

#include <stdio.h>

int tabuleiro[9][9];

void mostrarTabuleiro() {
    printf("\n  1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 9; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificarNumero(int linha, int coluna, int numero) {
    for (int j = 0; j < 9; j++) {
        if (tabuleiro[linha][j] == numero) {
            return 0;
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i][coluna] == numero) {
            return 0;
        }
    }
    
    int startI = (linha / 3) * 3;
    int startJ = (coluna / 3) * 3;
    for (int i = startI; i < startI + 3; i++) {
        for (int j = startJ; j < startJ + 3; j++) {
            if (tabuleiro[i][j] == numero) {
                return 0;
            }
        }
    }
    
    return 1;
}
int resolverSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tabuleiro[i][j] == 0) {
                for (int numero = 1; numero <= 9; numero++) {
                    if (verificarNumero(i, j, numero)) {
                        tabuleiro[i][j] = numero;
                        
                        if (resolverSudoku()) {
                            return 1; 
                        }
                        tabuleiro[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    FILE *arquivo = fopen("input2.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro: arquivo input2.txt não encontrado!\n");
        printf("Crie o arquivo com 9 linhas de 9 números cada (use 0 para vazios).\n");
        return 1;
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fscanf(arquivo, "%d", &tabuleiro[i][j]) != 1) {
                printf("Erro ao ler o arquivo!\n");
                fclose(arquivo);
                return 1;
            }
        }
    }
    fclose(arquivo);
    
    printf("--- RESOLVEDOR DE SUDOKU ---\n");
    printf("Tabuleiro original:");
    mostrarTabuleiro();
    
    printf("\nResolvendo...\n");
    
    if (resolverSudoku()) {
        printf("Sudoku resolvido:");
        mostrarTabuleiro();
    } else {
        printf("Este Sudoku não tem solução!\n");
    }
    
    return 0;
}
