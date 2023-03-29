/* The ADT STACK by Edward Tladi March 03, 2023 */

#include<stdio.h>
#include<math.h>
#define MAX_LEN 10
#define EMPTY -1
#define FULL (MAX_LEN-1)

// Stack LIFO : Push(), Pop(), Top(), Empty(), full(), Reset()

/* Stack datatype definition */
typedef struct stack {/* data */ char s[MAX_LEN]; int last_index;} Stack;

/* Method to initialize  the the stack */
void initialize_stack(Stack* stack_ptr) {stack_ptr->last_index = EMPTY;} // Very Important

/* Push the value to the list */
void push(char c, Stack* stack_ptr){ stack_ptr->last_index++; stack_ptr->s[stack_ptr->last_index] = c;}

/* remove the last value from the list */
char pop(Stack* stack_prt){ return (stack_prt->s[stack_prt->last_index--]);}

/* return the last value of the stack */
char top(const Stack* stack_ptr){return(stack_ptr->s[stack_ptr->last_index]);}

/*
  Checking if is full ...
  Checking if is empty ..
*/
int isEmpty(Stack* stack_ptr){return(stack_ptr->last_index==EMPTY);}
int isFull(Stack* stack_ptr){return(stack_ptr->last_index==FULL);}

int main()
{
   Stack  books;
   char   *str = "Edward is";
   int    i=0;
   char   name_back[10];
   initialize_stack(&books);
   printf("The original message ... %s\n", str);

   while(str[i]!='\0')
   {
     printf("%c\n", str[i]);
     push(str[i++], &books);
   }

   i=0;
   while(!isEmpty(&books) && i<10)
   {
      name_back[i++] = pop(&books);
   }
   printf("The reverse message ... %s\n", name_back);
   
   printf("Do I get here?");

   return 0;
}



