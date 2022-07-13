/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_making.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:45:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/14 01:38:11 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	check_ok(t_info *info)
{
	t_node	*node;

	node = info->stacka_top->next;
	while (node)
	{
		if (node->next)
			if (node->data > node->next->data)
			{
				write(1, "KO\n", 3);
				return ;	
			}
		node = node->next;
	}
	write(1, "OK\n", 3);
}

void	get_stdin(t_info *info, char *line)
{
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strlen(line) != 3 && ft_strnstr(line, "sa", 2))
			sa(info);
		else if (ft_strlen(line) != 3 && ft_strnstr(line, "sb", 2))
			sb(info);
		else if (ft_strlen(line) != 3 && ft_strnstr(line, "pa", 2))
			pa(info);
		else if (ft_strlen(line) != 3 && ft_strnstr(line, "pb", 2))
			pb(info);
		else if (ft_strlen(line) != 3 && ft_strnstr(line, "ra", 2))
			ra(info);
		else if (ft_strlen(line) != 3 && ft_strnstr(line, "rb", 2))
			rb(info);
		else if (ft_strlen(line) != 4 && ft_strnstr(line, "rra", 2))
			rra(info);
		else if (ft_strlen(line) != 4 && ft_strnstr(line, "rrb", 2))
			rrb(info);
		else
			get_error(WRONGARG);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;
	char	*line;

	line = NULL;
	info = malloc(sizeof(t_info));
	init(argc, argv, info);
	get_stdin(info, line);
	check_ok(info);
}
