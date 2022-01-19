/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:45:37 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/19 01:44:33 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int so_long(int argc, int *argv[])
{
	t_game game;

	if (argc == 2)
	{
		game.data_map.map = map_gen(argv[1]);
	}
	else
		write(1, "Error\n, map is missing", 23);
	if (map_check(&game.data_map.map, argv[1]))
	{
		// init nas coisas
	}
		//...
}
