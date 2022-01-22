/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:37 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/22 03:04:44 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
		game.data_map.map = map_gen(argv[1]);
	else
		write(1, "Error\n, map is missing", 23);
	if (map_check(&game, argv[1]))
	{
		data_init(&game);
		win_init(&game);
		//hooks_init(&game);
	}
	return (1);
}
