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
