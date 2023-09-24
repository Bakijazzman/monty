#include "monty.h"
/**
* function_sub- sustration
* @head: stack head
* @line_counter: line_number
* Return: no return
*/
void function_sub(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;
	int result, count = 0;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
