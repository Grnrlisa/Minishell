/*
** EPITECH PROJECT, 2021
** my_computer_power_rec
** File description:
** task04 CPool Day05
*/

#include "my.h"

int my_compute_power_rec (int nb, int p)
{
    if (p == 0)
        return (1);
    return  (nb * my_compute_power_rec(nb, p-1));
}
