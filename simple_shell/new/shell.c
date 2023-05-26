#include "shell.h"

/**
 * main - the main program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	int interactive = isatty(STDIN_FILENO);
	Command cmd;

	if (argc > 1)
	{
		execute_command_from_args(argc, argv);
	} else
	{
		while (1)
		{
			if (interactive)
			{
				printf("shell> ");
				fflush(stdout);
			}
			if (fgets(buffer, sizeof(buffer), stdin) == NULL)
			{
				printf("\n");
				break;
			}
			buffer[strcspn(buffer, "\n")] = '\0';
			expand_variables(buffer);
			tokenize_command(buffer, &cmd);
			execute_command(&cmd);
		}
	}
	return (0);
}
