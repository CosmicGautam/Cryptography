#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "output.txt"; // File to write to
    FILE *file = fopen(filename, "w");  // Open file in write mode

    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        return 1;
    }

    long long counter = 0; // Counter to track the number of writes

    while (1) { // Infinite loop
        // Write a line of text to the file
        fprintf(file, "This is line %lld in the file.\n", counter);

        // Check for errors while writing
        if (ferror(file)) {
            printf("Error: Failed to write to file.\n");
            break;
        }

        counter++;

        // Print progress every 1000 writes
        if (counter % 1000 == 0) {
            printf("Written %lld lines...\n", counter);
        }
    }

    fclose(file); // Close the file
    printf("File writing stopped after %lld lines.\n", counter);

    return 0;
}
