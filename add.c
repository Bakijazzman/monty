#include "monty.h"
/**
 * fe_add - adds the two top elements of the stack
 * @head: head of the stack
 * @line_counter: counts the line_number
 * Return: Nothing
 */
void function_add(stack_t **head, unsigned int line_counter)
{
	stack_t *h;
	int length = 0, temp;

	h = *head;
	while (h != NULL)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n + h->next->n;
	h->next->n = temp;
	*head = h->next;
	free(h);
}
