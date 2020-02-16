#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

int     ft_puterr(char *str)
{
    ft_putstr(str);
    return (1);
}

void    ft_putnbr(int i)
{
    if (i < 0)
    {
        ft_putchar('-');
        i *= -1;
    }
    if (i == 8)
        ft_putchar('.');
    else
        ft_putchar(i + '0');
}

void    ft_print_tab(int **tab, int min, int max)
{
    int i;
    int j;

    i = min;
    while (i < max)
    {
        j = min;
        while (j < max)
        {
            ft_putnbr(tab[i][j]);
            j++;
            if (j == max)
                ft_putchar('\n');
            else
                ft_putchar(' ');
        }
        i++;
    }
}