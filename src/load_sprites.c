/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:59:07 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/21 19:49:21 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game)
{
	game->p_down = mlx_xpm_file_to_image(game->mlx, PLAYER_DOWN, \
		&(game->win_width), &(game->win_height));
	game->p_left = mlx_xpm_file_to_image(game->mlx, PLAYER_LEFT, \
		&(game->win_width), &(game->win_height));
	game->p_up = mlx_xpm_file_to_image(game->mlx, PLAYER_UP, \
		&(game->win_width), &(game->win_height));
	game->p_right = mlx_xpm_file_to_image(game->mlx, PLAYER_RIGHT, \
		&(game->win_width), &(game->win_height));
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, \
		&(game->win_width), &(game->win_height));
	game->exit_closed = mlx_xpm_file_to_image(game->mlx, EXIT_CLOSED, \
		&(game->win_width), &(game->win_height));
	game->exit_open = mlx_xpm_file_to_image(game->mlx, EXIT_OPEN, \
		&(game->win_width), &(game->win_height));
	game->cheese = mlx_xpm_file_to_image(game->mlx, CHEESE, \
		&(game->win_width), &(game->win_height));
	game->background = mlx_xpm_file_to_image(game->mlx, BACKGROUND, \
		&(game->win_width), &(game->win_height));
}