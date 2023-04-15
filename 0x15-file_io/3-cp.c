#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define BUFSIZE 1024

/**
 * main - entry point function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0, Success
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, len;
	char buffer[BUFSIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char a[] = argv[1];
	char b[] = argv[2];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", a);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", b);
		exit(99);
	}
	while ((len = read(fd_from, buffer, BUFSIZE)))
	{
		if (len == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", a);
			exit(98);
		}
		if (write(fd_to, buffer, len) != len)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
	return (0);
}
