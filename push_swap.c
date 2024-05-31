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

int     main(int ac, char **av)
{
    // (void)stack *a = NULL;
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
                j++;
            }
        }
        i++;
    }

}