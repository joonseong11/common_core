/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:27:33 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/08 17:47:35 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
