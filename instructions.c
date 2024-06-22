/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:25:51 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:36:18 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		if (push(a, b))
			write(1, "pb\n", 3);
	}
	else
	{
		if (push(b, a))
			write(1, "pa\n", 3);
	}
}

void	ft_ss(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		if (swap(a))
			write(1, "sa\n", 3);
	}
	else
	{
		if (swap(b))
			write(1, "sb\n", 3);
	}
}

void	ft_rs(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		if (rotate(a))
			write(1, "ra\n", 3);
	}
	else if (rotate(b))
		write(1, "rb\n", 3);
}

void	ft_rrs(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		if (reverse_rotate(a))
			write(1, "rra\n", 4);
	}
	else if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}
