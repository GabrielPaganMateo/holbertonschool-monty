#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
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
void (*f)(stack_t **stack, unsigned int line_number, char *line, FILE *file);
} instruction_t;
void (*call_func(char **tokens))(stack_t **, unsigned int, char *, FILE *file);
void push(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void pall(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void pint(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void pop(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void swap(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void add(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void nop(stack_t **stack, unsigned int line_number, char *line, FILE *file);
void invalid(stack_t **stack, unsigned int, char *line, FILE *file);
char **tokenization(char *ptr, char *delim);
extern char **tokens;
void free_grid(char **grid);
void free_stack(stack_t *head);
int check_line(char *line);
int check_arg(char *argument);
#endif
