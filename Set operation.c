#include <stdio.h>

// Function to print a set
void printSet(int set[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

// Function to find the union of two sets
void unionSet(int set1[], int set2[], int m, int n, int unionSet[]) {
    int i, j, k = 0;
    for (i = 0; i < m; i++) {
        unionSet[k++] = set1[i];
    }
    for (i = 0; i < n; i++) {
        int flag = 0;
        for (j = 0; j < m; j++) {
            if (set2[i] == set1[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            unionSet[k++] = set2[i];
        }
    }
}

// Function to find the intersection of two sets
void intersectionSet(int set1[], int set2[], int m, int n, int intersectionSet[]) {
    int i, j, k = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (set1[i] == set2[j]) {
                intersectionSet[k++] = set1[i];
                break;
            }
        }
    }
}

// Function to find the difference of two sets
void differenceSet(int set1[], int set2[], int m, int n, int differenceSet[]) {
    int i, j, k = 0;
    for (i = 0; i < m; i++) {
        int flag = 0;
        for (j = 0; j < n; j++) {
            if (set1[i] == set2[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            differenceSet[k++] = set1[i];
        }
    }
}

int main() {
    int set1[] = {1, 2, 3, 4};
    int set2[] = {3, 4, 5, 6};
    int m = sizeof(set1) / sizeof(set1[0]);
    int n = sizeof(set2) / sizeof(set2[0]);

    int unionSet[m + n];
    int intersectionSet[m];
    int differenceSet[m];

    unionSet(m, n, unionSet);
    intersectionSet(m, n, intersectionSet);
    differenceSet(m, n, differenceSet);

    printf("Set A: ");
    printSet(set1, m);
    printf("Set B: ");
    printSet(set2, n);

    printf("Union of A and B: ");
    printSet(unionSet, m + n);
    printf("Intersection of A and B: ");
    printSet(intersectionSet, m);
    printf("Difference of A and B: ");
    printSet(differenceSet, m);

    return 0;
}