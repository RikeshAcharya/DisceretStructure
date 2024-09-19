// C program to find the cartesian product of two set
#include <stdio.h>
void printCartesianProduct(int set1[], int set2[], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d, %d) ", set1[i], set2[j]);
        }
        printf("\n");
    }
}

int main() {
    int set1[] = {1, 2, 3};
    int set2[] = {4, 5, 6};
    int m = sizeof(set1) / sizeof(set1[0]);
    int n = sizeof(set2) / sizeof(set2[0]);

    printf("Cartesian product of two sets:\n");
    printCartesianProduct(set1, set2, m, n);

    return 0;
}