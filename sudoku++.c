// feito em dupla com Julia Dos Santos Mota

#include <stdio.h>
#include <string.h>

#define TAMANHO 9

int eh_valido(int matriz[TAMANHO][TAMANHO]) {
	int i, j, k;

	for (i = 0; i < TAMANHO; i++) {
		int freq[11] = {0};
		for (j = 0; j < TAMANHO; j++) {
			int num = matriz[i][j];
			if (num < 1 || num > 10 || freq[num]) return 0;
			freq[num] = 1;
		}
	}

	for (j = 0; j < TAMANHO; j++) {
		int freq[11] = {0};
		for (i = 0; i < TAMANHO; i++) {
			int num = matriz[i][j];
			if (num < 1 || num > 10 || freq[num]) return 0;
			freq[num] = 1;
		}
	}
	for (j = 0; j < TAMANHO; j++) {
		int freq[11] = {0};
		for (i = 0; i < TAMANHO; i++) {
			int num = matriz[i][j];
			if (num < 1 || num > 10 || freq[num]) return 0;
			freq[num] = 1;
		}
	}

	for (int bloco_i = 0; bloco_i < 3; bloco_i++) {
		for (int bloco_j = 0; bloco_j < 3; bloco_j++) {
			int freq[11] = {0};
			for (i = bloco_i * 3; i < bloco_i * 3 + 3; i++) {
				for (j = bloco_j * 3; j < bloco_j * 3 + 3; j++) {
					int num = matriz[i][j];
					if (num < 1 || num > 10 || freq[num]) return 0;
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

		FILE *arquivo = fopen("input3.txt", "r");
		if (arquivo == NULL) {
			printf("Erro: arquivo input3.txt não encontrado\n");
			return 1;
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
			}
		}
		fclose(arquivo);

		printf("Instância %d\n", instancia++);

		if (eh_valido(matriz))
			printf("SIM\n");
		else
			printf("NÃO\n");

		printf("\n");
	}

	return 0;
}
