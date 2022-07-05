/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:03:03 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/05 22:08:38 by jujeon           ###   ########seoul.kr  */
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
	head -> back = NULL;
	return (head);
}
