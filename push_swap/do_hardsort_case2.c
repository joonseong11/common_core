/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hardsort_case2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:41:08 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/13 20:33:02 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_hardsort_four(t_info *info)
{
	t_node	*node;
	int		i;

	i = 0;
	while (ft_nodesize(info->stackb_top->next) < 1)
	{
		node = info->stacka_top->next;
		if (node->index < 1)
			safe_p(info, 'b');
		else
			safe_r(info, 'a');
	}
	do_hardsort_three(info, 'a');
	safe_p(info, 'a');
	safe_p(info, 'a');
}

void	do_hardsort_five(t_info *info)
{
	t_node	*node;
	int		i;

	i = 0;
	while (ft_nodesize(info->stackb_top->next) < 2)
	{
		node = info->stacka_top->next;
		if (node->index < 2)
			safe_p(info, 'b');
		else
			safe_r(info, 'a');
	}
	do_hardsort_three(info, 'a');
	safe_p(info, 'a');
	safe_p(info, 'a');
	if (info->stacka_top->next->index > info->stacka_top->next->next->index)
		safe_s(info, 'a');
}
