#include <stdio.h>

int main() {
    double valor;
    int positivos = 0;
    double soma = 0.0;

    for (int i = 0; i < 6; i++) {
        scanf("%lf", &valor);

        if (valor > 0) {
            positivos++;
            soma += valor;
        }
    }

    printf("%d valores positivos\n", positivos);
    printf("%.1lf\n", soma / positivos);

    return 0;
}
