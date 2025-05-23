#include <stdio.h>
#include <string.h>
#include <ctype.h>

void primeirapassada(char *str) {
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] += 3;
        }
    }
}

void segundapassada(char *str) {
    
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void terceirapassada(char *str) {
    
    int len = strlen(str);
    int metade = len / 2;
    
    for (int i = metade; i < len; i++) {
        str[i] -= 1;
    }
}

void criptografar(char *str) {
    
    primeirapassada(str);
    segundapassada(str);
    terceirapassada(str);
}

int main() {
    int N;
    
    scanf("%d", &N);
    
    getchar();
    
    for (int i = 0; i < N; i++) {
        char linha[1001];
        fgets(linha, sizeof(linha), stdin);
        
        
        linha[strcspn(linha, "\n")] = '\0';
        
        criptografar(linha);
        printf("%s\n", linha);
    }
    
    return 0;
}
