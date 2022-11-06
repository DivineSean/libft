/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:02:16 by markik            #+#    #+#             */
/*   Updated: 2022/11/02 21:02:17 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*n;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		n = tmp -> next;
		ft_lstdelone(tmp, del);
		tmp = n;
	}
	*lst = 0;
}
