#include "shell.h"
/** main :the main function to show the prompt */

int main(void) {
    char *args[2];
    char command[100];
pid_t pid ;
    while(1) {
        printf("#cisfun$ ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        args[0] = command;
        args[1] = NULL;

         pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
           if (execve(args[0], args, NULL) == -1) 
	   {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
           
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
