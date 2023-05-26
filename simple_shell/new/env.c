#include "shell.h"

/**
 * env_command - env command
 */

void env_command(void)
{
	char *env = environ;

	while (env != NULL)
	{
		printf("%s\n", env);
		env++;
	}
}

/**
 * unsetenv_command - unset env variable
 * @cmd: cmd
 */

void unsetenv_command(Command *cmd)
{
	if (cmd->num_tokens == 1)
		printf("unsetenv: missing variable name\n");
	else
	{
		int i = 1;

		while (cmd->tokens[i] != NULL)
		{
			if (unsetenv(cmd->tokens[i]) == -1)
			{
				perror("unsetenv");
			}
			i++;
		}
	}
}

/**
 * setenv_command - set env variable
 * @cmd: cmd
 */

void setenv_command(Command *cmd)
{
	if (cmd->num_tokens == 1)
		printf("setenv: missing variable name\n");

	else if (cmd->num_tokens == 2)
	{
		if (setenv(cmd->tokens[1], "", 1) == -1)
			perror("setenv");
	}

	else if (cmd->num_tokens == 3)
	{
		if (setenv(cmd->tokens[1], cmd->tokens[2], 1) == -1)
			perror("setenv");
	}

	else
		printf("setenv: too many arguments\n");
}
