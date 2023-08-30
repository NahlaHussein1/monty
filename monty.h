#ifndef MONTY_H
#define MONTY_H


#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct stack_s - a Doubly_Linked_List that Represents Stack (Or queue)
 *
 * @n: Int
 *
 * @prev: to Points To Previous Element Of Stack (Or queue)
 *
 * @next: to Points To Next Element Of Stack (Or queue)
 * Description: a Doubly_Linked_List Node Structure.
 *
 * For Stack, queues, LIFO, FIFO
 */


typedef struct stack_s
{
        int n;
        struct stack_s *next;
	struct stack_s *prev;
} stack_t;


/**
 * struct instruction_s - opcode & the Function
 *
 * @opcode: opcode
 *
 * @f: the Function To Handle opcode.
 * Description: opcode & Its Function.
 *
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/* the File of Operations*/

void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*the Stack Operations*/

stack_t *create_node(int n);
void add_to_queue(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void free_nodes(void);


void print_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

/*math Operations With Nodes*/

void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*the Strings Operations*/

void print_str(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*handling Error */

void more_err(int error_code, ...);
void string_err(int error_code, ...);
void err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
