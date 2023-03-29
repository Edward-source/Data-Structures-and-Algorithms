#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/// @brief  @endcond
/*
* 
* 
*/
typedef struct node
{
    /* data */
    int data;
    struct node *parent_node;
    struct node *left_node;
    struct node *right_node;
}Node;

Node* create_node(int data)
{
    Node* parent = (Node*)malloc(sizeof(Node));
    parent->data = data;
    parent->left_node   = NULL;
    parent->right_node  = NULL;
    parent->parent_node = NULL;
    return parent;
}

void Init_Tree(const Node* tree){tree = NULL;}
bool is_empty(const Node* tree){return tree == NULL;}

void print_tree(Node* tree)
{
  while (!is_empty(tree))
  {
    /* code */
  }
  
}

int main()
{

    //Level 1
    Node *root;
    Init_Tree(root);
    root = create_node(1);

    //Level 2
    root->left_node = create_node(2);
    root->right_node = create_node(3);

    return 0;
}