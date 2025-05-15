#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"
#include "creatures.h"

int main() {
    srand(time(NULL));
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n", roll_dice(D100), roll_dice(D20), roll_dice(D12), roll_dice(D10), roll_dice(D8), roll_dice(D6), roll_dice(D4), roll_dice(D2));

    print_sheet(create_creature());
}