#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 2, y = 3, z = 4;

    // Dynamically allocate memory for a 3D array
    int ***arr = (int ***)malloc(x * sizeof(int **));
    for (int i = 0; i < x; i++) {
        arr[i] = (int **)malloc(y * sizeof(int *));
        for (int j = 0; j < y; j++) {
            arr[i][j] = (int *)malloc(z * sizeof(int));
        }
    }

    // Initialize and print the array elements
    int counter = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                arr[i][j][k] = counter++;
                printf("arr[%d][%d][%d] = %d\n", i, j, k, arr[i][j][k]);
            }
        }
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}
