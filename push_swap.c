/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:38:20 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 20:38:24 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;
	int		*array;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	str = parsing_args(ac, av);
	array = fill_array(str);
	init_stack(&a, str, array);
	while (str[i])
		i++;
	sort_array(array, i);
	init_index(&a, array);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	clear_all(&a, str, array);
}
