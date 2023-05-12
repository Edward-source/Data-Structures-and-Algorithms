#ifndef  __LINKED_LIST__H__
#define  __LINKED_LIST__H__

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
void Initialize_Node(Node* node);

/* function : check if is empty */
int is_empty(const Node *linked_list);

Node* create_node(int data);

/* Appending a node in front of list */
Node* append_to_front(int data, Node* front_node);
 
void append_node(Node* head_of_list, Node* new_node );

/* Appeding a node at back of link list */
Node* append_to_the_back(int data, Node* last_node);

Node* search(int value, Node* pointer);

Node* find_previous_pointer(int data, Node* ptr);


/* A function to insert a node between nodes in the list */
void insert_node(Node* first_node, int data, int position);

void menu();


/*  Printing the values in the linked list */
void PrintList(Node* node, char* title);

/* A function to convert array to list */
Node* ArrayToList(int arr[], int size);

void ListToArray(Node* first_node, int array[]);

void PrintArray(int arr[], int size);

#endif // !__LINKED_LIST__H__
