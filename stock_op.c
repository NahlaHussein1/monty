#include "monty.h"


/**
 * mul_nodes - to add Top Two Elements Of Stack
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode
 */

void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - to add Top Two Elements Of Stack
 *
 * @stack: a Pointer To Pointer that Pointing To the Top Node Of Stack
 *
 * @line_number: int Representing Line No. Of opcode
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
