/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_headnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:46:11 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/07 16:47:12 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*ft_headnew(void)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	if (head == NULL)
		return (NULL);
	head->next = NULL;
	return (head);
}
