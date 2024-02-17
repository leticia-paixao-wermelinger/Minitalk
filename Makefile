# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 00:22:34 by lpaixao-          #+#    #+#              #
#    Updated: 2024/02/17 11:29:22 by lpaixao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

THE_SERVER = server.c

THE_CLIENT = client.c

OPEN_S = ./server

OPEN_C = ./client

LIBFT = my_libft/libft.a

all: $(LIBFT)
	cp my_libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(THE_SERVER) $(NAME) -o $(SERVER)
	$(CC) $(FLAGS) $(THE_CLIENT) $(NAME) -o $(CLIENT)
	@echo "Server and Client are ready"
	@echo "Servidor e Cliente estão prontos"

$(LIBFT): 
	make -C my_libft

clean:
	make clean -C my_libft

fclean: clean
	make fclean -C my_libft
	rm -f $(NAME)
	rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client have beem cleaned successfully"
	@echo "Servidor e clientes foram limpos com sucesso"

re: fclean all

norm: 
	norminette -R CheckForbiddenSourceHeader
