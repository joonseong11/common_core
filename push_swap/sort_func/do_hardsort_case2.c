/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hardsort_case2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:41:08 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/14 00:52:32 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_hardsort_four(t_info *info)
{
	t_node	*node;
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
