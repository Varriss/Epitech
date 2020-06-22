/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** NAVY
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "../lib/my/my.h"

int usleep(unsigned int usec);

#define SUCCESS_CODE 0
#define FAILURE_CODE 84

// minimum 150 for security
#define SEND_SLEEP 250

int sig_handle(int signal);
struct sigaction *init_sig(void);
int wait_value(void);
void send_value_to(int x, int usr_id);

int j_one_start(void);
int j_two_start(char *j_one);
int link_then_start(int argc, char *const *argv, char **map);

int clean_all(int to_return, char **map, struct sigaction *sig);

char **check_input_file(char *path);

char **convert_input_file(char **file);

char **generate_layout(void);

int fill_map_from_file(char ***res, char **file);

int game(int one_id, int two_id, char **map);

int is_between_a_h(char c);
int is_between_one_heigth(char c);
void get_prompt_result(char *pos, size_t *n);

int update_own_map(char **map, char *pos);
int update_radar(char **radar, char *pos, int hitted);
void print_maps(char **own_map, char **radar);

#endif /* !NAVY_H_ */
