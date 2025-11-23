#include <stdio.h>
extern void imgCvtGrayDoubltToInt();

int main() {
    int rows = 0;
    int cols = 0;
    float matrix[1000][1000];

    scanf("%d", &rows);
    scanf("%d", &cols);
    printf("rows = %d\ncols = %d", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }

    imgCvtGrayDoubltToInt((float*)matrix, rows, cols);
    return 0;
}