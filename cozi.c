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

void enQueue(Queue* queue, char *team1, char *team2, float score1, float score2)
{
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->team1 = (char*)malloc(strlen(team1)+1);
    strcpy(temp->team1, team1);
    temp->team2 = (char*)malloc(strlen(team2)+1); 
    strcpy(temp->team2, team2);
    temp->score1 = score1;
    temp->score2 = score2;
    temp->link = NULL;

    if(queue->rear == NULL) queue->rear = temp;
    else
    {
        (queue->rear)->link = temp;
        queue->rear = temp;
    }

    if(queue->front == NULL) queue->front = queue->rear;
}

void deleteQueue(Queue* queue) 
{
    if (queue == NULL)
        return;

    QNode* currentNode = queue->front;
    while (currentNode != NULL) {
        QNode* temp = currentNode;
        currentNode = currentNode->link;
        free(temp);
    }

    queue->front = NULL;
    queue->rear = NULL;
}

void print_matches(QNode* q, FILE *ptr)
{
    int i;
    while(q != NULL)
    {
        fprintf(ptr, "%s", q->team1, q->score1);
        for(i=0; i<(33 - strlen(q->team1)); i++)
            fprintf(ptr, " ");
        fprintf(ptr, "-");
        for(i=0; i<(33 - strlen(q->team2)); i++)
            fprintf(ptr, " ");
        fprintf(ptr, "%s\n", q->team2, q->score2);
        q = q->link;
    }
}
