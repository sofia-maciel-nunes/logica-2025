#include <stdio.h>

int main() {
    int L;          
    char T;         
    double M[12][12], resultado = 0.0;
    
    scanf("%d", &L);
    scanf(" %c", &T);  
    
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &M[i][j]);
        }
    }
   
    for (int j = 0; j < 12; j++) {
        resultado += M[L][j];
    }
   
    if (T == 'M') {
        resultado /= 12.0;
    }

    
    printf("%.1lf\n", resultado);

    return 0;
}
