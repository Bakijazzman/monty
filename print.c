#include "monty.h"
/**
 * function_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void function_pchar(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;

	temp = *head;
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
