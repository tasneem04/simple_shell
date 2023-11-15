#include "shell.h"

#define MAX_INPUT_LENGTH 100

int main()
{
char input[MAX_INPUT_LENGTH];
char *args[10]; 

    while (1) {

	    int i = 0;
    char  *token = strtok(input, " ");
       	    printf("Enter a command (type 'exit' to quit): ");

 
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input\n");
            break;  
 	}

        
        input[strcspn(input, "\n")] = '\0';

        
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        
     
          
       while (token != NULL && i < 10) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;  

        execut(args[0], args);
    
    } 

    return 0;

}
