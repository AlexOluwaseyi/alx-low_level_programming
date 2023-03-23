#include "3-calc.h"


/**
 * op_add - adds two integers
 * @a: first integer
 * @b: second integer
 * Return: Sum of the integers
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtracts two integers
 * @a: first integer
 * @b: second integer
 * Return: Difference of the integers
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two integers
 * @a: first integer
 * @b: second integer
 * Return: product of the integers
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two integers
 * @a: first integer
 * @b: second integer
 * Return: division of the integers
 */

int op_div(int a, int b)
{
	return ( a / b);
}

/** op_mod - finds the modulus after division
 * @a: first integer
 * @b: second integer
 * Return: Modulus after division
 */

int op_mod(int a, int b)
{
	return (a % b);
}
