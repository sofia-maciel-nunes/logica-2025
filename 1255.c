#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int N;
    
    scanf("%d", &N);
    while (getchar() != '\n');
    
    for (int i = 0; i < N; i++) {
        char linha[201];
        int freq[26] = {0};

        fgets(linha, sizeof(linha), stdin);

        for (int j = 0; linha[j] != '\0'; j++) {
            if (isalpha(linha[j])) {
                char c = tolower(linha[j]);
                freq[c - 'a']++;
            }
        }

        int maxFreq = 0;
        for (int j = 0; j < 26; j++) {
            if (freq[j] > maxFreq) {
                maxFreq = freq[j];
            }
        }

        for (int j = 0; j < 26; j++) {
            if (freq[j] == maxFreq) {
                printf("%c", 'a' + j);
            }
        }
        printf("\n");
    }

    return 0;
}
