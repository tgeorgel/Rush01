#include <stdlib.h>

void ft_print_tab(int **tab, int min, int max);

int ft_fit_row_left(int **grid, int i, int j, int val)
{
    int k;
    int max;
    int count;
    int actual;

    k = 1;
    max = 0;
    count = 0;
    while (k <= 4)
    {
        actual = (k == j) ? val : grid[i][k];

        if (actual > max)
        {
            max = actual;
            count++;
        }
        k++;
    }
    if (j == 4 && count != grid[i][0])
        return (0);
    return (1);
}


int ft_fit_row_right(int **grid, int i, int j, int val)
{
    int k;
    int max;
    int count;
    int actual;

    k = 4;
    max = 0;
    count = 0;
    while (k >= 1)
    {
        actual = (k == j) ? val : grid[i][k];

        if (actual > max)
        {
            max = actual;
            count++;
        }
        k--;
    }
    if (j == 4 && count != grid[i][5])
        return (0);
    return (1);
}

int ft_fit_col_up(int **grid, int k, int j, int val)
{
    int i;
    int max;
    int count;
    int actual;

    i = 1;
    max = 0;
    count = 0;
    while (i <= 4)
    {
        actual = (i == k) ? val : grid[i][j];

        if (actual > max)
        {
            max = actual;
            count++;
        }
        i++;
    }
    if (k == 4 && count != grid[0][j])
        return (0);
    return (1);
}

int ft_fit_col_down(int **grid, int k, int j, int val)
{
    int i;
    int max;
    int count;
    int actual;

    i = 4;
    max = 0;
    count = 0;
    while (i >= 1)
    {
        actual = (i == k) ? val : grid[i][j];

        if (actual > max)
        {
            max = actual;
            count++;
        }
        i--;
    }

    if (k == 4 && count != grid[5][j])
        return (0);
    return (1);
}


int ft_solve(int **grid, int i, int j)
{
    int val;

    val = 1;
    if (i == 5)
        return (1);

    while (val <= 4)
    {
        if ((ft_fit_row_right(grid, i, j, val) == 1)
            && (ft_fit_row_left(grid, i, j, val) == 1)
            && (ft_fit_col_up(grid, i, j, val) == 1)
            && (ft_fit_col_down(grid, i, j, val) == 1))
        {
            grid[i][j] = val;

            if (j == 4 && ft_solve(grid, (i + 1), 1) == 1)
                return (1);
            if (j != 4 && ft_solve(grid, i, (j + 1)) == 1)
                return (1);
        }
        val++;
    }
    grid[i][j] = 1;
    return (0);
}