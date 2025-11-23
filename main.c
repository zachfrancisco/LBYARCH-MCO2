#include <stdio.h>
extern void imgCvtGrayDoubleToInt();

int main() {
    int rows = 0;
    int cols = 0;
    double matrix[500][500] = {0};
    // Zach's machine can only handle a 500 x 500 double 2D array

    scanf("%d", &rows);
    scanf("%d", &cols);
    printf("rows = %d\ncols = %d\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }

    imgCvtGrayDoubleToInt((double*)matrix, rows, cols);
    return 0;
}