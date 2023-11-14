#include "shell.h"

#define MAX_INPUT_LENGTH 100

int main()
{
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

        // Tokenize the input into command and arguments
        char *token;
        char *args[10];  // Assuming a maximum of 10 arguments

        int i = 0;
        token = strtok(input, " ");
        while (token != NULL && i < 10) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  // Null-terminate the argument array

        // Execute the command using execve
        execut(args[0], args);
    }

    return 0;

}
