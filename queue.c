#include "monty.h"
/**
 * fe_queue - prints the top element
 * @head: head of the stack
 * @line_counter: counts the line_number
 * Return: Nothing
 */
void fe_queue(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter
		bus.lifi = 1;
}
/**
 * addsqueue - adds node to the tail stack
 * @new: new_value
 * @head: stack head or head of stack
 * Return: Nothing
 */
void addsqueue(stack_t **head, int new)
{
	stack_t *new_nodes, *temp;

	temp == *head;
	new_nodes->new = new;
	new_nodes->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_nodes;
		new_nodes->prev = NULL;
	}
	else
	{
		temp->next = new_nodes;
		new_nodes->prev = temp;
	}
}
