/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:37 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/27 19:26:08 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		game.data_map.map = map_gen(argv[1]);
		if (!game.data_map.map)
		{
			printf("Error\nInvalid map\n");
			return (1);
		}
	}
	else
	{
		printf("Error\nYou need to send two arguments.\n");
		exit (1);
	}
	if (map_check(&game, argv[1]))
	{
		data_init(&game);
		win_init(&game);
		hooks_init(&game);
		mlx_loop(game.mlx);
	}
	return (0);
}
