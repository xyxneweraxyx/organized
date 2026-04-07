/*
** EPITECH PROJECT, 2025
** str_to_int
** File description:
** Function to convert strings to int
*/

int str_to_int(char *str)
{
    int total = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        total = total * 10 + (str[i] - '0');
    }
    return total;
}
