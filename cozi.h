#include <stdio.h>
#include <stdlib.h>

struct Elem
{
    int data;
    struct Elem* link;
};

typedef struct Elem Node;

struct q
{
    Node *front, *rear;
};

typedef struct q Queue;

Queue* createQueue();
void enQueue(Queue* q, int data);
int isEmptyQ(Queue* q);
void deQueue(Queue* q);
void deleteQueue(Queue* q);