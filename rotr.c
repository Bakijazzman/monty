#include "monty.h"
/**
 * function_rotr - rotates the stack to the bottom
 * @head: head of the stack
 * @line_counter: counts the line_number
 * Return: Nothing
 */
void function_rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
	stack_t *duplicate;

	duplicate = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *head;
	duplicate->prev->next = NULL;
	duplicate->prev = NULL;
	(*head)->prev = duplicate;
	(*head) = duplicate;
}
