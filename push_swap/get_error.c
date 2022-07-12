/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:20:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/11 11:38:23 by jujeon           ###   ########.fr       */
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
		printf("Developer's error\n");//you need to add ft_ !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	exit(EXIT_FAILURE);
}

void	check_overlap(t_head *head, int num)
{
	t_node	*curr;

	curr = head->next;
	while (curr)
	{
		if (curr->data == num)
			get_error(OVERLAP);
		curr = curr->next;
	}
}

void	check_outofint(int num)
{
	if (num < -2147483648 || num > 2147483647)
		get_error(OUTOFINT);
}

void	check_noint(char *str)
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

void	check_noarg(int argc)
{
	if (argc < 2)
		get_error(NOARG);
}