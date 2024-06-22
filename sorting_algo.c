#include "push_swap.h"

int     stack_sorted(t_stack *stack)
{
    while(stack != NULL && stack->next != NULL)
    {
        if(stack->content > stack->next->content)
            return 0;
        stack = stack->next;
    }
    return 1;
}

t_stack     *get_max(t_stack *stack)
{
    t_stack *tmp;
    t_stack *max;

    max = stack->next;
    tmp = stack;
    while(tmp)
    {
        if(tmp->content > max->content)
            max = tmp;
        tmp = tmp->next;
    }
    return max;
}

t_stack     *get_min(t_stack *stack)
{
    t_stack *tmp;
    t_stack *min;

    min = stack->next;
    tmp = stack;
    while(tmp)
    {
        if(tmp->content < min->content)
            min = tmp;
        tmp = tmp->next;
    }
    return min;
}