/*
** EPITECH PROJECT, 2020
** MY_TILESET
** File description:
** My_tileset header
*/

#ifndef MY_TILESET_H_
#define MY_TILESET_H_

//////////////////////// VAR ////////////////////////

// def struct
typedef struct tileset_s tileset_t;

// struct
struct tileset_s
{
    int tilesize_x;
    int tilesize_y;
    int nb_tiles;
    sfTexture **tiles;
};

///////////////////// PROTOTYPE /////////////////////

tileset_t *tileset_create(int nb_tiles);
int tileset_load(tileset_t *tileset, char const *tileset_path,
    int tilesize_x, int tilesize_y);
sfTexture *tileset_get(tileset_t *tileset, int id);
void *tileset_destroy(tileset_t *tileset);

#endif /* !MY_TILESET_H_ */