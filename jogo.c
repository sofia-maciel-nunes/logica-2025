//feito em dupla com Julia dos Santos Mota
#include <stdio.h>

int tabuleiro[9][9];

void mostrar_tabuleiro() {
    printf("\n   1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < 9; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < 9; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificar_jogada(int linha, int coluna, int palpite) {
    for (int j = 0; j < 9; j++) {
        if (tabuleiro[linha][j] == palpite) {
            return 0;
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i][coluna] == palpite) {
            return 0;
        }
    }

    int inicio_linha = (linha / 3) * 3;
    int inicio_coluna = (coluna / 3) * 3;
    for (int i = inicio_linha; i < inicio_linha + 3; i++) {
        for (int j = inicio_coluna; j < inicio_coluna + 3; j++) {
            if (tabuleiro[i][j] == palpite) {
                return 0;
            }
        }
    }
    return 1;
}
int verifica_vitoria() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tabuleiro[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    FILE *arquivo = fopen("input2.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: arquivo input2.txt não encontrado\n");
        return 1;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(arquivo, "%d", &tabuleiro[i][j]);
        }
    }
    fclose(arquivo);
    
    printf("\n ==SUDOKU== \n");
    int linha, coluna, palpite;
    while (1) {
        mostrar_tabuleiro();
        printf("\nDigite linha, coluna e palpite (1-9): ");
        scanf("%d %d %d", &linha, &coluna, &palpite);
        linha--;
        coluna--;
        if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8 || palpite < 1 || palpite > 9) {
            printf("\nJogada inválida! Tente outra posição.\n");
            continue;
        }
        if (tabuleiro[linha][coluna] != 0) {
            printf("\nJogada inválida! Posição já ocupada.\n");
            continue;
        }
        if (verificar_jogada(linha, coluna, palpite)) {
            tabuleiro[linha][coluna] = palpite;
            printf("Jogada Aceita!\n");
            if (verifica_vitoria()) {
                mostrar_tabuleiro();
                printf("\nParabéns! Você ganhou!\n");
                break;
            }
        } else {
            printf("\nJogada inválida! Número já existe na linha, coluna ou quadrante.\n");
        }
    }
    return 0;

}
