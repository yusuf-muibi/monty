#include "monty.h"
#define _POSIX_C_SOURCE 200809L

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
char *content = NULL;
FILE *file;
size_t size = 100;
stack_t *stack = NULL;
unsigned int counter = 0;
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
content = (char *)malloc(size);
while (fgets(content, size, file) != NULL)
{
size_t len;
bus.content = content;
counter++;
len = strlen(content);
if (len > 0 && content[len - 1] == '\n')
{
content[len - 1] = '\0';
}
execute(content, &stack, counter, file);
}

free(content);
free_stack(stack);
fclose(file);
return (0);
}
