#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);

    int X[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    int menor = X[0];
    int posicao = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }

    printf("menor valor: %d\n", menor);
    printf("posicao: %d\n", posicao);

    return 0;
}
