#include "push_swap.h"

void    put_error(char *str)
{
    int i;

    i = 0;
    write(2,"Error:\n",7);
    while(str[i])
    {
        write(2,&str[i],1);
        i++;
    }
    return ;
}

int     divide_args(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i])
    {
        if(ft_isnotnum(str[i]))
            put_error("Arguments are not valid !");
        while(str[i++] == ' ')
        { 
            if(j > 0)
                j = -1;
        }
        while(str[i] >= '0' && str[i] <= '9')
        {
            i++;
            if (j == -1)
                break ;    
            j++;
        }
    }
    if(j == -1)
        return(1);
    return(0);
}

// void    push(int n, stack *a)
// {
//     stack *newnode = malloc(sizeof(stack));
//     if(!newnode)
//         return ;
//     newnode->value = n;
//     newnode->next = a;
//     a = newnode;
//     return ;
// }

stack   *new_node(int value)
{
    stack *newnode;

    newnode = malloc(sizeof(stack));
    newnode->value = value;
    newnode->next = NULL;
    return(newnode);
}

 void    add_node(stack *a, stack *node)
{
    while(a->next)
        a = a->next;

    a->next = node; 
    
}

int     main(int ac, char **av)
{
    // stack *a;
    int i;
    int j;
    char **strs;
    int res;
    int array[500];
    int index;

    index = 0;
    i = 1;
    j = 0;
    while(i <= ac)
    {
        if(divide_args(av[i])) //it checks whether the arg is a string or a single entity
        {
            strs = ft_split(av[i],' ');
            while(strs[j] != NULL)
            {   
                res = ft_atoi(strs[j++]);
                array[index++] = res;
            }
        }
        else
        {
            res = ft_atoi(av[i]);
            array[index++] = res;
        }
        i++;
    }
    check_double(array,index);

}

void    check_double(int *array, int index)
{
    int i;
    int j;

    i = 0;
    while(i != index)
    {
        j = 1;
        while(j != index)
        {
            if(array[i] == array[i + j])
                put_error("double arguments !");
            j++;
        }
        i++;
    }
}