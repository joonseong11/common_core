/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:27:54 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/11 21:31:34 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* pid_t close pipe fork execve access */
# include <unistd.h>

/* perror exit */
# include <stdio.h>
# include <stdlib.h>

/* open */
# include <fcntl.h>

/* wait_pid */
# include <sys/wait.h>

typedef enum e_error
{
	ERR,
	ARG
}t_error;

typedef struct s_proc_info
{
	int		infile;
	int		outfile;
	int		i;
}	t_proc_info;

/* basic functions */
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t cnt, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/* error handling external function */
void	error(int mode, int ret_fd);
int		safe_open(const char *file_name, int flags);
void	safe_close(int fd);
void	safe_pipe(int *arr);
int		safe_dup2(int fd1, int fd2);
void	safe_execve(char *cmd, char **envp);
char	**safe_getcmd(char *cmd);
char	*safe_path(char *cmd, char **envp);

#endif