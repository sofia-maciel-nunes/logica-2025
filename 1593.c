#include <stdio.h>
#include <string.h>
int dividePor2(char num[]) {
    int len = strlen(num);
    int resto = 0;

    for (int i = 0; i < len; i++) {
        int digito = num[i] - '0' + resto * 10;
        num[i] = (digito / 2) + '0';
        resto = digito % 2;
    }

    int i = 0;
    while (num[i] == '0' && num[i + 1] != '\0') i++;
    if (i > 0) memmove(num, num + i, strlen(num) - i + 1);

    return resto;
}

int contarBits1(char num[]) {
    int count = 0;
    while (!(strlen(num) == 1 && num[0] == '0')) {
        int bit = dividePor2(num);
        if (bit == 1) count++;
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char num[1100]; 
        scanf("%s", num);

        int ones = contarBits1(num);
        printf("%d\n", ones);
    }

    return 0;
}
