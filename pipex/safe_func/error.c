/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:27:33 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/14 13:40:10 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(int mode, int ret)
{
	if (mode == ERR && ret == -1)
	{
		perror("ft_pipex Developer's error");
		exit(EXIT_FAILURE);
	}
	if (mode == ARG)
	{
		write(2, "ft_pipex Arguments Error\n", 25);
		exit(EXIT_FAILURE);
	}
}
