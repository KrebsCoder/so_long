/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:25:32 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/20 01:01:01 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_game *game, char *file)
{
	if (count_wall(&game), validate_wall(&game), validate_extension(file),
	 validate_content(&game))
		return (1);
	else
		return (0);
}
// validade wall -> checks bottom, top, and the sides if they're '1's
// validade extension -> checks if file is .ber
// validade content -> checks if there is at least one 'E' 'C' and 'P'
// it also counts it and adds values to struct


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
	int i;

	i = ft_strlen(game->data_map.map[0]);

	row = 0;
	if (game->data_map.collum != game->data_map.row)
		return (write(1, "Error\n, Invalid map, try again!", 31));
		// acho q isso tá errado, pq isso só passa mapa exatamente quadrado
		// tipo 3x3 e 6x6, mas pode ser tbm 4x6, 6x8, etc.

	while (game->data_map.map[row])
	{
		column = 0;
		while(game->data_map.map[row][column])
		{
			if (game->data_map.map[0][column] != '1'
			|| game->data_map.map[i - 1][column] != '1'
			|| game->data_map.map[row][0] != '1'
			|| game->data_map.map[row][i - 1] != '1')
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}

int	validade_extension(char file)
{
	char str;

	if (!file)
		return (0);

	str = ft_strchr(file, '.');
	if (ft_strncmp(str, ".ber", 5))
		return (1);
	else
		return (0);
}

int	validade_content(t_game *game)
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
