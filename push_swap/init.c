/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:19:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/06 17:00:08 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	isnoint(char *str)
{
	int	i;

	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		get_error(NOINT);
}

void	check_overlap(t_node *head, int num)
{
	t_node	*curr;

	curr = head->next;
	if (!head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
}

void	putintostacka(char **arr, t_info *info)
{
	int			i;
	long long	num;

	i = 0;
	while (arr[i])
	{
		isnoint(arr[i]);
		num = ft_atolong(arr[i]);
		if (num < -2147483648 || num > 2147483647)
			get_error(OUTOFINT);
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
	if (argc < 2)
		get_error(NOARG);
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
