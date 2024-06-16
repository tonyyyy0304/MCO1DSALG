#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct Node{
    char value;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int size;
}Queue;

Queue *createQueue();
int sizeOfQueue(Queue *q);
char peekQueue(Queue *q);
void Enqueue(Queue *q, char token);
char Dequeue(Queue *q);
bool isQueuempty(Queue *q);

#endif