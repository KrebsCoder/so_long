/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:25:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/25 01:13:12 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_game *game, char *file)
{
	t_map_initialize(game);
	if (count_wall(game) && validate_wall(game) && validate_extension(file)
		&& validate_content(game))
		return (1);
	else
	{
		printf("Error\nInvalid map.\n");
		return (0);
	}
}

int	count_wall(t_game *game)
{
	int	column;
	int	row;
	int	j;

	j = ft_strlen(game->data_map.map[0]);
	column = 0;
	while (game->data_map.map[column])
	{
		row = 0;
		while (game->data_map.map[column][row])
			row++;
		if (row != j)
			return (0);
		else
			column++;
	}
	game->data_map.row = row;
	game->data_map.column = column;
	return (1);
}

int	validate_wall(t_game *game)
{
	int	column;
	int	row;
	int	row_size;
	int	column_size;

	column_size = 0;
	while (game->data_map.map[column_size])
		column_size++;
	row_size = ft_strlen(game->data_map.map[0]);
	column = 0;
	while (column < column_size)
	{
		row = 0;
		while (row < row_size)
		{
			if (game->data_map.map[0][row] != '1' ||
			game->data_map.map[column_size - 1][row] != '1' ||
			game->data_map.map[column][0] != '1' ||
			game->data_map.map[column][row_size - 1] != '1')
				return (0);
			row++;
		}
		column++;
	}
	return (1);
}

int	validate_extension(char *file)
{
	if (!file)
		return (0);
	if (ft_strnstr(file, ".ber", ft_strlen(file)))
		return (1);
	else
	{
		printf("invalid extension\n");
		return (0);
	}
}

int	validate_content(t_game *game)
{
	int	row;
	int	column;

	column = -1;
	while (game->data_map.map[++column])
	{
		row = -1;
		while (game->data_map.map[column][++row])
		{
			if (game->data_map.map[column][row] == 'C')
				game->data_map.collectables_count++;
			if (game->data_map.map[column][row] == 'E')
				game->data_map.exit_count++;
			if (game->data_map.map[column][row] == 'P')
			{
				game->data_map.player_count++;
				game->p_x = row;
				game->p_y = column;
			}
		}
	}
	if (game->data_map.collectables_count == 0
		|| game->data_map.exit_count != 1 || game->data_map.player_count != 1)
		return (0);
	return (1);
}
