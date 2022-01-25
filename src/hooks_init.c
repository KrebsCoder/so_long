/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:13:15 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/25 21:32:13 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hooks_init(t_game *game)
{
	mlx_hook(game->win, 02, 1L << 0, &key_press, game);
	mlx_loop_hook(game->mlx, &put_img_win, game);
}
