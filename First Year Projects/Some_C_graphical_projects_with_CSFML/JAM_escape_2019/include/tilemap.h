/*
** EPITECH PROJECT, 2020
** TILEMAP
** File description:
** Tilemap header
*/

#ifndef TILEMAP_H_
#define TILEMAP_H_

//////////////////////// VAR ////////////////////////

// maps
static int const NB_MAPS = 3;
static char const MAPS_PATH[3][100] = {
    "assets/maps/map1.txt",
    "assets/maps/map2.txt",
    "assets/maps/map3.txt"
};
static char const MAPS_PREVIEW_PATH[1][100] = {
    "assets/maps/background.png"
};

// map layers
static int const NB_MAP_LAYERS = 1;
static int const MAP_LAYER = 0;

// tileset
static int const TILESIZE = 60;
static int const TILESET_TILESIZE = 236;
static char const TILESET[50] = "assets/tileset/tileset.png";

#endif /* !TILEMAP_H_ */