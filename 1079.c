#include <stdio.h>

int main() {
    int N;
 
    scanf("%d", &N);
 
    for(int i = 0; i < N; i++) {
        float A, B, C;
     
        scanf("%f %f %f", &A, &B, &C);
     
        float media = (A * 2 + B * 3 + C * 5) / (2 + 3 + 5);
     
        printf("%.1f\n", media);
    }
  return 0;
}
