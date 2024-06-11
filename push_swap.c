#include "push_swap.h"

void    space_check(char *str, char *to_be_free)
{
    while(*str)
    {
        if(*str == ' ' || *str == '\t')
            str++;
        else
            return ;
    }
    if(*to_be_free != '\0')
        free(to_be_free);
    ft_putstr_fd("Error space", 2);
}
void    destroy_res(char **res)
{
    int i;

    i = 0;
    while(res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}
void    destroy_array(int *array)
{
    free(array);
}

void    check_unit(char *str, char **res, int *array)
{
    if(*str == '-' || *str == '+')
        str++;
    if(*str == '\0')
    {
        destroy_res(res);
        destroy_array(array);
        ft_putstr_fd("Error unit", 2);
    }
    while(*str)
    {
        if(*str >= '0' && *str <= '9')
            str++;
        else
        {
            destroy_res(res);
            destroy_array(array);
            ft_putstr_fd("Error unit", 2);
        }
    }
}

int     *fill_array(char **res)
{
    int i;
    int *array;
    int len;

    len = 0;
    while(res[len])
        len++;
    array = malloc(sizeof(int ) * len);
    if(!array)
        return NULL;
    i = 0;
    while(res[i])
    {
        check_unit(res[i], res, array);
        array[i] = ft_atoi(res[i]);
        i++;
    }
    i = 0;
    destroy_res(res);
    return(array);
}

int     *parsing_args(int ac, char **av)
{
    int     i;
    char *str;
    int *array;
    char **res;
    char *tmp;

    space_check(av[1],"");
    str = ft_strdup(av[1]);
    i = 2;
    while(i < ac)
    {
        space_check(av[i],str);
        tmp = ft_strjoin(str, av[i++]);
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
    while(j </*should be the size of the array*/ 5)
    {
        printf("%d\n", array[j]);
        j++;
    }
    free(array);
}