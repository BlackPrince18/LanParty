#include "liste.h"

void test_file(FILE *ptr)
{
    if(ptr == NULL)
    {
        printf("Eroare!\n");
        exit(1);
    }
}

LTeam1* create_first_node1(LTeam1* head, char* name, Player* players, int number_of_players)
{
    float sum = 0;
    head = (LTeam1*)malloc(sizeof(LTeam1));
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
        sum += players[i].points;
    }
    head->score = sum / number_of_players;

    head->link = NULL;

    return head;
}

LTeam1* add_at_beginning1(LTeam1* head, char* name, Player* players, int number_of_players)
{
    float sum = 0;
    
    if(head == NULL)
        head = create_first_node1(head, name, players, number_of_players);
    else
    {
        LTeam1* temp;
        temp = (LTeam1*)malloc(sizeof(LTeam1));
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
            sum += players[i].points;
        }
        temp->score = sum / number_of_players;

        temp->link = head;
        head = temp;

        return head;
    }
}

void del_pos (LTeam1 **head, int pos)
{
    LTeam1 *p, *c;
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

LTeam2* create_first_node2(LTeam2* head, char* name, float score)
{
    head = (LTeam2*)malloc(sizeof(LTeam2));
    head->name = (char*)malloc(strlen(name)+1);
    strcpy(head->name, name);
    head->score = score;
    head->link = NULL;

    return head;
}

LTeam2* add_at_beginning2(LTeam2* head, char* name, float score)
{
    if(head == NULL) create_first_node2(head, name, score);
    else
    {
        LTeam2* temp;
        temp = (LTeam2*)malloc(sizeof(LTeam2));
        temp->name = (char*) malloc(strlen(name)+1);
        strcpy(temp->name, name);
        temp->score = score;
        temp->link = head;
        head = temp;

        return head;
    }
}

void remove_car(char* string)
{
    int j;

    for(j=0; j<MAX_LENGTH_STR; j++)
        {
            if(string[j] == '\n')
            {
                string[j] = ' ';
                break;
            }
        }
}

int eliminate_team(int n)
{
    int x;
    if(n > 32)
    {                    
        if(n < 64) x = n- 32;
        else if(n < 128) x = n - 64;
        else x = n - 128;
    }
    else if(n < 32)
    {
        if(n < 4) x = n - 2;
        else if(n < 8) x = n - 4;
        else if(n < 16) x = n - 8;
        else x = n - 16;
    }

    return x;
}

void check_team(Team *v)
{
    if(v == NULL)
    {
        printf("Eroare!\n");
        exit(1);
    }
}

void print_teams(int n, FILE *ptr, LTeam1* headcopy)
{
    int i;
    
    for(i=0; i<n; i++)
    {
        fputs(headcopy->name, ptr);
        fputs("\n", ptr);
        headcopy = headcopy->link;
    }
}