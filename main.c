#include "monty.h"
stack_t *head = NULL;


/**
 * main - the Entry Point
 *
 * @argc: Argus Count
 *
 * @argv: a List Of Argus
 *
 * Return: 0 always.
 */


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}


/**
 * create_node - node will be Created
 *
 * @n: No. To Go Inside Node
 *
 * Return: in case of Sucess the Pointer To Node. Null Otherwise
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}


/**
 * free_nodes - nodes will be Free In stack.
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}



/**
 * add_to_queue - to adds Node To queue
 *
 * @new_node: Pointer To New Node
 *
 * @ln: Line No. Of opcode.
 */


void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
