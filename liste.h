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

typedef struct LTeam LTeam1;

struct LTeam2
{
    char* name;
    float score;
    struct LTeam2* link;
};

typedef struct LTeam2 LTeam2;

void test_file(FILE *ptr);
LTeam1* create_first_node1(LTeam1* head, char* name, Player* players, int number_of_players);
LTeam1* add_at_beginning1(LTeam1* head, char* name, Player* players, int number_of_players);
void del_pos (LTeam1 **head, int pos);
LTeam2* create_first_node2(LTeam2* head, char* name, float score);
LTeam2* add_at_beginning2(LTeam2* head, char* name, float score);