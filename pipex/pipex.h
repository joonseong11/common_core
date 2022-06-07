/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:27:54 by jujeon            #+#    #+#             */
/*   Updated: 2022/06/07 19:52:11 by jujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/*
** to write, read, close, access, pipe, dup, dup2, execve, fork **
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

/* malloc, free, exit */
#include <stdlib.h>

/* open, unlink */
#include <fcntl.h>

/* waitpid, wait */
#include <sys/wait.h>

/* strerror */
#include <string.h>

/*to perror*/
#include <stdio.h>

/* to get_next_line */
#include "../gnl/get_next_line.h"

#endif