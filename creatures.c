#include <stdio.h>
#include <stdlib.h>
#include "creatures.h"
#include "equipment.h"
#include "dice.h"

 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

unsigned int roll_stat() {
    return roll_d6() + roll_d6() + roll_d6();
}

int count_modifier(unsigned stat){
    return ((int)stat-10)/2;
}

creature create_creature() {
    creature new;

    for (unsigned i = STR; i <= CHA; i++) {
        new.stat[i] = roll_stat();
        new.mod[i] = count_modifier(new.stat[i]);
    }
    
    return new;
}

static unsigned establish_hit_dice(unsigned class) {
    switch (class)
    {
    case FIGHTER:
        return D8;
    case PRIEST:
        return D6;
    case THIEF:
        return D4;
    case WIZARD:
        return D4;
    default:
        return D6;
    }
}

static unsigned roll_hp(unsigned dice, unsigned con) {
    return max(1, roll_dice(dice) + con);
}

creature create_player_character(unsigned aligment, unsigned race, unsigned class) {
    creature new = create_creature();
    
    new.race = race;
    new.class = class;
    new.aligment = aligment;

    new.hit_dice = establish_hit_dice(class);
    new.hp = (int) roll_hp(new.hit_dice, new.mod[CON]);
    new.cur_hp = new.hp;

    new.basic_ac = 10 + new.mod[DEX];
    new.unarmed = basic_unarmed(D4);

    new.equip = NULL;

    return new;
}

void creature_attack(creature attacker, weapon attack_weapon, creature *defender) {
    int damage;
    if ((attacker.mod[STR] + roll_d20()) > defender->basic_ac) {
        printf("Hit!\n");
        damage = (int) (attacker.mod[STR] + roll_dice(attack_weapon.damage_dice) + attack_weapon.weapon_bonus);
        defender->cur_hp -= damage;
    } else {
        printf("Miss!\n");
    }
}

void print_sheet(creature someone) {
    print_alligment(someone.aligment);
    printf("STATS:\nSTR: %d\nDEX: %d\nCON: %d\nINT: %d\nWIS: %d\nCHA: %d\n\n", someone.stat[STR], someone.stat[DEX], someone.stat[CON], 
                                                                                        someone.stat[INT], someone.stat[WIS], someone.stat[CHA]);
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    printf("MODS:\nSTR: %d\nDEX: %d\nCON: %d\nINT: %d\nWIS: %d\nCHA: %d\n\n", someone.mod[STR], someone.mod[DEX], someone.mod[CON], 
                                                                                        someone.mod[INT], someone.mod[WIS], someone.mod[CHA]);
    printf("HIT DICE: %d\nHP: %d -- CURRENT HP: %d\n", someone.hit_dice, someone.hp, someone.cur_hp);
}

void print_alligment(unsigned int aligment) {
    if (aligment == 0) {
        printf("Unaligned: %d\n", aligment);
        return;
    }

    if (aligment <= (LAWFUL+NEUTRAL)/2){
        printf("Lawful: %d\n", aligment);
        return;
    } else if (aligment >= (CHAOTIC+NEUTRAL)/2){
        printf("Chaotic: %d\n", aligment);
        return;
    } 
    
    printf("Neutral: %d\n", aligment); 
    return;
}