#ifndef MO_H
#define MO_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void op_fi(char *file_name);
int pa_li(char *buffer, int line_number, int format);
void re_fi(FILE *);
int le_ch(FILE *);
void fi_fu(char *, char *, int, int);

stack_t *cr_no(int n);
void fr_no(void);
void pr_st(stack_t **, unsigned int);
void ad_to_st(stack_t **, unsigned int);
void ad_to_qu(stack_t **, unsigned int);

void ca_fu(op_func, char *, char *, int, int);

void pr_to(stack_t **, unsigned int);
void po_to(stack_t **, unsigned int);
void no(stack_t **, unsigned int);
void sw_no(stack_t **, unsigned int);

void ad_no(stack_t **, unsigned int);
void su_no(stack_t **, unsigned int);
void di_no(stack_t **, unsigned int);
void mu_no(stack_t **, unsigned int);
void mo_no(stack_t **, unsigned int);

void pr_ch(stack_t **, unsigned int);
void pr_st(stack_t **, unsigned int);
void ro(stack_t **, unsigned int);

void er(int er_co, ...);
void mo_er(int er_co, ...);
void st_er(int er_co, ...);
void rotr(stack_t **, unsigned int);

#endif
