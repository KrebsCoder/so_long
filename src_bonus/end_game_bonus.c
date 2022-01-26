/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:32:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:51:46 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_ptr(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_map(t_game *game)
{
	int	column;

	column = 0;
	while (game->data_map.map[column])
	{
		free_ptr(game->data_map.map[column]);
		column++;
	}
	free_ptr(game->data_map.map);
}

int	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->p_down);
	mlx_destroy_image(game->mlx, game->p_up);
	mlx_destroy_image(game->mlx, game->p_left);
	mlx_destroy_image(game->mlx, game->p_right);
	mlx_destroy_image(game->mlx, game->cheese);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->background);
	mlx_destroy_image(game->mlx, game->exit_closed);
	mlx_destroy_image(game->mlx, game->exit_open);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_ptr(game->mlx);
	free_map(game);
	exit(0);
	return (0);
}
