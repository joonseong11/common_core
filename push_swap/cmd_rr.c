/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:39:33 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 22:27:39 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_info *info)
{
	int		size;
	t_node	*obj;

	size = ft_nodesize(info->stackb_top->next);
	if (size < 2)
		return (0);
	else
	{
		obj = info->stacka_bot->next;
		info->stacka_bot->next = 
	}
}
