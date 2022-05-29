/*  basic_shell.c
 *
 * 
 *  Author: Adrien Lapointe and Vincent Roberge and Stephen McKeon
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

const unsigned int cmd_max_len = 1024;
const unsigned int max_num_arg = 64;

void welcome_prompt();
void parse(char *input, char **argv);
void type_prompt(char *input);
void interpret_command(char **argv);

int main() {

    char input[cmd_max_len];	// the input
    char *argv[max_num_arg];	// the arguments

    welcome_prompt();

    while (1) {
        type_prompt(input);
        parse(input, argv);
        interpret_command(argv);
    }

    return 0;
}

/*
 * This functions prints the prompt message and accepts input from the user.
 */
void type_prompt(char *input) {

    printf("EEE335$");

    if (input != NULL) {
        int c = EOF;
        int i = 0;

        // Accepts input until user hits enter or end of file is encountered.
        while ((c = getchar()) != '\n' && c != EOF) {
            input[i++] = (char)c;
        }

        // Finish with a null terminating char
        input[i] = '\0';
    }
}


/*
 * This function parses the user inputs.
 */
void parse(char *input, char **argv) {
	char delimiters[] = " ";
	int i = 0;
	argv[i] = strtok(input, delimiters);
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, delimiters);
	}
}

/*
 * This function interprets the parsed command that is entered by the user and
 * calls the appropriate built-in function or calls the appropriate program.
 */
void interpret_command(char **argv) {
    //Variables required to hold errors, process ids, statuses, and buffer size
    int error;						// check for errors
	int pid;						// process id
	int status;						// status of child creation
    const int BUFFER_SIZE = 500;
	char buffer[BUFFER_SIZE];		// buffer used when printing to the console
    DIR *curr_dir;					// ptr to current directory
    struct dirent *entry;			// ptr to directory entry

    // The 'exit' function
    if (strcmp(argv[0], "exit") == 0){
        printf("Goodbye");
        exit(0);
    }

    // The 'cd' function
    else if(strcmp(argv[0], "cd") == 0){
    	printf("%s\n", argv[1]);
    	error = chdir(argv[1]);
        if (error == 0)
        	printf("Changing to: %s\n", argv[1]);
        else
            printf("No such directory\n");
    }

    // The 'ls' function
    else if (strcmp(argv[0], "ls") == 0){
        // Get the current directory and open it
        getcwd(buffer, BUFFER_SIZE);
        curr_dir = opendir(buffer);

        // If no error, print all entries
        if(curr_dir != NULL){
            while((entry = readdir(curr_dir)) != NULL){
                printf("%s\n", entry->d_name);
            }
        }
    }

    // The 'pwd' function
    else if (strcmp(argv[0], "pwd") == 0){
        getcwd(buffer, BUFFER_SIZE);
        if(buffer != NULL)
            printf("Current directory: %s\n", buffer);
    }

    //Take care of all other functions
    else{
        pid = fork();
        //Child process
        if(pid == 0){
        	error = execvp(argv[0], argv);
            if (error != 0){
            	printf("%s: %s\n", argv[0], strerror(errno));
                exit(0);
            }
        }
        //Parent process
        else{
            //Wait for child to finish
            waitpid(pid, &status, 0);
        }
        // If the child process is writing to stdout, this wait will ensure the text
        // can be printed to the screen, before our shell prints the next prompt
        usleep(10000);	// wait 10 ms
    }
}

/*
 * This function prints the welcome message.
 */
void welcome_prompt() {
    int num_padding = 41;
    int i;

    // Prints the first line of padding.
    for (i = 0; i < num_padding; i++)
        printf("#");
    printf("\n#\tWelcome to the EEE335 shell\t#\n");
    for (i = 0; i < num_padding; i++)
        printf("#");
    printf("\n\n");
}
