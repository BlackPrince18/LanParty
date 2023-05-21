#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem3
{
    char *team1;
    char *team2;
    struct Elem3* link;
};

typedef struct Elem3 QNode;

struct q
{
    QNode *front, *rear;
};

typedef struct q Queue;

int isEmptyQ(Queue* queue);
Queue* create_queue();
void enQueue(Queue* queue, char *team1, char *team2);
