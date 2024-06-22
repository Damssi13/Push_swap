#include "push_swap.h"

 void	init_index(t_stack **stack, int *array)
{
	int		len;
	t_stack	*stack_a;
	int		i;

	len = stack_size(*stack);
	i = 0;
	stack_a = *stack;
	while (i < len)
	{
		stack_a->index = get_index(stack_a->content, array, len);
		stack_a = stack_a->next;
		i++;
	}
}
int     get_index(int content, int *array, int len)
{
    int i;

    i = 0;
    while(i < len)
    {
        if(content == array[i])
            return i;
        i++;
    }
    return i;
}

int     stack_size(t_stack *stack)
{
    int size;

    size = 0;
    if(!stack)
        return -1;
    while(stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int	    in_index(t_stack *a, int len, int range)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index <= len + range)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int     init_range(int  size)
{
    if(size <= 10)
        return 5;
    if(size <= 100)
        return 15;
    else
        return 30;
}

int     find_index(t_stack *stack, t_stack *toFind)
{
    int i;

    i = 0;
    while(stack)
    {
        if(stack == toFind)
            return i;
        stack = stack->next;
        i++;
    }
    return i;
}