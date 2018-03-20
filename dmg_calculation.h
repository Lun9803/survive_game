#ifndef DMG_CALCULATION_H_INCLUDED
#define DMG_CALCULATION_H_INCLUDED

//calculate the the real damage done by a formula.

int dmg(int attack, int armor){
    if(attack <= armor){
        return 1;
    }
    else{
        return (attack - armor);
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
        printf("You won! Your health is now %d\n", health);
    }
}


#endif // DMG_CALCULATION_H_INCLUDED
