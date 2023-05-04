#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Empty 0xFF // empty

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


int main()
{
    Queue* queue_messages = create_queue();
    // use queue_messages to enqueue, dequeue, or perform any other queue operation

    enqueue(queue_messages, 0x00000001, "Please call me\n");
    enqueue(queue_messages, 0x00000002, "Please call me\n");
    enqueue(queue_messages, 0x00000003, "Please call me\n");
    enqueue(queue_messages, 0x00000004, "Please call me\n");
    enqueue(queue_messages, 0x00000005, "Please call me\n");
    print_queue(queue_messages);
    bool status;
    dequeue(queue_messages,  &status);

    print_queue(queue_messages);
    destroy_queue(queue_messages);
    return 0;
    
}

Queue* create_queue()
{
   Queue* queue = (Queue*)malloc(sizeof(Queue));
   queue->first_message =NULL;
   queue->last_message = NULL;
   queue->size = 0;
   return queue;
}

int size(Queue* queue)
{
    return queue->size;
}

bool is_empty(Queue* queue)
{
    return (queue->size == 0);
}

int peek(Queue* queue, bool* status)
{
    if(is_empty(queue)) 
    { 
        *status = false;
        return Empty;
    }
    *status = true;

    return queue->first_message->message_id;
}

void enqueue(Queue* queue, int id, char* sms)
{
   Message *new_message = (Message*)malloc(sizeof(Message));
   new_message->message_id = id;
   new_message->message = sms;
   new_message->next_message =NULL;

   if(is_empty(queue))
   {
     queue->first_message = new_message;
     queue->last_message = new_message;
   }
   else
   {
     queue->last_message->next_message = new_message;
     queue->last_message = new_message;
   }
   queue->size++;
}

int dequeue(Queue* queue, bool* status)
{
    if(is_empty(queue))
    {
        *status = false;
        return Empty;
    }
    *status = true;
    int message_id = queue->first_message->message_id;
    Message* old_first_message = queue->first_message;
    if(queue->size ==1)
    {
        queue->first_message = NULL;
        queue->last_message =NULL;
    }
    else
    {
          queue->first_message = queue->first_message->next_message;

    }
   
    free(old_first_message);

    queue->size--;
    return message_id;

}
void destroy_queue(Queue* queue)
{
   while (!is_empty(queue)) 
    {
        bool status;
        dequeue(queue, &status);
    }
    free(queue);
}

void print_queue(Queue* queue)
{
    printf("  ......  You have New Messages[%d]   .......\n", size(queue));
    Message* current_message = queue->first_message;
    while (current_message != NULL) 
    {
        printf("%s ", current_message->message);
        current_message = current_message->next_message;
    }
    printf("\n");
}