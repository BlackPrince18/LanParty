#include "cozi.h"
#include "stive.h"
#include "liste.h"
#include <string.h>

struct Player
{
    char *firstName;
    char *lastName;
    int points;
};

typedef struct Player Player;

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
    int i = 0;
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

    return 0;
}