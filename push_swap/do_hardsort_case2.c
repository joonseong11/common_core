/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hardsort_case2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:41:08 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 16:06:16 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_hardsort_four(t_info *info)
{
	int		i;
	t_node	*node;
	t_node	*obj;

	i = 0;
	safe_p(info, 'b');
	do_hardsort_three(info, 'a');
	obj = info->stackb_top->next;
	while (i < 3)
	{
		node = info->stacka_top->next;
		if (node->data < obj->data)
			safe_r(info, 'a');
		else
			break ;
		++i;
	}
	safe_p(info, 'a');
	while (i)
	{
		safe_rr(info, 'a');
		--i;
	}
}

void	do_hardsort_five(t_info *info)
{
	int		i;
	t_node	*node;
	t_node	*obj;

	i = 0;
	safe_p(info, 'b');
	do_hardsort_four(info);
	obj = info->stackb_top->next;
	while (i < 4)
	{
		node = info->stacka_top->next;
		if (node->data < obj->data)
			safe_r(info, 'a');
		else
			break ;
		++i;
	}
	safe_p(info, 'a');
	while (i)
	{
		safe_rr(info, 'a');
		--i;
	}
}
