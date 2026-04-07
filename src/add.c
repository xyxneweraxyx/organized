/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Add function of organized.
*/

#include "./../include/shell.h"

static bool is_category_correct(char *category)
{
    if (str_cmp(category, "ACTUATOR") == 0)
        return true;
    if (str_cmp(category, "DEVICE") == 0)
        return true;
    if (str_cmp(category, "PROCESSOR") == 0)
        return true;
    if (str_cmp(category, "SENSOR") == 0)
        return true;
    if (str_cmp(category, "WIRE") == 0)
        return true;
    return false;
}

static node_t *create_single_node(char *type, char *name, global_t *main)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        return NULL;
    if (!is_category_correct(type))
        return error_free(1, new_node);
    if (!name)
        return error_free(1, new_node);
    new_node->type = str_dup(type);
    if (!new_node->type)
        return error_free(1, new_node);
    new_node->name = str_dup(name);
    if (!new_node->name)
        return error_free(2, new_node->type, new_node);
    new_node->id = main->next_id;
    main->next_id += 1;
    return new_node;
}

int add(void *data, char **args)
{
    global_t *main = (global_t *)data;
    node_t *current_add;

    if (!main || !args)
        return EXIT_SUCC;
    for (int i = 0; args[i] && args[i + 1]; i += 2) {
        current_add = create_single_node(args[i], args[i + 1], main);
        if (!current_add) {
            return free_linked_list(main);
        }
        current_add->next = main->head;
        current_add->prev = NULL;
        if (main->head)
            main->head->prev = current_add;
        main->head = current_add;
        my_printf("%s n°%d - \"%s\" added.\n", current_add->type,
            current_add->id, current_add->name);
    }
    return EXIT_SUCC;
}
