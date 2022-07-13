/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:45:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/13 21:29:17 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	char	*line;

	info = malloc(sizeof(t_info));
	init(argc, argv, info);
	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (ft_strlen(line) != 2)
		{
			if (ft_strnstr()))
		}
		line = get_next_line(STDIN_FILENO);
	}
}
