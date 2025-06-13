int main() {
    int A;
    float B;
    char C;
    char D[51]; 

    scanf("%d %f %c %[^\n]", &A, &B, &C, D);

    printf("%d\n", A);
    printf("%.6f\n", B);
    printf("%c\n", C);
    printf("%s\n", D);

    printf("%d\t%.6f\t%c\t%s\n", A, B, C, D);

    printf("%10d%10.6f%10c%10s\n", A, B, C, D);

    return 0;
}
