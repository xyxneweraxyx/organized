/*
** EPITECH PROJECT, 2025
** frees
** File description:
** Function to free multiple instances at once while returning an error.
*/

#include <stdlib.h>
#include <stdarg.h>

// Only takes strings into account.
void *error_free(int amount, ...)
{
    va_list args;

    va_start(args, amount);
    for (int i = 0; i < amount; i++)
        free(va_arg(args, void *));
    return NULL;
}
