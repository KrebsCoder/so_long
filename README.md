# so_long

# how to compile

gcc -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11

gcc -g3 *.c ../includes/libft/libft.a -o so_long && ./so_long ../maps/teste.ber

gcc *.c -lbsd -lmlx -lXext -lX11  ../libraries/libft/libft.a -o so_long
check for memory leaks: 