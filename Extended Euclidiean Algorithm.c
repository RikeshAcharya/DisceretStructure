#include<stdio.h>

int extendedEuclidean(int a, int b, int* x, int* y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b, x, y;

    printf("Enter the first number: ");
    scanf("%d", &a);

    printf("Enter the second number: ");
    scanf("%d", &b);

    int gcd = extendedEuclidean(a, b, &x, &y);

    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("Coefficients x and y are %d and %d respectively\n", x, y);

    return 0;
}