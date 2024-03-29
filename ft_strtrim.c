/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:59:24 by markik            #+#    #+#             */
/*   Updated: 2022/10/28 08:19:58 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_check(char const *set, char s1)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_len1(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_check(set, s1[i]) == 1)
		i++;
	return (i);
}

static int	ft_len2(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_check(set, s1[i]) == 1)
			i--;
	return (i);
}

static void	ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (0);
	i = ft_len1(s1, set);
	j = ft_len2(s1, set);
	if (i == ft_strlen(s1) || j == 0)
	{
		str = (char *)malloc (sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else
		len = j - i + 1;
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strncpy(str, s1 + i, len + 1);
	return (str);
}
