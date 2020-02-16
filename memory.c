#include <stdlib.h>

int     **ft_malloc_tab(int size)
{
    int     **tab;
    int     i;

    i = 0;

    tab = (int **) malloc(sizeof(int *) * size);

    while (i < size)
    {
        tab[i] = (int *) malloc(sizeof(int) * size);
        i++;
    }
    return (tab);
}

char    *ft_malloc_str(int size)
{
    char    *str;

    str = (char *) malloc(sizeof(char) * size);
    return (str);
}

void    ft_free_tab(int **tab, int size)
{
    int    i;

    i = 0;    
    while (i < size)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}