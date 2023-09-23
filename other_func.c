#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
/**
 * function_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void function_pint(stack_t **head, unsigned int counter)
{
	if (!*head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * function_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void function_pop(stack_t **head, unsigned int counter)
{
	stack_t *temp;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
/**
 * function_stack - prints the top
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void function_stack(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter;
	bus.lifi = 0;
}
