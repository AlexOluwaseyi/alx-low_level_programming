#include "3-calc.h"

/**
 * main - the calculator program
 * @argc: number of arguments passed to program
 * @argv: the arguments
 *
 * Return: Result of arithmetic operation.
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	op = argv[2];

	if ((get_op_func)(op) == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	else if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}
	result = get_op_func(op)(num1, num2);
	printf("%d\n", result);

	return (0);
}
