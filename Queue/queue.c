#include "queue.h"

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

    if(is_empty(queue))
    {
        printf("You have read all messages \n");
    }
}

int search_by_id(Queue* queue, int message_id)
{
    Message* current_message = queue->first_message;
    while (current_message !=NULL)
    {
        /* code */
        if(current_message->message_id == message_id)
        {
            printf("The message id was found ..\n");
            return message_id;
        }
        current_message = current_message->next_message;
    }

    printf("The message is not found ....\n");
    return NOT_FOUND;
}