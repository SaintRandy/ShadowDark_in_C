#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipment.h"
#include "dice.h"
#include "utils.h"

const unsigned damage_dice_ref[] = {D12, D10, D8, D6, D4};

eq_list *initialize_eq_list() {
    eq_list *pointer = calloc(1, sizeof(eq_list));

    if (pointer == NULL) {
      fprintf(stderr, "Memory allocation for equipment failed!\n");
      return NULL;
    }

    return pointer;
}

eq_list *add_node_eq_list(eq_list *node) {
    if (node == NULL)
        return NULL;
    
    for (; node->next != NULL; node = node->next);
    
    node->next = initialize_eq_list();
    return node->next;
}

int free_eq_list(eq_list *node) {
    if (node == NULL)
        return 1;
    
    eq_list *tmp;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    
    return 0;
}

weapon conctrucor_weapon(unsigned dice, unsigned bonus, unsigned range[], unsigned type[], unsigned price) {
    weapon new;

    new.damage_dice = dice;
    new.weapon_bonus = bonus;

    memcpy(new._range, range, sizeof(unsigned) * WEAPON_RANGE_SZ);
    memcpy(new._type, type, sizeof(unsigned) * WEAPON_TYPE_SZ);
    
    new.price = price;

    return new;
}


weapon basic_unarmed(unsigned dice) {
    return conctrucor_weapon(dice, 0, CLOSE_RANGED_WEAPON, MELEE_WEAPON, 0);
}

unsigned roll_damage_dice(unsigned dice) {
    if (valueinarray(dice, damage_dice_ref, sizeof(damage_dice_ref)))
        return 0;
    return roll_dice(dice);
}