#include "shell.h"

/**
 * execute_command - execute_command
 * @cmd: cmd
 */

void execute_command(Command *cmd)
{
	if (cmd->num_tokens > 0)
	{
		if (strcmp(cmd->tokens[0], "exit") == 0)
			exit_command(cmd);
		else if (strcmp(cmd->tokens[0], "cd") == 0)
			cd_command(cmd);
		else if (strcmp(cmd->tokens[0], "setenv") == 0)
			setenv_command(cmd);
		else if (strcmp(cmd->tokens[0], "unsetenv") == 0)
			unsetenv_command(cmd);
		else if (strcmp(cmd->tokens[0], "env") == 0)
			env_command();
		else
			execute_single_command(cmd);
	}
}
