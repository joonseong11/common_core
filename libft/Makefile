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

NAME = libft.a
SRCS = 			 ft_atoi.c \
 				 ft_bzero.c \
                 ft_calloc.c \
                 ft_isalnum.c \
                 ft_isalpha.c \
                 ft_isascii.c \
                 ft_isdigit.c \
                 ft_isprint.c \
                 ft_itoa.c \
                 ft_memchr.c \
                 ft_memcmp.c \
                 ft_memcpy.c \
                 ft_memmove.c \
                 ft_memset.c \
                 ft_putchar_fd.c \
                 ft_putendl_fd.c \
                 ft_putnbr_fd.c \
                 ft_putstr_fd.c \
                 ft_split.c \
                 ft_strchr.c \
                 ft_strdup.c \
                 ft_striteri.c \
                 ft_strjoin.c \
                 ft_strlcat.c \
                 ft_strlcpy.c \
                 ft_strlen.c \
                 ft_strmapi.c \
                 ft_strncmp.c \
                 ft_strnstr.c \
                 ft_strrchr.c \
                 ft_strtrim.c \
                 ft_substr.c \
                 ft_tolower.c \
                 ft_toupper.c

BNS_SRCS      =  ft_lstnew.c \
                 ft_lstadd_front.c \
                 ft_lstsize.c \
                 ft_lstlast.c \
                 ft_lstadd_back.c \
                 ft_lstdelone.c \
                 ft_lstclear.c \
                 ft_lstiter.c \
                 ft_lstmap.c

OBJS = $(SRCS:.c=.o)

BNS_OBJS = $(BNS_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BNS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

$(NAME) : $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJS) $(BNS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
