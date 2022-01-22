NAME = so_long
CC = gcc
LIBFT = ./libraries/libft
CFLAGS = -g3 -Wall -Werror -Wextra
SRC = src/so_long.c src/map_check.c src/map_gen.c src/data_init.c \
src/so_long_utils.c src/win_init.c src/load_sprites.c src/put_img_win.c \

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
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
