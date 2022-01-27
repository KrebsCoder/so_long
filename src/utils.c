/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:01:21 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/27 19:11:21 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*merge_str(char *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*ccat;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ccat = ft_calloc(len1 + len2 + 1, 1);
	if (!ccat)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ccat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ccat[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (ccat);
}

int	content_cases(t_game *game, int column, int row)
{
	if (game->data_map.map[column][row] == 'C')
	{
		game->data_map.collectables_count++;
		return (1);
	}
	else if (game->data_map.map[column][row] == 'E')
	{
		game->data_map.exit_count++;
		return (1);
	}
	else if (game->data_map.map[column][row] == 'P')
	{
		game->data_map.player_count++;
		game->p_x = row;
		game->p_y = column;
		return (1);
	}
	else if (game->data_map.map[column][row] == '1'
		|| game->data_map.map[column][row] == '0')
		return (1);
	return (0);
}
