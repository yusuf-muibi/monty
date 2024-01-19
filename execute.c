#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", o_push}, {"pall", o_pall}, {"pint", o_pint},
				{"pop", o_pop},
				{"swap", o_swap},
				{"add", o_add},
				{"nop", o_nop},
				{"sub", o_sub},
				{"div", o_div},
				{"mul", o_mul},
				{"mod", o_mod},
				{"pchar", o_pchar},
				{"pstr", o_pstr},
				{"rotl", o_rotl},
				{"rotr", o_rotr},
				{"queue", o_queue},
				{"stack", o_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
