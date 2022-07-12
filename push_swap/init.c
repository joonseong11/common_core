/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:19:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 22:16:28 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_info *info)
{	
	int		i;
	int		j;
	int		size;
	t_node	*obj;

	i = 1;
	size = ft_nodesize(info->stacka_top->next);
	while (i <= size)
	{
		j = 1;
		obj = ft_nodesearch(info->stacka_top, i);
		while (j <= size)
		{
			if (obj->data > ft_nodesearch(info->stacka_top, j)->data)
				(obj->index)++;
			++j;
		}
		++i;
	}
}

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
		ft_nodeaddback(&(info->stacka_top->next), ft_nodenew(num));
		// printf("size : %d, num : %lld\n", ft_nodesize(info->stacka_top->next), num); // here too !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		++i;
	}
	info->stacka_bot->next = ft_nodelast(info->stacka_top->next);
}

void	make_stacks(t_info *info)
{
	info->stacka_top = ft_headnew();
	info->stacka_bot = ft_headnew();
	info->stackb_top = ft_headnew();
	info->stackb_bot = ft_headnew();
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
	indexing(info);
}
