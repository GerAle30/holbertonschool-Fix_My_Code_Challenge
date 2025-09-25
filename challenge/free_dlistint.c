#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: head of the list
 *
 * Return: no return
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	if (head != NULL)
	{
		while (head->next != NULL)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
		free(head);
	}
}
