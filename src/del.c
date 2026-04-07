/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Add function of organized.
*/

#include "./../include/shell.h"

static bool is_number_in_array(int nb, char **nbs)
{
    for (int i = 0; nbs[i]; i++) {
        if (str_to_int(nbs[i]) == nb)
            return true;
    }
    return false;
}

static int del_single_node(global_t *main, node_t *node)
{
    my_printf("%s n°%d - \"%s\" deleted.\n", node->type,
        node->id, node->name);
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    if (node == main->head)
        main->head = node->next;
    free(node->name);
    free(node->type);
    free(node);
    return EXIT_SUCC;
}

static int get_total_ids_del(char **args)
{
    int i = 0;

    for (i = 0; args[i]; i++);
    return i;
}

static bool does_array_contain_duplicates(char **args)
{
    int current = 0;

    for (int i = 0; args[i]; i++) {
        current = str_to_int(args[i]);
        if (is_number_in_array(current, &args[i + 1]))
            return true;
    }
    return false;
}

int del(void *data, char **args)
{
    global_t *main = (global_t *)data;
    node_t *temp;
    int total_del = get_total_ids_del(args);
    int total = 0;

    if (!main->head || !total_del || does_array_contain_duplicates(args))
        return free_linked_list(main);
    for (node_t *node = main->head; node;) {
        if (is_number_in_array(node->id, args)) {
            total++;
            temp = node;
            node = node->next;
            del_single_node(main, temp);
        } else
            node = node->next;
    }
    if (total != total_del)
        return EXIT_FAIL;
    return EXIT_SUCC;
}
