#ifndef _ENTITY_H_
#define _ENTITY_H_

//==============================================================================
// Includes
//==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include "common_typedef.h"
#include "tilemap.h"
#include "gameData.h"

//==============================================================================
// Enums
//==============================================================================

typedef enum {
    ENTITY_PLAYER,
    ENTITY_TEST
} entityIndex_t;

//==============================================================================
// Structs
//==============================================================================

typedef void(*updateFunction_t)(struct entity_t *self);

struct entity_t
{
    bool active;
    //bool important;

    uint8_t type;
    updateFunction_t updateFunction;

    uint16_t x;
    uint16_t y;
    
    int16_t xspeed;
    int16_t yspeed;
    int16_t gravity;

    uint8_t spriteIndex;
    uint8_t animationTimer;

    tilemap_t * tilemap;
    gameData_t * gameData;
};

//==============================================================================
// Prototypes
//==============================================================================
void initializeEntity(entity_t * entity, tilemap_t * tilemap, gameData_t * gameData);

void updatePlayer(entity_t * self) ;

void updateTestObject(entity_t * self);

void moveEntityWithTileCollisions(entity_t * self);

#endif