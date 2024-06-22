/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <reddamss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:59:19 by reddamss          #+#    #+#             */
/*   Updated: 2024/06/09 14:32:37 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t	len;
	int		i;

	i = 0;
	if (!s1)
		return ((char *)s2);
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	p = (char *)malloc((sizeof(char) * len) + 2);
	if (!p)
		return (0);
	len = 0;
	while (s1[len])
	{
		p[len] = s1[len];
		len++;
	}
	p[len++] = ' ';
	while (s2[i])
		p[len++] = s2[i++];
	p[len] = '\0';
	return (p);
}
