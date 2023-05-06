#include "liste.h"

LNode* create_first_node(LNode* head, int data)
{
    head = (LNode*)malloc(sizeof(LNode));
    head->data = data;
    head->link = NULL;

    return head;
}

LNode* create_list(LNode* head)
{
    LNode *previous, *current;
    int aux, nr, i;
    
    printf("How many elements? ");
    scanf("%d", &nr);

    printf("Type the elements: ");
    scanf("%d", &aux);
    previous = create_first_node(previous, aux);
    head = previous;

    for(i=1; i<nr; i++)
    {
        current = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &current->data);
        current->link = NULL;
        previous->link = current;
        previous = current;
    }

    return head;
}

void print_list(LNode* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }
}

void Linsert_at_end(LNode* head, int data)
{
    LNode* temp;
    temp = (LNode*)malloc(sizeof(LNode));
    temp->data = data;
    temp->link = NULL;

    LNode* index = head;
    while(index->link != NULL)
    {
        index = index->link;
    }

    index->link = temp;
}

LNode* Linsert_at_beginning(LNode* head, int data)
{
    LNode* temp;
    temp = (LNode*)malloc(sizeof(LNode));
    temp->data = data;
    temp->link = head;
    head = temp;

    return head;
}

void Linsert_at_pos(LNode* head, int data, int position)
{
    LNode* temp;
    temp = (LNode*)malloc(sizeof(LNode));
    temp->data = data;
    temp->link = NULL;

    LNode* index;
    index = head;

    position--;
    while(position != 1)
    {
        index = index->link;
        position--;
    }

    temp->link = index->link;
    index->link = temp;
}

LNode* Ldelete_first(LNode *head)
{
    if(head == NULL)
        printf("List is already empty.");
    else
    {
        LNode *temp = head;
        head = head->link;
        free(temp);
    }
    
    return head;
}

LNode *Ldelete_last (LNode *head)
{
    if(head == NULL)
    {
        printf("Your list is empty!");
    }
    else if(head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        LNode *index1, *index2;
        index1 = head;

        while(index1->link != NULL)
        {
            index2 = index1;
            index1 = index1->link;
        }

        free(index1);
        index2->link = NULL;
    }

    return head;
}

void Ldelete_pos (LNode **head, int position)
{
    LNode *previous, *current;
    previous = *head;
    current = *head;

    if(*head == NULL)
    {
        printf("Your list is empty.");
    }
    else if(position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(position != 1)
        {
            previous = current; 
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}