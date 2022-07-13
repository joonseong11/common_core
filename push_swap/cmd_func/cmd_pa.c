/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:22:02 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 12:30:44 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa2_2(t_info *info)
{
	int		size;
	t_node	*obj;

	obj = info->stackb_top->next;
	info->stackb_top->next = obj->next;
	size = ft_nodesize(info->stacka_top->next);
	if (size == 0)
		p3_1(info->stacka_top, info->stacka_bot, obj);
	else if (size > 0)
		p3_2(info->stacka_top, obj);
}

void	pa2_1(t_info *info)
{
	int		size;
	t_node	*obj;

	obj = info->stackb_top->next;
	info->stackb_top->next = NULL;
	info->stackb_bot->next = NULL;
	size = ft_nodesize(info->stacka_top->next);
	if (size == 0)
		p3_1(info->stacka_top, info->stacka_bot, obj);
	else if (size > 0)
		p3_2(info->stacka_top, obj);
}

int	pa(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stackb_top->next);
	if (size < 1)
		return (0);
	else if (size == 1)
		pa2_1(info);
	else
		pa2_2(info);
	return (1);
}
