/*
** EPITECH PROJECT, 2025
** organized
** File description:
** Sort function of organized.
*/

#include "./../include/shell.h"

static char criterion_to_char(char *str)
{
    if (str_cmp(str, "TYPE") == 0)
        return 't';
    if (str_cmp(str, "NAME") == 0)
        return 'n';
    if (str_cmp(str, "ID") == 0)
        return 'i';
    return 0;
}

static int count_criteria(char **args)
{
    int count = 0;

    for (int i = 0; args[i]; i++) {
        if (str_cmp(args[i], "-r") != 0)
            count++;
    }
    return count;
}

static int parse_sort_criteria(char **args, sort_criteria_t *criteria)
{
    int idx = 0;

    for (int i = 0; args[i]; i++) {
        if (str_cmp(args[i], "-r") == 0)
            continue;
        if (!criterion_to_char(args[i]))
            return -1;
        criteria[idx].criterion = criterion_to_char(args[i]);
        criteria[idx].reverse = false;
        if (args[i + 1] && str_cmp(args[i + 1], "-r") == 0) {
            criteria[idx].reverse = true;
            i++;
        }
        idx++;
    }
    return idx;
}

static int compare_single_criterion(node_t *a, node_t *b, char criterion)
{
    if (criterion == 't')
        return str_cmp(a->type, b->type);
    if (criterion == 'n')
        return str_cmp(a->name, b->name);
    if (criterion == 'i')
        return a->id - b->id;
    return 0;
}

static int compare_nodes(node_t *a, node_t *b,
    sort_criteria_t *criteria, int nb_criteria)
{
    int result;

    for (int i = 0; i < nb_criteria; i++) {
        result = compare_single_criterion(a, b, criteria[i].criterion);
        if (!result)
            continue;
        if (criteria[i].reverse)
            return -result;
        return result;
    }
    return 0;
}

node_t *find_middle(node_t *head)
{
    node_t *slow = head;
    node_t *fast = head;
    node_t *prev = NULL;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev)
        prev->next = NULL;
    return slow;
}

static node_t *attach_node(node_t *tail, node_t *node)
{
    if (node) {
        tail->next = node;
        node->prev = tail;
    }
    return node ? node : tail;
}

node_t *merge_sorted_lists(node_t *left, node_t *right,
    sort_criteria_t *criteria, int nb_criteria)
{
    node_t temp = {0};
    node_t *tail = &temp;

    while (left && right) {
        if (compare_nodes(left, right, criteria, nb_criteria) <= 0) {
            tail = attach_node(tail, left);
            left = left->next;
        } else {
            tail = attach_node(tail, right);
            right = right->next;
        }
    }
    attach_node(tail, left ? left : right);
    if (temp.next)
        temp.next->prev = NULL;
    return temp.next;
}

node_t *merge_sort_list(node_t *head,
    sort_criteria_t *criteria, int nb_criteria)
{
    node_t *middle;
    node_t *left;
    node_t *right;

    if (!head || !head->next)
        return head;
    middle = find_middle(head);
    left = merge_sort_list(head, criteria, nb_criteria);
    right = merge_sort_list(middle, criteria, nb_criteria);
    return merge_sorted_lists(left, right, criteria, nb_criteria);
}

int sort(void *data, char **args)
{
    global_t *main = (global_t *)data;
    int nb_criteria;
    sort_criteria_t criteria[10];

    if (!args || !args[0])
        return free_linked_list(main);
    nb_criteria = count_criteria(args);
    if (nb_criteria == 0 || nb_criteria > 3)
        return free_linked_list(main);
    if (parse_sort_criteria(args, criteria) != nb_criteria)
        return free_linked_list(main);
    main->head = merge_sort_list(main->head, criteria, nb_criteria);
    return EXIT_SUCC;
}
