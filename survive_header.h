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
int enhance_armor_time = 2;

int day = 1;
int hour = 8;


//system methods
void printline(){
    printf("=======================================================\n");
}

int check_energy(int act_time){
    if(energy>=10*act_time){
        return 1;
    }
    else{
        printf("You don't have enough energy to do that\n");
        return 0;
    }
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
        if(hour == 24){
            day+=1;
            hour = 0;
        }
        printf("You died because of low health\n");
        printf("You lived for %d days and %d hours, good luck next time!\n", day, hour);
        return 1;
    }
    else if(hunger<=0){
        if(hour == 24){
            day+=1;
            hour = 0;
        }
        printf("You died beacause of hunger\n");
        printf("You lived for %d days and %d hours, good luck next time!\n", day, hour);
        return 1;
    }
    else if(hunger<=30){
        printf("Your hunger is %d, you need to find something to eat!\n", hunger);
        return 0;
    }
    else{
        return 0;
    }
}

//player actions
void findfood(){
    if(hunger==100){
        printf("You are full already, no need to find food\n");
        return;
    }
    if(check_energy(findfoodTime)==1){
        hour+=findfoodTime;
        hunger-=5*findfoodTime;
        energy-=10*findfoodTime;
        int random = rand() % 10;
        if(random < 3){
            hunger+=15;
            health+=10;
            if(health>100){
                health = 100;
            }
            printf("You have found something to eat, your hunger is now %d and health is %d\n", hunger, health);
        }
        else{
            printf("Unfortunately you didn't find anything to eat\n");
        }
    }
    else{
        return;
    }
}

void hunt(){
    if(check_energy(huntTime)==1){
        hour+=huntTime;
        hunger-=10*huntTime;
        int current_hunger = hunger;
        encounter_random();
        if(current_hunger == hunger){
            printf("Hunting unsuccessful\n");
        }
    }
    else{
        return;
    }
}

void rest(){
    if (energy == 100){
        printf("You don't need to rest now\n");
    }

    else{
        hour+=restTime;
        energy+=30;
        hunger-=10*restTime;
        health+=5;
        if(energy > 100){
            energy = 100;
        }
        if(health>100){
            health = 100;
        }
        printf("Your energy increases to %d\n", energy);
    }

}

void enhance_armor(){
    if(check_energy(enhance_armor_time)==1){
        hour+=enhance_armor_time;
        energy-=10*enhance_armor_time;
        hunger-=10*enhance_armor_time;
        armor+=5;
    }
    else{
        return;
    }
}

void sleep(){
    hunger -= 10;
    energy = 100;
    hour = 8;
}



#endif // SURVIVE_HEADER_H_INCLUDED
