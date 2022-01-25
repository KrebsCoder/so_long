/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:15:02 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/25 02:18:53 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key_code, t_game *game)
{
	int	row;
	int	column;

	row = game->p_x;
	column = game->p_y;
	printf("%d\n", key_code);
	if (key_code == KEY_ESC)
		return (-1); // it should call exit_game function
		//exit_game(game);
	else if (game->end_game)
		return (0);
	else if (key_code == 'w')
		column--;
	else if (key_code == 's')
		column++;
	else if (key_code == 's')
		row--;
	else if (key_code == 'd')
		row++;
	if (game->end_game == 0 && validate_next_move(game, row, column, key_code))
		move_player(game, column, row);
	return (0);
}

int move_player(t_game *game, int column, int row)
{
	game->p_y = column;
	game->p_x = row;

	game->data_map.map[game->p_y][game->p_x]
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
	else if (game->data_map.map[column][row] == 'E')
		return (0);
	else
		return (1);
	return (0);
}
