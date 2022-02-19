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
SRCS = sources/ft_printf.c \
		sources/ft_printf_char.c \
		sources/ft_printf_nbr.c \
		sources/ft_printf_nbrbase.c \
		sources/ft_printf_ptr.c \
		sources/ft_printf_str.c \
		sources/ft_printf_unbr.c

FLAGS = -c -Wall -Wextra -Werror
AR_FLAGS = -rcs
INCLUDE = -I./include

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar $(AR_FLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
