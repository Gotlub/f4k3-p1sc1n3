#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_parse.c"
#include "ft_free.c"

int g_lensquare = 9; 

int ft_no_yes(int commut, int count)
{
    if ((count % 4 == 0) && (commut == 0))
    {
        return (count);
    }
    else
        return (0);
}

int ft_len_side(char *argv[])
{
    int i;
    int count;
    int commut;

    i = 0;
    count = 0;
    commut = 1;
    while (argv[1][i] != 0)
        {
            if ((argv[1][i] >= '0') && (argv[1][i] <= '9'))
            {
                if (commut == 1)
                    count++;
                commut = 0;
            }
            else
            {
                if ((argv[1][i] == 32  && commut == 1) || argv[1][i] != 32)
                    return (0);
                if (argv[1][i] == 32)
                    commut = 1;
            }
            i ++;
        }
    return (ft_no_yes(commut,count));
}

int    ft_atoi_tower(char *argv[], int count, int *perimeter)
{
    int i;
    int j;
    int temp;

    i = j = temp = 0;
    while (argv[1][i] != 0)
    {
        if (argv[1][i] != 32)
            temp = temp * 10 + (argv[1][i] - '0');
        if ((argv[1][i] == 32 && (temp <= count / 4)) || argv[1][i + 1] == 0)
        {
            perimeter[j] = temp;
            temp = 0;
            j++;
        }
        if (temp > count / 4)
            return (0);
        i++;
    }
    return (1);
}

void ft_game_launch(int all_side, int *perimeter)
{
    int i;
    int j;
    int **table = (int**)malloc((all_side / 4) * sizeof(int*));
    int **tab_parse = (int**)malloc((all_side / 4) * sizeof(int*));

    i = - 1;
    while (++i < (all_side / 4))
    {
        table[i] = (int*)malloc((all_side / 4) * sizeof(int));
        tab_parse[i] = (int*)malloc((all_side / 4) * sizeof(int));
        j = - 1;
        while (++j < (all_side / 4))
        {
            table[i][j] = 0;
            tab_parse[i][j] = all_side / 4;
        }
    }
    ft_parse(all_side, perimeter, table, tab_parse);
    ft_free_tab(table, tab_parse);
}

int main(int argc , char *argv[])
{
    int all_side;
    int *perimeter = NULL;

    if (argc != 2)
     {
        printf("Error\n");
        return (0);
     }
    all_side = ft_len_side(argv);
    perimeter = malloc(all_side * sizeof(int));
    if (perimeter == NULL || all_side == 0)
    {
        printf("Error\n");
        return (0);
    }    
    if (ft_atoi_tower(argv, all_side, perimeter) != 1)
    {
        printf("Error\n");
        return (0);
    }
    g_lensquare = (all_side / 4);
    ft_game_launch(all_side, perimeter);
    free(perimeter);
    return (0);
}