#include <stdio.h>
#include <stdlib.h>  

int main() {
    int x,y,z;
    int maiorXY, maior;

    scanf("%d %d %d",&x, &y, &z);
    
    maiorXY = (x + y + abs(x - y)) / 2;
    maior = ( (maiorXY) + z + abs((maiorXY) - z)) / 2;

    printf("%d o maior\n", maior);
 
    return 0;
}
