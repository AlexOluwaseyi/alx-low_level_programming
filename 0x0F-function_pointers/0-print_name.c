#include "function_pointers.h"

/**
 * print_name - prints a name using a given function pointer
 * @name: pointer to the name string to be printed
 * @f: function pointer that takes a char pointer argument and returns void
 */

void print_name(char *name, void(*f)(char *))
{
	f(name);
}
