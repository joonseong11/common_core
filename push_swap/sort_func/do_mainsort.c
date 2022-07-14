/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mainsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:33:03 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/14 11:16:15 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdeadcase(t_info *info, int size)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info->stacka_top->next;
	while (node)
	{
		if (info->stacka_top->next->data > node->data)
			++i;
		node = node->next;
	}
	if (i > size * 0.6)
		return (1);
	else
		return (0);
}

int	sort_where_are_you(t_info *info, int index)
{
	t_node	*node;
	int		i;

	i = 0;
	node = info->stackb_top->next;
	while (1)
	{
		if (node->index == index)
			break ;
		if (node->next)
		{
			node = node->next;
		}
		++i;
	}
	return (i);
}

void	sort_usesandclock(t_info *info, int size)
{
	int	index;
	int	i;

	index = size - 1;
	while (size)
	{
		i = sort_where_are_you(info, index);
		if (i < size / 2)
		{
			while (i--)
				safe_r(info, 'b');
		}
		else
		{
			while (i++ < size)
				safe_rr(info, 'b');
		}
		safe_p(info, 'a');
		--size;
		--index;
	}
}

void	sort_makesandclock(t_info *info, int i, int chunk, int size)
{
	info->checkdeadcase = checkdeadcase(info, size);
	while (ft_nodesize(info->stacka_top->next))
	{
		if (info->stacka_top->next->index <= i)
		{
			safe_p(info, 'b');
			++i;
		}
		else if (i < info->stacka_top->next->index && \
					info->stacka_top->next->index <= i + chunk)
		{
			safe_p(info, 'b');
			safe_r(info, 'b');
			++i;
		}
		else if (info->stacka_top->next->index > (i + chunk))
		{
			if (info->checkdeadcase == 1 && i < size / 3)
				safe_rr(info, 'a');
			else
				safe_r(info, 'a');
		}
	}
}

void	do_mainsort(t_info *info)
{
	int	i;
	int	size;
	int	chunk;

	i = 0;
	size = ft_nodesize(info->stacka_top->next);
	chunk = 0.000000053 * (size * size) + 0.03 * size + 14.5;
	sort_makesandclock(info, i, chunk, size);
	sort_usesandclock(info, size);
}
