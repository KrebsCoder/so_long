/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_initialize_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:03:10 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:52:16 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	t_map_initialize(t_game *game)
{
	game->data_map.collectables_count = 0;
	game->data_map.exit_count = 0;
	game->data_map.player_count = 0;
}
