#include "stive.h"

int isEmptyS(SNode* Top)
{
    return Top == NULL;
}

SNode* push(SNode* Top, int data)
{
    SNode* temp;
    temp = (SNode*)malloc(sizeof(SNode));
    temp->data = data;
    temp->link = Top;
    Top = temp;

    return Top;
}

SNode* pop(SNode* Top)
{
    if(isEmptyS(Top)) printf("Stiva este goala!\n");

    SNode* temp;
    temp = Top;
    Top = Top->link;
    free(temp);

    return Top;
}

void deleteStack(SNode** Top)
{
    if(isEmptyS(*Top)) printf("Stiva este goala!\n");

    SNode* temp;
    
    while(!isEmptyS(*Top))
    {
        temp = *Top;
        *Top = (*Top)->link;
        free(temp);
    }
}
