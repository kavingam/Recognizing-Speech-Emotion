#include <stdio.h>
#include <math.h>

// Function to compute the Euclidean distance between two vectors
double euclidean_distance(double* x, double* x_prime, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (x[i] - x_prime[i]) * (x[i] - x_prime[i]);
    }
    return sqrt(sum);
}

// Gaussian RBF Kernel function
double gaussian_kernel(double* x, double* x_prime, int n, double sigma) {
    // Compute the Euclidean distance between x and x_prime
    double dist = euclidean_distance(x, x_prime, n);
    
    // Compute the Gaussian kernel value
    return exp(-dist * dist / (2 * sigma * sigma));
}

int main() {
    // Example vectors (data points)
    double x[] = {1.0, 2.0};  // Point 1 (2D)
    double x_prime[] = {3.0, 4.0};  // Point 2 (2D)
    int n = 2;  // Dimension of the vectors
    double sigma = 1.0;  // Sigma parameter for Gaussian kernel

    // Compute the Gaussian kernel between x and x_prime
    double kernel_value = gaussian_kernel(x, x_prime, n, sigma);
    
    // Print the result
    printf("Gaussian RBF Kernel between x and x_prime: %f\n", kernel_value);
    
    return 0;
}
