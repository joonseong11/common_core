# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 22:13:40 by jujeon            #+#    #+#              #
#    Updated: 2022/07/14 01:19:07 by jujeon           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = push_swap
BONUS_NAME = checker
SRCS = mandatory/main.c
SHARED_SRCS = mandatory/init.c \
		basic_func/ft_atolong.c \
		basic_func/ft_calloc.c \
		basic_func/ft_split.c \
		basic_func/ft_strdup.c \
		basic_func/ft_strlen.c \
		basic_func/ft_strnstr.c \
		basic_func/ft_substr.c \
		basic_func/get_next_line.c \
		basic_func/get_next_line_utils.c \
		node_func/ft_headnew.c \
		node_func/ft_lstdelone.c \
		node_func/ft_nodeadd.c \
		node_func/ft_nodelast.c \
		node_func/ft_nodenew.c \
		node_func/ft_nodesearch.c \
		node_func/ft_nodesize.c \
		err_func/get_error.c \
		cmd_func/cmd_p.c \
		cmd_func/cmd_pa.c \
		cmd_func/cmd_pb.c \
		cmd_func/cmd_r.c \
		cmd_func/cmd_rr.c \
		cmd_func/cmd_s.c \
		cmd_func/cmd_safe.c \
		sort_func/do_sort.c \
		sort_func/do_mainsort.c \
		sort_func/do_hardsort_case1.c \
		sort_func/do_hardsort_case2.c
BONUS_SRCS = checker_src/checker_making.c
OBJS = $(SRCS:%.c=%.o)
SHARED_OBJS = $(SHARED_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
INCLUDES = -I.

all: $(NAME)

$(NAME): $(OBJS) $(SHARED_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SHARED_OBJS) $(INCLUDES) -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

bonus : $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(SHARED_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(SHARED_OBJS) $(INCLUDES) -o $@ 

clean:
	rm -f $(OBJS) $(SHARED_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: norm
norm:
	@norminette
	
.PHONY: all fclean clean re bonus
