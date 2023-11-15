#include "shell.h"

#define MAX_INPUT_LENGTH 100

int main() {
    char input[MAX_INPUT_LENGTH];
    pid_t pid;
char *args[10];

    while (1) {
        printf("#cisfun$ ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
          
            char *token;
            int i = 0;

            token = strtok(input, " ");

            while (token != NULL && i < 10) {
                args[i++] = strdup(token);
                token = strtok(NULL, " ");
            }

            args[i] = NULL;

         
            execute(input, args);
            exit(EXIT_SUCCESS);  
        } else {
         
            int status;
            waitpid(pid, &status, 0);
           
	}
    }

    return 0;
}

