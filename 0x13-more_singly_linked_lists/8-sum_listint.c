#include "lists.h"

/**
 * sum_listint - sums all the data of a linked list
 * @head: pointer to linked list
 * Return: result of summation
 */

int sum_listint(listint_t *head)
{
	int i;
	int add = 0;
	listint_t *current = head;

	for (i = 0; current != NULL; i++)
	{
		add += current->n;
		current = current->next;
	}
	return (add);
}
