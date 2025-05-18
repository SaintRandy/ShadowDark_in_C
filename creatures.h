#ifndef SD_CREATURES
#define SD_CREATURES
#include <stdlib.h>
#include "equipment.h"

/* Aligment has value from 0 to 10*/
#define LAWFUL 1
#define NEUTRAL 5
#define CHAOTIC 9
#define UNALIGNED 0

typedef enum stats {
    STR,
    DEX,
    CON,
    INT,
    WIS,
    CHA
} stats;

typedef enum races {
    DWARF,
    ELF,
    GOBLIN,
    HALFLING,
    HALFORC,
    HUMAN
} races;

typedef enum classes {
    FIGHTER,
    PRIEST,
    THIEF,
    WIZARD,
    CLASSLESS
} classes;

typedef struct creature {
    char name[64];

    int hp;
    int cur_hp;

    unsigned basic_ac;
    unsigned hit_dice;
    
    unsigned race;
    unsigned class;
    unsigned aligment;

    weapon unarmed;

    unsigned stat[6];
    int mod[6];
    /* Equppuied in hands/on body */
    /* List of equipment */
    eq_list *equip;
    /* List of spells and boons*/
} creature;

extern creature create_creature();

extern creature create_player_character(unsigned aligment, unsigned race, unsigned class);

extern void creature_attack(creature attacker, weapon attack_weapon, creature *defender);

extern void print_alligment(unsigned int aligment);

extern void print_sheet(creature someone);

#endif