/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_safe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:34:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/13 22:58:53 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	safe_s(t_info *info, char c)
{
	if (c == 'a')
	{	
		if (sa(info) == 1)
			write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		if (sb(info) == 1)
			write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		if (ss(info) == 1)
			write(1, "ss\n", 3);
	}
}

void	safe_p(t_info *info, char c)
{
	if (c == 'a')
	{	
		if (pa(info) == 1)
			write(1, "pa\n", 3);
	}
	else if (c == 'b')
	{
		if (pb(info) == 1)
			write(1, "pb\n", 3);
	}
}

void	safe_r(t_info *info, char c)
{
	if (c == 'a')
	{	
		if (ra(info) == 1)
			write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		if (rb(info) == 1)
			write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		if (rr(info) == 1)
			write(1, "rr\n", 3);
	}
}

void	safe_rr(t_info *info, char c)
{
	if (c == 'a')
	{	
		if (rra(info) == 1)
			write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		if (rrb(info) == 1)
			write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		if (rrr(info) == 1)
			write(1, "rrr\n", 4);
	}
}
