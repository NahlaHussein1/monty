#include "monty.h"


/**
 * print_char - to Prints Ascii Value
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode.
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}


/**
 * print_str - to Prints Str
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @ln: int Representing Line No. Of opcode.
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}


/**
 * rotl - it will rotates 1st Node Of Stack To Bottom
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @ln: int Representing Line No. Of opcode.
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - it will rotates 1st Node Of Stack To Bottom
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @ln: int Representing Line No. Of opcode.
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
