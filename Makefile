# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteles <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 20:42:26 by rteles            #+#    #+#              #
#    Updated: 2022/02/21 20:42:28 by rteles           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	server.c client.c

OBJECTS	=	$(SOURCES:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	$(RM) $(OBJECTS)
	@make -C libft clean
	
fclean: clean
		$(RM) server client libft/libft.a

re:		fclean all

.PHONY: all bonus libft clean fclean re