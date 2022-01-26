/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:59:12 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:41:29 by lkrebs-l         ###   ########.fr       */
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
	{
		printf("Error\n invalid fd, try again!");
		return (NULL);
	}
	map = ft_strdup("");
	while (1)
	{
		buffer = ft_get_next_line(fd);
		if (!buffer)
			break ;
		map = merge_str(map, buffer);
		free_ptr((void *)buffer);
	}
	gen_map = ft_split(map, '\n');
	free_ptr((void *)map);
	close(fd);
	return (gen_map);
}
