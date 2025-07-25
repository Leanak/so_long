/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:15:29 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/21 19:40:19 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_true_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	line = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

char	**dup_map(char **map)
{
	char	**dup;
	int		i;
	int		lines;

	i = 0;
	lines = count_true_line(map);
	dup = malloc(sizeof(char *) * (lines + 1));
	if (!dup)
		return (NULL);
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
