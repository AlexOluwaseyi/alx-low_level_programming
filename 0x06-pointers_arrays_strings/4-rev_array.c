#include "main.h"

/**
 * reverse_array - reverse the content of an array
 * @a: an array of integers
 * @n: the number of elements to swap
 */

void reverse_array(int *a, int n)
{
	int i = 0;
	int j = 0;
	int k = 0;

	k = n / 2;
	for (i = 0; i < k; i++)
	{
		j = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = j;
	}
}
