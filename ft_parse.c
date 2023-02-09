#include "ft_simulator.c"

extern int g_lensquare;

void ft_print_tab(int **table)
{
    int i;
    int j;

    i = - 1;
    while (++i < g_lensquare)
    {
        j = - 1;
        while (++j < g_lensquare)
        {
            printf("%d",table[i][j]);
            if (j != g_lensquare - 1)
                printf(" ");
        }
    printf("\n"); 
    }   
}

void ft_maxmin(int all_side, int *perimeter, int **tab_parse, int x)
{
    int i;
    int j;

    i = x / (all_side / 4);
    j = x % (all_side / 4);
    if ((tab_parse[i][j] > (all_side / 4) - perimeter[j] + i + 1) && (perimeter [j] > i))
        tab_parse[i][j] = (all_side / 4) - perimeter[j] + i + 1;
    if ((tab_parse[i][j] > (all_side / 4) * 2 - perimeter[j + (all_side / 4)] - i)
        && ((all_side / 4) - i <= perimeter[j + (all_side /4)]))
        tab_parse[i][j] = (all_side / 4) * 2 - perimeter[j + (all_side / 4)] - i;
    if ((tab_parse[i][j] > (all_side / 4) + 1 - perimeter[(all_side / 2) + i] + j)
        && (j < perimeter[all_side / 2 + i]))
        tab_parse[i][j] = (all_side / 4) + 1 - perimeter[all_side / 2 + i] + j;
    if ((tab_parse[i][j] > (all_side / 4) * 2 - perimeter[(all_side / 4 * 3) + i] - j)
        && ((all_side / 4) - j <= perimeter[(all_side / 4) * 3 + i]))
        tab_parse[i][j] = (all_side / 4) * 2 - perimeter[(all_side / 4 * 3) + i] - j;
}

int ft_dfs(int **table, int **tab_parse, int *perimeter, int i)
{
    int y;
    int x;
    int j;
    int commut;

    y = i / g_lensquare;
    x = i % g_lensquare;
    j = 0;
    commut = 0;
    while ((commut == 0) && (++j <= tab_parse[y][x]))
    {
        table[y][x] = j;
        if (ft_simulator(table, perimeter, y, x))
        {
            if (i == (g_lensquare * g_lensquare) - 1)
                {
                    ft_print_tab(table);
                    return  (1);
                }
            commut = ft_dfs(table, tab_parse, perimeter, i + 1);
        }
    }
    if (commut ==0)
        table[y][x] = 0;
    return (commut);
}

int ft_parse(int all_side, int *perimeter, int **table, int **tab_parse)
{
    int i;
    int j;

    i = - 1;
    while (++i < (all_side / 4))
    {
        j = - 1;
        while (++j < (all_side / 4))
        {
            if ((perimeter[j] + perimeter[j + (all_side / 4)] > (all_side / 4) + 1)
                || (perimeter[(all_side / 2) + i] + perimeter[(all_side / 4 * 3) + i] > (all_side / 4) + 1))
                {
                    printf("Error\n");
                    return (0);
                }
            ft_maxmin(all_side, perimeter, tab_parse, (i * (all_side / 4) + j));
        }
    }
    if (ft_dfs(table, tab_parse, perimeter, 0) == 0)
    {
        printf("coucou_error\n");
    }
    else
        printf("Joupi");
    return (0);
}