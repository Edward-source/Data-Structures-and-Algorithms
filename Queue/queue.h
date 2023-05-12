#ifndef   __QUEUE_H__
#define   __QUEUE_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Empty      0x00 // empty queue
#define NOT_FOUND -10

typedef struct node
{
    int message_id;
    char* message;
    struct node *next_message;
}Message;

typedef struct 
{
    /* data */
    Message *first_message;
    Message *last_message;
    int size;
}Queue;


Queue* create_queue();
int size(Queue* queue);
bool is_empty(Queue* queue);
int peek(Queue* queue, bool* status);
void enqueue(Queue* queue, int id, char* sms);
int dequeue(Queue* queue, bool* status);
void destroy_queue(Queue* queue);
void print_queue(Queue* queue);
int search_by_id(Queue* queue, int message_id);


#endif // !__QUEUE_H__