/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_win_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:18 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:52:09 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_img_win(t_game *game)
{
	int	row;
	int	column;

	column = 0;
	while (game->data_map.map[column])
	{
		row = 0;
		while (game->data_map.map[column][row])
		{
			if (game->data_map.map[column][row] == '1')
				put_img(game, column, row, game->wall);
			else if (game->data_map.map[column][row] == '0')
				put_img(game, column, row, game->background);
			else if (game->data_map.map[column][row] == 'E')
				put_img(game, column, row, game->exit_closed);
			else if (game->data_map.map[column][row] == 'C')
				put_img(game, column, row, game->cheese);
			else
				put_img(game, column, row, game->p_down);
			row++;
		}
		column++;
	}
	return (0);
}

void	put_img(t_game *game, int row, int column, void *img)
{	
	mlx_put_image_to_window(game->mlx, game->win, img, \
		column * SPRITE_SIZE, row * SPRITE_SIZE);
}
