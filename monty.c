#include <stdio.h>
#include "monty.h"

/**
 * main - stack and queue data structure interpreter
 * @av: argument
 * @ac: argument counter
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	char *file_path;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_path = av[1];
	file = fopen(file_path, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	processMonty(file);
	fclose(file);
	return (0);
}

/**
 * processMonty - Interprets Monty bytecodes from a file
 * @file: A pointer to the input file to process
 */
void processMonty(FILE *file)
{
	stack_t *stack = NULL;
	char *opcodes, *line = NULL;
	int line_number, found;
	size_t j, num_opcodes = 0, len = 0;
	instruction_t instruction[] = {
		{"push", pushFunc},
		{"pall", pallFunc}
	};
	num_opcodes = sizeof(instruction) / sizeof(instruction[0]);
	line = malloc(1024);
	len = sizeof(line);
	line_number = 1;
	found = 0;

	while ((fgets(line, len, file)) != NULL)
	{
		opcodes = strtok(line, " \t\n");
		if (opcodes == NULL || strlen(opcodes) == 0)
			continue;

		for (j  = 0; j < num_opcodes; j++)
		{
			if (strcmp(opcodes, instruction[j].opcode) == 0)
			{
				instruction[j].f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcodes);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	freeStack(&stack);
}
