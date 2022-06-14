/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:44:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/14 14:08:11 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child2_proc(int *fd, char **argv, char **envp)
{
	int	fd_outfile;

	safe_close(fd[1]);
	fd_outfile = safe_open(argv[4], O_WRONLY | O_TRUNC | O_CREAT);
	safe_dup2(fd[0], STDIN_FILENO);
	safe_dup2(fd_outfile, STDOUT_FILENO);
	safe_close(fd[0]);
	safe_execve(argv[3], envp);
}

void	parent_proc(int *fd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error(ERR, pid);
	else if (pid == 0)
		child2_proc(fd, argv, envp);
	else
	{
		safe_close(fd[0]);
		safe_close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
	return ;
}

void	child_proc(int *fd, char **argv, char **envp)
{
	int	fd_infile;

	safe_close(fd[0]);
	fd_infile = safe_open(argv[1], O_RDONLY);
	safe_dup2(fd_infile, STDIN_FILENO);
	safe_dup2(fd[1], STDOUT_FILENO);
	safe_close(fd[1]);
	safe_execve(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		error(ARG, 0);
	safe_pipe(fd);
	pid = fork();
	if (pid == -1)
		error(ERR, pid);
	else if (pid == 0)
		child_proc(fd, argv, envp);
	else
	{
		parent_proc(fd, argv, envp);
	}
	return (0);
}

// < file1 cmd1 | cmd2 file2 >
// ./pipex file1 cmd1 cmd2 file2