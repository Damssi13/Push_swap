/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <damssi.art@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:09:08 by reddamss          #+#    #+#             */
/*   Updated: 2023/11/29 18:24:22 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ending(const char *str, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		i = 0;
		while (set[i])
		{
			if (set[i] == str[len])
				break ;
			i++;
		}
		if (!set[i])
			break ;
		len--;
	}
	return (len + 1);
}

static size_t	beginning(const char *str, const char *set)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (set[i])
		{
			if (str[j] == set[i])
				break ;
			i++;
		}
		if (!set[i])
			break ;
		j++;
	}
	return (j);
}

static int	check_empty(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (s1[j])
	{
		i = 0;
		while (set[i])
		{
			if (s1[j] == set[i])
				break ;
			i++;
		}
		if (!set[i])
			break ;
		j++;
	}
	if (!s1[j])
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	end;
	char	*result;
	char	*str;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	if (check_empty(s1, set))
		return (ft_strdup(""));
	str = (char *)s1;
	start = beginning(s1, set);
	while (start--)
		str++;
	end = ending(str, set);
	result = malloc(sizeof(char) * (end + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, str, end);
	result[end] = '\0';
	return (result);
}
