
/* =============================================================================
 |   Project   :  DATA STRUCTURES AND ALGORITHS IN C
 |
 |   Author    :  EDWARD TLADI
 |   Language  :  ANSI C LANG
 |   To Compile:  gcc main.c 
 |
 |   Date      :  05 /04/2023
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  Learning Link list in C 
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Required Features Not Included: 
 |
 |   Known Bugs:  
 |
 *=========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Creating a linked List note model */
typedef struct node
{
    int data; 
    struct node *next_node;
} Node;

typedef union
{
    /* data */
    int x;
}Student;


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

 /*--------------------- append_node(Node*) -------------------------
|  Function FUNCTION_NAME
|
|  Purpose:  
|  
|  Parameters:
|  
|  Returns:  
*-------------------------------------------------------------------*/
void append_node(Node* head_of_list, Node* new_node )
{
    if(!is_empty(new_node)  && !is_empty(head_of_list))
    {
        new_node->next_node = head_of_list;
    }
    else
    {
        printf("The node has not been created \n You can create a new Node by Create_Node Function\n");
    }
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
   printf("Searching node...\n");
   while (!is_empty(head))
   {
      /* Worse case scenrio is that, the data is not in the first node */
      if(head->data == value)
      {
          printf("%d was found !\n", value); 
          return 1; // return if found
      }
      head = head->next_node; // elect new head
   }

   return -1;
   
} // 

/* A function to insert a node between nodes in the list */
void insert_node(Node* first_node, int data, int position)
{
     printf("Inserting a node at position %d \n", position); 

     Node* new_node = create_node(data); // creating a node

     int loop  = 0; // init loop
     if(!is_empty(first_node))
     {
        printf("The list is not EMPTY\n");
        printf("the content %d\n", first_node->data);
     }

     while (!is_empty(first_node)) // start while loop
     {
        
        loop ++; // increment the loop
        if(loop == position && !(position<=1) )
        {
            // point where the prev node was pointing to, 
            new_node->next_node = first_node->next_node; 
           // then, redirect the prev node to point to a new node
            first_node->next_node = new_node;
            break; // break the loop
        }
        
        // update the node
        first_node = first_node->next_node;
     } // end of while loop
     
} 

// del
void delete_node(Node* first_node, int data)
{
    
    if(search(data, first_node)==1)
    {
        printf("check if is right node : %d\n", first_node->data);
        while (!is_empty(first_node))
        {
            /* code */


        }
    }
    else
    {
        printf("Node %d is not in the list :\n", data);
    }
    
}

/*  Printing the values in the linked list */
void PrintList(Node* node, char* title)
{
    printf("%s\n", title);
    while (!is_empty(node))
    {
        /* code */
        printf("%d  ", node->data);
        node = node->next_node;
    }

    printf("\n");
    
}

/* A function to convert array to list */
Node* ArrayToList(int arr[], int size) 
{
    Node *first_node = create_node(arr[size-1]); // creating first node
    for (int i = (size-2); i>=0; i--) 
    {
        Node* new_node = append_to_front(arr[i], first_node); // append a new node in front
        first_node = new_node; // update a first node
    }
   
    return first_node; // return new node
}

void ListToArray(Node* first_node, int array[])
{
    int size = 0;
    
    while (!is_empty(first_node))
    {
        /* code */
        array[size] = first_node->data;
        size++;
        first_node = first_node->next_node;
    }
}

void PrintArray(int arr[], int size)
{
    for(int i =0 ; i<size ; i++)
    {
        printf("%d  ", arr[i]);
    }
     printf("\n");
}


int main()
{
    Node*  first_node;
    
    Initialize_Node(first_node);
    int arr[5]  = {20,30,40,50,60};
    int array[5] = {0}; // init array

    first_node = ArrayToList(arr,5);
    
    
    PrintList(first_node, "Single Element list");
    ListToArray(first_node, array);
    PrintArray(array,5);
    
       
    printf("\n\n");
    return 0;
}