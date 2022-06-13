/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:02:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/13 20:51:58 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/get_next_line.h"

void	func_lastcmd(t_proc_info info)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error(ERR, pid);
	else if (pid == 0)
	{
		safe_dup2(info.outfile, STDOUT_FILENO);
		if (access("tmp_file", F_OK) == 0)
			safe_unlink("tmp_file");
		safe_execve(info.argv[info.argc - 2], info.envp);
	}
	else
		return ;
	return ;
}

void	func_cmd(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	safe_pipe(fd);
	pid = fork();
	if (pid < 0)
		error(ERR, pid);
	else if (pid == 0)
	{
		close(fd[0]);
		safe_dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		safe_execve(cmd, envp);
	}
	else
	{
		close(fd[1]);
		safe_dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return ;
}

void	func_proc(t_proc_info info)
{
	int	j;

	j = info.i;
	safe_dup2(info.infile, STDIN_FILENO);
	while (j < info.argc)
	{
		func_cmd(info.argv[j], info.envp);
		++j;
	}
	safe_dup2(info.outfile, STDOUT_FILENO);
	func_lastcmd(info);
	return ;
}

void	func_heredoc(int infile, char *LIMITER)
{
	char	*line;

	while (1)
	{
		line = get_next_line(infile);
		if (ft_strnstr(line, LIMITER, ft_strlen(LIMITER)))
		{
			free(line);
			line = 0;
			break ;
		}
		write(infile, line, ft_strlen(line));
	}
	infile = open("./tmp_file", O_RDONLY);
	return ;
}
