/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:39:08 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:32:00 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack **stack, int *array)
{
	int		len;
	t_stack	*a;
	int		i;

	len = stack_size(*stack);
	i = 0;
	a = *stack;
	while (i < len)
	{
		a->index = get_index(a->content, array, len);
		a = a->next;
		i++;
	}
}

int	get_index(int content, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (content == array[i])
			return (i);
		i++;
	}
	return (i);
}

int	in_index(t_stack *a, int len, int range)
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

int	init_range(int size)
{
	if (size <= 10)
		return (5);
	if (size <= 100)
		return (15);
	else
		return (30);
}

int	find_index(t_stack *stack, t_stack *toFind)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == toFind)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
