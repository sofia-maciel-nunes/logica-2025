#include <stdio.h>
#include <string.h>

int ehvogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    char risada[51], vogais[51];
    int i, j = 0;

    scanf("%s", risada);

    for (i = 0; risada[i] != '\0'; i++) {
        if (ehvogal(risada[i])) {
            vogais[j++] = risada[i];
        }
    }
    vogais[j] = '\0'; 

    int palindromo = 1;
    for (i = 0; i < j / 2; i++) {
        if (vogais[i] != vogais[j - 1 - i]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
