/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:44:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 22:02:44 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/*
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
		wait(NULL);
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
*/

void	case_redirection(int argc, char **argv, char **envp)
{
	int			infile;
	int			outfile;
	t_proc_info	info;
	int			i;

	i = 3;
	if (argc < 5)
		error(ARG, NULL);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT);
	info.infile = infile;
	info.outfile = outfile;
	info.i = i;
	func_proc(argc, argv, envp, infile);
	while (i < argc)
		wait(NULL);
}

void	case_heredoc(int argc, char **argv, char **envp)
{
	int			infile;
	int			outfile;
	t_proc_info	info;
	int			i;

	i = 4;
	if (argc < 6)
		error(ARG, NULL);
	infile = open("./tmp_file", O_WRONLY | O_TRUNC | O_CREAT, 0755);
	outfile = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT);
	info.infile = infile;
	info.outfile = outfile;
	info.i = i;
	func_heredoc(infile, argv[2]);
	func_proc(argc, argv, envp, info);
	while (i < argc)
		wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	if (strnstr(argv[1], "here_doc", 8) == 0)
		case_heredoc(argc, argv, envp);
	else
		case_redirection(argc, argv, envp);
	return (0);
}

// cmd << LIMITER | cmd1 >> file
// ./pipex here_doc LIMITER cmd cmd1 file
// < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
// ./pipex file1 cmd1 cmd2 cmd3 .. cmdn file2