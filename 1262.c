#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char hist[55];  
    int P;

    while (scanf("%s", hist) != EOF) {
        scanf("%d", &P);

        int len = strlen(hist);
        int i = 0;
        int ciclos = 0;

        while (i < len) {
            if (hist[i] == 'R') {
                int count_r = 0;
        
                while (i < len && hist[i] == 'R') {
                    count_r++;
                    i++;
                }
               
                ciclos += (count_r + P - 1) / P;
            } else if (hist[i] == 'W') {
                ciclos++;
                i++;
            }
        }

        printf("%d\n", ciclos);
    }

    return 0;
}
