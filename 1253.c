#include <stdio.h>
#include <string.h>

void decodificar(char *mensagem, int deslocamento) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z') {
            mensagem[i] -= deslocamento;
            if (mensagem[i] < 'A') {
                mensagem[i] += 26; 
            }
        }
    }
}

int main() {
    int N;

    scanf("%d", &N);
    
    getchar(); 

    for (int i = 0; i < N; i++) {
        char mensagem[51];
        int deslocamento;

        fgets(mensagem, sizeof(mensagem), stdin);
        mensagem[strcspn(mensagem, "\n")] = '\0'; 

        scanf("%d", &deslocamento);
        
        getchar(); 

        decodificar(mensagem, deslocamento);

        printf("%s\n", mensagem);
    }

    return 0;
}
