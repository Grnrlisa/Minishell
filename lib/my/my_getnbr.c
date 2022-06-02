/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Return only the number in a string
*/

#include "my.h"

int my_getnbr_sweet(char const *str, int i, int brek)
{
    if (str[i + 1] < '0' || str[i + 1] > '9')
        brek = 1;
    return brek;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long nb = 0;
    int neg = 1;
    int brek = 0;

    for (; str[i] != '\0' && brek == 0; i++) {
        if (str[i] == '-')
            neg = neg * (-1);
        else if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + (str[i] - 48);
            brek = my_getnbr_sweet(str, i, brek);
        }
        nb = nb * neg;
        if (nb < -2147483648 || nb > 2147483647)
            return (84);
        nb = nb * neg;
    }
    return (nb * neg);
}
