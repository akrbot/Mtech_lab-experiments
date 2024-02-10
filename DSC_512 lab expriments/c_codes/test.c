#include<stdio.h>
#include<conio.h>

int main() {
    int elements[3]; // Array to store the elements
    int numElements = 0; // Variable to keep track of the number of elements entered

    printf("Enter three elements:\n");

    // Read input from the user
    while (numElements < 3) {
        if (scanf("%d", &elements[numElements]) == 1) {
            numElements++; // Increment the count of elements
        } else {
            printf("Invalid input. Please enter an integer.\n");
            // Clear input buffer in case of non-integer input
            while (getchar() != '\n');
            // Exit the program if input is invalid
            return 1;
        }
    }

    // Print the elements if three are entered
    printf("You have entered three elements: %d, %d, %d\n", elements[0], elements[1], elements[2]);

    return 0;
}