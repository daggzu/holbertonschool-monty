
#include "monty.h"

/**
 * free_stack - Free the memory allocated for the stack and its nodes.
 * @stack: Pointer to the stack.
 *
 * Description: This function frees the memory allocated for the stack and
 * its nodes, ensuring there are no memory leaks.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
