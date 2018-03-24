#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

//calculate the the real damage done by a formula.

int dmg(int attack, int armor){
    if(attack <= armor){
        return 1;
    }
    else{
        return (attack - armor);
    }
}

//enconters random animal
void encounter_random(){
    int random = rand() % 100;
    if(random < 9){
        encounter_wolf();
    }
    else if(random < 14){
        encounter_tiger();
    }
    else if(random < 19){
        encounter_rabbit();
    }
}


void combat(monster* current_monster){
    while(current_monster->health >= 0 && health >= 0){
        monster_attack(current_monster);
        current_monster->health -= dmg(attack, current_monster->armor);
    }
    if(health<=0){
        printf("You didn't win this combat\n");
    }
    else{
        health += current_monster->return_health;
        hunger += current_monster->return_hunger;
        if(health>100){
            health = 100;
        }
        if(hunger>100){
            hunger = 100;
        }
        printf("You won! Your health is now %d and your hunger is now %d\n", health, hunger);
    }
    monster_die(current_monster);
}


#endif
