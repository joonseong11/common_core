/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/11 00:23:24 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	do_hardsort_three2(t_info *info, char c, t_abc abc)
{
	if (abc.a > abc.b && abc.a < abc.c && abc.b < abc.c)
		safe_s(info, 'a');
	else
		safe_rr(info, 'a');
}

void	do_hardsort_three(t_info *info, char c)
{
	t_abc	abc;

	abc.a = info->stacka_top->next->data;
	abc.b = info->stacka_top->next->next->data;
	abc.c = info->stacka_top->next->next->next->data;
	if (abc.a < abc.b && abc.a < abc.c)
	{
		if (abc.b > abc.c)
		{
			safe_s(info, 'a');
			safe_r(info, 'a');
		}			
	}
	else if (abc.a > abc.b && abc.a > abc.c)
	{
		if (abc.b < abc.c)
			safe_r(info, 'a');
		else
		{
			safe_s(info, 'a');
			safe_rr(info, 'a');
		}
	}
	else
		do_hardsort_three2(info, c, abc);
}

void	do_hardsort_two(t_info *info, char c)
{
	int	a;
	int	b;

	a = info->stacka_top->next->data;
	b = info->stacka_bot->next->data;
	if (b < a)
		safe_s(info, 'a');
}

void	do_hardsort(t_info *info, int size)
{
	if (size == 2)
		do_hardsort_two(info, 'a');	
	else if (size == 3)
		do_hardsort_three(info, 'a');
}

void	do_sort(t_info *info)
{
	int	size;

	size = ft_nodesize(info->stacka_top->next);
	if (size <= 3)
		do_hardsort(info, size);
	//else
		//do_mergesort(info);
}
