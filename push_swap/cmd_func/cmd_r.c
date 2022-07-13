/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:43:15 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 21:53:14 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_info *info)
{
	int		size;
	t_node	*obj;

	size = ft_nodesize(info->stacka_top->next);
	if (size < 2)
		return (0);
	else
	{
		obj = info->stacka_top->next;
		ft_nodelast(info->stacka_top->next)->next = obj;
		info->stacka_bot->next = obj;
		info->stacka_top->next = obj->next;
		obj->next = NULL;
		return (1);
	}
}

int	rb(t_info *info)
{
	int		size;
	t_node	*obj;

	size = ft_nodesize(info->stackb_top->next);
	if (size < 2)
		return (0);
	else
	{
		obj = info->stackb_top->next;
		ft_nodelast(info->stackb_top->next)->next = obj;
		info->stackb_bot->next = obj;
		info->stackb_top->next = obj->next;
		obj->next = NULL;
		return (1);
	}
}

int	rr(t_info *info)
{
	if (ra(info) == 0 && rb(info) == 0)
		return (0);
	return (1);
}
