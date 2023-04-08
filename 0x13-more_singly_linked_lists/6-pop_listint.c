#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list.
 * @head: pointer to pointer to head node of list.
 *
 * Return: the data (n) of the deleted head node, or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *tmp;

	if (*head == NULL)
		return (0);

	tmp = *head;
	data = tmp->n;
	*head = tmp->next;
	free(tmp);
	return (data);
}
