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

typedef struct wolf {
	int attack: 30;
	int armor: 10;
	int health: 30;
} wolf;


void printline(){
    printf("=======================================================\n");
}

void timewarn(){
    printf("You don't have enough time to do that\n");
}

void findfood(){
    hour+=findfoodTime;
}

void hunt(){
    hour+=huntTime;
}

void rest(){
    hour+=restTime;
    energy+=10;
    if(energy > 100){
        energy = 100;
    }
    printf("Your energy increases to %d\n", energy);
}

void sleep(){
    hunger -= 60;
    energy = 100;
    hour = 8;
}


#endif // SURVIVE_HEADER_H_INCLUDED
