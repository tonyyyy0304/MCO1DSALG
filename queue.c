#include <stdlib.h>
#include <stdio.h>


void initQueue(Queue* queue) {
    queue->headIndex = -1;
    queue->tailIndex = -1;
    for(int i = 0; i<256; i++)
        strcpy(queue->token[i], "\0");
}

void resetQueue(Queue* queue){
    queue->headIndex = -1;
    queue->tailIndex = -1;
    for(int i = 0; i<256; i++)
        strcpy(queue->token[i], "\0");
}

int enqueue(Queue* queue, char* src)
{
    if(queue->tailIndex == 255)
        return 0;
    else
    {
        if(queue->headIndex == -1)
            queue->headIndex = 0;
        
        queue->tailIndex += 1;
        strcpy(queue->token[queue->tailIndex], src);
        return 1;
    } 
}

int dequeue(Queue* queue, char* dest)
{
    if(queue->headIndex == -1)
        return 0;
    else
    {       
        strcpy(dest, queue->token[queue->headIndex]);

        strcpy(queue->token[queue->headIndex], "\0");
        //removes the token in the current head index after dequeueing

        if (queue->headIndex == queue->tailIndex) //if dequeue will empty the queue, reset values to -1
        {
            queue->headIndex = -1;
            queue->tailIndex = -1;
        }
        else
            queue->headIndex += 1;//we shift the head
            
        return 1;
    }
}


