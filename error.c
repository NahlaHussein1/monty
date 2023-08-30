#include "monty.h"


/**
 * err - to Prints the Appropiate Error Messages that Determined By Their Error Code
 *
 * @error_code: an Error Codes Are The following:
 *
 * (1) => User Doesn't Give Any File Or More Than One File To The Program
 *
 * (2) => the Provided File Isn't File That Can Be Opened Or Read
 *
 * (3) => the Provided File Contains Invalid Instruction
 *
 * (4) => if The Program Unable To malloc More Memory
 *
 * (5) => if The Parameter Passed To Instruction "push" Isn't Int
 *
 * (6) => Stack is Empty For Print
 *
 * (7) => Stack is Empty For pop
 *
 * (8) => Stack Is Too Short For Operation.
 */

void err(int error_code, ...)
{
	char *op;
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * more_err - to Handles Errors
 *
 * @error_code: Error Codes Are The following:
 *
 * (6) => Stack is Empty For Pint
 *
 * (7) => Stack is Empty For pop
 *
 * (8) => Stack is Too Short For Operation
 *
 * (9) => division By Zero
 */

void more_err(int error_code, ...)
{
	char *op;
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}


/**
 * string_err - to Handles Errors
 *
 * @error_code: Error Codes Are The following:
 *
 * (10) ~> No. Inside Node Is Outside ASCII bounds
 *
 * (11) ~> Stack is Empty.
 */

void string_err(int error_code, ...)
{
	int l_num;
	va_list ag;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
