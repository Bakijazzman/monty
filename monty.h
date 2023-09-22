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
		{"push", f_push},       \
		    {"pall", f_pall},   \
		    {"pint", f_pint},   \
		    {"pop", f_pop},     \
		    {"swap", f_swap},   \
		    {"nop", f_nop},     \
		    {"div", f_div},    \
		    {"mul", f_mul},    \
		    {"add", f_add},    \
		    {"sub", f_sub},    \
		    {"mod", f_mod},     \
		    {"pchar", f_pchar}, \
		    {"pstr", f_pstr},   \
		    {"rotl", f_rotl},   \
		    {"rotr", f_rotr},   \
		    {"queue", f_queue}, \
		    {"stack", f_stack},  \
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
typedef struct temp
{
	FILE *file;
	int lifi;
	int content;
	char *arg;
} temp;
extern temp bus;
void _error(char *argv);
stack_t *add_node(stack_t **stack, const int n);
stack_t *queue(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print(const stack_t *stack);
void opcode(stack_t **stack, char *str, unsigned int line_cnt);
#endif
