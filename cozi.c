#include "cozi.h"

int isEmptyQ(Queue* queue)
{
    return queue->front == NULL;
}

Queue* create_queue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = NULL;
    queue->rear = NULL;
    
    return queue;
}

void enQueue(Queue* queue, char *team1, char *team2)
{
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->team1 = (char*)malloc(strlen(team1)+1);
    strcpy(temp->team1, team1);
    temp->team2 = (char*)malloc(strlen(team2)+1); 
    strcpy(temp->team2, team2);
    temp->link = NULL;

    if(queue->rear == NULL) queue->rear = temp;
    else
    {
        (queue->rear)->link = temp;
        queue->rear = temp;
    }

    if(isEmptyQ) queue->front = queue->rear;
}