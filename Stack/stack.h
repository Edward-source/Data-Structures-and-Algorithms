/* The ADT STACK by Edward Tladi March 03, 2023 */
#ifndef  __STACK_H__
#define  __STACK_H__

#include<stdio.h>
#include<math.h>
#define MAX_LEN 10
#define EMPTY -1
#define FULL (MAX_LEN-1)


/* Stack datatype definition */
typedef struct stack {/* data */ char s[MAX_LEN]; int last_index;} Stack;

/* Method to initialize  the the stack */
void initialize_stack(Stack* stack_ptr);

/* Push the value to the list */
void push(char c, Stack* stack_ptr);

/* remove the last value from the list */
char pop(Stack* stack_prt);

/* return the last value of the stack */
char top(const Stack* stack_ptr);
int size(const Stack* stack_ptr);
int isEmpty(Stack* stack_ptr);
int isFull(Stack* stack_ptr);

#endif //!__STACK_H__


