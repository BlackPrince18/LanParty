#include "liste.h"

Node* create_first_node(Node* head, int data)
{
    head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->link = NULL;

    return head;
}

Node* create_list(Node* head)
{
    Node *previous, *current;
    int aux, nr, i;
    
    printf("How many elements? ");
    scanf("%d", &nr);

    printf("Type the elements: ");
    scanf("%d", &aux);
    previous = create_first_node(previous, aux);
    head = previous;

    for(i=1; i<nr; i++)
    {
        current = (Node*)malloc(sizeof(Node));
        scanf("%d", &current->data);
        current->link = NULL;
        previous->link = current;
        previous = current;
    }

    return head;
}

void print_list(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }
}

void Linsert_at_end(Node* head, int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    Node* index = head;
    while(index->link != NULL)
    {
        index = index->link;
    }

    index->link = temp;
}

Node* Linsert_at_beginning(Node* head, int data)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = head;
    head = temp;

    return head;
}

void Linsert_at_pos(Node* head, int data, int position)
{
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->link = NULL;

    Node* index;
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

Node* Ldelete_first(Node *head)
{
    if(head == NULL)
        printf("List is already empty.");
    else
    {
        Node *temp = head;
        head = head->link;
        free(temp);
    }
    
    return head;
}

Node *Ldelete_last (Node *head)
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
        Node *index1, *index2;
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

void Ldelete_pos (Node **head, int position)
{
    Node *previous, *current;
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