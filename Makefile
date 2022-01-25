NAME = so_long
CC = gcc
LIBFT = ./libraries/libft
CFLAGS = -g3 -Wall -Werror -Wextra
SRC = src/so_long.c \
	src/map_check.c \
	src/map_gen.c \
	src/data_init.c \
	src/end_game.c \
	src/win_init.c \
	src/load_sprites.c \
	src/put_img_win.c \
	src/hooks_init.c \
	src/key_pressed.c \
	src/move.c \
	src/map_initialize.c
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
