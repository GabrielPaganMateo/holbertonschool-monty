#include "monty.h"
/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to head
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		free(temp);
	}
}
