/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:59:12 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/20 04:32:50 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_gen(t_game game, char *file)
{
	char	**gen_map;
	char	*buffer;
	char	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		write(1, "Error\n, invalid fd, try again!", 31);
		return (NULL);
	}
	map = ft_strdup("");
	while (1)
	{
		buffer = ft_get_next_line(fd);
		if (!buffer)
			break ;
		map = ft_strjoin(map, buffer);
	}
	gen_map = ft_split(map, '\n');
	// *map and *buffer? needs to be freed?
	close(fd);
	return(gen_map);
}