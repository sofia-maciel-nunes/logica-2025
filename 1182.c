#include <stdio.h>

int main() {
    int C;
    char T;
    double M[12][12], resultado = 0.0;
  
    scanf("%d", &C);
    scanf(" %c", &T);  
 
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }

    for (int i = 0; i < 12; i++) {
        resultado += M[i][C];
    }
   
    if (T == 'M') {
        resultado /= 12.0;
    }
  
    printf("%.1lf\n", resultado);

    return 0;
}
