/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:33:04 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/11 00:15:38 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_curr_next(t_head *top, char c)
{
	t_node	*curr;
	int		print;

	curr = top->next;
	printf("============\nstack %c TOP\n============\n", c);
	while (curr)
	{
		print = curr->data;
		printf("%d\n", print);
		curr = curr->next;
	}
	printf("======\nBOTTOM\n======\n\n");
}

void	test_wholecurr_next(t_info *info)
{
	t_node	*curr;
	int		print;

	curr = info->stacka_top->next;
	printf("============\nstack %c TOP\n============\n", 'a');
	while (curr)
	{
		print = curr->data;
		printf("%d\n", print);
		curr = curr->next;
	}
	printf("======\nBOTTOM\n======\n");
	printf("============\nstack %c TOP\n============\n", 'b');
	curr = info->stackb_top->next;
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

void	test_rra(t_info *info)
{
	printf("----------rra---------\n");
	rra(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_rrb(t_info *info)
{
	printf("----------rrb---------\n");
	rrb(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}

void	test_rrr(t_info *info)
{
	printf("----------rrr---------\n");
	rrr(info);
	test_curr_next(info->stacka_top, 'a');
	test_curr_next(info->stackb_top, 'b');
}
