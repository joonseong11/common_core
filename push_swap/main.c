/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/07 07:15:45 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int		main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init(argc, argv, info);
	do_sort(info);
	// printcmds();
	return (0);
}
