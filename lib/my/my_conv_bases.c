/*
** EPITECH PROJECT, 2021
** baseconv
** File description:
** conv to a base
*/

#include <stdarg.h>
#include "my.h"

int my_conv_bases(int nb, char *conv)
{
    int baselen = my_strlen(conv);
    int i = nb % baselen;

    nb = nb / baselen;
    if (nb > 0)
        my_conv_bases(nb, conv);
    my_putchar(conv[i]);
    return (0);
}
