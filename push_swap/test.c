/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:33:04 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/07 17:12:06 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_curr_next(t_info *info)
{
	t_node	*curr;
	int		print;

	curr = info->stacka_top->next;
	printf("curr_next\n\n");
	while (curr)
	{
		print = curr->data;
		printf("%d\n", print);
		curr = curr->next;
	}
	printf("\ncurr_next end\n");
}

void	test_curr_back(t_info *info)
{
	t_node	*curr;
	int		print;

	curr = info->stacka_bot->next;
	printf("curr_back\n\n");
	while (curr)
	{
		print = curr->data;
		printf("%d\n", print);
		curr = curr->back;
	}
	printf("\ncurr_back end\n");
}
