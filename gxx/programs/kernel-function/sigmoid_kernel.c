#include <stdio.h>
#include <math.h>

// Function to compute the dot product (x . x')
double dot_product(double* x, double* x_prime, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i] * x_prime[i];  // Compute the dot product
    }
    return sum;
}

// Sigmoid Kernel function: tanh(alpha * (x . x') + c)
double sigmoid_kernel(double* x, double* x_prime, int n, double alpha, double c) {
    double dot_prod = dot_product(x, x_prime, n);  // Compute dot product
    return tanh(alpha * dot_prod + c);  // Apply sigmoid kernel formula
}

int main() {
    // Example vectors (data points)
    double x[] = {1.0, 2.0};  // Point 1 (2D)
    double x_prime[] = {3.0, 4.0};  // Point 2 (2D)
    int n = 2;  // Dimension of the vectors
    double alpha = 0.5;  // Scaling factor for the sigmoid kernel
    double c = 1.0;  // Constant term in the sigmoid kernel

    // Compute the sigmoid kernel between x and x_prime
    double kernel_value = sigmoid_kernel(x, x_prime, n, alpha, c);
    
    // Print the result
    printf("Sigmoid Kernel between x and x_prime: %f\n", kernel_value);
    
    return 0;
}
