/*
** EPITECH PROJECT, 2020
** AUDIO
** File description:
** Audio header
*/

#ifndef AUDIO_H_
#define AUDIO_H_

//////////////////////// VAR ////////////////////////

// game
static int const G_MUSIC_COUNT = 1;
static int const G_SOUND_COUNT = 4;

static int const G_MAIN_THEME = 0;
static char const MAIN_THEME_PATH[50] = "assets/audio/music/kammarheit_the_poignant.ogg";

static int const G_CANON_SOUND = 0;
static char const CANON_SOUND_PATH[50] = "assets/audio/sound/canon.ogg";
static int const G_MISSILE_SOUND = 1;
static char const MISSILE_SOUND_PATH[50] = "assets/audio/sound/missile.ogg";
static int const G_SNIPER_SOUND = 2;
static char const SNIPER_SOUND_PATH[50] = "assets/audio/sound/sniper.ogg";
static int const G_EXPLOSION_SOUND = 3;
static char const EXPLOSION_SOUND_PATH[50] = "assets/audio/sound/explosion.ogg";

// lose
static int const L_MUSIC_COUNT = 0;
static int const L_SOUND_COUNT = 1;

static int const L_WASTED_SOUND = 0;
static char const WASTED_SOUND_PATH[50] = "assets/audio/sound/wasted.ogg";

#endif /* !AUDIO_H_ */