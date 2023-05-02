#include <stdio.h>
#include <stdlib.h>

#define EMPTY NULL

typedef struct node{ int data; struct node *prev_node; struct node *next_node; } Node;

/* function : check if is empty */
int is_empty(const Node *linked_list){ return linked_list==EMPTY;}

Node* Create_Node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node)); // allocating the space on the heap ...
    new_node->data = data; // data passing
    new_node->prev_node = NULL;
    new_node->next_node = NULL;

    return new_node;
    
}

int main()
{
   Node* head = NULL;

   head = Create_Node(46);

   printf("The value in the list is %d\n", head->data);
    return 0;
}