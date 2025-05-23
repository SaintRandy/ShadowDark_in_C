#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipment.h"
#include "dice.h"

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
    new.weapon_bonus = 0;

    memcpy(new._range, range, sizeof(unsigned) * WEAPON_RANGE_SZ);
    memcpy(new._type, type, sizeof(unsigned) * WEAPON_TYPE_SZ);
    
    new._type[MELEE] = type[MELEE];
    new._type[RANGED] = type[RANGED];
    
    new.price = price;

    return new;
}


weapon basic_unarmed(unsigned dice) {
    return conctrucor_weapon(dice, 0, CLOSE_RANGED_WEAPON, MELEE_WEAPON, 0);
}