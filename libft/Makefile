# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 21:17:09 by rteles            #+#    #+#              #
#    Updated: 2022/01/08 22:27:24 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS 	= $(wildcard *.c)

OBJS	= $(SRCS:.c=.o) 

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar -rcs

all:	$(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re