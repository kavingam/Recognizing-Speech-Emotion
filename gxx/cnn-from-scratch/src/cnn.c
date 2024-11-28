#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function for zero-padding
void pad_input(float ***input, float ***padded_input, int in_channels, int height, int width, int pad) {
    int padded_height = height + 2 * pad;
    int padded_width = width + 2 * pad;

    for (int c = 0; c < in_channels; c++) {
        for (int i = 0; i < padded_height; i++) {
            for (int j = 0; j < padded_width; j++) {
                if (i >= pad && i < height + pad && j >= pad && j < width + pad) {
                    padded_input[c][i][j] = input[c][i - pad][j - pad];
                } else {
                    padded_input[c][i][j] = 0; // Zero padding
                }
            }
        }
    }
}

// Convolutional Layer Function
void conv2d(float ***input,        // Input tensor [in_channels][in_height][in_width]
            float ****filters,     // Filter weights [out_channels][in_channels][kernel_size][kernel_size]
            float *biases,         // Biases [out_channels]
            float ***output,       // Output tensor [out_channels][out_height][out_width]
            int in_channels,       // Number of input channels
            int out_channels,      // Number of output channels
            int in_height,         // Input height
            int in_width,          // Input width
            int kernel_size,       // Kernel size (e.g., 3 for 3x3 filters)
            int stride,            // Stride
            int padding) {         // Padding size
    // Compute output dimensions
    int out_height = (in_height - kernel_size + 2 * padding) / stride + 1;
    int out_width = (in_width - kernel_size + 2 * padding) / stride + 1;

    // Allocate padded input if padding > 0
    float ***padded_input = NULL;
    if (padding > 0) {
        int padded_height = in_height + 2 * padding;
        int padded_width = in_width + 2 * padding;
        padded_input = (float ***)malloc(in_channels * sizeof(float **));
        for (int c = 0; c < in_channels; c++) {
            padded_input[c] = (float **)malloc(padded_height * sizeof(float *));
            for (int i = 0; i < padded_height; i++) {
                padded_input[c][i] = (float *)malloc(padded_width * sizeof(float));
            }
        }
        pad_input(input, padded_input, in_channels, in_height, in_width, padding);
    } else {
        padded_input = input; // Use original input if no padding
    }

    // Perform convolution
    for (int oc = 0; oc < out_channels; oc++) { // Loop over output channels
        for (int oh = 0; oh < out_height; oh++) { // Loop over output height
            for (int ow = 0; ow < out_width; ow++) { // Loop over output width
                float sum = 0.0;
                for (int ic = 0; ic < in_channels; ic++) { // Loop over input channels
                    for (int kh = 0; kh < kernel_size; kh++) { // Loop over kernel height
                        for (int kw = 0; kw < kernel_size; kw++) { // Loop over kernel width
                            int ih = oh * stride + kh; // Corresponding input height
                            int iw = ow * stride + kw; // Corresponding input width
                            sum += padded_input[ic][ih][iw] * filters[oc][ic][kh][kw];
                        }
                    }
                }
                sum += biases[oc]; // Add bias
                output[oc][oh][ow] = sum; // Store the result
            }
        }
    }

    // Free padded input if allocated
    if (padding > 0) {
        for (int c = 0; c < in_channels; c++) {
            for (int i = 0; i < in_height + 2 * padding; i++) {
                free(padded_input[c][i]);
            }
            free(padded_input[c]);
        }
        free(padded_input);
    }
}
