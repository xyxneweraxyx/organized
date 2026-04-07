/*
** EPITECH PROJECT, 2025
** organized.
** File description:
** Include of organized.
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    #define EXIT_SUCC 0
    #define EXIT_FAIL 84

// Stupid typedefs
typedef struct node
{
    int id;
    char *type;
    char *name;

    struct node *next;
    struct node *prev;
} node_t;

// t = type, n = name, i = id
typedef struct sort_criteria
{
    char criterion;
    bool reverse;
} sort_criteria_t;

typedef struct global
{
    node_t *head;
    int next_id;
} global_t;

// Stupid dependencies
int free_linked_list(global_t *main);
int str_cmp(const char *str1, const char *str2);
char *str_dup(const char *src);
void *error_free(int amount, ...);
int print_single_node(node_t *node);
int my_printf(const char *format, ...);
int str_to_int(char *str);

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
