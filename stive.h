#include <stdio.h>
#include <stdlib.h>

struct Elem1
{
    int data;
    struct Elem1* link;
};

typedef struct Elem1 SNode;

SNode* push(SNode* Top, int data);
int isEmptyS(SNode* Top);
SNode* pop(SNode* Top);
void deleteStack(SNode** Top);