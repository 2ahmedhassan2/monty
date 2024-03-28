#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Data structure for a stack */
typedef struct stack_s
{
    int data;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Data structure for instructions */
typedef struct instruction_s
{
    char *opcode;
    void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void pu(stack_t **stack, int value);
void po(stack_t **stack, unsigned int line_number);
void pr_al(stack_t **stack, unsigned int line_number);
void pr_to(stack_t **stack, unsigned int line_number);
void sw_to_tw(stack_t **stack, unsigned int line_number);
void ad_to_tw(stack_t **stack, unsigned int line_number);
void do_no(stack_t **stack, unsigned int line_number);
void su_to_tw(stack_t **stack, unsigned int line_number);
void di_to_tw(stack_t **stack, unsigned int line_number);
void mu_to_tw(stack_t **stack, unsigned int line_number);
void mo_to_tw(stack_t **stack, unsigned int line_number);
void pr_ch_at_to(stack_t **stack, unsigned int line_number);
void pr_st(stack_t **stack, unsigned int line_number);
void ro_le(stack_t **stack, unsigned int line_number);
void ro_ri(stack_t **stack, unsigned int line_number);
void se_st_fo(stack_t **stack, unsigned int line_number);
void se_qu_fo(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
