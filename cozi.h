#include <stdio.h>
#include <stdlib.h>

struct Elem3
{
    int data;
    struct Elem3* link;
};

typedef struct Elem3 QNode;

struct q
{
    QNode *front, *rear;
};

typedef struct q Queue;

Queue* createQueue();
void enQueue(Queue* q, int data);
int isEmptyQ(Queue* q);
void deQueue(Queue* q);
void deleteQueue(Queue* q);