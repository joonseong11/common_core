/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:19:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/07 07:12:43 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putintostacka(char **arr, t_info *info)
{
	int			i;
	long long	num;

	i = 0;
	while (arr[i])
	{
		check_noint(arr[i]);
		num = ft_atolong(arr[i]);
		check_outofint(num);
		check_overlap(info->stacka_top, num);
		ft_nodeadd_back(&(info->stacka_top), ft_nodenew(num));
		printf("size : %d, num : %lld\n", ft_nodesize(info->stacka_top) - 1, num); // here too !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		++i;
	}
	info->stacka_bot = ft_nodelast(info->stacka_top);
}

/*
size means TOP -> NODE1 -> NODE2 -> ... NODEn
ft_nodesize calculate Nodes number + 1 (TOP Node)
therefore - 1
*/

void	make_stacks(t_info *info)
{
	info->stacka_top = ft_nodenew(0);
	info->stacka_bot = ft_nodenew(0);
	info->stackb_top = ft_nodenew(0);
	info->stackb_bot = ft_nodenew(0);
	if (info->stacka_bot == NULL || info->stacka_top == NULL || \
		info->stackb_bot == NULL || info->stackb_top == NULL)
		get_error(OTHER);
}

void	init(int argc, char **argv, t_info *info)
{
	int		i;
	char	**arr;

	i = 1;
	check_noarg(argc);
	make_stacks(info);
	while (argv[i])
	{
		arr = ft_split(argv[i], ' ');
		if (arr == NULL)
			get_error(OTHER);
		putintostacka(arr, info);
		++i;
	}
}