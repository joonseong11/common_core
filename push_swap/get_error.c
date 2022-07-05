/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:20:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/06 02:20:56 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_error(int errcase)
{
	if (errcase == NOARG)
		;
	else if (errcase == NOINT || errcase == OUTOFINT || \
		errcase == OVERLAP)
		printf("Error\n");//		you need to add ft_
	else
		printf("Developer's error\n");//you need to add ft_
	exit(EXIT_FAILURE);
}
