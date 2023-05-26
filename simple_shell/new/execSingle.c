#include "shell.h"

/**
 * execute_single_command - execute single command
 * @cmd: cmd
 */

void execute_single_command(Command *cmd)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		execvp(cmd->tokens[0], cmd->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	} else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			set_status(WEXITSTATUS(status));
		}
	}
}

/**
 * execute_command_from_args - Executes command from command line arguments
 * @argc: number of command line arguments
 * @argv: array of arguments
 */

void execute_command_from_args(int argc, char *argv[])
{
	Command cmd;
	int i = 0;

	cmd.num_tokens = argc - 1;
	for (i = 0; i < cmd.num_tokens; i++)
	{
		cmd.tokens[i] = argv[i + 1];
	}
	execute_command(&cmd);
}
