#include <stdio.h>
#include <stdlib.h>
#include "creatures.h"
#include "dice.h"

unsigned int roll_stat() {
    return roll_d6() + roll_d6() + roll_d6();
}

creature create_creature() {
    creature new;
    new.aligment = roll_d10() - 1;
    new.stat[STR] = roll_stat();
    new.stat[DEX] = roll_stat();
    new.stat[CON] = roll_stat();
    new.stat[INT] = roll_stat();
    new.stat[WIS] = roll_stat();
    new.stat[CHA] = roll_stat();

    return new;
}

void print_sheet(creature someone) {
    print_alligment(someone.aligment);
    printf("STATS:\nSTR: %d\nDEX: %d\nCON: %d\nINT: %d\nWIS: %d\nCHA: %d\n", someone.stat[STR], 
                                                                                            someone.stat[DEX], someone.stat[CON], someone.stat[INT], 
                                                                                            someone.stat[WIS], someone.stat[CHA]);
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