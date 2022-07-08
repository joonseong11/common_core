/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/07 15:41:29 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	do_sort(t_info *info)
{
	pb();
	pa();
	sa();
	sb();
	ss();
	ra();
	rb();
	rr();
	rra();
	rrb();
	rrr();
}
*/
int		main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init(argc, argv, info);
	//do_sort(info);
	//printcmds();
	test_curr_next(info);
	test_curr_back(info);
	return (0);
}
