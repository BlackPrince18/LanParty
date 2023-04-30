#include <stdio.h>
#include <stdlib.h>

struct Elem
{
    int data;
    struct Elem* link;
};

typedef struct Elem Node;

Node* create_first_node(Node* head, int value);
Node* create_list(Node* head);
void print_list(Node* head);
void Linsert_at_end(Node* head, int data);
Node* Linsert_at_beginning(Node* head, int data);
void Linsert_at_pos(Node* head, int data, int position);
Node* Ldelete_first(Node* head);
Node *Ldelete_last (Node* head);
void Ldelete_pos (Node **head, int position);