/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:48:44 by markik            #+#    #+#             */
/*   Updated: 2022/10/28 09:07:13 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_power(long n)
{
	int	power;

	power = 0;
	if (n <= 0)
	{
		n = -n;
		power++;
	}
	while (n > 0)
	{
		n = n / 10;
		power++;
	}
	return (power);
}

char	*ft_itoa(int n)
{
	int		power;
	char	*str;
	long	nb;

	nb = n;
	power = ft_power(nb);
	str = (char *)malloc(sizeof (char) * (power + 1));
	if (!str)
		return (0);
	str[power] = '\0';
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[power - 1] = nb % 10 + 48;
		nb = nb / 10;
		power--;
	}
	return (str);
}
