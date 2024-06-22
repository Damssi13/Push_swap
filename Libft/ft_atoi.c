/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:41:49 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 19:31:01 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str, int *array, char **res)
{
	long long	number;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += str[i++] - 48;
	}
	if ((number * sign) > 2147483647 || (number * sign) < -2147483648)
	{
		free(array);
		destroy_res(res);
		ft_putstr_fd("Error max int", 2);
	}
	return (number * sign);
}
