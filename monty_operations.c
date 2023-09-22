#include "monty.h"
/**
* command - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @buffer: line content
* Return: no return
*/
int command(char *buffer, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = OPERATIONS;
	unsigned int i = 0;
	char *opera;

	opera = strtok(buffer, " \n\t");
	if (opera && opera[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && opera)
	{
		if (strcmp(opera, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (opera && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opera);
		fclose(file);
		free(buffer);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
