#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Player
{
    char *firstName;
    char *lastName;
    int points;
};

typedef struct Player Player;

struct LTeam
{
    char* name;
    Player* players;
    int number_of_players;
    struct LTeam* link;
};

typedef struct LTeam LTeam;

LTeam* create_first_node(LTeam* head, char* name, Player* players, int number_of_players);
LTeam* add_at_beginning(LTeam* head, char* name, Player* players, int number_of_players);
