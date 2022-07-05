/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:10:12 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/06 00:33:25 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nodesize(t_node *lst)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = lst;
	while (curr != NULL)
	{
		curr = curr->next;
		++count;
	}
	return (count);
}
