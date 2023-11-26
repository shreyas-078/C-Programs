#include <stdio.h>

int main(void) {
    int a[50][50], b[50][50], c[50][50], row1, col1, row2, col2, i, j, k;
    printf("Enter number of rows of first matrix:\n");
    scanf("%d", &row1);
    printf("Enter number of columns of first matrix:\n");
    scanf("%d", &col1);
    printf("Enter elements of first array:\n");
    for(i=0; i<row1; i++) {
        for(j=0; j<col1; j++) {
            scanf("%d" ,&a[i][j]);
        }
    }
    printf("Enter number of rows of second matrix:\n");
    scanf("%d", &row2);
    printf("Enter number of columns of second matrix:\n");
    scanf("%d", &col2);
    printf("Enter elements of second array:\n");
    for(i=0; i<row2; i++) {
        for(j=0; j<col2; j++) {
            scanf("%d" ,&b[i][j]);
        }
    }

    for(i=0; i<row1; i++) { 
        for(j=0; j<col2; j++) {
            c[i][j]=0;
            for(k=0; k<row2; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("Product of 2 arrays:\n");
    for(i=0; i<row1; i++) {
        for(j=0; j<col2; j++) {
            printf("%d\n", c[i][j]);
        }
    }
}