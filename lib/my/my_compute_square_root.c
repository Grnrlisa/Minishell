/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** task05 CPool Day05
*/

#include "my.h"

int my_compute_square_root (int nb)
{
    int nb2 = 0;
    if (nb == 0) {
        return (1);
    }
    if (nb < 0) {
        return (0);
    }
    while (nb2 * nb2 != nb) {
        nb2++;
    }
}
