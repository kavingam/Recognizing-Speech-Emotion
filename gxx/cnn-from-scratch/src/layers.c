#include <stdio.h>
#include <stdlib.h>
#include <float.h>

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
             int pool_size, int stride, int pooling_type) {
    // Calculate output dimensions
    int out_height = (in_height - pool_size) / stride + 1;
    int out_width = (in_width - pool_size) / stride + 1;

    // Loop over channels
    for (int c = 0; c < channels; c++) {
        // Loop over output height and width
        for (int oh = 0; oh < out_height; oh++) {
            for (int ow = 0; ow < out_width; ow++) {
                float value;
                if (pooling_type == 0) {
                    value = -FLT_MAX; // For Max Pooling
                } else {
                    value = 0.0; // For Average Pooling
                }

                // Pooling window
                for (int kh = 0; kh < pool_size; kh++) {
                    for (int kw = 0; kw < pool_size; kw++) {
                        int ih = oh * stride + kh; // Map output height to input height
                        int iw = ow * stride + kw; // Map output width to input width
                        if (pooling_type == 0) {
                            // Max Pooling
                            if (input[c][ih][iw] > value) {
                                value = input[c][ih][iw];
                            }
                        } else {
                            // Average Pooling
                            value += input[c][ih][iw];
                        }
                    }
                }

                // Average Pooling: Compute average
                if (pooling_type == 1) {
                    value /= (pool_size * pool_size);
                }

                // Store the result
                output[c][oh][ow] = value;
            }
        }
    }
}
