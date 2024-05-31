#include "push_swap.h"


void    add_node(stack *a, int value)
{
    stack *node = malloc(sizeof(node));

    a->next = node;
    node->value = value;
    

}

// int main()
// {
//     stack *a;

//     add_node(a,7)
        
// }