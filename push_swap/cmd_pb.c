/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 06:40:24 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/09 01:36:05 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb2_2(t_info *info)
{
	int		size_a;
	t_node	*obj;

	obj = info->stacka_top->next;
	info->stacka_top->next = obj->next;
	size_a = ft_nodesize(info->stackb_top->next);
	if (size_a == 0)
		p3_1(info->stackb_top, info->stackb_bot, obj);
	else if (size_a > 0)
		p3_2(info->stackb_top, info->stackb_bot, obj);
}

void	pb2_1(t_info *info)
{
	int		size;
	t_node	*obj;

	obj = info->stacka_top->next;
	info->stacka_top->next = NULL;
	info->stacka_bot->next = NULL;
	size = ft_nodesize(info->stackb_top->next);
	if (size == 0)
		p3_1(info->stackb_top, info->stackb_bot, obj);
	else if (size > 0)
		p3_2(info->stackb_top, info->stackb_bot, obj);
}

void	pb(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stacka_top->next);
	if (size < 1)
		return ;
	else if (size == 1)
		pb2_1(info);
	else
		pb2_2(info);
}
