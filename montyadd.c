#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void add(stack_t **stack, unsigned int line_num)
{
        stack_t *h = *stack, *n;

        if ((*stack) == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
                exit(EXIT_FAILURE);
        }

        if (*stack && (*stack)->next)
        {
                n = h->next;
                n->n += h->n;
                free(h);
                *stack = n;
        }
}
