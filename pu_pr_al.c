#include "mo.h"
#include <ctype.h>

void pu(stack_t **stack, int data_to_push)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data_to_push;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

/* print_all function */
void pr_al(stack_t **stack, unsigned int line_number);
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
