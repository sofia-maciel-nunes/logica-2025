#include <stdio.h>

int main() {
    int A, B;
    int soma;

    printf("digite dois números inteiros: ");
    
    scanf("%d %d", &A, &B);

    soma = A + B;

    printf("A soma é %d\n", soma);

    return 0;
}
