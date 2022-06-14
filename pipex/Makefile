# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeon <jujeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 23:01:14 by jujeon            #+#    #+#              #
#    Updated: 2022/06/14 14:15:57 by jujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = pipex
BONUS_NAME = pipex_bonus
SRCS = mandatory/pipex.c
SHARED_SRCS = basic_func/ft_calloc.c \
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
BONUS_SRCS = bonus/pipex_bonus.c \
			bonus/proc_funcs.c \
			bonus/safe_unlink.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)
SHARED_OBJ = $(SHARED_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
INCLUDES = -I./include

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) $(SHARED_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(SHARED_OBJ)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(SHARED_OBJ) $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS_NAME) $(SHARED_OBJ) $(BONUS_OBJS)

rm_pipex :
	rm -f $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(SHARED_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: norm
norm: 
	@norminette

.PHONY: fclean all clean re bonus
