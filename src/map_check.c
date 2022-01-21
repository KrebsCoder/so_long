/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:25:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/20 19:03:56 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_game *game, char *file)
{
	if (count_wall(game), validate_wall(game), validate_extension(file),
	 validate_content(game))
		return (1);
	else
		return (0);
}

int	count_wall(t_game *game)
{
	int column;
	int row;
	int j;

	j = ft_strlen(game->data_map.map[0]);

	row = 0;
	while (game->data_map.map[row])
	{
		column = 0;
		while (game->data_map.map[row][column])
			column++;
		if (column != j)
			return (0);
		else
			row++;
	}
	game->data_map.row = row;
	game->data_map.collum = column;
	return (1);
}

int validate_wall(t_game *game)
{
	int column;
	int row;
	int row_size;
	int column_size;

	column_size = 0;
	row_size = 0;
	while(game->data_map.map[row_size])
		row_size++;
	column_size  = ft_strlen(game->data_map.map[0]);

	row = 0;
	while(row < row_size)
	{
		column = 0;
		while(column < column_size)
		{
			if (game->data_map.map[0][column] != '1' ||
			game->data_map.map[row_size - 1][column] != '1' ||
			game->data_map.map[row][0] != '1' ||
			game->data_map.map[row][column_size - 1] != '1')
			{
				printf("Error\nMap is invalid.");
				return (0);
			}
			column++;
		}
		row++;
	}
	return (1);
}

int	validate_extension(char *file)
{
	char *str;

	if (!file)
		return (0);

	str = ft_strchr(file, '.');
	if (ft_strncmp(str, ".ber", 5))
		return (1);
	else
		return (0);
}

int	validate_content(t_game *game)
{
	int row;
	int column;

	row = 0;
	while(game->data_map.map[row])
	{
		column = 0;
		while(game->data_map.map[row][column])
		{
			if (game->data_map.map[row][column] == 'C')
				game->data_map.collectables_count++;
			if (game->data_map.map[row][column] == 'E')
				game->data_map.exit_count++;
			if (game->data_map.map[row][column] == 'P')
				game->data_map.player_count++;
			column++;
		}
		row++;
	}
	if (game->data_map.collectables_count == 0 || 
	game->data_map.exit_count != 1 || game->data_map.player_count != 1)
		return (0);
	else
		return (1);
}
