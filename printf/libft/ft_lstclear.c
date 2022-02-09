/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:09 by jujeon            #+#    #+#             */
/*   Updated: 2022/01/12 16:50:10 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_del;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		to_del = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(to_del, del);
	}
}
