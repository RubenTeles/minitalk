# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <rteles@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:42:26 by rteles            #+#    #+#              #
#    Updated: 2022/04/05 22:24:51 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	server.c client.c

OBJECTS	=	$(SOURCES:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all: server client

bonus: server client

server: server.o

client: client.o

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJECTS)
	
fclean: clean
		$(RM) server client

re:		fclean all

.PHONY: all bonus libft clean fclean re