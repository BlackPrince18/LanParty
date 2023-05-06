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
    QNode* temp;
    temp = (QNode*)malloc(sizeof(QNode));
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

    QNode* temp;

    temp = q->front;
    q->front = (q->front)->link;
    free(temp);
}

void deleteQueue(Queue* q)
{
    QNode* temp;
    if(isEmptyQ(q)) printf("Lista este goala!\n");

    while(!isEmptyQ(q))
    {
        temp = q->front;
        q->front = (q->front)->link;
        free(temp);
    }
    free(q);
}