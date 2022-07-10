/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:00:01 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/11 00:21:15 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	init(argc, argv, info);
	test_wholecurr_next(info);
	do_sort(info);
	//printcmds();
	test_wholecurr_next(info);
	return (0);
}
