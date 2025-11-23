#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayDoubleToInt(double *matrix_ptr, int *dest_ptr, int rows, int cols);

int main()
{
    clock_t start_time = clock();

    int rows = 0;
    int cols = 0;
    double matrix[500][500] = {0};
    double time = 0.0;

    scanf("%d", &rows);
    scanf("%d", &cols);
    printf("rows = %d\ncols = %d\n", rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    int *int_matrix = (int*)malloc(rows * cols * sizeof(int));

    printf("Input double matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5.2lf ", matrix[i][j]);
        }
        printf("\n");
    }

    imgCvtGrayDoubleToInt((double *)matrix, int_matrix, rows, cols);

    printf("\nConverted integer matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%3d", int_matrix[i * cols + j]);
            if (j < cols - 1)
                printf(", ");
        }
        printf("\n");
    }

    free(int_matrix);

    clock_t end_time = clock();
    time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTime: %.3f seconds", time);

    return 0;
}