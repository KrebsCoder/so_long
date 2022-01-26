/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:57:16 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 19:05:46 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int key_code, t_game *game)
{
	int		row;
	int		column;

	row = game->p_x;
	column = game->p_y;
	if (key_code == KEY_ESC)
		end_game(game);
	else if (game->end_game)
		return (0);
	else if (key_code == 'w')
		column--;
	else if (key_code == 's')
		column++;
	else if (key_code == 'a')
		row--;
	else if (key_code == 'd')
		row++;
	if (game->end_game == 0 && validate_next_move(game, row, column, key_code))
	{
		check_side(game, key_code);
		move_player(game, column, row);
	}
	return (0);
}

int	check_side(t_game *game, int key_code)
{
	if (key_code == 'w')
		game->p_direction = 'w';
	else if (key_code == 's')
		game->p_direction = 's';
	else if (key_code == 'a')
		game->p_direction = 'a';
	else if (key_code == 'd')
		game->p_direction = 'd';
	return (0);
}
