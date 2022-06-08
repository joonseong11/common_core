/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_getcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:32:18 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/08 21:04:39 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**safe_getcmd(char *cmd)
{
	char	**arr_cmd;

	arr_cmd = ft_split(cmd, ' ');
	if (arr_cmd == NULL)
	{
		write(2, "allocation error\n", 17);
		exit(1);
	}
	return (arr_cmd);
}
