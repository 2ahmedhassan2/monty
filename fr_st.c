#include "monty.h"

/**
* fr_st - function that frees a doubly linked list
* @head: head pointer to the stack
*
* Return: nothing
*/
void fr_st(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* m_st - function that prints the top
* @head: head of stack
* @counter: line count
*
* Return: nothing
*/
void m_st(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
