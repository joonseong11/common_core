/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_unlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:35:23 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 22:03:04 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex_bonus.h"

void	safe_unlink(const char *path)
{
	int	err;

	err = unlink(path);
	error(ERR, err);
}
