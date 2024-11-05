
SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

THE_SERVER = server.c

THE_CLIENT = client.c

THE_SERVER_BONUS = server_bonus.c

THE_CLIENT_BONUS = client_bonus.c

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
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Server and Client have been cleaned successfully"
	@echo "Servidor e clientes foram limpos com sucesso"

re: fclean all

bonus: $(LIBFT)
	cp my_libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(THE_SERVER_BONUS) $(NAME) -o $(SERVER_BONUS)
	$(CC) $(FLAGS) $(THE_CLIENT_BONUS) $(NAME) -o $(CLIENT_BONUS)
	@echo "Server bonus and Client bonus are ready"
	@echo "Servidor bônus e Cliente bônus estão prontos"

norm: 
	norminette -R CheckForbiddenSourceHeader
