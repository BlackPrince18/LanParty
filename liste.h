#include <stdio.h>
#include <stdlib.h>

struct Elem2
{
    int data;
    struct Elem2* link;
};

typedef struct Elem2 LNode;

LNode* create_first_node(LNode* head, int value);
LNode* create_list(LNode* head);
void print_list(LNode* head);
void Linsert_at_end(LNode* head, int data);
LNode* Linsert_at_beginning(LNode* head, int data);
void Linsert_at_pos(LNode* head, int data, int position);
LNode* Ldelete_first(LNode* head);
LNode *Ldelete_last (LNode* head);
void Ldelete_pos (LNode **head, int position);