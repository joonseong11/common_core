/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:39:33 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 22:48:13 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrb(t_info *info)
{
	int		size;
	t_node	*obj;

	size = ft_nodesize(info->stackb_top->next);
	if (size < 2)
		return (0);
	else
	{
		obj = info->stackb_bot->next;
		info->stackb_bot->next = ft_nodesearch(info->stackb_top, size - 1);
		info->stackb_bot->next->next = NULL;
		obj->next = info->stackb_top->next;
		info->stackb_top->next = obj;
		return (1);
	}
}

int	rra(t_info *info)
{
	int		size;
	t_node	*obj;

	size = ft_nodesize(info->stacka_top->next);
	if (size < 2)
		return (0);
	else
	{
		obj = info->stacka_bot->next;
		info->stacka_bot->next = ft_nodesearch(info->stacka_top, size - 1);
		info->stacka_bot->next->next = NULL;
		obj->next = info->stacka_top->next;
		info->stacka_top->next = obj;
		return (1);
	}
}

int	rrr(t_info *info)
{
	if (rra(info) == 0 && rrb(info) == 0)
		return (0);
	return (1);
}
