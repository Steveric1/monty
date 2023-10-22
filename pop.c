#include "monty.h"

/**
 * popFunc - Removes the top element from the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The current line number being processed.
 */
void popFunc(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}

