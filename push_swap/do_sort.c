/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 12:38:50 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_hardsort_four(t_info *info)
{
	int		i;
	int		j;
	t_node	*node;
	t_node	*obj;

	i = 0;
	safe_p(info, 'b');
	do_hardsort_three(info, 'a');
	obj = info->stackb_top->next;
	while (i < 3)
	{
		node = info->stacka_top->next;
		if (node -> data < obj->data)
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
	int		j;
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

void	do_hardsort(t_info *info, int size)
{
	if (size == 2)
		do_hardsort_two(info, 'a');
	else if (size == 3)
		do_hardsort_three(info, 'a');
	else if (size == 4)
		do_hardsort_four(info);
	else
		do_hardsort_five(info);
}

void	do_sort(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stacka_top->next);
	if (size <= 5)
		do_hardsort(info, size);
	// else
	// 	do_mainsort(info);
}
