/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:32:10 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/08 22:43:21 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*safe_path(char *cmd, char **envp)
{
	char	**arr_path;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		++i;
	arr_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (arr_path[i])
	{
		tmp = ft_strjoin(arr_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		path = NULL;
		++i;
	}
	return (0);
}
