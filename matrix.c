#include <stdio.h>

#define n 10

void inputMatrix(int matrix[n][n], int row, int col) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[n][n], int row, int col) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[n][n], int B[n][n], int row, int col) {
    int result[n][n];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = A[i][j] + B[i][j];

    printf("Addition Result:\n");
    printMatrix(result, row, col);
}

void subtractMatrices(int A[n][n], int B[n][n], int row, int col) {
    int result[n][n];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = A[i][j] - B[i][j];

    printf("Subtraction Result:\n");
    printMatrix(result, row, col);
}

void multiplyMatrices(int A[n][n], int B[n][n], int row1, int col1, int col2) {
    int result[n][n] = {0};
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Multiplication Result:\n");
    printMatrix(result, row1, col2);
}

void transposeMatrix(int matrix[n][n], int row, int col) {
    int transpose[n][n];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            transpose[j][i] = matrix[i][j];

    printf("Transpose:\n");
    printMatrix(transpose, col, row);
}

int main() {
    int A[n][n], B[n][n], row1, col1, row2, col2, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &row1, &col1);
    inputMatrix(A, row1, col1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &row2, &col2);
    inputMatrix(B, row2, col2);

    do {
        printf("\nMenu:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (row1 == row2 && col1 == col2)
                    addMatrices(A, B, row1, col1);
                else
                    printf("Addition not possible (Matrix dimensions must be the same).\n");
                break;
            case 2:
                if (row1 == row2 && col1 == col2)
                    subtractMatrices(A, B, row1, col1);
                else
                    printf("Subtraction not possible (Matrix dimensions must be the same).\n");
                break;
            case 3:
                if (col1 == row2)
                    multiplyMatrices(A, B, row1, col1, col2);
                else
                    printf("Multiplication not possible (Columns of A must match rows of B).\n");
                break;
            case 4:
                printf("Transpose of first matrix:\n");
                transposeMatrix(A, row1, col1);
                printf("Transpose of second matrix:\n");
                transposeMatrix(B, row2, col2);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
