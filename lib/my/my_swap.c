/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Task01 CPool Day04
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
