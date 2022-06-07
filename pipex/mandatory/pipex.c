/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:44:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/07 17:27:35 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"    

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == 0)
		child_proc();
	else
		parent_proc();
	return (0);
}
