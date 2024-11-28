#ifndef CNN_H
#define CNN_H

#include <stdlib.h>
#include <math.h>

// Function Prototypes

/**
 * Performs pooling on a single input tensor.
 *
 * @param input        Input tensor [channels][in_height][in_width].
 * @param output       Output tensor [channels][out_height][out_width].
 * @param channels     Number of input channels.
 * @param in_height    Height of the input tensor.
 * @param in_width     Width of the input tensor.
 * @param pool_size    Pooling window size (assumes square window).
 * @param stride       Stride for the pooling operation.
 * @param pooling_type Type of pooling: 0 for Max Pooling, 1 for Average Pooling.
 */
void pooling(float ***input, float ***output, int channels, int in_height, int in_width,
             int pool_size, int stride, int pooling_type);

// Other function prototypes (e.g., convolution, ReLU, softmax, etc.)

/**
 * Pads the input tensor with zeros.
 * 
 * @param input          The input tensor [in_channels][in_height][in_width].
 * @param padded_input   The output padded tensor.
 * @param in_channels    Number of input channels.
 * @param height         Height of the input tensor.
 * @param width          Width of the input tensor.
 * @param pad            Padding size.
 */
void pad_input(float ***input, float ***padded_input, int in_channels, int height, int width, int pad);

/**
 * Performs 2D convolution on the input tensor.
 * 
 * @param input          The input tensor [in_channels][in_height][in_width].
 * @param filters        The filter weights [out_channels][in_channels][kernel_size][kernel_size].
 * @param biases         The bias values [out_channels].
 * @param output         The output tensor [out_channels][out_height][out_width].
 * @param in_channels    Number of input channels.
 * @param out_channels   Number of output channels.
 * @param in_height      Height of the input tensor.
 * @param in_width       Width of the input tensor.
 * @param kernel_size    Kernel size (assumed square).
 * @param stride         Stride size.
 * @param padding        Padding size.
 */
void conv2d(float ***input, float ****filters, float *biases, float ***output, 
            int in_channels, int out_channels, int in_height, int in_width, 
            int kernel_size, int stride, int padding);

/**
 * Performs ReLU activation on a tensor element.
 * 
 * @param x    Input value.
 * @return     ReLU-activated value.
 */
float relu(float x);

/**
 * Applies the ReLU activation function to a tensor.
 * 
 * @param input          Input tensor.
 * @param output         Output tensor.
 * @param channels       Number of channels.
 * @param height         Height of the tensor.
 * @param width          Width of the tensor.
 */
void apply_relu(float ***input, float ***output, int channels, int height, int width);

/**
 * Applies softmax activation to a 1D array.
 * 
 * @param input          Input array.
 * @param output         Output array after softmax.
 * @param length         Length of the input and output arrays.
 */
void softmax(float *input, float *output, int length);

/**
 * Allocates a 3D tensor dynamically.
 * 
 * @param channels       Number of channels.
 * @param height         Height of the tensor.
 * @param width          Width of the tensor.
 * @return               Pointer to the allocated 3D tensor.
 */
float ***allocate_3d_tensor(int channels, int height, int width);

/**
 * Frees a 3D tensor allocated dynamically.
 * 
 * @param tensor         Pointer to the 3D tensor.
 * @param channels       Number of channels.
 * @param height         Height of the tensor.
 */
void free_3d_tensor(float ***tensor, int channels, int height);

#endif // CNN_H

/*
#ifndef CNN_H
#define CNN_H

#include <stdlib.h>

// Define the CNN structure
typedef struct {
    // Add fields for layers, weights, biases, etc.
} CNN;

// Initialize the CNN
void cnn_init(CNN *cnn);

// Forward pass
void cnn_forward(CNN *cnn, float **input);

// Backward pass
void cnn_backward(CNN *cnn, int label);

// Update weights
void cnn_update(CNN *cnn, float learning_rate);

// Test the CNN
float cnn_test(CNN *cnn, float ***test_images, int *test_labels);

// Free CNN resources
void cnn_free(CNN *cnn);

#endif // CNN_H

*/ 