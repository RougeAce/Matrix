#include <stdio.h>
#include <stdlib.h>  // Include the <stdlib.h> header
#include "create_array.h"

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

int main(void) {
    int* array_1 = create_array(6);

    int* array_2 = create_array(6);

    int* result = sub_vector(array_1, array_2, 6);  // Fix the function call and provide the correct length

    for (int i = 0; i < 6; i++) {  // Fix the loop variable declaration
        printf("%d ", result[i]);
    }
    printf("\n");

    free(array_1);  // Free the dynamically allocated memory
    free(array_2);
    free(result);

    return 0;
}
