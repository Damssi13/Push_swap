#include "push_swap.h"

void    space_check(char *str, char *to_be_free, t_stack *a)
{
    // (void)a;
    while(*str)
    {
        if(*str == ' ' || *str == '\t')
            str++;
        else
            return ;
    }
    if(*to_be_free != '\0')
    {
        free(to_be_free);
    }
    free(a);
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
// void    destroy_array(int *array)
// {
//     free(array);
// }

void    check_unit(char *str, char **res, t_stack *a)
{
    if(*str == '-' || *str == '+')
        str++;
    if(*str == '\0')
    {
        destroy_res(res);
        free(a->array);
        free(a);
        ft_putstr_fd("Error unit", 2);
    }
    while(*str)
    {
        if(*str >= '0' && *str <= '9')
            str++;
        else
        {
            destroy_res(res);
            free(a->array);
            free(a);
            ft_putstr_fd("Error unit", 2);
        }
    }
}

void     fill_array(char **res, t_stack *a)
{
    int i;
    int length;

    length = 0;
    while(res[length])
        length++;
    a->len = length;
    a->array = malloc(sizeof(int ) * length);
    if(!a->array)
        return ;
    i = 0;
    while(res[i])
    {
        check_unit(res[i], res, a);
        a->array[i] = ft_atoi(res[i], a, res);
        i++;
    }
    i = 0;
    destroy_res(res);
    return ;
}

void    double_num_check(t_stack *a)
{
    int i;
    int j;

    i = 0;
    while(i < a->len - 1)
    {
        j = 1;
        while(j < a->len - i)
        {
            if(a->array[i] == a->array[i + j])
            {
                free(a->array);
                free(a);
                ft_putstr_fd("Error double", 2);
            }
            j++;
        }
        i++;
    }
    return ;
}

void     parsing_args(int ac, char **av, t_stack *a)
{
    int     i;
    char *str;
    char **res;
    char *tmp;

    space_check(av[1],"", a);
    str = ft_strdup(av[1]);
    i = 2;
    while(i < ac)
    {
        space_check(av[i], str, a);
        tmp = ft_strjoin(str, av[i++]);
        free(str);
        str = tmp;
    }
    res = ft_split(str,' ');
    free(str);
    fill_array(res, a);
    double_num_check(a);
    return ;
}


int     main(int ac, char **av)
{
    t_stack *a;

    if(ac == 1)
        return 0;
    a = malloc(sizeof(t_stack));
    // here where the things start
    parsing_args(ac,av, a);
    int j = 0; 
    while(j </*should be the size of the array*/ 5)
    {
        printf("%d\n", a->array[j]);
        j++;
    }
    free(a->array);
    free(a);
}