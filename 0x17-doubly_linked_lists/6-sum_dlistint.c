#include "lists.h"

/**
 * sum_dlistint - adds up the items in a list
 * @head: pointer to the first node in the list
 *
 * Return: Sum of all nodes
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
