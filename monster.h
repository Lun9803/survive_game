#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

//attributes of a monster
typedef struct monster {
	int attack;
	int armor;
	int health;
	int return_health;
	int return_hunger; //the health the palyer gets in return after kill the
} monster;

//free the memory when the monster dies
void monster_die(monster* current_monster){
    free(current_monster);
}

//monster attack
void monster_attack(monster* current_monster){
    health -= dmg(current_monster->attack, armor);
}

//below are the monster types
//create a new wolf object
monster* create_wolf(){
    monster * new_wolf;
    new_wolf = (monster *)malloc(5*sizeof(int));
    new_wolf->armor = 0;
    new_wolf->attack = 15;
    new_wolf->health = 30;
    new_wolf->return_health = 15;
    new_wolf->return_hunger = 50;
    return new_wolf;
}

void encounter_wolf(){
    printf("You encountered a wolf!\n");
    monster* new_wolf = create_wolf();
    combat(new_wolf);
}
//tiger
monster* create_tiger(){
    monster * new_tiger;
    new_tiger = (monster *)malloc(5*sizeof(int));
    new_tiger->armor = 5;
    new_tiger->attack = 30;
    new_tiger->health = 50;
    new_tiger->return_health = 25;
    new_tiger->return_hunger = 70;
    return new_tiger;
}

void encounter_tiger(){
    printf("You encountered a tiger!\n");
    monster * new_tiger = create_tiger();
    combat(new_tiger);
}

//rabbit
monster* create_rabbit(){
    monster* new_rabbit;
    new_rabbit = (monster *)malloc(5*sizeof(int));
    new_rabbit->armor = 0;
    new_rabbit->attack = 0;
    new_rabbit->health = 20;
    new_rabbit->return_health = 10;
    new_rabbit->return_hunger = 20;
    return new_rabbit;
}

void encounter_rabbit(){
    printf("You luckily encountered a rabbit!\n");
    health+=10;
    hunger+=20;
    if(health>100){
        health = 100;
    }
    if(hunger>100){
        hunger = 100;
    }
    printf("You hunt the rabbit and your health now is %d and hunger is %d\n", health, hunger);
}




#endif
