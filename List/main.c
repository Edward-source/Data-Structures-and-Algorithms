/*
  The ADT List
  by Edward Tladi
  .... date
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Creating a linked List note model */
typedef struct node
{
    int data; 
    struct node *next_node;
} Node;

/* function : initializing a list */
void Initialize_Node(Node* node){ node = NULL; }

/* function : check if is empty */
int is_empty(const Node *linked_list){ return linked_list==NULL;}

Node* create_node(int data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next_node = NULL;
    return node;
}

/* Appending a node in front of list */
Node* append_to_front(int data, Node* front_node)
{
    Node* head = create_node(data);
    head->next_node = front_node; // linking
    return head;
}

/* Appeding a node at back of link list */
Node* append_to_the_back(int data, Node* last_node)
{
    Node* new_tail = create_node(data);
    last_node->next_node = new_tail;
    return new_tail;
}

int search(int value, Node* head)
{
   printf("Searching ...\n");
   while (!is_empty(head))
   {
      /* Worse case scenrio is that, the data is not in the first node */
      if(head->data == value)
      {
          printf("%d was found !\n", value);
          return 1;
          head = head->next_node; // elect new head

       }
   }
   return -1;
   
}

/*  Printing the values in the linked list */
void print_list(Node* node, char* title)
{
    printf("%s\n", title);
    while (!is_empty(node))
    {
        /* code */
        printf("%d :", node->data);
        node = node->next_node;
    }
    
}

int main()
{
    Node*  first_node;
    Initialize_Node(first_node);
    first_node = create_node(7);

    

    Node* node_2 = append_to_front(2, first_node);
    Node* node_3 = append_to_front(3, node_2);
    Node* node_4 = append_to_front(4, node_3);
    Node* node_5 = append_to_the_back(5, first_node);
    
    print_list(node_4, "Single Element list");
    int result = search(5, node_4);

    if(result == 1)
    {
       printf("It was found !\n");
    } 
    else
    {
       printf("It was not found !\n");
    }
       
    printf("\n\n");
    return 0;
}