#include "push_swap.h"

void    space_check(char *str)
{
    while(*str)
    {
        if(*str == ' ' || *str == '\t')
            str++;
        else
            return ;
    }
    ft_putstr_fd("Error space", 2);
}

void    check_unit(char *str)
{
    if(*str == '-' || *str == '+')
        str++;
    if(*str == '\0')
        ft_putstr_fd("Error unit", 2);
    while(*str)
    {
        if(*str >= '0' && *str <= '9')
            str++;
        else
            ft_putstr_fd("Error unit", 2);
    }
}
int     *fill_array(char **res)
{
    int i;
    int *array;

    i = 0;
    while(res[i])
        i++;
    array = (int *)malloc(sizeof(int) * i);
    if(!array)
        return NULL;
    ft_bzero(array,i);
    i = 0;
    while(res[i])
    {
        check_unit(res[i]);
        array[i] = ft_atoi(res[i]);
        i++;
    }
    i = 0;
    while(res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
    return(array);
}

int     *parsing_args(int ac, char **av)
{
    int     i;
    char *str;
    int *array;
    char **res;
    char *tmp;


    i = 1;
    str = NULL;
    i = 1;
    while(i < ac)
    {
        space_check(av[i]);
        tmp = ft_strjoin(str, av[i++]);
        if(str != NULL)
            free(str);
        str = tmp;
    }
    res = ft_split(str,' ');
    free(str);
    array = fill_array(res);
    return(array);
}


int     main(int ac, char **av)
{
    int *array;

    array = parsing_args(ac,av);

    int j = 0; 
    while(array[j])
    {
        printf("%d\n", array[j]);
        j++;
    }
    free(array);
}