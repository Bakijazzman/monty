#ifndef MONTY_H_
#define MONTY_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>

#define OPERATIONS            \
	{                           \
		{"push", function_push},       \
		    {"pall", function_pall},   \
		    {"pint", function_pint},   \
		    {"pop", function_pop},     \
		    {"swap", function_swap},   \
		    {"nop", function_nop},     \
		    {"add", function_add},    \
		    {"queue", function_queue}, \
		    {"stack", function_stack},  \
		{                     \
			NULL, NULL      \
		}                     \
	}
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct help - argument for the current opcode
* @data_struct: stack mode, stack (default) and queue
* @argument: the arguments of the string
*
* Description: global structure used to pass data around the functions easily
*/
typedef struct temp_t
{
	FILE *file;
	int lifi;
	char *content;
	char *arg;
} temp_t;
extern temp_t bus;



char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void function_push(stack_t **head, unsigned int number);
void function_pall(stack_t **head, unsigned int number);
void function_pint(stack_t **head, unsigned int number);
int command(char *buffer, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void function_pop(stack_t **head, unsigned int line_counter);
void function_swap(stack_t **head, unsigned int line_counter);
void function_add(stack_t **head, unsigned int line_counter);
void function_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void function_queue(stack_t **head, unsigned int line_counter);
void function_stack(stack_t **head, unsigned int line_counter);
#endif
