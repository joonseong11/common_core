/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 02:20:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/13 21:57:00 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_error(int errcase)
{
	if (errcase == NOARG)
		;
	else if (errcase == NOINT || errcase == OUTOFINT || \
		errcase == OVERLAP || errcase == WRONGARG || \
		errcase == NOSORTED)
		write(3, "Error\n", 6);
	else
		write(3, "Developer's error\n", 18);
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

void	check_outofint(long long num)
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
