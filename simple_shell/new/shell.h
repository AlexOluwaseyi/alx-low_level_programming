#ifndef SHELL_H
#define SHELL_H

/* STANDARD LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>


/* GLOBAL DECLARATIONS */
extern int status;
extern char *environ;

char *environ;

#define BUFFER_SIZE 1024
#define MAX_TOKENS 128

typedef struct Command Command;

/**
 * struct Command - Command
 * @tokens: tokens
 * @num_tokens: number of tokens
 */

struct Command
{
	char *tokens[MAX_TOKENS];
	int num_tokens;
};


/* FUNCTION PROTOTYPES */
int get_status(void);
void set_status(int new_status);
void expand_variables(char *command);
void tokenize_command(char *command, Command *cmd);
void execute_command(Command *cmd);
void execute_single_command(Command *cmd);
void execute_logical_and(Command *cmd);
void execute_logical_or(Command *cmd);
void execute_command_with_redirect(Command *cmd, char *output_file);
void execute_command_with_pipe(Command *cmd1, Command *cmd2);
void cd_command(Command *cmd);
void unsetenv_command(Command *cmd);
void setenv_command(Command *cmd);
void env_command(void);
void exit_command(Command *cmd);
void execute_command_from_args(int argc, char *argv[]);



#endif /* ifndef SHELL_H */
