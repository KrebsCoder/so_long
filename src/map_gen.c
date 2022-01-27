/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:59:12 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/27 18:49:15 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_gen(char *file)
{
	char	**gen_map;
	char	*buffer;
	char	*map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (NULL);
	map = ft_strdup("");
	while (1)
	{
		buffer = ft_get_next_line(fd);
		if (!buffer)
			break ;
		map = merge_str(map, buffer);
		free_ptr((void *)buffer);
	}
	if (check_next_line(map))
		exit (1);
	gen_map = ft_split(map, '\n');
	free_ptr((void *)map);
	close(fd);
	return (gen_map);
}

int	check_next_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n' && map[i + 2] == '1')
		{
			free_ptr(map);
			return (1);
		}
		i++;
	}
	return (0);
}
