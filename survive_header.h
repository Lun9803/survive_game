#ifndef SURVIVE_HEADER_H_INCLUDED
#define SURVIVE_HEADER_H_INCLUDED

#include <stdio.h>
int health = 100;
int hunger = 100;
int energy = 100;
int armor = 0;
int attack = 10;
char name[20];

int findfoodTime = 1;
int huntTime = 3;
int restTime = 1;

int day = 1;
int hour = 8;


//system methods
void printline(){
    printf("=======================================================\n");
}


int check_time(int act_time,int current_time){
    if(24-current_time >= act_time){
        return 1;
    }
    else{
        return 0;
    }
}

void timewarn(){
    printline();
    printf("You don't have enough time to do that\n");
}

int check_alive(){
    if(health <= 0 ){
        return 1;
    }
    else{
        return 0;
    }
}



//player actions
void findfood(){
    hour+=findfoodTime;
}

void hunt(){
    hour+=huntTime;
}

void rest(){
    if (energy == 100){
        printf("You don't need to rest now\n");
    }

    else{
        hour+=restTime;
        energy+=10;
        if(energy > 100){
            energy = 100;
        }
        printf("Your energy increases to %d\n", energy);
    }

}

void sleep(){
    hunger -= 60;
    energy = 100;
    hour = 8;
}



#endif // SURVIVE_HEADER_H_INCLUDED
