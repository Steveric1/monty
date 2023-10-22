#include "monty.h"

/**
 * pintFunc - Prints the value at the top of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number being processed.
 *
 * This function prints the value at the top of the stack.
 * If the stack is empty, it prints an error message
 * and exits the program.
 */
void pintFunc(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
