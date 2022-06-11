# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 23:01:14 by jujeon            #+#    #+#              #
#    Updated: 2022/06/11 22:09:52 by jujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = pipex
SRCS =	mandatory/pipex.c \
		basic_func/ft_calloc.c \
		basic_func/ft_split.c \
		basic_func/ft_strdup.c \
		basic_func/ft_strjoin.c \
		basic_func/ft_strlen.c \
		basic_func/ft_strnstr.c \
		basic_func/ft_substr.c \
		safe_func/error.c \
		safe_func/safe_close.c \
		safe_func/safe_dup2.c \
		safe_func/safe_execve.c \
		safe_func/safe_getcmd.c \
		safe_func/safe_open.c \
		safe_func/safe_path.c \
		safe_func/safe_pipe.c
OBJS = $(SRCS:%.c=%.o)
BONUS_NAME = pipex
BONUS_SRCS = bonus/pipex_bonus.c \
			bonus/proc_funcs.c \
			bonus/safe_unlink.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
INCLUDES = -I./include

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: fclean all clean re bonus