/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hardsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 00:40:55 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 12:21:27 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_hardsort_three3(t_info *info, char c, t_abc abc)
{
	safe_r(info, c);
	safe_s(info, c);
	safe_rr(info, c);
	safe_s(info, c);
}

void	do_hardsort_three2(t_info *info, char c, t_abc abc)
{
	if (abc.a > abc.b && abc.a > abc.c)
	{
		if (abc.b < abc.c)
		{
			safe_s(info, c);
			safe_r(info, c);
			safe_s(info, c);
			safe_rr(info, c);
		}
		else
		{
			safe_s(info, c);
			safe_r(info, c);
			safe_s(info, c);
			safe_rr(info, c);
			safe_s(info, c);
		}
	}
	else if (abc.a > abc.b && abc.a < abc.c && abc.b < abc.c)
		safe_s(info, c);
	else
		do_hardsort_three3(info, c, abc);
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
			safe_r(info, c);
			safe_s(info, c);
			safe_rr(info, c);
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
		safe_s(info, c);
}
