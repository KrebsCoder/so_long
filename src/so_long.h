/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:34 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/20 17:19:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/mlx/mlx.h"
# include "../libraries/libft/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	char **map;
	int collum;
	int row;
	int player_count;
	int exit_count;
	int collectables_count;
} t_map;

typedef struct s_game
{
	void *init;
	void *win;
	void *player_w;
	void *player_s;
	void *player_d;
	void *player_a;
	t_map data_map;
} t_game;

char	**map_gen(t_game game, char *file);
int		map_check(t_game *game, char *file);
int		count_wall(t_game *game);
int 	validate_wall(t_game *game);
int		validate_extension(char *file);
int		validate_content(t_game *game);

#endif