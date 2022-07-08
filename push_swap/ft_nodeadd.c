/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:25:42 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/07 17:00:01 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeadd(t_node **lst, t_node *new)
{
	t_node	*last;

	if (lst == NULL || new == NULL)
		get_error(OTHER);
	if (*lst == NULL)
	{
		*lst = new;
	}
	else if ((*lst)->next == NULL)
	{
		last = *lst;
		last->next = new;
		new->back = NULL;
	}
	else
	{
		last = ft_nodelast(*lst);
		last->next = new;
		new->back = last;
	}
}
