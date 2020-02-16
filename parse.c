#include <stdlib.h>

char    *ft_malloc_str(int size);

int     **ft_fill_empty(int **tab, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (i == size - 1 || j == size - 1 || j == 0 || i == 0)
                tab[i][j] = 8;
            else
                tab[i][j] = 1;
            j++;
        }
        i++;
    }
    return (tab);
}

char    *ft_trim_input(char *arg)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    str = ft_malloc_str(4 * 4 + 1);
    while (arg[i] != '\0')
    {
        if (arg[i] >= '0' && arg[i] <= '9')
        {
            str[j] = arg[i];
            j++;
        }
        i++;
    }
    return (str);
}

int     ft_valid_input(char *arg)
{
    int     i;

    i = 0;
    while (arg[i] != '\0')
    {
        if (arg[i] != ' ' && arg[i] > '9' && arg[i] < '0')
            return (0);
        i++;
    }
    if (i != 31)
        return (0);
    return (1);
}

int     **ft_fill_argv(int **tab, char *arg)
{
    int     j;

    j = 0;
    while (j < 4)
    {
        tab[0][(j % 4) + 1] = arg[j] - '0';
        tab[5][(j % 4) + 1] = arg[j + 4] - '0';
        j++;
    }
    j += 4;
    while (j < 12)
    {
        tab[(j % 4) + 1][0] = arg[j] - '0';
        tab[(j % 4) + 1][5] = arg[j + 4] - '0';
        j++;
    }
    free(arg);
    return (tab);
}