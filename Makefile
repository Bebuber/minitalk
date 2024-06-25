# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/25 11:03:21 by bebuber           #+#    #+#              #
#    Updated: 2024/06/25 14:21:24 by bebuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

LIBFT = libft/libft.a
CC = CC
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = server.c client.c

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft/
	$(CC) $(CFLAGS) -o server server.c $(LIBFT)
	$(CC) $(CFLAGS) -o client client.c $(LIBFT)

clean:
	make -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re