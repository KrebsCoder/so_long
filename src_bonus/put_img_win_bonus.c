/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_win_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:20:18 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 19:19:24 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_img_win(t_game *game)
{
	int		row;
	int		column;
	char	*moves;

	column = 0;
	while (game->data_map.map[column])
	{
		row = 0;
		while (game->data_map.map[column][row])
		{
			put_img_win_bonus(game, column, row);
			moves = ft_itoa(game->moves_count);
			mlx_string_put(game->mlx, game->win, 25, 25, 0x000000, "MOVES: ");
			mlx_string_put(game->mlx, game->win, 75, 25, 0x000000, moves);
			free_ptr(moves);
			row++;
		}
		column++;
	}
	return (0);
}

int	put_img_win_bonus(t_game *game, int column, int row)
{
	if (game->data_map.map[column][row] == '1')
		put_img(game, column, row, game->wall);
	else if (game->data_map.map[column][row] == '0')
		put_img(game, column, row, game->background);
	else if (game->data_map.map[column][row] == 'E'
		&& game->data_map.collectables_count == 0)
		put_img(game, column, row, game->exit_open);
	else if (game->data_map.map[column][row] == 'E')
		put_img(game, column, row, game->exit_closed);
	else if (game->data_map.map[column][row] == 'C')
		put_img(game, column, row, game->cheese);
	else if (game->data_map.map[column][row] == 'K')
		put_img(game, column, row, game->enemy_down);
	else
		handle_p_direction(game, column, row);
	return (0);
}

void	handle_p_direction(t_game *game, int column, int row)
{
	if (game->p_direction == 'w')
		put_img(game, column, row, game->p_up);
	if (game->p_direction == 's')
		put_img(game, column, row, game->p_down);
	if (game->p_direction == 'd')
		put_img(game, column, row, game->p_right);
	if (game->p_direction == 'a')
		put_img(game, column, row, game->p_left);
}

void	put_img(t_game *game, int row, int column, void *img)
{	
	mlx_put_image_to_window(game->mlx, game->win, img, \
		column * SPRITE_SIZE, row * SPRITE_SIZE);
}
