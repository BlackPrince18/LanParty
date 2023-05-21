#include "cozi.h"
#include "stive.h"
#include "liste.h"

// am creat structura unei echipe
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
    int i = 0, j;
    FILE* reading_file;                             // am creat fisierul pentru citire

    reading_file = fopen("d.txt", "r");
    if(reading_file == NULL)
    {
        printf("Fisierul nu a putut fi citit!\n");
        exit(1);
    }

    fscanf(reading_file, "%d", &number_of_teams);  // am citit prima linie pe care erau numarul de echipe

    Team* teams;                                   // am creat un vector de echipe pentru o implementare mai usoara a listei de echipe
    teams = (Team*)malloc(sizeof(Team)*number_of_teams);    
    if(teams == NULL)
    {
        printf("Eroare!\n");
        exit(1);
    }

    while(!feof(reading_file))                     // am inceput sa citesc din fisier fiecare informatie si sa o introduc in vector
    {
        char buffer[256];

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

    LTeam* head, *headcopy;                        // am inceput implementarea listei
    for(i=0; i<number_of_teams; i++)
    {
        head = add_at_beginning(head, teams[i].name, teams[i].players, teams[i].number_of_players);
    }

    free(teams);                                   // dupa ce am completat toata lista, nu am mai avut nevoie de vectorul auxiliar

    float *scores;                                 // am creat un vector pentru a retine scorul fiecarei echipe in ordinea in care erau trecute in lista
    scores = (float*)calloc(number_of_teams, sizeof(float));
    if(scores == NULL)
    {
        printf("Eroare!\n");
        exit(1);
    }

    i = 0;
    headcopy = head;
    
    while(headcopy != NULL)                        // in acest ciclu am calculat fiecare scor
    {
        for(j=0; j<headcopy->number_of_players; j++)
        {
            scores[i] += headcopy->players[j].points;
        }
        scores[i] /= 2;
        
        i++;
        headcopy = headcopy->link;
        if(i == number_of_teams) break;
    }

    int eliminate = 0;                             // am creat o variabila ca sa stiu cate echipe trebuie eliminate
    
    if(number_of_teams > 32)                       // am implementat un algoritm pentru a afla numarul echipelor eliminate
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

    for(i=0; i<eliminate; i++)
    {
        for(j=1; j<number_of_teams; j++)             // acest ciclu calculeaza de fiecare data cel mai mic scor, urmand ca echipa sa fie scoasa
        {
            if(scores[j] < min) 
            {
                min = scores[j];
                min_poz = j+1;
            }
        }

        del_pos(&head, min_poz);
    }

    number_of_teams = number_of_teams - eliminate;  // am actualizat numarul de echipe
    free(scores);               

    FILE* writing_file;                             // am creat un fisier pentru a scrie numele echipelor ramase
    writing_file = fopen("r.txt", "w");
    if(writing_file == NULL)
    {
        printf("Fisierul nu a putut fi scris!\n");
        exit(1);
    }

    headcopy = head;

    for(i=0; i<number_of_teams; i++)
    {
        fputs(headcopy->name, writing_file);
        headcopy = headcopy->link;
    }

    Queue* matches;                                // am creat coada pentru meciuri
    matches = create_queue();
    
    headcopy = head;
    while(headcopy->link != NULL)
    {
        enQueue(matches, headcopy->name, (headcopy->link)->name);
        headcopy = (headcopy->link)->link;
    }

    return 0;
}