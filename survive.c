#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "survive_header.h"
#include "monster.h"
#include "combat.h"


int main(){
    //setting player name
    printf("game starts now, please enter your charactor name\n");
    scanf("%s", name);
    printline();
    printf("Hello, %s! Welcome to the dark world, in this world, you need to try your best to survive.\n", &name);
    printf("Here is your attributes: health: %d, hunger: %d, energy: %d, armor: %d, attack: %d\n", health, hunger, energy, armor, attack);

    char command[20];
    printf("Type 'go' to start, or 'q' to quit\n");
    scanf("%s", command);


    while(strcmp(command, "q") != 0){
        printline();
        printf("Day %d begins, the time is %d:00\n Your health is %d and hunger is %d\n", day, hour, health, hunger);

        printline();

        int move;
        while(hour < 24){
            printf("you have the following options:\n   1. Find food\n   2. Hunt\n   3. Rest\n   4. Enhance Armor\n");
            printf("Enter the number of the move\n");
            scanf("%d", &move);

            //find food
            if(move == 1){
                if(check_time(findfoodTime, hour)==1){
                    findfood();
                }
                else{
                    timewarn();
                }
            }
            //hunt
            else if(move == 2){
                if(check_time(huntTime, hour)==1){
                    hunt();
                }
                else{
                    timewarn();
                }
            }
                //rest
            else if(move == 3){
                if(check_time(restTime, hour)==1){
                    rest();
                }
                else{
                    timewarn();
                }
            }

            else if(move == 4){
                if(check_time(enhance_armor_time, hour)==1){
                    enhance_armor();
                }
                else{
                    timewarn();
                }
            }
            encounter_random();
            if(check_alive()==1){
                exit(0);
            }
            printline();
            printf("The time is %d:00\n", hour);
            printline();
        }
        sleep();
        if(check_alive()==0){
            printf("Day %d has ended, congrats! type 'q' to quit or 'go' to continue\n", day);
            printline();
            day++;
            scanf("%s", command);
        }
        else{
            exit(0);
        }
    }

}


