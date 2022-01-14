//Author: Garrett Giddings | Date: 6/7/2020
#include <stdio.h>
#include <stdlib.h>
void Array(int row, int column, int a[row][column]);
void Array(int row, int column, int a[row][column]) {
    int i, j;

    for (i = 0; i < row; i++) {
        printf("\n");
        for (j = 0; j < column; j++)
            printf("%5d", a[i][j]);
    }
    printf("\n");
}

int main(void) {
    int max, min, n, sum, rowM, columnM;

    printf("\nEnter the size of a 2D square array: ");
    scanf("%d", &n);
    rowM = n;
    columnM = n;
    int ar[rowM][columnM];
    printf("\n");

    printf("Enter min and max of random numbers to fill in the array.\n");
    printf("For example, enter -12...8 if min is -12 and max is 8, they must be separated by\n");
    printf("'...': \t");
    scanf("%d...%d", &min, &max);

    for (int i = 0; i < rowM; ++i) {
        for (int j = 0; j < columnM; ++j) {
            ar[i][j] = (min + rand() % (max + 1 - min));
        }
    }

    Array( rowM, columnM, ar );

    printf("\nRow totals:");
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            sum += ar[i][j];
        }
        printf(" %d", sum);
    }

    printf("\nColumn totals:");
    for (int j = 0; j < n; j++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar[i][j];
        }
        printf(" %d", sum);
    }
    printf("\n");
    return 0;
}