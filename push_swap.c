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

int     *parsing_args(int ac, char **av, int i)
{
    char *str;
    int *array;
    char **res;

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


// stack   *new_node(int value)
// {
//     stack *newnode;

//     newnode = malloc(sizeof(stack));
//     newnode->value = value;
//     newnode->next = NULL;
//     return(newnode);
// }

//  void    add_node(stack *a, stack *node)
// {
//     while(a->next)
//         a = a->next;

//     a->next = node; 
    
// }

int     main(int ac, char **av)
{
    int i;
    int *array;

    i = 1;
    array = parsing_arguments(ac,av,i);

}

// void    check_double(int *array, int index)
// {
//     int i;
//     int j;

//     i = 0;
//     while(i != index)
//     {
//         j = 1;
//         while(j != index)
//         {
//             if(array[i] == array[i + j])
//                 put_error("double arguments !");
//             j++;
//         }
//         i++;
//     }
// }