/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:37 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:41:18 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
		game.data_map.map = map_gen(argv[1]);
	else
		printf("Error\n map is missing");
	if (map_check(&game, argv[1]))
	{
		data_init(&game);
		win_init(&game);
		hooks_init(&game);
		mlx_loop(game.mlx);
	}
	return (0);
}
