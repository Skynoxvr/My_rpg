/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** parsing.c
*/

#include <stddef.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parsing.h"

static char *get_str_from_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer;

    stat(filepath, &sb);
    buffer = malloc(sb.st_size + 1);
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    close(fd);
    return buffer;
}

int get_line_count(char *buffer)
{
    int lines = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            lines++;
    return lines;
}

static int **parse_buffer_to_int_pairs(char *buffer, int *line_count)
{
    int lines = 0;
    int **coords;
    char *line;
    int index = 0;

    lines = get_line_count(buffer);
    coords = malloc(sizeof(int *) * (lines + 1));
    line = strtok(buffer, "\n");
    while (line != NULL && index < lines) {
        coords[index] = malloc(sizeof(int) * 2);
        sscanf(line, "%d %d", &coords[index][0], &coords[index][1]);
        coords[index][0] *= 48;
        coords[index][0] += 24;
        coords[index][1] *= 48;
        index++;
        line = strtok(NULL, "\n");
    }
    coords[index] = NULL;
    *line_count = index;
    return coords;
}

int **open_file_and_parse_coords(char *filepath)
{
    char *buffer = get_str_from_file(filepath);
    int line_count;
    int **coords;

    if (buffer == NULL)
        return NULL;
    coords = parse_buffer_to_int_pairs(buffer, &line_count);
    free(buffer);
    return coords;
}

void init_parsing(parsing_t *parsing, char *filepath)
{
    parsing = malloc(sizeof(parsing_t));

    parsing->collision_file = open_file_and_parse_coords(filepath);
}
