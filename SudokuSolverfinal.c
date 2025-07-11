// feito em dupla com Julia Dos Santos Mota

#include <stdio.h>

int tabuleiro[9][9];
int contador_solucoes = 0;

void mostrar_tabuleiro() {
    printf("\n     1 2 3   4 5 6   7 8 9\n");
    printf("   +-------+-------+-------+\n");
    
    for (int i = 0; i < 9; i++) {
        printf("%d  | ", i + 1);
        
        for (int j = 0; j < 9; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("* ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
            
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("|\n");
        
        if (i == 2 || i == 5) {
            printf("   +-------+-------+-------+\n");
        }
    }
    printf("   +-------+-------+-------+\n");
}

int eh_valido(int linha, int coluna, int numero) {
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
    
    int inicio_linha = (linha / 3) * 3;
    int inicio_coluna = (coluna / 3) * 3;
    for (int i = inicio_linha; i < inicio_linha + 3; i++) {
        for (int j = inicio_coluna; j < inicio_coluna + 3; j++) {
            if (tabuleiro[i][j] == numero) {
                return 0;
            }
        }
    }
    return 1;
}

int encontrar_zeros(int *linha, int *coluna) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tabuleiro[i][j] == 0) {
                *linha = i;
                *coluna = j;
                return 1;
            }
        }
    }
    return 0;
}

void resolver_sudoku_final() {
    int linha, coluna;
    
    if (!encontrar_zeros(&linha, &coluna)) {
        contador_solucoes++;
        printf("\n    ------ SOLUÇÃO %d ------", contador_solucoes);
        mostrar_tabuleiro();
        return;
    }
    
    for (int numero = 1; numero <= 9; numero++) {
        if (eh_valido(linha, coluna, numero)) {
            tabuleiro[linha][coluna] = numero;
            
            resolver_sudoku_final();
            
            tabuleiro[linha][coluna] = 0;
        }
    }
}

int solucao() {
    int linha, coluna;
    
    if (!encontrar_zeros(&linha, &coluna)) {
        return 1;
    }
    
    for (int numero = 1; numero <= 9; numero++) {
        if (eh_valido(linha, coluna, numero)) {
            tabuleiro[linha][coluna] = numero;
            
            if (solucao()) {
                return 1;
            }
            
            tabuleiro[linha][coluna] = 0;
        }
    }
    return 0;
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
   
    printf("\n ---RESOLVEDOR DE SUDOKU---\n");
    printf("\n      Tabuleiro Inicial:");
    mostrar_tabuleiro();
    
    int tabuleiro_inicial[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            tabuleiro_inicial[i][j] = tabuleiro[i][j];
        }
    }
    
    contador_solucoes = 0;
    resolver_sudoku_final();
    

    printf("Total de soluções encontradas: %d\n", contador_solucoes);
    
    if (contador_solucoes == 0) {
        printf("Este sudoku não tem solução!\n");

    }
    
    return 0;
}
