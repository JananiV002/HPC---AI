
















#include <stdio.h>
#include <stdlib.h>

void readMatrix(FILE *file, int rows, int cols, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Error reading matrix data from file.\n");
                exit(1);
            }
        }
    }
}

void writeMatrix(FILE *file, int rows, int cols, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

void addMatrices(int rows, int cols, int **A, int **B, int **C) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int rows, cols;

    // Input the size of the matrices
    printf("Enter the number of rows and columns of the matrices: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Invalid input for matrix dimensions.\n");
        return 1;
    }

    // Dynamically allocate memory for matrices
    int **A = (int **)malloc(rows * sizeof(int *));
    int **B = (int **)malloc(rows * sizeof(int *));
    int **C = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        A[i] = (int *)malloc(cols * sizeof(int));
        B[i] = (int *)malloc(cols * sizeof(int));
        C[i] = (int *)malloc(cols * sizeof(int));
    }

    // Open files for reading and writing
    FILE *fileA = fopen("matrixA.txt", "r");
    FILE *fileB = fopen("matrixB.txt", "r");
    FILE *fileC = fopen("matrixC.txt", "w");

    if (fileA == NULL) {
        printf("Error opening matrixA.txt.\n");
        return 1;
    }
    if (fileB == NULL) {
        printf("Error opening matrixB.txt.\n");
        fclose(fileA);
        return 1;
    }
    if (fileC == NULL) {
        printf("Error opening matrixC.txt for writing.\n");
        fclose(fileA);
        fclose(fileB);
        return 1;
    }

    // Read matrices from files
    readMatrix(fileA, rows, cols, A);
    readMatrix(fileB, rows, cols, B);

    // Perform matrix addition
    addMatrices(rows, cols, A, B, C);

    // Write the result to a file
    writeMatrix(fileC, rows, cols, C);

    printf("Matrix addition completed. Result written to matrixC.txt.\n");

    // Close all files
    fclose(fileA);
    fclose(fileB);
    fclose(fileC);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
