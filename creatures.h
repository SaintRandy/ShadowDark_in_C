#ifndef SD_CREATURES
#define SD_CREATURES
#include <stdlib.h>

/* Aligment has value from 1 to 10*/
typedef unsigned int aligment;
#define LAWFUL 1;
#define NEUTRAL 5;
#define CHAOTIC 10;
#define UNALIGNED 0;

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
#endif