#ifndef SD_CREATURES
#define SD_CREATURES
#include <stdlib.h>

/* Aligment has value from 0 to 10*/
#define LAWFUL 1
#define NEUTRAL 5
#define CHAOTIC 9

typedef struct creature {
    unsigned int aligment;
    unsigned int stat[6];
} creature;

typedef enum stats {
    STR,
    DEX,
    CON,
    INT,
    WIS,
    CHA
} stats;

typedef enum classes {
    FIGHTER,
    PRIEST,
    THIEF,
    WIZARD,
    CLASSLESS
} classes;

extern creature create_creature();

extern void print_alligment(unsigned int aligment);

extern void print_sheet(creature someone);

#endif