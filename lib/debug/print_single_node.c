/*
** EPITECH PROJECT, 2025
** organized.
** File description:
** Include of organized.
*/

#include "./../../include/shell.h"

int print_single_node(node_t *node)
{
    my_printf("--- SINGLE NODE BEGIN\n");
    my_printf("Id is %d\n", node->id);
    my_printf("Type is %s\n", node->type);
    my_printf("Name is %s\n", node->name);
    return EXIT_SUCC;
}
