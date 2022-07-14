/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:44:06 by jujeon            #+#    #+#             */
/*   Updated: 2022/07/13 20:52:50 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	case_redirection(t_proc_info info)
{
	if (info.argc < 5)
		error(ARG, 0);
	info.infile = safe_open(info.argv[1], O_RDONLY);
	info.outfile = safe_open(info.argv[info.argc - 1], \
						O_WRONLY | O_TRUNC | O_CREAT);
	info.i = 3;
	func_proc(info);
	while (info.i < info.argc)
	{
		wait(NULL);
		++info.i;
	}
	return ;
}

void	case_heredoc(t_proc_info info)
{
	if (info.argc < 6)
		error(ARG, 0);
	info.infile = safe_open("tmp_file", O_RDWR | O_TRUNC | O_CREAT);
	info.outfile = safe_open(info.argv[info.argc - 1], \
					O_RDWR | O_APPEND | O_CREAT);
	info.i = 4;
	info = func_heredoc(info, info.argv[2]);
	func_proc(info);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_proc_info	info;

	info.argc = argc;
	info.argv = argv;
	info.envp = envp;
	if (ft_strnstr(argv[1], "here_doc", 8) > 0)
	{
		info.h = 1;
		case_heredoc(info);
	}
	else
	{
		info.h = 0;
		case_redirection(info);
	}
	return (0);
}

// cmd << LIMITER | cmd1 >> file
// ./pipex here_doc LIMITER cmd cmd1 file
// < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
// ./pipex file1 cmd1 cmd2 cmd3 .. cmdn file2