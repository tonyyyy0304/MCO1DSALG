#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

Queue* createQueue(){
    Queue *q = malloc(sizeof(Queue));

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

int sizeOfQueue(Queue *q){
    return q->size;
}

bool isQueuempty(Queue *q){
    return (q->size == 0);
}

char peekQueue(Queue *q){
    return q->head->value; 
}

void Enqueue(Queue *q, char token){
    Node *nextNode = malloc(sizeof(Node));

    nextNode->value = token; // stores token to the link 
    nextNode->next = NULL; // creates a new link

    if(isQueuempty(q)){ // checks if token is empty 
        q->head = nextNode;  // both head and tail points to the new node 
        q->tail = nextNode;
    }else{
        q->tail->next = nextNode; // the tail points to the new node 
        q->tail = nextNode; // updates the current node 
    }

    q->size++; // increments size of queue

}

char Dequeue(Queue *q){

    if (isQueuempty(q) || q->head == NULL){
        printf("Head is empty");
        return '\0';
    }

    char head = q->head->value;

    Node* oldHead = q->head;

    q->head = q->head->next;

    free(oldHead);

    if (q->head == NULL){ 
        q->tail = NULL; 
    }
  
    q->size--;

    return head;
}
