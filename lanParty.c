#include "cozi.h"
#include "stive.h"
#include "liste.h"
#include "arbori.h"

int main()
{
    int number_of_teams, eliminate = 0, min_poz;
    int i = 0, j, c = 1;                         
    SNode *losers = NULL, *winners = NULL, *ptr;
    QNode *current;
    Team* teams;
    LTeam1 *head, *headcopy;
    LTeam2 *first_eight, *aux;
    TNode *ranking;
    FILE *reading_file, *writing_file1, *writing_file2; 
    
    reading_file = fopen("d.txt", "r");
    test_file(reading_file);
    fscanf(reading_file, "%d", &number_of_teams);  

    teams = (Team*)malloc(sizeof(Team)*number_of_teams);    
    check_team(teams);

    while(!feof(reading_file)) {
        char buffer[MAX_LENGTH_STR];

        fscanf(reading_file, "%d ", &teams[i].number_of_players);
        fgets(buffer, 256, reading_file);
        teams[i].name = (char*)malloc(strlen(buffer)+1);
        strcpy(teams[i].name, buffer);
        teams[i].players = (Player*)malloc(teams[i].number_of_players*sizeof(Player));

        for(int j=0; j<teams[i].number_of_players; j++) {
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
    
    for(i=0; i<number_of_teams; i++) {
        head = add_at_beginning1(head, teams[i].name, teams[i].players, teams[i].number_of_players);
    }
    free(teams);                                   

    headcopy = head;
    for(i=0; i<number_of_teams; i++) {
        remove_car(headcopy->name);
        headcopy = headcopy->link;
    }                      
    eliminate = eliminate_team(number_of_teams);

    float min = head->score;
    headcopy = head;
    for(i=0; i<eliminate; i++) {
        while(headcopy != NULL) {   
            if(headcopy->score < min) {
                min = headcopy->score;
                min_poz = c;
            }
            c++;
            headcopy = headcopy->link;
        }
        del_pos(&head, min_poz);
    }

    number_of_teams = number_of_teams - eliminate;            

    writing_file1 = fopen("r.txt", "w");
    test_file(writing_file1);
    headcopy = head;
    print_teams(number_of_teams, writing_file1, headcopy);

    fclose(writing_file1);

    Queue* matches;                                
    matches = create_queue();
    
    headcopy = head;
    c = 0;
    while(headcopy->link != NULL) {
        enQueue(matches, headcopy->name, (headcopy->link)->name, headcopy->score, (headcopy->link)->score);
        headcopy = (headcopy->link)->link;
        c += 2;
        if(c == number_of_teams) break;
    }

    writing_file2 = fopen("r.txt", "a");
    test_file(writing_file2);

    current = matches->front;
    c = 1;

    while(number_of_teams != 1) {   
        fprintf(writing_file2, "\n--- ROUND NO:%d\n", c);
        
        current = matches->front;
        print_matches(current, writing_file2);
        delete_Stacks(&winners, &losers, c);
        
        current = matches->front;
        while(current != NULL) {   
            if((current->score1 > current->score2) || (current->score1 == current->score2)) {
                push(&winners, current->team1, current->score1);
                push(&losers, current->team2, current->score2);
            }
            else {
                push(&winners, current->team2, current->score2);
                push(&losers, current->team1, current->score1);
            }
            current = current->link;
        }

        if(number_of_teams <= 8) {   
            ptr = losers;
            while(ptr != NULL)
            {
                first_eight = add_at_beginning2(first_eight, ptr->team, ptr->score);
                ptr = ptr->link; 
            }
        }

        if(number_of_teams == 2) {
            ptr = winners;
            first_eight = add_at_beginning2(first_eight, ptr->team, ptr->score);
        }

        number_of_teams = number_of_teams / 2;
        if(number_of_teams != 1) fprintf(writing_file2, "\nWINNERS OF ROUND NO:%d\n", c);
        else fprintf(writing_file2, "\nWINNER OF ROUND NO:%d\n", c);

        ptr = winners;
        
        deleteQueue(matches);
        
        if(number_of_teams != 1) {
            while(ptr != NULL)
            {
                fprintf(writing_file2, "%s\t\t\t- %.2f\n%s\t\t\t- %.2f\n", ptr->team, ptr->score, (ptr->link)->team, (ptr->link)->score);
                ptr->score++;
                (ptr->link)->score++;
                enQueue(matches, ptr->team, (ptr->link)->team,  ptr->score, (ptr->link)->score);
                ptr = (ptr->link)->link;
            }
        }
        else {
            fprintf(writing_file2, "%s\t\t\t- %.2f\n", ptr->team, ptr->score);
        }

        c++;
    }

    aux = first_eight;
    printf("nnn\n");
    //ranking = insertNode(ranking, aux->name, aux->score);
    aux = aux->link;

    return 0;
}