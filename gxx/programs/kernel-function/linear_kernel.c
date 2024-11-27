#include <stdio.h>

// Function to compute the dot product (linear kernel)
double linear_kernel(double* x, double* x_prime, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += x[i] * x_prime[i];  // Compute the dot product
    }
    return sum;  // Return the linear kernel (dot product)
}

int main() {
    // Example vectors (data points)
    double x[] = {1.0, 2.0};  // Point 1 (2D)
    double x_prime[] = {3.0, 4.0};  // Point 2 (2D)
    int n = 2;  // Dimension of the vectors (length of the vectors)

    // Compute the linear kernel (dot product) between x and x_prime
    double kernel_value = linear_kernel(x, x_prime, n);
    
    // Print the result
    printf("Linear Kernel (Dot Product) between x and x_prime: %f\n", kernel_value);
    
    return 0;
}
