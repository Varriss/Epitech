/*
** EPITECH PROJECT, 2020
** load_files
** File description:
** load_files
*/

#include "corewar.h"
#include "op.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void take_name(vm_data_t *data, int i, int fd)
{
    char *name = malloc(sizeof(char) * (MAX_NAME_LEN + 1));
    int rt_read = 1;

    lseek(fd, 4, SEEK_SET);
    if (!name)
        return;
    for (int i = 0; rt_read == 1 && i < MAX_NAME_LEN; i++) {
        read(fd, &name[i], 1);
        name[i + 1] = '\0';
    }
    data->prog[i]->name = name;
}

static int load_one_file(vm_data_t *data, int i)
{
    int origin = data->prog[i]->origin;
    int fd = open(data->prog[i]->name, O_RDONLY);
    int rt_read = 1;

    if (fd == -1)
        return (ERROR);
    take_name(data, i, fd);
    lseek(fd, BLOCK_COMMENT_LEN, SEEK_CUR);
    while (rt_read == 1) {
        if (origin >= MEM_SIZE || data->mem[origin] != 0)
            return (ERROR);
        rt_read = read(fd, &data->mem[origin], 1);
        origin += 1;
    }
    data->prog[i]->pc = data->prog[i]->origin;
    data->prog[i]->carry = 0;
    return (0);
}

static int check_adress(vm_data_t *data, int i, int adress, int count)
{
    for (int k = 0; k <= count; k++)
        if (adress + k >= MEM_SIZE || data->mem[adress + k] != 0)
            return (ERROR);
    data->prog[i]->origin = adress;
    return (1);
}

static int found_place(vm_data_t *data, int i)
{
    int fd = open(data->prog[i]->name, O_RDONLY);
    int stock = 0;
    int rt_read = 1;
    int count = 0;

    if (fd == -1)
        return (ERROR);
    while (rt_read == 1) {
        rt_read = read(fd, &stock, 1);
        count += 1;
    }
    count -= BLOCK_NAME_LEN + BLOCK_COMMENT_LEN;
    close(fd);
    for (int k = 0; k < 4; k++)
        if (check_adress(data, i, MEM_SIZE / 4 * k, count) == 1)
            return (0);
    for (int k = 0; k < MEM_SIZE; k++)
        if (data->mem[k] == 0 && check_adress(data, i, k, count) == 1)
            return (0);
    return (ERROR);
}

int load_files(vm_data_t *data)
{
    for (int i = 0; data->prog[i]; i++)
        if (data->prog[i]->origin != -1
        && load_one_file(data, i) == ERROR)
            return (ERROR);
    for (int i = 0; data->prog[i]; i++)
        if (data->prog[i]->origin == -1
        && (found_place(data, i) == ERROR || load_one_file(data, i) == ERROR))
            return (ERROR);
    return (0);
}
