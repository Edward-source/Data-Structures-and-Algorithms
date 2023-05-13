/* The ADT STACK by Edward Tladi March 03, 2023 */

#include "stack.h"

/* Method to initialize  the the stack */
void initialize_stack(Stack* stack_ptr) {stack_ptr->last_index = EMPTY;} // Very Important

/* Push the value to the list */
void push(char c, Stack* stack_ptr){ stack_ptr->last_index++; stack_ptr->s[stack_ptr->last_index] = c;}

/* remove the last value from the list */
char pop(Stack* stack_prt){ return (stack_prt->s[stack_prt->last_index--]);}

/* return the last value of the stack */
char top(const Stack* stack_ptr){return(stack_ptr->s[stack_ptr->last_index]);}

/* return the size of stack */
int size(const Stack* stack_ptr) {return (stack_ptr->last_index+1);}

/*  Checking if is full */
int isEmpty(Stack* stack_ptr){return(stack_ptr->last_index==EMPTY);}

/* Checking if is empty ..*/
int isFull(Stack* stack_ptr){return(stack_ptr->last_index==FULL);}





