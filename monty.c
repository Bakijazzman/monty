#include "monty.h"
/**
 * main - entry point
 * @argc: argument count
 * @argcv: arguement vector
 * Return: 0 on success
 */
int main(int argc, char *argv)
{	
	unsigned int len = 0, count = 1;
	char *command, *str;
	stack_t *stack;
	temp global;

	global.data = 1;
	if (argc != 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
		_error(argv[1]);
	return (0);
}
