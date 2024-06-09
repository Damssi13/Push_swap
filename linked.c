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