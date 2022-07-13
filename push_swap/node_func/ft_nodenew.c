/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:03:03 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/08 20:09:21 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_nodenew(int data)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (head == NULL)
		return (NULL);
	head -> data = data;
	head -> next = NULL;
	return (head);
}
