// feito em dupla com Julia Dos Santos Mota

#include <stdio.h>

#include <stdio.h>
int tabuleiro[9][9];

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

void resolvedor_sudoku() {
    int preenchido;
    do {
        preenchido = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (tabuleiro[i][j] == 0) {
                    int candidato = 0;
                    int contagem = 0;
                    
                    for (int numero = 1; numero <= 9; numero++) {
                        if (eh_valido(i, j, numero)) {
                            candidato = numero;
                            contagem++;
                        }
                    }
                    
                    if (contagem == 1) {
                        tabuleiro[i][j] = candidato;
                        preenchido = 1;
                    }
                }
            }
        }
    } while (preenchido);
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
   
    printf("\n         ---RESOLVEDOR DE SUDOKU---\n");
    printf("\nTabuleiro Inicial:");
    mostrar_tabuleiro();
    
    resolvedor_sudoku();
    
    printf("\nTabuleiro Resolvido:");
    mostrar_tabuleiro();
    
    return 0;
}
