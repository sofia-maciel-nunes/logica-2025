#include <stdio.h>

int main() {
    double valor;
    int notas, moedas;

    scanf("%lf", &valor);

    int centavos = (int)(valor * 100 + 0.5); 
    
    printf("NOTAS:\n");

    int notas_valores[] = {10000, 5000, 2000, 1000, 500, 200};
    for (int i = 0; i < 6; i++) {
        notas = centavos / notas_valores[i];
        centavos %= notas_valores[i];
        printf("%d nota(s) de R$ %.2f\n", notas, notas_valores[i] / 100.0);
    }

    printf("MOEDAS:\n");

    int moedas_valores[] = {100, 50, 25, 10, 5, 1};
    for (int i = 0; i < 6; i++) {
        moedas = centavos / moedas_valores[i];
        centavos %= moedas_valores[i];
        printf("%d moeda(s) de R$ %.2f\n", moedas, moedas_valores[i] / 100.0);
    }

    return 0;
}
