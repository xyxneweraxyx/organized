/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Add function of organized.
*/

#include "./../include/shell.h"

int disp(void *data, char **args)
{
    global_t *main = (global_t *)data;

    for (node_t *node = main->head; node; node = node->next)
        my_printf("%s n°%d - \"%s\"\n", node->type, node->id, node->name);
    return EXIT_SUCC;
}
