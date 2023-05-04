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

int size(const Stack* stack_ptr) {return (stack_ptr->last_index+1);}

/*
  Checking if is full ...
  Checking if is empty ..
*/
int isEmpty(Stack* stack_ptr){return(stack_ptr->last_index==EMPTY);}
int isFull(Stack* stack_ptr){return(stack_ptr->last_index==FULL);}

int main()
{
   Stack  chars;
   char   *str = "Edward is tladi";
   char   name_back[10];

   initialize_stack(&chars);

   printf("The original message ... %s\n", str);

   // appeding items to a stack
   int i=0;
   while(str[i]!='\0') 
   {  
    printf("%c\n", str[i]); 
    if(size(&chars)<MAX_LEN)
    {
       push(str[i++], &chars); 
    } 
    else{
      printf("The stack if full ,,,\n");
      break;
    }
    
    }
   printf("The size of the stack is %d\n", size(&chars));

    //
   i=0;
   while(!isEmpty(&chars) && i<10) { name_back[i++] = pop(&chars); }


   printf("The reverse message ... %s\n", name_back);

   
   
   

   return 0;
}



