#include "cozi.h"
#include "stive.h"
#include "liste.h"
#include "arbori.h"

int main(int argc, char* argv[])
{
    int number_of_teams, eliminate = 0, min_poz;
    int i = 0, j, c = 1;                         
    SNode *losers = NULL, *winners = NULL, *ptr;
    QNode *current;
    Team* teams;
    LTeam1 *head = NULL, *aux1 = NULL;
    LTeam1 *headcopy = NULL;
    LTeam2 *first_eight = NULL;
    LTeam2 *aux = NULL;
    TNode *ranking = NULL;
    FILE *checker, *reading_file, *writing_file;
    
    checker = fopen("c.in", "r");
    test_file(checker);
    reading_file = fopen("d.in", "r");
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

        if(i == number_of_teams) break;
        i++;
    }
    
    for(i=0; i<=number_of_teams; i++) {
        head = add_at_beginning1(head, teams[i].name, teams[i].players, teams[i].number_of_players);
    }
                                
    headcopy = head;
    for(i=0; i<number_of_teams; i++) {
        remove_car(headcopy->name);
        headcopy = headcopy->link;
    }    

    eliminate = eliminate_team(number_of_teams);

    float min;
    for(i=0; i<=eliminate; i++) {
        c = 1;
        min = 10000;
        min_poz = 1;
        headcopy = head;
        while(headcopy != NULL) {   
            if(headcopy->score < min) {
                min = headcopy->score;
                min_poz = c;
            }
            c++;
            headcopy = headcopy->link;
        }
        if(min_poz == 1)
        {
            aux1 = head;
            head = head->link;
            free(aux1);
        }
        else del_pos(&head, min_poz);
    }
    
    number_of_teams = number_of_teams - eliminate;            

    writing_file = fopen("r.out", "w");
    test_file(writing_file);
    print_teams(number_of_teams, writing_file, head);

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

    current = matches->front;
    c = 1;

    while(number_of_teams != 1) {   
        fprintf(writing_file, "\n--- ROUND NO:%d\n", c);
        
        current = matches->front;
        print_matches(current, writing_file);
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

        number_of_teams = number_of_teams / 2;
        if(number_of_teams != 1) fprintf(writing_file, "\nWINNERS OF ROUND NO:%d\n", c);
        else fprintf(writing_file, "\nWINNER OF ROUND NO:%d\n", c);

        ptr = winners;
        
        deleteQueue(matches);
        
        if(number_of_teams != 1) {
            while(ptr != NULL)
            {
                ptr->score++;
                (ptr->link)->score++;
                
                fprintf(writing_file, "%s", ptr->team);
                for(i=0; i<(34-strlen(ptr->team)); i++)
                    fprintf(writing_file, " ");
                fprintf(writing_file, "%.2f\n", ptr->score);
                fprintf(writing_file, "%s", (ptr->link)->team);
                for(i=0; i<(34-strlen((ptr->link)->team)); i++)
                    fprintf(writing_file, " ");
                fprintf(writing_file, "%.2f\n", (ptr->link)->score);
                
                enQueue(matches, ptr->team, (ptr->link)->team,  ptr->score, (ptr->link)->score);
                ptr = (ptr->link)->link;
            }
        }
        else {
            ptr->score++;
            fprintf(writing_file, "%s", ptr->team);
            for(i=0; i<(34-strlen(ptr->team)); i++)
                fprintf(writing_file, " ");
            fprintf(writing_file, "%.2f", ptr->score);
        }
        
        if(number_of_teams == 1) {
            ptr = winners;
            first_eight = add_at_beginning2(first_eight, ptr->team, ptr->score);
        }

        c++;
    }

    aux = first_eight;

    while(aux != NULL)
    {
        ranking = insertNode(ranking, aux->name, aux->score);
        aux = aux->link;
    }
    fprintf(writing_file, "\n\nTOP 8 TEAMS:\n");
    inorderTraversal(ranking, writing_file);

    return 0;
}