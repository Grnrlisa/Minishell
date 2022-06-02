/*
** EPITECH PROJECT, 2021
** putunsigned
** File description:
** put unsigned
*/

void my_putchar(char c);

unsigned int my_unsigned(unsigned int nb)
{
    if (nb < 10)
        my_putchar(nb + '0');
    else {
        my_unsigned(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return (0);
}
