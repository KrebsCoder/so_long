NAME = so_long
CC = gcc
LIBFT = ./libraries/libft
CFLAGS = -fsanitize=address -Wall -Werror -Wextra
SRC = 	src/data_init.c \
		src/end_game.c \
		src/hooks_init.c \
		src/key_pressed.c \
		src/load_sprites.c \
		src/map_check.c \
		src/map_gen.c \
		src/move.c \
		src/put_img_win.c \
		src/so_long.c \
		src/t_map_initialize.c \
		src/win_init.c \

FLAGS = -lmlx -lXext -lX11 
OBJ = $(SRC:.c=.o)
RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT) $(OBJ) -L$(LIBFT) -lft $(FLAGS) -o $(NAME)

clean: 
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ)


fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
