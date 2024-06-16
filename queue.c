#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void initQueue(Queue* queue) {
    queue->headIndex = 0;
    queue->tailIndex = 0;
}

int enqueue(Queue* queue, char* src)
{
    if(queue->tailIndex == 255)
        return 0;
    else
    {
        strcpy(queue->token[queue->tailIndex], src);
        queue->tailIndex += 1;
        return 1;
    } 
}

int dequeue(Queue* queue, char* dest)
{
    if(queue->headIndex == 0)
        return 0;
    else
    {       
        strcpy(dest, queue->token[queue->headIndex]);

        strcpy(queue->token[queue->headIndex], "\0");
        //removes the token in the current head index after dequeueing

        if (queue->headIndex == queue->tailIndex) //if dequeue will empty the queue, reset values to -1
        {
            queue->headIndex = 0;
            queue->tailIndex = 0;
        }
        else
            queue->headIndex++;//we shift the head

        return 1;
    }
}


