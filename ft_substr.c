/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:14:18 by markik            #+#    #+#             */
/*   Updated: 2022/11/03 03:37:21 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*d;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		d = (char *)malloc(sizeof(char));
		if (!d)
			return (0);
		d[0] = '\0';
		return (d);
	}
	n = ft_strlen(s) - start + 1;
	if (n > len)
		n = len + 1;
	d = (char *)malloc(sizeof(char) * n);
	if (!d)
		return (0);
	d = ft_strncpy(d, (char *)(s + start), n);
	return (d);
}
