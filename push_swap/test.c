/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:33:04 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 21:54:19 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_curr_next(t_head *top, char c)
{
	t_node	*curr;
	int		print;

	curr = top->next;
	printf("\n============\nstack %c TOP\n============\n", c);
	while (curr)
	{
		print = curr->data;
		printf("%d\n", print);
		curr = curr->next;
	}
	printf("======\nBOTTOM\n======\n\n");
}

void	test_start(t_info *info)
{
	printf("---------start---------\n");
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_sa(t_info *info)
{
	printf("----------sa----------\n");
	sa(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_sb(t_info *info)
{
	printf("----------sb----------\n");
	sb(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_ss(t_info *info)
{
	printf("----------ss----------\n");
	ss(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_pb(t_info *info)
{
	printf("----------pb----------\n");
	pb(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_pa(t_info *info)
{
	printf("----------pa---------\n");
	pa(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_ra(t_info *info)
{
	printf("----------ra---------\n");
	ra(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_rb(t_info *info)
{
	printf("----------rb---------\n");
	rb(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_rr(t_info *info)
{
	printf("----------rr---------\n");
	rr(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}
