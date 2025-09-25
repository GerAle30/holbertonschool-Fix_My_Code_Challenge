#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Find the node at index */
	for (i = 0; i < index && current != NULL; i++)
		current = current->next;

	if (current == NULL)
		return (-1);

	/* FIXED: Properly delete the node by updating pointers */

	/* If it's the head node */
	if (current == *head)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		/* Update the previous node's next pointer */
		if (current->prev != NULL)
			current->prev->next = current->next;
	}

	/* Update the next node's prev pointer */
	if (current->next != NULL)
		current->next->prev = current->prev;

	/* Free the node */
	free(current);

	return (1);
}
