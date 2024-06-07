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
    ft_putstr_fd("Error", 2);
}

void    check_unit(char *str)
{
    if(*str == '-' || *str == '+')
        str++;
    while(*str)
    {
        if(*str >= '0' && *str <= '9')
            str++;
        else
            ft_putstr_fd("Error", 2);
    }
}

int main(int ac, char **av)
{
    int i;
    char *str;
    int *array;
    char **res;

    i = 1;
    str = NULL;
    while(i < ac)
    {
        space_check(av[i]);
        str = ft_strjoin(str, av[i++]);
    }
    res = ft_split(str,' ');
    i = 0;
    while(res[i])
        i++;
    array = malloc(sizeof(int) * i);
    if(!array)
        return NULL;
    i = 0;
    while(res[i])
    {
        check_unit(res[i]);
        array[i] = ft_atoi(res[i++]);
    }
    return(array);
}
