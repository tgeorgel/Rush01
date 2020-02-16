int     **ft_malloc_tab(int size);
char    *ft_malloc_str(int size);
void    ft_free_tab(int **tab, int size);
int     ft_valid_input(char *arg);
char    *ft_trim_input(char *arg);
int     **ft_fill_empty(int **tab, int size);
int     **ft_fill_argv(int **tab, char *argv, int size);
void    ft_putstr(char *str);
int     ft_puterr(char *str);
void    ft_putnbr(int i);
void    ft_print_tab(int **tab, int min, int max);
int     ft_solve(int **grid, int i, int j);

int     main(int argc, char **argv)
{
    int     **grid;

    if (argc != 2 || ft_valid_input(argv[1]) != 1) 
        return ft_puterr("Error\n\0");

    grid = ft_malloc_tab(6);

    ft_fill_empty(grid, 6);
    ft_fill_argv(grid, ft_trim_input(argv[1]), 6);
    
    if (ft_solve(grid, 1, 1) == 0)
        return ft_puterr("Error\n\0");

    ft_putstr("Full grid : \n");
    ft_print_tab(grid, 0, 6);

    ft_putstr("\nSolution only : \n");
    ft_print_tab(grid, 1, 5);

    ft_free_tab(grid, 6);
    return (0);
}