#include "monty.h"

/**
 * opcode - function in charge of running builtins
 * @stack: stack given by main
 * @str: string to compare
 * @line_cnt: amount of lines
 *
 * Return: nothing
 */
void opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;

	instruction_t op[] = {};

	if (!strcmp(str, "stack"))
	{
		temp.data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data = 0;
		return;
	}

	while (op[i].opcode)
	{
		if (strcmp(op[i].opcode, str) == 0)
		{
			op[i].f(stack, line_cnt);
			return; /* if we found a match, run the function */
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	exit(EXIT_FAILURE);
}
