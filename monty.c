#include "monty.h"
temp_t bus;
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *buffer;
	FILE *file;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		buffer = NULL;
		read = getline(&buffer, &size, file);
		bus.content = buffer;
		line_counter++;
		if (read > 0)
		{
			command(buffer, &stack, line_counter, file);
		}
		free(buffer);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
