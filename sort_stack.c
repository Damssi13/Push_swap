#include "push_swap.h"

void    sort_stack(t_stack **a, t_stack **b)
{
    int len;

    len = stack_size(*a);
    
    if(len <= 3)
        sort_three(a, b);
    else if(len <= 4)
        sort_four(a, b);
    else if(len <= 5)
        sort_five(a, b);
    else if(len > 5)
       sort_algo(a, b);
}

void    sort_three(t_stack **a, t_stack **b)
{
    t_stack *last;
    t_stack *max;

    last = last_node(*a);
    max = get_max(*a);
    while(last->content != max->content)
    {
        ft_rs(a, b, 'a');
        last = last_node(*a);
    }
    if((*a)->content > (*a)->next->content)
        ft_ss(a, b, 'a');
}

void    sort_four(t_stack **a, t_stack **b)
{
    t_stack *min;
    int     mid;

    mid = stack_size(*a) / 2;
    min = get_min(*a);
    while(stack_size(*a) > 2)
    {
        if((*a)->content == min->content)
            ft_ps(a, b, 'a');
        else if(find_index(*a, min) <= mid)
            ft_rs(a, b, 'a');
        else
            ft_rrs(a, b, 'a');
        min = get_min(*a);
    }
    if((*a)->content > (*a)->next->content)
        ft_ss(a, b, 'a');
    ft_ps(a, b, 'b');
    ft_ps(a, b, 'b');
}

void    sort_five(t_stack **a, t_stack **b)
{
    int len;
    int minIndex;
    t_stack *min;

    len = stack_size(*a);
    min = get_min(*a);
    minIndex = find_index(*a, min);
    while(len > 3)
    {
        if(minIndex == 0)
            ft_ps(a, b, 'a');
        else if(minIndex <= len / 2)
            ft_rs(a, b, 'a');
        else if(minIndex > len / 2)
            ft_rrs(a, b, 'a');
        len = stack_size(*a);
        min = get_min(*a);
        minIndex = find_index(*a, min);
   }
   sort_three(a, b);
   ft_ps(a, b, 'b');
   ft_ps(a, b, 'b');
}

void     sort_algo(t_stack **a, t_stack **b)
{
    int i = 0;
    int stack_len;
    int range;

    stack_len = stack_size(*a);
    range = init_range(stack_len);
    while(*a)
    {
        if((*a)->index <= i)
        {
            ft_ps(a, b, 'a');
            ft_rs(a, b, 'b');
            i++;
        }
        else if((*a)->index <= i + range)
        {
            ft_ps(a, b, 'a');
            i++;
        }
        else if(in_index(*a, i, range) <= stack_size(*a) / 2)
            ft_rs(a, b, 'a');
        else
            ft_rrs(a, b, 'a');
    }
    push_back(a, b);
}

void	push_back(t_stack **a, t_stack **b)
{
	t_stack	*max;

	max = get_max(*b);
	while (*b)
	{
		if ((*b)->content == max->content)
		{
			ft_ps(a, b, 'b');
			max = get_max(*b);
		}
		else if (find_index(*b, max) <= stack_size(*b) / 2)
			ft_rs(a, b, 'b');
		else
			ft_rrs(a, b, 'b');
	}
}


