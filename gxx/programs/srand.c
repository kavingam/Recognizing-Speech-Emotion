#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // For time() function

int main() {
    // Seed the random number generator using the current time
    srand(time(NULL)); // time(NULL) returns the current time in seconds

    // Generate and print 5 random numbers between 0 and RAND_MAX
    printf("Random numbers between 0 and RAND_MAX:\n");
    for (int i = 0; i < 5; i++) {
        int randNum = rand(); // Generates a random number
        printf("%d\n", randNum);
    }

    // Generate random numbers in a specific range (1 to 100)
    printf("\nRandom numbers between 1 and 100:\n");
    for (int i = 0; i < 5; i++) {
        int randInRange = (rand() % 100) + 1; // Generates a random number between 1 and 100
        printf("%d\n", randInRange);
    }

    return 0;
}
