#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char grupo[20];
    int horas;
} Elfo;

int tempo_por_presente(char grupo[]) {
    if (strcmp(grupo, "bonecos") == 0) return 8;
    else if (strcmp(grupo, "arquitetos") == 0) return 4;
    else if (strcmp(grupo, "musicos") == 0) return 6;
    else if (strcmp(grupo, "desenhistas") == 0) return 12;
    return 1; 
}

int main() {
    int N, total_presentes = 0;
    scanf("%d", &N);

    Elfo elfos[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d", elfos[i].nome, elfos[i].grupo, &elfos[i].horas);
    }

    for (int i = 0; i < N; i++) {
        int tempo = tempo_por_presente(elfos[i].grupo);
        int presentes = elfos[i].horas / tempo;
        total_presentes += presentes;
    }

    printf("%d\n", total_presentes);
    return 0;
}
