/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:24:19 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/12 12:20:55 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p3_2(t_head *top, t_node *obj)
{
	obj->next = top->next;
	top->next = obj;
}

void	p3_1(t_head *top, t_head *bot, t_node *obj)
{
	obj->next = NULL;
	top->next = obj;
	bot->next = obj;
}
