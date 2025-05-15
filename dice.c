#include <stdlib.h>
#include "dice.h"

unsigned int roll_dice(unsigned int top) {
    return rand() % top + 1;
}

