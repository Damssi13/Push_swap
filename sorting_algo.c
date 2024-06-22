/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:38:06 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:33:58 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_size(*a);
	if (len <= 3)
		sort_three(a, b);
	else if (len <= 4)
		sort_four(a, b);
	else if (len <= 5)
		sort_five(a, b);
	else if (len > 5)
	{
		sort_algo(a, b);
		push_back(a, b);
	}
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	min = stack->next;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
