#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Initialize the queue.
 *
 * This function sets the head and tail indices of the queue to -1 and 
 * clears all token entries in the queue.
 *
 * @param queue Pointer to the Queue to initialize.
 */
void initQueue(Queue* queue) {
    queue->headIndex = -1;
    queue->tailIndex = -1;
    for(int i = 0; i<256; i++)
        strcpy(queue->token[i], "\0");
}

/**
 * @brief Reset the queue.
 *
 * This function resets the head and tail indices of the queue to -1 and
 * clears all token entries in the queue.
 *
 * @param queue Pointer to the Queue to reset.
 */
void resetQueue(Queue* queue){
    queue->headIndex = -1;
    queue->tailIndex = -1;
    for(int i = 0; i<256; i++)
        strcpy(queue->token[i], "\0");
}

/**
 * @brief Add an element to the queue.
 *
 * This function enqueues a string into the queue. If the queue is full,
 * it returns 0; otherwise, it returns 1.
 *
 * @param queue Pointer to the Queue where the string will be enqueued.
 * @param src The string to enqueue.
 * @return 1 if the string was enqueued successfully, 0 if the queue is full.
 */
int enqueue(Queue* queue, char* src)
{
    if(queue->tailIndex == 255)
        return 0;
    else{
        if(queue->headIndex == -1)
            queue->headIndex = 0;
        
        queue->tailIndex += 1;
        strcpy(queue->token[queue->tailIndex], src);
        return 1;
    }
}

/**
 * @brief Remove and retrieve an element from the queue.
 *
 * This function dequeues a string from the queue and stores it in the provided
 * destination. If the queue is empty, it returns 0; otherwise, it returns 1.
 *
 * @param queue Pointer to the Queue from which the string will be dequeued.
 * @param dest The destination where the dequeued string will be stored.
 * @return 1 if the string was dequeued successfully, 0 if the queue is empty.
 */
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


