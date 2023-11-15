#include "shell.h"

#define MAX_INPUT_LENGTH 100

int main()
{
char input[MAX_INPUT_LENGTH];
char *args[10]; 

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
         int i = 0;
        token = strtok(input, " ");
        while (token != NULL && i < 10) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  // Null-terminate the argument array



	// Get the PATH environment variable
        char *path = getenv("PATH");
        if (path == NULL) {
            perror("getenv");
            exit(EXIT_FAILURE);
        }

        // Tokenize the PATH variable
        char *path_token;
        path_token = strtok(path, ":");

        // Flag to check if the command is found in any directory
        int commandFound = 0;

        // Check each directory in the PATH for the command
        while (path_token != NULL) {
            // Construct the full path to the command
            char commandPath[1024];
            snprintf(commandPath, sizeof(commandPath), "%s/%s", path_token, args[0]);

            // Check if the command exists in this directory
            if (access(commandPath, X_OK) == 0) {
                // Command found, execute it
		execut(commandPath, args);
                //executeCommand(commandPath, args);
                commandFound = 1;
                break;
            }

            // Move to the next directory in PATH
            path_token = strtok(NULL, ":");
        }

        if (!commandFound) {
            printf("Command not found: %s\n", args[0]);
        }
    
  

    } 

    return 0;

}
