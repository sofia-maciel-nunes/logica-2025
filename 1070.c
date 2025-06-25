#include <stdio.h>

int main() {
    int X, contador = 0;

    scanf("%d", &X);

    while (contador < 6) {
        if (X % 2 != 0) {
            printf("%d\n", X);
            contador++;
        }
        X++;
    }

    return 0;
}
