#include "monty.h"

/**
 * nop - do Nothing
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}

/**
 * swap_nodes - to swap Top Two Elements Of Stack
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode.
 */

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;

}

/**
 * add_nodes - to add Top Two Elements Of Stack
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode.
 */

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * sub_nodes - to add Top Two Elements Of Stack
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode.
 */

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * div_nodes - to add Top Two Elements Of Stack
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode.
 */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
