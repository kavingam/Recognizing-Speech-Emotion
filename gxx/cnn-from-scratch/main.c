#include <stdio.h>
#include <stdlib.h>
#include "include/cnn.h"

/*
int main() {
    // Load dataset
    float ***train_images, ***test_images;
    int *train_labels, *test_labels;
    load_dataset(&train_images, &train_labels, &test_images, &test_labels);

    // Initialize CNN
    CNN cnn;
    cnn_init(&cnn);

    // Train the CNN
    for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
        for (int i = 0; i < NUM_TRAIN_IMAGES; i++) {
            cnn_forward(&cnn, train_images[i]);
            cnn_backward(&cnn, train_labels[i]);
            cnn_update(&cnn, LEARNING_RATE);
        }
    }

    // Test the CNN
    float accuracy = cnn_test(&cnn, test_images, test_labels);
    printf("Test Accuracy: %.2f%%\n", accuracy * 100);

    // Clean up
    cnn_free(&cnn);
    free_dataset(train_images, train_labels, test_images, test_labels);

    return 0;
}
*/

/*
int main() {
    int in_channels = 1, out_channels = 1, kernel_size = 3, stride = 1, padding = 1;
    int in_height = 5, in_width = 5;

    // Allocate and initialize input tensor
    float ***input = (float ***)malloc(in_channels * sizeof(float **));
    for (int c = 0; c < in_channels; c++) {
        input[c] = (float **)malloc(in_height * sizeof(float *));
        for (int i = 0; i < in_height; i++) {
            input[c][i] = (float *)malloc(in_width * sizeof(float));
            for (int j = 0; j < in_width; j++) {
                input[c][i][j] = rand() % 10; // Random initialization
            }
        }
    }

    // Allocate and initialize filters and biases
    float ****filters = (float ****)malloc(out_channels * sizeof(float ***));
    float *biases = (float *)malloc(out_channels * sizeof(float));
    for (int oc = 0; oc < out_channels; oc++) {
        filters[oc] = (float ***)malloc(in_channels * sizeof(float **));
        for (int ic = 0; ic < in_channels; ic++) {
            filters[oc][ic] = (float **)malloc(kernel_size * sizeof(float *));
            for (int kh = 0; kh < kernel_size; kh++) {
                filters[oc][ic][kh] = (float *)malloc(kernel_size * sizeof(float));
                for (int kw = 0; kw < kernel_size; kw++) {
                    filters[oc][ic][kh][kw] = 1.0; // Example: all ones
                }
            }
        }
        biases[oc] = 0.0; // No bias
    }

    // Allocate output tensor
    int out_height = (in_height - kernel_size + 2 * padding) / stride + 1;
    int out_width = (in_width - kernel_size + 2 * padding) / stride + 1;
    float ***output = (float ***)malloc(out_channels * sizeof(float **));
    for (int oc = 0; oc < out_channels; oc++) {
        output[oc] = (float **)malloc(out_height * sizeof(float *));
        for (int oh = 0; oh < out_height; oh++) {
            output[oc][oh] = (float *)malloc(out_width * sizeof(float));
        }
    }

    // Perform convolution
    conv2d(input, filters, biases, output, in_channels, out_channels, in_height, in_width, kernel_size, stride, padding);

    // Free memory (skipped here for brevity)

    return 0;
}
*/

int main() {
    int channels = 1, in_height = 4, in_width = 4;
    int pool_size = 2, stride = 2;

    // Allocate and initialize input tensor
    float ***input = (float ***)malloc(channels * sizeof(float **));
    for (int c = 0; c < channels; c++) {
        input[c] = (float **)malloc(in_height * sizeof(float *));
        for (int i = 0; i < in_height; i++) {
            input[c][i] = (float *)malloc(in_width * sizeof(float));
            for (int j = 0; j < in_width; j++) {
                input[c][i][j] = rand() % 10; // Random values for testing
            }
        }
    }

    // Print input tensor
    printf("Input Tensor:\n");
    for (int i = 0; i < in_height; i++) {
        for (int j = 0; j < in_width; j++) {
            printf("%.1f ", input[0][i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Calculate output dimensions
    int out_height = (in_height - pool_size) / stride + 1;
    int out_width = (in_width - pool_size) / stride + 1;

    // Allocate output tensor
    float ***output = (float ***)malloc(channels * sizeof(float **));
    for (int c = 0; c < channels; c++) {
        output[c] = (float **)malloc(out_height * sizeof(float *));
        for (int i = 0; i < out_height; i++) {
            output[c][i] = (float *)malloc(out_width * sizeof(float));
        }
    }

    // Perform Max Pooling
    pooling(input, output, channels, in_height, in_width, pool_size, stride, 0);

    // Print output tensor
    printf("Max-Pooled Tensor:\n");
    for (int i = 0; i < out_height; i++) {
        for (int j = 0; j < out_width; j++) {
            printf("%.1f ", output[0][i][j]);
        }
        printf("\n");
    }

    // Free memory (for simplicity, not fully shown here)
    for (int c = 0; c < channels; c++) {
        for (int i = 0; i < in_height; i++) {
            free(input[c][i]);
        }
        free(input[c]);
    }
    free(input);

    for (int c = 0; c < channels; c++) {
        for (int i = 0; i < out_height; i++) {
            free(output[c][i]);
        }
        free(output[c]);
    }
    free(output);

}