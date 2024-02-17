# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 00:22:34 by lpaixao-          #+#    #+#              #
#    Updated: 2024/02/17 00:54:44 by lpaixao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

CC = cc

FLAGS = -Wall -Wextra -Werror

THE_SERVER = server.c

THE_CLIENT = client.c

OPEN_S = ./server

OPEN_C = ./client

LIBFT = my_libft/libft.a

NAME_LIB = libft.a

$(LIBFT): 
	make -C my_libft

all: $(LIBFT)
	cp my_libft/libft.a $(NAME_LIB)
	$(CC) $(FLAGS) $(THE_SERVER) -o $(SERVER)
	$(CC) $(FLAGS) $(THE_CLIENT) -o $(CLIENT)
	@echo "Server and Client are ready"
	@echo "Servidor e Cliente estão prontos"


clean:
	make clean -C my_libft

fclean: clean
	make fclean -C my_libft
	rf -f $(NAME_LIB)
	rm -f $(SERVER) $(CLIENT)

re: fclean all
