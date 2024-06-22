/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:39:01 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:35:19 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_res(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	clear_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	clear_all(t_stack **a, char **str, int *array)
{
	destroy_res(str);
	free(array);
	clear_stack(*a);
}
