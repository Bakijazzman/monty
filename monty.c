#include "monty.h"
temp_t bus = {NULL, 0, NULL, NULL};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
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
	while (read_line > 0)
	{
		//content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		line_counter++;
		if (read_line > 0)
		{
			execute(content, &stack, line_counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
