/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 20:42:37 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sort(t_info *info)
{
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init(argc, argv, info);
	//do_sort(info);
	//printcmds();
	test_start(info);
	test_sa(info);
	test_pb(info);
	test_sa(info);
	test_pb(info);
	test_ss(info);
	test_ss(info);
	test_pa(info);
	test_sb(info);
	test_pa(info);
	return (0);
}
