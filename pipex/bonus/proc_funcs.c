/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:02:49 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 22:03:36 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	lastcmd_proc(int infile, int outfile)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error(ERR, pid);
	else if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		if (access("./tmp_file", F_OK) == 0)
			safe_unlink("./tmp_file");
		safe_execve(argv[argc - 2], envp);
	}
	else
		return ;
	return ;
}

void	cmd_proc(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	safe_pipe(fd);
	pid = fork();
	if (pid < 0)
		error(ERR, pid);
	else if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		safe_execve(cmd, envp);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
	}
	return ;
}

void	func_proc(int argc, char **argv, char **envp, t_proc_info info)
{
	int	j;

	j = info.i;
	safe_dup2(info.infile, STDIN_FILENO);
	while (j < argc)
		cmd_proc(argv[j], envp);
	lastcmd_proc(info.infile, info.outfile);
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
