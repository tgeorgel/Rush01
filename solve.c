#include <stdlib.h>
#include <stdio.h>

void ft_print_tab(int **tab, int min, int max);

int ft_slv_row_left(int **grid, int i, int j, int val)
{
    int k;
    int max;
    int count;
    int actual;
    int prev;

    k = 2;
    max = 1;
    count = 1;
    while (k < 5)
    {
        actual = (k == j) ? val : grid[i][k];
        prev = ((k - 1) == j) ? val : grid[i][k - 1];

        if (actual > max && actual > prev)
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


int ft_slv_row_right(int **grid, int i, int j, int val)
{
    int k;
    int max;
    int count;
    int actual;
    int next;

    k = 3;
    max = 1;
    count = 1;
    while (k > 0)
    {
        actual = (k == j) ? val : grid[i][k];
        next = ((k + 1) == j) ? val : grid[i][k + 1];

        if (actual > max && actual > next)
        {
            max = actual;
            count++;
        }
        k--;
    }
    if (j == 1 && count != grid[i][5])
        return (0);
    return (1);
}


int ft_slv_col_up(int **grid, int k, int j, int val)
{
    int i;
    int max;
    int count;
    int actual;
    int prev;

    i = 2;
    max = 1;
    count = 1;
    while (i < 5)
    {
        actual = (i == k) ? val : grid[i][j];
        prev = ((i - 1) == k) ? val : grid[i - 1][j];

        if (actual > max && actual > prev)
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


int ft_slv_col_down(int **grid, int k, int j, int val)
{
    int i;
    int max;
    int count;
    int actual;
    int next;

    i = 3;
    max = 1;
    count = 1;
    while (i > 0)
    {
        actual = (i == k) ? val : grid[i][j];
        next = ((i + 1) == k) ? val : grid[i + 1][j];

        if (actual > max && actual > next)
        {
            max = actual;
            count++;
        }
        i--;
    }
    if (k == 1 && count != grid[5][j])
        return (0);
    return (1);
}


int ft_solve(int **grid, int i, int j)
{
    int val;

    val = 1;

    if (i == 5)
        return (1);
    if (j == 5)
        return (0);
    
    while (val <= 4)
    {
        if ((ft_slv_row_right(grid, i, j, val) == 1)
            && (ft_slv_row_left(grid, i, j, val) == 1)
            && (ft_slv_col_up(grid, i, j, val) == 1)
            && (ft_slv_col_down(grid, i, j, val) == 1))
        {
            grid[i][j] = val;

            if (j == 4 && ft_solve(grid, (i + 1), 1) == 1)
                return (1);
            else if (ft_solve(grid, i, (j + 1)) == 1)
                return (1);
        }
        val++;
    }

    grid[i][j] = 1;
    return (0);
}




/*
        if ((ft_slv_row_right(grid, i, j, val) == 1)
            && (ft_slv_row_left(grid, i, j, val) == 1)
            && (ft_slv_col_up(grid, i, j, val) == 1)
            && (ft_slv_col_down(grid, i, j, val) == 1))
        {
*/