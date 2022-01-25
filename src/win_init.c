/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:27:27 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/25 18:06:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_init(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->data_map.row * SPRITE_SIZE, \
		game->data_map.column * SPRITE_SIZE, "win");
	load_sprites(game);
}
