
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

#define EMPTY NULL

/* Creating a linked List note model */
typedef struct node
{
    int data; 
    struct node *next_node;
} Node;


/* function : initializing a list */
void Initialize_Node(Node* node){ node = EMPTY; }

/* function : check if is empty */
int is_empty(const Node *linked_list){ return linked_list==EMPTY;}

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

Node* search(int value, Node* pointer)
{
   printf("Searching node...\n");
   while (!is_empty(pointer))
   {
      /* Worse case scenrio is that, the data is not in the first node */
      if(pointer->data == value)
      {
          printf("%d was to a next node !\n", value); 
          return pointer; // return if found
      }
      pointer = pointer->next_node; // elect new head
   }

   return NULL;
   
} // 

Node* find_previous_pointer(int data, Node* ptr)
{
   printf("Searching node...\n");
   while (!is_empty(ptr))
   {
      /* Worse case scenrio is that, the data is not in the first node */
      if(ptr->data == data)
      {
          printf("%d was to a next node !\n", data); 
          return ptr; // return if found
      }
      ptr = ptr->next_node; // elect new head
   }

   return NULL;
}

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


void menu()
{
    printf("/* =============== LinkedList Options ===============\n \
              1) Display List\n  \
              2) Add a node to front\n \
              3) Deletion in between the list\n       \
              4) Quick\n        \
          * ============================= END ====================*/");
}



/*  Printing the values in the linked list */
void PrintList(Node* node, char* title)
{
    printf("%s\n", title);

    if(is_empty(node))
    {
        printf("The list is empty\n");
        return;
    }

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
    system("cls");
    printf("\n");
    int arr[10]  = {20,30,40,50,60,70,80,90,100,110}; // input stream ...
    Node* first_node = ArrayToList(arr, 10);

    PrintList(first_node, "before del"); // before


    Node* node_ptr = search(50, first_node);

    printf("previous value would be %d\n", node_ptr->next_node->data);
    //printf("next value would be %d\n", )
    
    /*
       temp = node;

       
    
    */
    
   
    
    
    
   
    printf("\n\n");
    
    return 0;
}