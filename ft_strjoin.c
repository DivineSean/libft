/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:47:19 by markik            #+#    #+#             */
/*   Updated: 2022/11/03 03:30:27 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *str, char *dest, char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[j])
	{
		str[i] = dest [i];
		i++;
		j++;
	}
	j = 0;
	while (src[j])
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (0);
	len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	str = (char *)malloc(sizeof (char) * len);
	if (!str)
		return (0);
	ft_strcat(str, (char *)s1, (char *)s2);
	return (str);
}
