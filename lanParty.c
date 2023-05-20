#include "cozi.h"
#include "stive.h"
#include "liste.h"

struct Team
{
    char* name;
    Player* players;
    int number_of_players;
};

typedef struct Team Team;

int main()
{
    int number_of_teams;
    int keep_reading = 1;
    int current_line = 1;
    int i = 0, j;
    FILE* reading_file;

    reading_file = fopen("d.txt", "r");
    if(reading_file == NULL)
    {
        printf("Fisierul nu a putut fi citit!\n");
        exit(1);
    }

    fscanf(reading_file, "%d", &number_of_teams);
    current_line++;

    Team* teams;
    teams = (Team*)malloc(sizeof(Team)*number_of_teams);
    if(teams == NULL)
    {
        printf("Eroare!\n");
        exit(1);
    }

    while(!feof(reading_file))
    {
        char buffer[256];
        if(current_line == 2) current_line++;
        else fgets(buffer, 256, reading_file);

        fscanf(reading_file, "%d ", &teams[i].number_of_players);
        fgets(buffer, 256, reading_file);
        teams[i].name = (char*)malloc(strlen(buffer)+1);
        strcpy(teams[i].name, buffer);
        teams[i].players = (Player*)malloc(teams[i].number_of_players*sizeof(Player));

        for(int j=0; j<teams[i].number_of_players; j++)
        {
            fscanf(reading_file, "%s", buffer);
            teams[i].players[j].lastName = (char*)malloc(strlen(buffer)+1);
            strcpy(teams[i].players[j].lastName, buffer);
            fscanf(reading_file, "%s", buffer);
            teams[i].players[j].firstName = (char*)malloc(strlen(buffer)+1);
            strcpy(teams[i].players[j].firstName, buffer);
            fscanf(reading_file, "%d", &teams[i].players[j].points);
        }

        i++;
    }

    LTeam* head, *headcopy;
    for(i=0; i<3; i++)
    {
        head = add_at_beginning(head, teams[i].name, teams[i].players, teams[i].number_of_players);
    }

    free(teams);

    float *scores;
    scores = (float*)calloc(number_of_teams, sizeof(float));
    if(scores == NULL)
    {
        printf("Eroare!\n");
        exit(1);
    }

    i = 0;
    headcopy = head;
    
    while(headcopy != NULL)
    {
        for(j = 0; j < headcopy->number_of_players; j++)
        {
            scores[i] += headcopy->players[j].points;
        }
        scores[i] /= 2;
        
        i++;
        headcopy = headcopy->link;
        if(i == 3) break;
    }

    int eliminate = 0;
    
    if(number_of_teams > 32) 
    {
        if(number_of_teams < 64) eliminate = number_of_teams - 32;
        else if(number_of_teams < 128) eliminate = number_of_teams - 64;
        else eliminate = number_of_teams - 128;
    }
    else if(number_of_teams < 32)
    {
        if(number_of_teams < 4) eliminate = number_of_teams - 2;
        else if(number_of_teams < 8) eliminate = number_of_teams - 4;
        else if(number_of_teams < 16) eliminate = number_of_teams - 8;
        else eliminate = number_of_teams - 16;
    }

    float min = scores[0];
    int min_poz = 1;

    for(i=0; i<1; i++)
    {
        for(j=1; j<3; j++)
        {
            if(scores[j] < min) 
            {
                min = scores[j];
                min_poz = j+1;
            }
        }

        del_pos(&head, min_poz);
    }

    number_of_teams = number_of_teams - eliminate;
    free(scores);

    FILE* writing_file;
    writing_file = fopen("r.txt", "w");
    if(writing_file == NULL)
    {
        printf("Fisierul nu a putut fi scris!\n");
        exit(1);
    }

    char buffer[256];
    headcopy = head;
    
    for(i=0; i<3; i++)
    {
        strcpy(buffer, headcopy->name);
        fputs(buffer, writing_file);
        headcopy = headcopy->link;
    }

    return 0;
}