#include <stdio.h>
#include <stdlib.h>  // Include the <stdlib.h> header
#include "create_array.h"

int** create_matrix(int matrix_columns, int matrix_rows) {
    int** matrix = malloc(matrix_columns * sizeof(int*));

    for (int i = 0; i < matrix_columns; i++) {
        matrix[i] = create_array(matrix_rows);
    }

    return matrix;
}

int* create_array(int array_length) {
    int* array = malloc(array_length * sizeof(int));
    int x;

    for (int i = 0; i < array_length; i++) {
        printf("Enter value %d: ", i);
        scanf("%d", &x);
        array[i] = x;
    }
    
    return array;
}

int** add_matrix(const int** matrix1, const int** matrix2, int rows, int columns) {
    int** result_matrix = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        result_matrix[i] = malloc(columns * sizeof(int));

        for (int j = 0; j < columns; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result_matrix;
}

int** sub_matrix(const int** matrix1, const int** matrix2, int rows, int columns) {
    int** result_matrix = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        result_matrix[i] = malloc(columns * sizeof(int));

        for (int j = 0; j < columns; j++) {
            result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result_matrix;
}


int* add_vector(const int array1[], const int array2[], int length) {
    int* result_array = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        result_array[i] = array1[i] + array2[i];
    }

    return result_array;
}

int* sub_vector(const int array1[], const int array2[], int length) {
    int* result_array = malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        result_array[i] = array1[i] - array2[i];
    }

    return result_array;
}

int main() {

    int x, y;

    printf("How many rows would you like: ");
    scanf("%d", &x);

    printf("How many columns would you like: ");
    scanf("%d", &y);

    int matrix_columns = x;
    int matrix_rows = y;

    int** matrix = create_matrix(matrix_columns, matrix_rows);

    int** matrix2 = create_matrix(matrix_columns, matrix_rows);

    int** answer = add_matrix(matrix, matrix2, x, y);

    // Print the resulting matrix
    printf("Resulting Matrix:\n");
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_columns; j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    free(matrix2);
    free(answer);

    

    return 0;
}
