#include "monty.h"

/**
* m_ro - function that rotates the stack to the bottom
* @head: stack head of the stack
* @counter: line count
*
* Return: nothing
*/
void m_ro(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
