# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 14:51:22 by jujeon            #+#    #+#              #
#    Updated: 2022/01/15 14:51:24 by jujeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_putnbr_base.c \
		ft_putptr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -c -Wall -Wextra -Werror
AR_FLAGS = rcs
INCLUDE = -I./

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDE) $(SRCS)

$(NAME) : $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	%(CC) $(FLAGS) $(INCLUDE) $(SRCS)
	ar $(AR_FLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	make clean -C ./libft
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
