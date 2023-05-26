#include "shell.h"

/**
 * execute_command_with_redirect - executes commands with redirections
 * @cmd: cmd
 * @output_file: output file
 */

void execute_command_with_redirect(Command *cmd, char *output_file)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);

		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}

		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}

		close(fd);

		execvp(cmd->tokens[0], cmd->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	} else
	{
		int status;

		waitpid(pid, &status, 0);
		set_status(status);
	}
}

/**
 * execute_command_with_pipe - execute command with pipe
 * @cmd1: cmd1
 * @cmd2: cmd2
 */

void execute_command_with_pipe(Command *cmd1, Command *cmd2)
{
	int pipefd[2];
	pid_t pid1, pid2;
	int status1, status2;

	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit(EXIT_FAILURE);
	else if (pid1 == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipefd[1]);

		execvp(cmd1->tokens[0], cmd1->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	pid2 = fork();
	if (pid2 == -1)
		exit(EXIT_FAILURE);
	else if (pid2 == 0)
	{
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipefd[0]);

		execvp(cmd2->tokens[0], cmd2->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	}

	close(pipefd[0]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	set_status(status2);
}
