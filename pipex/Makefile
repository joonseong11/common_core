# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 23:01:14 by jujeon            #+#    #+#              #
#    Updated: 2022/06/10 22:39:36 by jujeon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = pipex
SRCS =	mandatory/pipex.c \
		Libft/ft_calloc.c \
		Libft/ft_split.c \
		Libft/ft_strdup.c \
		Libft/ft_strjoin.c \
		Libft/ft_strlen.c \
		Libft/ft_strnstr.c \
		Libft/ft_substr.c \
		safe_func/error.c \
		safe_func/safe_close.c \
		safe_func/safe_dup2.c \
		safe_func/safe_execve.c \
		safe_func/safe_getcmd.c \
		safe_func/safe_open.c \
		safe_func/safe_path.c \
		safe_func/safe_pipe.c
OBJS = $(SRCS:%.c=%.o)
INCLUDES = -I.

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean re bonus