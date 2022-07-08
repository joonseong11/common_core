/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:25:42 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 19:38:18 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nodeaddback(t_node **node, t_node *new)
{
	t_node	*last;

	if (node == NULL || new == NULL)
		get_error(OTHER);
	if (*node == NULL)
	{
		*node = new;
	}
	else
	{
		last = ft_nodelast(*node);
		last->next = new;
	}
}
