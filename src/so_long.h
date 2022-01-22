/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:34 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/22 00:55:03 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../libraries/libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SPRITE_SIZE 50
# define PLAYER_DOWN "sprites/Player_Down.xpm"
# define PLAYER_LEFT "sprites/Player_Left.xpm"
# define PLAYER_UP "sprites/Player_Up.xpm"
# define PLAYER_RIGHT "sprites/Player_right.xpm"
# define WALL "sprites/Wall.xpm"
# define EXIT_CLOSED "sprites/Goal_Blocked.xpm"
# define EXIT_OPEN "sprites/Goal_Open.xpm"
# define CHEESE "sprites/Collect.xpm"
# define BACKGROUND "sprites/Background.xpm"

typedef struct s_map
{
	char	**map;
	int		column;
	int		row;
	int		player_count;
	int		exit_count;
	int		collectables_count;
}	t_map;

typedef struct s_game
{
	void	*p_down;
	void	*p_left;
	void	*p_up;
	void	*p_right;
	void	*wall;
	void	*exit_closed;
	void	*exit_open;
	void	*cheese;
	void	*background;
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	void	*player_w;
	void	*player_s;
	void	*player_d;
	void	*player_a;
	int		collected_cheese;
	int		moves_count;
	t_map	data_map;
}	t_game;

char	**map_gen(char *file);
int		map_check(t_game *game, char *file);
int		count_wall(t_game *game);
int		validate_wall(t_game *game);
int		validate_extension(char *file);
int		validate_content(t_game *game);
void	new_win(t_game game);
void	t_map_initialize(t_game *game);
void	data_init(t_game *game);
void	win_init(t_game *game);
void	load_sprites(t_game *game);
void	put_img(t_game *game, int row, int column, void *img);
void	put_img_win(t_game *game);
void	free_ptr(void *ptr);
//void	hooks_init(t_game *game);

#endif