#include <stdio.h>
#include <stdlib.h>

struct Elem
{
    int data;
    struct Elem* link;
};

typedef struct Elem Node;

Node* push(Node* Top, int data);
int isEmpty(Node* Top);
Node* pop(Node* Top);
void deleteStack(Node** Top);