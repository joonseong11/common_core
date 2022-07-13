/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/13 20:32:11 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_info *info)
{
	int		sorted;
	t_node	*node;

	sorted = 1;
	node = info->stacka_top->next;
	while (node)
	{
		if (node->next)
		{
			if (node->data > node->next->data)
				sorted = 0;
		}
		node = node->next;
	}
	if (sorted == 1)
		return (1);
	else
		return (0);
}

void	do_hardsort(t_info *info, int size)
{
	if (size == 2)
		do_hardsort_two(info, 'a');
	else if (size == 3)
		do_hardsort_three(info, 'a');
	else if (size == 4)
		do_hardsort_four(info);
	else
		do_hardsort_five(info);
}

void	do_sort(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stacka_top->next);
	if (issorted(info) == 1)
		return ;
	else if (size <= 5)
		do_hardsort(info, size);
	else
		do_mainsort(info);
}
