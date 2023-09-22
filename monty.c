#include "monty.h"
/**
 * main - entry point
 * @argc: argument count
 * @argcv: arguement vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;	
	size_t len = 0, count = 1;
	char *command, *str;
	stack_t *stack;
	temp global;
	int line;

	global.data = 1;
	if (argc != 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
		_error(argv[1]);
	line = (getline(&command, &len, file));
	while (line != -1)
	{
		if (stat)
			break;
		if (*command == '\n')
		{
			count++;
			continue;
		}
		str = strtok(command, " \t\n");
		if (str == NULL || *str == '#')
		{
			count++;
			continue;
		}
		global.arg = strtok(NULL, " \t\n");
		opcode(&stack, str, count);
		count++;
	}
	free(command);
	free_stack(stack);
	fclose(file);
	return (0);
}
