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

// Polynomial Kernel function: (x . x' + c)^d
double polynomial_kernel(double* x, double* x_prime, int n, double c, int d) {
    double dot_prod = dot_product(x, x_prime, n);  // Compute dot product
    return pow(dot_prod + c, d);  // Apply polynomial kernel formula
}

int main() {
    // Example vectors (data points)
    double x[] = {1.0, 2.0};  // Point 1 (2D)
    double x_prime[] = {3.0, 4.0};  // Point 2 (2D)
    int n = 2;  // Dimension of the vectors
    double c = 1.0;  // Constant term in the polynomial kernel
    int d = 3;  // Degree of the polynomial kernel

    // Compute the polynomial kernel between x and x_prime
    double kernel_value = polynomial_kernel(x, x_prime, n, c, d);
    
    // Print the result
    printf("Polynomial Kernel between x and x_prime: %f\n", kernel_value);
    
    return 0;
}
