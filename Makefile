SO_LONG =
NAME = so_long.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC =
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lbsd -lmlx -lXext -lX11 -o $(NAME)