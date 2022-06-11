/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:27:33 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 19:41:17 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(int mode, int ret)
{
	if (mode == ERR && ret == -1)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	if (mode == ARG)
	{
		write(2, "Arguments Error\n", 16);
		exit(EXIT_FAILURE);
	}
}
