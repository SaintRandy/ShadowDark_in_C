#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dice.h"
#include "creatures.h"

int main() {
    srand(time(NULL));
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n", roll_dice(D100), roll_dice(D20), roll_dice(D12), roll_dice(D10), roll_dice(D8), roll_dice(D6), roll_dice(D4), roll_dice(D2));

    creature joe_peach = create_player_character(CHAOTIC, HUMAN, FIGHTER);
    creature victor_coi = create_player_character(CHAOTIC, ELF, THIEF);

    printf("Joe Peach enters the ring!\n");
    print_sheet(joe_peach);
    printf("/\n\n//////////////////////////////////////////\n\n");
    printf("Victor Coi makes his way to the ring!\n");
    print_sheet(victor_coi);

    printf("/\n\nMatch starts!\n\n");
    while ((victor_coi.cur_hp >= 0) && (joe_peach.cur_hp >= 0))
    {
        printf("Victor Coi strikes the Joe!\n");
        creature_attack(victor_coi, victor_coi.unarmed, &joe_peach);
        printf("Joe's current HP: %d\n", joe_peach.cur_hp);
        if (joe_peach.cur_hp <= 0)
            break;
        sleep(1);
        printf("Illuha ebashit Coya!\n");
        creature_attack(joe_peach, joe_peach.unarmed, &victor_coi);
        printf("Victor's current HP: %d\n", victor_coi.cur_hp);
        sleep(1);
    }

    if (victor_coi.cur_hp <= 0)
        printf("Joe wins!\n");
    else
        printf("Victor wins!\n");
}