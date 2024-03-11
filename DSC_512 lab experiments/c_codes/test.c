#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

int main() {
    char name[MAX_NAME_LENGTH];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LENGTH, stdin); // Read string with spaces

    // Remove trailing newline character, if present
    size_t length = strlen(name);
    if (name[length - 1] == '\n')
        name[length - 1] = '\0';
    
    printf("Name entered: %s\n", name);

    return 0;
}