#include <stdio.h>
#include <string.h>
#include "mo.h"

int main(int argc, char *argv[])
{
    /* Check for correct usage */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    /* Open the Monty bytecode file */
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* Initialize stack */
    stack_t *stack = NULL;

    /* Read and interpret each line of the file */
    char opcode[100];
    int value;
    unsigned int line_number = 0;
    while (fscanf(file, "%99s", opcode) == 1)
    {
        line_number++;
        if (strcmp(opcode, "push") == 0)
        {
            if (fscanf(file, "%d", &value) != 1)
            {
                fprintf(stderr, "L%u: Usage: push integer\n", line_number);
                fclose(file);
                return EXIT_FAILURE;
            }
            push(&stack, value);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(&stack, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            print_all(&stack, line_number);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            print_top(&stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap_top_two(&stack, line_number);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add_top_two(&stack, line_number);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            do_nothing(&stack, line_number);
        }
        else if (strcmp(opcode, "sub") == 0)
        {
            subtract_top_two(&stack, line_number);
        }
        else if (strcmp(opcode, "div") == 0)
        {
            divide_top_two(&stack, line_number);
        }
        else if (strcmp(opcode, "mul") == 0)
        {
            multiply_top_two(&stack, line_number);
        }
        else if (strcmp(opcode, "mod") == 0)
        {
            mod_top_two(&stack, line_number);
        }
        else if (strcmp(opcode, "pchar") == 0)
        {
            print_char_at_top(&stack, line_number);
        }
        else if (strcmp(opcode, "pstr") == 0)
        {
            print_string(&stack, line_number);
        }
        else if (strcmp(opcode, "rotl") == 0)
        {
            rotate_left(&stack, line_number);
        }
        else if (strcmp(opcode, "rotr") == 0)
        {
            rotate_right(&stack, line_number);
        }
        else if (strcmp(opcode, "stack") == 0)
        {
            set_stack_format(&stack, line_number);
        }
        else if (strcmp(opcode, "queue") == 0)
        {
            set_queue_format(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: Unknown instruction %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    /* Cleanup and close file */
    fclose(file);

    return EXIT_SUCCESS;
}
