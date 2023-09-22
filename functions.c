#include "monty.h"
/**
 * push - Push an integer onto the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "push" opcode appears.
 *
 * Description: This function pushes an integer value onto the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	/* Allocate memory for a new stack node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the integer value in the new node */
	new_node->n = line_number;

	/* Initialize pointers for the new node */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Update the previous pointer of the current top element */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* Update the stack pointer to point to the new top element */
	*stack = new_node;
}

/**
 * pall - Print all elements in the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "pall" opcode appears.
 *
 * Description: This function prints all elements in the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	/* Suppress unused parameter warning for line_number */
	(void)line_number;

	/* Traverse the stack and print each element */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop - Remove the top element from the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "pop" opcode appears.
 *
 * Description: This function removes the top element from the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* Check if the stack is empty */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save a pointer to the current top element */
	temp = *stack;

	/* Update the stack pointer to point to the next element */
	*stack = (*stack)->next;

	/* Update the previous pointer of the new top element to NULL */
	if (*stack != NULL)
		(*stack)->prev = NULL;

	/* Free the memory of the removed element */
	free(temp);
}

/**
 * swap - Swap the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The line number where the "swap" opcode appears.
 *
 * Description: This function swaps the top two elements of the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/* Check if there are at least two elements on the stack */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Save pointers to the top two elements */
	temp = (*stack)->next;

	/* Update the next pointers to perform the swap */
	(*stack)->next = temp->next;
	temp->next = *stack;

	/* Update the previous pointers to maintain the doubly linked list */
	temp->prev = NULL;
	(*stack)->prev = temp;

	/* Update the stack pointer to point to the new top element */
	*stack = temp;
}

#include "monty.h"
/**
 * is_integer - Check if a string is a valid integer.
 * @str: The input string to be checked.
 * Return: 1 if @str is a valid integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (!str || !*str || (*str != '-' && !isdigit(*str)))
		return (0);

	for (int i = 1; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
