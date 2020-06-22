/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ai
*/

#include <unistd.h>
#include <stdio.h>
#include "ai.h"

static command_t test_commands[] = {
    {".", FLOAT_EMPTY, INT_EMPTY},
    {"START_SIMULATION", FLOAT_EMPTY, INT_EMPTY},
    {"STOP_SIMULATION", FLOAT_EMPTY, INT_EMPTY},
    {"GET_INFO_LIDAR", FLOAT_EMPTY, INT_EMPTY},
    {"CAR_FORWARD", 1, INT_EMPTY}
};

float adjust_speed(float angle, float *dists)
{
    float max_speed = 1;
    float min_speed = 0.2;
    float speed = (angle > 0 ? (max_speed - angle) : (max_speed + angle));
    float avrg_dist = 0;

    avrg_dist = (dists[13] + dists[14] + dists[15] + dists[16]+ dists[17] +
    dists[18] + dists[19]) / 5;
    if (speed > max_speed)
        speed = max_speed;
    else if (speed <= min_speed)
        speed = min_speed;
    speed /= (3010 / avrg_dist) * 0.5;
    if (angle != 0 && speed < 0.001)
        speed = 1;
    return (speed > 1 ? 1 : speed);
}

int end_reached(void)
{
    static char *to_comp = "18:KO:Command not found:Track Cleared";
    char *str = NULL;

    send(&test_commands[0]);
    str = receive();
    if (str == NULL)
        return (0);
    for (int i = 0; (to_comp[i] != '\0') && (str[i] != '\0'); i++)
        if (str[i] != to_comp[i]) {
            free(str);
            return (0);
        }
    free(str);
    return (1);
}

float choose_wheel_dir(response_t *response)
{
    float mid_d = response->distances[16];
    float left_d = response->distances[31];
    float right_d = response->distances[0];
    float res = 0.0;

    res = (right_d - left_d) / 25000 * (6020 / mid_d);
    if (res < -1)
        res = -1;
    else if (res > 1)
        res = 1;
    return (res);
}

void change_dir_and_speed(float dir, float *dists)
{
    command_t *command = create_command("WHEELS_DIR", dir, INT_EMPTY);

    send(command);
    free(receive());
    free(command);
    command = create_command("CAR_FORWARD"
    , adjust_speed(dir, dists), INT_EMPTY);
    send(command);
    free(receive());
    free(command);
}

int ai(void)
{
    float dir = 0;
    response_t *response;
    command_t *command;

    send(&test_commands[1]);
    free(receive());
    sleep(1);
    send(&test_commands[4]);
    free(receive());
    while (!end_reached()) {
        send(&test_commands[3]);
        response = parser(receive(), test_commands[3].command);
        dir = choose_wheel_dir(response);
        change_dir_and_speed(dir, response->distances);
    }
    command = create_command("CAR_FORWARD", 0.0, INT_EMPTY);
    send(command);
    free(command);
    sleep(2);
    send(&test_commands[2]);
    return (SUCCESS_CODE);
}