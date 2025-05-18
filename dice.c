#include <stdlib.h>
#include "dice.h"

unsigned int roll_dice(unsigned int top) {
    return rand() % top + 1;
}

unsigned int roll_d6() {
    return roll_dice(D6);
}

unsigned int roll_d10() {
    return roll_dice(D10);
}

unsigned int roll_d20() {
    return roll_dice(D20);
}

unsigned int roll_d20_advantage() {
    unsigned int first = roll_d20();
    unsigned int second = roll_d20();
    return first >= second ? first : second;
}

unsigned int roll_d20_disadvantage() {
    unsigned int first = roll_d20();
    unsigned int second = roll_d20();
    return first <= second ? first : second;
}