/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:08:50 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 12:24:07 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_size_two(t_head *top, t_head *bot)
{
	t_node	*obj_a;
	t_node	*obj_b;

	obj_a = top->next;
	obj_b = top->next->next;
	obj_a->next = NULL;
	obj_b->next = obj_a;
	top->next = obj_b;
	bot->next = obj_a;
}

void	swap_size_morethan_two(t_head *top)
{
	t_node	*obj_a;
	t_node	*obj_b;

	obj_a = top->next;
	obj_b = top->next->next;
	obj_a->next = obj_b->next;
	obj_b->next = obj_a;
	top->next = obj_b;
}

int	ss(t_info *info)
{
	sa(info);
	sb(info);
	return (1);
}

int	sb(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stackb_top->next);
	if (size < 2)
		return (0);
	else if (size == 2)
		swap_size_two(info->stackb_top, info->stackb_bot);
	else
		swap_size_morethan_two(info->stackb_top);
	return (1);
}

int	sa(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stacka_top->next);
	if (size < 2)
		return (0);
	else if (size == 2)
		swap_size_two(info->stacka_top, info->stacka_bot);
	else
		swap_size_morethan_two(info->stacka_top);
	return (1);
}
