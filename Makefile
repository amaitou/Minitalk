
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

CLIENT_SRC = $(CLIENT_FILES:.c=.o)
SERVER_SRC = $(SERVER_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_2) bonus

bonus:
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(UTILS_BONUS) -o $(NAME_BONUS)
	$(CC) $(CFLAGS) $(SERVER_BONUS) $(UTILS_BONUS) -o $(NAME_2_BONUS)

$(NAME):
	$(CC) $(CFLAGS) $(CLIENT) $(UTILS) -o $@

$(NAME_2):
	$(CC) $(CFLAGS) $(SERVER) $(UTILS) -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f *.a

re: all

