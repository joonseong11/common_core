/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/11 21:58:02 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_hardsort_four(t_info *info, char c)
{
	int		i;
	int		j;
	t_node	*node;

	i = 0;
	safe_r(info, 'a');
	do_hardsort_three(info, 'a');
	safe_rr(info, 'a');
	while (i < 3)
	{
	
	}
}

void	do_hardsort_five(t_info *info, char c)
{
	int		i;
	t_node	*node;

	i = 4;
	safe_r(info, 'a');
	do_hardsort_four(info, 'a');
	safe_rr(info, 'a');
	node = info->stacka_top->next;
	while (i)
	{
		printf("hard five i = %d\n", i);
		if (node->data > node->next->data)
			safe_s(info, 'a');
		if (node->next != NULL)
			node = node->next;
		--i;
	}
}

void	do_hardsort(t_info *info, int size)
{
	if (size == 2)
		do_hardsort_two(info, 'a');
	else if (size == 3)
		do_hardsort_three(info, 'a');
	else if (size == 4)
		do_hardsort_four(info, 'a');
	else
		do_hardsort_five(info, 'a');
}

void	do_sort(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stacka_top->next);
	if (size <= 5)
		do_hardsort(info, size);
	// else
	// 	do_mainsort(info);
}
