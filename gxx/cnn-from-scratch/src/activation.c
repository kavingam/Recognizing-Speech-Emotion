/*
#include "activation.h"
#include <stdio.h>
#include <stdlib.h>
#include "cnn.h"

// convolutional layers
// implements the convolution operation.
void conv2d(float ***input, float ****filters, float ***output, int in_channels, int out_channels, int kernel_size, int stride, int padding) {
    // Convolution operation: input, filters, and output tensors
    // Allocate memory, apply padding, and perform convolution
}


// activation functions
// implements activation functions like ReLu and softmax
float relu(float x) {
    return x > 0 ? x : 0;
}

void softmax(float *input, float *output, int length) {
    float sum = 0.0;
    for (int i = 0; i < length; i++) {
        output[i] = exp(input[i]);
        sum += output[i];
    }
    for (int i = 0; i < length; i++) {
        output[i] /= sum;
    }
}

// pooling layer
// implements max pooling 
void maxpool(float ***input, float ***output, int channels, int input_size, int pool_size, int stride) {
    // Perform max pooling
}


// fully connected layer
// implements the dense layer for finall classification
void dense(float *input, float *weights, float *bias, float *output, int input_size, int output_size) {
    for (int i = 0; i < output_size; i++) {
        output[i] = 0;
        for (int j = 0; j < input_size; j++) {
            output[i] += input[j] * weights[i * input_size + j];
        }
        output[i] += bias[i];
    }
}

// training (backpropagation)
// implements loss function and weight updates
float cross_entropy_loss(float *predictions, float *labels, int length) {
    float loss = 0.0;
    for (int i = 0; i < length; i++) {
        loss -= labels[i] * log(predictions[i]);
    }
    return loss;
}

void backprop(float *weights, float *bias, float *grad, float learning_rate, int size) {
    for (int i = 0; i < size; i++) {
        weights[i] -= learning_rate * grad[i];
        bias[i] -= learning_rate * grad[i];
    }
}
*/