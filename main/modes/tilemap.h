#ifndef _TILEMAP_H_
#define _TILEMAP_H_

//==============================================================================
// Includes
//==============================================================================

#include <stdint.h>
#include <stdbool.h>
#include "display.h"

//==============================================================================
// Structs
//==============================================================================

typedef struct 
{
    wsg_t tiles[10];

    uint8_t * map;
    uint8_t mapWidth;
    uint8_t mapHeight;

    int16_t mapOffsetX;
    int16_t mapOffsetY;
    
    int16_t minMapOffsetX;
    int16_t maxMapOffsetX;
    int16_t minMapOffsetY;
    int16_t maxMapOffsetY;

} tilemap_t;

//==============================================================================
// Prototypes
//==============================================================================
void initializeTileMap(tilemap_t * tilemap);
void drawTileMap(display_t * disp, tilemap_t * tilemap);
void scrollTileMap(tilemap_t * tilemap, int16_t x, int16_t y);
void drawTile(tilemap_t * tilemap, uint8_t tileId, int16_t x, int16_t y);
bool loadMapFromFile(tilemap_t * tilemap, char * name);
bool loadTiles(tilemap_t * tilemap);


#endif