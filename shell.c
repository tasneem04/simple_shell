#include "shell.h"

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("Enter a command (type 'exit' to quit): ");

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            break;  // Exit the loop on EOF or error
        }

        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Execute the command using system
        int result = system(input);
        if (result == -1) {
            printf("Error executing the command\n");
        } else {
            printf("Command executed with exit status: %d\n", result);
        }
    }

    return 0;
}
