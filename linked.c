#include "push_swap.h"


stack    *new_node(int value)
{
    stack   *newnode;

    newnode = malloc(sizeof(stack));
    newnode->next = NULL;
    newnode->value = value;
    return(newnode);
}

void    stack_addback(stack *a, stack *newnode)
{
    while(a->next)
        a = a->next;
    a->next = newnode;
}


void    parse_args(int ac, char **av)
{
    int i;
    static char *all_args;
    i = 1;
    while(i < ac)
    {
        all_args = ft_strjoin(all_args ,av[i]);
        i++;
    }
    printf("%s", all_args);

}

// int main(int ac, char **av)
// {
//     stack *a = NULL;
//     int i;
//     int num;

//     i = 1;
//     a = new_node(1);
//     parse_args(ac,av);
//     while(i < ac)
//     {
//         num = ft_atoi(av[i]);
//         stack_addback(a, new_node(num));
//         i++;
//     }
//     while(a)
//     {
//         printf("%d\n", a->value);
//         a = a->next;
//     }
//     return 0;
// }

int main(int ac, char **av)
{
    parse_args(ac,av);
}