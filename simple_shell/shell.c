#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>


#define BUFFER_SIZE 1024
#define MAX_TOKENS 128

int status = 0;

typedef struct {
	char *tokens[MAX_TOKENS];
	int num_tokens;
} Command;

int get_status();
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
void env_command();
void exit_command(Command *cmd);
void execute_command_from_args(int argc, char* argv[]);

int get_status() {
	extern int status;
	return status;
}

void set_status(int new_status) {
	extern int status;
	status = new_status;
}

void expand_variables(char *command) {
	char *dollar_sign = strchr(command, '$');
	char status_str[8];
	char var_name[128];
	char *var_value = getenv(var_name);

	while (dollar_sign != NULL) {

		if (strncmp(dollar_sign, "$?", 2) == 0) {
			sprintf(status_str, "%d", get_status());
			memmove(dollar_sign + strlen(status_str), dollar_sign + 2, strlen(dollar_sign + 2) + 1);
			memcpy(dollar_sign, status_str, strlen(status_str));
		} else if (strncmp(dollar_sign, "$$", 2) == 0) {

			char pid_str[16];
			sprintf(pid_str, "%d", getpid());
			memmove(dollar_sign + strlen(pid_str), dollar_sign + 2, strlen(dollar_sign + 2) + 1);
			memcpy(dollar_sign, pid_str, strlen(pid_str));
		} else {

			char *var_start = dollar_sign + 1;
			char *var_end = strpbrk(var_start, " \t\n\"\'$");
			if (var_end == NULL) {
				var_end = var_start + strlen(var_start);
			}

			memcpy(var_name, var_start, var_end - var_start);
			var_name[var_end - var_start] = '\0';

			if (var_value != NULL) {
				memmove(dollar_sign + strlen(var_value), dollar_sign + (var_end - var_start), strlen(dollar_sign + (var_end - var_start)) + 1);
				memcpy(dollar_sign, var_value, strlen(var_value));
			} else {
				dollar_sign = strchr(dollar_sign + 1, '$');
				continue;
			}
		}

		dollar_sign = strchr(dollar_sign + 1, '$');
	}
}

void tokenize_command(char *command, Command *cmd) {
	char *token = strtok(command, " \t\n");
	
	cmd->num_tokens = 0;

	while (token != NULL) {
		cmd->tokens[cmd->num_tokens++] = token;
		token = strtok(NULL, " \t\n");
	}

	cmd->tokens[cmd->num_tokens] = NULL;
}

void execute_single_command(Command *cmd) {
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		execvp(cmd->tokens[0], cmd->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	} else {
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status)) {
			set_status(WEXITSTATUS(status));
		}
	}
}

void execute_command(Command *cmd) {
	if (cmd->num_tokens > 0) {
		if (strcmp(cmd->tokens[0], "exit") == 0) {
			exit_command(cmd);
		} else if (strcmp(cmd->tokens[0], "cd") == 0) {
			cd_command(cmd);
		} else if (strcmp(cmd->tokens[0], "setenv") == 0) {
			setenv_command(cmd);
		} else if (strcmp(cmd->tokens[0], "unsetenv") == 0) {
			unsetenv_command(cmd);
		} else if (strcmp(cmd->tokens[0], "env") == 0) {
			env_command();
		} else {
			execute_single_command(cmd);
		}
	}
}

void execute_logical_and(Command *cmd) {
	int status = get_status();

	if (status == 0) {
		execute_single_command(cmd);
	}
}

void execute_logical_or(Command *cmd) {
	int status = get_status();

	if (status != 0) {
		execute_single_command(cmd);
	}
}

void execute_command_with_redirect(Command *cmd, char *output_file) {
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {

		int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd == -1) {
			perror("open");
			exit(EXIT_FAILURE);
		}

		if (dup2(fd, STDOUT_FILENO) == -1) {
			perror("dup2");
			exit(EXIT_FAILURE);
		}

		close(fd);

		execvp(cmd->tokens[0], cmd->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	} else {
		int status;
		waitpid(pid, &status, 0);
		set_status(status);
	}
}

void execute_command_with_pipe(Command *cmd1, Command *cmd2) {
	int pipefd[2];
	pid_t pid1, pid2;
	int status1, status2;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid1 = fork();
	if (pid1 == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid1 == 0) {

		close(pipefd[0]);

		if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
			perror("dup2");
			exit(EXIT_FAILURE);
		}

		close(pipefd[1]);

		execvp(cmd1->tokens[0], cmd1->tokens);
		perror("execvp");
		exit(EXIT_FAILURE);
	}

	close(pipefd[1]);

	pid2 = fork();

	if (pid2 == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid2 == 0) {

		if (dup2(pipefd[0], STDIN_FILENO) == -1) {
			perror("dup2");
			exit(EXIT_FAILURE);
		}

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

void cd_command(Command *cmd) {
	char current_dir[PATH_MAX];

	if (cmd->num_tokens == 1) {
		char *home_dir = getenv("HOME");
		if (home_dir) {
			if (chdir(home_dir) == -1) {
				perror("chdir");
			}
		} else {
			printf("cd: no home directory\n");
		}
	} else if (strcmp(cmd->tokens[1], "-") == 0) {
		char *prev_dir = getenv("OLDPWD");
		if (prev_dir) {
			if (chdir(prev_dir) == -1) {
				perror("chdir");
			}
		} else {
			printf("cd: no previous directory\n");
		}
	} else {
		if (chdir(cmd->tokens[1]) == -1) {
			perror("chdir");
		}
	}

	if (getcwd(current_dir, sizeof(current_dir)) != NULL) {
		setenv("PWD", current_dir, 1);
		setenv("OLDPWD", current_dir, 1);
	} else {
		perror("getcwd");
	}
}

void unsetenv_command(Command *cmd) {
	if (cmd->num_tokens == 1) {
		printf("unsetenv: missing variable name\n");
	} else {
		int i = 1;
		while (cmd->tokens[i] != NULL) {
			if (unsetenv(cmd->tokens[i]) == -1) {
				perror("unsetenv");
			}
			i++;
		}
	}
}

void setenv_command(Command *cmd) {
	if (cmd->num_tokens == 1) {
		printf("setenv: missing variable name\n");
	} else if (cmd->num_tokens == 2) {
		if (setenv(cmd->tokens[1], "", 1) == -1) {
			perror("setenv");
		}
	} else if (cmd->num_tokens == 3) {
		if (setenv(cmd->tokens[1], cmd->tokens[2], 1) == -1) {
			perror("setenv");
		}
	} else {
		printf("setenv: too many arguments\n");
	}
}

void env_command() {
	extern char *environ;
	char *env = environ;

	while (env != NULL) {
		printf("%s\n", env);
		env++;
	}
}

void exit_command(Command *cmd) {
	if (cmd->num_tokens == 1) {
		exit(EXIT_SUCCESS);
	} else if (cmd->num_tokens == 2) {
		int status = atoi(cmd->tokens[1]);
		exit(status);
	} else {
		printf("exit: too many arguments\n");
	}
}

void execute_command_from_args(int argc, char* argv[]) {
    Command cmd;
    int i = 0;
    
    cmd.num_tokens = argc - 1;
    for (i = 0; i < cmd.num_tokens; i++) {
        cmd.tokens[i] = argv[i + 1];
    }
    execute_command(&cmd);
}

/*
int main(int argc, char *argv[]) {
	char buffer[BUFFER_SIZE];
	int buffer_pos = 0;
	int bytes_read;
	char *command = strtok(buffer, ";");
	Command cmd;

	int interactive = isatty(fileno(stdin));

	argc += 0;

	if (interactive) {
		while (1) {
			printf("$ ");

			bytes_read = read(fileno(stdin), buffer + buffer_pos, BUFFER_SIZE - buffer_pos);
			if (bytes_read == -1) {
				perror("read");
				exit(EXIT_FAILURE);
			}

			if (bytes_read == 0) {

				break;
			}

			buffer_pos += bytes_read;

			buffer[buffer_pos] = '\0';

			while (command != NULL) {
				expand_variables(command);

				tokenize_command(command, &cmd);

				execute_command(&cmd);

				command = strtok(NULL, ";");
			}

			memset(buffer, 0, sizeof(buffer));
			buffer_pos = 0;
		}
	} else {

		FILE *file = fopen(argv[1], "r");
		if (file == NULL) {
			perror("fopen");
			exit(EXIT_FAILURE);
		}

		while (fgets(buffer, sizeof(buffer), file)) {
			expand_variables(buffer);

			tokenize_command(buffer, &cmd);

			execute_command(&cmd);

			memset(buffer, 0, sizeof(buffer));
		}

		fclose(file);
	}

	return 0;
}
*/

int main(int argc, char* argv[]) {
    char buffer[BUFFER_SIZE];
    int interactive = isatty(STDIN_FILENO);
    Command cmd;
    
    if (argc > 1) {

        execute_command_from_args(argc, argv);
    } else {
        while (1) {

            if (interactive) {
                printf("shell> ");
                fflush(stdout);
            }

            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {

                printf("\n");
                break;
            }

            buffer[strcspn(buffer, "\n")] = '\0';

            expand_variables(buffer);

            tokenize_command(buffer, &cmd);

            execute_command(&cmd);
        }
    }

    return 0;
}
