NAME = so_long
CC = gcc
LIBFT = ./libraries/libft
CFLAGS = -Wall -Werror -Wextra
SRC =  src/so_long.c src/map_check.c src/map_gen.c
FLAGS = -lbsd -lmlx -lXext -lX11
OBJ = $(SRC:.c=.o)
RM = rm -f

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(FLAGS) -I$(LIBFT) $(OBJ) -L$(LIBFT) -lft -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
