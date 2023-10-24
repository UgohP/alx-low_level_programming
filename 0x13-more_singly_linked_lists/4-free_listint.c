#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 * @head: A pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
    listint_t *current, *next;

    current = head;

    while (current != NULL)
    {
        next = current->next;  // Store the next node before freeing the current one
        free(current);         // Free the current node
        current = next;       // Move to the next node
    }
}
