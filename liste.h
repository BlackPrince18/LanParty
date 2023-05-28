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

struct Team                                        
{
    char* name;
    Player* players;
    int number_of_players;
};

typedef struct Team Team;

struct LTeam
{
    char* name;
    Player* players;
    int number_of_players;
    float score;
    struct LTeam* link;
};

typedef struct LTeam LTeam;

void test_file(FILE *ptr);
LTeam* create_first_node(LTeam* head, char* name, Player* players, int number_of_players);
LTeam* add_at_beginning(LTeam* head, char* name, Player* players, int number_of_players);
void del_pos (LTeam **head, int pos);