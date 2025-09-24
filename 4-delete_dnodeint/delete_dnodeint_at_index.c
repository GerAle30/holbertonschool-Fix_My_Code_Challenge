#include "lists.h"

/**
 * delete_dnodeint_at_index - delete the node at index of a dlistint_t list
 * @head: head of the list
 * @index: index of the node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *h1;

    if (*head == NULL)
        return (-1);

    h1 = *head;

    if (index == 0)
    {
        *head = h1->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(h1);
        return (1);
    }

    while (index != 0)
    {
        if (h1 == NULL)
            return (-1);
        h1 = h1->next;
        index--;
    }

    if (h1 == NULL)
        return (-1);

    if (h1->next != NULL)
        h1->next->prev = h1->prev;
    if (h1->prev != NULL)
        h1->prev->next = h1->next;
    
    free(h1);
    return (1);
}