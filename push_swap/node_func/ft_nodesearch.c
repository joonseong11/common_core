/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:36:59 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 23:04:04 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodesearch(t_head *top, int size)
{
	int		i;
	t_node	*curr;

	i = 1;
	if (top == NULL || size < 0)
		return (NULL);
	curr = top->next;
	while (i < size)
	{
		curr = curr->next;
		++i;
	}
	return (curr);
}
