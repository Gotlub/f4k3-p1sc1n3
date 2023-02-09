extern int g_lensquare;

void ft_free_tab(int **table, int **tab_parse)
{
    int i;

    i = - 1;
    while (++i < g_lensquare)
    {
        free(table[i]);
        free(tab_parse[i]);
    }
    free(table);
    free(tab_parse);
}