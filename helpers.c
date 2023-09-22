#include "monty.h"
/**
 * exec_instruction - Execute Monty ByteCode instruction.
 * @stack: Pointer to the stack.
 * @line: The instruction line.
 * @line_number: The line number in the Monty file.
 *
 * Description: This function parses and executes Monty ByteCode instructions
 * using an array of instruction_t structures.
 */

void exec_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode = strtok(line, " \t\n$");
	int i;

	if (!opcode)
		return;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (!strcmp(opcode, instructions[i].opcode))
		{
			if (!strcmp(opcode, "push"))
			{
				char *arg = strtok(NULL, " \t\n$");

				if (!is_integer(arg))
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}

				instructions[i].f(stack, atoi(arg));
			}
			else
				instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
