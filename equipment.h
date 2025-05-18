#ifndef SD_EQUIPMENT
#define SD_EQUIPMENT

typedef enum eq_type {
    WEAPON,
    ARMOR,
    GEAR
} eq_type;

typedef enum range {
    CLOSE,
    NEAR,
    FAR
} range;

#define CLOSE_RANGED_WEAPON (unsigned[]){1, 0, 0}

/* Weapon type */
typedef enum w_type {
    MELEE,
    RANGED
} w_type;

#define MELEE_WEAPON (unsigned[]){1, 0}
#define RANGED_WEAPON (unsigned[]){0, 1}
#define HYBRID_WEAPON (unsigned[]){1, 1}

typedef struct gear {

} gear;

typedef struct armor {
    /* Main properties */
    unsigned int ac;
    unsigned int DEX_cap;

    /* Additional */
    unsigned char stealth_dis;
    unsigned char no_swim;
    unsigned char mithral;

    unsigned int price;
    unsigned int geat_slots;
} armor;

typedef struct weapon {
    unsigned int damage_dice;
    unsigned int weapon_bonus;

    unsigned int _range[3];
    unsigned int _type[2];

    unsigned int price;
} weapon;


typedef struct equipment {
    eq_type type;
    armor _armor;
    weapon _weapon;
} equipment;

typedef struct eq_list
{
    equipment node;
    eq_list *next;
} eq_list;

extern weapon basic_unarmed(unsigned dice);

#endif