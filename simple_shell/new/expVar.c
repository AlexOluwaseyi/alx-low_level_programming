#include "shell.h"

/**
 * expand_variables - expands variable
 * @command: command
 */

void expand_variables(char *command)
{
	char *dollar_sign = strchr(command, '$');
	char status_str[8];
	char var_name[128], pid_str[16];
	char *var_value = getenv(var_name);

	while (dollar_sign != NULL)
	{
		if (strncmp(dollar_sign, "$?", 2) == 0)
		{
			sprintf(status_str, "%d", get_status());
			memmove(dollar_sign + strlen(status_str), dollar_sign + 2, strlen(dollar_sign + 2) + 1);
			memcpy(dollar_sign, status_str, strlen(status_str));
		} else if (strncmp(dollar_sign, "$$", 2) == 0)
		{
			sprintf(pid_str, "%d", getpid());
			memmove(dollar_sign + strlen(pid_str), dollar_sign + 2, strlen(dollar_sign + 2) + 1);
			memcpy(dollar_sign, pid_str, strlen(pid_str));
		}
		else
		{
			char *var_start = dollar_sign + 1;
			char *var_end = strpbrk(var_start, " \t\n\"\'$");

			if (var_end == NULL)
				var_end = var_start + strlen(var_start);
			memcpy(var_name, var_start, var_end - var_start);
			var_name[var_end - var_start] = '\0';
			if (var_value != NULL)
			{
				memmove(dollar_sign + strlen(var_value), dollar_sign + (var_end - var_start), strlen(dollar_sign + (var_end - var_start)) + 1);
				memcpy(dollar_sign, var_value, strlen(var_value));
			} else
			{
				dollar_sign = strchr(dollar_sign + 1, '$');
				continue;
			}
		}
		dollar_sign = strchr(dollar_sign + 1, '$');
	}
}
