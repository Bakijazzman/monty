#include "monty.h"
/**
 * fe_swap - adds the top elements of the stack
 * @head: head of the stack
 * @line_counter: it counts the line_number
 * Return: nothing
 */
void fe_swap(stack_t **head, unsigned int line_counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
