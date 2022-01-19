/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:34 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/18 19:35:15 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libraries/mlx/mlx.h"
# include "includes/libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_game
{
	void *init;
	void *win;
	void *player_w;
	void *player_s;
	void *player_d;
	void *player_a;
	t_map data_map
} t_game;

typedef struct s_map
{
	char **map;
	int collum;
	int row;
	int player_count;
	int exit_count;
	int collectables_count;
} t_map;

#endif