/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:29:05 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:51:41 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	data_init(t_game *game)
{
	game->mlx = mlx_init();
	game->collected_cheese = 0;
	game->moves_count = 0;
	game->end_game = 0;
}
