/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:07:47 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 19:42:45 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	safe_open(const char *file_name, int flags)
{
	int	fd;

	if (flags & O_CREAT)
		fd = open(file_name, flags, 0644);
	else
		fd = open(file_name, flags);
	error(ERR, fd);
	return (fd);
}
