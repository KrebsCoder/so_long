/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:13:15 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:51:53 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	hooks_init(t_game *game)
{
	mlx_hook(game->win, X_KEY_PRESS, 1L << 0, &key_press, game);
	mlx_hook(game->win, X_CLICK_EXIT, 0, &end_game, game);
	mlx_loop_hook(game->mlx, &put_img_win, game);
}
