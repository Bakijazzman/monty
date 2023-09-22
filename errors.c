#include "monty.h"
/**
 * _error - prints file error message and exits
 * @argv: argv given by main()
 * Return: nothing
 */
void _error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}
