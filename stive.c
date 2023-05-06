#include "stive.h"

int isEmpty(Node* Top)
{
    return Top == NULL;
}

Node* push(Node* Top, int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = Top;
    Top = temp;

    return Top;
}

Node* pop(Node* Top)
{
    if(isEmpty(Top)) printf("Stiva este goala!\n");

    Node* temp;
    temp = Top;
    Top = Top->link;
    free(temp);

    return Top;
}

void deleteStack(Node** Top)
{
    if(isEmpty(*Top)) printf("Stiva este goala!\n");

    Node* temp;
    
    while(!isEmpty(*Top))
    {
        temp = *Top;
        *Top = (*Top)->link;
        free(temp);
    }
}
