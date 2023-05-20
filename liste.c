#include "liste.h"

LTeam* create_first_node(LTeam* head, char* name, Player* players, int number_of_players)
{
    head = (LTeam*)malloc(sizeof(LTeam));
    head->name = (char*)malloc(strlen(name)+1);
    strcpy(head->name, name);
    head->number_of_players = number_of_players;
    head->players = (Player*)malloc(sizeof(Player)*number_of_players);

    for(int i=0; i<number_of_players; i++)
    {
        head->players[i].firstName = (char*)malloc(strlen(players[i].firstName)+1);
        strcpy(head->players[i].firstName, players[i].firstName);

        head->players[i].lastName = (char*)malloc(strlen(players[i].lastName)+1);
        strcpy(head->players[i].lastName, players[i].lastName);
        
        head->players[i].points = players[i].points;
    }

    head->link = NULL;

    return head;
}

LTeam* add_at_beginning(LTeam* head, char* name, Player* players, int number_of_players)
{
    if(head == NULL)
        head = create_first_node(head, name, players, number_of_players);
    else
    {
        LTeam* temp;
        temp = (LTeam*)malloc(sizeof(LTeam));
        temp->name = (char*)malloc(strlen(name)+1);
        strcpy(temp->name, name);
        temp->number_of_players = number_of_players;
        temp->players = (Player*)malloc(sizeof(Player)*number_of_players);

        for(int i=0; i<number_of_players; i++)
        {
            temp->players[i].firstName = (char*)malloc(strlen(players[i].firstName)+1);
            strcpy(temp->players[i].firstName, players[i].firstName);

            temp->players[i].lastName = (char*)malloc(strlen(players[i].lastName)+1);
            strcpy(temp->players[i].lastName, players[i].lastName);
        
            temp->players[i].points = players[i].points;
        }

        temp->link = head;
        head = temp;

        return head;
    }
}

void del_pos (LTeam **head, int pos)
{
    LTeam *p, *c;
    p = *head;
    c = *head;

    if(*head == NULL)
    {
        printf("Your list is empty.");
    }
    else if(pos == 1)
    {
        *head = c->link;
        free(c);
        c = NULL;
    }
    else
    {
        while(pos != 1)
        {
            p = c; 
            c = c->link;
            pos--;
        }
        p->link = c->link;
        free(c);
        c = NULL;
    }
}