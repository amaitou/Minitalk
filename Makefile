
CLIENT = client.c
CLIENT_BONUS = client_bonus.c

SERVER = server.c
SERVER_BONUS = server_bonus.c

UTILS =  minitalk_utils.c ft_atoi.c
UTILS_BONUS = minitalk_utils_bonus.c ft_atoi_bonus.c

NAME = client
NAME_BONUS = client_bonus

NAME_2 = server
NAME_2_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_2) bonus

bonus:
	@echo "compiling \033[1;32m$(CLIENT_BONUS)\033[0m"
	@$(CC) $(CFLAGS) $(CLIENT_BONUS) $(UTILS_BONUS) -o $(NAME_BONUS)
	@echo "compiling \033[1;32m$(SERVER_BONUS)\033[0m"
	@$(CC) $(CFLAGS) $(SERVER_BONUS) $(UTILS_BONUS) -o $(NAME_2_BONUS)

$(NAME):
	@echo "compiling \033[1;32m$(CLIENT)\033[0m"
	@$(CC) $(CFLAGS) $(CLIENT) $(UTILS) -o $@

$(NAME_2):
	@echo "compiling \033[1;32m$(SERVER)\033[0m"
	@$(CC) $(CFLAGS) $(SERVER) $(UTILS) -o $@

clean:
	@echo "deleting all the executable files"
	@rm -f $(NAME) $(NAME_2) $(NAME_BONUS) $(NAME_2_BONUS)

fclean: clean
	@echo "deleting *.a"
	@rm -f *.a

re: fclean all

