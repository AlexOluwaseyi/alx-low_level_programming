#include "shell.h"

/**
 * tokenize_command - tokenize command
 * @command: command
 * @cmd: cmd
 */

void tokenize_command(char *command, Command *cmd)
{
	char *token = strtok(command, " \t\n");

	cmd->num_tokens = 0;

	while (token != NULL)
	{
		cmd->tokens[cmd->num_tokens++] = token;
		token = strtok(NULL, " \t\n");
	}

	cmd->tokens[cmd->num_tokens] = NULL;
}
