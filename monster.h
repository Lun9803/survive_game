#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

//attributes of a monster
typedef struct monster {
	int attack;
	int armor;
	int health;
	int return_health;
	int return_hunger; //the health the palyer gets in return after kill the monster
} monster;

//create a new wolf object
monster* create_wolf(){
    monster * new_wolf;
    new_wolf = (monster *)malloc(4*sizeof(int));
    new_wolf->armor = 0;
    new_wolf->attack = 30;
    new_wolf->health = 30;
    new_wolf->return_health = 15;
    new_wolf->return_hunger = 50;
}

void encounter_wolf(){
    printf("You encountered a wolf!\n");
    monster* new_wolf = create_wolf();
    combat(new_wolf);
}

//free the memory when the monster dies
void monster_die(monster* current_monster){
    free(current_monster);
}

//monster attack
void monster_attack(monster* current_monster){
    health -= dmg(current_monster->attack, armor);
}



#endif
