#include "stive.h"

int isEmptyS(SNode* Top)
{
    return Top == NULL;
}

void push(SNode** Top, char* team, float score)
{
    SNode* temp;
    temp = (SNode*)malloc(sizeof(SNode));
    temp->team = (char*)malloc(strlen(team)+1);
    strcpy(temp->team, team);
    temp->score = score;
    temp->link = *Top;
    *Top = temp;
}

void pop(SNode** Top)
{
    if(isEmptyS(*Top)) printf("Stiva este goala!\n");

    SNode* temp;
    char* aux;
    temp = *Top;
    *Top = (*Top)->link;
    free(temp);
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
