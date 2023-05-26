#include "shell.h"

/**
 * cd_command - execute cd command
 * @cmd: cmd
 */

void cd_command(Command *cmd)
{
	char current_dir[PATH_MAX];

	if (cmd->num_tokens == 1)
	{
		char *home_dir = getenv("HOME");

		if (home_dir)
		{
			if (chdir(home_dir) == -1)
				perror("chdir");
		} else
			printf("cd: no home directory\n");
	} else if (strcmp(cmd->tokens[1], "-") == 0)
	{
		char *prev_dir = getenv("OLDPWD");

		if (prev_dir)
		{
			if (chdir(prev_dir) == -1)
				perror("chdir");
		} else
			printf("cd: no previous directory\n");
	} else
	{
		if (chdir(cmd->tokens[1]) == -1)
			perror("chdir");
	}

	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
	{
		setenv("PWD", current_dir, 1);
		setenv("OLDPWD", current_dir, 1);
	} else
	{
		perror("getcwd");
	}
}

/**
 * exit_command - executes exit command
 * @cmd: cmd
 */

void exit_command(Command *cmd)
{
	if (cmd->num_tokens == 1)
	{
		exit(EXIT_SUCCESS);
	} else if (cmd->num_tokens == 2)
	{
		int status = atoi(cmd->tokens[1]);

		exit(status);
	} else
	{
		printf("exit: too many arguments\n");
	}
}
