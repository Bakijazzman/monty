#include "monty.h"
/**
 * function_rotl - rotates the stack to the top
 * @head: head of the stack
 * @line_counter: counts  the line_number
 * Return: Nothing
 */
void function_rotl(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
	stack_t *tmp = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = temp;
}
