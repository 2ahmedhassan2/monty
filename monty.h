#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
* struct bus_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
*
* Description: carries values through the program
*/
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void m_pu(stack_t **head, unsigned int number);
void m_pa(stack_t **head, unsigned int number);
void m_pi(stack_t **head, unsigned int number);
int exe(char *content, stack_t **head, unsigned int counter, FILE *file);
void fr_st(stack_t *head);
void m_po(stack_t **head, unsigned int counter);
void m_sw(stack_t **head, unsigned int counter);
void m_ad(stack_t **head, unsigned int counter);
void m_no(stack_t **head, unsigned int counter);
void m_su(stack_t **head, unsigned int counter);
void m_di(stack_t **head, unsigned int counter);
void m_mu(stack_t **head, unsigned int counter);
void m_mo(stack_t **head, unsigned int counter);
void m_pc(stack_t **head, unsigned int counter);
void m_ps(stack_t **head, unsigned int counter);
void m_rot(stack_t **head, unsigned int counter);
void m_ro(stack_t **head, __attribute__((unused)) unsigned int counter);
void adno(stack_t **head, int n);
void adqu(stack_t **head, int n);
void m_qu(stack_t **head, unsigned int counter);
void m_st(stack_t **head, unsigned int counter);


#endif
