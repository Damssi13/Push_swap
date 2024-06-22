/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reddamss <damssi.art@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:58:44 by reddamss          #+#    #+#             */
/*   Updated: 2023/11/28 11:23:28 by reddamss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;

	string = (char *)s;
	while (*string)
	{
		if ((char)c == *string)
			return (string);
		string++;
	}
	if ((char)c == '\0')
		return (string);
	return (0);
}
