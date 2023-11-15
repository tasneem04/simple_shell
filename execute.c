#include "shell.h"

#define MAX_INPUT_LENGTH 100

void execute(const char *command, char *const arguments[]) 
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        
        if (execve(command, arguments, NULL)  == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        
        int status;
        waitpid(pid, &status, 0);
        
    }
}
