#include "monty.h"
/**
 * function_push - add node to the stack
 * @head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void function_push(stack_t **head, unsigned int line_counter)
{
	unsigned int n, i = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{ 
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		 }
	}
	else
	{ 
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
/**
 * function_pall - prints the stack
 * @head: stack head
 * @line_counter: no used
 * Return: no return
*/
void function_pall(stack_t **head, unsigned int line_counter)
{
	stack_t *temp;
	(void)line_counter;

	temp = *head;
	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(stack_t));
	if (!new)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void function_queue(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new, *temp;

	temp = *head;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		temp->next = new;
		new->prev = temp;
	}
}
/**
 * f_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void function_stack(stack_t **head, unsigned int line_counter)
{
	(void)head;
	(void)line_counter;
	bus.lifi = 0;
}
