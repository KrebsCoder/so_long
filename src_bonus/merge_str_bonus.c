/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:01:21 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/01/26 01:52:05 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
