NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc

LIBFT = ./libraries/libft

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
		src/utils.c


SRC_BONUS = src_bonus/data_init_bonus.c \
		src_bonus/end_game_bonus.c \
		src_bonus/hooks_init_bonus.c \
		src_bonus/key_pressed_bonus.c \
		src_bonus/load_sprites_bonus.c \
		src_bonus/map_check_bonus.c \
		src_bonus/map_gen_bonus.c \
		src_bonus/move_bonus.c \
		src_bonus/put_img_win_bonus.c \
		src_bonus/so_long_bonus.c \
		src_bonus/t_map_initialize_bonus.c \
		src_bonus/win_init_bonus.c \
		src_bonus/utils_bonus.c

CFLAGS = -g3 -Wall -Werror -Wextra


FLAGS = -lmlx -lXext -lX11

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT) $(OBJ) -L$(LIBFT) -lft $(FLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT) $(OBJ_BONUS) -L$(LIBFT) -lft $(FLAGS) -o $(NAME_BONUS)

clean: 
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

clean_bonus:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ_BONUS) 

fclean_bonus: clean_bonus
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME_BONUS)

re: fclean $(NAME)

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean clean_bonus fclean_bonus re re_bonus
