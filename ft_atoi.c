/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:37:32 by markik            #+#    #+#             */
/*   Updated: 2022/10/27 09:20:26 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isspace3(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && (str[i] <= 13 || str[i] == 32))
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		signe;
	int		i;

	i = isspace3(str);
	res = 0;
	signe = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * signe);
}
