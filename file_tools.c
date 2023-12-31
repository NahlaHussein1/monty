#include "monty.h"


/**
 * open_file - to Opens File
 *
 * @file_name: File Namepath
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - Reads File
 *
 * @fd: Pointer To File Descriptor
 *
 * Return: void
 */

void read_file(FILE *fd)
{
	size_t len = 0;
	char *buffer = NULL;
	int line_number, format = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}



/**
 * parse_line - to Separates Each Line to Tokens To Determine
 *
 * Which Function To Call
 *
 * @buffer: Line From File
 *
 * @line_number: Line No.
 *
 * @format:  Storage Format. if 0 nodes Will Be Entered As Stack
 *
 * in case of  1 Nodes Will Be Entered As queue
 *
 * Return: if opcode is Stack return 0. if queue 1.
 */


int parse_line(char *buffer, int line_number, int format)
{
	const char *delim = "\n ";
	char *opcode, *value;

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}


/**
 * find_func - to Find Appropriate Function For opcode
 *
 * @opcode: opcode
 *
 * @value: Argu Of opcode
 *
 * @format:  Storage Format. nodes Will Be Entered as Stack if 0.
 *
 * @ln: Line No.
 *
 * Nodes Will Be Entered as a queue if 1.
 *
 * Return: void
 */

void find_func(char *opcode, char *value, int ln, int format)
{
	int flag;
	int i;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - to call Required Function
 *
 * @func: Pointer To Function That to Be Called
 *
 * @op: the String Representing opcode
 *
 * @val: String Representing Numeric Value
 *
 * @ln: Line No. For Instruction
 *
 * @format: Format specifier. nodes Will Be Entered as a stack if 1.
 *
 * Nodes Will Be Entered as a queue if 1.
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	int i;
	int flag;
	stack_t *node;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
