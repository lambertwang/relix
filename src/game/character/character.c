#include "character.h"

// Library
#include <stdlib.h>

// Game
#include "../item/item.h"

#include "log/log.h"

CharacterData *createCharData() {
    CharacterData *data = malloc(sizeof(CharacterData));

    data->name = createString();
    data->max_health = 0;
    data->health = 0;

    data->level = 1;

    data->equipment = NULL;
    initArray(&data->inventory);

    return data;
}

void closeCharData(CharacterData *data) {
    deleteString(data->name);
    deleteEquipment(data->equipment);
    closeArray(&data->inventory);
}

