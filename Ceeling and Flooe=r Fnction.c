#include <stdio.h>
#include <math.h>

int main() {
    double num;

    printf("Enter a number: ");
    scanf("%lf", &num);

    double ceiling = ceil(num);
    double floor = floor(num);

    printf("Ceiling of %.2f is %.2f\n", num, ceiling);
    printf("Floor of %.2f is %.2f\n", num, floor);

    return 0;
}2