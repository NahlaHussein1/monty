#include "monty.h"

/**
* free_stack - Function that frees a doubly linked list
* @head: Head pointer to the stack
* Return: Always 0 (success)
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* f_stack - Function that prints the top
* @head: Head of stack
* @counter: Line count
* Return: Always 0 (success)
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
