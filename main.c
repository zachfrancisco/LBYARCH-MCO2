#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayDoubleToInt(double *matrix_ptr, int *dest_ptr, int rows, int cols);

int main()
{
    int rows = 0;
    int cols = 0;
    int *int_matrix;
    double matrix[500][500] = {0};
    double nasm_total_time = 0.0;
    double c_total_time = 0.0;

    // Read input
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

    int_matrix = (int *)malloc(rows * cols * sizeof(int));

    // Print input
    printf("Input double matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%5.2lf ", matrix[i][j]);
        }
        printf("\n");
    }

    //C only
    clock_t start_time = clock();
    for (int z = 0; z < 30; z++)
    {
        printf("\n----------------------------------------");
        printf("\nIteration %d:\n", z + 1);

        printf("\nConverted integer matrix:\n");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int_matrix[i * cols + j] = (int)(matrix[i][j] * 255);
                printf("%3d", int_matrix[i * cols + j]);
                if (j < cols - 1)
                    printf(", ");
            }
            printf("\n");
        }
    }
    clock_t end_time = clock();
    c_total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nC Total Time: %.3f seconds", c_total_time);

    //NASM call
    start_time = clock();

    for (int k = 0; k < 30; k++)
    {
        printf("\n----------------------------------------");
        printf("\nIteration %d:\n", k + 1);
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
    }
    end_time = clock();
    nasm_total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nNasm Total Time: %.3f seconds", nasm_total_time);

    // Print final outputs
    printf("\n----------------------------------------");
    printf("\n\nAverage Time C with Nasm: %.3f seconds\n", nasm_total_time / 30.0);
    printf("Total Time C with Nasm: %.3f seconds\n", nasm_total_time);

    printf("\n----------------------------------------");
    printf("\n\nAverage Time C ONLY: %.3f seconds\n", c_total_time / 30.0);
    printf("Total Time C ONLY: %.3f seconds\n", c_total_time);

    return 0;
}