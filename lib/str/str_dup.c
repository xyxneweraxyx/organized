/*
** EPITECH PROJECT, 2025
** str_dup
** File description:
** Function to malloc a new str
*/

#include <stdlib.h>
#include <stdio.h>
#include "./../../include/shell.h"

static int str_len(const char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    return i;
}

char *str_dup(const char *src)
{
    int len = str_len(src);
    char *str;

    if (len < 1)
        return NULL;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    str[len] = 0;
    for (int i = 0; i < len; i++)
        str[i] = src[i];
    return str;
}
