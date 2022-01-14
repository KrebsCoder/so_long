NAME = so_long.a
CC = gcc
LIBFT = ./includes/libft
CFLAGS = -Wall -Werror -Wextra
FLAGS = -lbsd -lmlx -lXext -lX11
SRC =
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(OBJ) $(FLAGS) -lbsd -lmlx -lXext -lX11 -o $(NAME)
