#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Elem1
{
    char* team;
    float score;
    struct Elem1* link;
};

typedef struct Elem1 SNode;

void push(SNode** Top, char* team, float score);
int isEmptyS(SNode* Top);
void pop(SNode** Top);
void deleteStack(SNode** Top);
void delete_Stacks(SNode** Top1, SNode** Top2, int n);
