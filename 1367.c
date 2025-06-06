#include <stdio.h>
#include <string.h>

#define MAX_PROBLEMAS 26

int main() {
    int N;

    while (scanf("%d", &N), N != 0) {
       
        int penalidade[MAX_PROBLEMAS] = {0}; 
        int tempo_correct[MAX_PROBLEMAS];    
        for (int i = 0; i < MAX_PROBLEMAS; i++) {
            tempo_correct[i] = -1;
        }

        for (int i = 0; i < N; i++) {
            char problema;
            int tempo;
            char resultado[10];
            scanf(" %c %d %s", &problema, &tempo, resultado);

            int idx = problema - 'A';

            
            if (tempo_correct[idx] != -1) {
                continue;
            }

            if (strcmp(resultado, "correct") == 0) {
                tempo_correct[idx] = tempo; 
            } else {
                penalidade[idx] += 20;      
            }
        }

        int problemas_resolvidos = 0;
        int tempo_total = 0;

        for (int i = 0; i < MAX_PROBLEMAS; i++) {
            if (tempo_correct[i] != -1) {
                problemas_resolvidos++;
                tempo_total += tempo_correct[i] + penalidade[i];
            }
        }

        printf("%d %d\n", problemas_resolvidos, tempo_total);
    }

    return 0;
}
