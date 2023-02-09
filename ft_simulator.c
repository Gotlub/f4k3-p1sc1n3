#include "ft_hori.c"

extern int g_lensquare;

int ft_seek_double(int **table,int y, int x)
{
    int i;
    int j;

    i = -1;
    while (++i < g_lensquare - 1)
    {
        j = i ;
        while (++j < g_lensquare)
        {
            if ((table[y][i] != 0) && (table[y][i] == table[y][j]))
                return (0);
            if ((table[i][x] != 0) && (table[i][x] == table[j][x]))
                return (0);
        }
    }
    return (1);
}

int ft_verti_2(int **table, int *perimeter, int x)
{
    int       i;
    int    temp;
    int    look;

    i = g_lensquare - 1;
    temp = 0;
    look = 0;
    while ((g_lensquare - i) <= g_lensquare) 
    {
        if (table[i][x] > temp)
        {
            temp = table[i][x];
            look++;
        }
        i--;
    }
    if (perimeter[x + g_lensquare] == look)
        return (1);
    return (0);
}

int ft_verti(int **table, int *perimeter,int y, int x)
{
    int       i;
    int    temp;
    int    look;

    i = - 1;
    temp = 0;
    look = 0;
    while (++i < g_lensquare) 
    {
        if ((table[i][x] != 0) && (table[i][x] > temp))
        {
            temp = table[i][x];
            look++;
        }
    }
    if ((y < g_lensquare - 1) && look <= perimeter[x])
        return (1);
    if ((y == g_lensquare - 1) && (look == perimeter[x]) && (ft_verti_2(table, perimeter, x) != 0))
            return (1);
    return (0);
}

int ft_simulator(int **table, int *perimeter, int y, int x)
{
    if (ft_seek_double(table, y, x) == 0)
        return  (0);
    if (ft_verti(table, perimeter, y, x) == 0)
        return (0);
    if (ft_hori(table, perimeter, y, x) == 0)
        return (0);
    return (1);
}