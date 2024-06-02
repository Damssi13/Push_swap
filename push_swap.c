#include "push_swap.h"

stack    *add_node(stack *a, int value);

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

stack    *add_node(stack *a, int value)
{
    while(a->next)
        a = a->next;
        
    node->next = NULL;
    node->value = value; 
    a->next = node;
}

int     main(int ac, char **av)
{
    stack *a;
    int i;
    int j;
    char **strs;
    int res;

    i = 1;
    j = 0;
    while(i <= ac)
    {
        if(divide_args(av[i]))
        {
            strs = ft_split(av[i],' ');
            while(strs[j] != NULL)
            {   
                res = ft_atoi(strs[j]);
                add_node(a, res);
                j++;
            }
        }
        else
        {
            res = ft_atoi(av[i]);
            add_node(a, new_node(res));
        }
        
        i++;
    }

}
