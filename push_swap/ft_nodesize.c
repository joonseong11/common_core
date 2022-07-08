/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:10:12 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 14:01:50 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nodesize(t_node *node)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = node;
	while (curr != NULL)
	{
		curr = curr->next;
		++count;
	}
	return (count);
}
