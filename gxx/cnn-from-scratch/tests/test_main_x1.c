#include "../include/cnn.h"
#include <stdio.h>

int main() {
    int in_channels = 1, in_height = 5, in_width = 5;
    int kernel_size = 3, stride = 1, padding = 1;

    // Allocate input tensor
    float ***input = allocate_3d_tensor(in_channels, in_height, in_width);

    // Initialize input tensor (example)
    for (int c = 0; c < in_channels; c++) {
        for (int i = 0; i < in_height; i++) {
            for (int j = 0; j < in_width; j++) {
                input[c][i][j] = rand() % 10;
            }
        }
    }

    // Free tensor
    free_3d_tensor(input, in_channels, in_height);

    return 0;
}
