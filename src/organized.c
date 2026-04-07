/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Main organized file.
*/

#include "./../include/shell.h"

int free_linked_list(global_t *main)
{
    node_t *temp = NULL;

    for (node_t *current = main->head; current;) {
        temp = current;
        current = current->next;
        free(temp->name);
        free(temp->type);
        free(temp);
    }
    return EXIT_FAIL;
}

int main(int argc, char **argv)
{
    global_t *main = malloc(sizeof(global_t));
    int error = 0;

    if (!main)
        return EXIT_FAIL;
    main->head = NULL;
    main->next_id = 0;
    if (workshop_shell((void *)main) == EXIT_FAIL)
        error = 1;
    if (!error)
        free_linked_list(main);
    free(main);
    return (!error) ? EXIT_SUCC : EXIT_FAIL;
}
