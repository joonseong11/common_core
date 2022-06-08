/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:03:43 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/08 22:44:37 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	safe_execve(char *cmd, char **envp)
{
	int		ret;
	char	**arr_cmd;

	arr_cmd = safe_getcmd(cmd);
	ret = execve(safe_path(arr_cmd[0], envp), arr_cmd, envp);
	error(ERR, ret);
}
