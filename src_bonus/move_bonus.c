/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:15:02 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 18:40:27 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_player(t_game *game, int column, int row)
{
	game->data_map.map[game->p_y][game->p_x] = '0';
	game->data_map.map[column][row] = 'P';
	game->p_y = column;
	game->p_x = row;
	game->moves_count++;
	return (0);
}

int	validate_next_move(t_game *game, int row, int column, int key_code)
{
	if (key_code != 'w' && key_code != 'a' && key_code != 'd'
		&& key_code != 's')
		return (0);
	if (game->data_map.map[column][row] == '1')
		return (0);
	else if (game->data_map.map[column][row] == 'C')
		game->data_map.collectables_count--;
	else if (game->data_map.map[column][row] == 'E' &&
		game->data_map.collectables_count == 0)
	{
		game->data_map.map[game->p_y][game->p_x] = '0';
		game->end_game = 1;
		return (0);
	}
	else if (game->data_map.map[column][row] == 'K')
		end_game(game);
	else if (game->data_map.map[column][row] == 'E')
		return (0);
	else
		return (1);
	return (1);
}
