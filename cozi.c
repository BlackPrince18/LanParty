#include "cozi.h"

int isEmptyQ(Queue* q)
{
    return q->front == NULL;
}

Queue* createQueue()
{
    Queue* q;
    q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL) return NULL;
    q->front = q->rear = NULL;

    return q;
}

void enQueue(Queue* q, int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    if(q->rear == NULL) q->rear = temp;
    else
    {
        (q->rear)->link = temp;
        q->rear = temp;
    }

    if(q->front == NULL) q->front = q->rear;
}

void deQueue(Queue* q)
{
    if(isEmptyQ(q)) printf("Lista este goala!\n");

    Node* temp;

    temp = q->front;
    q->front = (q->front)->link;
    free(temp);
}

void deleteQueue(Queue* q)
{
    Node* temp;
    if(isEmptyQ(q)) printf("Lista este goala!\n");

    while(!isEmptyQ(q))
    {
        temp = q->front;
        q->front = (q->front)->link;
        free(temp);
    }
    free(q);
}