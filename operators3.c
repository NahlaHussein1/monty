nclude "monty.h"

/**
* f_pop - function that prints the top of the stack
* @head: double head pointer to the stack
* @counter: line count
* Return: Always 0 (success)
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* f_pint - Function that prints the top of the stack
* @head: Double head pointer to the stack
* @counter: Line count
* Return: Always 0 (success)
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* f_nop - Function that does nothing
* @head: Double head pointer to the stack
* @counter: Line count
* Return: Always 0 (success)
*/
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
