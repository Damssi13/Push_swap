/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:34:22 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/22 21:36:06 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing_args(int ac, char **av)
{
	int		i;
	char	*str;
	char	**res;
	char	*tmp;

	space_check(av[1], "");
	str = ft_strdup(av[1]);
	i = 2;
	while (i < ac)
	{
		space_check(av[i], str);
		tmp = ft_strjoin(str, av[i++]);
		free(str);
		str = tmp;
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

int	*fill_array(char **res)
{
	int	i;
	int	length;
	int	*array;

	length = 0;
	while (res[length])
		length++;
	array = malloc(sizeof(int) * length);
	if (!array)
		return (0);
	i = 0;
	while (res[i])
	{
		check_unit(res[i], res, array);
		array[i] = ft_atoi(res[i], array, res);
		i++;
	}
	i = 0;
	double_num_check(array, length, res);
	return (array);
}

void	double_num_check(int *array, int size, char **res)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (array[i] == array[i + j])
			{
				free(array);
				destroy_res(res);
				ft_putstr_fd("Error double", 2);
			}
			j++;
		}
		i++;
	}
	return ;
}

void	check_unit(char *str, char **res, int *array)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
	{
		destroy_res(res);
		free(array);
		ft_putstr_fd("Error unit", 2);
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
		{
			destroy_res(res);
			free(array);
			ft_putstr_fd("Error unit", 2);
		}
	}
}

void	space_check(char *str, char *to_be_free)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			str++;
		else
			return ;
	}
	if (*to_be_free != '\0')
		free(to_be_free);
	ft_putstr_fd("Error space", 2);
}
