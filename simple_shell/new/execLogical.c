#include "shell.h"

/**
 * execute_logical_and - executes logical and
 * @cmd: cmd
 */

void execute_logical_and(Command *cmd)
{
	int status = get_status();

	if (status == 0)
		execute_single_command(cmd);
}

/**
 * execute_logical_or - executes logical or
 * @cmd: cmd
 */

void execute_logical_or(Command *cmd)
{
	int status = get_status();

	if (status != 0)
		execute_single_command(cmd);
}
